/* valatypecheck.c generated by valac, the Vala compiler
 * generated from valatypecheck.vala, do not modify */

/* valatypecheck.vala
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
#include <stdlib.h>
#include <string.h>
#include <glib-object.h>

#define _vala_code_node_unref0(var) ((var == NULL) ? NULL : (var = (vala_code_node_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))

struct _ValaTypeCheckPrivate {
	ValaExpression* _expression;
	ValaDataType* _data_type;
};

static gint ValaTypeCheck_private_offset;
static gpointer vala_typecheck_parent_class = NULL;

static void vala_typecheck_set_expression (ValaTypeCheck* self,
                                    ValaExpression* value);
static void vala_typecheck_set_type_reference (ValaTypeCheck* self,
                                        ValaDataType* value);
static void vala_typecheck_real_accept (ValaCodeNode* base,
                                 ValaCodeVisitor* visitor);
static void vala_typecheck_real_accept_children (ValaCodeNode* base,
                                          ValaCodeVisitor* visitor);
static gboolean vala_typecheck_real_is_pure (ValaExpression* base);
static void vala_typecheck_real_replace_type (ValaCodeNode* base,
                                       ValaDataType* old_type,
                                       ValaDataType* new_type);
static void vala_typecheck_real_replace_expression (ValaCodeNode* base,
                                             ValaExpression* old_node,
                                             ValaExpression* new_node);
static gboolean vala_typecheck_real_check (ValaCodeNode* base,
                                    ValaCodeContext* context);
static void vala_typecheck_real_emit (ValaCodeNode* base,
                               ValaCodeGenerator* codegen);
static gchar* vala_typecheck_real_to_string (ValaCodeNode* base);
static void vala_typecheck_finalize (ValaCodeNode * obj);
static GType vala_typecheck_get_type_once (void);

static inline gpointer
vala_typecheck_get_instance_private (ValaTypeCheck* self)
{
	return G_STRUCT_MEMBER_P (self, ValaTypeCheck_private_offset);
}

ValaExpression*
vala_typecheck_get_expression (ValaTypeCheck* self)
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
vala_typecheck_set_expression (ValaTypeCheck* self,
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

ValaDataType*
vala_typecheck_get_type_reference (ValaTypeCheck* self)
{
	ValaDataType* result;
	ValaDataType* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_data_type;
	result = _tmp0_;
	return result;
}

static void
vala_typecheck_set_type_reference (ValaTypeCheck* self,
                                   ValaDataType* value)
{
	ValaDataType* _tmp0_;
	ValaDataType* _tmp1_;
	g_return_if_fail (self != NULL);
	_tmp0_ = _vala_code_node_ref0 (value);
	_vala_code_node_unref0 (self->priv->_data_type);
	self->priv->_data_type = _tmp0_;
	_tmp1_ = self->priv->_data_type;
	vala_code_node_set_parent_node ((ValaCodeNode*) _tmp1_, (ValaCodeNode*) self);
}

/**
 * Creates a new type check expression.
 *
 * @param expr   an expression
 * @param type   a data type
 * @param source reference to source code
 * @return       newly created type check expression
 */
ValaTypeCheck*
vala_typecheck_construct (GType object_type,
                          ValaExpression* expr,
                          ValaDataType* type,
                          ValaSourceReference* source)
{
	ValaTypeCheck* self = NULL;
	g_return_val_if_fail (expr != NULL, NULL);
	g_return_val_if_fail (type != NULL, NULL);
	self = (ValaTypeCheck*) vala_expression_construct (object_type);
	vala_typecheck_set_expression (self, expr);
	vala_typecheck_set_type_reference (self, type);
	vala_code_node_set_source_reference ((ValaCodeNode*) self, source);
	return self;
}

ValaTypeCheck*
vala_typecheck_new (ValaExpression* expr,
                    ValaDataType* type,
                    ValaSourceReference* source)
{
	return vala_typecheck_construct (VALA_TYPE_TYPECHECK, expr, type, source);
}

static void
vala_typecheck_real_accept (ValaCodeNode* base,
                            ValaCodeVisitor* visitor)
{
	ValaTypeCheck * self;
	self = (ValaTypeCheck*) base;
	g_return_if_fail (visitor != NULL);
	vala_code_visitor_visit_type_check (visitor, self);
	vala_code_visitor_visit_expression (visitor, (ValaExpression*) self);
}

