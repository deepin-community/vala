/* valaprofile.c generated by valac, the Vala compiler
 * generated from valaprofile.vala, do not modify */

/* valaprofile.vala
 *
 * Copyright (C) 2009-2010  Jürg Billeter
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

static GType
vala_profile_get_type_once (void)
{
	static const GEnumValue values[] = {{VALA_PROFILE_GOBJECT, "VALA_PROFILE_GOBJECT", "gobject"}, {VALA_PROFILE_LIBC, "VALA_PROFILE_LIBC", "libc"}, {VALA_PROFILE_POSIX, "VALA_PROFILE_POSIX", "posix"}, {0, NULL, NULL}};
	GType vala_profile_type_id;
	vala_profile_type_id = g_enum_register_static ("ValaProfile", values);
	return vala_profile_type_id;
}

GType
vala_profile_get_type (void)
{
	static volatile gsize vala_profile_type_id__once = 0;
	if (g_once_init_enter (&vala_profile_type_id__once)) {
		GType vala_profile_type_id;
		vala_profile_type_id = vala_profile_get_type_once ();
		g_once_init_leave (&vala_profile_type_id__once, vala_profile_type_id);
	}
	return vala_profile_type_id__once;
}

