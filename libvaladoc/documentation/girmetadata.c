/* girmetadata.c generated by valac, the Vala compiler
 * generated from girmetadata.vala, do not modify */

/* girmetadata.vala
 *
 * Copyright (C) 2012-2014 Florian Brosch
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
#include <glib/gstdio.h>
#include <glib-object.h>

enum  {
	VALADOC_GIR_META_DATA_0_PROPERTY,
	VALADOC_GIR_META_DATA_IS_DOCBOOK_PROPERTY,
	VALADOC_GIR_META_DATA_INDEX_SGML_PROPERTY,
	VALADOC_GIR_META_DATA_INDEX_SGML_ONLINE_PROPERTY,
	VALADOC_GIR_META_DATA_NUM_PROPERTIES
};
static GParamSpec* valadoc_gir_meta_data_properties[VALADOC_GIR_META_DATA_NUM_PROPERTIES];
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_key_file_unref0(var) ((var == NULL) ? NULL : (var = (g_key_file_unref (var), NULL)))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))

struct _ValadocGirMetaDataPrivate {
	gchar* metadata_path;
	gchar* resource_dir;
	gboolean _is_docbook;
	gchar* _index_sgml;
	gchar* _index_sgml_online;
};

static gint ValadocGirMetaData_private_offset;
static gpointer valadoc_gir_meta_data_parent_class = NULL;

static void valadoc_gir_meta_data_set_is_docbook (ValadocGirMetaData* self,
                                           gboolean value);
static void valadoc_gir_meta_data_set_index_sgml (ValadocGirMetaData* self,
                                           const gchar* value);
static void valadoc_gir_meta_data_set_index_sgml_online (ValadocGirMetaData* self,
                                                  const gchar* value);
static gchar* valadoc_gir_meta_data_get_metadata_file_name (ValadocGirMetaData* self,
                                                     const gchar* gir_file_path);
static gchar* valadoc_gir_meta_data_get_metadata_path (ValadocGirMetaData* self,
                                                const gchar* gir_file_path,
                                                gchar** metadata_dirs,
                                                gint metadata_dirs_length1);
static void valadoc_gir_meta_data_load_general_metadata (ValadocGirMetaData* self,
                                                  GKeyFile* key_file,
                                                  ValadocErrorReporter* reporter,
                                                  GError** error);
static void valadoc_gir_meta_data_finalize (GObject * obj);
static GType valadoc_gir_meta_data_get_type_once (void);
static void _vala_valadoc_gir_meta_data_get_property (GObject * object,
                                               guint property_id,
                                               GValue * value,
                                               GParamSpec * pspec);
static void _vala_valadoc_gir_meta_data_set_property (GObject * object,
                                               guint property_id,
                                               const GValue * value,
                                               GParamSpec * pspec);
static void _vala_array_destroy (gpointer array,
                          gssize array_length,
                          GDestroyNotify destroy_func);
static void _vala_array_free (gpointer array,
                       gssize array_length,
                       GDestroyNotify destroy_func);

static inline gpointer
valadoc_gir_meta_data_get_instance_private (ValadocGirMetaData* self)
{
	return G_STRUCT_MEMBER_P (self, ValadocGirMetaData_private_offset);
}

gboolean
valadoc_gir_meta_data_get_is_docbook (ValadocGirMetaData* self)
{
	gboolean result;
	g_return_val_if_fail (self != NULL, FALSE);
	result = self->priv->_is_docbook;
	return result;
}

static void
valadoc_gir_meta_data_set_is_docbook (ValadocGirMetaData* self,
                                      gboolean value)
{
	gboolean old_value;
	g_return_if_fail (self != NULL);
	old_value = valadoc_gir_meta_data_get_is_docbook (self);
	if (old_value != value) {
		self->priv->_is_docbook = value;
		g_object_notify_by_pspec ((GObject *) self, valadoc_gir_meta_data_properties[VALADOC_GIR_META_DATA_IS_DOCBOOK_PROPERTY]);
	}
}

const gchar*
valadoc_gir_meta_data_get_index_sgml (ValadocGirMetaData* self)
{
	const gchar* result;
	const gchar* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_index_sgml;
	result = _tmp0_;
	return result;
}

static void
valadoc_gir_meta_data_set_index_sgml (ValadocGirMetaData* self,
                                      const gchar* value)
{
	gchar* old_value;
	g_return_if_fail (self != NULL);
	old_value = valadoc_gir_meta_data_get_index_sgml (self);
	if (g_strcmp0 (value, old_value) != 0) {
		gchar* _tmp0_;
		_tmp0_ = g_strdup (value);
		_g_free0 (self->priv->_index_sgml);
		self->priv->_index_sgml = _tmp0_;
		g_object_notify_by_pspec ((GObject *) self, valadoc_gir_meta_data_properties[VALADOC_GIR_META_DATA_INDEX_SGML_PROPERTY]);
	}
}

const gchar*
valadoc_gir_meta_data_get_index_sgml_online (ValadocGirMetaData* self)
{
	const gchar* result;
	const gchar* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_index_sgml_online;
	result = _tmp0_;
	return result;
}

static void
valadoc_gir_meta_data_set_index_sgml_online (ValadocGirMetaData* self,
                                             const gchar* value)
{
	gchar* old_value;
	g_return_if_fail (self != NULL);
	old_value = valadoc_gir_meta_data_get_index_sgml_online (self);
	if (g_strcmp0 (value, old_value) != 0) {
		gchar* _tmp0_;
		_tmp0_ = g_strdup (value);
		_g_free0 (self->priv->_index_sgml_online);
		self->priv->_index_sgml_online = _tmp0_;
		g_object_notify_by_pspec ((GObject *) self, valadoc_gir_meta_data_properties[VALADOC_GIR_META_DATA_INDEX_SGML_ONLINE_PROPERTY]);
	}
}

/**
 * Used to manipulate paths to resources inside gir-files
 */
