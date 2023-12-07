/* valalambdaexpression.c generated by valac, the Vala compiler
 * generated from valalambdaexpression.vala, do not modify */

/* valalambdaexpression.vala
 *
 * Copyright (C) 2006-2010  Jürg Billeter
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
 * 	Jürg Billeter <j@bitron.ch>
 */

#include "vala.h"
#include <valagee.h>
#include <glib-object.h>
#include <glib.h>
#include <stdlib.h>
#include <string.h>

#define _vala_code_node_unref0(var) ((var == NULL) ? NULL : (var = (vala_code_node_unref (var), NULL)))
#define _vala_iterable_unref0(var) ((var == NULL) ? NULL : (var = (vala_iterable_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))
#define _vala_iterator_unref0(var) ((var == NULL) ? NULL : (var = (vala_iterator_unref (var), NULL)))

struct _ValaLambdaExpressionPrivate {
	ValaMethod* _method;
	ValaList* parameters;
	ValaBlock* _statement_body;
	ValaExpression* _expression_body;
};

static gint ValaLambdaExpression_private_offset;
static gpointer vala_lambda_expression_parent_class = NULL;
static gint vala_lambda_expression_next_lambda_id;
static gint vala_lambda_expression_next_lambda_id = 0;

static void vala_lambda_expression_set_expression_body (ValaLambdaExpression* self,
                                                 ValaExpression* value);
static void vala_lambda_expression_set_statement_body (ValaLambdaExpression* self,
                                                ValaBlock* value);
static void vala_lambda_expression_set_method (ValaLambdaExpression* self,
                                        ValaMethod* value);
static void vala_lambda_expression_real_accept (ValaCodeNode* base,
                                         ValaCodeVisitor* visitor);
static void vala_lambda_expression_real_accept_children (ValaCodeNode* base,
                                                  ValaCodeVisitor* visitor);
static gboolean vala_lambda_expression_real_is_pure (ValaExpression* base);
static gboolean vala_lambda_expression_real_check (ValaCodeNode* base,
                                            ValaCodeContext* context);
static void vala_lambda_expression_real_emit (ValaCodeNode* base,
                                       ValaCodeGenerator* codegen);
static void vala_lambda_expression_real_get_used_variables (ValaCodeNode* base,
                                                     ValaCollection* collection);
static void vala_lambda_expression_finalize (ValaCodeNode * obj);
static GType vala_lambda_expression_get_type_once (void);

static inline gpointer
vala_lambda_expression_get_instance_private (ValaLambdaExpression* self)
{
	return G_STRUCT_MEMBER_P (self, ValaLambdaExpression_private_offset);
}

ValaExpression*
vala_lambda_expression_get_expression_body (ValaLambdaExpression* self)
{
	ValaExpression* result;
	ValaExpression* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_expression_body;
	result = _tmp0_;
	return result;
}

static gpointer
_vala_code_node_ref0 (gpointer self)
{
	return self ? vala_code_node_ref (self) : NULL;
}

static void
vala_lambda_expression_set_expression_body (ValaLambdaExpression* self,
                                            ValaExpression* value)
{
	ValaExpression* _tmp0_;
	ValaExpression* _tmp1_;
	g_return_if_fail (self != NULL);
	_tmp0_ = _vala_code_node_ref0 (value);
	_vala_code_node_unref0 (self->priv->_expression_body);
	self->priv->_expression_body = _tmp0_;
	_tmp1_ = self->priv->_expression_body;
	if (_tmp1_ != NULL) {
		ValaExpression* _tmp2_;
		_tmp2_ = self->priv->_expression_body;
		vala_code_node_set_parent_node ((ValaCodeNode*) _tmp2_, (ValaCodeNode*) self);
	}
}

ValaBlock*
vala_lambda_expression_get_statement_body (ValaLambdaExpression* self)
{
	ValaBlock* result;
	ValaBlock* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_statement_body;
	result = _tmp0_;
	return result;
}

static void
vala_lambda_expression_set_statement_body (ValaLambdaExpression* self,
                                           ValaBlock* value)
{
	ValaBlock* _tmp0_;
	ValaBlock* _tmp1_;
	g_return_if_fail (self != NULL);
	_tmp0_ = _vala_code_node_ref0 (value);
	_vala_code_node_unref0 (self->priv->_statement_body);
	self->priv->_statement_body = _tmp0_;
	_tmp1_ = self->priv->_statement_body;
	if (_tmp1_ != NULL) {
		ValaBlock* _tmp2_;
		_tmp2_ = self->priv->_statement_body;
		vala_code_node_set_parent_node ((ValaCodeNode*) _tmp2_, (ValaCodeNode*) self);
	}
}

ValaMethod*
vala_lambda_expression_get_method (ValaLambdaExpression* self)
{
	ValaMethod* result;
	ValaMethod* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_method;
	result = _tmp0_;
	return result;
}

static void
vala_lambda_expression_set_method (ValaLambdaExpression* self,
                                   ValaMethod* value)
{
	ValaMethod* _tmp0_;
	g_return_if_fail (self != NULL);
	_tmp0_ = _vala_code_node_ref0 (value);
	_vala_code_node_unref0 (self->priv->_method);
	self->priv->_method = _tmp0_;
}

/**
 * Creates a new lambda expression.
 *
 * @param expression_body  expression body
 * @param source_reference reference to source code
 * @return                 newly created lambda expression
 */
ValaLambdaExpression*
vala_lambda_expression_construct (GType object_type,
                                  ValaExpression* expression_body,
                                  ValaSourceReference* source_reference)
{
	ValaLambdaExpression* self = NULL;
	g_return_val_if_fail (expression_body != NULL, NULL);
	self = (ValaLambdaExpression*) vala_expression_construct (object_type);
	vala_code_node_set_source_reference ((ValaCodeNode*) self, source_reference);
	vala_lambda_expression_set_expression_body (self, expression_body);
	return self;
}

ValaLambdaExpression*
vala_lambda_expression_new (ValaExpression* expression_body,
                            ValaSourceReference* source_reference)
{
	return vala_lambda_expression_construct (VALA_TYPE_LAMBDA_EXPRESSION, expression_body, source_reference);
}

/**
 * Creates a new lambda expression with statement body.
 *
 * @param statement_body   statement body
 * @param source_reference reference to source code
 * @return                 newly created lambda expression
 */
