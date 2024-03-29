/* valaccodememberaccess.c generated by valac, the Vala compiler
 * generated from valaccodememberaccess.vala, do not modify */

/* valaccodememberaccess.vala
 *
 * Copyright (C) 2006-2008  Jürg Billeter
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

#include "valaccode.h"
#include <stdlib.h>
#include <string.h>
#include <glib.h>
#include <glib-object.h>

#define _vala_ccode_node_unref0(var) ((var == NULL) ? NULL : (var = (vala_ccode_node_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))

struct _ValaCCodeMemberAccessPrivate {
	ValaCCodeExpression* _inner;
	gchar* _member_name;
	gboolean _is_pointer;
};

static gint ValaCCodeMemberAccess_private_offset;
static gpointer vala_ccode_member_access_parent_class = NULL;

static void vala_ccode_member_access_real_write (ValaCCodeNode* base,
                                          ValaCCodeWriter* writer);
static void vala_ccode_member_access_finalize (ValaCCodeNode * obj);
static GType vala_ccode_member_access_get_type_once (void);

static inline gpointer
vala_ccode_member_access_get_instance_private (ValaCCodeMemberAccess* self)
{
	return G_STRUCT_MEMBER_P (self, ValaCCodeMemberAccess_private_offset);
}

ValaCCodeExpression*
vala_ccode_member_access_get_inner (ValaCCodeMemberAccess* self)
{
	ValaCCodeExpression* result;
	ValaCCodeExpression* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_inner;
	result = _tmp0_;
	return result;
}

static gpointer
_vala_ccode_node_ref0 (gpointer self)
{
	return self ? vala_ccode_node_ref (self) : NULL;
}

void
vala_ccode_member_access_set_inner (ValaCCodeMemberAccess* self,
                                    ValaCCodeExpression* value)
{
	ValaCCodeExpression* _tmp0_;
	g_return_if_fail (self != NULL);
	_tmp0_ = _vala_ccode_node_ref0 (value);
	_vala_ccode_node_unref0 (self->priv->_inner);
	self->priv->_inner = _tmp0_;
}

const gchar*
vala_ccode_member_access_get_member_name (ValaCCodeMemberAccess* self)
{
	const gchar* result;
	const gchar* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_member_name;
	result = _tmp0_;
	return result;
}

void
vala_ccode_member_access_set_member_name (ValaCCodeMemberAccess* self,
                                          const gchar* value)
{
	gchar* _tmp0_;
	g_return_if_fail (self != NULL);
	_tmp0_ = g_strdup (value);
	_g_free0 (self->priv->_member_name);
	self->priv->_member_name = _tmp0_;
}

gboolean
vala_ccode_member_access_get_is_pointer (ValaCCodeMemberAccess* self)
{
	gboolean result;
	g_return_val_if_fail (self != NULL, FALSE);
	result = self->priv->_is_pointer;
	return result;
}

void
vala_ccode_member_access_set_is_pointer (ValaCCodeMemberAccess* self,
                                         gboolean value)
{
	g_return_if_fail (self != NULL);
	self->priv->_is_pointer = value;
}

ValaCCodeMemberAccess*
vala_ccode_member_access_construct (GType object_type,
                                    ValaCCodeExpression* container,
                                    const gchar* member,
                                    gboolean pointer)
{
	ValaCCodeMemberAccess* self = NULL;
	g_return_val_if_fail (container != NULL, NULL);
	g_return_val_if_fail (member != NULL, NULL);
	self = (ValaCCodeMemberAccess*) vala_ccode_expression_construct (object_type);
	vala_ccode_member_access_set_inner (self, container);
	vala_ccode_member_access_set_member_name (self, member);
	vala_ccode_member_access_set_is_pointer (self, pointer);
	return self;
}

ValaCCodeMemberAccess*
vala_ccode_member_access_new (ValaCCodeExpression* container,
                              const gchar* member,
                              gboolean pointer)
{
	return vala_ccode_member_access_construct (VALA_TYPE_CCODE_MEMBER_ACCESS, container, member, pointer);
}

ValaCCodeMemberAccess*
vala_ccode_member_access_construct_pointer (GType object_type,
                                            ValaCCodeExpression* container,
                                            const gchar* member)
{
	ValaCCodeMemberAccess* self = NULL;
	g_return_val_if_fail (container != NULL, NULL);
	g_return_val_if_fail (member != NULL, NULL);
	self = (ValaCCodeMemberAccess*) vala_ccode_expression_construct (object_type);
	vala_ccode_member_access_set_inner (self, container);
	vala_ccode_member_access_set_member_name (self, member);
	vala_ccode_member_access_set_is_pointer (self, TRUE);
	return self;
}

ValaCCodeMemberAccess*
vala_ccode_member_access_new_pointer (ValaCCodeExpression* container,
                                      const gchar* member)
{
	return vala_ccode_member_access_construct_pointer (VALA_TYPE_CCODE_MEMBER_ACCESS, container, member);
}

static void
vala_ccode_member_access_real_write (ValaCCodeNode* base,
                                     ValaCCodeWriter* writer)
{
	ValaCCodeMemberAccess * self;
	ValaCCodeExpression* _tmp0_;
	gboolean _tmp1_;
	const gchar* _tmp2_;
	self = (ValaCCodeMemberAccess*) base;
	g_return_if_fail (writer != NULL);
	_tmp0_ = self->priv->_inner;
	vala_ccode_expression_write_inner (_tmp0_, writer);
	_tmp1_ = self->priv->_is_pointer;
	if (_tmp1_) {
		vala_ccode_writer_write_string (writer, "->");
	} else {
		vala_ccode_writer_write_string (writer, ".");
	}
	_tmp2_ = self->priv->_member_name;
	vala_ccode_writer_write_string (writer, _tmp2_);
}

static void
vala_ccode_member_access_class_init (ValaCCodeMemberAccessClass * klass,
                                     gpointer klass_data)
{
	vala_ccode_member_access_parent_class = g_type_class_peek_parent (klass);
	((ValaCCodeNodeClass *) klass)->finalize = vala_ccode_member_access_finalize;
	g_type_class_adjust_private_offset (klass, &ValaCCodeMemberAccess_private_offset);
	((ValaCCodeNodeClass *) klass)->write = (void (*) (ValaCCodeNode*, ValaCCodeWriter*)) vala_ccode_member_access_real_write;
}

static void
vala_ccode_member_access_instance_init (ValaCCodeMemberAccess * self,
                                        gpointer klass)
{
	self->priv = vala_ccode_member_access_get_instance_private (self);
}

static void
vala_ccode_member_access_finalize (ValaCCodeNode * obj)
{
	ValaCCodeMemberAccess * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, VALA_TYPE_CCODE_MEMBER_ACCESS, ValaCCodeMemberAccess);
	_vala_ccode_node_unref0 (self->priv->_inner);
	_g_free0 (self->priv->_member_name);
	VALA_CCODE_NODE_CLASS (vala_ccode_member_access_parent_class)->finalize (obj);
}

/**
 * Represents an access to a struct member in the C code.
 */
static GType
vala_ccode_member_access_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (ValaCCodeMemberAccessClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) vala_ccode_member_access_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (ValaCCodeMemberAccess), 0, (GInstanceInitFunc) vala_ccode_member_access_instance_init, NULL };
	GType vala_ccode_member_access_type_id;
	vala_ccode_member_access_type_id = g_type_register_static (VALA_TYPE_CCODE_EXPRESSION, "ValaCCodeMemberAccess", &g_define_type_info, 0);
	ValaCCodeMemberAccess_private_offset = g_type_add_instance_private (vala_ccode_member_access_type_id, sizeof (ValaCCodeMemberAccessPrivate));
	return vala_ccode_member_access_type_id;
}

GType
vala_ccode_member_access_get_type (void)
{
	static volatile gsize vala_ccode_member_access_type_id__once = 0;
	if (g_once_init_enter (&vala_ccode_member_access_type_id__once)) {
		GType vala_ccode_member_access_type_id;
		vala_ccode_member_access_type_id = vala_ccode_member_access_get_type_once ();
		g_once_init_leave (&vala_ccode_member_access_type_id__once, vala_ccode_member_access_type_id);
	}
	return vala_ccode_member_access_type_id__once;
}

