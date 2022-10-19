/* table.c generated by valac, the Vala compiler
 * generated from table.vala, do not modify */

/* table.vala
 *
 * Copyright (C) 2008-2009 Didier Villevalois
 * Copyright (C) 2008-2012 Florian Brosch
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
 * 	Didier 'Ptitjes Villevalois <ptitjes@free.fr>
 */

#include "valadoc.h"
#include <valagee.h>
#include <glib-object.h>
#include <stdlib.h>
#include <string.h>
#include <glib.h>

enum  {
	VALADOC_CONTENT_TABLE_0_PROPERTY,
	VALADOC_CONTENT_TABLE_ROWS_PROPERTY,
	VALADOC_CONTENT_TABLE_NUM_PROPERTIES
};
static GParamSpec* valadoc_content_table_properties[VALADOC_CONTENT_TABLE_NUM_PROPERTIES];
#define _vala_iterable_unref0(var) ((var == NULL) ? NULL : (var = (vala_iterable_unref (var), NULL)))
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

struct _ValadocContentTablePrivate {
	ValaList* _rows;
};

static gint ValadocContentTable_private_offset;
static gpointer valadoc_content_table_parent_class = NULL;
static ValadocContentBlockIface * valadoc_content_table_valadoc_content_block_parent_iface = NULL;

 G_GNUC_INTERNAL ValadocContentTable* valadoc_content_table_new (void);
 G_GNUC_INTERNAL ValadocContentTable* valadoc_content_table_construct (GType object_type);
static void valadoc_content_table_real_check (ValadocContentContentElement* base,
                                       ValadocApiTree* api_root,
                                       ValadocApiNode* container,
                                       const gchar* file_path,
                                       ValadocErrorReporter* reporter,
                                       ValadocSettings* settings);
 G_GNUC_INTERNAL void valadoc_content_content_element_set_parent (ValadocContentContentElement* self,
                                                 ValadocContentContentElement* value);
static void valadoc_content_table_real_accept (ValadocContentContentElement* base,
                                        ValadocContentContentVisitor* visitor);
static void valadoc_content_table_real_accept_children (ValadocContentContentElement* base,
                                                 ValadocContentContentVisitor* visitor);
static gboolean valadoc_content_table_real_is_empty (ValadocContentContentElement* base);
static ValadocContentContentElement* valadoc_content_table_real_copy (ValadocContentContentElement* base,
                                                               ValadocContentContentElement* new_parent);
static void valadoc_content_table_finalize (GObject * obj);
static GType valadoc_content_table_get_type_once (void);
static void _vala_valadoc_content_table_get_property (GObject * object,
                                               guint property_id,
                                               GValue * value,
                                               GParamSpec * pspec);

static inline gpointer
valadoc_content_table_get_instance_private (ValadocContentTable* self)
{
	return G_STRUCT_MEMBER_P (self, ValadocContentTable_private_offset);
}

ValaList*
valadoc_content_table_get_rows (ValadocContentTable* self)
{
	ValaList* result;
	ValaList* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_rows;
	result = _tmp0_;
	return result;
}

 G_GNUC_INTERNAL ValadocContentTable*
valadoc_content_table_construct (GType object_type)
{
	ValadocContentTable * self = NULL;
	GEqualFunc _tmp0_;
	ValaArrayList* _tmp1_;
	self = (ValadocContentTable*) valadoc_content_content_element_construct (object_type);
	_tmp0_ = g_direct_equal;
	_tmp1_ = vala_array_list_new (VALADOC_CONTENT_TYPE_TABLE_ROW, (GBoxedCopyFunc) g_object_ref, (GDestroyNotify) g_object_unref, _tmp0_);
	_vala_iterable_unref0 (self->priv->_rows);
	self->priv->_rows = (ValaList*) _tmp1_;
	return self;
}

 G_GNUC_INTERNAL ValadocContentTable*
valadoc_content_table_new (void)
{
	return valadoc_content_table_construct (VALADOC_CONTENT_TYPE_TABLE);
}