gchar*
valadoc_gir_meta_data_get_resource_path (ValadocGirMetaData* self,
                                         const gchar* resource)
{
	gboolean _tmp0_ = FALSE;
	const gchar* _tmp1_;
	const gchar* _tmp4_;
	const gchar* _tmp7_;
	gchar* _tmp8_;
	gchar* _tmp9_;
	const gchar* _tmp10_;
	gchar* _tmp11_;
	gchar* _tmp12_;
	gchar* result;
	g_return_val_if_fail (self != NULL, NULL);
	g_return_val_if_fail (resource != NULL, NULL);
	_tmp1_ = self->priv->resource_dir;
	if (_tmp1_ == NULL) {
		_tmp0_ = TRUE;
	} else {
		const gchar* _tmp2_;
		_tmp2_ = self->priv->metadata_path;
		_tmp0_ = _tmp2_ == NULL;
	}
	if (_tmp0_) {
		gchar* _tmp3_;
		_tmp3_ = g_strdup (resource);
		result = _tmp3_;
		return result;
	}
	_tmp4_ = self->priv->resource_dir;
	if (g_path_is_absolute (_tmp4_)) {
		const gchar* _tmp5_;
		gchar* _tmp6_;
		_tmp5_ = self->priv->resource_dir;
		_tmp6_ = g_build_filename (_tmp5_, resource, NULL);
		result = _tmp6_;
		return result;
	}
	_tmp7_ = self->priv->metadata_path;
	_tmp8_ = g_path_get_dirname (_tmp7_);
	_tmp9_ = _tmp8_;
	_tmp10_ = self->priv->resource_dir;
	_tmp11_ = g_build_filename (_tmp9_, _tmp10_, resource, NULL);
	_tmp12_ = _tmp11_;
	_g_free0 (_tmp9_);
	result = _tmp12_;
	return result;
}

static gint
string_last_index_of (const gchar* self,
                      const gchar* needle,
                      gint start_index)
{
	gchar* _result_ = NULL;
	gchar* _tmp0_;
	gchar* _tmp1_;
	gint result;
	g_return_val_if_fail (self != NULL, 0);
	g_return_val_if_fail (needle != NULL, 0);
	_tmp0_ = g_strrstr (((gchar*) self) + start_index, (gchar*) needle);
	_result_ = _tmp0_;
	_tmp1_ = _result_;
	if (_tmp1_ != NULL) {
		gchar* _tmp2_;
		_tmp2_ = _result_;
		result = (gint) (_tmp2_ - ((gchar*) self));
		return result;
	} else {
		result = -1;
		return result;
	}
}

static glong
string_strnlen (gchar* str,
                glong maxlen)
{
	gchar* end = NULL;
	gchar* _tmp0_;
	gchar* _tmp1_;
	glong result;
	_tmp0_ = memchr (str, 0, (gsize) maxlen);
	end = _tmp0_;
	_tmp1_ = end;
	if (_tmp1_ == NULL) {
		result = maxlen;
		return result;
	} else {
		gchar* _tmp2_;
		_tmp2_ = end;
		result = (glong) (_tmp2_ - str);
		return result;
	}
}

