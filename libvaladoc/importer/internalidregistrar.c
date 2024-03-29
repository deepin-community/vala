/* internalidregistrar.c generated by valac, the Vala compiler
 * generated from internalidregistrar.vala, do not modify */

/* gtkdocindexsgmlreader.vala
 *
 * Copyright (C) 2014  Florian Brosch
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
 *  Florian Brosch <flo.brosch@gmail.com>
 */

#include "valadoc.h"
#include <valagee.h>
#include <glib-object.h>
#include <stdlib.h>
#include <string.h>
#include <glib.h>
#include <vala.h>
#include <gobject/gvaluecollector.h>

#define _vala_map_unref0(var) ((var == NULL) ? NULL : (var = (vala_map_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))
#define _vala_markup_reader_unref0(var) ((var == NULL) ? NULL : (var = (vala_markup_reader_unref (var), NULL)))
typedef struct _ValadocImporterParamSpecInternalIdRegistrar ValadocImporterParamSpecInternalIdRegistrar;

struct _ValadocImporterInternalIdRegistrarPrivate {
	ValaHashMap* symbol_map;
	ValaHashMap* map;
};

struct _ValadocImporterParamSpecInternalIdRegistrar {
	GParamSpec parent_instance;
};

static gint ValadocImporterInternalIdRegistrar_private_offset;
static gpointer valadoc_importer_internal_id_registrar_parent_class = NULL;

static void valadoc_importer_internal_id_registrar_finalize (ValadocImporterInternalIdRegistrar * obj);
static GType valadoc_importer_internal_id_registrar_get_type_once (void);

static inline gpointer
valadoc_importer_internal_id_registrar_get_instance_private (ValadocImporterInternalIdRegistrar* self)
{
	return G_STRUCT_MEMBER_P (self, ValadocImporterInternalIdRegistrar_private_offset);
}

ValadocImporterInternalIdRegistrar*
valadoc_importer_internal_id_registrar_construct (GType object_type)
{
	ValadocImporterInternalIdRegistrar* self = NULL;
	GHashFunc _tmp0_;
	GEqualFunc _tmp1_;
	GEqualFunc _tmp2_;
	ValaHashMap* _tmp3_;
	GHashFunc _tmp4_;
	GEqualFunc _tmp5_;
	GEqualFunc _tmp6_;
	ValaHashMap* _tmp7_;
	self = (ValadocImporterInternalIdRegistrar*) g_type_create_instance (object_type);
	_tmp0_ = g_str_hash;
	_tmp1_ = g_str_equal;
	_tmp2_ = g_direct_equal;
	_tmp3_ = vala_hash_map_new (G_TYPE_STRING, (GBoxedCopyFunc) g_strdup, (GDestroyNotify) g_free, G_TYPE_STRING, (GBoxedCopyFunc) g_strdup, (GDestroyNotify) g_free, _tmp0_, _tmp1_, _tmp2_);
	_vala_map_unref0 (self->priv->map);
	self->priv->map = _tmp3_;
	_tmp4_ = g_str_hash;
	_tmp5_ = g_str_equal;
	_tmp6_ = g_direct_equal;
	_tmp7_ = vala_hash_map_new (G_TYPE_STRING, (GBoxedCopyFunc) g_strdup, (GDestroyNotify) g_free, VALADOC_API_TYPE_NODE, (GBoxedCopyFunc) g_object_ref, (GDestroyNotify) g_object_unref, _tmp4_, _tmp5_, _tmp6_);
	_vala_map_unref0 (self->priv->symbol_map);
	self->priv->symbol_map = _tmp7_;
	return self;
}

ValadocImporterInternalIdRegistrar*
valadoc_importer_internal_id_registrar_new (void)
{
	return valadoc_importer_internal_id_registrar_construct (VALADOC_IMPORTER_TYPE_INTERNAL_ID_REGISTRAR);
}

