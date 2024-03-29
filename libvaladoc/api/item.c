/* item.c generated by valac, the Vala compiler
 * generated from item.vala, do not modify */

/* item.vala
 *
 * Copyright (C) 2008  Florian Brosch
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
#include <vala.h>
#include <glib.h>
#include <glib-object.h>

enum  {
	VALADOC_API_ITEM_0_PROPERTY,
	VALADOC_API_ITEM_DATA_PROPERTY,
	VALADOC_API_ITEM_PARENT_PROPERTY,
	VALADOC_API_ITEM_SIGNATURE_PROPERTY,
	VALADOC_API_ITEM_NUM_PROPERTIES
};
static GParamSpec* valadoc_api_item_properties[VALADOC_API_ITEM_NUM_PROPERTIES];
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _vala_code_node_unref0(var) ((var == NULL) ? NULL : (var = (vala_code_node_unref (var), NULL)))

struct _ValadocApiItemPrivate {
	ValadocContentInline* _signature;
	ValaCodeNode* _data;
	ValadocApiItem* _parent;
};

static gint ValadocApiItem_private_offset;
static gpointer valadoc_api_item_parent_class = NULL;

 G_GNUC_INTERNAL void valadoc_api_item_parse_comments (ValadocApiItem* self,
                                      ValadocSettings* settings,
                                      ValadocDocumentationParser* parser);
 G_GNUC_INTERNAL void valadoc_api_item_check_comments (ValadocApiItem* self,
                                      ValadocSettings* settings,
                                      ValadocDocumentationParser* parser);
static void valadoc_api_item_set_data (ValadocApiItem* self,
                                ValaCodeNode* value);
static void valadoc_api_item_real_parse_comments (ValadocApiItem* self,
                                           ValadocSettings* settings,
                                           ValadocDocumentationParser* parser);
static void valadoc_api_item_real_check_comments (ValadocApiItem* self,
                                           ValadocSettings* settings,
                                           ValadocDocumentationParser* parser);
static ValadocContentInline* valadoc_api_item_real_build_signature (ValadocApiItem* self);
static void valadoc_api_item_finalize (GObject * obj);
static GType valadoc_api_item_get_type_once (void);
static void _vala_valadoc_api_item_get_property (GObject * object,
                                          guint property_id,
                                          GValue * value,
                                          GParamSpec * pspec);
static void _vala_valadoc_api_item_set_property (GObject * object,
                                          guint property_id,
                                          const GValue * value,
                                          GParamSpec * pspec);

static inline gpointer
valadoc_api_item_get_instance_private (ValadocApiItem* self)
{
	return G_STRUCT_MEMBER_P (self, ValadocApiItem_private_offset);
}

ValaCodeNode*
valadoc_api_item_get_data (ValadocApiItem* self)
{
	ValaCodeNode* result;
	ValaCodeNode* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_data;
	result = _tmp0_;
	return result;
}

static gpointer
_vala_code_node_ref0 (gpointer self)
{
	return self ? vala_code_node_ref (self) : NULL;
}

static void
valadoc_api_item_set_data (ValadocApiItem* self,
                           ValaCodeNode* value)
{
	ValaCodeNode* old_value;
	g_return_if_fail (self != NULL);
	old_value = valadoc_api_item_get_data (self);
	if (old_value != value) {
		ValaCodeNode* _tmp0_;
		_tmp0_ = _vala_code_node_ref0 (value);
		_vala_code_node_unref0 (self->priv->_data);
		self->priv->_data = _tmp0_;
		g_object_notify_by_pspec ((GObject *) self, valadoc_api_item_properties[VALADOC_API_ITEM_DATA_PROPERTY]);
	}
}

ValadocApiItem*
valadoc_api_item_get_parent (ValadocApiItem* self)
{
	ValadocApiItem* result;
	ValadocApiItem* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_parent;
	result = _tmp0_;
	return result;
}

static gpointer
_g_object_ref0 (gpointer self)
{
	return self ? g_object_ref (self) : NULL;
}

void
valadoc_api_item_set_parent (ValadocApiItem* self,
                             ValadocApiItem* value)
{
	ValadocApiItem* old_value;
	g_return_if_fail (self != NULL);
	old_value = valadoc_api_item_get_parent (self);
	if (old_value != value) {
		ValadocApiItem* _tmp0_;
		_tmp0_ = _g_object_ref0 (value);
		_g_object_unref0 (self->priv->_parent);
		self->priv->_parent = _tmp0_;
		g_object_notify_by_pspec ((GObject *) self, valadoc_api_item_properties[VALADOC_API_ITEM_PARENT_PROPERTY]);
	}
}

ValadocApiItem*
valadoc_api_item_construct (GType object_type,
                            ValaCodeNode* data)
{
	ValadocApiItem * self = NULL;
	self = (ValadocApiItem*) g_object_new (object_type, NULL);
	valadoc_api_item_set_data (self, data);
	return self;
}

static void
valadoc_api_item_real_parse_comments (ValadocApiItem* self,
                                      ValadocSettings* settings,
                                      ValadocDocumentationParser* parser)
{
	g_return_if_fail (settings != NULL);
	g_return_if_fail (parser != NULL);
}

void
valadoc_api_item_parse_comments (ValadocApiItem* self,
                                 ValadocSettings* settings,
                                 ValadocDocumentationParser* parser)
{
	ValadocApiItemClass* _klass_;
	g_return_if_fail (self != NULL);
	_klass_ = VALADOC_API_ITEM_GET_CLASS (self);
	if (_klass_->parse_comments) {
		_klass_->parse_comments (self, settings, parser);
	}
}

static void
valadoc_api_item_real_check_comments (ValadocApiItem* self,
                                      ValadocSettings* settings,
                                      ValadocDocumentationParser* parser)
{
	g_return_if_fail (settings != NULL);
	g_return_if_fail (parser != NULL);
}

void
valadoc_api_item_check_comments (ValadocApiItem* self,
                                 ValadocSettings* settings,
                                 ValadocDocumentationParser* parser)
{
	ValadocApiItemClass* _klass_;
	g_return_if_fail (self != NULL);
	_klass_ = VALADOC_API_ITEM_GET_CLASS (self);
	if (_klass_->check_comments) {
		_klass_->check_comments (self, settings, parser);
	}
}

ValadocContentInline*
valadoc_api_item_get_signature (ValadocApiItem* self)
{
	ValadocContentInline* result;
	ValadocContentInline* _tmp0_;
	ValadocContentInline* _tmp2_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_signature;
	if (_tmp0_ == NULL) {
		ValadocContentInline* _tmp1_;
		_tmp1_ = valadoc_api_item_build_signature (self);
		_g_object_unref0 (self->priv->_signature);
		self->priv->_signature = _tmp1_;
	}
	_tmp2_ = self->priv->_signature;
	result = _tmp2_;
	return result;
}

static ValadocContentInline*
valadoc_api_item_real_build_signature (ValadocApiItem* self)
{
	g_critical ("Type `%s' does not implement abstract method `valadoc_api_item_build_signature'", g_type_name (G_TYPE_FROM_INSTANCE (self)));
	return NULL;
}

ValadocContentInline*
valadoc_api_item_build_signature (ValadocApiItem* self)
{
	ValadocApiItemClass* _klass_;
	g_return_val_if_fail (self != NULL, NULL);
	_klass_ = VALADOC_API_ITEM_GET_CLASS (self);
	if (_klass_->build_signature) {
		return _klass_->build_signature (self);
	}
	return NULL;
}

static void
valadoc_api_item_class_init (ValadocApiItemClass * klass,
                             gpointer klass_data)
{
	valadoc_api_item_parent_class = g_type_class_peek_parent (klass);
	g_type_class_adjust_private_offset (klass, &ValadocApiItem_private_offset);
	((ValadocApiItemClass *) klass)->parse_comments = (void (*) (ValadocApiItem*, ValadocSettings*, ValadocDocumentationParser*)) valadoc_api_item_real_parse_comments;
	((ValadocApiItemClass *) klass)->check_comments = (void (*) (ValadocApiItem*, ValadocSettings*, ValadocDocumentationParser*)) valadoc_api_item_real_check_comments;
	((ValadocApiItemClass *) klass)->build_signature = (ValadocContentInline* (*) (ValadocApiItem*)) valadoc_api_item_real_build_signature;
	G_OBJECT_CLASS (klass)->get_property = _vala_valadoc_api_item_get_property;
	G_OBJECT_CLASS (klass)->set_property = _vala_valadoc_api_item_set_property;
	G_OBJECT_CLASS (klass)->finalize = valadoc_api_item_finalize;
	g_object_class_install_property (G_OBJECT_CLASS (klass), VALADOC_API_ITEM_DATA_PROPERTY, valadoc_api_item_properties[VALADOC_API_ITEM_DATA_PROPERTY] = vala_param_spec_code_node ("data", "data", "data", VALA_TYPE_CODE_NODE, G_PARAM_STATIC_STRINGS | G_PARAM_READABLE));
	/**
	 * The parent of this item.
	 */
	g_object_class_install_property (G_OBJECT_CLASS (klass), VALADOC_API_ITEM_PARENT_PROPERTY, valadoc_api_item_properties[VALADOC_API_ITEM_PARENT_PROPERTY] = g_param_spec_object ("parent", "parent", "parent", VALADOC_API_TYPE_ITEM, G_PARAM_STATIC_STRINGS | G_PARAM_READABLE | G_PARAM_WRITABLE));
	/**
	 * The signature of this item.
	 */
	g_object_class_install_property (G_OBJECT_CLASS (klass), VALADOC_API_ITEM_SIGNATURE_PROPERTY, valadoc_api_item_properties[VALADOC_API_ITEM_SIGNATURE_PROPERTY] = g_param_spec_object ("signature", "signature", "signature", VALADOC_CONTENT_TYPE_INLINE, G_PARAM_STATIC_STRINGS | G_PARAM_READABLE));
}

