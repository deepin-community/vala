/* valaswitchlabel.c generated by valac, the Vala compiler
 * generated from valaswitchlabel.vala, do not modify */

/* valaswitchlabel.vala
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
#include <glib.h>
#include <glib-object.h>
#include <valagee.h>
#include <stdlib.h>
#include <string.h>

#define _vala_code_node_unref0(var) ((var == NULL) ? NULL : (var = (vala_code_node_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))

struct _ValaSwitchLabelPrivate {
	ValaExpression* _expression;
};

static gint ValaSwitchLabel_private_offset;
static gpointer vala_switch_label_parent_class = NULL;

static void vala_switch_label_set_expression (ValaSwitchLabel* self,
                                       ValaExpression* value);
static void vala_switch_label_real_accept (ValaCodeNode* base,
                                    ValaCodeVisitor* visitor);
static void vala_switch_label_real_accept_children (ValaCodeNode* base,
                                             ValaCodeVisitor* visitor);
static gboolean vala_switch_label_real_check (ValaCodeNode* base,
                                       ValaCodeContext* context);
static void vala_switch_label_real_emit (ValaCodeNode* base,
                                  ValaCodeGenerator* codegen);
static void vala_switch_label_finalize (ValaCodeNode * obj);
static GType vala_switch_label_get_type_once (void);

static inline gpointer
vala_switch_label_get_instance_private (ValaSwitchLabel* self)
{
	return G_STRUCT_MEMBER_P (self, ValaSwitchLabel_private_offset);
}

ValaExpression*
vala_switch_label_get_expression (ValaSwitchLabel* self)
{
	ValaExpression* result;
	ValaExpression* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_expression;
	result = _tmp0_;
	return result;
}

static gpointer
_vala_code_node_ref0 (gpointer self)
{
	return self ? vala_code_node_ref (self) : NULL;
}

static void
vala_switch_label_set_expression (ValaSwitchLabel* self,
                                  ValaExpression* value)
{
	ValaExpression* _tmp0_;
	ValaExpression* _tmp1_;
	g_return_if_fail (self != NULL);
	_tmp0_ = _vala_code_node_ref0 (value);
	_vala_code_node_unref0 (self->priv->_expression);
	self->priv->_expression = _tmp0_;
	_tmp1_ = self->priv->_expression;
	vala_code_node_set_parent_node ((ValaCodeNode*) _tmp1_, (ValaCodeNode*) self);
}

ValaSwitchSection*
vala_switch_label_get_section (ValaSwitchLabel* self)
{
	ValaSwitchSection* result;
	ValaCodeNode* _tmp0_;
	ValaCodeNode* _tmp1_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = vala_code_node_get_parent_node ((ValaCodeNode*) self);
	_tmp1_ = _tmp0_;
	result = G_TYPE_CHECK_INSTANCE_CAST (_tmp1_, VALA_TYPE_SWITCH_SECTION, ValaSwitchSection);
	return result;
}

/**
 * Creates a new switch case label.
 *
 * @param expr   label expression
 * @param source reference to source code
 * @return       newly created switch case label
 */
ValaSwitchLabel*
vala_switch_label_construct (GType object_type,
                             ValaExpression* expr,
                             ValaSourceReference* source)
{
	ValaSwitchLabel* self = NULL;
	g_return_val_if_fail (expr != NULL, NULL);
	self = (ValaSwitchLabel*) vala_code_node_construct (object_type);
	vala_switch_label_set_expression (self, expr);
	vala_code_node_set_source_reference ((ValaCodeNode*) self, source);
	return self;
}

ValaSwitchLabel*
vala_switch_label_new (ValaExpression* expr,
                       ValaSourceReference* source)
{
	return vala_switch_label_construct (VALA_TYPE_SWITCH_LABEL, expr, source);
}

/**
 * Creates a new switch default label.
 *
 * @param source reference to source code
 * @return       newly created switch default label
 */
ValaSwitchLabel*
vala_switch_label_construct_with_default (GType object_type,
                                          ValaSourceReference* source)
{
	ValaSwitchLabel* self = NULL;
	self = (ValaSwitchLabel*) vala_code_node_construct (object_type);
	vala_code_node_set_source_reference ((ValaCodeNode*) self, source);
	return self;
}