static gchar*
string_substring (const gchar* self,
                  glong offset,
                  glong len)
{
	glong string_length = 0L;
	gboolean _tmp0_ = FALSE;
	gchar* _tmp3_;
	gchar* result;
	g_return_val_if_fail (self != NULL, NULL);
	if (offset >= ((glong) 0)) {
		_tmp0_ = len >= ((glong) 0);
	} else {
		_tmp0_ = FALSE;
	}
	if (_tmp0_) {
		string_length = string_strnlen ((gchar*) self, offset + len);
	} else {
		gint _tmp1_;
		gint _tmp2_;
		_tmp1_ = strlen (self);
		_tmp2_ = _tmp1_;
		string_length = (glong) _tmp2_;
	}
	if (offset < ((glong) 0)) {
		offset = string_length + offset;
		g_return_val_if_fail (offset >= ((glong) 0), NULL);
	} else {
		g_return_val_if_fail (offset <= string_length, NULL);
	}
	if (len < ((glong) 0)) {
		len = string_length - offset;
	}
	g_return_val_if_fail ((offset + len) <= string_length, NULL);
	_tmp3_ = g_strndup (((gchar*) self) + offset, (gsize) len);
	result = _tmp3_;
	return result;
}

static gchar*
valadoc_gir_meta_data_get_metadata_file_name (ValadocGirMetaData* self,
                                              const gchar* gir_file_path)
{
	gchar* metadata_file_name = NULL;
	gchar* _tmp0_;
	gint last_dot_pos = 0;
	const gchar* _tmp1_;
	const gchar* _tmp2_;
	gchar* _tmp3_;
	const gchar* _tmp4_;
	gchar* _tmp5_;
	gchar* result;
	g_return_val_if_fail (self != NULL, NULL);
	g_return_val_if_fail (gir_file_path != NULL, NULL);
	_tmp0_ = g_path_get_basename (gir_file_path);
	metadata_file_name = _tmp0_;
	_tmp1_ = metadata_file_name;
	last_dot_pos = string_last_index_of (_tmp1_, ".", 0);
	if (last_dot_pos < 0) {
		result = NULL;
		_g_free0 (metadata_file_name);
		return result;
	}
	_tmp2_ = metadata_file_name;
	_tmp3_ = string_substring (_tmp2_, (glong) 0, (glong) last_dot_pos);
	_g_free0 (metadata_file_name);
	metadata_file_name = _tmp3_;
	_tmp4_ = metadata_file_name;
	_tmp5_ = g_strconcat (_tmp4_, ".valadoc.metadata", NULL);
	result = _tmp5_;
	_g_free0 (metadata_file_name);
	return result;
}

static gchar*
valadoc_gir_meta_data_get_metadata_path (ValadocGirMetaData* self,
                                         const gchar* gir_file_path,
                                         gchar** metadata_dirs,
                                         gint metadata_dirs_length1)
{
	gchar* metadata_file_name = NULL;
	gchar* _tmp0_;
	const gchar* _tmp1_;
	gchar* metadata_path = NULL;
	gchar* _tmp2_;
	gchar* _tmp3_;
	const gchar* _tmp4_;
	gchar* _tmp5_;
	gchar* _tmp6_;
	const gchar* _tmp7_;
	gchar* result;
	g_return_val_if_fail (self != NULL, NULL);
	g_return_val_if_fail (gir_file_path != NULL, NULL);
	_tmp0_ = valadoc_gir_meta_data_get_metadata_file_name (self, gir_file_path);
	metadata_file_name = _tmp0_;
	_tmp1_ = metadata_file_name;
	if (_tmp1_ == NULL) {
		result = NULL;
		_g_free0 (metadata_file_name);
		return result;
	}
	_tmp2_ = g_path_get_dirname (gir_file_path);
	_tmp3_ = _tmp2_;
	_tmp4_ = metadata_file_name;
	_tmp5_ = g_build_filename (_tmp3_, _tmp4_, NULL);
	_tmp6_ = _tmp5_;
	_g_free0 (_tmp3_);
	metadata_path = _tmp6_;
	_tmp7_ = metadata_path;
	if (g_file_test (_tmp7_, G_FILE_TEST_IS_REGULAR)) {
		result = metadata_path;
		_g_free0 (metadata_file_name);
		return result;
	}
	{
		gchar** metadata_dir_collection = NULL;
		gint metadata_dir_collection_length1 = 0;
		gint _metadata_dir_collection_size_ = 0;
		gint metadata_dir_it = 0;
		metadata_dir_collection = metadata_dirs;
		metadata_dir_collection_length1 = metadata_dirs_length1;
		for (metadata_dir_it = 0; metadata_dir_it < metadata_dir_collection_length1; metadata_dir_it = metadata_dir_it + 1) {
			gchar* _tmp8_;
			gchar* metadata_dir = NULL;
			_tmp8_ = g_strdup (metadata_dir_collection[metadata_dir_it]);
			metadata_dir = _tmp8_;
			{
				const gchar* _tmp9_;
				const gchar* _tmp10_;
				gchar* _tmp11_;
				const gchar* _tmp12_;
				_tmp9_ = metadata_dir;
				_tmp10_ = metadata_file_name;
				_tmp11_ = g_build_filename (_tmp9_, _tmp10_, NULL);
				_g_free0 (metadata_path);
				metadata_path = _tmp11_;
				_tmp12_ = metadata_path;
				if (g_file_test (_tmp12_, G_FILE_TEST_IS_REGULAR)) {
					result = metadata_path;
					_g_free0 (metadata_dir);
					_g_free0 (metadata_file_name);
					return result;
				}
				_g_free0 (metadata_dir);
			}
		}
	}
	result = NULL;
	_g_free0 (metadata_path);
	_g_free0 (metadata_file_name);
	return result;
}