ValaLambdaExpression*
vala_lambda_expression_construct_with_statement_body (GType object_type,
                                                      ValaBlock* statement_body,
                                                      ValaSourceReference* source_reference)
{
	ValaLambdaExpression* self = NULL;
	g_return_val_if_fail (statement_body != NULL, NULL);
	self = (ValaLambdaExpression*) vala_expression_construct (object_type);
	vala_lambda_expression_set_statement_body (self, statement_body);
	vala_code_node_set_source_reference ((ValaCodeNode*) self, source_reference);
	return self;
}

ValaLambdaExpression*
vala_lambda_expression_new_with_statement_body (ValaBlock* statement_body,
                                                ValaSourceReference* source_reference)
{
	return vala_lambda_expression_construct_with_statement_body (VALA_TYPE_LAMBDA_EXPRESSION, statement_body, source_reference);
}

/**
 * Appends implicitly typed parameter.
 *
 * @param param parameter name
 */
void
vala_lambda_expression_add_parameter (ValaLambdaExpression* self,
                                      ValaParameter* param)
{
	ValaList* _tmp0_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (param != NULL);
	_tmp0_ = self->priv->parameters;
	vala_collection_add ((ValaCollection*) _tmp0_, param);
}

/**
 * Returns the parameter list.
 *
 * @return parameter list
 */
ValaList*
vala_lambda_expression_get_parameters (ValaLambdaExpression* self)
{
	ValaList* _tmp0_;
	ValaList* result;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->parameters;
	result = _tmp0_;
	return result;
}

static void
vala_lambda_expression_real_accept (ValaCodeNode* base,
                                    ValaCodeVisitor* visitor)
{
	ValaLambdaExpression * self;
	self = (ValaLambdaExpression*) base;
	g_return_if_fail (visitor != NULL);
	vala_code_visitor_visit_lambda_expression (visitor, self);
	vala_code_visitor_visit_expression (visitor, (ValaExpression*) self);
}

static void
vala_lambda_expression_real_accept_children (ValaCodeNode* base,
                                             ValaCodeVisitor* visitor)
{
	ValaLambdaExpression * self;
	ValaMethod* _tmp0_;
	self = (ValaLambdaExpression*) base;
	g_return_if_fail (visitor != NULL);
	_tmp0_ = self->priv->_method;
	if (_tmp0_ == NULL) {
		ValaExpression* _tmp1_;
		ValaExpression* _tmp2_;
		_tmp1_ = vala_lambda_expression_get_expression_body (self);
		_tmp2_ = _tmp1_;
		if (_tmp2_ != NULL) {
			ValaExpression* _tmp3_;
			ValaExpression* _tmp4_;
			ValaExpression* _tmp5_;
			ValaExpression* _tmp6_;
			_tmp3_ = vala_lambda_expression_get_expression_body (self);
			_tmp4_ = _tmp3_;
			vala_code_node_accept ((ValaCodeNode*) _tmp4_, visitor);
			_tmp5_ = vala_lambda_expression_get_expression_body (self);
			_tmp6_ = _tmp5_;
			vala_code_visitor_visit_end_full_expression (visitor, _tmp6_);
		} else {
			ValaBlock* _tmp7_;
			ValaBlock* _tmp8_;
			_tmp7_ = vala_lambda_expression_get_statement_body (self);
			_tmp8_ = _tmp7_;
			if (_tmp8_ != NULL) {
				ValaBlock* _tmp9_;
				ValaBlock* _tmp10_;
				_tmp9_ = vala_lambda_expression_get_statement_body (self);
				_tmp10_ = _tmp9_;
				vala_code_node_accept ((ValaCodeNode*) _tmp10_, visitor);
			}
		}
	} else {
		ValaMethod* _tmp11_;
		_tmp11_ = self->priv->_method;
		vala_code_node_accept ((ValaCodeNode*) _tmp11_, visitor);
	}
}

static gboolean
vala_lambda_expression_real_is_pure (ValaExpression* base)
{
	ValaLambdaExpression * self;
	gboolean result;
	self = (ValaLambdaExpression*) base;
	result = FALSE;
	return result;
}

static gpointer
_vala_iterable_ref0 (gpointer self)
{
	return self ? vala_iterable_ref (self) : NULL;
}

