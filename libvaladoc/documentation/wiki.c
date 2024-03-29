/* wiki.c generated by valac, the Vala compiler
 * generated from wiki.vala, do not modify */

/* wiki.vala
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
 * 	Florian Brosch <flo.brosch@gmail.com>
 */

#include "valadoc.h"
#include <stdlib.h>
#include <string.h>
#include <glib.h>
#include <glib-object.h>
#include <glib/gstdio.h>
#include <valagee.h>

enum  {
	VALADOC_WIKI_PAGE_0_PROPERTY,
	VALADOC_WIKI_PAGE_DOCUMENTATION_PROPERTY,
	VALADOC_WIKI_PAGE_DOCUMENTATION_STR_PROPERTY,
	VALADOC_WIKI_PAGE_PATH_PROPERTY,
	VALADOC_WIKI_PAGE_NAME_PROPERTY,
	VALADOC_WIKI_PAGE_PACKAGE_PROPERTY,
	VALADOC_WIKI_PAGE_NUM_PROPERTIES
};
static GParamSpec* valadoc_wiki_page_properties[VALADOC_WIKI_PAGE_NUM_PROPERTIES];
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))
enum  {
	VALADOC_WIKI_PAGE_TREE_0_PROPERTY,
	VALADOC_WIKI_PAGE_TREE_NUM_PROPERTIES
};
static GParamSpec* valadoc_wiki_page_tree_properties[VALADOC_WIKI_PAGE_TREE_NUM_PROPERTIES];
#define _vala_iterable_unref0(var) ((var == NULL) ? NULL : (var = (vala_iterable_unref (var), NULL)))
#define _g_dir_close0(var) ((var == NULL) ? NULL : (var = (g_dir_close (var), NULL)))

struct _ValadocWikiPagePrivate {
	ValadocContentPage* _documentation;
	gchar* _documentation_str;
	gchar* _path;
	gchar* _name;
	ValadocApiPackage* _package;
};

struct _ValadocWikiPageTreePrivate {
	ValaArrayList* wikipages;
};

static gint ValadocWikiPage_private_offset;
static gpointer valadoc_wiki_page_parent_class = NULL;
static ValadocDocumentationIface * valadoc_wiki_page_valadoc_documentation_parent_iface = NULL;
static gint ValadocWikiPageTree_private_offset;
static gpointer valadoc_wiki_page_tree_parent_class = NULL;

static void valadoc_wiki_page_set_documentation_str (ValadocWikiPage* self,
                                              const gchar* value);
static void valadoc_wiki_page_set_path (ValadocWikiPage* self,
                                 const gchar* value);
static void valadoc_wiki_page_set_name (ValadocWikiPage* self,
                                 const gchar* value);
static gchar* valadoc_wiki_page_real_get_filename (ValadocDocumentation* base);
static void valadoc_wiki_page_finalize (GObject * obj);
static GType valadoc_wiki_page_get_type_once (void);
static void _vala_valadoc_wiki_page_get_property (GObject * object,
                                           guint property_id,
                                           GValue * value,
                                           GParamSpec * pspec);
static void _vala_valadoc_wiki_page_set_property (GObject * object,
                                           guint property_id,
                                           const GValue * value,
                                           GParamSpec * pspec);
static void valadoc_wiki_page_tree_create_tree_from_path (ValadocWikiPageTree* self,
                                                   ValadocDocumentationParser* docparser,
                                                   ValadocApiPackage* package,
                                                   ValadocErrorReporter* reporter,
                                                   const gchar* path,
                                                   const gchar* nameoffset);
static void valadoc_wiki_page_tree_finalize (GObject * obj);
static GType valadoc_wiki_page_tree_get_type_once (void);

static inline gpointer
valadoc_wiki_page_get_instance_private (ValadocWikiPage* self)
{
	return G_STRUCT_MEMBER_P (self, ValadocWikiPage_private_offset);
}

ValadocContentPage*
valadoc_wiki_page_get_documentation (ValadocWikiPage* self)
{
	ValadocContentPage* result;
	ValadocContentPage* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_documentation;
	result = _tmp0_;
	return result;
}

static gpointer
_g_object_ref0 (gpointer self)
{
	return self ? g_object_ref (self) : NULL;
}

void
valadoc_wiki_page_set_documentation (ValadocWikiPage* self,
                                     ValadocContentPage* value)
{
	ValadocContentPage* old_value;
	g_return_if_fail (self != NULL);
	old_value = valadoc_wiki_page_get_documentation (self);
	if (old_value != value) {
		ValadocContentPage* _tmp0_;
		_tmp0_ = _g_object_ref0 (value);
		_g_object_unref0 (self->priv->_documentation);
		self->priv->_documentation = _tmp0_;
		g_object_notify_by_pspec ((GObject *) self, valadoc_wiki_page_properties[VALADOC_WIKI_PAGE_DOCUMENTATION_PROPERTY]);
	}
}