static void
valadoc_gir_meta_data_load_general_metadata (ValadocGirMetaData* self,
                                             GKeyFile* key_file,
                                             ValadocErrorReporter* reporter,
                                             GError** error)
{
	gchar** _tmp0_ = NULL;
	gsize _tmp1_ = 0;
	gchar** _tmp2_;
	gint _tmp0__length1;
	gint __tmp0__size_;
	GError* _inner_error0_ = NULL;
	g_return_if_fail (self != NULL);
	g_return_if_fail (key_file != NULL);
	g_return_if_fail (reporter != NULL);
	_tmp2_ = g_key_file_get_keys (key_file, "General", &_tmp1_, &_inner_error0_);
	_tmp0_ = _tmp2_;
	_tmp0__length1 = _tmp1_;
	__tmp0__size_ = _tmp0__length1;
	if (G_UNLIKELY (_inner_error0_ != NULL)) {
		if (_inner_error0_->domain == G_KEY_FILE_ERROR) {
			g_propagate_error (error, _inner_error0_);
			return;
		} else {
			g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error0_->message, g_quark_to_string (_inner_error0_->domain), _inner_error0_->code);
			g_clear_error (&_inner_error0_);
			return;
		}
	}
	{
		gchar** key_collection = NULL;
		gint key_collection_length1 = 0;
		gint _key_collection_size_ = 0;
		gint key_it = 0;
		key_collection = _tmp0_;
		key_collection_length1 = _tmp0__length1;
		for (key_it = 0; key_it < key_collection_length1; key_it = key_it + 1) {
			gchar* _tmp3_;
			gchar* key = NULL;
			_tmp3_ = g_strdup (key_collection[key_it]);
			key = _tmp3_;
			{
				const gchar* _tmp4_;
				const gchar* _tmp5_;
				GQuark _tmp7_ = 0U;
				static GQuark _tmp6_label0 = 0;
				static GQuark _tmp6_label1 = 0;
				static GQuark _tmp6_label2 = 0;
				static GQuark _tmp6_label3 = 0;
				_tmp4_ = key;
				_tmp5_ = _tmp4_;
				_tmp7_ = (NULL == _tmp5_) ? 0 : g_quark_from_string (_tmp5_);
				if (_tmp7_ == ((0 != _tmp6_label0) ? _tmp6_label0 : (_tmp6_label0 = g_quark_from_static_string ("resources")))) {
					switch (0) {
						default:
						{
							gchar* _tmp8_ = NULL;
							gchar* _tmp9_;
							gchar* _tmp10_;
							_tmp9_ = g_key_file_get_string (key_file, "General", "resources", &_inner_error0_);
							_tmp8_ = _tmp9_;
							if (G_UNLIKELY (_inner_error0_ != NULL)) {
								if (_inner_error0_->domain == G_KEY_FILE_ERROR) {
									g_propagate_error (error, _inner_error0_);
									_g_free0 (key);
									_tmp0_ = (_vala_array_free (_tmp0_, _tmp0__length1, (GDestroyNotify) g_free), NULL);
									return;
								} else {
									_g_free0 (key);
									_tmp0_ = (_vala_array_free (_tmp0_, _tmp0__length1, (GDestroyNotify) g_free), NULL);
									g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error0_->message, g_quark_to_string (_inner_error0_->domain), _inner_error0_->code);
									g_clear_error (&_inner_error0_);
									return;
								}
							}
							_tmp10_ = _tmp8_;
							_tmp8_ = NULL;
							_g_free0 (self->priv->resource_dir);
							self->priv->resource_dir = _tmp10_;
							_g_free0 (_tmp8_);
							break;
						}
					}
				} else if (_tmp7_ == ((0 != _tmp6_label1) ? _tmp6_label1 : (_tmp6_label1 = g_quark_from_static_string ("is_docbook")))) {
					switch (0) {
						default:
						{
							gboolean _tmp11_ = FALSE;
							_tmp11_ = g_key_file_get_boolean (key_file, "General", "is_docbook", &_inner_error0_);
							if (G_UNLIKELY (_inner_error0_ != NULL)) {
								if (_inner_error0_->domain == G_KEY_FILE_ERROR) {
									g_propagate_error (error, _inner_error0_);
									_g_free0 (key);
									_tmp0_ = (_vala_array_free (_tmp0_, _tmp0__length1, (GDestroyNotify) g_free), NULL);
									return;
								} else {
									_g_free0 (key);
									_tmp0_ = (_vala_array_free (_tmp0_, _tmp0__length1, (GDestroyNotify) g_free), NULL);
									g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error0_->message, g_quark_to_string (_inner_error0_->domain), _inner_error0_->code);
									g_clear_error (&_inner_error0_);
									return;
								}
							}
							valadoc_gir_meta_data_set_is_docbook (self, _tmp11_);
							break;
						}
					}
				} else if (_tmp7_ == ((0 != _tmp6_label2) ? _tmp6_label2 : (_tmp6_label2 = g_quark_from_static_string ("index_sgml")))) {
					switch (0) {
						default:
						{
							gchar* tmp = NULL;
							gchar* _tmp12_;
							const gchar* _tmp13_;
							gchar* _tmp14_;
							gchar* _tmp15_;
							const gchar* _tmp16_;
							gchar* _tmp17_;
							gchar* _tmp18_;
							_tmp12_ = g_key_file_get_string (key_file, "General", "index_sgml", &_inner_error0_);
							tmp = _tmp12_;
							if (G_UNLIKELY (_inner_error0_ != NULL)) {
								if (_inner_error0_->domain == G_KEY_FILE_ERROR) {
									g_propagate_error (error, _inner_error0_);
									_g_free0 (key);
									_tmp0_ = (_vala_array_free (_tmp0_, _tmp0__length1, (GDestroyNotify) g_free), NULL);
									return;
								} else {
									_g_free0 (key);
									_tmp0_ = (_vala_array_free (_tmp0_, _tmp0__length1, (GDestroyNotify) g_free), NULL);
									g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error0_->message, g_quark_to_string (_inner_error0_->domain), _inner_error0_->code);
									g_clear_error (&_inner_error0_);
									return;
								}
							}
							_tmp13_ = self->priv->metadata_path;
							_tmp14_ = g_path_get_dirname (_tmp13_);
							_tmp15_ = _tmp14_;
							_tmp16_ = tmp;
							_tmp17_ = g_build_filename (_tmp15_, _tmp16_, NULL);
							_tmp18_ = _tmp17_;
							valadoc_gir_meta_data_set_index_sgml (self, _tmp18_);
							_g_free0 (_tmp18_);
							_g_free0 (_tmp15_);
							_g_free0 (tmp);
							break;
						}
					}
				} else if (_tmp7_ == ((0 != _tmp6_label3) ? _tmp6_label3 : (_tmp6_label3 = g_quark_from_static_string ("index_sgml_online")))) {
					switch (0) {
						default:
						{
							gchar* _tmp19_ = NULL;
							gchar* _tmp20_;
							_tmp20_ = g_key_file_get_string (key_file, "General", "index_sgml_online", &_inner_error0_);
							_tmp19_ = _tmp20_;
							if (G_UNLIKELY (_inner_error0_ != NULL)) {
								if (_inner_error0_->domain == G_KEY_FILE_ERROR) {
									g_propagate_error (error, _inner_error0_);
									_g_free0 (key);
									_tmp0_ = (_vala_array_free (_tmp0_, _tmp0__length1, (GDestroyNotify) g_free), NULL);
									return;
								} else {
									_g_free0 (key);
									_tmp0_ = (_vala_array_free (_tmp0_, _tmp0__length1, (GDestroyNotify) g_free), NULL);
									g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error0_->message, g_quark_to_string (_inner_error0_->domain), _inner_error0_->code);
									g_clear_error (&_inner_error0_);
									return;
								}
							}
							valadoc_gir_meta_data_set_index_sgml_online (self, _tmp19_);
							_g_free0 (_tmp19_);
							break;
						}
					}
				} else {
					switch (0) {
						default:
						{
							const gchar* _tmp21_;
							const gchar* _tmp22_;
							_tmp21_ = self->priv->metadata_path;
							_tmp22_ = key;
							valadoc_error_reporter_simple_warning (reporter, _tmp21_, "Unknown key 'General.%s'", _tmp22_);
							break;
						}
					}
				}
				_g_free0 (key);
			}
		}
	}
	_tmp0_ = (_vala_array_free (_tmp0_, _tmp0__length1, (GDestroyNotify) g_free), NULL);
}

