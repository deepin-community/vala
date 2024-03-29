/* settings.c generated by valac, the Vala compiler
 * generated from settings.vala, do not modify */

/* settings.vala
 *
 * Copyright (C) 2008-2009 Florian Brosch
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301  USA
 *
 * Author:
 * 	Brosch Florian <flo.brosch@gmail.com>
 */

#include "valadoc.h"
#include <stdlib.h>
#include <string.h>
#include <glib.h>
#include <glib-object.h>

enum  {
	VALADOC_SETTINGS_0_PROPERTY,
	VALADOC_SETTINGS_NUM_PROPERTIES
};
static GParamSpec* valadoc_settings_properties[VALADOC_SETTINGS_NUM_PROPERTIES];
#define _g_free0(var) (var = (g_free (var), NULL))

static gpointer valadoc_settings_parent_class = NULL;

static void valadoc_settings_finalize (GObject * obj);
static GType valadoc_settings_get_type_once (void);
static void _vala_array_destroy (gpointer array,
                          gssize array_length,
                          GDestroyNotify destroy_func);
static void _vala_array_free (gpointer array,
                       gssize array_length,
                       GDestroyNotify destroy_func);

ValadocSettings*
valadoc_settings_construct (GType object_type)
{
	ValadocSettings * self = NULL;
	self = (ValadocSettings*) g_object_new (object_type, NULL);
	return self;
}

ValadocSettings*
valadoc_settings_new (void)
{
	return valadoc_settings_construct (VALADOC_TYPE_SETTINGS);
}

static void
valadoc_settings_class_init (ValadocSettingsClass * klass,
                             gpointer klass_data)
{
	valadoc_settings_parent_class = g_type_class_peek_parent (klass);
	G_OBJECT_CLASS (klass)->finalize = valadoc_settings_finalize;
}

static void
valadoc_settings_instance_init (ValadocSettings * self,
                                gpointer klass)
{
	gchar* _tmp0_;
	_tmp0_ = g_strdup ("documentation/");
	self->path = _tmp0_;
	self->pkg_name = NULL;
	self->_private = FALSE;
	self->_protected = FALSE;
	self->_internal = FALSE;
	self->with_deps = FALSE;
	self->add_inherited = FALSE;
	self->verbose = FALSE;
	self->use_svg_images = FALSE;
}

static void
valadoc_settings_finalize (GObject * obj)
{
	ValadocSettings * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, VALADOC_TYPE_SETTINGS, ValadocSettings);
	_g_free0 (self->path);
	_g_free0 (self->pkg_name);
	_g_free0 (self->pkg_version);
	_g_free0 (self->wiki_directory);
	self->pluginargs = (_vala_array_free (self->pluginargs, self->pluginargs_length1, (GDestroyNotify) g_free), NULL);
	_g_free0 (self->basedir);
	_g_free0 (self->directory);
	self->defines = (_vala_array_free (self->defines, self->defines_length1, (GDestroyNotify) g_free), NULL);
	self->vapi_directories = (_vala_array_free (self->vapi_directories, self->vapi_directories_length1, (GDestroyNotify) g_free), NULL);
	self->packages = (_vala_array_free (self->packages, self->packages_length1, (GDestroyNotify) g_free), NULL);
	self->source_files = (_vala_array_free (self->source_files, self->source_files_length1, (GDestroyNotify) g_free), NULL);
	_g_free0 (self->gir_directory);
	_g_free0 (self->gir_name);
	self->metadata_directories = (_vala_array_free (self->metadata_directories, self->metadata_directories_length1, (GDestroyNotify) g_free), NULL);
	self->alternative_resource_dirs = (_vala_array_free (self->alternative_resource_dirs, self->alternative_resource_dirs_length1, (GDestroyNotify) g_free), NULL);
	self->gir_directories = (_vala_array_free (self->gir_directories, self->gir_directories_length1, (GDestroyNotify) g_free), NULL);
	_g_free0 (self->target_glib);
	_g_free0 (self->gir_namespace);
	_g_free0 (self->gir_version);
	G_OBJECT_CLASS (valadoc_settings_parent_class)->finalize (obj);
}

/**
 * Contains information about output settings configuration
 */
static GType
valadoc_settings_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (ValadocSettingsClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) valadoc_settings_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (ValadocSettings), 0, (GInstanceInitFunc) valadoc_settings_instance_init, NULL };
	GType valadoc_settings_type_id;
	valadoc_settings_type_id = g_type_register_static (G_TYPE_OBJECT, "ValadocSettings", &g_define_type_info, 0);
	return valadoc_settings_type_id;
}

GType
valadoc_settings_get_type (void)
{
	static volatile gsize valadoc_settings_type_id__once = 0;
	if (g_once_init_enter (&valadoc_settings_type_id__once)) {
		GType valadoc_settings_type_id;
		valadoc_settings_type_id = valadoc_settings_get_type_once ();
		g_once_init_leave (&valadoc_settings_type_id__once, valadoc_settings_type_id);
	}
	return valadoc_settings_type_id__once;
}

static void
_vala_array_destroy (gpointer array,
                     gssize array_length,
                     GDestroyNotify destroy_func)
{
	if ((array != NULL) && (destroy_func != NULL)) {
		gssize i;
		for (i = 0; i < array_length; i = i + 1) {
			if (((gpointer*) array)[i] != NULL) {
				destroy_func (((gpointer*) array)[i]);
			}
		}
	}
}

static void
_vala_array_free (gpointer array,
                  gssize array_length,
                  GDestroyNotify destroy_func)
{
	_vala_array_destroy (array, array_length, destroy_func);
	g_free (array);
}