static void
valadoc_api_item_instance_init (ValadocApiItem * self,
                                gpointer klass)
{
	self->priv = valadoc_api_item_get_instance_private (self);
}

static void
valadoc_api_item_finalize (GObject * obj)
{
	ValadocApiItem * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, VALADOC_API_TYPE_ITEM, ValadocApiItem);
	_g_object_unref0 (self->priv->_signature);
	_vala_code_node_unref0 (self->priv->_data);
	_g_object_unref0 (self->priv->_parent);
	G_OBJECT_CLASS (valadoc_api_item_parent_class)->finalize (obj);
}

/**
 * Represents a node in the api tree.
 */
static GType
valadoc_api_item_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (ValadocApiItemClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) valadoc_api_item_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (ValadocApiItem), 0, (GInstanceInitFunc) valadoc_api_item_instance_init, NULL };
	GType valadoc_api_item_type_id;
	valadoc_api_item_type_id = g_type_register_static (G_TYPE_OBJECT, "ValadocApiItem", &g_define_type_info, G_TYPE_FLAG_ABSTRACT);
	ValadocApiItem_private_offset = g_type_add_instance_private (valadoc_api_item_type_id, sizeof (ValadocApiItemPrivate));
	return valadoc_api_item_type_id;
}

GType
valadoc_api_item_get_type (void)
{
	static volatile gsize valadoc_api_item_type_id__once = 0;
	if (g_once_init_enter (&valadoc_api_item_type_id__once)) {
		GType valadoc_api_item_type_id;
		valadoc_api_item_type_id = valadoc_api_item_get_type_once ();
		g_once_init_leave (&valadoc_api_item_type_id__once, valadoc_api_item_type_id);
	}
	return valadoc_api_item_type_id__once;
}