void
valadoc_importer_internal_id_registrar_register_symbol (ValadocImporterInternalIdRegistrar* self,
                                                        const gchar* id,
                                                        ValadocApiNode* symbol)
{
	ValaHashMap* _tmp0_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (id != NULL);
	g_return_if_fail (symbol != NULL);
	_tmp0_ = self->priv->symbol_map;
	vala_map_set ((ValaMap*) _tmp0_, id, symbol);
}

gchar*
valadoc_importer_internal_id_registrar_map_url_id (ValadocImporterInternalIdRegistrar* self,
                                                   const gchar* id)
{
	ValaHashMap* _tmp0_;
	gpointer _tmp1_;
	gchar* result;
	g_return_val_if_fail (self != NULL, NULL);
	g_return_val_if_fail (id != NULL, NULL);
	_tmp0_ = self->priv->map;
	_tmp1_ = vala_map_get ((ValaMap*) _tmp0_, id);
	result = (gchar*) _tmp1_;
	return result;
}

ValadocApiNode*
valadoc_importer_internal_id_registrar_map_symbol_id (ValadocImporterInternalIdRegistrar* self,
                                                      const gchar* id)
{
	ValaHashMap* _tmp0_;
	gpointer _tmp1_;
	ValadocApiNode* result;
	g_return_val_if_fail (self != NULL, NULL);
	g_return_val_if_fail (id != NULL, NULL);
	_tmp0_ = self->priv->symbol_map;
	_tmp1_ = vala_map_get ((ValaMap*) _tmp0_, id);
	result = (ValadocApiNode*) _tmp1_;
	return result;
}