static void
valadoc_content_table_real_check (ValadocContentContentElement* base,
                                  ValadocApiTree* api_root,
                                  ValadocApiNode* container,
                                  const gchar* file_path,
                                  ValadocErrorReporter* reporter,
                                  ValadocSettings* settings)
{
	ValadocContentTable * self;
	self = (ValadocContentTable*) base;
	g_return_if_fail (api_root != NULL);
	g_return_if_fail (container != NULL);
	g_return_if_fail (file_path != NULL);
	g_return_if_fail (reporter != NULL);
	g_return_if_fail (settings != NULL);
	{
		ValaList* _row_list = NULL;
		ValaList* _tmp0_;
		gint _row_size = 0;
		ValaList* _tmp1_;
		gint _tmp2_;
		gint _tmp3_;
		gint _row_index = 0;
		_tmp0_ = self->priv->_rows;
		_row_list = _tmp0_;
		_tmp1_ = _row_list;
		_tmp2_ = vala_collection_get_size ((ValaCollection*) _tmp1_);
		_tmp3_ = _tmp2_;
		_row_size = _tmp3_;
		_row_index = -1;
		while (TRUE) {
			gint _tmp4_;
			gint _tmp5_;
			ValadocContentTableRow* row = NULL;
			ValaList* _tmp6_;
			gpointer _tmp7_;
			ValadocContentTableRow* _tmp8_;
			ValadocContentTableRow* _tmp9_;
			_row_index = _row_index + 1;
			_tmp4_ = _row_index;
			_tmp5_ = _row_size;
			if (!(_tmp4_ < _tmp5_)) {
				break;
			}
			_tmp6_ = _row_list;
			_tmp7_ = vala_list_get (_tmp6_, _row_index);
			row = (ValadocContentTableRow*) _tmp7_;
			_tmp8_ = row;
			valadoc_content_content_element_set_parent ((ValadocContentContentElement*) _tmp8_, (ValadocContentContentElement*) self);
			_tmp9_ = row;
			valadoc_content_content_element_check ((ValadocContentContentElement*) _tmp9_, api_root, container, file_path, reporter, settings);
			_g_object_unref0 (row);
		}
	}
}

static void
valadoc_content_table_real_accept (ValadocContentContentElement* base,
                                   ValadocContentContentVisitor* visitor)
{
	ValadocContentTable * self;
	self = (ValadocContentTable*) base;
	g_return_if_fail (visitor != NULL);
	valadoc_content_content_visitor_visit_table (visitor, self);
}

static void
valadoc_content_table_real_accept_children (ValadocContentContentElement* base,
                                            ValadocContentContentVisitor* visitor)
{
	ValadocContentTable * self;
	self = (ValadocContentTable*) base;
	g_return_if_fail (visitor != NULL);
	{
		ValaList* _element_list = NULL;
		ValaList* _tmp0_;
		gint _element_size = 0;
		ValaList* _tmp1_;
		gint _tmp2_;
		gint _tmp3_;
		gint _element_index = 0;
		_tmp0_ = self->priv->_rows;
		_element_list = _tmp0_;
		_tmp1_ = _element_list;
		_tmp2_ = vala_collection_get_size ((ValaCollection*) _tmp1_);
		_tmp3_ = _tmp2_;
		_element_size = _tmp3_;
		_element_index = -1;
		while (TRUE) {
			gint _tmp4_;
			gint _tmp5_;
			ValadocContentTableRow* element = NULL;
			ValaList* _tmp6_;
			gpointer _tmp7_;
			ValadocContentTableRow* _tmp8_;
			_element_index = _element_index + 1;
			_tmp4_ = _element_index;
			_tmp5_ = _element_size;
			if (!(_tmp4_ < _tmp5_)) {
				break;
			}
			_tmp6_ = _element_list;
			_tmp7_ = vala_list_get (_tmp6_, _element_index);
			element = (ValadocContentTableRow*) _tmp7_;
			_tmp8_ = element;
			valadoc_content_content_element_accept ((ValadocContentContentElement*) _tmp8_, visitor);
			_g_object_unref0 (element);
		}
	}
}

