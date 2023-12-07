/* valaexpressionstatement.c generated by valac, the Vala compiler
 * generated from valaexpressionstatement.vala, do not modify */

/* valaexpressionstatement.vala
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
#include <valagee.h>
#include <glib-object.h>

#define _vala_code_node_unref0(var) ((var == NULL) ? NULL : (var = (vala_code_node_unref (var), NULL)))

struct _ValaExpressionStatementPrivate {
	ValaExpression* _expression;
};

static gint ValaExpressionStatement_private_offset;
static gpointer vala_expression_statement_parent_class = NULL;
static ValaStatementIface * vala_expression_statement_vala_statement_parent_iface = NULL;

static void vala_expression_statement_set_expression (ValaExpressionStatement* self,
                                               ValaExpression* value);
static void vala_expression_statement_real_accept (ValaCodeNode* base,
                                            ValaCodeVisitor* visitor);
static void vala_expression_statement_real_accept_children (ValaCodeNode* base,
                                                     ValaCodeVisitor* visitor);
static void vala_expression_statement_real_replace_expression (ValaCodeNode* base,
                                                        ValaExpression* old_node,
                                                        ValaExpression* new_node);
static gboolean vala_expression_statement_real_check (ValaCodeNode* base,
                                               ValaCodeContext* context);
static void vala_expression_statement_real_get_error_types (ValaCodeNode* base,
                                                     ValaCollection* collection,
                                                     ValaSourceReference* source_reference);
static void vala_expression_statement_real_emit (ValaCodeNode* base,
                                          ValaCodeGenerator* codegen);
static void vala_expression_statement_real_get_defined_variables (ValaCodeNode* base,
                                                           ValaCollection* collection);
static void vala_expression_statement_real_get_used_variables (ValaCodeNode* base,
                                                        ValaCollection* collection);
static void vala_expression_statement_finalize (ValaCodeNode * obj);
static GType vala_expression_statement_get_type_once (void);

static inline gpointer
vala_expression_statement_get_instance_private (ValaExpressionStatement* self)
{
	return G_STRUCT_MEMBER_P (self, ValaExpressionStatement_private_offset);
}

ValaExpression*
vala_expression_statement_get_expression (ValaExpressionStatement* self)
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
vala_expression_statement_set_expression (ValaExpressionStatement* self,
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

/**
 * Creates a new expression statement.
 *
 * @param expression        expression to evaluate
 * @param source_reference  reference to source code
 * @return                  newly created expression statement
 */
ValaExpressionStatement*
vala_expression_statement_construct (GType object_type,
                                     ValaExpression* expression,
                                     ValaSourceReference* source_reference)
{
	ValaExpressionStatement* self = NULL;
	g_return_val_if_fail (expression != NULL, NULL);
	self = (ValaExpressionStatement*) vala_code_node_construct (object_type);
	vala_code_node_set_source_reference ((ValaCodeNode*) self, source_reference);
	vala_expression_statement_set_expression (self, expression);
	return self;
}

ValaExpressionStatement*
vala_expression_statement_new (ValaExpression* expression,
                               ValaSourceReference* source_reference)
{
	return vala_expression_statement_construct (VALA_TYPE_EXPRESSION_STATEMENT, expression, source_reference);
}

static void
vala_expression_statement_real_accept (ValaCodeNode* base,
                                       ValaCodeVisitor* visitor)
{
	ValaExpressionStatement * self;
	self = (ValaExpressionStatement*) base;
	g_return_if_fail (visitor != NULL);
	vala_code_visitor_visit_expression_statement (visitor, self);
}

static void
vala_expression_statement_real_accept_children (ValaCodeNode* base,
                                                ValaCodeVisitor* visitor)
{
	ValaExpressionStatement * self;
	ValaExpression* _tmp0_;
	ValaExpression* _tmp1_;
	self = (ValaExpressionStatement*) base;
	g_return_if_fail (visitor != NULL);
	_tmp0_ = vala_expression_statement_get_expression (self);
	_tmp1_ = _tmp0_;
	vala_code_node_accept ((ValaCodeNode*) _tmp1_, visitor);
}