void
valadoc_importer_internal_id_registrar_read_index_sgml_file (ValadocImporterInternalIdRegistrar* self,
                                                             const gchar* filename,
                                                             const gchar* index_sgml_online,
                                                             ValadocErrorReporter* reporter)
{
	ValaSourceLocation begin = {0};
	ValaSourceLocation end = {0};
	ValaMarkupTokenType token = 0;
	gchar* _tmp0_ = NULL;
	gchar* _tmp1_;
	gchar* base_path = NULL;
	gchar* _tmp3_;
	ValaMarkupReader* reader = NULL;
	ValaMarkupReader* _tmp4_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (filename != NULL);
	g_return_if_fail (reporter != NULL);
	_tmp1_ = g_strdup (index_sgml_online);
	_tmp0_ = _tmp1_;
	if (_tmp0_ == NULL) {
		gchar* _tmp2_;
		_tmp2_ = vala_code_context_realpath (filename);
		_g_free0 (_tmp0_);
		_tmp0_ = _tmp2_;
	}
	_tmp3_ = _tmp0_;
	_tmp0_ = NULL;
	base_path = _tmp3_;
	_tmp4_ = vala_markup_reader_new (filename);
	reader = _tmp4_;
	while (TRUE) {
		ValaMarkupReader* _tmp5_;
		ValaSourceLocation _tmp6_ = {0};
		ValaSourceLocation _tmp7_ = {0};
		ValaMarkupTokenType _tmp8_;
		gboolean _tmp9_ = FALSE;
		_tmp5_ = reader;
		_tmp8_ = vala_markup_reader_read_token (_tmp5_, &_tmp6_, &_tmp7_);
		begin = _tmp6_;
		end = _tmp7_;
		token = _tmp8_;
		if (!(token != VALA_MARKUP_TOKEN_TYPE_EOF)) {
			break;
		}
		if (token == VALA_MARKUP_TOKEN_TYPE_START_ELEMENT) {
			ValaMarkupReader* _tmp10_;
			const gchar* _tmp11_;
			const gchar* _tmp12_;
			_tmp10_ = reader;
			_tmp11_ = vala_markup_reader_get_name (_tmp10_);
			_tmp12_ = _tmp11_;
			_tmp9_ = g_strcmp0 (_tmp12_, "ONLINE") == 0;
		} else {
			_tmp9_ = FALSE;
		}
		if (_tmp9_) {
			if (index_sgml_online == NULL) {
				ValaMarkupReader* _tmp13_;
				gchar* _tmp14_;
				const gchar* _tmp15_;
				_tmp13_ = reader;
				_tmp14_ = vala_markup_reader_get_attribute (_tmp13_, "href");
				_g_free0 (base_path);
				base_path = _tmp14_;
				_tmp15_ = base_path;
				if (_tmp15_ == NULL) {
					vala_report_error (NULL, "missing attribute `href' in <ONLINE>");
				}
			}
		} else {
			gboolean _tmp16_ = FALSE;
			if (token == VALA_MARKUP_TOKEN_TYPE_START_ELEMENT) {
				ValaMarkupReader* _tmp17_;
				const gchar* _tmp18_;
				const gchar* _tmp19_;
				_tmp17_ = reader;
				_tmp18_ = vala_markup_reader_get_name (_tmp17_);
				_tmp19_ = _tmp18_;
				_tmp16_ = g_strcmp0 (_tmp19_, "ANCHOR") == 0;
			} else {
				_tmp16_ = FALSE;
			}
			if (_tmp16_) {
				gchar* id = NULL;
				ValaMarkupReader* _tmp20_;
				gchar* _tmp21_;
				const gchar* _tmp22_;
				gchar* href = NULL;
				ValaMarkupReader* _tmp23_;
				gchar* _tmp24_;
				const gchar* _tmp25_;
				ValaHashMap* _tmp28_;
				const gchar* _tmp29_;
				const gchar* _tmp30_;
				const gchar* _tmp31_;
				gchar* _tmp32_;
				gchar* _tmp33_;
				_tmp20_ = reader;
				_tmp21_ = vala_markup_reader_get_attribute (_tmp20_, "id");
				id = _tmp21_;
				_tmp22_ = id;
				if (_tmp22_ == NULL) {
					vala_report_error (NULL, "missing attribute `id' in <ANCHOR>");
				}
				_tmp23_ = reader;
				_tmp24_ = vala_markup_reader_get_attribute (_tmp23_, "href");
				href = _tmp24_;
				_tmp25_ = href;
				if (_tmp25_ == NULL) {
					vala_report_error (NULL, "missing attribute `href' in <ANCHOR>");
				} else {
					if (index_sgml_online != NULL) {
						const gchar* _tmp26_;
						gchar* _tmp27_;
						_tmp26_ = href;
						_tmp27_ = g_path_get_basename (_tmp26_);
						_g_free0 (href);
						href = _tmp27_;
					}
				}
				_tmp28_ = self->priv->map;
				_tmp29_ = id;
				_tmp30_ = base_path;
				_tmp31_ = href;
				_tmp32_ = g_build_path ("/", _tmp30_, _tmp31_, NULL);
				_tmp33_ = _tmp32_;
				vala_map_set ((ValaMap*) _tmp28_, _tmp29_, _tmp33_);
				_g_free0 (_tmp33_);
				_g_free0 (href);
				_g_free0 (id);
			} else {
				vala_report_error (NULL, "expected element of <ONLINE> or <ANCHOR>");
			}
		}
	}
	_vala_markup_reader_unref0 (reader);
	_g_free0 (base_path);
	_g_free0 (_tmp0_);
}

static void
valadoc_importer_value_internal_id_registrar_init (GValue* value)
{
	value->data[0].v_pointer = NULL;
}

static void
valadoc_importer_value_internal_id_registrar_free_value (GValue* value)
{
	if (value->data[0].v_pointer) {
		valadoc_importer_internal_id_registrar_unref (value->data[0].v_pointer);
	}
}

static void
valadoc_importer_value_internal_id_registrar_copy_value (const GValue* src_value,
                                                         GValue* dest_value)
{
	if (src_value->data[0].v_pointer) {
		dest_value->data[0].v_pointer = valadoc_importer_internal_id_registrar_ref (src_value->data[0].v_pointer);
	} else {
		dest_value->data[0].v_pointer = NULL;
	}
}

static gpointer
valadoc_importer_value_internal_id_registrar_peek_pointer (const GValue* value)
{
	return value->data[0].v_pointer;
}