static gboolean
vala_lambda_expression_real_check (ValaCodeNode* base,
                                   ValaCodeContext* context)
{
	ValaLambdaExpression * self;
	gboolean _tmp0_;
	gboolean _tmp1_;
	ValaDataType* _tmp4_;
	ValaDataType* _tmp5_;
	ValaDelegate* cb = NULL;
	ValaDataType* _tmp16_;
	ValaDataType* _tmp17_;
	ValaDelegate* _tmp18_;
	ValaDelegate* _tmp19_;
	ValaDelegate* _tmp20_;
	ValaDataType* return_type = NULL;
	ValaDelegate* _tmp21_;
	ValaDataType* _tmp22_;
	ValaDataType* _tmp23_;
	ValaDataType* _tmp24_;
	ValaDataType* _tmp25_;
	ValaDataType* _tmp26_;
	gint _tmp27_;
	gchar* _tmp28_;
	gchar* _tmp29_;
	ValaDataType* _tmp30_;
	ValaSourceReference* _tmp31_;
	ValaSourceReference* _tmp32_;
	ValaMethod* _tmp33_;
	ValaMethod* _tmp34_;
	ValaMethod* _tmp35_;
	ValaDataType* _tmp36_;
	gboolean _tmp46_ = FALSE;
	ValaDelegate* _tmp47_;
	gboolean _tmp48_;
	gboolean _tmp49_;
	ValaMethod* _tmp93_;
	ValaSemanticAnalyzer* _tmp94_;
	ValaSemanticAnalyzer* _tmp95_;
	ValaSymbol* _tmp96_;
	ValaSymbol* _tmp97_;
	ValaScope* _tmp98_;
	ValaScope* _tmp99_;
	ValaMethod* _tmp100_;
	ValaList* lambda_params = NULL;
	ValaList* _tmp101_;
	ValaList* _tmp102_;
	ValaIterator* lambda_param_it = NULL;
	ValaList* _tmp103_;
	ValaIterator* _tmp104_;
	gboolean _tmp105_ = FALSE;
	ValaDelegate* _tmp106_;
	ValaDataType* _tmp107_;
	ValaDataType* _tmp108_;
	ValaIterator* _tmp161_;
	ValaArrayList* error_types = NULL;
	GEqualFunc _tmp164_;
	ValaArrayList* _tmp165_;
	ValaDelegate* _tmp166_;
	ValaArrayList* _tmp167_;
	ValaExpression* _tmp180_;
	ValaExpression* _tmp181_;
	ValaMethod* _tmp215_;
	ValaBlock* _tmp216_;
	ValaBlock* _tmp217_;
	ValaMethod* _tmp218_;
	ValaScope* _tmp219_;
	ValaScope* _tmp220_;
	ValaMethod* m = NULL;
	ValaSemanticAnalyzer* _tmp221_;
	ValaSemanticAnalyzer* _tmp222_;
	ValaSymbol* _tmp223_;
	ValaSymbol* _tmp224_;
	ValaMethod* _tmp225_;
	ValaMethod* _tmp226_;
	ValaMethod* _tmp249_;
	ValaMethod* _tmp250_;
	ValaMethod* _tmp251_;
	ValaSourceReference* _tmp252_;
	ValaSourceReference* _tmp253_;
	ValaMethodType* _tmp254_;
	ValaMethodType* _tmp255_;
	ValaDataType* _tmp256_;
	ValaDataType* _tmp257_;
	ValaDataType* _tmp258_;
	ValaDataType* _tmp259_;
	gboolean _tmp260_;
	gboolean _tmp261_;
	gboolean _tmp262_;
	gboolean _tmp263_;
	gboolean result;
	self = (ValaLambdaExpression*) base;
	g_return_val_if_fail (context != NULL, FALSE);
	_tmp0_ = vala_code_node_get_checked ((ValaCodeNode*) self);
	_tmp1_ = _tmp0_;
	if (_tmp1_) {
		gboolean _tmp2_;
		gboolean _tmp3_;
		_tmp2_ = vala_code_node_get_error ((ValaCodeNode*) self);
		_tmp3_ = _tmp2_;
		result = !_tmp3_;
		return result;
	}
	vala_code_node_set_checked ((ValaCodeNode*) self, TRUE);
	_tmp4_ = vala_expression_get_target_type ((ValaExpression*) self);
	_tmp5_ = _tmp4_;
	if (!VALA_IS_DELEGATE_TYPE (_tmp5_)) {
		ValaDataType* _tmp6_;
		ValaDataType* _tmp7_;
		vala_code_node_set_error ((ValaCodeNode*) self, TRUE);
		_tmp6_ = vala_expression_get_target_type ((ValaExpression*) self);
		_tmp7_ = _tmp6_;
		if (_tmp7_ != NULL) {
			ValaSourceReference* _tmp8_;
			ValaSourceReference* _tmp9_;
			ValaDataType* _tmp10_;
			ValaDataType* _tmp11_;
			gchar* _tmp12_;
			gchar* _tmp13_;
			_tmp8_ = vala_code_node_get_source_reference ((ValaCodeNode*) self);
			_tmp9_ = _tmp8_;
			_tmp10_ = vala_expression_get_target_type ((ValaExpression*) self);
			_tmp11_ = _tmp10_;
			_tmp12_ = vala_code_node_to_string ((ValaCodeNode*) _tmp11_);
			_tmp13_ = _tmp12_;
			vala_report_error (_tmp9_, "Cannot convert lambda expression to `%s'", _tmp13_);
			_g_free0 (_tmp13_);
		} else {
			ValaSourceReference* _tmp14_;
			ValaSourceReference* _tmp15_;
			_tmp14_ = vala_code_node_get_source_reference ((ValaCodeNode*) self);
			_tmp15_ = _tmp14_;
			vala_report_error (_tmp15_, "lambda expression not allowed in this context");
		}
		result = FALSE;
		return result;
	}
	_tmp16_ = vala_expression_get_target_type ((ValaExpression*) self);
	_tmp17_ = _tmp16_;
	_tmp18_ = vala_delegate_type_get_delegate_symbol (G_TYPE_CHECK_INSTANCE_CAST (_tmp17_, VALA_TYPE_DELEGATE_TYPE, ValaDelegateType));
	_tmp19_ = _tmp18_;
	_tmp20_ = _vala_code_node_ref0 (G_TYPE_CHECK_INSTANCE_CAST (_tmp19_, VALA_TYPE_DELEGATE, ValaDelegate));
	cb = _tmp20_;
	_tmp21_ = cb;
	_tmp22_ = vala_callable_get_return_type ((ValaCallable*) _tmp21_);
	_tmp23_ = _tmp22_;
	_tmp24_ = vala_expression_get_target_type ((ValaExpression*) self);
	_tmp25_ = _tmp24_;
	_tmp26_ = vala_data_type_get_actual_type (_tmp23_, _tmp25_, NULL, (ValaCodeNode*) self);
	return_type = _tmp26_;
	_tmp27_ = vala_lambda_expression_next_lambda_id;
	vala_lambda_expression_next_lambda_id = _tmp27_ + 1;
	_tmp28_ = g_strdup_printf ("_lambda%d_", _tmp27_);
	_tmp29_ = _tmp28_;
	_tmp30_ = return_type;
	_tmp31_ = vala_code_node_get_source_reference ((ValaCodeNode*) self);
	_tmp32_ = _tmp31_;
	_tmp33_ = vala_method_new (_tmp29_, _tmp30_, _tmp32_, NULL);
	_tmp34_ = _tmp33_;
	vala_lambda_expression_set_method (self, _tmp34_);
	_vala_code_node_unref0 (_tmp34_);
	_g_free0 (_tmp29_);
	_tmp35_ = self->priv->_method;
	vala_symbol_set_used ((ValaSymbol*) _tmp35_, TRUE);
	_tmp36_ = return_type;
	if (VALA_IS_ARRAY_TYPE (_tmp36_)) {
		ValaMethod* _tmp37_;
		ValaDelegate* _tmp38_;
		ValaMethod* _tmp39_;
		ValaDelegate* _tmp40_;
		ValaMethod* _tmp41_;
		ValaDelegate* _tmp42_;
		_tmp37_ = self->priv->_method;
		_tmp38_ = cb;
		vala_code_node_copy_attribute_bool ((ValaCodeNode*) _tmp37_, (ValaCodeNode*) _tmp38_, "CCode", "array_length");
		_tmp39_ = self->priv->_method;
		_tmp40_ = cb;
		vala_code_node_copy_attribute_bool ((ValaCodeNode*) _tmp39_, (ValaCodeNode*) _tmp40_, "CCode", "array_null_terminated");
		_tmp41_ = self->priv->_method;
		_tmp42_ = cb;
		vala_code_node_copy_attribute_string ((ValaCodeNode*) _tmp41_, (ValaCodeNode*) _tmp42_, "CCode", "array_length_type");
	} else {
		ValaDataType* _tmp43_;
		_tmp43_ = return_type;
		if (VALA_IS_DELEGATE_TYPE (_tmp43_)) {
			ValaMethod* _tmp44_;
			ValaDelegate* _tmp45_;
			_tmp44_ = self->priv->_method;
			_tmp45_ = cb;
			vala_code_node_copy_attribute_bool ((ValaCodeNode*) _tmp44_, (ValaCodeNode*) _tmp45_, "CCode", "delegate_target");
		}
	}
	_tmp47_ = cb;
	_tmp48_ = vala_delegate_get_has_target (_tmp47_);
	_tmp49_ = _tmp48_;
	if (!_tmp49_) {
		_tmp46_ = TRUE;
	} else {
		ValaSemanticAnalyzer* _tmp50_;
		ValaSemanticAnalyzer* _tmp51_;
		_tmp50_ = vala_code_context_get_analyzer (context);
		_tmp51_ = _tmp50_;
		_tmp46_ = !vala_semantic_analyzer_is_in_instance_method (_tmp51_);
	}
	if (_tmp46_) {
		ValaMethod* _tmp52_;
		_tmp52_ = self->priv->_method;
		vala_method_set_binding (_tmp52_, VALA_MEMBER_BINDING_STATIC);
	} else {
		ValaSymbol* sym = NULL;
		ValaSemanticAnalyzer* _tmp53_;
		ValaSemanticAnalyzer* _tmp54_;
		ValaSymbol* _tmp55_;
		ValaSymbol* _tmp56_;
		ValaSymbol* _tmp57_;
		_tmp53_ = vala_code_context_get_analyzer (context);
		_tmp54_ = _tmp53_;
		_tmp55_ = vala_semantic_analyzer_get_current_symbol (_tmp54_);
		_tmp56_ = _tmp55_;
		_tmp57_ = _vala_code_node_ref0 (_tmp56_);
		sym = _tmp57_;
		while (TRUE) {
			ValaMethod* _tmp58_;
			ValaParameter* _tmp59_;
			ValaParameter* _tmp60_;
			ValaSymbol* _tmp61_;
			ValaSymbol* _tmp89_;
			ValaSymbol* _tmp90_;
			ValaSymbol* _tmp91_;
			ValaSymbol* _tmp92_;
			_tmp58_ = self->priv->_method;
			_tmp59_ = vala_method_get_this_parameter (_tmp58_);
			_tmp60_ = _tmp59_;
			if (!(_tmp60_ == NULL)) {
				break;
			}
			_tmp61_ = sym;
			if (VALA_IS_PROPERTY (_tmp61_)) {
				ValaProperty* prop = NULL;
				ValaSymbol* _tmp62_;
				ValaProperty* _tmp63_;
				ValaMethod* _tmp64_;
				ValaProperty* _tmp65_;
				ValaParameter* _tmp66_;
				ValaParameter* _tmp67_;
				_tmp62_ = sym;
				_tmp63_ = _vala_code_node_ref0 (G_TYPE_CHECK_INSTANCE_CAST (_tmp62_, VALA_TYPE_PROPERTY, ValaProperty));
				prop = _tmp63_;
				_tmp64_ = self->priv->_method;
				_tmp65_ = prop;
				_tmp66_ = vala_property_get_this_parameter (_tmp65_);
				_tmp67_ = _tmp66_;
				vala_method_set_this_parameter (_tmp64_, _tmp67_);
				_vala_code_node_unref0 (prop);
			} else {
				ValaSymbol* _tmp68_;
				_tmp68_ = sym;
				if (VALA_IS_CONSTRUCTOR (_tmp68_)) {
					ValaConstructor* c = NULL;
					ValaSymbol* _tmp69_;
					ValaConstructor* _tmp70_;
					ValaMethod* _tmp71_;
					ValaConstructor* _tmp72_;
					ValaParameter* _tmp73_;
					ValaParameter* _tmp74_;
					_tmp69_ = sym;
					_tmp70_ = _vala_code_node_ref0 (G_TYPE_CHECK_INSTANCE_CAST (_tmp69_, VALA_TYPE_CONSTRUCTOR, ValaConstructor));
					c = _tmp70_;
					_tmp71_ = self->priv->_method;
					_tmp72_ = c;
					_tmp73_ = vala_constructor_get_this_parameter (_tmp72_);
					_tmp74_ = _tmp73_;
					vala_method_set_this_parameter (_tmp71_, _tmp74_);
					_vala_code_node_unref0 (c);
				} else {
					ValaSymbol* _tmp75_;
					_tmp75_ = sym;
					if (VALA_IS_DESTRUCTOR (_tmp75_)) {
						ValaDestructor* d = NULL;
						ValaSymbol* _tmp76_;
						ValaDestructor* _tmp77_;
						ValaMethod* _tmp78_;
						ValaDestructor* _tmp79_;
						ValaParameter* _tmp80_;
						ValaParameter* _tmp81_;
						_tmp76_ = sym;
						_tmp77_ = _vala_code_node_ref0 (G_TYPE_CHECK_INSTANCE_CAST (_tmp76_, VALA_TYPE_DESTRUCTOR, ValaDestructor));
						d = _tmp77_;
						_tmp78_ = self->priv->_method;
						_tmp79_ = d;
						_tmp80_ = vala_destructor_get_this_parameter (_tmp79_);
						_tmp81_ = _tmp80_;
						vala_method_set_this_parameter (_tmp78_, _tmp81_);
						_vala_code_node_unref0 (d);
					} else {
						ValaSymbol* _tmp82_;
						_tmp82_ = sym;
						if (VALA_IS_METHOD (_tmp82_)) {
							ValaMethod* m = NULL;
							ValaSymbol* _tmp83_;
							ValaMethod* _tmp84_;
							ValaMethod* _tmp85_;
							ValaMethod* _tmp86_;
							ValaParameter* _tmp87_;
							ValaParameter* _tmp88_;
							_tmp83_ = sym;
							_tmp84_ = _vala_code_node_ref0 (G_TYPE_CHECK_INSTANCE_CAST (_tmp83_, VALA_TYPE_METHOD, ValaMethod));
							m = _tmp84_;
							_tmp85_ = self->priv->_method;
							_tmp86_ = m;
							_tmp87_ = vala_method_get_this_parameter (_tmp86_);
							_tmp88_ = _tmp87_;
							vala_method_set_this_parameter (_tmp85_, _tmp88_);
							_vala_code_node_unref0 (m);
						}
					}
				}
			}
			_tmp89_ = sym;
			_tmp90_ = vala_symbol_get_parent_symbol (_tmp89_);
			_tmp91_ = _tmp90_;
			_tmp92_ = _vala_code_node_ref0 (_tmp91_);
			_vala_code_node_unref0 (sym);
			sym = _tmp92_;
		}
		_vala_code_node_unref0 (sym);
	}
	_tmp93_ = self->priv->_method;
	_tmp94_ = vala_code_context_get_analyzer (context);
	_tmp95_ = _tmp94_;
	_tmp96_ = vala_semantic_analyzer_get_current_symbol (_tmp95_);
	_tmp97_ = _tmp96_;
	_tmp98_ = vala_symbol_get_scope (_tmp97_);
	_tmp99_ = _tmp98_;
	vala_symbol_set_owner ((ValaSymbol*) _tmp93_, _tmp99_);
	_tmp100_ = self->priv->_method;
	vala_code_node_set_parent_node ((ValaCodeNode*) _tmp100_, (ValaCodeNode*) self);
	_tmp101_ = vala_lambda_expression_get_parameters (self);
	_tmp102_ = _vala_iterable_ref0 (_tmp101_);
	lambda_params = _tmp102_;
	_tmp103_ = lambda_params;
	_tmp104_ = vala_iterable_iterator ((ValaIterable*) _tmp103_);
	lambda_param_it = _tmp104_;
	_tmp106_ = cb;
	_tmp107_ = vala_delegate_get_sender_type (_tmp106_);
	_tmp108_ = _tmp107_;
	if (_tmp108_ != NULL) {
		ValaList* _tmp109_;
		gint _tmp110_;
		gint _tmp111_;
		ValaDelegate* _tmp112_;
		ValaList* _tmp113_;
		gint _tmp114_;
		gint _tmp115_;
		_tmp109_ = lambda_params;
		_tmp110_ = vala_collection_get_size ((ValaCollection*) _tmp109_);
		_tmp111_ = _tmp110_;
		_tmp112_ = cb;
		_tmp113_ = vala_callable_get_parameters ((ValaCallable*) _tmp112_);
		_tmp114_ = vala_collection_get_size ((ValaCollection*) _tmp113_);
		_tmp115_ = _tmp114_;
		_tmp105_ = _tmp111_ == (_tmp115_ + 1);
	} else {
		_tmp105_ = FALSE;
	}
	if (_tmp105_) {
		ValaIterator* _tmp116_;
		ValaParameter* lambda_param = NULL;
		ValaIterator* _tmp117_;
		gpointer _tmp118_;
		ValaParameter* _tmp119_;
		ValaDelegate* _tmp120_;
		ValaDataType* _tmp121_;
		ValaDataType* _tmp122_;
		ValaMethod* _tmp123_;
		ValaParameter* _tmp124_;
		_tmp116_ = lambda_param_it;
		vala_iterator_next (_tmp116_);
		_tmp117_ = lambda_param_it;
		_tmp118_ = vala_iterator_get (_tmp117_);
		lambda_param = (ValaParameter*) _tmp118_;
		_tmp119_ = lambda_param;
		_tmp120_ = cb;
		_tmp121_ = vala_delegate_get_sender_type (_tmp120_);
		_tmp122_ = _tmp121_;
		vala_variable_set_variable_type ((ValaVariable*) _tmp119_, _tmp122_);
		_tmp123_ = self->priv->_method;
		_tmp124_ = lambda_param;
		vala_callable_add_parameter ((ValaCallable*) _tmp123_, _tmp124_);
		_vala_code_node_unref0 (lambda_param);
	}
	{
		ValaList* _cb_param_list = NULL;
		ValaDelegate* _tmp125_;
		ValaList* _tmp126_;
		gint _cb_param_size = 0;
		ValaList* _tmp127_;
		gint _tmp128_;
		gint _tmp129_;
		gint _cb_param_index = 0;
		_tmp125_ = cb;
		_tmp126_ = vala_callable_get_parameters ((ValaCallable*) _tmp125_);
		_cb_param_list = _tmp126_;
		_tmp127_ = _cb_param_list;
		_tmp128_ = vala_collection_get_size ((ValaCollection*) _tmp127_);
		_tmp129_ = _tmp128_;
		_cb_param_size = _tmp129_;
		_cb_param_index = -1;
		while (TRUE) {
			gint _tmp130_;
			gint _tmp131_;
			ValaParameter* cb_param = NULL;
			ValaList* _tmp132_;
			gpointer _tmp133_;
			ValaIterator* _tmp134_;
			ValaParameter* lambda_param = NULL;
			ValaIterator* _tmp135_;
			gpointer _tmp136_;
			ValaParameter* _tmp137_;
			ValaParameterDirection _tmp138_;
			ValaParameterDirection _tmp139_;
			ValaParameter* _tmp140_;
			ValaParameterDirection _tmp141_;
			ValaParameterDirection _tmp142_;
			ValaParameter* _tmp149_;
			ValaParameter* _tmp150_;
			ValaDataType* _tmp151_;
			ValaDataType* _tmp152_;
			ValaDataType* _tmp153_;
			ValaDataType* _tmp154_;
			ValaDataType* _tmp155_;
			ValaDataType* _tmp156_;
			ValaParameter* _tmp157_;
			ValaParameter* _tmp158_;
			ValaMethod* _tmp159_;
			ValaParameter* _tmp160_;
			_cb_param_index = _cb_param_index + 1;
			_tmp130_ = _cb_param_index;
			_tmp131_ = _cb_param_size;
			if (!(_tmp130_ < _tmp131_)) {
				break;
			}
			_tmp132_ = _cb_param_list;
			_tmp133_ = vala_list_get (_tmp132_, _cb_param_index);
			cb_param = (ValaParameter*) _tmp133_;
			_tmp134_ = lambda_param_it;
			if (!vala_iterator_next (_tmp134_)) {
				_vala_code_node_unref0 (cb_param);
				break;
			}
			_tmp135_ = lambda_param_it;
			_tmp136_ = vala_iterator_get (_tmp135_);
			lambda_param = (ValaParameter*) _tmp136_;
			_tmp137_ = lambda_param;
			_tmp138_ = vala_parameter_get_direction (_tmp137_);
			_tmp139_ = _tmp138_;
			_tmp140_ = cb_param;
			_tmp141_ = vala_parameter_get_direction (_tmp140_);
			_tmp142_ = _tmp141_;
			if (_tmp139_ != _tmp142_) {
				ValaParameter* _tmp143_;
				ValaSourceReference* _tmp144_;
				ValaSourceReference* _tmp145_;
				ValaParameter* _tmp146_;
				const gchar* _tmp147_;
				const gchar* _tmp148_;
				vala_code_node_set_error ((ValaCodeNode*) self, TRUE);
				_tmp143_ = lambda_param;
				_tmp144_ = vala_code_node_get_source_reference ((ValaCodeNode*) _tmp143_);
				_tmp145_ = _tmp144_;
				_tmp146_ = lambda_param;
				_tmp147_ = vala_symbol_get_name ((ValaSymbol*) _tmp146_);
				_tmp148_ = _tmp147_;
				vala_report_error (_tmp145_, "direction of parameter `%s' is incompatible with the target delegate", _tmp148_);
			}
			_tmp149_ = lambda_param;
			_tmp150_ = cb_param;
			_tmp151_ = vala_variable_get_variable_type ((ValaVariable*) _tmp150_);
			_tmp152_ = _tmp151_;
			_tmp153_ = vala_expression_get_target_type ((ValaExpression*) self);
			_tmp154_ = _tmp153_;
			_tmp155_ = vala_data_type_get_actual_type (_tmp152_, _tmp154_, NULL, (ValaCodeNode*) self);
			_tmp156_ = _tmp155_;
			vala_variable_set_variable_type ((ValaVariable*) _tmp149_, _tmp156_);
			_vala_code_node_unref0 (_tmp156_);
			_tmp157_ = lambda_param;
			_tmp158_ = cb_param;
			vala_parameter_set_base_parameter (_tmp157_, _tmp158_);
			_tmp159_ = self->priv->_method;
			_tmp160_ = lambda_param;
			vala_callable_add_parameter ((ValaCallable*) _tmp159_, _tmp160_);
			_vala_code_node_unref0 (lambda_param);
			_vala_code_node_unref0 (cb_param);
		}
	}
	_tmp161_ = lambda_param_it;
	if (vala_iterator_next (_tmp161_)) {
		ValaSourceReference* _tmp162_;
		ValaSourceReference* _tmp163_;
		vala_code_node_set_error ((ValaCodeNode*) self, TRUE);
		_tmp162_ = vala_code_node_get_source_reference ((ValaCodeNode*) self);
		_tmp163_ = _tmp162_;
		vala_report_error (_tmp163_, "lambda expression: too many parameters");
		result = FALSE;
		_vala_iterator_unref0 (lambda_param_it);
		_vala_iterable_unref0 (lambda_params);
		_vala_code_node_unref0 (return_type);
		_vala_code_node_unref0 (cb);
		return result;
	}
	_tmp164_ = g_direct_equal;
	_tmp165_ = vala_array_list_new (VALA_TYPE_DATA_TYPE, (GBoxedCopyFunc) vala_code_node_ref, (GDestroyNotify) vala_code_node_unref, _tmp164_);
	error_types = _tmp165_;
	_tmp166_ = cb;
	_tmp167_ = error_types;
	vala_code_node_get_error_types ((ValaCodeNode*) _tmp166_, (ValaCollection*) _tmp167_, NULL);
	{
		ValaArrayList* _error_type_list = NULL;
		ValaArrayList* _tmp168_;
		gint _error_type_size = 0;
		ValaArrayList* _tmp169_;
		gint _tmp170_;
		gint _tmp171_;
		gint _error_type_index = 0;
		_tmp168_ = error_types;
		_error_type_list = _tmp168_;
		_tmp169_ = _error_type_list;
		_tmp170_ = vala_collection_get_size ((ValaCollection*) _tmp169_);
		_tmp171_ = _tmp170_;
		_error_type_size = _tmp171_;
		_error_type_index = -1;
		while (TRUE) {
			gint _tmp172_;
			gint _tmp173_;
			ValaDataType* error_type = NULL;
			ValaArrayList* _tmp174_;
			gpointer _tmp175_;
			ValaMethod* _tmp176_;
			ValaDataType* _tmp177_;
			ValaDataType* _tmp178_;
			ValaDataType* _tmp179_;
			_error_type_index = _error_type_index + 1;
			_tmp172_ = _error_type_index;
			_tmp173_ = _error_type_size;
			if (!(_tmp172_ < _tmp173_)) {
				break;
			}
			_tmp174_ = _error_type_list;
			_tmp175_ = vala_list_get ((ValaList*) _tmp174_, _error_type_index);
			error_type = (ValaDataType*) _tmp175_;
			_tmp176_ = self->priv->_method;
			_tmp177_ = error_type;
			_tmp178_ = vala_data_type_copy (_tmp177_);
			_tmp179_ = _tmp178_;
			vala_method_add_error_type (_tmp176_, _tmp179_);
			_vala_code_node_unref0 (_tmp179_);
			_vala_code_node_unref0 (error_type);
		}
	}
	_tmp180_ = vala_lambda_expression_get_expression_body (self);
	_tmp181_ = _tmp180_;
	if (_tmp181_ != NULL) {
		ValaBlock* block = NULL;
		ValaSourceReference* _tmp182_;
		ValaSourceReference* _tmp183_;
		ValaBlock* _tmp184_;
		ValaBlock* _tmp185_;
		ValaScope* _tmp186_;
		ValaScope* _tmp187_;
		ValaMethod* _tmp188_;
		ValaScope* _tmp189_;
		ValaScope* _tmp190_;
		ValaMethod* _tmp191_;
		ValaDataType* _tmp192_;
		ValaDataType* _tmp193_;
		ValaTypeSymbol* _tmp194_;
		ValaTypeSymbol* _tmp195_;
		ValaMethod* _tmp210_;
		ValaBlock* _tmp211_;
		_tmp182_ = vala_code_node_get_source_reference ((ValaCodeNode*) self);
		_tmp183_ = _tmp182_;
		_tmp184_ = vala_block_new (_tmp183_);
		block = _tmp184_;
		_tmp185_ = block;
		_tmp186_ = vala_symbol_get_scope ((ValaSymbol*) _tmp185_);
		_tmp187_ = _tmp186_;
		_tmp188_ = self->priv->_method;
		_tmp189_ = vala_symbol_get_scope ((ValaSymbol*) _tmp188_);
		_tmp190_ = _tmp189_;
		vala_scope_set_parent_scope (_tmp187_, _tmp190_);
		_tmp191_ = self->priv->_method;
		_tmp192_ = vala_callable_get_return_type ((ValaCallable*) _tmp191_);
		_tmp193_ = _tmp192_;
		_tmp194_ = vala_data_type_get_type_symbol (_tmp193_);
		_tmp195_ = _tmp194_;
		if (_tmp195_ != NULL) {
			ValaBlock* _tmp196_;
			ValaExpression* _tmp197_;
			ValaExpression* _tmp198_;
			ValaSourceReference* _tmp199_;
			ValaSourceReference* _tmp200_;
			ValaReturnStatement* _tmp201_;
			ValaReturnStatement* _tmp202_;
			_tmp196_ = block;
			_tmp197_ = vala_lambda_expression_get_expression_body (self);
			_tmp198_ = _tmp197_;
			_tmp199_ = vala_code_node_get_source_reference ((ValaCodeNode*) self);
			_tmp200_ = _tmp199_;
			_tmp201_ = vala_return_statement_new (_tmp198_, _tmp200_);
			_tmp202_ = _tmp201_;
			vala_block_add_statement (_tmp196_, (ValaStatement*) _tmp202_);
			_vala_code_node_unref0 (_tmp202_);
		} else {
			ValaBlock* _tmp203_;
			ValaExpression* _tmp204_;
			ValaExpression* _tmp205_;
			ValaSourceReference* _tmp206_;
			ValaSourceReference* _tmp207_;
			ValaExpressionStatement* _tmp208_;
			ValaExpressionStatement* _tmp209_;
			_tmp203_ = block;
			_tmp204_ = vala_lambda_expression_get_expression_body (self);
			_tmp205_ = _tmp204_;
			_tmp206_ = vala_code_node_get_source_reference ((ValaCodeNode*) self);
			_tmp207_ = _tmp206_;
			_tmp208_ = vala_expression_statement_new (_tmp205_, _tmp207_);
			_tmp209_ = _tmp208_;
			vala_block_add_statement (_tmp203_, (ValaStatement*) _tmp209_);
			_vala_code_node_unref0 (_tmp209_);
		}
		_tmp210_ = self->priv->_method;
		_tmp211_ = block;
		vala_subroutine_set_body ((ValaSubroutine*) _tmp210_, _tmp211_);
		_vala_code_node_unref0 (block);
	} else {
		ValaMethod* _tmp212_;
		ValaBlock* _tmp213_;
		ValaBlock* _tmp214_;
		_tmp212_ = self->priv->_method;
		_tmp213_ = vala_lambda_expression_get_statement_body (self);
		_tmp214_ = _tmp213_;
		vala_subroutine_set_body ((ValaSubroutine*) _tmp212_, _tmp214_);
	}
	_tmp215_ = self->priv->_method;
	_tmp216_ = vala_subroutine_get_body ((ValaSubroutine*) _tmp215_);
	_tmp217_ = _tmp216_;
	_tmp218_ = self->priv->_method;
	_tmp219_ = vala_symbol_get_scope ((ValaSymbol*) _tmp218_);
	_tmp220_ = _tmp219_;
	vala_symbol_set_owner ((ValaSymbol*) _tmp217_, _tmp220_);
	_tmp221_ = vala_code_context_get_analyzer (context);
	_tmp222_ = _tmp221_;
	_tmp223_ = vala_semantic_analyzer_get_current_symbol (_tmp222_);
	_tmp224_ = _tmp223_;
	_tmp225_ = vala_semantic_analyzer_find_parent_method (_tmp224_);
	m = _tmp225_;
	_tmp226_ = m;
	if (_tmp226_ != NULL) {
		{
			ValaList* _type_param_list = NULL;
			ValaMethod* _tmp227_;
			ValaList* _tmp228_;
			gint _type_param_size = 0;
			ValaList* _tmp229_;
			gint _tmp230_;
			gint _tmp231_;
			gint _type_param_index = 0;
			_tmp227_ = m;
			_tmp228_ = vala_method_get_type_parameters (_tmp227_);
			_type_param_list = _tmp228_;
			_tmp229_ = _type_param_list;
			_tmp230_ = vala_collection_get_size ((ValaCollection*) _tmp229_);
			_tmp231_ = _tmp230_;
			_type_param_size = _tmp231_;
			_type_param_index = -1;
			while (TRUE) {
				gint _tmp232_;
				gint _tmp233_;
				ValaTypeParameter* type_param = NULL;
				ValaList* _tmp234_;
				gpointer _tmp235_;
				ValaMethod* _tmp236_;
				ValaTypeParameter* _tmp237_;
				const gchar* _tmp238_;
				const gchar* _tmp239_;
				ValaTypeParameter* _tmp240_;
				ValaSourceReference* _tmp241_;
				ValaSourceReference* _tmp242_;
				ValaTypeParameter* _tmp243_;
				ValaTypeParameter* _tmp244_;
				ValaMethod* _tmp245_;
				ValaMethod* _tmp246_;
				ValaBlock* _tmp247_;
				ValaBlock* _tmp248_;
				_type_param_index = _type_param_index + 1;
				_tmp232_ = _type_param_index;
				_tmp233_ = _type_param_size;
				if (!(_tmp232_ < _tmp233_)) {
					break;
				}
				_tmp234_ = _type_param_list;
				_tmp235_ = vala_list_get (_tmp234_, _type_param_index);
				type_param = (ValaTypeParameter*) _tmp235_;
				_tmp236_ = self->priv->_method;
				_tmp237_ = type_param;
				_tmp238_ = vala_symbol_get_name ((ValaSymbol*) _tmp237_);
				_tmp239_ = _tmp238_;
				_tmp240_ = type_param;
				_tmp241_ = vala_code_node_get_source_reference ((ValaCodeNode*) _tmp240_);
				_tmp242_ = _tmp241_;
				_tmp243_ = vala_typeparameter_new (_tmp239_, _tmp242_);
				_tmp244_ = _tmp243_;
				vala_method_add_type_parameter (_tmp236_, _tmp244_);
				_vala_code_node_unref0 (_tmp244_);
				_tmp245_ = self->priv->_method;
				vala_method_set_closure (_tmp245_, TRUE);
				_tmp246_ = m;
				_tmp247_ = vala_subroutine_get_body ((ValaSubroutine*) _tmp246_);
				_tmp248_ = _tmp247_;
				vala_block_set_captured (_tmp248_, TRUE);
				_vala_code_node_unref0 (type_param);
			}
		}
	}
	_tmp249_ = self->priv->_method;
	vala_expression_set_symbol_reference ((ValaExpression*) self, (ValaSymbol*) _tmp249_);
	_tmp250_ = self->priv->_method;
	vala_code_node_check ((ValaCodeNode*) _tmp250_, context);
	_tmp251_ = self->priv->_method;
	_tmp252_ = vala_code_node_get_source_reference ((ValaCodeNode*) self);
	_tmp253_ = _tmp252_;
	_tmp254_ = vala_method_type_new (_tmp251_, _tmp253_);
	_tmp255_ = _tmp254_;
	vala_expression_set_value_type ((ValaExpression*) self, (ValaDataType*) _tmp255_);
	_vala_code_node_unref0 (_tmp255_);
	_tmp256_ = vala_expression_get_value_type ((ValaExpression*) self);
	_tmp257_ = _tmp256_;
	_tmp258_ = vala_expression_get_target_type ((ValaExpression*) self);
	_tmp259_ = _tmp258_;
	_tmp260_ = vala_data_type_get_value_owned (_tmp259_);
	_tmp261_ = _tmp260_;
	vala_data_type_set_value_owned (_tmp257_, _tmp261_);
	_tmp262_ = vala_code_node_get_error ((ValaCodeNode*) self);
	_tmp263_ = _tmp262_;
	result = !_tmp263_;
	_vala_iterable_unref0 (error_types);
	_vala_iterator_unref0 (lambda_param_it);
	_vala_iterable_unref0 (lambda_params);
	_vala_code_node_unref0 (return_type);
	_vala_code_node_unref0 (cb);
	return result;
}