ValaSwitchLabel*
vala_switch_label_new_with_default (ValaSourceReference* source)
{
	return vala_switch_label_construct_with_default (VALA_TYPE_SWITCH_LABEL, source);
}

static void
vala_switch_label_real_accept (ValaCodeNode* base,
                               ValaCodeVisitor* visitor)
{
	ValaSwitchLabel * self;
	self = (ValaSwitchLabel*) base;
	g_return_if_fail (visitor != NULL);
	vala_code_visitor_visit_switch_label (visitor, self);
}

static void
vala_switch_label_real_accept_children (ValaCodeNode* base,
                                        ValaCodeVisitor* visitor)
{
	ValaSwitchLabel * self;
	ValaExpression* _tmp0_;
	ValaExpression* _tmp1_;
	self = (ValaSwitchLabel*) base;
	g_return_if_fail (visitor != NULL);
	_tmp0_ = vala_switch_label_get_expression (self);
	_tmp1_ = _tmp0_;
	if (_tmp1_ != NULL) {
		ValaExpression* _tmp2_;
		ValaExpression* _tmp3_;
		ValaExpression* _tmp4_;
		ValaExpression* _tmp5_;
		_tmp2_ = vala_switch_label_get_expression (self);
		_tmp3_ = _tmp2_;
		vala_code_node_accept ((ValaCodeNode*) _tmp3_, visitor);
		_tmp4_ = vala_switch_label_get_expression (self);
		_tmp5_ = _tmp4_;
		vala_code_visitor_visit_end_full_expression (visitor, _tmp5_);
	}
}