const gchar*
valadoc_wiki_page_get_documentation_str (ValadocWikiPage* self)
{
	const gchar* result;
	const gchar* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_documentation_str;
	result = _tmp0_;
	return result;
}

static void
valadoc_wiki_page_set_documentation_str (ValadocWikiPage* self,
                                         const gchar* value)
{
	gchar* old_value;
	g_return_if_fail (self != NULL);
	old_value = valadoc_wiki_page_get_documentation_str (self);
	if (g_strcmp0 (value, old_value) != 0) {
		gchar* _tmp0_;
		_tmp0_ = g_strdup (value);
		_g_free0 (self->priv->_documentation_str);
		self->priv->_documentation_str = _tmp0_;
		g_object_notify_by_pspec ((GObject *) self, valadoc_wiki_page_properties[VALADOC_WIKI_PAGE_DOCUMENTATION_STR_PROPERTY]);
	}
}

const gchar*
valadoc_wiki_page_get_path (ValadocWikiPage* self)
{
	const gchar* result;
	const gchar* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_path;
	result = _tmp0_;
	return result;
}

static void
valadoc_wiki_page_set_path (ValadocWikiPage* self,
                            const gchar* value)
{
	gchar* old_value;
	g_return_if_fail (self != NULL);
	old_value = valadoc_wiki_page_get_path (self);
	if (g_strcmp0 (value, old_value) != 0) {
		gchar* _tmp0_;
		_tmp0_ = g_strdup (value);
		_g_free0 (self->priv->_path);
		self->priv->_path = _tmp0_;
		g_object_notify_by_pspec ((GObject *) self, valadoc_wiki_page_properties[VALADOC_WIKI_PAGE_PATH_PROPERTY]);
	}
}

const gchar*
valadoc_wiki_page_get_name (ValadocWikiPage* self)
{
	const gchar* result;
	const gchar* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_name;
	result = _tmp0_;
	return result;
}

static void
valadoc_wiki_page_set_name (ValadocWikiPage* self,
                            const gchar* value)
{
	gchar* old_value;
	g_return_if_fail (self != NULL);
	old_value = valadoc_wiki_page_get_name (self);
	if (g_strcmp0 (value, old_value) != 0) {
		gchar* _tmp0_;
		_tmp0_ = g_strdup (value);
		_g_free0 (self->priv->_name);
		self->priv->_name = _tmp0_;
		g_object_notify_by_pspec ((GObject *) self, valadoc_wiki_page_properties[VALADOC_WIKI_PAGE_NAME_PROPERTY]);
	}
}

static ValadocApiPackage*
valadoc_wiki_page_real_get_package (ValadocDocumentation* base)
{
	ValadocApiPackage* result;
	ValadocWikiPage* self;
	ValadocApiPackage* _tmp0_;
	self = (ValadocWikiPage*) base;
	_tmp0_ = self->priv->_package;
	result = _tmp0_;
	return result;
}

/**
 * The corresponding file name
 */
static gchar*
valadoc_wiki_page_real_get_filename (ValadocDocumentation* base)
{
	ValadocWikiPage * self;
	const gchar* _tmp0_;
	gchar* _tmp1_;
	gchar* result;
	self = (ValadocWikiPage*) base;
	_tmp0_ = self->priv->_path;
	_tmp1_ = g_path_get_basename (_tmp0_);
	result = _tmp1_;
	return result;
}

ValadocWikiPage*
valadoc_wiki_page_construct (GType object_type,
                             const gchar* name,
                             const gchar* path,
                             ValadocApiPackage* package)
{
	ValadocWikiPage * self = NULL;
	ValadocApiPackage* _tmp0_;
	g_return_val_if_fail (name != NULL, NULL);
	g_return_val_if_fail (path != NULL, NULL);
	g_return_val_if_fail (package != NULL, NULL);
	self = (ValadocWikiPage*) g_object_new (object_type, NULL);
	_tmp0_ = _g_object_ref0 (package);
	_g_object_unref0 (self->priv->_package);
	self->priv->_package = _tmp0_;
	valadoc_wiki_page_set_name (self, name);
	valadoc_wiki_page_set_path (self, path);
	return self;
}