ValadocGirMetaData*
valadoc_gir_meta_data_construct (GType object_type,
                                 const gchar* gir_file_path,
                                 gchar** metadata_dirs,
                                 gint metadata_dirs_length1,
                                 ValadocErrorReporter* reporter)
{
	ValadocGirMetaData * self = NULL;
	gchar* _tmp0_;
	const gchar* _tmp1_;
	GKeyFile* key_file = NULL;
	GError* _inner_error0_ = NULL;
	g_return_val_if_fail (gir_file_path != NULL, NULL);
	g_return_val_if_fail (reporter != NULL, NULL);
	self = (ValadocGirMetaData*) g_object_new (object_type, NULL);
	if (!g_file_test (gir_file_path, G_FILE_TEST_IS_REGULAR)) {
		return self;
	}
	_tmp0_ = valadoc_gir_meta_data_get_metadata_path (self, gir_file_path, metadata_dirs, (gint) metadata_dirs_length1);
	_g_free0 (self->priv->metadata_path);
	self->priv->metadata_path = _tmp0_;
	_tmp1_ = self->priv->metadata_path;
	if (_tmp1_ == NULL) {
		return self;
	}
	{
		GKeyFile* _tmp2_;
		GKeyFile* _tmp3_;
		const gchar* _tmp4_;
		_tmp2_ = g_key_file_new ();
		_g_key_file_unref0 (key_file);
		key_file = _tmp2_;
		_tmp3_ = key_file;
		_tmp4_ = self->priv->metadata_path;
		g_key_file_load_from_file (_tmp3_, _tmp4_, G_KEY_FILE_NONE, &_inner_error0_);
		if (G_UNLIKELY (_inner_error0_ != NULL)) {
			if (_inner_error0_->domain == G_KEY_FILE_ERROR) {
				goto __catch0_g_key_file_error;
			}
			if (_inner_error0_->domain == G_FILE_ERROR) {
				goto __catch0_g_file_error;
			}
			_g_key_file_unref0 (key_file);
			g_critical ("file %s: line %d: unexpected error: %s (%s, %d)", __FILE__, __LINE__, _inner_error0_->message, g_quark_to_string (_inner_error0_->domain), _inner_error0_->code);
			g_clear_error (&_inner_error0_);
			return NULL;
		}
	}
	goto __finally0;
	__catch0_g_key_file_error:
	{
		GError* e = NULL;
		const gchar* _tmp5_;
		GError* _tmp6_;
		const gchar* _tmp7_;
		e = _inner_error0_;
		_inner_error0_ = NULL;
		_tmp5_ = self->priv->metadata_path;
		_tmp6_ = e;
		_tmp7_ = _tmp6_->message;
		valadoc_error_reporter_simple_error (reporter, _tmp5_, "%s", _tmp7_);
		_g_error_free0 (e);
		_g_key_file_unref0 (key_file);
		return self;
	}
	goto __finally0;
	__catch0_g_file_error:
	{
		GError* e = NULL;
		const gchar* _tmp8_;
		GError* _tmp9_;
		const gchar* _tmp10_;
		e = _inner_error0_;
		_inner_error0_ = NULL;
		_tmp8_ = self->priv->metadata_path;
		_tmp9_ = e;
		_tmp10_ = _tmp9_->message;
		valadoc_error_reporter_simple_error (reporter, _tmp8_, "%s", _tmp10_);
		_g_error_free0 (e);
		_g_key_file_unref0 (key_file);
		return self;
	}
	__finally0:
	if (G_UNLIKELY (_inner_error0_ != NULL)) {
		_g_key_file_unref0 (key_file);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error0_->message, g_quark_to_string (_inner_error0_->domain), _inner_error0_->code);
		g_clear_error (&_inner_error0_);
		return NULL;
	}
	{
		GKeyFile* _tmp11_;
		gsize _tmp12_ = 0;
		gchar** _tmp13_;
		_tmp11_ = key_file;
		_tmp13_ = g_key_file_get_groups (_tmp11_, &_tmp12_);
		{
			gchar** group_collection = NULL;
			gint group_collection_length1 = 0;
			gint _group_collection_size_ = 0;
			gint group_it = 0;
			group_collection = _tmp13_;
			group_collection_length1 = _tmp12_;
			for (group_it = 0; group_it < group_collection_length1; group_it = group_it + 1) {
				gchar* _tmp14_;
				gchar* group = NULL;
				_tmp14_ = g_strdup (group_collection[group_it]);
				group = _tmp14_;
				{
					const gchar* _tmp15_;
					const gchar* _tmp16_;
					GQuark _tmp18_ = 0U;
					static GQuark _tmp17_label0 = 0;
					_tmp15_ = group;
					_tmp16_ = _tmp15_;
					_tmp18_ = (NULL == _tmp16_) ? 0 : g_quark_from_string (_tmp16_);
					if (_tmp18_ == ((0 != _tmp17_label0) ? _tmp17_label0 : (_tmp17_label0 = g_quark_from_static_string ("General")))) {
						switch (0) {
							default:
							{
								GKeyFile* _tmp19_;
								_tmp19_ = key_file;
								valadoc_gir_meta_data_load_general_metadata (self, _tmp19_, reporter, &_inner_error0_);
								if (G_UNLIKELY (_inner_error0_ != NULL)) {
									_g_free0 (group);
									group_collection = (_vala_array_free (group_collection, group_collection_length1, (GDestroyNotify) g_free), NULL);
									if (_inner_error0_->domain == G_KEY_FILE_ERROR) {
										goto __catch1_g_key_file_error;
									}
									_g_key_file_unref0 (key_file);
									g_critical ("file %s: line %d: unexpected error: %s (%s, %d)", __FILE__, __LINE__, _inner_error0_->message, g_quark_to_string (_inner_error0_->domain), _inner_error0_->code);
									g_clear_error (&_inner_error0_);
									return NULL;
								}
								break;
							}
						}
					} else {
						switch (0) {
							default:
							{
								const gchar* _tmp20_;
								const gchar* _tmp21_;
								_tmp20_ = self->priv->metadata_path;
								_tmp21_ = group;
								valadoc_error_reporter_simple_warning (reporter, _tmp20_, "Unknown group '%s'", _tmp21_);
								break;
							}
						}
					}
					_g_free0 (group);
				}
			}
			group_collection = (_vala_array_free (group_collection, group_collection_length1, (GDestroyNotify) g_free), NULL);
		}
	}
	goto __finally1;
	__catch1_g_key_file_error:
	{
		GError* e = NULL;
		const gchar* _tmp22_;
		GError* _tmp23_;
		const gchar* _tmp24_;
		e = _inner_error0_;
		_inner_error0_ = NULL;
		_tmp22_ = self->priv->metadata_path;
		_tmp23_ = e;
		_tmp24_ = _tmp23_->message;
		valadoc_error_reporter_simple_error (reporter, NULL, "Unable to read file '%s': %s", _tmp22_, _tmp24_);
		_g_error_free0 (e);
	}
	__finally1:
	if (G_UNLIKELY (_inner_error0_ != NULL)) {
		_g_key_file_unref0 (key_file);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error0_->message, g_quark_to_string (_inner_error0_->domain), _inner_error0_->code);
		g_clear_error (&_inner_error0_);
		return NULL;
	}
	_g_key_file_unref0 (key_file);
	return self;
}

