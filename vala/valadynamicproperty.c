/* valadynamicproperty.c generated by valac, the Vala compiler
 * generated from valadynamicproperty.vala, do not modify */

/* valadynamicproperty.vala
 *
 * Copyright (C) 2008  Jürg Billeter
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

struct _ValaDynamicPropertyPrivate {
	ValaDataType* _dynamic_type;
};

static gint ValaDynamicProperty_private_offset;
static gpointer vala_dynamic_property_parent_class = NULL;

static void vala_dynamic_property_set_dynamic_type (ValaDynamicProperty* self,
                                             ValaDataType* value);
static gboolean vala_dynamic_property_real_check (ValaCodeNode* base,
                                           ValaCodeContext* context);
static void vala_dynamic_property_finalize (ValaCodeNode * obj);
static GType vala_dynamic_property_get_type_once (void);

static inline gpointer
vala_dynamic_property_get_instance_private (ValaDynamicProperty* self)
{
	return G_STRUCT_MEMBER_P (self, ValaDynamicProperty_private_offset);
}

ValaDataType*
vala_dynamic_property_get_dynamic_type (ValaDynamicProperty* self)
{
	ValaDataType* result;
	ValaDataType* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_dynamic_type;
	result = _tmp0_;
	return result;
}

static gpointer
_vala_code_node_ref0 (gpointer self)
{
	return self ? vala_code_node_ref (self) : NULL;
}

static void
vala_dynamic_property_set_dynamic_type (ValaDynamicProperty* self,
                                        ValaDataType* value)
{
	ValaDataType* _tmp0_;
	g_return_if_fail (self != NULL);
	_tmp0_ = _vala_code_node_ref0 (value);
	_vala_code_node_unref0 (self->priv->_dynamic_type);
	self->priv->_dynamic_type = _tmp0_;
}

ValaDynamicProperty*
vala_dynamic_property_construct (GType object_type,
                                 ValaDataType* dynamic_type,
                                 const gchar* name,
                                 ValaSourceReference* source_reference,
                                 ValaComment* comment)
{
	ValaDynamicProperty* self = NULL;
	g_return_val_if_fail (dynamic_type != NULL, NULL);
	g_return_val_if_fail (name != NULL, NULL);
	self = (ValaDynamicProperty*) vala_property_construct (object_type, name, NULL, NULL, NULL, source_reference, comment);
	vala_dynamic_property_set_dynamic_type (self, dynamic_type);
	return self;
}

ValaDynamicProperty*
vala_dynamic_property_new (ValaDataType* dynamic_type,
                           const gchar* name,
                           ValaSourceReference* source_reference,
                           ValaComment* comment)
{
	return vala_dynamic_property_construct (VALA_TYPE_DYNAMIC_PROPERTY, dynamic_type, name, source_reference, comment);
}

static gboolean
vala_dynamic_property_real_check (ValaCodeNode* base,
                                  ValaCodeContext* context)
{
	ValaDynamicProperty * self;
	gboolean result;
	self = (ValaDynamicProperty*) base;
	g_return_val_if_fail (context != NULL, FALSE);
	result = TRUE;
	return result;
}

static void
vala_dynamic_property_class_init (ValaDynamicPropertyClass * klass,
                                  gpointer klass_data)
{
	vala_dynamic_property_parent_class = g_type_class_peek_parent (klass);
	((ValaCodeNodeClass *) klass)->finalize = vala_dynamic_property_finalize;
	g_type_class_adjust_private_offset (klass, &ValaDynamicProperty_private_offset);
	((ValaCodeNodeClass *) klass)->check = (gboolean (*) (ValaCodeNode*, ValaCodeContext*)) vala_dynamic_property_real_check;
}

static void
vala_dynamic_property_instance_init (ValaDynamicProperty * self,
                                     gpointer klass)
{
	self->priv = vala_dynamic_property_get_instance_private (self);
}

static void
vala_dynamic_property_finalize (ValaCodeNode * obj)
{
	ValaDynamicProperty * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, VALA_TYPE_DYNAMIC_PROPERTY, ValaDynamicProperty);
	_vala_code_node_unref0 (self->priv->_dynamic_type);
	VALA_CODE_NODE_CLASS (vala_dynamic_property_parent_class)->finalize (obj);
}

/**
 * Represents a late bound property.
 */
static GType
vala_dynamic_property_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (ValaDynamicPropertyClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) vala_dynamic_property_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (ValaDynamicProperty), 0, (GInstanceInitFunc) vala_dynamic_property_instance_init, NULL };
	GType vala_dynamic_property_type_id;
	vala_dynamic_property_type_id = g_type_register_static (VALA_TYPE_PROPERTY, "ValaDynamicProperty", &g_define_type_info, 0);
	ValaDynamicProperty_private_offset = g_type_add_instance_private (vala_dynamic_property_type_id, sizeof (ValaDynamicPropertyPrivate));
	return vala_dynamic_property_type_id;
}

GType
vala_dynamic_property_get_type (void)
{
	static volatile gsize vala_dynamic_property_type_id__once = 0;
	if (g_once_init_enter (&vala_dynamic_property_type_id__once)) {
		GType vala_dynamic_property_type_id;
		vala_dynamic_property_type_id = vala_dynamic_property_get_type_once ();
		g_once_init_leave (&vala_dynamic_property_type_id__once, vala_dynamic_property_type_id);
	}
	return vala_dynamic_property_type_id__once;
}