static void
vala_typecheck_real_accept_children (ValaCodeNode* base,
                                     ValaCodeVisitor* visitor)
{
	ValaTypeCheck * self;
	ValaExpression* _tmp0_;
	ValaExpression* _tmp1_;
	ValaDataType* _tmp2_;
	ValaDataType* _tmp3_;
	self = (ValaTypeCheck*) base;
	g_return_if_fail (visitor != NULL);
	_tmp0_ = vala_typecheck_get_expression (self);
	_tmp1_ = _tmp0_;
	vala_code_node_accept ((ValaCodeNode*) _tmp1_, visitor);
	_tmp2_ = vala_typecheck_get_type_reference (self);
	_tmp3_ = _tmp2_;
	vala_code_node_accept ((ValaCodeNode*) _tmp3_, visitor);
}

static gboolean
vala_typecheck_real_is_pure (ValaExpression* base)
{
	ValaTypeCheck * self;
	ValaExpression* _tmp0_;
	ValaExpression* _tmp1_;
	gboolean result;
	self = (ValaTypeCheck*) base;
	_tmp0_ = vala_typecheck_get_expression (self);
	_tmp1_ = _tmp0_;
	result = vala_expression_is_pure (_tmp1_);
	return result;
}

static void
vala_typecheck_real_replace_type (ValaCodeNode* base,
                                  ValaDataType* old_type,
                                  ValaDataType* new_type)
{
	ValaTypeCheck * self;
	ValaDataType* _tmp0_;
	ValaDataType* _tmp1_;
	self = (ValaTypeCheck*) base;
	g_return_if_fail (old_type != NULL);
	g_return_if_fail (new_type != NULL);
	_tmp0_ = vala_typecheck_get_type_reference (self);
	_tmp1_ = _tmp0_;
	if (_tmp1_ == old_type) {
		vala_typecheck_set_type_reference (self, new_type);
	}
}

static void
vala_typecheck_real_replace_expression (ValaCodeNode* base,
                                        ValaExpression* old_node,
                                        ValaExpression* new_node)
{
	ValaTypeCheck * self;
	ValaExpression* _tmp0_;
	ValaExpression* _tmp1_;
	self = (ValaTypeCheck*) base;
	g_return_if_fail (old_node != NULL);
	g_return_if_fail (new_node != NULL);
	_tmp0_ = vala_typecheck_get_expression (self);
	_tmp1_ = _tmp0_;
	if (_tmp1_ == old_node) {
		vala_typecheck_set_expression (self, new_node);
	}
}

