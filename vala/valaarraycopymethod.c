/* valaarraycopymethod.c generated by valac, the Vala compiler
 * generated from valaarraycopymethod.vala, do not modify */

/* valaarraycopymethod.vala
 *
 * Copyright (C) 2011  Luca Bruno
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
 * 	Luca Bruno <lucabru@src.gnome.org>
 */

#include "vala.h"
#include <glib-object.h>
#include <glib.h>

#define _vala_code_node_unref0(var) ((var == NULL) ? NULL : (var = (vala_code_node_unref (var), NULL)))

static gpointer vala_array_copy_method_parent_class = NULL;

static GType vala_array_copy_method_get_type_once (void);

/**
 * Creates a new array copy method.
 *
 * @return newly created method
 */
ValaArrayCopyMethod*
vala_array_copy_method_construct (GType object_type,
                                  ValaSourceReference* source_reference)
{
	ValaArrayCopyMethod* self = NULL;
	ValaInvalidType* _tmp0_;
	ValaInvalidType* _tmp1_;
	_tmp0_ = vala_invalid_type_new ();
	_tmp1_ = _tmp0_;
	self = (ValaArrayCopyMethod*) vala_method_construct (object_type, "copy", (ValaDataType*) _tmp1_, source_reference, NULL);
	_vala_code_node_unref0 (_tmp1_);
	vala_symbol_set_external ((ValaSymbol*) self, TRUE);
	return self;
}

ValaArrayCopyMethod*
vala_array_copy_method_new (ValaSourceReference* source_reference)
{
	return vala_array_copy_method_construct (VALA_TYPE_ARRAY_COPY_METHOD, source_reference);
}

static void
vala_array_copy_method_class_init (ValaArrayCopyMethodClass * klass,
                                   gpointer klass_data)
{
	vala_array_copy_method_parent_class = g_type_class_peek_parent (klass);
}

static void
vala_array_copy_method_instance_init (ValaArrayCopyMethod * self,
                                      gpointer klass)
{
}

/**
 * Represents the Array.copy method.
 */
static GType
vala_array_copy_method_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (ValaArrayCopyMethodClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) vala_array_copy_method_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (ValaArrayCopyMethod), 0, (GInstanceInitFunc) vala_array_copy_method_instance_init, NULL };
	GType vala_array_copy_method_type_id;
	vala_array_copy_method_type_id = g_type_register_static (VALA_TYPE_METHOD, "ValaArrayCopyMethod", &g_define_type_info, 0);
	return vala_array_copy_method_type_id;
}

GType
vala_array_copy_method_get_type (void)
{
	static volatile gsize vala_array_copy_method_type_id__once = 0;
	if (g_once_init_enter (&vala_array_copy_method_type_id__once)) {
		GType vala_array_copy_method_type_id;
		vala_array_copy_method_type_id = vala_array_copy_method_get_type_once ();
		g_once_init_leave (&vala_array_copy_method_type_id__once, vala_array_copy_method_type_id);
	}
	return vala_array_copy_method_type_id__once;
}