static void
vala_expression_statement_real_replace_expression (ValaCodeNode* base,
                                                   ValaExpression* old_node,
                                                   ValaExpression* new_node)
{
	ValaExpressionStatement * self;
	ValaExpression* _tmp0_;
	ValaExpression* _tmp1_;
	self = (ValaExpressionStatement*) base;
	g_return_if_fail (old_node != NULL);
	g_return_if_fail (new_node != NULL);
	_tmp0_ = vala_expression_statement_get_expression (self);
	_tmp1_ = _tmp0_;
	if (_tmp1_ == old_node) {
		vala_expression_statement_set_expression (self, new_node);
	}
}

static gboolean
vala_expression_statement_real_check (ValaCodeNode* base,
                                      ValaCodeContext* context)
{
	ValaExpressionStatement * self;
	gboolean _tmp0_;
	gboolean _tmp1_;
	ValaExpression* _tmp4_;
	ValaExpression* _tmp5_;
	gboolean _tmp10_;
	gboolean _tmp11_;
	gboolean result;
	self = (ValaExpressionStatement*) base;
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
	_tmp4_ = vala_expression_statement_get_expression (self);
	_tmp5_ = _tmp4_;
	if (!vala_code_node_check ((ValaCodeNode*) _tmp5_, context)) {
		vala_code_node_set_error ((ValaCodeNode*) self, TRUE);
		result = FALSE;
		return result;
	} else {
		ValaExpression* _tmp6_;
		ValaExpression* _tmp7_;
		_tmp6_ = vala_expression_statement_get_expression (self);
		_tmp7_ = _tmp6_;
		if (VALA_IS_LITERAL (_tmp7_)) {
			ValaSourceReference* _tmp8_;
			ValaSourceReference* _tmp9_;
			_tmp8_ = vala_code_node_get_source_reference ((ValaCodeNode*) self);
			_tmp9_ = _tmp8_;
			vala_report_error (_tmp9_, "Literal expression not allowed as statement");
			vala_code_node_set_error ((ValaCodeNode*) self, TRUE);
			result = FALSE;
			return result;
		}
	}
	_tmp10_ = vala_code_node_get_error ((ValaCodeNode*) self);
	_tmp11_ = _tmp10_;
	result = !_tmp11_;
	return result;
}

static void
vala_expression_statement_real_get_error_types (ValaCodeNode* base,
                                                ValaCollection* collection,
                                                ValaSourceReference* source_reference)
{
	ValaExpressionStatement * self;
	ValaExpression* _tmp0_;
	ValaExpression* _tmp1_;
	self = (ValaExpressionStatement*) base;
	g_return_if_fail (collection != NULL);
	_tmp0_ = vala_expression_statement_get_expression (self);
	_tmp1_ = _tmp0_;
	vala_code_node_get_error_types ((ValaCodeNode*) _tmp1_, collection, source_reference);
}

static void
vala_expression_statement_real_emit (ValaCodeNode* base,
                                     ValaCodeGenerator* codegen)
{
	ValaExpressionStatement * self;
	ValaExpression* _tmp0_;
	ValaExpression* _tmp1_;
	self = (ValaExpressionStatement*) base;
	g_return_if_fail (codegen != NULL);
	_tmp0_ = vala_expression_statement_get_expression (self);
	_tmp1_ = _tmp0_;
	vala_code_node_emit ((ValaCodeNode*) _tmp1_, codegen);
	vala_code_visitor_visit_expression_statement ((ValaCodeVisitor*) codegen, self);
}

static void
vala_expression_statement_real_get_defined_variables (ValaCodeNode* base,
                                                      ValaCollection* collection)
{
	ValaExpressionStatement * self;
	ValaExpression* _tmp0_;
	ValaExpression* _tmp1_;
	self = (ValaExpressionStatement*) base;
	g_return_if_fail (collection != NULL);
	_tmp0_ = vala_expression_statement_get_expression (self);
	_tmp1_ = _tmp0_;
	vala_code_node_get_defined_variables ((ValaCodeNode*) _tmp1_, collection);
}

static void
vala_expression_statement_real_get_used_variables (ValaCodeNode* base,
                                                   ValaCollection* collection)
{
	ValaExpressionStatement * self;
	ValaExpression* _tmp0_;
	ValaExpression* _tmp1_;
	self = (ValaExpressionStatement*) base;
	g_return_if_fail (collection != NULL);
	_tmp0_ = vala_expression_statement_get_expression (self);
	_tmp1_ = _tmp0_;
	vala_code_node_get_used_variables ((ValaCodeNode*) _tmp1_, collection);
}