ValadocGirMetaData*
valadoc_gir_meta_data_new (const gchar* gir_file_path,
                           gchar** metadata_dirs,
                           gint metadata_dirs_length1,
                           ValadocErrorReporter* reporter)
{
	return valadoc_gir_meta_data_construct (VALADOC_TYPE_GIR_META_DATA, gir_file_path, metadata_dirs, metadata_dirs_length1, reporter);
}

static void
valadoc_gir_meta_data_class_init (ValadocGirMetaDataClass * klass,
                                  gpointer klass_data)
{
	valadoc_gir_meta_data_parent_class = g_type_class_peek_parent (klass);
	g_type_class_adjust_private_offset (klass, &ValadocGirMetaData_private_offset);
	G_OBJECT_CLASS (klass)->get_property = _vala_valadoc_gir_meta_data_get_property;
	G_OBJECT_CLASS (klass)->set_property = _vala_valadoc_gir_meta_data_set_property;
	G_OBJECT_CLASS (klass)->finalize = valadoc_gir_meta_data_finalize;
	g_object_class_install_property (G_OBJECT_CLASS (klass), VALADOC_GIR_META_DATA_IS_DOCBOOK_PROPERTY, valadoc_gir_meta_data_properties[VALADOC_GIR_META_DATA_IS_DOCBOOK_PROPERTY] = g_param_spec_boolean ("is-docbook", "is-docbook", "is-docbook", FALSE, G_PARAM_STATIC_STRINGS | G_PARAM_READABLE));
	g_object_class_install_property (G_OBJECT_CLASS (klass), VALADOC_GIR_META_DATA_INDEX_SGML_PROPERTY, valadoc_gir_meta_data_properties[VALADOC_GIR_META_DATA_INDEX_SGML_PROPERTY] = g_param_spec_string ("index-sgml", "index-sgml", "index-sgml", NULL, G_PARAM_STATIC_STRINGS | G_PARAM_READABLE));
	g_object_class_install_property (G_OBJECT_CLASS (klass), VALADOC_GIR_META_DATA_INDEX_SGML_ONLINE_PROPERTY, valadoc_gir_meta_data_properties[VALADOC_GIR_META_DATA_INDEX_SGML_ONLINE_PROPERTY] = g_param_spec_string ("index-sgml-online", "index-sgml-online", "index-sgml-online", NULL, G_PARAM_STATIC_STRINGS | G_PARAM_READABLE));
}