static gboolean
valadoc_content_table_real_is_empty (ValadocContentContentElement* base)
{
	ValadocContentTable * self;
	gboolean result = FALSE;
	self = (ValadocContentTable*) base;
	result = FALSE;
	return result;
}

static ValadocContentContentElement*
valadoc_content_table_real_copy (ValadocContentContentElement* base,
                                 ValadocContentContentElement* new_parent)
{
	ValadocContentTable * self;
	ValadocContentTable* table = NULL;
	ValadocContentTable* _tmp0_;
	ValadocContentTable* _tmp1_;
	ValadocContentContentElement* result = NULL;
	self = (ValadocContentTable*) base;
	_tmp0_ = valadoc_content_table_new ();
	table = _tmp0_;
	_tmp1_ = table;
	valadoc_content_content_element_set_parent ((ValadocContentContentElement*) _tmp1_, new_parent);
	{
		ValaList* _row_list = NULL;
		ValaList* _tmp2_;
		gint _row_size = 0;
		ValaList* _tmp3_;
		gint _tmp4_;
		gint _tmp5_;
		gint _row_index = 0;
		_tmp2_ = self->priv->_rows;
		_row_list = _tmp2_;
		_tmp3_ = _row_list;
		_tmp4_ = vala_collection_get_size ((ValaCollection*) _tmp3_);
		_tmp5_ = _tmp4_;
		_row_size = _tmp5_;
		_row_index = -1;
		while (TRUE) {
			gint _tmp6_;
			gint _tmp7_;
			ValadocContentTableRow* row = NULL;
			ValaList* _tmp8_;
			gpointer _tmp9_;
			ValadocContentTableRow* copy = NULL;
			ValadocContentTableRow* _tmp10_;
			ValadocContentTable* _tmp11_;
			ValadocContentContentElement* _tmp12_;
			ValadocContentTableRow* _tmp13_;
			ValadocContentTable* _tmp14_;
			ValaList* _tmp15_;
			ValaList* _tmp16_;
			ValadocContentTableRow* _tmp17_;
			_row_index = _row_index + 1;
			_tmp6_ = _row_index;
			_tmp7_ = _row_size;
			if (!(_tmp6_ < _tmp7_)) {
				break;
			}
			_tmp8_ = _row_list;
			_tmp9_ = vala_list_get (_tmp8_, _row_index);
			row = (ValadocContentTableRow*) _tmp9_;
			_tmp10_ = row;
			_tmp11_ = table;
			_tmp12_ = valadoc_content_content_element_copy ((ValadocContentContentElement*) _tmp10_, (ValadocContentContentElement*) _tmp11_);
			_tmp13_ = VALADOC_CONTENT_IS_TABLE_ROW (_tmp12_) ? ((ValadocContentTableRow*) _tmp12_) : NULL;
			if (_tmp13_ == NULL) {
				_g_object_unref0 (_tmp12_);
			}
			copy = _tmp13_;
			_tmp14_ = table;
			_tmp15_ = valadoc_content_table_get_rows (_tmp14_);
			_tmp16_ = _tmp15_;
			_tmp17_ = copy;
			vala_collection_add ((ValaCollection*) _tmp16_, _tmp17_);
			_g_object_unref0 (copy);
			_g_object_unref0 (row);
		}
	}
	result = (ValadocContentContentElement*) table;
	return result;
}