static gchar*
valadoc_importer_value_internal_id_registrar_collect_value (GValue* value,
                                                            guint n_collect_values,
                                                            GTypeCValue* collect_values,
                                                            guint collect_flags)
{
	if (collect_values[0].v_pointer) {
		ValadocImporterInternalIdRegistrar * object;
		object = collect_values[0].v_pointer;
		if (object->parent_instance.g_class == NULL) {
			return g_strconcat ("invalid unclassed object pointer for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		} else if (!g_value_type_compatible (G_TYPE_FROM_INSTANCE (object), G_VALUE_TYPE (value))) {
			return g_strconcat ("invalid object type `", g_type_name (G_TYPE_FROM_INSTANCE (object)), "' for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		}
		value->data[0].v_pointer = valadoc_importer_internal_id_registrar_ref (object);
	} else {
		value->data[0].v_pointer = NULL;
	}
	return NULL;
}

static gchar*
valadoc_importer_value_internal_id_registrar_lcopy_value (const GValue* value,
                                                          guint n_collect_values,
                                                          GTypeCValue* collect_values,
                                                          guint collect_flags)
{
	ValadocImporterInternalIdRegistrar ** object_p;
	object_p = collect_values[0].v_pointer;
	if (!object_p) {
		return g_strdup_printf ("value location for `%s' passed as NULL", G_VALUE_TYPE_NAME (value));
	}
	if (!value->data[0].v_pointer) {
		*object_p = NULL;
	} else if (collect_flags & G_VALUE_NOCOPY_CONTENTS) {
		*object_p = value->data[0].v_pointer;
	} else {
		*object_p = valadoc_importer_internal_id_registrar_ref (value->data[0].v_pointer);
	}
	return NULL;
}

GParamSpec*
valadoc_importer_param_spec_internal_id_registrar (const gchar* name,
                                                   const gchar* nick,
                                                   const gchar* blurb,
                                                   GType object_type,
                                                   GParamFlags flags)
{
	ValadocImporterParamSpecInternalIdRegistrar* spec;
	g_return_val_if_fail (g_type_is_a (object_type, VALADOC_IMPORTER_TYPE_INTERNAL_ID_REGISTRAR), NULL);
	spec = g_param_spec_internal (G_TYPE_PARAM_OBJECT, name, nick, blurb, flags);
	G_PARAM_SPEC (spec)->value_type = object_type;
	return G_PARAM_SPEC (spec);
}

gpointer
valadoc_importer_value_get_internal_id_registrar (const GValue* value)
{
	g_return_val_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, VALADOC_IMPORTER_TYPE_INTERNAL_ID_REGISTRAR), NULL);
	return value->data[0].v_pointer;
}

void
valadoc_importer_value_set_internal_id_registrar (GValue* value,
                                                  gpointer v_object)
{
	ValadocImporterInternalIdRegistrar * old;
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, VALADOC_IMPORTER_TYPE_INTERNAL_ID_REGISTRAR));
	old = value->data[0].v_pointer;
	if (v_object) {
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, VALADOC_IMPORTER_TYPE_INTERNAL_ID_REGISTRAR));
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
		value->data[0].v_pointer = v_object;
		valadoc_importer_internal_id_registrar_ref (value->data[0].v_pointer);
	} else {
		value->data[0].v_pointer = NULL;
	}
	if (old) {
		valadoc_importer_internal_id_registrar_unref (old);
	}
}

void
valadoc_importer_value_take_internal_id_registrar (GValue* value,
                                                   gpointer v_object)
{
	ValadocImporterInternalIdRegistrar * old;
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, VALADOC_IMPORTER_TYPE_INTERNAL_ID_REGISTRAR));
	old = value->data[0].v_pointer;
	if (v_object) {
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, VALADOC_IMPORTER_TYPE_INTERNAL_ID_REGISTRAR));
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
		value->data[0].v_pointer = v_object;
	} else {
		value->data[0].v_pointer = NULL;
	}
	if (old) {
		valadoc_importer_internal_id_registrar_unref (old);
	}
}

