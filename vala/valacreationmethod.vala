/* valacreationmethod.vala
 *
 * Copyright (C) 2007-2010  Jürg Billeter
 * Copyright (C) 2007-2008  Raffaele Sandrini
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.

 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.

 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301  USA
 *
 * Author:
 *	Raffaele Sandrini <raffaele@sandrini.ch>
 * 	Jürg Billeter <j@bitron.ch>
 */

using GLib;

/**
 * Represents a type creation method.
 */
public class Vala.CreationMethod : Method {
	/**
	 * Specifies the name of the type this creation method belongs to.
	 */
	public string class_name { get; set; }

	/**
	 * Specifies whether this constructor chains up to a base
	 * constructor or a different constructor of the same class.
	 */
	public bool chain_up { get; set; }

	/**
	 * Creates a new method.
	 *
	 * @param name             method name
	 * @param source_reference reference to source code
	 * @return                 newly created method
	 */
	public CreationMethod (string? class_name, string? name, SourceReference? source_reference = null, Comment? comment = null) {
		base (name, new VoidType (), source_reference, comment);
		this.class_name = class_name;
	}

	public override void accept (CodeVisitor visitor) {
		visitor.visit_creation_method (this);
	}

	public override void accept_children (CodeVisitor visitor) {
		foreach (Parameter param in get_parameters()) {
			param.accept (visitor);
		}

		if (error_types != null) {
			foreach (DataType error_type in error_types) {
				error_type.accept (visitor);
			}
		}

		foreach (Expression precondition in get_preconditions ()) {
			precondition.accept (visitor);
		}

		foreach (Expression postcondition in get_postconditions ()) {
			postcondition.accept (visitor);
		}

		if (body != null) {
			body.accept (visitor);
		}
	}

	public override bool check (CodeContext context) {
		if (checked) {
			return !error;
		}

		checked = true;

		if (class_name != null && class_name != parent_symbol.name) {
			// class_name is null for constructors generated by GIdlParser
			Report.error (source_reference, "missing return type in method `%s.%s´", context.analyzer.current_symbol.get_full_name (), class_name);
			error = true;
			return false;
		}

		if (this_parameter != null) {
			this_parameter.check (context);
		}

		if (coroutine && !external_package && !context.has_package ("gio-2.0")) {
			error = true;
			Report.error (source_reference, "gio-2.0 package required for async constructors");
			return false;
		}

		var old_source_file = context.analyzer.current_source_file;
		var old_symbol = context.analyzer.current_symbol;

		if (source_reference != null) {
			context.analyzer.current_source_file = source_reference.file;
		}
		context.analyzer.current_symbol = this;

		int i = 0;
		foreach (Parameter param in get_parameters()) {
			if (!param.check (context)) {
				error = true;
			}
			if (i == 0 && param.ellipsis && body != null) {
				error = true;
				Report.error (param.source_reference, "Named parameter required before `...'");
			}
			i++;

			// Add local variable to provide access to params arrays which will be constructed out of the given va-args
			if (param.params_array && body != null) {
				if (params_array_var != null) {
					error = true;
					Report.error (param.source_reference, "Only one params-array parameter is allowed");
					continue;
				}
				if (!context.experimental) {
					Report.warning (param.source_reference, "Support of params-arrays is experimental");
				}
				var type = (ArrayType) param.variable_type.copy ();
				type.element_type.value_owned = type.value_owned;
				type.value_owned = true;
				if (type.element_type.is_real_struct_type () && !type.element_type.nullable) {
					error = true;
					Report.error (param.source_reference, "Only nullable struct elements are supported in params-array");
				}
				if (type.length != null) {
					error = true;
					Report.error (param.source_reference, "Passing length to params-array is not supported yet");
				}
				params_array_var = new LocalVariable (type, param.name, null, param.source_reference);
				body.insert_statement (0, new DeclarationStatement (params_array_var, param.source_reference));
			}
		}

		if (error_types != null) {
			foreach (DataType error_type in error_types) {
				error_type.check (context);

				// check whether error type is at least as accessible as the creation method
				if (!error_type.is_accessible (this)) {
					error = true;
					Report.error (source_reference, "error type `%s' is less accessible than creation method `%s'", error_type.to_string (), get_full_name ());
					return false;
				}
			}
		}

		foreach (Expression precondition in get_preconditions ()) {
			precondition.check (context);
		}

		foreach (Expression postcondition in get_postconditions ()) {
			postcondition.check (context);
		}

		if (body != null) {
			body.check (context);

			unowned Class? cl = parent_symbol as Class;

			// ensure we chain up to base constructor
			if (!chain_up && cl != null && cl.base_class != null) {
				if (context.profile == Profile.GOBJECT
				    && cl.base_class.default_construction_method != null
				    && !cl.base_class.default_construction_method.has_construct_function) {
					// directly chain up to Object
					var old_insert_block = context.analyzer.insert_block;
					context.analyzer.current_symbol = body;
					context.analyzer.insert_block = body;

					var stmt = new ExpressionStatement (new MethodCall (new MemberAccess (new MemberAccess.simple ("GLib", source_reference), "Object", source_reference), source_reference), source_reference);
					body.insert_statement (0, stmt);
					stmt.check (context);

					context.analyzer.current_symbol = this;
					context.analyzer.insert_block = old_insert_block;
				} else if (cl.base_class.default_construction_method == null
				    || cl.base_class.default_construction_method.access == SymbolAccessibility.PRIVATE) {
					Report.error (source_reference, "unable to chain up to private base constructor");
				} else if (cl.base_class.default_construction_method.get_required_arguments () > 0) {
					Report.error (source_reference, "unable to chain up to base constructor requiring arguments");
				} else {
					var old_insert_block = context.analyzer.insert_block;
					context.analyzer.current_symbol = body;
					context.analyzer.insert_block = body;

					var base_call = new MethodCall (new BaseAccess (source_reference), source_reference);
					if (coroutine && cl.base_class.default_construction_method.coroutine) {
						base_call.is_yield_expression = true;
					}
					var stmt = new ExpressionStatement (base_call, source_reference);
					body.insert_statement (0, stmt);
					stmt.check (context);

					context.analyzer.current_symbol = this;
					context.analyzer.insert_block = old_insert_block;
				}
			}
		}

		context.analyzer.current_source_file = old_source_file;
		context.analyzer.current_symbol = old_symbol;

		// check that all errors that can be thrown in the method body are declared
		if (body != null && !body.error) {
			var body_errors = new ArrayList<DataType> ();
			body.get_error_types (body_errors);
			foreach (DataType body_error_type in body_errors) {
				bool can_propagate_error = false;
				if (error_types != null) {
					foreach (DataType method_error_type in error_types) {
						if (body_error_type.compatible (method_error_type)) {
							can_propagate_error = true;
						}
					}
				}
				if (!can_propagate_error && !((ErrorType) body_error_type).dynamic_error) {
					Report.warning (body_error_type.source_reference, "unhandled error `%s'", body_error_type.to_string());
				}
			}
		}

		return !error;
	}
}