static void
vala_lambda_expression_real_emit (ValaCodeNode* base,
                                  ValaCodeGenerator* codegen)
{
	ValaLambdaExpression * self;
	self = (ValaLambdaExpression*) base;
	g_return_if_fail (codegen != NULL);
	vala_code_visitor_visit_lambda_expression ((ValaCodeVisitor*) codegen, self);
	vala_code_visitor_visit_expression ((ValaCodeVisitor*) codegen, (ValaExpression*) self);
}

static void
vala_lambda_expression_real_get_used_variables (ValaCodeNode* base,
                                                ValaCollection* collection)
{
	ValaLambdaExpression * self;
	gboolean _tmp0_ = FALSE;
	ValaMethod* _tmp1_;
	self = (ValaLambdaExpression*) base;
	g_return_if_fail (collection != NULL);
	_tmp1_ = self->priv->_method;
	if (_tmp1_ != NULL) {
		ValaMethod* _tmp2_;
		gboolean _tmp3_;
		gboolean _tmp4_;
		_tmp2_ = self->priv->_method;
		_tmp3_ = vala_method_get_closure (_tmp2_);
		_tmp4_ = _tmp3_;
		_tmp0_ = _tmp4_;
	} else {
		_tmp0_ = FALSE;
	}
	if (_tmp0_) {
		ValaMethod* _tmp5_;
		_tmp5_ = self->priv->_method;
		vala_method_get_captured_variables (_tmp5_, G_TYPE_CHECK_INSTANCE_CAST (collection, VALA_TYPE_COLLECTION, ValaCollection));
	}
}