static void
_vala_valadoc_api_item_get_property (GObject * object,
                                     guint property_id,
                                     GValue * value,
                                     GParamSpec * pspec)
{
	ValadocApiItem * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (object, VALADOC_API_TYPE_ITEM, ValadocApiItem);
	switch (property_id) {
		case VALADOC_API_ITEM_DATA_PROPERTY:
		vala_value_set_code_node (value, valadoc_api_item_get_data (self));
		break;
		case VALADOC_API_ITEM_PARENT_PROPERTY:
		g_value_set_object (value, valadoc_api_item_get_parent (self));
		break;
		case VALADOC_API_ITEM_SIGNATURE_PROPERTY:
		g_value_set_object (value, valadoc_api_item_get_signature (self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}

static void
_vala_valadoc_api_item_set_property (GObject * object,
                                     guint property_id,
                                     const GValue * value,
                                     GParamSpec * pspec)
{
	ValadocApiItem * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (object, VALADOC_API_TYPE_ITEM, ValadocApiItem);
	switch (property_id) {
		case VALADOC_API_ITEM_DATA_PROPERTY:
		valadoc_api_item_set_data (self, vala_value_get_code_node (value));
		break;
		case VALADOC_API_ITEM_PARENT_PROPERTY:
		valadoc_api_item_set_parent (self, g_value_get_object (value));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}

