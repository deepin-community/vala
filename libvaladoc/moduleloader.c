/* moduleloader.c generated by valac, the Vala compiler
 * generated from moduleloader.vala, do not modify */

/* moduleloader.vala
 *
 * Copyright (C) 2008-2009 Florian Brosch
 * Copyright (C) 2011      Florian Brosch
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
#include <valagee.h>
#include <glib-object.h>
#include <stdlib.h>
#include <string.h>
#include <glib.h>
#include <gmodule.h>
#include <glib/gstdio.h>
#include <config.h>
#include <vala.h>

#define VALADOC_MODULE_LOADER_TYPE_MODULE_DATA (valadoc_module_loader_module_data_get_type ())
#define VALADOC_MODULE_LOADER_MODULE_DATA(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), VALADOC_MODULE_LOADER_TYPE_MODULE_DATA, ValadocModuleLoaderModuleData))
#define VALADOC_MODULE_LOADER_MODULE_DATA_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), VALADOC_MODULE_LOADER_TYPE_MODULE_DATA, ValadocModuleLoaderModuleDataClass))
#define VALADOC_MODULE_LOADER_IS_MODULE_DATA(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), VALADOC_MODULE_LOADER_TYPE_MODULE_DATA))
#define VALADOC_MODULE_LOADER_IS_MODULE_DATA_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), VALADOC_MODULE_LOADER_TYPE_MODULE_DATA))
#define VALADOC_MODULE_LOADER_MODULE_DATA_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), VALADOC_MODULE_LOADER_TYPE_MODULE_DATA, ValadocModuleLoaderModuleDataClass))

typedef struct _ValadocModuleLoaderModuleData ValadocModuleLoaderModuleData;
typedef struct _ValadocModuleLoaderModuleDataClass ValadocModuleLoaderModuleDataClass;
enum  {
	VALADOC_MODULE_LOADER_0_PROPERTY,
	VALADOC_MODULE_LOADER_NUM_PROPERTIES
};
static GParamSpec* valadoc_module_loader_properties[VALADOC_MODULE_LOADER_NUM_PROPERTIES];
#define _vala_map_unref0(var) ((var == NULL) ? NULL : (var = (vala_map_unref (var), NULL)))
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_module_close0(var) ((var == NULL) ? NULL : (var = (g_module_close (var), NULL)))
typedef struct _ValadocModuleLoaderModuleDataPrivate ValadocModuleLoaderModuleDataPrivate;
enum  {
	VALADOC_MODULE_LOADER_MODULE_DATA_0_PROPERTY,
	VALADOC_MODULE_LOADER_MODULE_DATA_NUM_PROPERTIES
};
static GParamSpec* valadoc_module_loader_module_data_properties[VALADOC_MODULE_LOADER_MODULE_DATA_NUM_PROPERTIES];

struct _ValadocModuleLoaderPrivate {
	ValaHashMap* doclets;
	ValaHashMap* taglets;
};

struct _ValadocModuleLoaderModuleData {
	GObject parent_instance;
	GModule* module;
	GType type;
	ValadocModuleLoaderModuleDataPrivate * priv;
};

struct _ValadocModuleLoaderModuleDataClass {
	GObjectClass parent_class;
};

static gint ValadocModuleLoader_private_offset;
static gpointer valadoc_module_loader_parent_class = NULL;
static ValadocModuleLoader* valadoc_module_loader_instance;
static ValadocModuleLoader* valadoc_module_loader_instance = NULL;
static gpointer valadoc_module_loader_module_data_parent_class = NULL;

static GType valadoc_module_loader_module_data_get_type (void) G_GNUC_CONST  G_GNUC_UNUSED ;
static ValadocModuleLoader* valadoc_module_loader_new (void);
static ValadocModuleLoader* valadoc_module_loader_construct (GType object_type);
static gchar* valadoc_module_loader_get_plugin_path (const gchar* pluginpath,
                                              const gchar* pluginsubdir);
static ValadocModuleLoaderModuleData* valadoc_module_loader_module_data_new (void);
static ValadocModuleLoaderModuleData* valadoc_module_loader_module_data_construct (GType object_type);
static void valadoc_module_loader_module_data_finalize (GObject * obj);
static GType valadoc_module_loader_module_data_get_type_once (void);
static void valadoc_module_loader_finalize (GObject * obj);
static GType valadoc_module_loader_get_type_once (void);

static inline gpointer
valadoc_module_loader_get_instance_private (ValadocModuleLoader* self)
{
	return G_STRUCT_MEMBER_P (self, ValadocModuleLoader_private_offset);
}

static gpointer
_g_object_ref0 (gpointer self)
{
	return self ? g_object_ref (self) : NULL;
}

ValadocModuleLoader*
valadoc_module_loader_get_instance (void)
{
	ValadocModuleLoader* _tmp0_;
	ValadocModuleLoader* _tmp3_;
	ValadocModuleLoader* _tmp4_;
	ValadocModuleLoader* result;
	_tmp0_ = valadoc_module_loader_instance;
	if (_tmp0_ == NULL) {
		ValadocModuleLoader* _tmp1_;
		ValadocModuleLoader* _tmp2_;
		_tmp1_ = valadoc_module_loader_new ();
		_g_object_unref0 (valadoc_module_loader_instance);
		valadoc_module_loader_instance = _tmp1_;
		_tmp2_ = valadoc_module_loader_instance;
		valadoc_taglets_init (_tmp2_);
	}
	_tmp3_ = valadoc_module_loader_instance;
	_tmp4_ = _g_object_ref0 (_tmp3_);
	result = _tmp4_;
	return result;
}

static ValadocModuleLoader*
valadoc_module_loader_construct (GType object_type)
{
	ValadocModuleLoader * self = NULL;
	self = (ValadocModuleLoader*) g_object_new (object_type, NULL);
	return self;
}

static ValadocModuleLoader*
valadoc_module_loader_new (void)
{
	return valadoc_module_loader_construct (VALADOC_TYPE_MODULE_LOADER);
}

gboolean
valadoc_module_loader_is_doclet (const gchar* path)
{
	gchar* library_path = NULL;
	gchar* _tmp0_;
	gboolean _tmp1_ = FALSE;
	gboolean result;
	g_return_val_if_fail (path != NULL, FALSE);
	_tmp0_ = g_build_filename (path, "libdoclet." G_MODULE_SUFFIX, NULL);
	library_path = _tmp0_;
	if (g_file_test (path, G_FILE_TEST_EXISTS)) {
		const gchar* _tmp2_;
		_tmp2_ = library_path;
		_tmp1_ = g_file_test (_tmp2_, G_FILE_TEST_EXISTS);
	} else {
		_tmp1_ = FALSE;
	}
	result = _tmp1_;
	_g_free0 (library_path);
	return result;
}

static gchar*
valadoc_module_loader_get_plugin_path (const gchar* pluginpath,
                                       const gchar* pluginsubdir)
{
	gchar* _tmp6_;
	gchar* result;
	g_return_val_if_fail (pluginpath != NULL, NULL);
	g_return_val_if_fail (pluginsubdir != NULL, NULL);
	if (g_path_is_absolute (pluginpath) == FALSE) {
		gchar* local_path = NULL;
		gchar* _tmp0_;
		gchar* _tmp1_;
		gchar* _tmp2_;
		gchar* _tmp3_;
		const gchar* _tmp4_;
		_tmp0_ = g_get_current_dir ();
		_tmp1_ = _tmp0_;
		_tmp2_ = g_build_filename (_tmp1_, pluginpath, NULL);
		_tmp3_ = _tmp2_;
		_g_free0 (_tmp1_);
		local_path = _tmp3_;
		_tmp4_ = local_path;
		if (valadoc_module_loader_is_doclet (_tmp4_)) {
			result = local_path;
			return result;
		} else {
			gchar* _tmp5_;
			_tmp5_ = g_build_filename (PACKAGE_VALADOC_LIBDIR, pluginsubdir, pluginpath, NULL);
			result = _tmp5_;
			_g_free0 (local_path);
			return result;
		}
		_g_free0 (local_path);
	}
	_tmp6_ = g_strdup (pluginpath);
	result = _tmp6_;
	return result;
}

gchar*
valadoc_module_loader_get_doclet_path (const gchar* docletpath,
                                       ValadocErrorReporter* reporter)
{
	gchar* _tmp1_;
	gchar* result;
	g_return_val_if_fail (reporter != NULL, NULL);
	if (docletpath == NULL) {
		gchar* _tmp0_;
		_tmp0_ = g_build_filename (PACKAGE_VALADOC_LIBDIR, "doclets", "html", NULL);
		result = _tmp0_;
		return result;
	}
	_tmp1_ = valadoc_module_loader_get_plugin_path (docletpath, "doclets");
	result = _tmp1_;
	return result;
}

ValadocContentTaglet*
valadoc_module_loader_create_taglet (ValadocModuleLoader* self,
                                     const gchar* keyword)
{
	ValadocContentTaglet* _tmp0_ = NULL;
	ValaHashMap* _tmp1_;
	ValadocContentTaglet* result;
	g_return_val_if_fail (self != NULL, NULL);
	g_return_val_if_fail (keyword != NULL, NULL);
	_tmp1_ = self->priv->taglets;
	if (vala_map_contains ((ValaMap*) _tmp1_, keyword)) {
		ValaHashMap* _tmp2_;
		gpointer _tmp3_;
		GObject* _tmp4_;
		GObject* _tmp5_;
		_tmp2_ = self->priv->taglets;
		_tmp3_ = vala_map_get ((ValaMap*) _tmp2_, keyword);
		_tmp4_ = g_object_new ((GType) ((gintptr) _tmp3_), NULL);
		_tmp5_ = G_IS_INITIALLY_UNOWNED (_tmp4_) ? g_object_ref_sink (_tmp4_) : _tmp4_;
		_g_object_unref0 (_tmp0_);
		_tmp0_ = G_TYPE_CHECK_INSTANCE_CAST (_tmp5_, VALADOC_CONTENT_TYPE_TAGLET, ValadocContentTaglet);
	} else {
		_g_object_unref0 (_tmp0_);
		_tmp0_ = NULL;
	}
	result = _tmp0_;
	return result;
}

void
valadoc_module_loader_register_taglet (ValadocModuleLoader* self,
                                       const gchar* keyword,
                                       GType type)
{
	ValaHashMap* _tmp0_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (keyword != NULL);
	_tmp0_ = self->priv->taglets;
	vala_map_set ((ValaMap*) _tmp0_, keyword, (gpointer) ((gintptr) type));
}

ValadocDoclet*
valadoc_module_loader_create_doclet (ValadocModuleLoader* self,
                                     const gchar* _path)
{
	gchar* path = NULL;
	gchar* _tmp0_;
	ValadocModuleLoaderModuleData* data = NULL;
	ValaHashMap* _tmp1_;
	const gchar* _tmp2_;
	gpointer _tmp3_;
	ValadocModuleLoaderModuleData* _tmp4_;
	ValadocModuleLoaderModuleData* _tmp23_;
	GObject* _tmp24_;
	GObject* _tmp25_;
	ValadocDoclet* result;
	g_return_val_if_fail (self != NULL, NULL);
	g_return_val_if_fail (_path != NULL, NULL);
	_tmp0_ = vala_code_context_realpath (_path);
	path = _tmp0_;
	_tmp1_ = self->priv->doclets;
	_tmp2_ = path;
	_tmp3_ = vala_map_get ((ValaMap*) _tmp1_, _tmp2_);
	data = (ValadocModuleLoaderModuleData*) _tmp3_;
	_tmp4_ = data;
	if (_tmp4_ == NULL) {
		void* function = NULL;
		GModule* module = NULL;
		const gchar* _tmp5_;
		gchar* _tmp6_;
		gchar* _tmp7_;
		GModule* _tmp8_;
		GModule* _tmp9_;
		GModule* _tmp10_;
		GModule* _tmp11_;
		void* _tmp12_ = NULL;
		void* _tmp13_;
		ValadocDocletRegisterFunction register_func = NULL;
		void* _tmp14_;
		ValadocModuleLoaderModuleData* _tmp15_;
		ValaHashMap* _tmp16_;
		const gchar* _tmp17_;
		ValadocModuleLoaderModuleData* _tmp18_;
		ValadocModuleLoaderModuleData* _tmp19_;
		ValadocDocletRegisterFunction _tmp20_;
		ValadocModuleLoaderModuleData* _tmp21_;
		GModule* _tmp22_;
		_tmp5_ = path;
		_tmp6_ = g_module_build_path (_tmp5_, "libdoclet");
		_tmp7_ = _tmp6_;
		_tmp8_ = g_module_open (_tmp7_, G_MODULE_BIND_LAZY | G_MODULE_BIND_LOCAL);
		_tmp9_ = _tmp8_;
		_g_free0 (_tmp7_);
		module = _tmp9_;
		_tmp10_ = module;
		if (_tmp10_ == NULL) {
			result = NULL;
			_g_module_close0 (module);
			_g_object_unref0 (data);
			_g_free0 (path);
			return result;
		}
		_tmp11_ = module;
		g_module_symbol (_tmp11_, "register_plugin", &_tmp12_);
		function = _tmp12_;
		_tmp13_ = function;
		if (_tmp13_ == NULL) {
			result = NULL;
			_g_module_close0 (module);
			_g_object_unref0 (data);
			_g_free0 (path);
			return result;
		}
		_tmp14_ = function;
		register_func = (ValadocDocletRegisterFunction) _tmp14_;
		_tmp15_ = valadoc_module_loader_module_data_new ();
		_g_object_unref0 (data);
		data = _tmp15_;
		_tmp16_ = self->priv->doclets;
		_tmp17_ = path;
		_tmp18_ = data;
		vala_map_set ((ValaMap*) _tmp16_, _tmp17_, _tmp18_);
		_tmp19_ = data;
		_tmp20_ = register_func;
		_tmp19_->type = _tmp20_ (self);
		_tmp21_ = data;
		_tmp22_ = module;
		module = NULL;
		_g_module_close0 (_tmp21_->module);
		_tmp21_->module = _tmp22_;
		_g_module_close0 (module);
	}
	_tmp23_ = data;
	_tmp24_ = g_object_new (_tmp23_->type, NULL);
	_tmp25_ = G_IS_INITIALLY_UNOWNED (_tmp24_) ? g_object_ref_sink (_tmp24_) : _tmp24_;
	result = G_TYPE_CHECK_INSTANCE_CAST (_tmp25_, VALADOC_TYPE_DOCLET, ValadocDoclet);
	_g_object_unref0 (data);
	_g_free0 (path);
	return result;
}

static ValadocModuleLoaderModuleData*
valadoc_module_loader_module_data_construct (GType object_type)
{
	ValadocModuleLoaderModuleData * self = NULL;
	self = (ValadocModuleLoaderModuleData*) g_object_new (object_type, NULL);
	return self;
}

static ValadocModuleLoaderModuleData*
valadoc_module_loader_module_data_new (void)
{
	return valadoc_module_loader_module_data_construct (VALADOC_MODULE_LOADER_TYPE_MODULE_DATA);
}

static void
valadoc_module_loader_module_data_class_init (ValadocModuleLoaderModuleDataClass * klass,
                                              gpointer klass_data)
{
	valadoc_module_loader_module_data_parent_class = g_type_class_peek_parent (klass);
	G_OBJECT_CLASS (klass)->finalize = valadoc_module_loader_module_data_finalize;
}

static void
valadoc_module_loader_module_data_instance_init (ValadocModuleLoaderModuleData * self,
                                                 gpointer klass)
{
}

static void
valadoc_module_loader_module_data_finalize (GObject * obj)
{
	ValadocModuleLoaderModuleData * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, VALADOC_MODULE_LOADER_TYPE_MODULE_DATA, ValadocModuleLoaderModuleData);
	_g_module_close0 (self->module);
	G_OBJECT_CLASS (valadoc_module_loader_module_data_parent_class)->finalize (obj);
}

static GType
valadoc_module_loader_module_data_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (ValadocModuleLoaderModuleDataClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) valadoc_module_loader_module_data_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (ValadocModuleLoaderModuleData), 0, (GInstanceInitFunc) valadoc_module_loader_module_data_instance_init, NULL };
	GType valadoc_module_loader_module_data_type_id;
	valadoc_module_loader_module_data_type_id = g_type_register_static (G_TYPE_OBJECT, "ValadocModuleLoaderModuleData", &g_define_type_info, 0);
	return valadoc_module_loader_module_data_type_id;
}

static GType
valadoc_module_loader_module_data_get_type (void)
{
	static volatile gsize valadoc_module_loader_module_data_type_id__once = 0;
	if (g_once_init_enter (&valadoc_module_loader_module_data_type_id__once)) {
		GType valadoc_module_loader_module_data_type_id;
		valadoc_module_loader_module_data_type_id = valadoc_module_loader_module_data_get_type_once ();
		g_once_init_leave (&valadoc_module_loader_module_data_type_id__once, valadoc_module_loader_module_data_type_id);
	}
	return valadoc_module_loader_module_data_type_id__once;
}

static void
valadoc_module_loader_class_init (ValadocModuleLoaderClass * klass,
                                  gpointer klass_data)
{
	valadoc_module_loader_parent_class = g_type_class_peek_parent (klass);
	g_type_class_adjust_private_offset (klass, &ValadocModuleLoader_private_offset);
	G_OBJECT_CLASS (klass)->finalize = valadoc_module_loader_finalize;
}

static void
valadoc_module_loader_instance_init (ValadocModuleLoader * self,
                                     gpointer klass)
{
	GHashFunc _tmp0_;
	GEqualFunc _tmp1_;
	GEqualFunc _tmp2_;
	ValaHashMap* _tmp3_;
	GHashFunc _tmp4_;
	GEqualFunc _tmp5_;
	GEqualFunc _tmp6_;
	ValaHashMap* _tmp7_;
	self->priv = valadoc_module_loader_get_instance_private (self);
	_tmp0_ = g_str_hash;
	_tmp1_ = g_str_equal;
	_tmp2_ = g_direct_equal;
	_tmp3_ = vala_hash_map_new (G_TYPE_STRING, (GBoxedCopyFunc) g_strdup, (GDestroyNotify) g_free, VALADOC_MODULE_LOADER_TYPE_MODULE_DATA, (GBoxedCopyFunc) g_object_ref, (GDestroyNotify) g_object_unref, _tmp0_, _tmp1_, _tmp2_);
	self->priv->doclets = _tmp3_;
	_tmp4_ = g_str_hash;
	_tmp5_ = g_str_equal;
	_tmp6_ = g_direct_equal;
	_tmp7_ = vala_hash_map_new (G_TYPE_STRING, (GBoxedCopyFunc) g_strdup, (GDestroyNotify) g_free, G_TYPE_GTYPE, NULL, NULL, _tmp4_, _tmp5_, _tmp6_);
	self->priv->taglets = _tmp7_;
}

static void
valadoc_module_loader_finalize (GObject * obj)
{
	ValadocModuleLoader * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, VALADOC_TYPE_MODULE_LOADER, ValadocModuleLoader);
	_vala_map_unref0 (self->priv->doclets);
	_vala_map_unref0 (self->priv->taglets);
	G_OBJECT_CLASS (valadoc_module_loader_parent_class)->finalize (obj);
}

static GType
valadoc_module_loader_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (ValadocModuleLoaderClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) valadoc_module_loader_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (ValadocModuleLoader), 0, (GInstanceInitFunc) valadoc_module_loader_instance_init, NULL };
	GType valadoc_module_loader_type_id;
	valadoc_module_loader_type_id = g_type_register_static (G_TYPE_OBJECT, "ValadocModuleLoader", &g_define_type_info, 0);
	ValadocModuleLoader_private_offset = g_type_add_instance_private (valadoc_module_loader_type_id, sizeof (ValadocModuleLoaderPrivate));
	return valadoc_module_loader_type_id;
}

GType
valadoc_module_loader_get_type (void)
{
	static volatile gsize valadoc_module_loader_type_id__once = 0;
	if (g_once_init_enter (&valadoc_module_loader_type_id__once)) {
		GType valadoc_module_loader_type_id;
		valadoc_module_loader_type_id = valadoc_module_loader_get_type_once ();
		g_once_init_leave (&valadoc_module_loader_type_id__once, valadoc_module_loader_type_id);
	}
	return valadoc_module_loader_type_id__once;
}