ValadocWikiPage*
valadoc_wiki_page_new (const gchar* name,
                       const gchar* path,
                       ValadocApiPackage* package)
{
	return valadoc_wiki_page_construct (VALADOC_TYPE_WIKI_PAGE, name, path, package);
}

void
valadoc_wiki_page_read (ValadocWikiPage* self,
                        ValadocErrorReporter* reporter)
{
	GError* _inner_error0_ = NULL;
	g_return_if_fail (self != NULL);
	g_return_if_fail (reporter != NULL);
	{
		gchar* content = NULL;
		const gchar* _tmp0_;
		gchar* _tmp1_ = NULL;
		_tmp0_ = self->priv->_path;
		g_file_get_contents (_tmp0_, &_tmp1_, NULL, &_inner_error0_);
		_g_free0 (content);
		content = _tmp1_;
		if (G_UNLIKELY (_inner_error0_ != NULL)) {
			_g_free0 (content);
			if (_inner_error0_->domain == G_FILE_ERROR) {
				goto __catch0_g_file_error;
			}
			g_critical ("file %s: line %d: unexpected error: %s (%s, %d)", __FILE__, __LINE__, _inner_error0_->message, g_quark_to_string (_inner_error0_->domain), _inner_error0_->code);
			g_clear_error (&_inner_error0_);
			return;
		}
		valadoc_wiki_page_set_documentation_str (self, content);
		_g_free0 (content);
	}
	goto __finally0;
	__catch0_g_file_error:
	{
		GError* err = NULL;
		const gchar* _tmp2_;
		GError* _tmp3_;
		const gchar* _tmp4_;
		err = _inner_error0_;
		_inner_error0_ = NULL;
		_tmp2_ = self->priv->_path;
		_tmp3_ = err;
		_tmp4_ = _tmp3_->message;
		valadoc_error_reporter_simple_error (reporter, NULL, "Unable to read file '%s': %s", _tmp2_, _tmp4_);
		_g_error_free0 (err);
	}
	__finally0:
	if (G_UNLIKELY (_inner_error0_ != NULL)) {
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error0_->message, g_quark_to_string (_inner_error0_->domain), _inner_error0_->code);
		g_clear_error (&_inner_error0_);
		return;
	}
}

void
valadoc_wiki_page_parse (ValadocWikiPage* self,
                         ValadocDocumentationParser* docparser,
                         ValadocApiPackage* pkg)
{
	ValadocContentPage* _tmp0_;
	ValadocContentPage* _tmp1_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (docparser != NULL);
	g_return_if_fail (pkg != NULL);
	_tmp0_ = valadoc_documentation_parser_parse_wikipage (docparser, pkg, self);
	_tmp1_ = _tmp0_;
	valadoc_wiki_page_set_documentation (self, _tmp1_);
	_g_object_unref0 (_tmp1_);
}

static void
valadoc_wiki_page_class_init (ValadocWikiPageClass * klass,
                              gpointer klass_data)
{
	valadoc_wiki_page_parent_class = g_type_class_peek_parent (klass);
	g_type_class_adjust_private_offset (klass, &ValadocWikiPage_private_offset);
	G_OBJECT_CLASS (klass)->get_property = _vala_valadoc_wiki_page_get_property;
	G_OBJECT_CLASS (klass)->set_property = _vala_valadoc_wiki_page_set_property;
	G_OBJECT_CLASS (klass)->finalize = valadoc_wiki_page_finalize;
	g_object_class_install_property (G_OBJECT_CLASS (klass), VALADOC_WIKI_PAGE_DOCUMENTATION_PROPERTY, valadoc_wiki_page_properties[VALADOC_WIKI_PAGE_DOCUMENTATION_PROPERTY] = g_param_spec_object ("documentation", "documentation", "documentation", VALADOC_CONTENT_TYPE_PAGE, G_PARAM_STATIC_STRINGS | G_PARAM_READABLE | G_PARAM_WRITABLE));
	g_object_class_install_property (G_OBJECT_CLASS (klass), VALADOC_WIKI_PAGE_DOCUMENTATION_STR_PROPERTY, valadoc_wiki_page_properties[VALADOC_WIKI_PAGE_DOCUMENTATION_STR_PROPERTY] = g_param_spec_string ("documentation-str", "documentation-str", "documentation-str", NULL, G_PARAM_STATIC_STRINGS | G_PARAM_READABLE));
	g_object_class_install_property (G_OBJECT_CLASS (klass), VALADOC_WIKI_PAGE_PATH_PROPERTY, valadoc_wiki_page_properties[VALADOC_WIKI_PAGE_PATH_PROPERTY] = g_param_spec_string ("path", "path", "path", NULL, G_PARAM_STATIC_STRINGS | G_PARAM_READABLE));
	g_object_class_install_property (G_OBJECT_CLASS (klass), VALADOC_WIKI_PAGE_NAME_PROPERTY, valadoc_wiki_page_properties[VALADOC_WIKI_PAGE_NAME_PROPERTY] = g_param_spec_string ("name", "name", "name", NULL, G_PARAM_STATIC_STRINGS | G_PARAM_READABLE));
	g_object_class_install_property (G_OBJECT_CLASS (klass), VALADOC_WIKI_PAGE_PACKAGE_PROPERTY, valadoc_wiki_page_properties[VALADOC_WIKI_PAGE_PACKAGE_PROPERTY] = g_param_spec_object ("package", "package", "package", VALADOC_API_TYPE_PACKAGE, G_PARAM_STATIC_STRINGS | G_PARAM_READABLE));
}