static gboolean
vala_typecheck_real_check (ValaCodeNode* base,
                           ValaCodeContext* context)
{
	ValaTypeCheck * self;
	gboolean _tmp0_;
	gboolean _tmp1_;
	ValaExpression* _tmp4_;
	ValaExpression* _tmp5_;
	ValaDataType* _tmp6_;
	ValaDataType* _tmp7_;
	ValaExpression* _tmp8_;
	ValaExpression* _tmp9_;
	ValaDataType* _tmp10_;
	ValaDataType* _tmp11_;
	ValaDataType* _tmp16_;
	ValaDataType* _tmp17_;
	ValaTypeSymbol* _tmp18_;
	ValaTypeSymbol* _tmp19_;
	gboolean _tmp20_ = FALSE;
	ValaDataType* _tmp21_;
	ValaDataType* _tmp22_;
	gboolean _tmp35_ = FALSE;
	ValaProfile _tmp36_;
	ValaProfile _tmp37_;
	ValaSemanticAnalyzer* _tmp43_;
	ValaSemanticAnalyzer* _tmp44_;
	ValaDataType* _tmp45_;
	gboolean _tmp46_;
	gboolean _tmp47_;
	gboolean result;
	self = (ValaTypeCheck*) base;
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
	_tmp4_ = vala_typecheck_get_expression (self);
	_tmp5_ = _tmp4_;
	vala_code_node_check ((ValaCodeNode*) _tmp5_, context);
	_tmp6_ = vala_typecheck_get_type_reference (self);
	_tmp7_ = _tmp6_;
	vala_code_node_check ((ValaCodeNode*) _tmp7_, context);
	_tmp8_ = vala_typecheck_get_expression (self);
	_tmp9_ = _tmp8_;
	_tmp10_ = vala_expression_get_value_type (_tmp9_);
	_tmp11_ = _tmp10_;
	if (_tmp11_ == NULL) {
		ValaExpression* _tmp12_;
		ValaExpression* _tmp13_;
		ValaSourceReference* _tmp14_;
		ValaSourceReference* _tmp15_;
		_tmp12_ = vala_typecheck_get_expression (self);
		_tmp13_ = _tmp12_;
		_tmp14_ = vala_code_node_get_source_reference ((ValaCodeNode*) _tmp13_);
		_tmp15_ = _tmp14_;
		vala_report_error (_tmp15_, "invalid left operand");
		vala_code_node_set_error ((ValaCodeNode*) self, TRUE);
		result = FALSE;
		return result;
	}
	_tmp16_ = vala_typecheck_get_type_reference (self);
	_tmp17_ = _tmp16_;
	_tmp18_ = vala_data_type_get_type_symbol (_tmp17_);
	_tmp19_ = _tmp18_;
	if (_tmp19_ == NULL) {
		vala_code_node_set_error ((ValaCodeNode*) self, TRUE);
		result = FALSE;
		return result;
	}
	_tmp21_ = vala_typecheck_get_type_reference (self);
	_tmp22_ = _tmp21_;
	if (VALA_IS_ERROR_TYPE (_tmp22_)) {
		ValaExpression* _tmp23_;
		ValaExpression* _tmp24_;
		ValaDataType* _tmp25_;
		ValaDataType* _tmp26_;
		_tmp23_ = vala_typecheck_get_expression (self);
		_tmp24_ = _tmp23_;
		_tmp25_ = vala_expression_get_value_type (_tmp24_);
		_tmp26_ = _tmp25_;
		_tmp20_ = !VALA_IS_ERROR_TYPE (_tmp26_);
	} else {
		_tmp20_ = FALSE;
	}
	if (_tmp20_) {
		ValaExpression* _tmp27_;
		ValaExpression* _tmp28_;
		ValaSourceReference* _tmp29_;
		ValaSourceReference* _tmp30_;
		ValaExpression* _tmp31_;
		ValaExpression* _tmp32_;
		gchar* _tmp33_;
		gchar* _tmp34_;
		_tmp27_ = vala_typecheck_get_expression (self);
		_tmp28_ = _tmp27_;
		_tmp29_ = vala_code_node_get_source_reference ((ValaCodeNode*) _tmp28_);
		_tmp30_ = _tmp29_;
		_tmp31_ = vala_typecheck_get_expression (self);
		_tmp32_ = _tmp31_;
		_tmp33_ = vala_code_node_to_string ((ValaCodeNode*) _tmp32_);
		_tmp34_ = _tmp33_;
		vala_report_error (_tmp30_, "`%s' must be an error", _tmp34_);
		_g_free0 (_tmp34_);
		vala_code_node_set_error ((ValaCodeNode*) self, TRUE);
		result = FALSE;
		return result;
	}
	_tmp36_ = vala_code_context_get_profile (context);
	_tmp37_ = _tmp36_;
	if (_tmp37_ == VALA_PROFILE_GOBJECT) {
		ValaDataType* _tmp38_;
		ValaDataType* _tmp39_;
		_tmp38_ = vala_typecheck_get_type_reference (self);
		_tmp39_ = _tmp38_;
		_tmp35_ = vala_data_type_has_type_arguments (_tmp39_);
	} else {
		_tmp35_ = FALSE;
	}
	if (_tmp35_) {
		ValaDataType* _tmp40_;
		ValaSourceReference* _tmp41_;
		ValaSourceReference* _tmp42_;
		_tmp40_ = self->priv->_data_type;
		_tmp41_ = vala_code_node_get_source_reference ((ValaCodeNode*) _tmp40_);
		_tmp42_ = _tmp41_;
		vala_report_warning (_tmp42_, "Type argument list has no effect");
	}
	_tmp43_ = vala_code_context_get_analyzer (context);
	_tmp44_ = _tmp43_;
	_tmp45_ = _tmp44_->bool_type;
	vala_expression_set_value_type ((ValaExpression*) self, _tmp45_);
	_tmp46_ = vala_code_node_get_error ((ValaCodeNode*) self);
	_tmp47_ = _tmp46_;
	result = !_tmp47_;
	return result;
}

static void
vala_typecheck_real_emit (ValaCodeNode* base,
                          ValaCodeGenerator* codegen)
{
	ValaTypeCheck * self;
	ValaExpression* _tmp0_;
	ValaExpression* _tmp1_;
	self = (ValaTypeCheck*) base;
	g_return_if_fail (codegen != NULL);
	_tmp0_ = vala_typecheck_get_expression (self);
	_tmp1_ = _tmp0_;
	vala_code_node_emit ((ValaCodeNode*) _tmp1_, codegen);
	vala_code_visitor_visit_type_check ((ValaCodeVisitor*) codegen, self);
	vala_code_visitor_visit_expression ((ValaCodeVisitor*) codegen, (ValaExpression*) self);
}

