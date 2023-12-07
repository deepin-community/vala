/* errordomain.c generated by valac, the Vala compiler
 * generated from errordomain.vala, do not modify */

/* errordomain.vala
 *
 * Copyright (C) 2008-2011  Florian Brosch
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
#include <vala.h>
#include <valacodegen.h>

enum  {
	VALADOC_API_ERROR_DOMAIN_0_PROPERTY,
	VALADOC_API_ERROR_DOMAIN_NODE_TYPE_PROPERTY,
	VALADOC_API_ERROR_DOMAIN_NUM_PROPERTIES
};
static GParamSpec* valadoc_api_error_domain_properties[VALADOC_API_ERROR_DOMAIN_NUM_PROPERTIES];
#define _g_free0(var) (var = (g_free (var), NULL))
#define _valadoc_api_signature_builder_unref0(var) ((var == NULL) ? NULL : (var = (valadoc_api_signature_builder_unref (var), NULL)))

struct _ValadocApiErrorDomainPrivate {
	gchar* quark_function_name;
	gchar* quark_macro_name;
	gchar* dbus_name;
	gchar* cname;
};

static gint ValadocApiErrorDomain_private_offset;
static gpointer valadoc_api_error_domain_parent_class = NULL;

static gchar* _valadoc_api_error_domain_get_quark_function_name (ValadocApiErrorDomain* self,
                                                          ValaErrorDomain* element);
static gchar* _valadoc_api_error_domain_get_quark_macro_name (ValadocApiErrorDomain* self,
                                                       ValaErrorDomain* element);
static void valadoc_api_error_domain_real_accept (ValadocApiNode* base,
                                           ValadocApiVisitor* visitor);
static ValadocContentInline* valadoc_api_error_domain_real_build_signature (ValadocApiItem* base);
static void valadoc_api_error_domain_finalize (GObject * obj);
static GType valadoc_api_error_domain_get_type_once (void);
static void _vala_valadoc_api_error_domain_get_property (GObject * object,
                                                  guint property_id,
                                                  GValue * value,
                                                  GParamSpec * pspec);

static inline gpointer
valadoc_api_error_domain_get_instance_private (ValadocApiErrorDomain* self)
{
	return G_STRUCT_MEMBER_P (self, ValadocApiErrorDomain_private_offset);
}

ValadocApiErrorDomain*
valadoc_api_error_domain_construct (GType object_type,
                                    ValadocApiNode* parent,
                                    ValadocApiSourceFile* file,
                                    const gchar* name,
                                    ValaSymbolAccessibility accessibility,
                                    ValadocApiSourceComment* comment,
                                    ValaErrorDomain* data)
{
	ValadocApiErrorDomain * self = NULL;
	gchar* _tmp0_;
	gchar* _tmp1_;
	gchar* _tmp2_;
	gchar* _tmp3_;
	g_return_val_if_fail (parent != NULL, NULL);
	g_return_val_if_fail (file != NULL, NULL);
	g_return_val_if_fail (name != NULL, NULL);
	g_return_val_if_fail (data != NULL, NULL);
	self = (ValadocApiErrorDomain*) valadoc_api_typesymbol_construct (object_type, parent, file, name, accessibility, comment, FALSE, (ValaTypeSymbol*) data);
	_tmp0_ = _valadoc_api_error_domain_get_quark_function_name (self, data);
	_g_free0 (self->priv->quark_function_name);
	self->priv->quark_function_name = _tmp0_;
	_tmp1_ = _valadoc_api_error_domain_get_quark_macro_name (self, data);
	_g_free0 (self->priv->quark_macro_name);
	self->priv->quark_macro_name = _tmp1_;
	_tmp2_ = vala_gd_bus_module_get_dbus_name ((ValaTypeSymbol*) data);
	_g_free0 (self->priv->dbus_name);
	self->priv->dbus_name = _tmp2_;
	_tmp3_ = vala_get_ccode_name ((ValaCodeNode*) data);
	_g_free0 (self->priv->cname);
	self->priv->cname = _tmp3_;
	return self;
}

ValadocApiErrorDomain*
valadoc_api_error_domain_new (ValadocApiNode* parent,
                              ValadocApiSourceFile* file,
                              const gchar* name,
                              ValaSymbolAccessibility accessibility,
                              ValadocApiSourceComment* comment,
                              ValaErrorDomain* data)
{
	return valadoc_api_error_domain_construct (VALADOC_API_TYPE_ERROR_DOMAIN, parent, file, name, accessibility, comment, data);
}

static gchar*
_valadoc_api_error_domain_get_quark_function_name (ValadocApiErrorDomain* self,
                                                   ValaErrorDomain* element)
{
	gchar* _tmp0_;
	gchar* _tmp1_;
	gchar* _tmp2_;
	gchar* _tmp3_;
	gchar* result;
	g_return_val_if_fail (self != NULL, NULL);
	g_return_val_if_fail (element != NULL, NULL);
	_tmp0_ = vala_get_ccode_lower_case_prefix ((ValaSymbol*) element);
	_tmp1_ = _tmp0_;
	_tmp2_ = g_strconcat (_tmp1_, "quark", NULL);
	_tmp3_ = _tmp2_;
	_g_free0 (_tmp1_);
	result = _tmp3_;
	return result;
}

static gchar*
_valadoc_api_error_domain_get_quark_macro_name (ValadocApiErrorDomain* self,
                                                ValaErrorDomain* element)
{
	gchar* _tmp0_;
	gchar* result;
	g_return_val_if_fail (self != NULL, NULL);
	g_return_val_if_fail (element != NULL, NULL);
	_tmp0_ = vala_get_ccode_upper_case_name ((ValaSymbol*) element, NULL);
	result = _tmp0_;
	return result;
}

/**
 * Returns the name of this errordomain as it is used in C.
 */