static void
valadoc_wiki_page_valadoc_documentation_interface_init (ValadocDocumentationIface * iface,
                                                        gpointer iface_data)
{
	valadoc_wiki_page_valadoc_documentation_parent_iface = g_type_interface_peek_parent (iface);
	iface->get_filename = (gchar* (*) (ValadocDocumentation*)) valadoc_wiki_page_real_get_filename;
	iface->get_package = valadoc_wiki_page_real_get_package;
}

static void
valadoc_wiki_page_instance_init (ValadocWikiPage * self,
                                 gpointer klass)
{
	self->priv = valadoc_wiki_page_get_instance_private (self);
}

static void
valadoc_wiki_page_finalize (GObject * obj)
{
	ValadocWikiPage * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, VALADOC_TYPE_WIKI_PAGE, ValadocWikiPage);
	_g_object_unref0 (self->priv->_documentation);
	_g_free0 (self->priv->_documentation_str);
	_g_free0 (self->priv->_path);
	_g_free0 (self->priv->_name);
	_g_object_unref0 (self->priv->_package);
	G_OBJECT_CLASS (valadoc_wiki_page_parent_class)->finalize (obj);
}

static GType
valadoc_wiki_page_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (ValadocWikiPageClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) valadoc_wiki_page_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (ValadocWikiPage), 0, (GInstanceInitFunc) valadoc_wiki_page_instance_init, NULL };
	static const GInterfaceInfo valadoc_documentation_info = { (GInterfaceInitFunc) valadoc_wiki_page_valadoc_documentation_interface_init, (GInterfaceFinalizeFunc) NULL, NULL};
	GType valadoc_wiki_page_type_id;
	valadoc_wiki_page_type_id = g_type_register_static (G_TYPE_OBJECT, "ValadocWikiPage", &g_define_type_info, 0);
	g_type_add_interface_static (valadoc_wiki_page_type_id, VALADOC_TYPE_DOCUMENTATION, &valadoc_documentation_info);
	ValadocWikiPage_private_offset = g_type_add_instance_private (valadoc_wiki_page_type_id, sizeof (ValadocWikiPagePrivate));
	return valadoc_wiki_page_type_id;
}

GType
valadoc_wiki_page_get_type (void)
{
	static volatile gsize valadoc_wiki_page_type_id__once = 0;
	if (g_once_init_enter (&valadoc_wiki_page_type_id__once)) {
		GType valadoc_wiki_page_type_id;
		valadoc_wiki_page_type_id = valadoc_wiki_page_get_type_once ();
		g_once_init_leave (&valadoc_wiki_page_type_id__once, valadoc_wiki_page_type_id);
	}
	return valadoc_wiki_page_type_id__once;
}