static gboolean
vala_switch_label_real_check (ValaCodeNode* base,
                              ValaCodeContext* context)
{
	ValaSwitchLabel * self;
	gboolean _tmp0_;
	gboolean _tmp1_;
	ValaExpression* _tmp4_;
	ValaExpression* _tmp5_;
	gboolean result;
	self = (ValaSwitchLabel*) base;
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
	_tmp4_ = vala_switch_label_get_expression (self);
	_tmp5_ = _tmp4_;
	if (_tmp5_ != NULL) {
		ValaSwitchStatement* switch_statement = NULL;
		ValaSwitchSection* _tmp6_;
		ValaSwitchSection* _tmp7_;
		ValaCodeNode* _tmp8_;
		ValaCodeNode* _tmp9_;
		ValaSwitchStatement* _tmp10_;
		ValaDataType* condition_target_type = NULL;
		ValaSwitchStatement* _tmp11_;
		ValaExpression* _tmp12_;
		ValaExpression* _tmp13_;
		ValaDataType* _tmp14_;
		ValaDataType* _tmp15_;
		ValaDataType* _tmp16_;
		gboolean _tmp17_ = FALSE;
		gboolean _tmp18_ = FALSE;
		ValaExpression* _tmp19_;
		ValaExpression* _tmp20_;
		ValaSymbol* _tmp21_;
		ValaSymbol* _tmp22_;
		ValaExpression* _tmp56_;
		ValaExpression* _tmp57_;
		ValaExpression* _tmp58_;
		ValaExpression* _tmp59_;
		ValaExpression* _tmp64_;
		ValaExpression* _tmp65_;
		ValaDataType* _tmp66_;
		ValaDataType* _tmp67_;
		ValaSwitchStatement* _tmp68_;
		ValaExpression* _tmp69_;
		ValaExpression* _tmp70_;
		ValaDataType* _tmp71_;
		ValaDataType* _tmp72_;
		_tmp6_ = vala_switch_label_get_section (self);
		_tmp7_ = _tmp6_;
		_tmp8_ = vala_code_node_get_parent_node ((ValaCodeNode*) _tmp7_);
		_tmp9_ = _tmp8_;
		_tmp10_ = _vala_code_node_ref0 (G_TYPE_CHECK_INSTANCE_CAST (_tmp9_, VALA_TYPE_SWITCH_STATEMENT, ValaSwitchStatement));
		switch_statement = _tmp10_;
		_tmp11_ = switch_statement;
		_tmp12_ = vala_switch_statement_get_expression (_tmp11_);
		_tmp13_ = _tmp12_;
		_tmp14_ = vala_expression_get_target_type (_tmp13_);
		_tmp15_ = _tmp14_;
		_tmp16_ = _vala_code_node_ref0 (_tmp15_);
		condition_target_type = _tmp16_;
		_tmp19_ = vala_switch_label_get_expression (self);
		_tmp20_ = _tmp19_;
		_tmp21_ = vala_expression_get_symbol_reference (_tmp20_);
		_tmp22_ = _tmp21_;
		if (_tmp22_ == NULL) {
			ValaDataType* _tmp23_;
			_tmp23_ = condition_target_type;
			_tmp18_ = _tmp23_ != NULL;
		} else {
			_tmp18_ = FALSE;
		}
		if (_tmp18_) {
			ValaDataType* _tmp24_;
			ValaTypeSymbol* _tmp25_;
			ValaTypeSymbol* _tmp26_;
			_tmp24_ = condition_target_type;
			_tmp25_ = vala_data_type_get_type_symbol (_tmp24_);
			_tmp26_ = _tmp25_;
			_tmp17_ = VALA_IS_ENUM (_tmp26_);
		} else {
			_tmp17_ = FALSE;
		}
		if (_tmp17_) {
			ValaEnum* enum_type = NULL;
			ValaDataType* _tmp27_;
			ValaTypeSymbol* _tmp28_;
			ValaTypeSymbol* _tmp29_;
			ValaEnum* _tmp30_;
			_tmp27_ = condition_target_type;
			_tmp28_ = vala_data_type_get_type_symbol (_tmp27_);
			_tmp29_ = _tmp28_;
			_tmp30_ = _vala_code_node_ref0 (G_TYPE_CHECK_INSTANCE_CAST (_tmp29_, VALA_TYPE_ENUM, ValaEnum));
			enum_type = _tmp30_;
			{
				ValaList* _val_list = NULL;
				ValaEnum* _tmp31_;
				ValaList* _tmp32_;
				gint _val_size = 0;
				ValaList* _tmp33_;
				gint _tmp34_;
				gint _tmp35_;
				gint _val_index = 0;
				_tmp31_ = enum_type;
				_tmp32_ = vala_enum_get_values (_tmp31_);
				_val_list = _tmp32_;
				_tmp33_ = _val_list;
				_tmp34_ = vala_collection_get_size ((ValaCollection*) _tmp33_);
				_tmp35_ = _tmp34_;
				_val_size = _tmp35_;
				_val_index = -1;
				while (TRUE) {
					gint _tmp36_;
					gint _tmp37_;
					ValaEnumValue* val = NULL;
					ValaList* _tmp38_;
					gpointer _tmp39_;
					ValaExpression* _tmp40_;
					ValaExpression* _tmp41_;
					gchar* _tmp42_;
					gchar* _tmp43_;
					ValaEnumValue* _tmp44_;
					const gchar* _tmp45_;
					const gchar* _tmp46_;
					gboolean _tmp47_;
					_val_index = _val_index + 1;
					_tmp36_ = _val_index;
					_tmp37_ = _val_size;
					if (!(_tmp36_ < _tmp37_)) {
						break;
					}
					_tmp38_ = _val_list;
					_tmp39_ = vala_list_get (_tmp38_, _val_index);
					val = (ValaEnumValue*) _tmp39_;
					_tmp40_ = vala_switch_label_get_expression (self);
					_tmp41_ = _tmp40_;
					_tmp42_ = vala_code_node_to_string ((ValaCodeNode*) _tmp41_);
					_tmp43_ = _tmp42_;
					_tmp44_ = val;
					_tmp45_ = vala_symbol_get_name ((ValaSymbol*) _tmp44_);
					_tmp46_ = _tmp45_;
					_tmp47_ = g_strcmp0 (_tmp43_, _tmp46_) == 0;
					_g_free0 (_tmp43_);
					if (_tmp47_) {
						ValaExpression* _tmp48_;
						ValaExpression* _tmp49_;
						ValaDataType* _tmp50_;
						ValaDataType* _tmp51_;
						ValaDataType* _tmp52_;
						ValaExpression* _tmp53_;
						ValaExpression* _tmp54_;
						ValaEnumValue* _tmp55_;
						_tmp48_ = vala_switch_label_get_expression (self);
						_tmp49_ = _tmp48_;
						_tmp50_ = condition_target_type;
						_tmp51_ = vala_data_type_copy (_tmp50_);
						_tmp52_ = _tmp51_;
						vala_expression_set_target_type (_tmp49_, _tmp52_);
						_vala_code_node_unref0 (_tmp52_);
						_tmp53_ = vala_switch_label_get_expression (self);
						_tmp54_ = _tmp53_;
						_tmp55_ = val;
						vala_expression_set_symbol_reference (_tmp54_, (ValaSymbol*) _tmp55_);
						_vala_code_node_unref0 (val);
						break;
					}
					_vala_code_node_unref0 (val);
				}
			}
			_vala_code_node_unref0 (enum_type);
		}
		_tmp56_ = vala_switch_label_get_expression (self);
		_tmp57_ = _tmp56_;
		if (!vala_code_node_check ((ValaCodeNode*) _tmp57_, context)) {
			vala_code_node_set_error ((ValaCodeNode*) self, TRUE);
			result = FALSE;
			_vala_code_node_unref0 (condition_target_type);
			_vala_code_node_unref0 (switch_statement);
			return result;
		}
		_tmp58_ = vala_switch_label_get_expression (self);
		_tmp59_ = _tmp58_;
		if (!vala_expression_is_constant (_tmp59_)) {
			ValaExpression* _tmp60_;
			ValaExpression* _tmp61_;
			ValaSourceReference* _tmp62_;
			ValaSourceReference* _tmp63_;
			vala_code_node_set_error ((ValaCodeNode*) self, TRUE);
			_tmp60_ = vala_switch_label_get_expression (self);
			_tmp61_ = _tmp60_;
			_tmp62_ = vala_code_node_get_source_reference ((ValaCodeNode*) _tmp61_);
			_tmp63_ = _tmp62_;
			vala_report_error (_tmp63_, "Expression must be constant");
			result = FALSE;
			_vala_code_node_unref0 (condition_target_type);
			_vala_code_node_unref0 (switch_statement);
			return result;
		}
		_tmp64_ = vala_switch_label_get_expression (self);
		_tmp65_ = _tmp64_;
		_tmp66_ = vala_expression_get_value_type (_tmp65_);
		_tmp67_ = _tmp66_;
		_tmp68_ = switch_statement;
		_tmp69_ = vala_switch_statement_get_expression (_tmp68_);
		_tmp70_ = _tmp69_;
		_tmp71_ = vala_expression_get_value_type (_tmp70_);
		_tmp72_ = _tmp71_;
		if (!vala_data_type_compatible (_tmp67_, _tmp72_)) {
			ValaExpression* _tmp73_;
			ValaExpression* _tmp74_;
			ValaSourceReference* _tmp75_;
			ValaSourceReference* _tmp76_;
			ValaExpression* _tmp77_;
			ValaExpression* _tmp78_;
			ValaDataType* _tmp79_;
			ValaDataType* _tmp80_;
			gchar* _tmp81_;
			gchar* _tmp82_;
			ValaSwitchStatement* _tmp83_;
			ValaExpression* _tmp84_;
			ValaExpression* _tmp85_;
			ValaDataType* _tmp86_;
			ValaDataType* _tmp87_;
			gchar* _tmp88_;
			gchar* _tmp89_;
			vala_code_node_set_error ((ValaCodeNode*) self, TRUE);
			_tmp73_ = vala_switch_label_get_expression (self);
			_tmp74_ = _tmp73_;
			_tmp75_ = vala_code_node_get_source_reference ((ValaCodeNode*) _tmp74_);
			_tmp76_ = _tmp75_;
			_tmp77_ = vala_switch_label_get_expression (self);
			_tmp78_ = _tmp77_;
			_tmp79_ = vala_expression_get_value_type (_tmp78_);
			_tmp80_ = _tmp79_;
			_tmp81_ = vala_code_node_to_string ((ValaCodeNode*) _tmp80_);
			_tmp82_ = _tmp81_;
			_tmp83_ = switch_statement;
			_tmp84_ = vala_switch_statement_get_expression (_tmp83_);
			_tmp85_ = _tmp84_;
			_tmp86_ = vala_expression_get_value_type (_tmp85_);
			_tmp87_ = _tmp86_;
			_tmp88_ = vala_code_node_to_string ((ValaCodeNode*) _tmp87_);
			_tmp89_ = _tmp88_;
			vala_report_error (_tmp76_, "Cannot convert from `%s' to `%s'", _tmp82_, _tmp89_);
			_g_free0 (_tmp89_);
			_g_free0 (_tmp82_);
			result = FALSE;
			_vala_code_node_unref0 (condition_target_type);
			_vala_code_node_unref0 (switch_statement);
			return result;
		}
		_vala_code_node_unref0 (condition_target_type);
		_vala_code_node_unref0 (switch_statement);
	}
	result = TRUE;
	return result;
}