gchar*
valadoc_api_error_domain_get_cname (ValadocApiErrorDomain* self)
{
	const gchar* _tmp0_;
	gchar* _tmp1_;
	gchar* result;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->cname;
	_tmp1_ = g_strdup (_tmp0_);
	result = _tmp1_;
	return result;
}

/**
 * Returns the dbus-name.
 */
gchar*
valadoc_api_error_domain_get_dbus_name (ValadocApiErrorDomain* self)
{
	const gchar* _tmp0_;
	gchar* _tmp1_;
	gchar* result;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->dbus_name;
	_tmp1_ = g_strdup (_tmp0_);
	result = _tmp1_;
	return result;
}

/**
 * Gets the name of the quark() function which represents the error domain
 */
gchar*
valadoc_api_error_domain_get_quark_function_name (ValadocApiErrorDomain* self)
{
	const gchar* _tmp0_;
	gchar* _tmp1_;
	gchar* result;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->quark_function_name;
	_tmp1_ = g_strdup (_tmp0_);
	result = _tmp1_;
	return result;
}

/**
 * Gets the name of the quark macro which represents the error domain
 */
gchar*
valadoc_api_error_domain_get_quark_macro_name (ValadocApiErrorDomain* self)
{
	const gchar* _tmp0_;
	gchar* _tmp1_;
	gchar* result;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->quark_macro_name;
	_tmp1_ = g_strdup (_tmp0_);
	result = _tmp1_;
	return result;
}

static ValadocApiNodeType
valadoc_api_error_domain_real_get_node_type (ValadocApiNode* base)
{
	ValadocApiNodeType result;
	ValadocApiErrorDomain* self;
	self = (ValadocApiErrorDomain*) base;
	result = VALADOC_API_NODE_TYPE_ERROR_DOMAIN;
	return result;
}

/**
 * {@inheritDoc}
 */
static void
valadoc_api_error_domain_real_accept (ValadocApiNode* base,
                                      ValadocApiVisitor* visitor)
{
	ValadocApiErrorDomain * self;
	self = (ValadocApiErrorDomain*) base;
	g_return_if_fail (visitor != NULL);
	valadoc_api_visitor_visit_error_domain (visitor, self);
}

/**
 * {@inheritDoc}
 */
static ValadocContentInline*
valadoc_api_error_domain_real_build_signature (ValadocApiItem* base)
{
	ValadocApiErrorDomain * self;
	ValadocApiSignatureBuilder* _tmp0_;
	ValadocApiSignatureBuilder* _tmp1_;
	ValaSymbolAccessibility _tmp2_;
	ValaSymbolAccessibility _tmp3_;
	const gchar* _tmp4_;
	ValadocApiSignatureBuilder* _tmp5_;
	ValadocApiSignatureBuilder* _tmp6_;
	ValadocApiSignatureBuilder* _tmp7_;
	ValadocContentRun* _tmp8_;
	ValadocContentInline* _tmp9_;
	ValadocContentInline* result;
	self = (ValadocApiErrorDomain*) base;
	_tmp0_ = valadoc_api_signature_builder_new ();
	_tmp1_ = _tmp0_;
	_tmp2_ = valadoc_api_symbol_get_accessibility ((ValadocApiSymbol*) self);
	_tmp3_ = _tmp2_;
	_tmp4_ = vala_symbol_accessibility_to_string (_tmp3_);
	_tmp5_ = valadoc_api_signature_builder_append_keyword (_tmp1_, _tmp4_, TRUE);
	_tmp6_ = valadoc_api_signature_builder_append_keyword (_tmp5_, "errordomain", TRUE);
	_tmp7_ = valadoc_api_signature_builder_append_symbol (_tmp6_, (ValadocApiNode*) self, TRUE);
	_tmp8_ = valadoc_api_signature_builder_get (_tmp7_);
	_tmp9_ = (ValadocContentInline*) _tmp8_;
	_valadoc_api_signature_builder_unref0 (_tmp1_);
	result = _tmp9_;
	return result;
}