static void
valadoc_content_table_class_init (ValadocContentTableClass * klass,
                                  gpointer klass_data)
{
	valadoc_content_table_parent_class = g_type_class_peek_parent (klass);
	g_type_class_adjust_private_offset (klass, &ValadocContentTable_private_offset);
	((ValadocContentContentElementClass *) klass)->check = (void (*) (ValadocContentContentElement*, ValadocApiTree*, ValadocApiNode*, const gchar*, ValadocErrorReporter*, ValadocSettings*)) valadoc_content_table_real_check;
	((ValadocContentContentElementClass *) klass)->accept = (void (*) (ValadocContentContentElement*, ValadocContentContentVisitor*)) valadoc_content_table_real_accept;
	((ValadocContentContentElementClass *) klass)->accept_children = (void (*) (ValadocContentContentElement*, ValadocContentContentVisitor*)) valadoc_content_table_real_accept_children;
	((ValadocContentContentElementClass *) klass)->is_empty = (gboolean (*) (ValadocContentContentElement*)) valadoc_content_table_real_is_empty;
	((ValadocContentContentElementClass *) klass)->copy = (ValadocContentContentElement* (*) (ValadocContentContentElement*, ValadocContentContentElement*)) valadoc_content_table_real_copy;
	G_OBJECT_CLASS (klass)->get_property = _vala_valadoc_content_table_get_property;
	G_OBJECT_CLASS (klass)->finalize = valadoc_content_table_finalize;
	g_object_class_install_property (G_OBJECT_CLASS (klass), VALADOC_CONTENT_TABLE_ROWS_PROPERTY, valadoc_content_table_properties[VALADOC_CONTENT_TABLE_ROWS_PROPERTY] = vala_param_spec_iterable ("rows", "rows", "rows", VALA_TYPE_LIST, G_PARAM_STATIC_STRINGS | G_PARAM_READABLE));
}

static void
valadoc_content_table_valadoc_content_block_interface_init (ValadocContentBlockIface * iface,
                                                            gpointer iface_data)
{
	valadoc_content_table_valadoc_content_block_parent_iface = g_type_interface_peek_parent (iface);
}

static void
valadoc_content_table_instance_init (ValadocContentTable * self,
                                     gpointer klass)
{
	self->priv = valadoc_content_table_get_instance_private (self);
}

static void
valadoc_content_table_finalize (GObject * obj)
{
	ValadocContentTable * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, VALADOC_CONTENT_TYPE_TABLE, ValadocContentTable);
	_vala_iterable_unref0 (self->priv->_rows);
	G_OBJECT_CLASS (valadoc_content_table_parent_class)->finalize (obj);
}

static GType
valadoc_content_table_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (ValadocContentTableClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) valadoc_content_table_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (ValadocContentTable), 0, (GInstanceInitFunc) valadoc_content_table_instance_init, NULL };
	static const GInterfaceInfo valadoc_content_block_info = { (GInterfaceInitFunc) valadoc_content_table_valadoc_content_block_interface_init, (GInterfaceFinalizeFunc) NULL, NULL};
	GType valadoc_content_table_type_id;
	valadoc_content_table_type_id = g_type_register_static (VALADOC_CONTENT_TYPE_CONTENT_ELEMENT, "ValadocContentTable", &g_define_type_info, 0);
	g_type_add_interface_static (valadoc_content_table_type_id, VALADOC_CONTENT_TYPE_BLOCK, &valadoc_content_block_info);
	ValadocContentTable_private_offset = g_type_add_instance_private (valadoc_content_table_type_id, sizeof (ValadocContentTablePrivate));
	return valadoc_content_table_type_id;
}

GType
valadoc_content_table_get_type (void)
{
	static volatile gsize valadoc_content_table_type_id__volatile = 0;
	if (g_once_init_enter (&valadoc_content_table_type_id__volatile)) {
		GType valadoc_content_table_type_id;
		valadoc_content_table_type_id = valadoc_content_table_get_type_once ();
		g_once_init_leave (&valadoc_content_table_type_id__volatile, valadoc_content_table_type_id);
	}
	return valadoc_content_table_type_id__volatile;
}

static void
_vala_valadoc_content_table_get_property (GObject * object,
                                          guint property_id,
                                          GValue * value,
                                          GParamSpec * pspec)
{
	ValadocContentTable * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (object, VALADOC_CONTENT_TYPE_TABLE, ValadocContentTable);
	switch (property_id) {
		case VALADOC_CONTENT_TABLE_ROWS_PROPERTY:
		vala_value_set_iterable (value, valadoc_content_table_get_rows (self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}