static void
vala_switch_label_real_emit (ValaCodeNode* base,
                             ValaCodeGenerator* codegen)
{
	ValaSwitchLabel * self;
	self = (ValaSwitchLabel*) base;
	g_return_if_fail (codegen != NULL);
	vala_code_visitor_visit_switch_label ((ValaCodeVisitor*) codegen, self);
}

static void
vala_switch_label_class_init (ValaSwitchLabelClass * klass,
                              gpointer klass_data)
{
	vala_switch_label_parent_class = g_type_class_peek_parent (klass);
	((ValaCodeNodeClass *) klass)->finalize = vala_switch_label_finalize;
	g_type_class_adjust_private_offset (klass, &ValaSwitchLabel_private_offset);
	((ValaCodeNodeClass *) klass)->accept = (void (*) (ValaCodeNode*, ValaCodeVisitor*)) vala_switch_label_real_accept;
	((ValaCodeNodeClass *) klass)->accept_children = (void (*) (ValaCodeNode*, ValaCodeVisitor*)) vala_switch_label_real_accept_children;
	((ValaCodeNodeClass *) klass)->check = (gboolean (*) (ValaCodeNode*, ValaCodeContext*)) vala_switch_label_real_check;
	((ValaCodeNodeClass *) klass)->emit = (void (*) (ValaCodeNode*, ValaCodeGenerator*)) vala_switch_label_real_emit;
}