static gchar*
vala_typecheck_real_to_string (ValaCodeNode* base)
{
	ValaTypeCheck * self;
	ValaExpression* _tmp0_;
	ValaExpression* _tmp1_;
	gchar* _tmp2_;
	gchar* _tmp3_;
	ValaDataType* _tmp4_;
	ValaDataType* _tmp5_;
	gchar* _tmp6_;
	gchar* _tmp7_;
	gchar* _tmp8_;
	gchar* _tmp9_;
	gchar* result;
	self = (ValaTypeCheck*) base;
	_tmp0_ = vala_typecheck_get_expression (self);
	_tmp1_ = _tmp0_;
	_tmp2_ = vala_code_node_to_string ((ValaCodeNode*) _tmp1_);
	_tmp3_ = _tmp2_;
	_tmp4_ = vala_typecheck_get_type_reference (self);
	_tmp5_ = _tmp4_;
	_tmp6_ = vala_code_node_to_string ((ValaCodeNode*) _tmp5_);
	_tmp7_ = _tmp6_;
	_tmp8_ = g_strdup_printf ("(%s is %s)", _tmp3_, _tmp7_);
	_tmp9_ = _tmp8_;
	_g_free0 (_tmp7_);
	_g_free0 (_tmp3_);
	result = _tmp9_;
	return result;
}

static void
vala_typecheck_class_init (ValaTypeCheckClass * klass,
                           gpointer klass_data)
{
	vala_typecheck_parent_class = g_type_class_peek_parent (klass);
	((ValaCodeNodeClass *) klass)->finalize = vala_typecheck_finalize;
	g_type_class_adjust_private_offset (klass, &ValaTypeCheck_private_offset);
	((ValaCodeNodeClass *) klass)->accept = (void (*) (ValaCodeNode*, ValaCodeVisitor*)) vala_typecheck_real_accept;
	((ValaCodeNodeClass *) klass)->accept_children = (void (*) (ValaCodeNode*, ValaCodeVisitor*)) vala_typecheck_real_accept_children;
	((ValaExpressionClass *) klass)->is_pure = (gboolean (*) (ValaExpression*)) vala_typecheck_real_is_pure;
	((ValaCodeNodeClass *) klass)->replace_type = (void (*) (ValaCodeNode*, ValaDataType*, ValaDataType*)) vala_typecheck_real_replace_type;
	((ValaCodeNodeClass *) klass)->replace_expression = (void (*) (ValaCodeNode*, ValaExpression*, ValaExpression*)) vala_typecheck_real_replace_expression;
	((ValaCodeNodeClass *) klass)->check = (gboolean (*) (ValaCodeNode*, ValaCodeContext*)) vala_typecheck_real_check;
	((ValaCodeNodeClass *) klass)->emit = (void (*) (ValaCodeNode*, ValaCodeGenerator*)) vala_typecheck_real_emit;
	((ValaCodeNodeClass *) klass)->to_string = (gchar* (*) (ValaCodeNode*)) vala_typecheck_real_to_string;
}

static void
vala_typecheck_instance_init (ValaTypeCheck * self,
                              gpointer klass)
{
	self->priv = vala_typecheck_get_instance_private (self);
}

static void
vala_typecheck_finalize (ValaCodeNode * obj)
{
	ValaTypeCheck * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, VALA_TYPE_TYPECHECK, ValaTypeCheck);
	_vala_code_node_unref0 (self->priv->_expression);
	_vala_code_node_unref0 (self->priv->_data_type);
	VALA_CODE_NODE_CLASS (vala_typecheck_parent_class)->finalize (obj);
}

/**
 * Represents a type check (`is`) expression in the source code.
 */
static GType
vala_typecheck_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (ValaTypeCheckClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) vala_typecheck_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (ValaTypeCheck), 0, (GInstanceInitFunc) vala_typecheck_instance_init, NULL };
	GType vala_typecheck_type_id;
	vala_typecheck_type_id = g_type_register_static (VALA_TYPE_EXPRESSION, "ValaTypeCheck", &g_define_type_info, 0);
	ValaTypeCheck_private_offset = g_type_add_instance_private (vala_typecheck_type_id, sizeof (ValaTypeCheckPrivate));
	return vala_typecheck_type_id;
}

GType
vala_typecheck_get_type (void)
{
	static volatile gsize vala_typecheck_type_id__once = 0;
	if (g_once_init_enter (&vala_typecheck_type_id__once)) {
		GType vala_typecheck_type_id;
		vala_typecheck_type_id = vala_typecheck_get_type_once ();
		g_once_init_leave (&vala_typecheck_type_id__once, vala_typecheck_type_id);
	}
	return vala_typecheck_type_id__once;
}

