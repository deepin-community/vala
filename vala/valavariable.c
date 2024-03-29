/* valavariable.c generated by valac, the Vala compiler
 * generated from valavariable.vala, do not modify */

/* valavariable.vala
 *
 * Copyright (C) 2010  Jürg Billeter
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
#include <stdlib.h>
#include <string.h>

#define _vala_code_node_unref0(var) ((var == NULL) ? NULL : (var = (vala_code_node_unref (var), NULL)))

struct _ValaVariablePrivate {
	gboolean _single_assignment;
	ValaExpression* _initializer;
	ValaDataType* _variable_type;
};

static gint ValaVariable_private_offset;
static gpointer vala_variable_parent_class = NULL;

static void vala_variable_finalize (ValaCodeNode * obj);
static GType vala_variable_get_type_once (void);

static inline gpointer
vala_variable_get_instance_private (ValaVariable* self)
{
	return G_STRUCT_MEMBER_P (self, ValaVariable_private_offset);
}

ValaExpression*
vala_variable_get_initializer (ValaVariable* self)
{
	ValaExpression* result;
	ValaExpression* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_initializer;
	result = _tmp0_;
	return result;
}

static gpointer
_vala_code_node_ref0 (gpointer self)
{
	return self ? vala_code_node_ref (self) : NULL;
}

void
vala_variable_set_initializer (ValaVariable* self,
                               ValaExpression* value)
{
	ValaExpression* _tmp0_;
	ValaExpression* _tmp1_;
	g_return_if_fail (self != NULL);
	_tmp0_ = _vala_code_node_ref0 (value);
	_vala_code_node_unref0 (self->priv->_initializer);
	self->priv->_initializer = _tmp0_;
	_tmp1_ = self->priv->_initializer;
	if (_tmp1_ != NULL) {
		ValaExpression* _tmp2_;
		_tmp2_ = self->priv->_initializer;
		vala_code_node_set_parent_node ((ValaCodeNode*) _tmp2_, (ValaCodeNode*) self);
	}
}

ValaDataType*
vala_variable_get_variable_type (ValaVariable* self)
{
	ValaDataType* result;
	ValaDataType* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_variable_type;
	result = _tmp0_;
	return result;
}

void
vala_variable_set_variable_type (ValaVariable* self,
                                 ValaDataType* value)
{
	ValaDataType* _tmp0_;
	ValaDataType* _tmp1_;
	g_return_if_fail (self != NULL);
	_tmp0_ = _vala_code_node_ref0 (value);
	_vala_code_node_unref0 (self->priv->_variable_type);
	self->priv->_variable_type = _tmp0_;
	_tmp1_ = self->priv->_variable_type;
	if (_tmp1_ != NULL) {
		ValaDataType* _tmp2_;
		_tmp2_ = self->priv->_variable_type;
		vala_code_node_set_parent_node ((ValaCodeNode*) _tmp2_, (ValaCodeNode*) self);
	}
}

gboolean
vala_variable_get_single_assignment (ValaVariable* self)
{
	gboolean result;
	g_return_val_if_fail (self != NULL, FALSE);
	result = self->priv->_single_assignment;
	return result;
}

void
vala_variable_set_single_assignment (ValaVariable* self,
                                     gboolean value)
{
	g_return_if_fail (self != NULL);
	self->priv->_single_assignment = value;
}

ValaVariable*
vala_variable_construct (GType object_type,
                         ValaDataType* variable_type,
                         const gchar* name,
                         ValaExpression* initializer,
                         ValaSourceReference* source_reference,
                         ValaComment* comment)
{
	ValaVariable* self = NULL;
	self = (ValaVariable*) vala_symbol_construct (object_type, name, source_reference, comment);
	vala_variable_set_variable_type (self, variable_type);
	vala_variable_set_initializer (self, initializer);
	return self;
}

static void
vala_variable_class_init (ValaVariableClass * klass,
                          gpointer klass_data)
{
	vala_variable_parent_class = g_type_class_peek_parent (klass);
	((ValaCodeNodeClass *) klass)->finalize = vala_variable_finalize;
	g_type_class_adjust_private_offset (klass, &ValaVariable_private_offset);
}

static void
vala_variable_instance_init (ValaVariable * self,
                             gpointer klass)
{
	self->priv = vala_variable_get_instance_private (self);
}

static void
vala_variable_finalize (ValaCodeNode * obj)
{
	ValaVariable * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, VALA_TYPE_VARIABLE, ValaVariable);
	_vala_code_node_unref0 (self->priv->_initializer);
	_vala_code_node_unref0 (self->priv->_variable_type);
	VALA_CODE_NODE_CLASS (vala_variable_parent_class)->finalize (obj);
}

static GType
vala_variable_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (ValaVariableClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) vala_variable_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (ValaVariable), 0, (GInstanceInitFunc) vala_variable_instance_init, NULL };
	GType vala_variable_type_id;
	vala_variable_type_id = g_type_register_static (VALA_TYPE_SYMBOL, "ValaVariable", &g_define_type_info, G_TYPE_FLAG_ABSTRACT);
	ValaVariable_private_offset = g_type_add_instance_private (vala_variable_type_id, sizeof (ValaVariablePrivate));
	return vala_variable_type_id;
}

GType
vala_variable_get_type (void)
{
	static volatile gsize vala_variable_type_id__once = 0;
	if (g_once_init_enter (&vala_variable_type_id__once)) {
		GType vala_variable_type_id;
		vala_variable_type_id = vala_variable_get_type_once ();
		g_once_init_leave (&vala_variable_type_id__once, vala_variable_type_id);
	}
	return vala_variable_type_id__once;
}