static void
vala_switch_label_instance_init (ValaSwitchLabel * self,
                                 gpointer klass)
{
	self->priv = vala_switch_label_get_instance_private (self);
}

static void
vala_switch_label_finalize (ValaCodeNode * obj)
{
	ValaSwitchLabel * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, VALA_TYPE_SWITCH_LABEL, ValaSwitchLabel);
	_vala_code_node_unref0 (self->priv->_expression);
	VALA_CODE_NODE_CLASS (vala_switch_label_parent_class)->finalize (obj);
}

/**
 * Represents a switch label in the source code.
 */
static GType
vala_switch_label_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (ValaSwitchLabelClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) vala_switch_label_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (ValaSwitchLabel), 0, (GInstanceInitFunc) vala_switch_label_instance_init, NULL };
	GType vala_switch_label_type_id;
	vala_switch_label_type_id = g_type_register_static (VALA_TYPE_CODE_NODE, "ValaSwitchLabel", &g_define_type_info, 0);
	ValaSwitchLabel_private_offset = g_type_add_instance_private (vala_switch_label_type_id, sizeof (ValaSwitchLabelPrivate));
	return vala_switch_label_type_id;
}

GType
vala_switch_label_get_type (void)
{
	static volatile gsize vala_switch_label_type_id__once = 0;
	if (g_once_init_enter (&vala_switch_label_type_id__once)) {
		GType vala_switch_label_type_id;
		vala_switch_label_type_id = vala_switch_label_get_type_once ();
		g_once_init_leave (&vala_switch_label_type_id__once, vala_switch_label_type_id);
	}
	return vala_switch_label_type_id__once;
}