static void
valadoc_importer_internal_id_registrar_class_init (ValadocImporterInternalIdRegistrarClass * klass,
                                                   gpointer klass_data)
{
	valadoc_importer_internal_id_registrar_parent_class = g_type_class_peek_parent (klass);
	((ValadocImporterInternalIdRegistrarClass *) klass)->finalize = valadoc_importer_internal_id_registrar_finalize;
	g_type_class_adjust_private_offset (klass, &ValadocImporterInternalIdRegistrar_private_offset);
}

static void
valadoc_importer_internal_id_registrar_instance_init (ValadocImporterInternalIdRegistrar * self,
                                                      gpointer klass)
{
	self->priv = valadoc_importer_internal_id_registrar_get_instance_private (self);
	self->ref_count = 1;
}

static void
valadoc_importer_internal_id_registrar_finalize (ValadocImporterInternalIdRegistrar * obj)
{
	ValadocImporterInternalIdRegistrar * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, VALADOC_IMPORTER_TYPE_INTERNAL_ID_REGISTRAR, ValadocImporterInternalIdRegistrar);
	g_signal_handlers_destroy (self);
	_vala_map_unref0 (self->priv->symbol_map);
	_vala_map_unref0 (self->priv->map);
}

static GType
valadoc_importer_internal_id_registrar_get_type_once (void)
{
	static const GTypeValueTable g_define_type_value_table = { valadoc_importer_value_internal_id_registrar_init, valadoc_importer_value_internal_id_registrar_free_value, valadoc_importer_value_internal_id_registrar_copy_value, valadoc_importer_value_internal_id_registrar_peek_pointer, "p", valadoc_importer_value_internal_id_registrar_collect_value, "p", valadoc_importer_value_internal_id_registrar_lcopy_value };
	static const GTypeInfo g_define_type_info = { sizeof (ValadocImporterInternalIdRegistrarClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) valadoc_importer_internal_id_registrar_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (ValadocImporterInternalIdRegistrar), 0, (GInstanceInitFunc) valadoc_importer_internal_id_registrar_instance_init, &g_define_type_value_table };
	static const GTypeFundamentalInfo g_define_type_fundamental_info = { (G_TYPE_FLAG_CLASSED | G_TYPE_FLAG_INSTANTIATABLE | G_TYPE_FLAG_DERIVABLE | G_TYPE_FLAG_DEEP_DERIVABLE) };
	GType valadoc_importer_internal_id_registrar_type_id;
	valadoc_importer_internal_id_registrar_type_id = g_type_register_fundamental (g_type_fundamental_next (), "ValadocImporterInternalIdRegistrar", &g_define_type_info, &g_define_type_fundamental_info, 0);
	ValadocImporterInternalIdRegistrar_private_offset = g_type_add_instance_private (valadoc_importer_internal_id_registrar_type_id, sizeof (ValadocImporterInternalIdRegistrarPrivate));
	return valadoc_importer_internal_id_registrar_type_id;
}

GType
valadoc_importer_internal_id_registrar_get_type (void)
{
	static volatile gsize valadoc_importer_internal_id_registrar_type_id__once = 0;
	if (g_once_init_enter (&valadoc_importer_internal_id_registrar_type_id__once)) {
		GType valadoc_importer_internal_id_registrar_type_id;
		valadoc_importer_internal_id_registrar_type_id = valadoc_importer_internal_id_registrar_get_type_once ();
		g_once_init_leave (&valadoc_importer_internal_id_registrar_type_id__once, valadoc_importer_internal_id_registrar_type_id);
	}
	return valadoc_importer_internal_id_registrar_type_id__once;
}

gpointer
valadoc_importer_internal_id_registrar_ref (gpointer instance)
{
	ValadocImporterInternalIdRegistrar * self;
	self = instance;
	g_atomic_int_inc (&self->ref_count);
	return instance;
}

void
valadoc_importer_internal_id_registrar_unref (gpointer instance)
{
	ValadocImporterInternalIdRegistrar * self;
	self = instance;
	if (g_atomic_int_dec_and_test (&self->ref_count)) {
		VALADOC_IMPORTER_INTERNAL_ID_REGISTRAR_GET_CLASS (self)->finalize (self);
		g_type_free_instance ((GTypeInstance *) self);
	}
}

