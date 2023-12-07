/* ccode.vapi generated by valac, do not modify. */

namespace Vala {
	[CCode (cheader_filename = "valaccode.h")]
	public class CCodeAssignment : Vala.CCodeExpression {
		public CCodeAssignment (Vala.CCodeExpression l, Vala.CCodeExpression r, Vala.CCodeAssignmentOperator op = CCodeAssignmentOperator.SIMPLE);
		public override void write (Vala.CCodeWriter writer);
		public override void write_inner (Vala.CCodeWriter writer);
		public Vala.CCodeExpression left { get; set; }
		public Vala.CCodeAssignmentOperator operator { get; set; }
		public Vala.CCodeExpression right { get; set; }
	}
	[CCode (cheader_filename = "valaccode.h")]
	public class CCodeBinaryCompareExpression : Vala.CCodeBinaryExpression {
		public CCodeBinaryCompareExpression (Vala.CCodeExpression cmp, Vala.CCodeBinaryOperator op, Vala.CCodeExpression l, Vala.CCodeExpression r, Vala.CCodeExpression res);
		public override void write (Vala.CCodeWriter writer);
		public Vala.CCodeExpression call { get; set; }
		public Vala.CCodeExpression result { get; set; }
	}
	[CCode (cheader_filename = "valaccode.h")]
	public class CCodeBinaryExpression : Vala.CCodeExpression {
		public CCodeBinaryExpression (Vala.CCodeBinaryOperator op, Vala.CCodeExpression l, Vala.CCodeExpression r);
		public override void write (Vala.CCodeWriter writer);
		public override void write_inner (Vala.CCodeWriter writer);
		public Vala.CCodeExpression left { get; set; }
		public Vala.CCodeBinaryOperator operator { get; set; }
		public Vala.CCodeExpression right { get; set; }
	}
	[CCode (cheader_filename = "valaccode.h")]
	public class CCodeBlock : Vala.CCodeStatement {
		public CCodeBlock ();
		public void add_statement (Vala.CCodeNode statement);
		public void prepend_statement (Vala.CCodeNode statement);
		public override void write (Vala.CCodeWriter writer);
		public bool suppress_newline { get; set; }
	}
	[CCode (cheader_filename = "valaccode.h")]
	public class CCodeBreakStatement : Vala.CCodeStatement {
		public CCodeBreakStatement ();
		public override void write (Vala.CCodeWriter writer);
	}
	[CCode (cheader_filename = "valaccode.h")]
	public class CCodeCaseStatement : Vala.CCodeStatement {
		public CCodeCaseStatement (Vala.CCodeExpression expression);
		public override void write (Vala.CCodeWriter writer);
		public Vala.CCodeExpression expression { get; set; }
	}
	[CCode (cheader_filename = "valaccode.h")]
	public class CCodeCastExpression : Vala.CCodeExpression {
		public CCodeCastExpression (Vala.CCodeExpression expr, string type);
		public override void write (Vala.CCodeWriter writer);
		public override void write_inner (Vala.CCodeWriter writer);
		public Vala.CCodeExpression inner { get; set; }
		public string type_name { get; set; }
	}
	[CCode (cheader_filename = "valaccode.h")]
	public class CCodeCommaExpression : Vala.CCodeExpression {
		public CCodeCommaExpression ();
		public void append_expression (Vala.CCodeExpression expr);
		public unowned Vala.List<Vala.CCodeExpression> get_inner ();
		public void set_expression (int index, Vala.CCodeExpression expr);
		public override void write (Vala.CCodeWriter writer);
	}
	[CCode (cheader_filename = "valaccode.h")]
	public class CCodeComment : Vala.CCodeNode {
		public CCodeComment (string _text);
		public override void write (Vala.CCodeWriter writer);
		public string text { get; set; }
	}
	[CCode (cheader_filename = "valaccode.h")]
	public class CCodeConditionalExpression : Vala.CCodeExpression {
		public CCodeConditionalExpression (Vala.CCodeExpression cond, Vala.CCodeExpression true_expr, Vala.CCodeExpression false_expr);
		public override void write (Vala.CCodeWriter writer);
		public override void write_inner (Vala.CCodeWriter writer);
		public Vala.CCodeExpression condition { get; set; }
		public Vala.CCodeExpression false_expression { get; set; }
		public Vala.CCodeExpression true_expression { get; set; }
	}
	[CCode (cheader_filename = "valaccode.h")]
	public class CCodeConstant : Vala.CCodeExpression {
		public CCodeConstant (global::string _name);
		public CCodeConstant.string (global::string _name);
		public override void write (Vala.CCodeWriter writer);
		public global::string name { get; set; }
	}
	[CCode (cheader_filename = "valaccode.h")]
	public class CCodeConstantIdentifier : Vala.CCodeIdentifier {
		public CCodeConstantIdentifier (string name);
	}
	[CCode (cheader_filename = "valaccode.h")]
	public class CCodeContinueStatement : Vala.CCodeStatement {
		public CCodeContinueStatement ();
		public override void write (Vala.CCodeWriter writer);
	}
	[CCode (cheader_filename = "valaccode.h")]
	public class CCodeDeclaration : Vala.CCodeStatement {
		public CCodeDeclaration (string type_name);
		public void add_declarator (Vala.CCodeDeclarator decl);
		public unowned Vala.List<Vala.CCodeDeclarator> get_declarators ();
		public override void write (Vala.CCodeWriter writer);
		public override void write_declaration (Vala.CCodeWriter writer);
		public string type_name { get; set; }
	}
	[CCode (cheader_filename = "valaccode.h")]
	public abstract class CCodeDeclarator : Vala.CCodeNode {
		protected CCodeDeclarator ();
		public virtual void write_initialization (Vala.CCodeWriter writer);
		public string name { get; set; }
	}
	[CCode (cheader_filename = "valaccode.h")]
	public class CCodeDeclaratorSuffix {
		public CCodeDeclaratorSuffix ();
		public CCodeDeclaratorSuffix.with_array (Vala.CCodeExpression? array_length = null);
		public CCodeDeclaratorSuffix.with_multi_array (Vala.List<Vala.CCodeExpression>? array_length = null);
		public void write (Vala.CCodeWriter writer);
	}
	[CCode (cheader_filename = "valaccode.h")]
	public class CCodeDefine : Vala.CCodeNode {
		public CCodeDefine (string name, string? value = null);
		public CCodeDefine.with_expression (string name, Vala.CCodeExpression expression);
		public override void write (Vala.CCodeWriter writer);
		public string name { get; set; }
		public string? value { get; set; }
		public Vala.CCodeExpression? value_expression { get; set; }
	}
	[CCode (cheader_filename = "valaccode.h")]
	public class CCodeDoStatement : Vala.CCodeStatement {
		public CCodeDoStatement (Vala.CCodeStatement stmt, Vala.CCodeExpression cond);
		public override void write (Vala.CCodeWriter writer);
		public Vala.CCodeStatement body { get; set; }
		public Vala.CCodeExpression condition { get; set; }
	}
	[CCode (cheader_filename = "valaccode.h")]
	public class CCodeElementAccess : Vala.CCodeExpression {
		public CCodeElementAccess (Vala.CCodeExpression cont, Vala.CCodeExpression i);
		public CCodeElementAccess.with_indices (Vala.CCodeExpression cont, Vala.List<Vala.CCodeExpression> i);
		public override void write (Vala.CCodeWriter writer);
		public Vala.CCodeExpression container { get; set; }
		public Vala.List<Vala.CCodeExpression> indices { get; set; }
	}
	[CCode (cheader_filename = "valaccode.h")]
	public class CCodeEmptyStatement : Vala.CCodeStatement {
		public CCodeEmptyStatement ();
		public override void write (Vala.CCodeWriter writer);
	}
	[CCode (cheader_filename = "valaccode.h")]
	public class CCodeEnum : Vala.CCodeNode {
		public CCodeEnum (string? name = null);
		public void add_value (Vala.CCodeEnumValue value);
		public override void write (Vala.CCodeWriter writer);
		public string name { get; set; }
	}
	[CCode (cheader_filename = "valaccode.h")]
	public class CCodeEnumValue : Vala.CCodeNode {
		public CCodeEnumValue (string name, Vala.CCodeExpression? value = null);
		public override void write (Vala.CCodeWriter writer);
		public string name { get; set; }
		public Vala.CCodeExpression? value { get; set; }
	}
	[CCode (cheader_filename = "valaccode.h")]
	public abstract class CCodeExpression : Vala.CCodeNode {
		protected CCodeExpression ();
		public virtual void write_inner (Vala.CCodeWriter writer);
	}
	[CCode (cheader_filename = "valaccode.h")]
	public class CCodeExpressionStatement : Vala.CCodeStatement {
		public CCodeExpressionStatement (Vala.CCodeExpression expr);
		public override void write (Vala.CCodeWriter writer);
		public Vala.CCodeExpression expression { get; set; }
	}
	[CCode (cheader_filename = "valaccode.h")]
	public class CCodeFile {
		public CCodeFile (CCodeFileType type = CCodeFileType.SOURCE, Vala.SourceFile? source_file = null);
		public void add_comment (Vala.CCodeComment comment);
		public void add_constant_declaration (Vala.CCodeNode node);
		public bool add_declaration (string name);
		public void add_define (Vala.CCodeNode node);
		public void add_feature_test_macro (string feature_test_macro);
		public void add_function (Vala.CCodeFunction func);
		public void add_function_declaration (Vala.CCodeFunction func);
		public void add_include (string filename, bool local = false);
		public void add_type_declaration (Vala.CCodeNode node);
		public void add_type_definition (Vala.CCodeNode node);
		public void add_type_member_declaration (Vala.CCodeNode node);
		public void add_type_member_definition (Vala.CCodeNode node);
		public Vala.List<string> get_symbols ();
		public bool store (string filename, string? source_filename, bool write_version, bool line_directives, string? begin_decls = null, string? end_decls = null);
		public weak Vala.SourceFile? file { get; private set; }
		public CCodeFileType file_type { get; private set; }
	}
	[CCode (cheader_filename = "valaccode.h")]
	public class CCodeForStatement : Vala.CCodeStatement {
		public CCodeForStatement (Vala.CCodeExpression? condition, Vala.CCodeStatement? body = null);
		public void add_initializer (Vala.CCodeExpression expr);
		public void add_iterator (Vala.CCodeExpression expr);
		public override void write (Vala.CCodeWriter writer);
		public Vala.CCodeStatement body { get; set; }
		public Vala.CCodeExpression? condition { get; set; }
	}
	[CCode (cheader_filename = "valaccode.h")]
	public class CCodeFragment : Vala.CCodeNode {
		public CCodeFragment ();
		public void append (Vala.CCodeNode node);
		public unowned Vala.List<Vala.CCodeNode> get_children ();
		public override void write (Vala.CCodeWriter writer);
		public override void write_combined (Vala.CCodeWriter writer);
		public override void write_declaration (Vala.CCodeWriter writer);
	}
	[CCode (cheader_filename = "valaccode.h")]
	public class CCodeFunction : Vala.CCodeNode {
		public CCodeFunction (string name, string return_type = "void");
		public void add_assignment (Vala.CCodeExpression left, Vala.CCodeExpression right);
		public void add_break ();
		public void add_case (Vala.CCodeExpression expression);
		public void add_continue ();
		public void add_declaration (string type_name, Vala.CCodeDeclarator declarator, Vala.CCodeModifiers modifiers = 0);
		public void add_default ();
		public void add_else ();
		public void add_expression (Vala.CCodeExpression expression);
		public void add_goto (string target);
		public void add_label (string label);
		public void add_parameter (Vala.CCodeParameter param);
		public void add_return (Vala.CCodeExpression? expression = null);
		public void add_statement (Vala.CCodeNode stmt);
		public void close ();
		public Vala.CCodeFunction copy ();
		public void else_if (Vala.CCodeExpression condition);
		public Vala.CCodeParameter get_parameter (int position);
		public int get_parameter_count ();
		public void insert_parameter (int position, Vala.CCodeParameter param);
		public void open_block ();
		public void open_for (Vala.CCodeExpression? initializer, Vala.CCodeExpression condition, Vala.CCodeExpression? iterator);
		public void open_if (Vala.CCodeExpression condition);
		public void open_switch (Vala.CCodeExpression expression);
		public void open_while (Vala.CCodeExpression condition);
		public override void write (Vala.CCodeWriter writer);
		public Vala.CCodeBlock block { get; set; }
		public Vala.CCodeBlock current_block { get; set; }
		public Vala.CCodeLineDirective current_line { get; set; }
		public bool is_declaration { get; set; }
		public string name { get; set; }
		public string return_type { get; set; }
	}
	[CCode (cheader_filename = "valaccode.h")]
	public class CCodeFunctionCall : Vala.CCodeExpression {
		public CCodeFunctionCall (Vala.CCodeExpression? call = null);
		public void add_argument (Vala.CCodeExpression expr);
		public unowned Vala.List<Vala.CCodeExpression> get_arguments ();
		public void insert_argument (int index, Vala.CCodeExpression expr);
		public override void write (Vala.CCodeWriter writer);
		public Vala.CCodeExpression? call { get; set; }
	}
	[CCode (cheader_filename = "valaccode.h")]
	public class CCodeFunctionDeclarator : Vala.CCodeDeclarator {
		public CCodeFunctionDeclarator (string name);
		public void add_parameter (Vala.CCodeParameter param);
		public override void write (Vala.CCodeWriter writer);
		public override void write_declaration (Vala.CCodeWriter writer);
	}
	[CCode (cheader_filename = "valaccode.h")]
	public class CCodeGGnucSection : Vala.CCodeFragment {
		public CCodeGGnucSection (Vala.GGnucSectionType t);
		public override void write (Vala.CCodeWriter writer);
		public override void write_declaration (Vala.CCodeWriter writer);
		public Vala.GGnucSectionType section_type { get; set; }
	}
	[CCode (cheader_filename = "valaccode.h")]
	public class CCodeGotoStatement : Vala.CCodeStatement {
		public CCodeGotoStatement (string name);
		public override void write (Vala.CCodeWriter writer);
		public string name { get; set; }
	}
	[CCode (cheader_filename = "valaccode.h")]
	public class CCodeIdentifier : Vala.CCodeExpression {
		public CCodeIdentifier (string _name);
		public override void write (Vala.CCodeWriter writer);
		public string name { get; set; }
	}
	[CCode (cheader_filename = "valaccode.h")]
	public class CCodeIfSection : Vala.CCodeFragment {
		public CCodeIfSection (string? expr);
		public unowned Vala.CCodeIfSection append_else (string? expr = null);
		public override void write (Vala.CCodeWriter writer);
		public override void write_combined (Vala.CCodeWriter writer);
		public override void write_declaration (Vala.CCodeWriter writer);
		public string? expression { get; set; }
	}
	[CCode (cheader_filename = "valaccode.h")]
	public class CCodeIfStatement : Vala.CCodeStatement {
		public CCodeIfStatement (Vala.CCodeExpression cond, Vala.CCodeStatement true_stmt, Vala.CCodeStatement? false_stmt = null);
		public override void write (Vala.CCodeWriter writer);
		public Vala.CCodeExpression condition { get; set; }
		public bool else_if { get; set; }
		public Vala.CCodeStatement? false_statement { get; set; }
		public Vala.CCodeStatement true_statement { get; set; }
	}
	[CCode (cheader_filename = "valaccode.h")]
	public class CCodeIncludeDirective : Vala.CCodeNode {
		public CCodeIncludeDirective (string _filename, bool _local = false);
		public override void write (Vala.CCodeWriter writer);
		public string filename { get; set; }
		public bool local { get; set; }
	}
	[CCode (cheader_filename = "valaccode.h")]
	public class CCodeInitializerList : Vala.CCodeExpression {
		public CCodeInitializerList ();
		public void append (Vala.CCodeExpression expr);
		public override void write (Vala.CCodeWriter writer);
	}
	[CCode (cheader_filename = "valaccode.h")]
	public class CCodeInvalidExpression : Vala.CCodeExpression {
		public CCodeInvalidExpression ();
		public override void write (Vala.CCodeWriter writer);
	}
	[CCode (cheader_filename = "valaccode.h")]
	public class CCodeLabel : Vala.CCodeStatement {
		public CCodeLabel (string name);
		public override void write (Vala.CCodeWriter writer);
		public string name { get; set; }
	}
	[CCode (cheader_filename = "valaccode.h")]
	public class CCodeLineDirective : Vala.CCodeNode {
		public CCodeLineDirective (string _filename, int _line);
		public override void write (Vala.CCodeWriter writer);
		public string filename { get; set; }
		public int line_number { get; set; }
	}
	[CCode (cheader_filename = "valaccode.h")]
	public class CCodeMacroReplacement : Vala.CCodeDefine {
		public CCodeMacroReplacement (string name, string replacement);
		public CCodeMacroReplacement.with_expression (string name, Vala.CCodeExpression replacement_expression);
	}
	[CCode (cheader_filename = "valaccode.h")]
	public class CCodeMemberAccess : Vala.CCodeExpression {
		public CCodeMemberAccess (Vala.CCodeExpression container, string member, bool pointer = false);
		public CCodeMemberAccess.pointer (Vala.CCodeExpression container, string member);
		public override void write (Vala.CCodeWriter writer);
		public Vala.CCodeExpression inner { get; set; }
		public bool is_pointer { get; set; }
		public string member_name { get; set; }
	}
	[CCode (cheader_filename = "valaccode.h")]
	public class CCodeNewline : Vala.CCodeNode {
		public CCodeNewline ();
		public override void write (Vala.CCodeWriter writer);
	}
	[CCode (cheader_filename = "valaccode.h")]
	public abstract class CCodeNode {
		protected CCodeNode ();
		public abstract void write (Vala.CCodeWriter writer);
		public virtual void write_combined (Vala.CCodeWriter writer);
		public virtual void write_declaration (Vala.CCodeWriter writer);
		public Vala.CCodeLineDirective line { get; set; }
		public Vala.CCodeModifiers modifiers { get; set; }
	}
	[CCode (cheader_filename = "valaccode.h")]
	public class CCodeOnceSection : Vala.CCodeFragment {
		public CCodeOnceSection (string def);
		public override void write (Vala.CCodeWriter writer);
		public override void write_declaration (Vala.CCodeWriter writer);
		public string define { get; set; }
	}
	[CCode (cheader_filename = "valaccode.h")]
	public class CCodeParameter : Vala.CCodeNode {
		public CCodeParameter (string n, string type);
		public CCodeParameter.with_declarator (string type, Vala.CCodeDeclarator decl);
		public CCodeParameter.with_ellipsis ();
		public override void write (Vala.CCodeWriter writer);
		public bool ellipsis { get; set; }
		public string name { get; set; }
		public string type_name { get; set; }
	}
	[CCode (cheader_filename = "valaccode.h")]
	public class CCodeParenthesizedExpression : Vala.CCodeExpression {
		public CCodeParenthesizedExpression (Vala.CCodeExpression expr);
		public override void write (Vala.CCodeWriter writer);
		public Vala.CCodeExpression inner { get; set; }
	}
	[CCode (cheader_filename = "valaccode.h")]
	public class CCodeReturnStatement : Vala.CCodeStatement {
		public CCodeReturnStatement (Vala.CCodeExpression? expr = null);
		public override void write (Vala.CCodeWriter writer);
		public Vala.CCodeExpression? return_expression { get; set; }
	}
	[CCode (cheader_filename = "valaccode.h")]
	public abstract class CCodeStatement : Vala.CCodeNode {
		protected CCodeStatement ();
	}
	[CCode (cheader_filename = "valaccode.h")]
	public class CCodeStruct : Vala.CCodeNode {
		public CCodeStruct (string name);
		public void add_declaration (Vala.CCodeDeclaration decl);
		public void add_field (string type_name, string name, Vala.CCodeModifiers modifiers = 0, Vala.CCodeDeclaratorSuffix? declarator_suffix = null);
		public override void write (Vala.CCodeWriter writer);
		public bool is_empty { get; }
		public string name { get; set; }
	}
	[CCode (cheader_filename = "valaccode.h")]
	public class CCodeSwitchStatement : Vala.CCodeBlock {
		public CCodeSwitchStatement (Vala.CCodeExpression expression);
		public override void write (Vala.CCodeWriter writer);
		public Vala.CCodeExpression expression { get; set; }
	}
	[CCode (cheader_filename = "valaccode.h")]
	public class CCodeTypeDefinition : Vala.CCodeNode {
		public CCodeTypeDefinition (string type, Vala.CCodeDeclarator decl);
		public override void write (Vala.CCodeWriter writer);
		public override void write_declaration (Vala.CCodeWriter writer);
		public Vala.CCodeDeclarator declarator { get; set; }
		public string type_name { get; set; }
	}
	[CCode (cheader_filename = "valaccode.h")]
	public class CCodeUnaryExpression : Vala.CCodeExpression {
		public CCodeUnaryExpression (Vala.CCodeUnaryOperator op, Vala.CCodeExpression expr);
		public override void write (Vala.CCodeWriter writer);
		public override void write_inner (Vala.CCodeWriter writer);
		public Vala.CCodeExpression inner { get; set; }
		public Vala.CCodeUnaryOperator operator { get; set; }
	}
	[CCode (cheader_filename = "valaccode.h")]
	public class CCodeVariableDeclarator : Vala.CCodeDeclarator {
		public CCodeVariableDeclarator (string name, Vala.CCodeExpression? initializer = null, Vala.CCodeDeclaratorSuffix? declarator_suffix = null);
		public override void write (Vala.CCodeWriter writer);
		public override void write_declaration (Vala.CCodeWriter writer);
		public override void write_initialization (Vala.CCodeWriter writer);
		public CCodeVariableDeclarator.zero (string name, Vala.CCodeExpression? initializer, Vala.CCodeDeclaratorSuffix? declarator_suffix = null);
		public Vala.CCodeDeclaratorSuffix? declarator_suffix { get; set; }
		public bool init0 { get; set; }
		public Vala.CCodeExpression? initializer { get; set; }
	}
	[CCode (cheader_filename = "valaccode.h")]
	public class CCodeWhileStatement : Vala.CCodeStatement {
		public CCodeWhileStatement (Vala.CCodeExpression cond, Vala.CCodeStatement? stmt = null);
		public override void write (Vala.CCodeWriter writer);
		public Vala.CCodeStatement body { get; set; }
		public Vala.CCodeExpression condition { get; set; }
	}
	[CCode (cheader_filename = "valaccode.h")]
	public class CCodeWriter {
		public CCodeWriter (string filename, string? source_filename = null);
		public void close ();
		public bool open (bool write_version);
		public void write_begin_block ();
		public void write_comment (string text);
		public void write_end_block ();
		public void write_indent (Vala.CCodeLineDirective? line = null);
		public void write_newline ();
		public void write_nspaces (uint n);
		public void write_string (string s);
		public bool bol { get; }
		public string filename { get; set; }
		public bool line_directives { get; set; }
	}
	[CCode (cheader_filename = "valaccode.h")]
	public enum CCodeAssignmentOperator {
		SIMPLE,
		BITWISE_OR,
		BITWISE_AND,
		BITWISE_XOR,
		ADD,
		SUB,
		MUL,
		DIV,
		PERCENT,
		SHIFT_LEFT,
		SHIFT_RIGHT
	}
	[CCode (cheader_filename = "valaccode.h")]
	public enum CCodeBinaryOperator {
		PLUS,
		MINUS,
		MUL,
		DIV,
		MOD,
		SHIFT_LEFT,
		SHIFT_RIGHT,
		LESS_THAN,
		GREATER_THAN,
		LESS_THAN_OR_EQUAL,
		GREATER_THAN_OR_EQUAL,
		EQUALITY,
		INEQUALITY,
		BITWISE_AND,
		BITWISE_OR,
		BITWISE_XOR,
		AND,
		OR
	}
	[CCode (cheader_filename = "valaccode.h")]
	[Flags]
	public enum CCodeModifiers {
		NONE,
		STATIC,
		REGISTER,
		EXTERN,
		INLINE,
		VOLATILE,
		DEPRECATED,
		THREAD_LOCAL,
		INTERNAL,
		CONST,
		UNUSED,
		CONSTRUCTOR,
		DESTRUCTOR,
		FORMAT_ARG,
		PRINTF,
		SCANF,
		NO_INLINE
	}
	[CCode (cheader_filename = "valaccode.h")]
	public enum CCodeUnaryOperator {
		PLUS,
		MINUS,
		LOGICAL_NEGATION,
		BITWISE_COMPLEMENT,
		POINTER_INDIRECTION,
		ADDRESS_OF,
		PREFIX_INCREMENT,
		PREFIX_DECREMENT,
		POSTFIX_INCREMENT,
		POSTFIX_DECREMENT
	}
	[CCode (cheader_filename = "valaccode.h")]
	public enum GGnucSectionType {
		IGNORE_DEPRECATIONS;
		public unowned string to_string ();
	}
	[CCode (cheader_filename = "valaccode.h")]
	public static weak string GNUC_CONST;
	[CCode (cheader_filename = "valaccode.h")]
	public static weak string GNUC_DEPRECATED;
	[CCode (cheader_filename = "valaccode.h")]
	public static weak string GNUC_FORMAT;
	[CCode (cheader_filename = "valaccode.h")]
	public static weak string GNUC_INTERNAL;
	[CCode (cheader_filename = "valaccode.h")]
	public static weak string GNUC_NO_INLINE;
	[CCode (cheader_filename = "valaccode.h")]
	public static weak string GNUC_PRINTF;
	[CCode (cheader_filename = "valaccode.h")]
	public static weak string GNUC_SCANF;
	[CCode (cheader_filename = "valaccode.h")]
	public static weak string GNUC_UNUSED;
	[CCode (cheader_filename = "valaccode.h")]
	public static void ccode_init (Vala.Profile profile);
}
[CCode (cheader_filename = "valaccode.h")]
[Flags]
public enum CCodeFileType {
	SOURCE,
	PUBLIC_HEADER,
	INTERNAL_HEADER,
	HEADER
}