static void
_vala_valadoc_wiki_page_get_property (GObject * object,
                                      guint property_id,
                                      GValue * value,
                                      GParamSpec * pspec)
{
	ValadocWikiPage * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (object, VALADOC_TYPE_WIKI_PAGE, ValadocWikiPage);
	switch (property_id) {
		case VALADOC_WIKI_PAGE_DOCUMENTATION_PROPERTY:
		g_value_set_object (value, valadoc_wiki_page_get_documentation (self));
		break;
		case VALADOC_WIKI_PAGE_DOCUMENTATION_STR_PROPERTY:
		g_value_set_string (value, valadoc_wiki_page_get_documentation_str (self));
		break;
		case VALADOC_WIKI_PAGE_PATH_PROPERTY:
		g_value_set_string (value, valadoc_wiki_page_get_path (self));
		break;
		case VALADOC_WIKI_PAGE_NAME_PROPERTY:
		g_value_set_string (value, valadoc_wiki_page_get_name (self));
		break;
		case VALADOC_WIKI_PAGE_PACKAGE_PROPERTY:
		g_value_set_object (value, valadoc_documentation_get_package ((ValadocDocumentation*) self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}

static void
_vala_valadoc_wiki_page_set_property (GObject * object,
                                      guint property_id,
                                      const GValue * value,
                                      GParamSpec * pspec)
{
	ValadocWikiPage * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (object, VALADOC_TYPE_WIKI_PAGE, ValadocWikiPage);
	switch (property_id) {
		case VALADOC_WIKI_PAGE_DOCUMENTATION_PROPERTY:
		valadoc_wiki_page_set_documentation (self, g_value_get_object (value));
		break;
		case VALADOC_WIKI_PAGE_DOCUMENTATION_STR_PROPERTY:
		valadoc_wiki_page_set_documentation_str (self, g_value_get_string (value));
		break;
		case VALADOC_WIKI_PAGE_PATH_PROPERTY:
		valadoc_wiki_page_set_path (self, g_value_get_string (value));
		break;
		case VALADOC_WIKI_PAGE_NAME_PROPERTY:
		valadoc_wiki_page_set_name (self, g_value_get_string (value));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}

static inline gpointer
valadoc_wiki_page_tree_get_instance_private (ValadocWikiPageTree* self)
{
	return G_STRUCT_MEMBER_P (self, ValadocWikiPageTree_private_offset);
}

ValadocWikiPageTree*
valadoc_wiki_page_tree_construct (GType object_type)
{
	ValadocWikiPageTree * self = NULL;
	self = (ValadocWikiPageTree*) g_object_new (object_type, NULL);
	return self;
}

ValadocWikiPageTree*
valadoc_wiki_page_tree_new (void)
{
	return valadoc_wiki_page_tree_construct (VALADOC_TYPE_WIKI_PAGE_TREE);
}

static gpointer
_vala_iterable_ref0 (gpointer self)
{
	return self ? vala_iterable_ref (self) : NULL;
}

ValaCollection*
valadoc_wiki_page_tree_get_pages (ValadocWikiPageTree* self)
{
	ValaArrayList* _tmp0_ = NULL;
	ValaArrayList* _tmp1_;
	ValaCollection* result;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp1_ = self->priv->wikipages;
	if (_tmp1_ == NULL) {
		GEqualFunc _tmp2_;
		ValaArrayList* _tmp3_;
		_tmp2_ = g_direct_equal;
		_tmp3_ = vala_array_list_new (VALADOC_TYPE_WIKI_PAGE, (GBoxedCopyFunc) g_object_ref, (GDestroyNotify) g_object_unref, _tmp2_);
		_vala_iterable_unref0 (_tmp0_);
		_tmp0_ = _tmp3_;
	} else {
		ValaArrayList* _tmp4_;
		ValaArrayList* _tmp5_;
		_tmp4_ = self->priv->wikipages;
		_tmp5_ = _vala_iterable_ref0 (_tmp4_);
		_vala_iterable_unref0 (_tmp0_);
		_tmp0_ = _tmp5_;
	}
	result = (ValaCollection*) _tmp0_;
	return result;
}

ValadocWikiPage*
valadoc_wiki_page_tree_search (ValadocWikiPageTree* self,
                               const gchar* name)
{
	ValaArrayList* _tmp0_;
	ValadocWikiPage* result;
	g_return_val_if_fail (self != NULL, NULL);
	g_return_val_if_fail (name != NULL, NULL);
	_tmp0_ = self->priv->wikipages;
	if (_tmp0_ == NULL) {
		result = NULL;
		return result;
	}
	{
		ValaArrayList* _page_list = NULL;
		ValaArrayList* _tmp1_;
		gint _page_size = 0;
		ValaArrayList* _tmp2_;
		gint _tmp3_;
		gint _tmp4_;
		gint _page_index = 0;
		_tmp1_ = self->priv->wikipages;
		_page_list = _tmp1_;
		_tmp2_ = _page_list;
		_tmp3_ = vala_collection_get_size ((ValaCollection*) _tmp2_);
		_tmp4_ = _tmp3_;
		_page_size = _tmp4_;
		_page_index = -1;
		while (TRUE) {
			gint _tmp5_;
			gint _tmp6_;
			ValadocWikiPage* page = NULL;
			ValaArrayList* _tmp7_;
			gpointer _tmp8_;
			ValadocWikiPage* _tmp9_;
			const gchar* _tmp10_;
			const gchar* _tmp11_;
			_page_index = _page_index + 1;
			_tmp5_ = _page_index;
			_tmp6_ = _page_size;
			if (!(_tmp5_ < _tmp6_)) {
				break;
			}
			_tmp7_ = _page_list;
			_tmp8_ = vala_list_get ((ValaList*) _tmp7_, _page_index);
			page = (ValadocWikiPage*) _tmp8_;
			_tmp9_ = page;
			_tmp10_ = valadoc_wiki_page_get_name (_tmp9_);
			_tmp11_ = _tmp10_;
			if (g_strcmp0 (_tmp11_, name) == 0) {
				result = page;
				return result;
			}
			_g_object_unref0 (page);
		}
	}
	result = NULL;
	return result;
}

static void
valadoc_wiki_page_tree_create_tree_from_path (ValadocWikiPageTree* self,
                                              ValadocDocumentationParser* docparser,
                                              ValadocApiPackage* package,
                                              ValadocErrorReporter* reporter,
                                              const gchar* path,
                                              const gchar* nameoffset)
{
	GError* _inner_error0_ = NULL;
	g_return_if_fail (self != NULL);
	g_return_if_fail (docparser != NULL);
	g_return_if_fail (package != NULL);
	g_return_if_fail (reporter != NULL);
	g_return_if_fail (path != NULL);
	{
		GDir* dir = NULL;
		GDir* _tmp0_;
		_tmp0_ = g_dir_open (path, (guint) 0, &_inner_error0_);
		dir = _tmp0_;
		if (G_UNLIKELY (_inner_error0_ != NULL)) {
			if (_inner_error0_->domain == G_FILE_ERROR) {
				goto __catch0_g_file_error;
			}
			g_critical ("file %s: line %d: unexpected error: %s (%s, %d)", __FILE__, __LINE__, _inner_error0_->message, g_quark_to_string (_inner_error0_->domain), _inner_error0_->code);
			g_clear_error (&_inner_error0_);
			return;
		}
		{
			gchar* curname = NULL;
			GDir* _tmp1_;
			const gchar* _tmp2_;
			gchar* _tmp3_;
			_tmp1_ = dir;
			_tmp2_ = g_dir_read_name (_tmp1_);
			_tmp3_ = g_strdup (_tmp2_);
			curname = _tmp3_;
			{
				gboolean _tmp4_ = FALSE;
				_tmp4_ = TRUE;
				while (TRUE) {
					const gchar* _tmp8_;
					gchar* filename = NULL;
					const gchar* _tmp9_;
					gchar* _tmp10_;
					gboolean _tmp11_ = FALSE;
					const gchar* _tmp12_;
					if (!_tmp4_) {
						GDir* _tmp5_;
						const gchar* _tmp6_;
						gchar* _tmp7_;
						_tmp5_ = dir;
						_tmp6_ = g_dir_read_name (_tmp5_);
						_tmp7_ = g_strdup (_tmp6_);
						_g_free0 (curname);
						curname = _tmp7_;
					}
					_tmp4_ = FALSE;
					_tmp8_ = curname;
					if (!(_tmp8_ != NULL)) {
						break;
					}
					_tmp9_ = curname;
					_tmp10_ = g_build_filename (path, _tmp9_, NULL);
					filename = _tmp10_;
					_tmp12_ = curname;
					if (g_str_has_suffix (_tmp12_, ".valadoc")) {
						const gchar* _tmp13_;
						_tmp13_ = filename;
						_tmp11_ = g_file_test (_tmp13_, G_FILE_TEST_IS_REGULAR);
					} else {
						_tmp11_ = FALSE;
					}
					if (_tmp11_) {
						gchar* _tmp14_ = NULL;
						ValadocWikiPage* wikipage = NULL;
						const gchar* _tmp19_;
						ValadocWikiPage* _tmp20_;
						ValaArrayList* _tmp21_;
						ValadocWikiPage* _tmp22_;
						ValadocWikiPage* _tmp23_;
						if (nameoffset != NULL) {
							const gchar* _tmp15_;
							gchar* _tmp16_;
							_tmp15_ = curname;
							_tmp16_ = g_build_filename (nameoffset, _tmp15_, NULL);
							_g_free0 (_tmp14_);
							_tmp14_ = _tmp16_;
						} else {
							const gchar* _tmp17_;
							gchar* _tmp18_;
							_tmp17_ = curname;
							_tmp18_ = g_strdup (_tmp17_);
							_g_free0 (_tmp14_);
							_tmp14_ = _tmp18_;
						}
						_tmp19_ = filename;
						_tmp20_ = valadoc_wiki_page_new (_tmp14_, _tmp19_, package);
						wikipage = _tmp20_;
						_tmp21_ = self->priv->wikipages;
						_tmp22_ = wikipage;
						vala_collection_add ((ValaCollection*) _tmp21_, _tmp22_);
						_tmp23_ = wikipage;
						valadoc_wiki_page_read (_tmp23_, reporter);
						_g_object_unref0 (wikipage);
						_g_free0 (_tmp14_);
					} else {
						const gchar* _tmp24_;
						_tmp24_ = filename;
						if (g_file_test (_tmp24_, G_FILE_TEST_IS_DIR)) {
							gchar* _tmp25_ = NULL;
							const gchar* _tmp30_;
							if (nameoffset != NULL) {
								const gchar* _tmp26_;
								gchar* _tmp27_;
								_tmp26_ = curname;
								_tmp27_ = g_build_filename (nameoffset, _tmp26_, NULL);
								_g_free0 (_tmp25_);
								_tmp25_ = _tmp27_;
							} else {
								const gchar* _tmp28_;
								gchar* _tmp29_;
								_tmp28_ = curname;
								_tmp29_ = g_strdup (_tmp28_);
								_g_free0 (_tmp25_);
								_tmp25_ = _tmp29_;
							}
							_tmp30_ = filename;
							valadoc_wiki_page_tree_create_tree_from_path (self, docparser, package, reporter, _tmp30_, _tmp25_);
							_g_free0 (_tmp25_);
						}
					}
					_g_free0 (filename);
				}
			}
			_g_free0 (curname);
		}
		_g_dir_close0 (dir);
	}
	goto __finally0;
	__catch0_g_file_error:
	{
		GError* err = NULL;
		GError* _tmp31_;
		const gchar* _tmp32_;
		err = _inner_error0_;
		_inner_error0_ = NULL;
		_tmp31_ = err;
		_tmp32_ = _tmp31_->message;
		valadoc_error_reporter_simple_error (reporter, NULL, "Unable to open directory '%s': %s", path, _tmp32_);
		_g_error_free0 (err);
	}
	__finally0:
	if (G_UNLIKELY (_inner_error0_ != NULL)) {
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error0_->message, g_quark_to_string (_inner_error0_->domain), _inner_error0_->code);
		g_clear_error (&_inner_error0_);
		return;
	}
}

void
valadoc_wiki_page_tree_parse (ValadocWikiPageTree* self,
                              ValadocSettings* settings,
                              ValadocDocumentationParser* docparser,
                              ValadocApiPackage* package,
                              ValadocErrorReporter* reporter)
{
	const gchar* path = NULL;
	const gchar* _tmp0_;
	const gchar* _tmp1_;
	GEqualFunc _tmp2_;
	ValaArrayList* _tmp3_;
	const gchar* _tmp4_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (settings != NULL);
	g_return_if_fail (docparser != NULL);
	g_return_if_fail (package != NULL);
	g_return_if_fail (reporter != NULL);
	_tmp0_ = settings->wiki_directory;
	path = _tmp0_;
	_tmp1_ = path;
	if (_tmp1_ == NULL) {
		return;
	}
	_tmp2_ = g_direct_equal;
	_tmp3_ = vala_array_list_new (VALADOC_TYPE_WIKI_PAGE, (GBoxedCopyFunc) g_object_ref, (GDestroyNotify) g_object_unref, _tmp2_);
	_vala_iterable_unref0 (self->priv->wikipages);
	self->priv->wikipages = _tmp3_;
	_tmp4_ = path;
	valadoc_wiki_page_tree_create_tree_from_path (self, docparser, package, reporter, _tmp4_, NULL);
	{
		ValaArrayList* _page_list = NULL;
		ValaArrayList* _tmp5_;
		gint _page_size = 0;
		ValaArrayList* _tmp6_;
		gint _tmp7_;
		gint _tmp8_;
		gint _page_index = 0;
		_tmp5_ = self->priv->wikipages;
		_page_list = _tmp5_;
		_tmp6_ = _page_list;
		_tmp7_ = vala_collection_get_size ((ValaCollection*) _tmp6_);
		_tmp8_ = _tmp7_;
		_page_size = _tmp8_;
		_page_index = -1;
		while (TRUE) {
			gint _tmp9_;
			gint _tmp10_;
			ValadocWikiPage* page = NULL;
			ValaArrayList* _tmp11_;
			gpointer _tmp12_;
			ValadocWikiPage* _tmp13_;
			_page_index = _page_index + 1;
			_tmp9_ = _page_index;
			_tmp10_ = _page_size;
			if (!(_tmp9_ < _tmp10_)) {
				break;
			}
			_tmp11_ = _page_list;
			_tmp12_ = vala_list_get ((ValaList*) _tmp11_, _page_index);
			page = (ValadocWikiPage*) _tmp12_;
			_tmp13_ = page;
			valadoc_wiki_page_parse (_tmp13_, docparser, package);
			_g_object_unref0 (page);
		}
	}
}

void
valadoc_wiki_page_tree_check (ValadocWikiPageTree* self,
                              ValadocSettings* settings,
                              ValadocDocumentationParser* docparser,
                              ValadocApiPackage* pkg)
{
	ValaArrayList* _tmp0_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (settings != NULL);
	g_return_if_fail (docparser != NULL);
	g_return_if_fail (pkg != NULL);
	_tmp0_ = self->priv->wikipages;
	if (_tmp0_ == NULL) {
		return;
	}
	{
		ValaArrayList* _page_list = NULL;
		ValaArrayList* _tmp1_;
		gint _page_size = 0;
		ValaArrayList* _tmp2_;
		gint _tmp3_;
		gint _tmp4_;
		gint _page_index = 0;
		_tmp1_ = self->priv->wikipages;
		_page_list = _tmp1_;
		_tmp2_ = _page_list;
		_tmp3_ = vala_collection_get_size ((ValaCollection*) _tmp2_);
		_tmp4_ = _tmp3_;
		_page_size = _tmp4_;
		_page_index = -1;
		while (TRUE) {
			gint _tmp5_;
			gint _tmp6_;
			ValadocWikiPage* page = NULL;
			ValaArrayList* _tmp7_;
			gpointer _tmp8_;
			ValadocWikiPage* _tmp9_;
			_page_index = _page_index + 1;
			_tmp5_ = _page_index;
			_tmp6_ = _page_size;
			if (!(_tmp5_ < _tmp6_)) {
				break;
			}
			_tmp7_ = _page_list;
			_tmp8_ = vala_list_get ((ValaList*) _tmp7_, _page_index);
			page = (ValadocWikiPage*) _tmp8_;
			_tmp9_ = page;
			valadoc_documentation_parser_check_wikipage (docparser, pkg, _tmp9_);
			_g_object_unref0 (page);
		}
	}
}

static void
valadoc_wiki_page_tree_class_init (ValadocWikiPageTreeClass * klass,
                                   gpointer klass_data)
{
	valadoc_wiki_page_tree_parent_class = g_type_class_peek_parent (klass);
	g_type_class_adjust_private_offset (klass, &ValadocWikiPageTree_private_offset);
	G_OBJECT_CLASS (klass)->finalize = valadoc_wiki_page_tree_finalize;
}

static void
valadoc_wiki_page_tree_instance_init (ValadocWikiPageTree * self,
                                      gpointer klass)
{
	self->priv = valadoc_wiki_page_tree_get_instance_private (self);
}

static void
valadoc_wiki_page_tree_finalize (GObject * obj)
{
	ValadocWikiPageTree * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, VALADOC_TYPE_WIKI_PAGE_TREE, ValadocWikiPageTree);
	_vala_iterable_unref0 (self->priv->wikipages);
	G_OBJECT_CLASS (valadoc_wiki_page_tree_parent_class)->finalize (obj);
}

static GType
valadoc_wiki_page_tree_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (ValadocWikiPageTreeClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) valadoc_wiki_page_tree_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (ValadocWikiPageTree), 0, (GInstanceInitFunc) valadoc_wiki_page_tree_instance_init, NULL };
	GType valadoc_wiki_page_tree_type_id;
	valadoc_wiki_page_tree_type_id = g_type_register_static (G_TYPE_OBJECT, "ValadocWikiPageTree", &g_define_type_info, 0);
	ValadocWikiPageTree_private_offset = g_type_add_instance_private (valadoc_wiki_page_tree_type_id, sizeof (ValadocWikiPageTreePrivate));
	return valadoc_wiki_page_tree_type_id;
}

GType
valadoc_wiki_page_tree_get_type (void)
{
	static volatile gsize valadoc_wiki_page_tree_type_id__once = 0;
	if (g_once_init_enter (&valadoc_wiki_page_tree_type_id__once)) {
		GType valadoc_wiki_page_tree_type_id;
		valadoc_wiki_page_tree_type_id = valadoc_wiki_page_tree_get_type_once ();
		g_once_init_leave (&valadoc_wiki_page_tree_type_id__once, valadoc_wiki_page_tree_type_id);
	}
	return valadoc_wiki_page_tree_type_id__once;
}

