/* valaccodeincludedirective.c generated by valac, the Vala compiler
 * generated from valaccodeincludedirective.vala, do not modify */

/* valaccodeincludedirective.vala
 *
 * Copyright (C) 2006  Jürg Billeter
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

#define _g_free0(var) (var = (g_free (var), NULL))

struct _ValaCCodeIncludeDirectivePrivate {
	gchar* _filename;
	gboolean _local;
};

static gint ValaCCodeIncludeDirective_private_offset;
static gpointer vala_ccode_include_directive_parent_class = NULL;

static void vala_ccode_include_directive_real_write (ValaCCodeNode* base,
                                              ValaCCodeWriter* writer);
static void vala_ccode_include_directive_finalize (ValaCCodeNode * obj);
static GType vala_ccode_include_directive_get_type_once (void);

static inline gpointer
vala_ccode_include_directive_get_instance_private (ValaCCodeIncludeDirective* self)
{
	return G_STRUCT_MEMBER_P (self, ValaCCodeIncludeDirective_private_offset);
}

const gchar*
vala_ccode_include_directive_get_filename (ValaCCodeIncludeDirective* self)
{
	const gchar* result;
	const gchar* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_filename;
	result = _tmp0_;
	return result;
}

void
vala_ccode_include_directive_set_filename (ValaCCodeIncludeDirective* self,
                                           const gchar* value)
{
	gchar* _tmp0_;
	g_return_if_fail (self != NULL);
	_tmp0_ = g_strdup (value);
	_g_free0 (self->priv->_filename);
	self->priv->_filename = _tmp0_;
}

gboolean
vala_ccode_include_directive_get_local (ValaCCodeIncludeDirective* self)
{
	gboolean result;
	g_return_val_if_fail (self != NULL, FALSE);
	result = self->priv->_local;
	return result;
}

void
vala_ccode_include_directive_set_local (ValaCCodeIncludeDirective* self,
                                        gboolean value)
{
	g_return_if_fail (self != NULL);
	self->priv->_local = value;
}

ValaCCodeIncludeDirective*
vala_ccode_include_directive_construct (GType object_type,
                                        const gchar* _filename,
                                        gboolean _local)
{
	ValaCCodeIncludeDirective* self = NULL;
	g_return_val_if_fail (_filename != NULL, NULL);
	self = (ValaCCodeIncludeDirective*) vala_ccode_node_construct (object_type);
	vala_ccode_include_directive_set_filename (self, _filename);
	vala_ccode_include_directive_set_local (self, _local);
	return self;
}

ValaCCodeIncludeDirective*
vala_ccode_include_directive_new (const gchar* _filename,
                                  gboolean _local)
{
	return vala_ccode_include_directive_construct (VALA_TYPE_CCODE_INCLUDE_DIRECTIVE, _filename, _local);
}

static void
vala_ccode_include_directive_real_write (ValaCCodeNode* base,
                                         ValaCCodeWriter* writer)
{
	ValaCCodeIncludeDirective * self;
	gboolean _tmp0_;
	self = (ValaCCodeIncludeDirective*) base;
	g_return_if_fail (writer != NULL);
	vala_ccode_writer_write_indent (writer, NULL);
	vala_ccode_writer_write_string (writer, "#include ");
	_tmp0_ = self->priv->_local;
	if (_tmp0_) {
		const gchar* _tmp1_;
		vala_ccode_writer_write_string (writer, "\"");
		_tmp1_ = self->priv->_filename;
		vala_ccode_writer_write_string (writer, _tmp1_);
		vala_ccode_writer_write_string (writer, "\"");
	} else {
		const gchar* _tmp2_;
		vala_ccode_writer_write_string (writer, "<");
		_tmp2_ = self->priv->_filename;
		vala_ccode_writer_write_string (writer, _tmp2_);
		vala_ccode_writer_write_string (writer, ">");
	}
	vala_ccode_writer_write_newline (writer);
}

static void
vala_ccode_include_directive_class_init (ValaCCodeIncludeDirectiveClass * klass,
                                         gpointer klass_data)
{
	vala_ccode_include_directive_parent_class = g_type_class_peek_parent (klass);
	((ValaCCodeNodeClass *) klass)->finalize = vala_ccode_include_directive_finalize;
	g_type_class_adjust_private_offset (klass, &ValaCCodeIncludeDirective_private_offset);
	((ValaCCodeNodeClass *) klass)->write = (void (*) (ValaCCodeNode*, ValaCCodeWriter*)) vala_ccode_include_directive_real_write;
}

static void
vala_ccode_include_directive_instance_init (ValaCCodeIncludeDirective * self,
                                            gpointer klass)
{
	self->priv = vala_ccode_include_directive_get_instance_private (self);
}

static void
vala_ccode_include_directive_finalize (ValaCCodeNode * obj)
{
	ValaCCodeIncludeDirective * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, VALA_TYPE_CCODE_INCLUDE_DIRECTIVE, ValaCCodeIncludeDirective);
	_g_free0 (self->priv->_filename);
	VALA_CCODE_NODE_CLASS (vala_ccode_include_directive_parent_class)->finalize (obj);
}

/**
 * Represents an include preprocessor directive in the C code.
 */
static GType
vala_ccode_include_directive_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (ValaCCodeIncludeDirectiveClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) vala_ccode_include_directive_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (ValaCCodeIncludeDirective), 0, (GInstanceInitFunc) vala_ccode_include_directive_instance_init, NULL };
	GType vala_ccode_include_directive_type_id;
	vala_ccode_include_directive_type_id = g_type_register_static (VALA_TYPE_CCODE_NODE, "ValaCCodeIncludeDirective", &g_define_type_info, 0);
	ValaCCodeIncludeDirective_private_offset = g_type_add_instance_private (vala_ccode_include_directive_type_id, sizeof (ValaCCodeIncludeDirectivePrivate));
	return vala_ccode_include_directive_type_id;
}

GType
vala_ccode_include_directive_get_type (void)
{
	static volatile gsize vala_ccode_include_directive_type_id__once = 0;
	if (g_once_init_enter (&vala_ccode_include_directive_type_id__once)) {
		GType vala_ccode_include_directive_type_id;
		vala_ccode_include_directive_type_id = vala_ccode_include_directive_get_type_once ();
		g_once_init_leave (&vala_ccode_include_directive_type_id__once, vala_ccode_include_directive_type_id);
	}
	return vala_ccode_include_directive_type_id__once;
}

