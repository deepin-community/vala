/* valaccodestatement.c generated by valac, the Vala compiler
 * generated from valaccodestatement.vala, do not modify */

/* valaccodestatement.vala
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
#include <glib-object.h>

static gpointer vala_ccode_statement_parent_class = NULL;

static GType vala_ccode_statement_get_type_once (void);

ValaCCodeStatement*
vala_ccode_statement_construct (GType object_type)
{
	ValaCCodeStatement* self = NULL;
	self = (ValaCCodeStatement*) vala_ccode_node_construct (object_type);
	return self;
}

static void
vala_ccode_statement_class_init (ValaCCodeStatementClass * klass,
                                 gpointer klass_data)
{
	vala_ccode_statement_parent_class = g_type_class_peek_parent (klass);
}

static void
vala_ccode_statement_instance_init (ValaCCodeStatement * self,
                                    gpointer klass)
{
}

/**
 * Represents a statement in the C code.
 */
static GType
vala_ccode_statement_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (ValaCCodeStatementClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) vala_ccode_statement_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (ValaCCodeStatement), 0, (GInstanceInitFunc) vala_ccode_statement_instance_init, NULL };
	GType vala_ccode_statement_type_id;
	vala_ccode_statement_type_id = g_type_register_static (VALA_TYPE_CCODE_NODE, "ValaCCodeStatement", &g_define_type_info, G_TYPE_FLAG_ABSTRACT);
	return vala_ccode_statement_type_id;
}

GType
vala_ccode_statement_get_type (void)
{
	static volatile gsize vala_ccode_statement_type_id__once = 0;
	if (g_once_init_enter (&vala_ccode_statement_type_id__once)) {
		GType vala_ccode_statement_type_id;
		vala_ccode_statement_type_id = vala_ccode_statement_get_type_once ();
		g_once_init_leave (&vala_ccode_statement_type_id__once, vala_ccode_statement_type_id);
	}
	return vala_ccode_statement_type_id__once;
}