static void
valadoc_gir_meta_data_instance_init (ValadocGirMetaData * self,
                                     gpointer klass)
{
	self->priv = valadoc_gir_meta_data_get_instance_private (self);
	self->priv->metadata_path = NULL;
	self->priv->resource_dir = NULL;
	self->priv->_is_docbook = FALSE;
	self->priv->_index_sgml = NULL;
	self->priv->_index_sgml_online = NULL;
}

static void
valadoc_gir_meta_data_finalize (GObject * obj)
{
	ValadocGirMetaData * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, VALADOC_TYPE_GIR_META_DATA, ValadocGirMetaData);
	_g_free0 (self->priv->metadata_path);
	_g_free0 (self->priv->resource_dir);
	_g_free0 (self->priv->_index_sgml);
	_g_free0 (self->priv->_index_sgml_online);
	G_OBJECT_CLASS (valadoc_gir_meta_data_parent_class)->finalize (obj);
}

/**
 * Metadata reader for GIR files
 */
static GType
valadoc_gir_meta_data_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (ValadocGirMetaDataClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) valadoc_gir_meta_data_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (ValadocGirMetaData), 0, (GInstanceInitFunc) valadoc_gir_meta_data_instance_init, NULL };
	GType valadoc_gir_meta_data_type_id;
	valadoc_gir_meta_data_type_id = g_type_register_static (G_TYPE_OBJECT, "ValadocGirMetaData", &g_define_type_info, 0);
	ValadocGirMetaData_private_offset = g_type_add_instance_private (valadoc_gir_meta_data_type_id, sizeof (ValadocGirMetaDataPrivate));
	return valadoc_gir_meta_data_type_id;
}