static void
vala_expression_statement_class_init (ValaExpressionStatementClass * klass,
                                      gpointer klass_data)
{
	vala_expression_statement_parent_class = g_type_class_peek_parent (klass);
	((ValaCodeNodeClass *) klass)->finalize = vala_expression_statement_finalize;
	g_type_class_adjust_private_offset (klass, &ValaExpressionStatement_private_offset);
	((ValaCodeNodeClass *) klass)->accept = (void (*) (ValaCodeNode*, ValaCodeVisitor*)) vala_expression_statement_real_accept;
	((ValaCodeNodeClass *) klass)->accept_children = (void (*) (ValaCodeNode*, ValaCodeVisitor*)) vala_expression_statement_real_accept_children;
	((ValaCodeNodeClass *) klass)->replace_expression = (void (*) (ValaCodeNode*, ValaExpression*, ValaExpression*)) vala_expression_statement_real_replace_expression;
	((ValaCodeNodeClass *) klass)->check = (gboolean (*) (ValaCodeNode*, ValaCodeContext*)) vala_expression_statement_real_check;
	((ValaCodeNodeClass *) klass)->get_error_types = (void (*) (ValaCodeNode*, ValaCollection*, ValaSourceReference*)) vala_expression_statement_real_get_error_types;
	((ValaCodeNodeClass *) klass)->emit = (void (*) (ValaCodeNode*, ValaCodeGenerator*)) vala_expression_statement_real_emit;
	((ValaCodeNodeClass *) klass)->get_defined_variables = (void (*) (ValaCodeNode*, ValaCollection*)) vala_expression_statement_real_get_defined_variables;
	((ValaCodeNodeClass *) klass)->get_used_variables = (void (*) (ValaCodeNode*, ValaCollection*)) vala_expression_statement_real_get_used_variables;
}

static void
vala_expression_statement_vala_statement_interface_init (ValaStatementIface * iface,
                                                         gpointer iface_data)
{
	vala_expression_statement_vala_statement_parent_iface = g_type_interface_peek_parent (iface);
}

static void
vala_expression_statement_instance_init (ValaExpressionStatement * self,
                                         gpointer klass)
{
	self->priv = vala_expression_statement_get_instance_private (self);
}

static void
vala_expression_statement_finalize (ValaCodeNode * obj)
{
	ValaExpressionStatement * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, VALA_TYPE_EXPRESSION_STATEMENT, ValaExpressionStatement);
	_vala_code_node_unref0 (self->priv->_expression);
	VALA_CODE_NODE_CLASS (vala_expression_statement_parent_class)->finalize (obj);
}

/**
 * A code statement that evaluates a given expression. The value computed by the
 * expression, if any, is discarded.
 */
static GType
vala_expression_statement_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (ValaExpressionStatementClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) vala_expression_statement_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (ValaExpressionStatement), 0, (GInstanceInitFunc) vala_expression_statement_instance_init, NULL };
	static const GInterfaceInfo vala_statement_info = { (GInterfaceInitFunc) vala_expression_statement_vala_statement_interface_init, (GInterfaceFinalizeFunc) NULL, NULL};
	GType vala_expression_statement_type_id;
	vala_expression_statement_type_id = g_type_register_static (VALA_TYPE_CODE_NODE, "ValaExpressionStatement", &g_define_type_info, 0);
	g_type_add_interface_static (vala_expression_statement_type_id, VALA_TYPE_STATEMENT, &vala_statement_info);
	ValaExpressionStatement_private_offset = g_type_add_instance_private (vala_expression_statement_type_id, sizeof (ValaExpressionStatementPrivate));
	return vala_expression_statement_type_id;
}

GType
vala_expression_statement_get_type (void)
{
	static volatile gsize vala_expression_statement_type_id__once = 0;
	if (g_once_init_enter (&vala_expression_statement_type_id__once)) {
		GType vala_expression_statement_type_id;
		vala_expression_statement_type_id = vala_expression_statement_get_type_once ();
		g_once_init_leave (&vala_expression_statement_type_id__once, vala_expression_statement_type_id);
	}
	return vala_expression_statement_type_id__once;
}

