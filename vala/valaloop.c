/* valaloop.c generated by valac, the Vala compiler
 * generated from valaloop.vala, do not modify */

/* valaloop.vala
 *
 * Copyright (C) 2021  Rico Tzschichholz
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
 * 	Rico Tzschichholz <ricotz@ubuntu.com>
 */

#include "vala.h"
#include <glib.h>
#include <glib-object.h>

#define _vala_code_node_unref0(var) ((var == NULL) ? NULL : (var = (vala_code_node_unref (var), NULL)))

struct _ValaLoopPrivate {
	ValaExpression* _condition;
	ValaBlock* _body;
};

static gint ValaLoop_private_offset;
static gpointer vala_loop_parent_class = NULL;

static void vala_loop_set_condition (ValaLoop* self,
                              ValaExpression* value);
static void vala_loop_set_body (ValaLoop* self,
                         ValaBlock* value);
static void vala_loop_real_replace_expression (ValaCodeNode* base,
                                        ValaExpression* old_node,
                                        ValaExpression* new_node);
static void vala_loop_finalize (ValaCodeNode * obj);
static GType vala_loop_get_type_once (void);

static inline gpointer
vala_loop_get_instance_private (ValaLoop* self)
{
	return G_STRUCT_MEMBER_P (self, ValaLoop_private_offset);
}

ValaExpression*
vala_loop_get_condition (ValaLoop* self)
{
	ValaExpression* result;
	ValaExpression* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_condition;
	result = _tmp0_;
	return result;
}

static gpointer
_vala_code_node_ref0 (gpointer self)
{
	return self ? vala_code_node_ref (self) : NULL;
}

static void
vala_loop_set_condition (ValaLoop* self,
                         ValaExpression* value)
{
	ValaExpression* _tmp0_;
	ValaExpression* _tmp1_;
	g_return_if_fail (self != NULL);
	_tmp0_ = _vala_code_node_ref0 (value);
	_vala_code_node_unref0 (self->priv->_condition);
	self->priv->_condition = _tmp0_;
	_tmp1_ = self->priv->_condition;
	if (_tmp1_ != NULL) {
		ValaExpression* _tmp2_;
		_tmp2_ = self->priv->_condition;
		vala_code_node_set_parent_node ((ValaCodeNode*) _tmp2_, (ValaCodeNode*) self);
	}
}

ValaBlock*
vala_loop_get_body (ValaLoop* self)
{
	ValaBlock* result;
	ValaBlock* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_body;
	result = _tmp0_;
	return result;
}

static void
vala_loop_set_body (ValaLoop* self,
                    ValaBlock* value)
{
	ValaBlock* _tmp0_;
	ValaBlock* _tmp1_;
	g_return_if_fail (self != NULL);
	_tmp0_ = _vala_code_node_ref0 (value);
	_vala_code_node_unref0 (self->priv->_body);
	self->priv->_body = _tmp0_;
	_tmp1_ = self->priv->_body;
	vala_code_node_set_parent_node ((ValaCodeNode*) _tmp1_, (ValaCodeNode*) self);
}

ValaLoop*
vala_loop_construct (GType object_type,
                     ValaExpression* condition,
                     ValaBlock* body,
                     ValaSourceReference* source_reference)
{
	ValaLoop* self = NULL;
	g_return_val_if_fail (body != NULL, NULL);
	self = (ValaLoop*) vala_code_node_construct (object_type);
	vala_loop_set_condition (self, condition);
	vala_loop_set_body (self, body);
	vala_code_node_set_source_reference ((ValaCodeNode*) self, source_reference);
	return self;
}

static void
vala_loop_real_replace_expression (ValaCodeNode* base,
                                   ValaExpression* old_node,
                                   ValaExpression* new_node)
{
	ValaLoop * self;
	ValaExpression* _tmp0_;
	ValaExpression* _tmp1_;
	self = (ValaLoop*) base;
	g_return_if_fail (old_node != NULL);
	g_return_if_fail (new_node != NULL);
	_tmp0_ = vala_loop_get_condition (self);
	_tmp1_ = _tmp0_;
	if (_tmp1_ == old_node) {
		vala_loop_set_condition (self, new_node);
	}
}

static void
vala_loop_class_init (ValaLoopClass * klass,
                      gpointer klass_data)
{
	vala_loop_parent_class = g_type_class_peek_parent (klass);
	((ValaCodeNodeClass *) klass)->finalize = vala_loop_finalize;
	g_type_class_adjust_private_offset (klass, &ValaLoop_private_offset);
	((ValaCodeNodeClass *) klass)->replace_expression = (void (*) (ValaCodeNode*, ValaExpression*, ValaExpression*)) vala_loop_real_replace_expression;
}

static void
vala_loop_instance_init (ValaLoop * self,
                         gpointer klass)
{
	self->priv = vala_loop_get_instance_private (self);
}

static void
vala_loop_finalize (ValaCodeNode * obj)
{
	ValaLoop * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, VALA_TYPE_LOOP, ValaLoop);
	_vala_code_node_unref0 (self->priv->_condition);
	_vala_code_node_unref0 (self->priv->_body);
	VALA_CODE_NODE_CLASS (vala_loop_parent_class)->finalize (obj);
}

/**
 * Base class for all loop statements.
 */
static GType
vala_loop_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (ValaLoopClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) vala_loop_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (ValaLoop), 0, (GInstanceInitFunc) vala_loop_instance_init, NULL };
	GType vala_loop_type_id;
	vala_loop_type_id = g_type_register_static (VALA_TYPE_CODE_NODE, "ValaLoop", &g_define_type_info, G_TYPE_FLAG_ABSTRACT);
	ValaLoop_private_offset = g_type_add_instance_private (vala_loop_type_id, sizeof (ValaLoopPrivate));
	return vala_loop_type_id;
}

GType
vala_loop_get_type (void)
{
	static volatile gsize vala_loop_type_id__once = 0;
	if (g_once_init_enter (&vala_loop_type_id__once)) {
		GType vala_loop_type_id;
		vala_loop_type_id = vala_loop_get_type_once ();
		g_once_init_leave (&vala_loop_type_id__once, vala_loop_type_id);
	}
	return vala_loop_type_id__once;
}