GType
valadoc_gir_meta_data_get_type (void)
{
	static volatile gsize valadoc_gir_meta_data_type_id__once = 0;
	if (g_once_init_enter (&valadoc_gir_meta_data_type_id__once)) {
		GType valadoc_gir_meta_data_type_id;
		valadoc_gir_meta_data_type_id = valadoc_gir_meta_data_get_type_once ();
		g_once_init_leave (&valadoc_gir_meta_data_type_id__once, valadoc_gir_meta_data_type_id);
	}
	return valadoc_gir_meta_data_type_id__once;
}

static void
_vala_valadoc_gir_meta_data_get_property (GObject * object,
                                          guint property_id,
                                          GValue * value,
                                          GParamSpec * pspec)
{
	ValadocGirMetaData * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (object, VALADOC_TYPE_GIR_META_DATA, ValadocGirMetaData);
	switch (property_id) {
		case VALADOC_GIR_META_DATA_IS_DOCBOOK_PROPERTY:
		g_value_set_boolean (value, valadoc_gir_meta_data_get_is_docbook (self));
		break;
		case VALADOC_GIR_META_DATA_INDEX_SGML_PROPERTY:
		g_value_set_string (value, valadoc_gir_meta_data_get_index_sgml (self));
		break;
		case VALADOC_GIR_META_DATA_INDEX_SGML_ONLINE_PROPERTY:
		g_value_set_string (value, valadoc_gir_meta_data_get_index_sgml_online (self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}

static void
_vala_valadoc_gir_meta_data_set_property (GObject * object,
                                          guint property_id,
                                          const GValue * value,
                                          GParamSpec * pspec)
{
	ValadocGirMetaData * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (object, VALADOC_TYPE_GIR_META_DATA, ValadocGirMetaData);
	switch (property_id) {
		case VALADOC_GIR_META_DATA_IS_DOCBOOK_PROPERTY:
		valadoc_gir_meta_data_set_is_docbook (self, g_value_get_boolean (value));
		break;
		case VALADOC_GIR_META_DATA_INDEX_SGML_PROPERTY:
		valadoc_gir_meta_data_set_index_sgml (self, g_value_get_string (value));
		break;
		case VALADOC_GIR_META_DATA_INDEX_SGML_ONLINE_PROPERTY:
		valadoc_gir_meta_data_set_index_sgml_online (self, g_value_get_string (value));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
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

