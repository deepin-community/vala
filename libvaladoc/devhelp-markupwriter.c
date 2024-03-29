/* devhelp-markupwriter.c generated by valac, the Vala compiler
 * generated from devhelp-markupwriter.vala, do not modify */

/* devhelp-markupwriter.vala
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
#include <stdio.h>

typedef struct _Block2Data Block2Data;
#define _valadoc_markup_writer_unref0(var) ((var == NULL) ? NULL : (var = (valadoc_markup_writer_unref (var), NULL)))

struct _Block2Data {
	int _ref_count_;
	ValadocDevhelpMarkupWriter* self;
	FILE* _stream;
};

static gpointer valadoc_devhelp_markup_writer_parent_class = NULL;

static Block2Data* block2_data_ref (Block2Data* _data2_);
static void block2_data_unref (void * _userdata_);
static void __lambda132_ (Block2Data* _data2_,
                   const gchar* str);
static void ___lambda132__valadoc_markup_writer_write_func (const gchar* text,
                                                     gpointer self);
static gboolean valadoc_devhelp_markup_writer_real_inline_element (ValadocMarkupWriter* base,
                                                            const gchar* name);
static gboolean valadoc_devhelp_markup_writer_real_content_inline_element (ValadocMarkupWriter* base,
                                                                    const gchar* name);
static GType valadoc_devhelp_markup_writer_get_type_once (void);
static void _vala_array_destroy (gpointer array,
                          gssize array_length,
                          GDestroyNotify destroy_func);
static void _vala_array_free (gpointer array,
                       gssize array_length,
                       GDestroyNotify destroy_func);

static Block2Data*
block2_data_ref (Block2Data* _data2_)
{
	g_atomic_int_inc (&_data2_->_ref_count_);
	return _data2_;
}

static void
block2_data_unref (void * _userdata_)
{
	Block2Data* _data2_;
	_data2_ = (Block2Data*) _userdata_;
	if (g_atomic_int_dec_and_test (&_data2_->_ref_count_)) {
		ValadocDevhelpMarkupWriter* self;
		self = _data2_->self;
		_valadoc_markup_writer_unref0 (self);
		g_slice_free (Block2Data, _data2_);
	}
}

static void
__lambda132_ (Block2Data* _data2_,
              const gchar* str)
{
	ValadocDevhelpMarkupWriter* self;
	self = _data2_->self;
	g_return_if_fail (str != NULL);
	fprintf (_data2_->_stream, "%s", str);
}

static void
___lambda132__valadoc_markup_writer_write_func (const gchar* text,
                                                gpointer self)
{
	__lambda132_ (self, text);
}

ValadocDevhelpMarkupWriter*
valadoc_devhelp_markup_writer_construct (GType object_type,
                                         FILE* stream,
                                         gboolean xml_declaration)
{
	ValadocDevhelpMarkupWriter* self = NULL;
	Block2Data* _data2_;
	g_return_val_if_fail (stream != NULL, NULL);
	_data2_ = g_slice_new0 (Block2Data);
	_data2_->_ref_count_ = 1;
	_data2_->_stream = stream;
	self = (ValadocDevhelpMarkupWriter*) valadoc_markup_writer_construct (object_type, ___lambda132__valadoc_markup_writer_write_func, block2_data_ref (_data2_), block2_data_unref, xml_declaration);
	_data2_->self = valadoc_markup_writer_ref (self);
	block2_data_unref (_data2_);
	_data2_ = NULL;
	return self;
}

ValadocDevhelpMarkupWriter*
valadoc_devhelp_markup_writer_new (FILE* stream,
                                   gboolean xml_declaration)
{
	return valadoc_devhelp_markup_writer_construct (VALADOC_DEVHELP_TYPE_MARKUP_WRITER, stream, xml_declaration);
}

static gboolean
valadoc_devhelp_markup_writer_real_inline_element (ValadocMarkupWriter* base,
                                                   const gchar* name)
{
	ValadocDevhelpMarkupWriter * self;
	gboolean result;
	self = (ValadocDevhelpMarkupWriter*) base;
	g_return_val_if_fail (name != NULL, FALSE);
	result = g_strcmp0 (name, "book") != 0;
	return result;
}

static gboolean
valadoc_devhelp_markup_writer_real_content_inline_element (ValadocMarkupWriter* base,
                                                           const gchar* name)
{
	ValadocDevhelpMarkupWriter * self;
	gboolean _tmp0_ = FALSE;
	gboolean result;
	self = (ValadocDevhelpMarkupWriter*) base;
	g_return_val_if_fail (name != NULL, FALSE);
	if (g_strcmp0 (name, "keyword") == 0) {
		_tmp0_ = TRUE;
	} else {
		_tmp0_ = g_strcmp0 (name, "sub") == 0;
	}
	result = _tmp0_;
	return result;
}

ValadocDevhelpMarkupWriter*
valadoc_devhelp_markup_writer_start_book (ValadocDevhelpMarkupWriter* self,
                                          const gchar* title,
                                          const gchar* lang,
                                          const gchar* link,
                                          const gchar* name,
                                          const gchar* version,
                                          const gchar* author)
{
	gchar* _tmp0_;
	gchar* _tmp1_;
	gchar* _tmp2_;
	gchar* _tmp3_;
	gchar* _tmp4_;
	gchar* _tmp5_;
	gchar* _tmp6_;
	gchar* _tmp7_;
	gchar* _tmp8_;
	gchar* _tmp9_;
	gchar* _tmp10_;
	gchar* _tmp11_;
	gchar* _tmp12_;
	gchar* _tmp13_;
	gchar** _tmp14_;
	gchar** _tmp15_;
	gint _tmp15__length1;
	ValadocDevhelpMarkupWriter* result;
	g_return_val_if_fail (self != NULL, NULL);
	g_return_val_if_fail (title != NULL, NULL);
	g_return_val_if_fail (lang != NULL, NULL);
	g_return_val_if_fail (link != NULL, NULL);
	g_return_val_if_fail (name != NULL, NULL);
	g_return_val_if_fail (version != NULL, NULL);
	g_return_val_if_fail (author != NULL, NULL);
	_tmp0_ = g_strdup ("xmlns");
	_tmp1_ = g_strdup ("http://www.devhelp.net/book");
	_tmp2_ = g_strdup ("title");
	_tmp3_ = g_strdup (title);
	_tmp4_ = g_strdup ("language");
	_tmp5_ = g_strdup (lang);
	_tmp6_ = g_strdup ("name");
	_tmp7_ = g_strdup (name);
	_tmp8_ = g_strdup ("version");
	_tmp9_ = g_strdup (version);
	_tmp10_ = g_strdup ("author");
	_tmp11_ = g_strdup (author);
	_tmp12_ = g_strdup ("link");
	_tmp13_ = g_strdup (link);
	_tmp14_ = g_new0 (gchar*, 14 + 1);
	_tmp14_[0] = _tmp0_;
	_tmp14_[1] = _tmp1_;
	_tmp14_[2] = _tmp2_;
	_tmp14_[3] = _tmp3_;
	_tmp14_[4] = _tmp4_;
	_tmp14_[5] = _tmp5_;
	_tmp14_[6] = _tmp6_;
	_tmp14_[7] = _tmp7_;
	_tmp14_[8] = _tmp8_;
	_tmp14_[9] = _tmp9_;
	_tmp14_[10] = _tmp10_;
	_tmp14_[11] = _tmp11_;
	_tmp14_[12] = _tmp12_;
	_tmp14_[13] = _tmp13_;
	_tmp15_ = _tmp14_;
	_tmp15__length1 = 14;
	valadoc_markup_writer_start_tag ((ValadocMarkupWriter*) self, "book", _tmp15_, (gint) 14);
	_tmp15_ = (_vala_array_free (_tmp15_, _tmp15__length1, (GDestroyNotify) g_free), NULL);
	result = self;
	return result;
}

ValadocDevhelpMarkupWriter*
valadoc_devhelp_markup_writer_end_book (ValadocDevhelpMarkupWriter* self)
{
	ValadocDevhelpMarkupWriter* result;
	g_return_val_if_fail (self != NULL, NULL);
	valadoc_markup_writer_end_tag ((ValadocMarkupWriter*) self, "book");
	result = self;
	return result;
}

ValadocDevhelpMarkupWriter*
valadoc_devhelp_markup_writer_start_functions (ValadocDevhelpMarkupWriter* self)
{
	ValadocDevhelpMarkupWriter* result;
	g_return_val_if_fail (self != NULL, NULL);
	valadoc_markup_writer_start_tag ((ValadocMarkupWriter*) self, "functions", NULL, (gint) 0);
	result = self;
	return result;
}

ValadocDevhelpMarkupWriter*
valadoc_devhelp_markup_writer_end_functions (ValadocDevhelpMarkupWriter* self)
{
	ValadocDevhelpMarkupWriter* result;
	g_return_val_if_fail (self != NULL, NULL);
	valadoc_markup_writer_end_tag ((ValadocMarkupWriter*) self, "functions");
	result = self;
	return result;
}

ValadocDevhelpMarkupWriter*
valadoc_devhelp_markup_writer_start_chapters (ValadocDevhelpMarkupWriter* self)
{
	ValadocDevhelpMarkupWriter* result;
	g_return_val_if_fail (self != NULL, NULL);
	valadoc_markup_writer_start_tag ((ValadocMarkupWriter*) self, "chapters", NULL, (gint) 0);
	result = self;
	return result;
}

ValadocDevhelpMarkupWriter*
valadoc_devhelp_markup_writer_end_chapters (ValadocDevhelpMarkupWriter* self)
{
	ValadocDevhelpMarkupWriter* result;
	g_return_val_if_fail (self != NULL, NULL);
	valadoc_markup_writer_end_tag ((ValadocMarkupWriter*) self, "chapters");
	result = self;
	return result;
}

ValadocDevhelpMarkupWriter*
valadoc_devhelp_markup_writer_start_sub (ValadocDevhelpMarkupWriter* self,
                                         const gchar* name,
                                         const gchar* link)
{
	gchar* _tmp0_;
	gchar* _tmp1_;
	gchar* _tmp2_;
	gchar* _tmp3_;
	gchar** _tmp4_;
	gchar** _tmp5_;
	gint _tmp5__length1;
	ValadocDevhelpMarkupWriter* result;
	g_return_val_if_fail (self != NULL, NULL);
	g_return_val_if_fail (name != NULL, NULL);
	g_return_val_if_fail (link != NULL, NULL);
	_tmp0_ = g_strdup ("name");
	_tmp1_ = g_strdup (name);
	_tmp2_ = g_strdup ("link");
	_tmp3_ = g_strdup (link);
	_tmp4_ = g_new0 (gchar*, 4 + 1);
	_tmp4_[0] = _tmp0_;
	_tmp4_[1] = _tmp1_;
	_tmp4_[2] = _tmp2_;
	_tmp4_[3] = _tmp3_;
	_tmp5_ = _tmp4_;
	_tmp5__length1 = 4;
	valadoc_markup_writer_start_tag ((ValadocMarkupWriter*) self, "sub", _tmp5_, (gint) 4);
	_tmp5_ = (_vala_array_free (_tmp5_, _tmp5__length1, (GDestroyNotify) g_free), NULL);
	result = self;
	return result;
}

ValadocDevhelpMarkupWriter*
valadoc_devhelp_markup_writer_end_sub (ValadocDevhelpMarkupWriter* self)
{
	ValadocDevhelpMarkupWriter* result;
	g_return_val_if_fail (self != NULL, NULL);
	valadoc_markup_writer_end_tag ((ValadocMarkupWriter*) self, "sub");
	result = self;
	return result;
}

ValadocDevhelpMarkupWriter*
valadoc_devhelp_markup_writer_keyword (ValadocDevhelpMarkupWriter* self,
                                       const gchar* name,
                                       const gchar* type,
                                       const gchar* link)
{
	gchar* _tmp0_;
	gchar* _tmp1_;
	gchar* _tmp2_;
	gchar* _tmp3_;
	gchar* _tmp4_;
	gchar* _tmp5_;
	gchar** _tmp6_;
	gchar** _tmp7_;
	gint _tmp7__length1;
	ValadocDevhelpMarkupWriter* result;
	g_return_val_if_fail (self != NULL, NULL);
	g_return_val_if_fail (name != NULL, NULL);
	g_return_val_if_fail (type != NULL, NULL);
	g_return_val_if_fail (link != NULL, NULL);
	_tmp0_ = g_strdup ("type");
	_tmp1_ = g_strdup (type);
	_tmp2_ = g_strdup ("name");
	_tmp3_ = g_strdup (name);
	_tmp4_ = g_strdup ("link");
	_tmp5_ = g_strdup (link);
	_tmp6_ = g_new0 (gchar*, 6 + 1);
	_tmp6_[0] = _tmp0_;
	_tmp6_[1] = _tmp1_;
	_tmp6_[2] = _tmp2_;
	_tmp6_[3] = _tmp3_;
	_tmp6_[4] = _tmp4_;
	_tmp6_[5] = _tmp5_;
	_tmp7_ = _tmp6_;
	_tmp7__length1 = 6;
	valadoc_markup_writer_start_tag ((ValadocMarkupWriter*) self, "keyword", _tmp7_, (gint) 6);
	_tmp7_ = (_vala_array_free (_tmp7_, _tmp7__length1, (GDestroyNotify) g_free), NULL);
	valadoc_markup_writer_end_tag ((ValadocMarkupWriter*) self, "keyword");
	result = self;
	return result;
}

static void
valadoc_devhelp_markup_writer_class_init (ValadocDevhelpMarkupWriterClass * klass,
                                          gpointer klass_data)
{
	valadoc_devhelp_markup_writer_parent_class = g_type_class_peek_parent (klass);
	((ValadocMarkupWriterClass *) klass)->inline_element = (gboolean (*) (ValadocMarkupWriter*, const gchar*)) valadoc_devhelp_markup_writer_real_inline_element;
	((ValadocMarkupWriterClass *) klass)->content_inline_element = (gboolean (*) (ValadocMarkupWriter*, const gchar*)) valadoc_devhelp_markup_writer_real_content_inline_element;
}

static void
valadoc_devhelp_markup_writer_instance_init (ValadocDevhelpMarkupWriter * self,
                                             gpointer klass)
{
}

static GType
valadoc_devhelp_markup_writer_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (ValadocDevhelpMarkupWriterClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) valadoc_devhelp_markup_writer_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (ValadocDevhelpMarkupWriter), 0, (GInstanceInitFunc) valadoc_devhelp_markup_writer_instance_init, NULL };
	GType valadoc_devhelp_markup_writer_type_id;
	valadoc_devhelp_markup_writer_type_id = g_type_register_static (VALADOC_TYPE_MARKUP_WRITER, "ValadocDevhelpMarkupWriter", &g_define_type_info, 0);
	return valadoc_devhelp_markup_writer_type_id;
}

GType
valadoc_devhelp_markup_writer_get_type (void)
{
	static volatile gsize valadoc_devhelp_markup_writer_type_id__once = 0;
	if (g_once_init_enter (&valadoc_devhelp_markup_writer_type_id__once)) {
		GType valadoc_devhelp_markup_writer_type_id;
		valadoc_devhelp_markup_writer_type_id = valadoc_devhelp_markup_writer_get_type_once ();
		g_once_init_leave (&valadoc_devhelp_markup_writer_type_id__once, valadoc_devhelp_markup_writer_type_id);
	}
	return valadoc_devhelp_markup_writer_type_id__once;
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

