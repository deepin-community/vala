/* valaccodemacroreplacement.c generated by valac, the Vala compiler
 * generated from valaccodemacroreplacement.vala, do not modify */

/* valaccodemacroreplacement.vala
 *
 * Copyright (C) 2006-2009  Jürg Billeter
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

static gpointer vala_ccode_macro_replacement_parent_class = NULL;

static GType vala_ccode_macro_replacement_get_type_once (void);

ValaCCodeMacroReplacement*
vala_ccode_macro_replacement_construct (GType object_type,
                                        const gchar* name,
                                        const gchar* replacement)
{
	ValaCCodeMacroReplacement* self = NULL;
	g_return_val_if_fail (name != NULL, NULL);
	g_return_val_if_fail (replacement != NULL, NULL);
	self = (ValaCCodeMacroReplacement*) vala_ccode_define_construct (object_type, name, replacement);
	return self;
}

ValaCCodeMacroReplacement*
vala_ccode_macro_replacement_new (const gchar* name,
                                  const gchar* replacement)
{
	return vala_ccode_macro_replacement_construct (VALA_TYPE_CCODE_MACRO_REPLACEMENT, name, replacement);
}

ValaCCodeMacroReplacement*
vala_ccode_macro_replacement_construct_with_expression (GType object_type,
                                                        const gchar* name,
                                                        ValaCCodeExpression* replacement_expression)
{
	ValaCCodeMacroReplacement* self = NULL;
	g_return_val_if_fail (name != NULL, NULL);
	g_return_val_if_fail (replacement_expression != NULL, NULL);
	self = (ValaCCodeMacroReplacement*) vala_ccode_define_construct_with_expression (object_type, name, replacement_expression);
	return self;
}

ValaCCodeMacroReplacement*
vala_ccode_macro_replacement_new_with_expression (const gchar* name,
                                                  ValaCCodeExpression* replacement_expression)
{
	return vala_ccode_macro_replacement_construct_with_expression (VALA_TYPE_CCODE_MACRO_REPLACEMENT, name, replacement_expression);
}

static void
vala_ccode_macro_replacement_class_init (ValaCCodeMacroReplacementClass * klass,
                                         gpointer klass_data)
{
	vala_ccode_macro_replacement_parent_class = g_type_class_peek_parent (klass);
}

static void
vala_ccode_macro_replacement_instance_init (ValaCCodeMacroReplacement * self,
                                            gpointer klass)
{
}

/**
 * Represents a preprocessor macro replacement definition in the C code.
 */
static GType
vala_ccode_macro_replacement_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (ValaCCodeMacroReplacementClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) vala_ccode_macro_replacement_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (ValaCCodeMacroReplacement), 0, (GInstanceInitFunc) vala_ccode_macro_replacement_instance_init, NULL };
	GType vala_ccode_macro_replacement_type_id;
	vala_ccode_macro_replacement_type_id = g_type_register_static (VALA_TYPE_CCODE_DEFINE, "ValaCCodeMacroReplacement", &g_define_type_info, 0);
	return vala_ccode_macro_replacement_type_id;
}

GType
vala_ccode_macro_replacement_get_type (void)
{
	static volatile gsize vala_ccode_macro_replacement_type_id__volatile = 0;
	if (g_once_init_enter (&vala_ccode_macro_replacement_type_id__volatile)) {
		GType vala_ccode_macro_replacement_type_id;
		vala_ccode_macro_replacement_type_id = vala_ccode_macro_replacement_get_type_once ();
		g_once_init_leave (&vala_ccode_macro_replacement_type_id__volatile, vala_ccode_macro_replacement_type_id);
	}
	return vala_ccode_macro_replacement_type_id__volatile;
}