static void
vala_lambda_expression_class_init (ValaLambdaExpressionClass * klass,
                                   gpointer klass_data)
{
	vala_lambda_expression_parent_class = g_type_class_peek_parent (klass);
	((ValaCodeNodeClass *) klass)->finalize = vala_lambda_expression_finalize;
	g_type_class_adjust_private_offset (klass, &ValaLambdaExpression_private_offset);
	((ValaCodeNodeClass *) klass)->accept = (void (*) (ValaCodeNode*, ValaCodeVisitor*)) vala_lambda_expression_real_accept;
	((ValaCodeNodeClass *) klass)->accept_children = (void (*) (ValaCodeNode*, ValaCodeVisitor*)) vala_lambda_expression_real_accept_children;
	((ValaExpressionClass *) klass)->is_pure = (gboolean (*) (ValaExpression*)) vala_lambda_expression_real_is_pure;
	((ValaCodeNodeClass *) klass)->check = (gboolean (*) (ValaCodeNode*, ValaCodeContext*)) vala_lambda_expression_real_check;
	((ValaCodeNodeClass *) klass)->emit = (void (*) (ValaCodeNode*, ValaCodeGenerator*)) vala_lambda_expression_real_emit;
	((ValaCodeNodeClass *) klass)->get_used_variables = (void (*) (ValaCodeNode*, ValaCollection*)) vala_lambda_expression_real_get_used_variables;
}

