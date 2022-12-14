/* valaccode.c generated by valac, the Vala compiler
 * generated from valaccode.vala, do not modify */

/* valaccode.vala
 *
 * Copyright (C) 2020  Rico Tzschichholz
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

#include "valaccode.h"
#include <vala.h>
#include <glib.h>

const gchar* vala_GNUC_CONST = NULL;
const gchar* vala_GNUC_DEPRECATED = NULL;
const gchar* vala_GNUC_FORMAT = NULL;
const gchar* vala_GNUC_INTERNAL = NULL;
const gchar* vala_GNUC_NO_INLINE = NULL;
const gchar* vala_GNUC_PRINTF = NULL;
const gchar* vala_GNUC_SCANF = NULL;
const gchar* vala_GNUC_UNUSED = NULL;

void
vala_ccode_init (ValaProfile profile)
{
	switch (profile) {
		case VALA_PROFILE_GOBJECT:
		{
			vala_GNUC_CONST = " G_GNUC_CONST ";
			vala_GNUC_DEPRECATED = " G_GNUC_DEPRECATED ";
			vala_GNUC_FORMAT = " G_GNUC_FORMAT(%d) ";
			vala_GNUC_INTERNAL = " G_GNUC_INTERNAL ";
			vala_GNUC_NO_INLINE = " G_GNUC_NO_INLINE ";
			vala_GNUC_PRINTF = "  G_GNUC_PRINTF(%d,%d) ";
			vala_GNUC_SCANF = " G_GNUC_SCANF(%d,%d) ";
			vala_GNUC_UNUSED = " G_GNUC_UNUSED ";
			break;
		}
		case VALA_PROFILE_POSIX:
		{
			vala_GNUC_CONST = " __attribute__((__const__)) ";
			vala_GNUC_DEPRECATED = " __attribute__((__deprecated__)) ";
			vala_GNUC_FORMAT = " __attribute__((__format_arg__ (arg_idx))) ";
			vala_GNUC_INTERNAL = " __attribute__((visibility(\"hidden\"))) ";
			vala_GNUC_NO_INLINE = " __attribute__((noinline)) ";
			vala_GNUC_PRINTF = " __attribute__((__format__ (__printf__, %d, %d))) ";
			vala_GNUC_SCANF = " __attribute__((__format__ (__scanf__, %d, %d))) ";
			vala_GNUC_UNUSED = " __attribute__((__unused__)) ";
			break;
		}
		default:
		{
			g_assert_not_reached ();
		}
	}
}