static void
valadoc_api_error_domain_class_init (ValadocApiErrorDomainClass * klass,
                                     gpointer klass_data)
{
	valadoc_api_error_domain_parent_class = g_type_class_peek_parent (klass);
	g_type_class_adjust_private_offset (klass, &ValadocApiErrorDomain_private_offset);
	((ValadocApiNodeClass *) klass)->accept = (void (*) (ValadocApiNode*, ValadocApiVisitor*)) valadoc_api_error_domain_real_accept;
	((ValadocApiItemClass *) klass)->build_signature = (ValadocContentInline* (*) (ValadocApiItem*)) valadoc_api_error_domain_real_build_signature;
	VALADOC_API_NODE_CLASS (klass)->get_node_type = (ValadocApiNodeType (*) (ValadocApiNode*)) valadoc_api_error_domain_real_get_node_type;
	G_OBJECT_CLASS (klass)->get_property = _vala_valadoc_api_error_domain_get_property;
	G_OBJECT_CLASS (klass)->finalize = valadoc_api_error_domain_finalize;
	/**
	 * {@inheritDoc}
	 */
	g_object_class_install_property (G_OBJECT_CLASS (klass), VALADOC_API_ERROR_DOMAIN_NODE_TYPE_PROPERTY, valadoc_api_error_domain_properties[VALADOC_API_ERROR_DOMAIN_NODE_TYPE_PROPERTY] = g_param_spec_enum ("node-type", "node-type", "node-type", VALADOC_API_TYPE_NODE_TYPE, 0, G_PARAM_STATIC_STRINGS | G_PARAM_READABLE));
}

static void
valadoc_api_error_domain_instance_init (ValadocApiErrorDomain * self,
                                        gpointer klass)
{
	self->priv = valadoc_api_error_domain_get_instance_private (self);
}

static void
valadoc_api_error_domain_finalize (GObject * obj)
{
	ValadocApiErrorDomain * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, VALADOC_API_TYPE_ERROR_DOMAIN, ValadocApiErrorDomain);
	_g_free0 (self->priv->quark_function_name);
	_g_free0 (self->priv->quark_macro_name);
	_g_free0 (self->priv->dbus_name);
	_g_free0 (self->priv->cname);
	G_OBJECT_CLASS (valadoc_api_error_domain_parent_class)->finalize (obj);
}

/**
 * Represents an error domain declaration.
 */
static GType
valadoc_api_error_domain_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (ValadocApiErrorDomainClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) valadoc_api_error_domain_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (ValadocApiErrorDomain), 0, (GInstanceInitFunc) valadoc_api_error_domain_instance_init, NULL };
	GType valadoc_api_error_domain_type_id;
	valadoc_api_error_domain_type_id = g_type_register_static (VALADOC_API_TYPE_TYPESYMBOL, "ValadocApiErrorDomain", &g_define_type_info, 0);
	ValadocApiErrorDomain_private_offset = g_type_add_instance_private (valadoc_api_error_domain_type_id, sizeof (ValadocApiErrorDomainPrivate));
	return valadoc_api_error_domain_type_id;
}

GType
valadoc_api_error_domain_get_type (void)
{
	static volatile gsize valadoc_api_error_domain_type_id__once = 0;
	if (g_once_init_enter (&valadoc_api_error_domain_type_id__once)) {
		GType valadoc_api_error_domain_type_id;
		valadoc_api_error_domain_type_id = valadoc_api_error_domain_get_type_once ();
		g_once_init_leave (&valadoc_api_error_domain_type_id__once, valadoc_api_error_domain_type_id);
	}
	return valadoc_api_error_domain_type_id__once;
}

static void
_vala_valadoc_api_error_domain_get_property (GObject * object,
                                             guint property_id,
                                             GValue * value,
                                             GParamSpec * pspec)
{
	ValadocApiErrorDomain * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (object, VALADOC_API_TYPE_ERROR_DOMAIN, ValadocApiErrorDomain);
	switch (property_id) {
		case VALADOC_API_ERROR_DOMAIN_NODE_TYPE_PROPERTY:
		g_value_set_enum (value, valadoc_api_node_get_node_type ((ValadocApiNode*) self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}