static void
vala_lambda_expression_instance_init (ValaLambdaExpression * self,
                                      gpointer klass)
{
	GEqualFunc _tmp0_;
	ValaArrayList* _tmp1_;
	self->priv = vala_lambda_expression_get_instance_private (self);
	_tmp0_ = g_direct_equal;
	_tmp1_ = vala_array_list_new (VALA_TYPE_PARAMETER, (GBoxedCopyFunc) vala_code_node_ref, (GDestroyNotify) vala_code_node_unref, _tmp0_);
	self->priv->parameters = (ValaList*) _tmp1_;
}

static void
vala_lambda_expression_finalize (ValaCodeNode * obj)
{
	ValaLambdaExpression * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, VALA_TYPE_LAMBDA_EXPRESSION, ValaLambdaExpression);
	_vala_code_node_unref0 (self->priv->_method);
	_vala_iterable_unref0 (self->priv->parameters);
	_vala_code_node_unref0 (self->priv->_statement_body);
	_vala_code_node_unref0 (self->priv->_expression_body);
	VALA_CODE_NODE_CLASS (vala_lambda_expression_parent_class)->finalize (obj);
}

/**
 * Represents a lambda expression in the source code.
 *
 * Lambda expressions are anonymous methods with implicitly typed parameters.
 */
static GType
vala_lambda_expression_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (ValaLambdaExpressionClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) vala_lambda_expression_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (ValaLambdaExpression), 0, (GInstanceInitFunc) vala_lambda_expression_instance_init, NULL };
	GType vala_lambda_expression_type_id;
	vala_lambda_expression_type_id = g_type_register_static (VALA_TYPE_EXPRESSION, "ValaLambdaExpression", &g_define_type_info, 0);
	ValaLambdaExpression_private_offset = g_type_add_instance_private (vala_lambda_expression_type_id, sizeof (ValaLambdaExpressionPrivate));
	return vala_lambda_expression_type_id;
}

GType
vala_lambda_expression_get_type (void)
{
	static volatile gsize vala_lambda_expression_type_id__once = 0;
	if (g_once_init_enter (&vala_lambda_expression_type_id__once)) {
		GType vala_lambda_expression_type_id;
		vala_lambda_expression_type_id = vala_lambda_expression_get_type_once ();
		g_once_init_leave (&vala_lambda_expression_type_id__once, vala_lambda_expression_type_id);
	}
	return vala_lambda_expression_type_id__once;
}

