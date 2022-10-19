/* method.c generated by valac, the Vala compiler
 * generated from method.vala, do not modify */

/* method.vala
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
#include <vala.h>
#include <valacodegen.h>
#include <valagee.h>
#include <glib-object.h>

enum  {
	VALADOC_API_METHOD_0_PROPERTY,
	VALADOC_API_METHOD_IMPLICIT_ARRAY_LENGTH_CPARAMETER_NAME_PROPERTY,
	VALADOC_API_METHOD_BASE_METHOD_PROPERTY,
	VALADOC_API_METHOD_RETURN_TYPE_PROPERTY,
	VALADOC_API_METHOD_IS_YIELDS_PROPERTY,
	VALADOC_API_METHOD_IS_ABSTRACT_PROPERTY,
	VALADOC_API_METHOD_IS_VIRTUAL_PROPERTY,
	VALADOC_API_METHOD_IS_OVERRIDE_PROPERTY,
	VALADOC_API_METHOD_IS_STATIC_PROPERTY,
	VALADOC_API_METHOD_IS_CLASS_PROPERTY,
	VALADOC_API_METHOD_IS_CONSTRUCTOR_PROPERTY,
	VALADOC_API_METHOD_IS_INLINE_PROPERTY,
	VALADOC_API_METHOD_IS_DBUS_VISIBLE_PROPERTY,
	VALADOC_API_METHOD_NODE_TYPE_PROPERTY,
	VALADOC_API_METHOD_NUM_PROPERTIES
};
static GParamSpec* valadoc_api_method_properties[VALADOC_API_METHOD_NUM_PROPERTIES];
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _vala_iterable_unref0(var) ((var == NULL) ? NULL : (var = (vala_iterable_unref (var), NULL)))
#define _valadoc_api_signature_builder_unref0(var) ((var == NULL) ? NULL : (var = (valadoc_api_signature_builder_unref (var), NULL)))

struct _ValadocApiMethodPrivate {
	gchar* finish_function_cname;
	gchar* dbus_result_name;
	gchar* dbus_name;
	gchar* cname;
	gchar* _implicit_array_length_cparameter_name;
	ValadocApiMethod* _base_method;
	ValadocApiTypeReference* _return_type;
	gboolean _is_yields;
	gboolean _is_constructor;
	gboolean _is_dbus_visible;
};

static gint ValadocApiMethod_private_offset;
static gpointer valadoc_api_method_parent_class = NULL;
static ValadocApiCallableIface * valadoc_api_method_valadoc_api_callable_parent_iface = NULL;

static void valadoc_api_method_set_is_dbus_visible (ValadocApiMethod* self,
                                             gboolean value);
static void valadoc_api_method_set_is_constructor (ValadocApiMethod* self,
                                            gboolean value);
static void valadoc_api_method_set_is_yields (ValadocApiMethod* self,
                                       gboolean value);
static ValadocContentInline* valadoc_api_method_real_build_signature (ValadocApiItem* base);
static void valadoc_api_method_real_accept (ValadocApiNode* base,
                                     ValadocApiVisitor* visitor);
 G_GNUC_INTERNAL const gchar* valadoc_api_callable_get_implicit_array_length_cparameter_name (ValadocApiCallable* self);
 G_GNUC_INTERNAL void valadoc_api_callable_set_implicit_array_length_cparameter_name (ValadocApiCallable* self,
                                                                     const gchar* value);
static void valadoc_api_method_finalize (GObject * obj);
static GType valadoc_api_method_get_type_once (void);
static void _vala_valadoc_api_method_get_property (GObject * object,
                                            guint property_id,
                                            GValue * value,
                                            GParamSpec * pspec);
static void _vala_valadoc_api_method_set_property (GObject * object,
                                            guint property_id,
                                            const GValue * value,
                                            GParamSpec * pspec);

static inline gpointer
valadoc_api_method_get_instance_private (ValadocApiMethod* self)
{
	return G_STRUCT_MEMBER_P (self, ValadocApiMethod_private_offset);
}

static const gchar*
valadoc_api_method_real_get_implicit_array_length_cparameter_name (ValadocApiCallable* base)
{
	const gchar* result;
	ValadocApiMethod* self;
	const gchar* _tmp0_;
	self = (ValadocApiMethod*) base;
	_tmp0_ = self->priv->_implicit_array_length_cparameter_name;
	result = _tmp0_;
	return result;
}

static void
valadoc_api_method_real_set_implicit_array_length_cparameter_name (ValadocApiCallable* base,
                                                                   const gchar* value)
{
	ValadocApiMethod* self;
	gchar* old_value;
	self = (ValadocApiMethod*) base;
	old_value = valadoc_api_method_real_get_implicit_array_length_cparameter_name (base);
	if (g_strcmp0 (value, old_value) != 0) {
		gchar* _tmp0_;
		_tmp0_ = g_strdup (value);
		_g_free0 (self->priv->_implicit_array_length_cparameter_name);
		self->priv->_implicit_array_length_cparameter_name = _tmp0_;
		g_object_notify_by_pspec ((GObject *) self, valadoc_api_method_properties[VALADOC_API_METHOD_IMPLICIT_ARRAY_LENGTH_CPARAMETER_NAME_PROPERTY]);
	}
}

ValadocApiMethod*
valadoc_api_method_construct (GType object_type,
                              ValadocApiNode* parent,
                              ValadocApiSourceFile* file,
                              const gchar* name,
                              ValaSymbolAccessibility accessibility,
                              ValadocApiSourceComment* comment,
                              ValaMethod* data)
{
	ValadocApiMethod * self = NULL;
	gchar* _tmp0_ = NULL;
	gboolean _tmp1_;
	gboolean _tmp2_;
	gchar* _tmp4_;
	gchar* _tmp5_;
	gchar* _tmp6_;
	gchar* _tmp7_;
	gboolean _tmp8_;
	gboolean _tmp9_;
	g_return_val_if_fail (parent != NULL, NULL);
	g_return_val_if_fail (file != NULL, NULL);
	g_return_val_if_fail (name != NULL, NULL);
	g_return_val_if_fail (data != NULL, NULL);
	self = (ValadocApiMethod*) valadoc_api_symbol_construct (object_type, parent, file, name, accessibility, comment, (ValaSymbol*) data);
	_tmp1_ = vala_method_get_coroutine (data);
	_tmp2_ = _tmp1_;
	if (_tmp2_) {
		gchar* _tmp3_;
		_tmp3_ = vala_get_ccode_finish_name (data);
		_g_free0 (_tmp0_);
		_tmp0_ = _tmp3_;
	} else {
		_g_free0 (_tmp0_);
		_tmp0_ = NULL;
	}
	_tmp4_ = g_strdup (_tmp0_);
	_g_free0 (self->priv->finish_function_cname);
	self->priv->finish_function_cname = _tmp4_;
	_tmp5_ = vala_gd_bus_module_dbus_result_name (data);
	_g_free0 (self->priv->dbus_result_name);
	self->priv->dbus_result_name = _tmp5_;
	_tmp6_ = vala_gd_bus_module_get_dbus_name_for_member ((ValaSymbol*) data);
	_g_free0 (self->priv->dbus_name);
	self->priv->dbus_name = _tmp6_;
	_tmp7_ = vala_get_ccode_name ((ValaCodeNode*) data);
	_g_free0 (self->priv->cname);
	self->priv->cname = _tmp7_;
	valadoc_api_method_set_is_dbus_visible (self, vala_gd_bus_module_is_dbus_visible ((ValaCodeNode*) data));
	valadoc_api_method_set_is_constructor (self, G_TYPE_CHECK_INSTANCE_TYPE (data, VALA_TYPE_CREATION_METHOD));
	_tmp8_ = vala_method_get_coroutine (data);
	_tmp9_ = _tmp8_;
	valadoc_api_method_set_is_yields (self, _tmp9_);
	_g_free0 (_tmp0_);
	return self;
}

ValadocApiMethod*
valadoc_api_method_new (ValadocApiNode* parent,
                        ValadocApiSourceFile* file,
                        const gchar* name,
                        ValaSymbolAccessibility accessibility,
                        ValadocApiSourceComment* comment,
                        ValaMethod* data)
{
	return valadoc_api_method_construct (VALADOC_API_TYPE_METHOD, parent, file, name, accessibility, comment, data);
}

/**
 * Returns the name of this method as it is used in C.
 */
gchar*
valadoc_api_method_get_cname (ValadocApiMethod* self)
{
	const gchar* _tmp0_;
	gchar* _tmp1_;
	gchar* result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->cname;
	_tmp1_ = g_strdup (_tmp0_);
	result = _tmp1_;
	return result;
}

/**
 * Returns the name of the finish function as it is used in C.
 */
gchar*
valadoc_api_method_get_finish_function_cname (ValadocApiMethod* self)
{
	const gchar* _tmp0_;
	gchar* _tmp1_;
	gchar* result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->finish_function_cname;
	_tmp1_ = g_strdup (_tmp0_);
	result = _tmp1_;
	return result;
}

/**
 * Returns the dbus-name.
 */
gchar*
valadoc_api_method_get_dbus_name (ValadocApiMethod* self)
{
	const gchar* _tmp0_;
	gchar* _tmp1_;
	gchar* result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->dbus_name;
	_tmp1_ = g_strdup (_tmp0_);
	result = _tmp1_;
	return result;
}

gchar*
valadoc_api_method_get_dbus_result_name (ValadocApiMethod* self)
{
	const gchar* _tmp0_;
	gchar* _tmp1_;
	gchar* result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->dbus_result_name;
	_tmp1_ = g_strdup (_tmp0_);
	result = _tmp1_;
	return result;
}

ValadocApiMethod*
valadoc_api_method_get_base_method (ValadocApiMethod* self)
{
	ValadocApiMethod* result;
	ValadocApiMethod* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_base_method;
	result = _tmp0_;
	return result;
}

void
valadoc_api_method_set_base_method (ValadocApiMethod* self,
                                    ValadocApiMethod* value)
{
	ValadocApiMethod* old_value;
	g_return_if_fail (self != NULL);
	old_value = valadoc_api_method_get_base_method (self);
	if (old_value != value) {
		self->priv->_base_method = value;
		g_object_notify_by_pspec ((GObject *) self, valadoc_api_method_properties[VALADOC_API_METHOD_BASE_METHOD_PROPERTY]);
	}
}

static ValadocApiTypeReference*
valadoc_api_method_real_get_return_type (ValadocApiCallable* base)
{
	ValadocApiTypeReference* result;
	ValadocApiMethod* self;
	ValadocApiTypeReference* _tmp0_;
	self = (ValadocApiMethod*) base;
	_tmp0_ = self->priv->_return_type;
	result = _tmp0_;
	return result;
}

static gpointer
_g_object_ref0 (gpointer self)
{
	return self ? g_object_ref (self) : NULL;
}

static void
valadoc_api_method_real_set_return_type (ValadocApiCallable* base,
                                         ValadocApiTypeReference* value)
{
	ValadocApiMethod* self;
	ValadocApiTypeReference* old_value;
	self = (ValadocApiMethod*) base;
	old_value = valadoc_api_method_real_get_return_type (base);
	if (old_value != value) {
		ValadocApiTypeReference* _tmp0_;
		_tmp0_ = _g_object_ref0 (value);
		_g_object_unref0 (self->priv->_return_type);
		self->priv->_return_type = _tmp0_;
		g_object_notify_by_pspec ((GObject *) self, valadoc_api_method_properties[VALADOC_API_METHOD_RETURN_TYPE_PROPERTY]);
	}
}

gboolean
valadoc_api_method_get_is_yields (ValadocApiMethod* self)
{
	gboolean result;
	g_return_val_if_fail (self != NULL, FALSE);
	result = self->priv->_is_yields;
	return result;
}

static void
valadoc_api_method_set_is_yields (ValadocApiMethod* self,
                                  gboolean value)
{
	gboolean old_value;
	g_return_if_fail (self != NULL);
	old_value = valadoc_api_method_get_is_yields (self);
	if (old_value != value) {
		self->priv->_is_yields = value;
		g_object_notify_by_pspec ((GObject *) self, valadoc_api_method_properties[VALADOC_API_METHOD_IS_YIELDS_PROPERTY]);
	}
}

gboolean
valadoc_api_method_get_is_abstract (ValadocApiMethod* self)
{
	gboolean result;
	ValaCodeNode* _tmp0_;
	ValaCodeNode* _tmp1_;
	gboolean _tmp2_;
	gboolean _tmp3_;
	g_return_val_if_fail (self != NULL, FALSE);
	_tmp0_ = valadoc_api_item_get_data ((ValadocApiItem*) self);
	_tmp1_ = _tmp0_;
	_tmp2_ = vala_method_get_is_abstract (G_TYPE_CHECK_INSTANCE_CAST (_tmp1_, VALA_TYPE_METHOD, ValaMethod));
	_tmp3_ = _tmp2_;
	result = _tmp3_;
	return result;
}

gboolean
valadoc_api_method_get_is_virtual (ValadocApiMethod* self)
{
	gboolean result;
	ValaCodeNode* _tmp0_;
	ValaCodeNode* _tmp1_;
	gboolean _tmp2_;
	gboolean _tmp3_;
	g_return_val_if_fail (self != NULL, FALSE);
	_tmp0_ = valadoc_api_item_get_data ((ValadocApiItem*) self);
	_tmp1_ = _tmp0_;
	_tmp2_ = vala_method_get_is_virtual (G_TYPE_CHECK_INSTANCE_CAST (_tmp1_, VALA_TYPE_METHOD, ValaMethod));
	_tmp3_ = _tmp2_;
	result = _tmp3_;
	return result;
}

gboolean
valadoc_api_method_get_is_override (ValadocApiMethod* self)
{
	gboolean result;
	ValaCodeNode* _tmp0_;
	ValaCodeNode* _tmp1_;
	gboolean _tmp2_;
	gboolean _tmp3_;
	g_return_val_if_fail (self != NULL, FALSE);
	_tmp0_ = valadoc_api_item_get_data ((ValadocApiItem*) self);
	_tmp1_ = _tmp0_;
	_tmp2_ = vala_method_get_overrides (G_TYPE_CHECK_INSTANCE_CAST (_tmp1_, VALA_TYPE_METHOD, ValaMethod));
	_tmp3_ = _tmp2_;
	result = _tmp3_;
	return result;
}

gboolean
valadoc_api_method_get_is_static (ValadocApiMethod* self)
{
	gboolean result;
	gboolean _tmp0_ = FALSE;
	gboolean _tmp1_ = FALSE;
	gboolean _tmp2_;
	g_return_val_if_fail (self != NULL, FALSE);
	_tmp2_ = self->priv->_is_constructor;
	if (!_tmp2_) {
		ValaCodeNode* _tmp3_;
		ValaCodeNode* _tmp4_;
		ValaMemberBinding _tmp5_;
		ValaMemberBinding _tmp6_;
		_tmp3_ = valadoc_api_item_get_data ((ValadocApiItem*) self);
		_tmp4_ = _tmp3_;
		_tmp5_ = vala_method_get_binding (G_TYPE_CHECK_INSTANCE_CAST (_tmp4_, VALA_TYPE_METHOD, ValaMethod));
		_tmp6_ = _tmp5_;
		_tmp1_ = _tmp6_ == VALA_MEMBER_BINDING_STATIC;
	} else {
		_tmp1_ = FALSE;
	}
	if (_tmp1_) {
		ValadocApiItem* _tmp7_;
		ValadocApiItem* _tmp8_;
		_tmp7_ = valadoc_api_item_get_parent ((ValadocApiItem*) self);
		_tmp8_ = _tmp7_;
		_tmp0_ = VALADOC_API_IS_NAMESPACE (_tmp8_) == FALSE;
	} else {
		_tmp0_ = FALSE;
	}
	result = _tmp0_;
	return result;
}

gboolean
valadoc_api_method_get_is_class (ValadocApiMethod* self)
{
	gboolean result;
	ValaCodeNode* _tmp0_;
	ValaCodeNode* _tmp1_;
	ValaMemberBinding _tmp2_;
	ValaMemberBinding _tmp3_;
	g_return_val_if_fail (self != NULL, FALSE);
	_tmp0_ = valadoc_api_item_get_data ((ValadocApiItem*) self);
	_tmp1_ = _tmp0_;
	_tmp2_ = vala_method_get_binding (G_TYPE_CHECK_INSTANCE_CAST (_tmp1_, VALA_TYPE_METHOD, ValaMethod));
	_tmp3_ = _tmp2_;
	result = _tmp3_ == VALA_MEMBER_BINDING_CLASS;
	return result;
}

gboolean
valadoc_api_method_get_is_constructor (ValadocApiMethod* self)
{
	gboolean result;
	g_return_val_if_fail (self != NULL, FALSE);
	result = self->priv->_is_constructor;
	return result;
}

static void
valadoc_api_method_set_is_constructor (ValadocApiMethod* self,
                                       gboolean value)
{
	gboolean old_value;
	g_return_if_fail (self != NULL);
	old_value = valadoc_api_method_get_is_constructor (self);
	if (old_value != value) {
		self->priv->_is_constructor = value;
		g_object_notify_by_pspec ((GObject *) self, valadoc_api_method_properties[VALADOC_API_METHOD_IS_CONSTRUCTOR_PROPERTY]);
	}
}

gboolean
valadoc_api_method_get_is_inline (ValadocApiMethod* self)
{
	gboolean result;
	ValaCodeNode* _tmp0_;
	ValaCodeNode* _tmp1_;
	gboolean _tmp2_;
	gboolean _tmp3_;
	g_return_val_if_fail (self != NULL, FALSE);
	_tmp0_ = valadoc_api_item_get_data ((ValadocApiItem*) self);
	_tmp1_ = _tmp0_;
	_tmp2_ = vala_method_get_is_inline (G_TYPE_CHECK_INSTANCE_CAST (_tmp1_, VALA_TYPE_METHOD, ValaMethod));
	_tmp3_ = _tmp2_;
	result = _tmp3_;
	return result;
}

gboolean
valadoc_api_method_get_is_dbus_visible (ValadocApiMethod* self)
{
	gboolean result;
	g_return_val_if_fail (self != NULL, FALSE);
	result = self->priv->_is_dbus_visible;
	return result;
}

static void
valadoc_api_method_set_is_dbus_visible (ValadocApiMethod* self,
                                        gboolean value)
{
	gboolean old_value;
	g_return_if_fail (self != NULL);
	old_value = valadoc_api_method_get_is_dbus_visible (self);
	if (old_value != value) {
		self->priv->_is_dbus_visible = value;
		g_object_notify_by_pspec ((GObject *) self, valadoc_api_method_properties[VALADOC_API_METHOD_IS_DBUS_VISIBLE_PROPERTY]);
	}
}

/**
 * {@inheritDoc}
 */
static ValadocContentInline*
valadoc_api_method_real_build_signature (ValadocApiItem* base)
{
	ValadocApiMethod * self;
	ValadocApiSignatureBuilder* signature = NULL;
	ValadocApiSignatureBuilder* _tmp0_;
	ValadocApiSignatureBuilder* _tmp1_;
	ValaSymbolAccessibility _tmp2_;
	ValaSymbolAccessibility _tmp3_;
	const gchar* _tmp4_;
	gboolean _tmp5_;
	gboolean _tmp24_;
	gboolean _tmp26_;
	ValadocApiSignatureBuilder* _tmp32_;
	ValaList* type_parameters = NULL;
	ValaList* _tmp33_;
	ValaList* _tmp34_;
	gint _tmp35_;
	gint _tmp36_;
	ValadocApiSignatureBuilder* _tmp52_;
	gboolean first = FALSE;
	ValadocApiSignatureBuilder* _tmp66_;
	ValaList* exceptions = NULL;
	ValadocApiNodeType* _tmp67_;
	ValadocApiNodeType* _tmp68_;
	gint _tmp68__length1;
	ValaList* _tmp69_;
	ValaList* _tmp70_;
	ValaList* _tmp71_;
	gint _tmp72_;
	gint _tmp73_;
	ValadocApiSignatureBuilder* _tmp86_;
	ValadocContentRun* _tmp87_;
	ValadocContentInline* result = NULL;
	self = (ValadocApiMethod*) base;
	_tmp0_ = valadoc_api_signature_builder_new ();
	signature = _tmp0_;
	_tmp1_ = signature;
	_tmp2_ = valadoc_api_symbol_get_accessibility ((ValadocApiSymbol*) self);
	_tmp3_ = _tmp2_;
	_tmp4_ = vala_symbol_accessibility_to_string (_tmp3_);
	valadoc_api_signature_builder_append_keyword (_tmp1_, _tmp4_, TRUE);
	_tmp5_ = self->priv->_is_constructor;
	if (!_tmp5_) {
		gboolean _tmp6_;
		gboolean _tmp7_;
		gboolean _tmp21_;
		gboolean _tmp22_;
		_tmp6_ = valadoc_api_method_get_is_static (self);
		_tmp7_ = _tmp6_;
		if (_tmp7_) {
			ValadocApiSignatureBuilder* _tmp8_;
			_tmp8_ = signature;
			valadoc_api_signature_builder_append_keyword (_tmp8_, "static", TRUE);
		} else {
			gboolean _tmp9_;
			gboolean _tmp10_;
			_tmp9_ = valadoc_api_method_get_is_class (self);
			_tmp10_ = _tmp9_;
			if (_tmp10_) {
				ValadocApiSignatureBuilder* _tmp11_;
				_tmp11_ = signature;
				valadoc_api_signature_builder_append_keyword (_tmp11_, "class", TRUE);
			} else {
				gboolean _tmp12_;
				gboolean _tmp13_;
				_tmp12_ = valadoc_api_method_get_is_abstract (self);
				_tmp13_ = _tmp12_;
				if (_tmp13_) {
					ValadocApiSignatureBuilder* _tmp14_;
					_tmp14_ = signature;
					valadoc_api_signature_builder_append_keyword (_tmp14_, "abstract", TRUE);
				} else {
					gboolean _tmp15_;
					gboolean _tmp16_;
					_tmp15_ = valadoc_api_method_get_is_override (self);
					_tmp16_ = _tmp15_;
					if (_tmp16_) {
						ValadocApiSignatureBuilder* _tmp17_;
						_tmp17_ = signature;
						valadoc_api_signature_builder_append_keyword (_tmp17_, "override", TRUE);
					} else {
						gboolean _tmp18_;
						gboolean _tmp19_;
						_tmp18_ = valadoc_api_method_get_is_virtual (self);
						_tmp19_ = _tmp18_;
						if (_tmp19_) {
							ValadocApiSignatureBuilder* _tmp20_;
							_tmp20_ = signature;
							valadoc_api_signature_builder_append_keyword (_tmp20_, "virtual", TRUE);
						}
					}
				}
			}
		}
		_tmp21_ = valadoc_api_method_get_is_inline (self);
		_tmp22_ = _tmp21_;
		if (_tmp22_) {
			ValadocApiSignatureBuilder* _tmp23_;
			_tmp23_ = signature;
			valadoc_api_signature_builder_append_keyword (_tmp23_, "inline", TRUE);
		}
	}
	_tmp24_ = self->priv->_is_yields;
	if (_tmp24_) {
		ValadocApiSignatureBuilder* _tmp25_;
		_tmp25_ = signature;
		valadoc_api_signature_builder_append_keyword (_tmp25_, "async", TRUE);
	}
	_tmp26_ = self->priv->_is_constructor;
	if (!_tmp26_) {
		ValadocApiSignatureBuilder* _tmp27_;
		ValadocApiTypeReference* _tmp28_;
		ValadocApiTypeReference* _tmp29_;
		ValadocContentInline* _tmp30_;
		ValadocContentInline* _tmp31_;
		_tmp27_ = signature;
		_tmp28_ = valadoc_api_callable_get_return_type ((ValadocApiCallable*) self);
		_tmp29_ = _tmp28_;
		_tmp30_ = valadoc_api_item_get_signature ((ValadocApiItem*) _tmp29_);
		_tmp31_ = _tmp30_;
		valadoc_api_signature_builder_append_content (_tmp27_, _tmp31_, TRUE);
	}
	_tmp32_ = signature;
	valadoc_api_signature_builder_append_symbol (_tmp32_, (ValadocApiNode*) self, TRUE);
	_tmp33_ = valadoc_api_node_get_children_by_type ((ValadocApiNode*) self, VALADOC_API_NODE_TYPE_TYPE_PARAMETER, FALSE);
	type_parameters = _tmp33_;
	_tmp34_ = type_parameters;
	_tmp35_ = vala_collection_get_size ((ValaCollection*) _tmp34_);
	_tmp36_ = _tmp35_;
	if (_tmp36_ > 0) {
		ValadocApiSignatureBuilder* _tmp37_;
		gboolean first = FALSE;
		ValadocApiSignatureBuilder* _tmp51_;
		_tmp37_ = signature;
		valadoc_api_signature_builder_append (_tmp37_, "<", FALSE);
		first = TRUE;
		{
			ValaList* _param_list = NULL;
			ValaList* _tmp38_;
			gint _param_size = 0;
			ValaList* _tmp39_;
			gint _tmp40_;
			gint _tmp41_;
			gint _param_index = 0;
			_tmp38_ = type_parameters;
			_param_list = _tmp38_;
			_tmp39_ = _param_list;
			_tmp40_ = vala_collection_get_size ((ValaCollection*) _tmp39_);
			_tmp41_ = _tmp40_;
			_param_size = _tmp41_;
			_param_index = -1;
			while (TRUE) {
				gint _tmp42_;
				gint _tmp43_;
				ValadocApiItem* param = NULL;
				ValaList* _tmp44_;
				gpointer _tmp45_;
				ValadocApiSignatureBuilder* _tmp47_;
				ValadocApiItem* _tmp48_;
				ValadocContentInline* _tmp49_;
				ValadocContentInline* _tmp50_;
				_param_index = _param_index + 1;
				_tmp42_ = _param_index;
				_tmp43_ = _param_size;
				if (!(_tmp42_ < _tmp43_)) {
					break;
				}
				_tmp44_ = _param_list;
				_tmp45_ = vala_list_get (_tmp44_, _param_index);
				param = (ValadocApiItem*) ((ValadocApiNode*) _tmp45_);
				if (!first) {
					ValadocApiSignatureBuilder* _tmp46_;
					_tmp46_ = signature;
					valadoc_api_signature_builder_append (_tmp46_, ",", FALSE);
				}
				_tmp47_ = signature;
				_tmp48_ = param;
				_tmp49_ = valadoc_api_item_get_signature (_tmp48_);
				_tmp50_ = _tmp49_;
				valadoc_api_signature_builder_append_content (_tmp47_, _tmp50_, FALSE);
				first = FALSE;
				_g_object_unref0 (param);
			}
		}
		_tmp51_ = signature;
		valadoc_api_signature_builder_append (_tmp51_, ">", FALSE);
	}
	_tmp52_ = signature;
	valadoc_api_signature_builder_append (_tmp52_, "(", TRUE);
	first = TRUE;
	{
		ValaList* _param_list = NULL;
		ValaList* _tmp53_;
		gint _param_size = 0;
		ValaList* _tmp54_;
		gint _tmp55_;
		gint _tmp56_;
		gint _param_index = 0;
		_tmp53_ = valadoc_api_node_get_children_by_type ((ValadocApiNode*) self, VALADOC_API_NODE_TYPE_FORMAL_PARAMETER, FALSE);
		_param_list = _tmp53_;
		_tmp54_ = _param_list;
		_tmp55_ = vala_collection_get_size ((ValaCollection*) _tmp54_);
		_tmp56_ = _tmp55_;
		_param_size = _tmp56_;
		_param_index = -1;
		while (TRUE) {
			gint _tmp57_;
			gint _tmp58_;
			ValadocApiNode* param = NULL;
			ValaList* _tmp59_;
			gpointer _tmp60_;
			ValadocApiSignatureBuilder* _tmp62_;
			ValadocApiNode* _tmp63_;
			ValadocContentInline* _tmp64_;
			ValadocContentInline* _tmp65_;
			_param_index = _param_index + 1;
			_tmp57_ = _param_index;
			_tmp58_ = _param_size;
			if (!(_tmp57_ < _tmp58_)) {
				break;
			}
			_tmp59_ = _param_list;
			_tmp60_ = vala_list_get (_tmp59_, _param_index);
			param = (ValadocApiNode*) _tmp60_;
			if (!first) {
				ValadocApiSignatureBuilder* _tmp61_;
				_tmp61_ = signature;
				valadoc_api_signature_builder_append (_tmp61_, ",", FALSE);
			}
			_tmp62_ = signature;
			_tmp63_ = param;
			_tmp64_ = valadoc_api_item_get_signature ((ValadocApiItem*) _tmp63_);
			_tmp65_ = _tmp64_;
			valadoc_api_signature_builder_append_content (_tmp62_, _tmp65_, !first);
			first = FALSE;
			_g_object_unref0 (param);
		}
		_vala_iterable_unref0 (_param_list);
	}
	_tmp66_ = signature;
	valadoc_api_signature_builder_append (_tmp66_, ")", FALSE);
	_tmp67_ = g_new0 (ValadocApiNodeType, 2);
	_tmp67_[0] = VALADOC_API_NODE_TYPE_ERROR_DOMAIN;
	_tmp67_[1] = VALADOC_API_NODE_TYPE_CLASS;
	_tmp68_ = _tmp67_;
	_tmp68__length1 = 2;
	_tmp69_ = valadoc_api_node_get_children_by_types ((ValadocApiNode*) self, _tmp68_, (gint) 2, TRUE);
	_tmp70_ = _tmp69_;
	_tmp68_ = (g_free (_tmp68_), NULL);
	exceptions = _tmp70_;
	_tmp71_ = exceptions;
	_tmp72_ = vala_collection_get_size ((ValaCollection*) _tmp71_);
	_tmp73_ = _tmp72_;
	if (_tmp73_ > 0) {
		ValadocApiSignatureBuilder* _tmp74_;
		_tmp74_ = signature;
		valadoc_api_signature_builder_append_keyword (_tmp74_, "throws", TRUE);
		first = TRUE;
		{
			ValaList* _param_list = NULL;
			ValaList* _tmp75_;
			gint _param_size = 0;
			ValaList* _tmp76_;
			gint _tmp77_;
			gint _tmp78_;
			gint _param_index = 0;
			_tmp75_ = exceptions;
			_param_list = _tmp75_;
			_tmp76_ = _param_list;
			_tmp77_ = vala_collection_get_size ((ValaCollection*) _tmp76_);
			_tmp78_ = _tmp77_;
			_param_size = _tmp78_;
			_param_index = -1;
			while (TRUE) {
				gint _tmp79_;
				gint _tmp80_;
				ValadocApiNode* param = NULL;
				ValaList* _tmp81_;
				gpointer _tmp82_;
				ValadocApiSignatureBuilder* _tmp84_;
				ValadocApiNode* _tmp85_;
				_param_index = _param_index + 1;
				_tmp79_ = _param_index;
				_tmp80_ = _param_size;
				if (!(_tmp79_ < _tmp80_)) {
					break;
				}
				_tmp81_ = _param_list;
				_tmp82_ = vala_list_get (_tmp81_, _param_index);
				param = (ValadocApiNode*) _tmp82_;
				if (!first) {
					ValadocApiSignatureBuilder* _tmp83_;
					_tmp83_ = signature;
					valadoc_api_signature_builder_append (_tmp83_, ",", FALSE);
				}
				_tmp84_ = signature;
				_tmp85_ = param;
				valadoc_api_signature_builder_append_type (_tmp84_, _tmp85_, TRUE);
				first = FALSE;
				_g_object_unref0 (param);
			}
		}
	}
	_tmp86_ = signature;
	_tmp87_ = valadoc_api_signature_builder_get (_tmp86_);
	result = (ValadocContentInline*) _tmp87_;
	_vala_iterable_unref0 (exceptions);
	_vala_iterable_unref0 (type_parameters);
	_valadoc_api_signature_builder_unref0 (signature);
	return result;
}

static ValadocApiNodeType
valadoc_api_method_real_get_node_type (ValadocApiNode* base)
{
	ValadocApiNodeType result;
	ValadocApiMethod* self;
	ValadocApiNodeType _tmp0_ = 0;
	gboolean _tmp1_;
	self = (ValadocApiMethod*) base;
	_tmp1_ = self->priv->_is_constructor;
	if (_tmp1_) {
		_tmp0_ = VALADOC_API_NODE_TYPE_CREATION_METHOD;
	} else {
		ValadocApiNodeType _tmp2_ = 0;
		gboolean _tmp3_;
		gboolean _tmp4_;
		_tmp3_ = valadoc_api_method_get_is_static (self);
		_tmp4_ = _tmp3_;
		if (_tmp4_) {
			_tmp2_ = VALADOC_API_NODE_TYPE_STATIC_METHOD;
		} else {
			_tmp2_ = VALADOC_API_NODE_TYPE_METHOD;
		}
		_tmp0_ = _tmp2_;
	}
	result = _tmp0_;
	return result;
}

/**
 * {@inheritDoc}
 */
static void
valadoc_api_method_real_accept (ValadocApiNode* base,
                                ValadocApiVisitor* visitor)
{
	ValadocApiMethod * self;
	self = (ValadocApiMethod*) base;
	g_return_if_fail (visitor != NULL);
	valadoc_api_visitor_visit_method (visitor, self);
}

static void
valadoc_api_method_class_init (ValadocApiMethodClass * klass,
                               gpointer klass_data)
{
	valadoc_api_method_parent_class = g_type_class_peek_parent (klass);
	g_type_class_adjust_private_offset (klass, &ValadocApiMethod_private_offset);
	((ValadocApiItemClass *) klass)->build_signature = (ValadocContentInline* (*) (ValadocApiItem*)) valadoc_api_method_real_build_signature;
	((ValadocApiNodeClass *) klass)->accept = (void (*) (ValadocApiNode*, ValadocApiVisitor*)) valadoc_api_method_real_accept;
	VALADOC_API_NODE_CLASS (klass)->get_node_type = valadoc_api_method_real_get_node_type;
	G_OBJECT_CLASS (klass)->get_property = _vala_valadoc_api_method_get_property;
	G_OBJECT_CLASS (klass)->set_property = _vala_valadoc_api_method_set_property;
	G_OBJECT_CLASS (klass)->finalize = valadoc_api_method_finalize;
	/**
	 * {@inheritDoc}
	 */
	g_object_class_install_property (G_OBJECT_CLASS (klass), VALADOC_API_METHOD_IMPLICIT_ARRAY_LENGTH_CPARAMETER_NAME_PROPERTY, valadoc_api_method_properties[VALADOC_API_METHOD_IMPLICIT_ARRAY_LENGTH_CPARAMETER_NAME_PROPERTY] = g_param_spec_string ("implicit-array-length-cparameter-name", "implicit-array-length-cparameter-name", "implicit-array-length-cparameter-name", NULL, G_PARAM_STATIC_STRINGS | G_PARAM_READABLE | G_PARAM_WRITABLE));
	/**
	 * Specifies the virtual or abstract method this method overrides.
	 */
	g_object_class_install_property (G_OBJECT_CLASS (klass), VALADOC_API_METHOD_BASE_METHOD_PROPERTY, valadoc_api_method_properties[VALADOC_API_METHOD_BASE_METHOD_PROPERTY] = g_param_spec_object ("base-method", "base-method", "base-method", VALADOC_API_TYPE_METHOD, G_PARAM_STATIC_STRINGS | G_PARAM_READABLE | G_PARAM_WRITABLE));
	/**
	 * {@inheritDoc}
	 */
	g_object_class_install_property (G_OBJECT_CLASS (klass), VALADOC_API_METHOD_RETURN_TYPE_PROPERTY, valadoc_api_method_properties[VALADOC_API_METHOD_RETURN_TYPE_PROPERTY] = g_param_spec_object ("return-type", "return-type", "return-type", VALADOC_API_TYPE_TYPEREFERENCE, G_PARAM_STATIC_STRINGS | G_PARAM_READABLE | G_PARAM_WRITABLE));
	/**
	 * Specifies whether this method is asynchronous
	 */
	g_object_class_install_property (G_OBJECT_CLASS (klass), VALADOC_API_METHOD_IS_YIELDS_PROPERTY, valadoc_api_method_properties[VALADOC_API_METHOD_IS_YIELDS_PROPERTY] = g_param_spec_boolean ("is-yields", "is-yields", "is-yields", FALSE, G_PARAM_STATIC_STRINGS | G_PARAM_READABLE));
	/**
	 * Specifies whether this method is abstract
	 */
	g_object_class_install_property (G_OBJECT_CLASS (klass), VALADOC_API_METHOD_IS_ABSTRACT_PROPERTY, valadoc_api_method_properties[VALADOC_API_METHOD_IS_ABSTRACT_PROPERTY] = g_param_spec_boolean ("is-abstract", "is-abstract", "is-abstract", FALSE, G_PARAM_STATIC_STRINGS | G_PARAM_READABLE));
	/**
	 * Specifies whether this method is virtual
	 */
	g_object_class_install_property (G_OBJECT_CLASS (klass), VALADOC_API_METHOD_IS_VIRTUAL_PROPERTY, valadoc_api_method_properties[VALADOC_API_METHOD_IS_VIRTUAL_PROPERTY] = g_param_spec_boolean ("is-virtual", "is-virtual", "is-virtual", FALSE, G_PARAM_STATIC_STRINGS | G_PARAM_READABLE));
	/**
	 * Specifies whether this method overrides another one
	 */
	g_object_class_install_property (G_OBJECT_CLASS (klass), VALADOC_API_METHOD_IS_OVERRIDE_PROPERTY, valadoc_api_method_properties[VALADOC_API_METHOD_IS_OVERRIDE_PROPERTY] = g_param_spec_boolean ("is-override", "is-override", "is-override", FALSE, G_PARAM_STATIC_STRINGS | G_PARAM_READABLE));
	/**
	 * Specifies whether this method is static
	 */
	g_object_class_install_property (G_OBJECT_CLASS (klass), VALADOC_API_METHOD_IS_STATIC_PROPERTY, valadoc_api_method_properties[VALADOC_API_METHOD_IS_STATIC_PROPERTY] = g_param_spec_boolean ("is-static", "is-static", "is-static", FALSE, G_PARAM_STATIC_STRINGS | G_PARAM_READABLE));
	/**
	 * Specifies whether this method is a class method
	 */
	g_object_class_install_property (G_OBJECT_CLASS (klass), VALADOC_API_METHOD_IS_CLASS_PROPERTY, valadoc_api_method_properties[VALADOC_API_METHOD_IS_CLASS_PROPERTY] = g_param_spec_boolean ("is-class", "is-class", "is-class", FALSE, G_PARAM_STATIC_STRINGS | G_PARAM_READABLE));
	/**
	 * Specifies whether this method is a creation method
	 */
	g_object_class_install_property (G_OBJECT_CLASS (klass), VALADOC_API_METHOD_IS_CONSTRUCTOR_PROPERTY, valadoc_api_method_properties[VALADOC_API_METHOD_IS_CONSTRUCTOR_PROPERTY] = g_param_spec_boolean ("is-constructor", "is-constructor", "is-constructor", FALSE, G_PARAM_STATIC_STRINGS | G_PARAM_READABLE));
	/**
	 * Specifies whether this method is inline
	 */
	g_object_class_install_property (G_OBJECT_CLASS (klass), VALADOC_API_METHOD_IS_INLINE_PROPERTY, valadoc_api_method_properties[VALADOC_API_METHOD_IS_INLINE_PROPERTY] = g_param_spec_boolean ("is-inline", "is-inline", "is-inline", FALSE, G_PARAM_STATIC_STRINGS | G_PARAM_READABLE));
	/**
	 * Specifies whether this method is visible for dbus
	 */
	g_object_class_install_property (G_OBJECT_CLASS (klass), VALADOC_API_METHOD_IS_DBUS_VISIBLE_PROPERTY, valadoc_api_method_properties[VALADOC_API_METHOD_IS_DBUS_VISIBLE_PROPERTY] = g_param_spec_boolean ("is-dbus-visible", "is-dbus-visible", "is-dbus-visible", FALSE, G_PARAM_STATIC_STRINGS | G_PARAM_READABLE));
	/**
	 * {@inheritDoc}
	 */
	g_object_class_install_property (G_OBJECT_CLASS (klass), VALADOC_API_METHOD_NODE_TYPE_PROPERTY, valadoc_api_method_properties[VALADOC_API_METHOD_NODE_TYPE_PROPERTY] = g_param_spec_enum ("node-type", "node-type", "node-type", VALADOC_API_TYPE_NODE_TYPE, 0, G_PARAM_STATIC_STRINGS | G_PARAM_READABLE));
}

static void
valadoc_api_method_valadoc_api_callable_interface_init (ValadocApiCallableIface * iface,
                                                        gpointer iface_data)
{
	valadoc_api_method_valadoc_api_callable_parent_iface = g_type_interface_peek_parent (iface);
	iface->get_implicit_array_length_cparameter_name = valadoc_api_method_real_get_implicit_array_length_cparameter_name;
	iface->set_implicit_array_length_cparameter_name = valadoc_api_method_real_set_implicit_array_length_cparameter_name;
	iface->get_return_type = valadoc_api_method_real_get_return_type;
	iface->set_return_type = valadoc_api_method_real_set_return_type;
}

static void
valadoc_api_method_instance_init (ValadocApiMethod * self,
                                  gpointer klass)
{
	self->priv = valadoc_api_method_get_instance_private (self);
}

static void
valadoc_api_method_finalize (GObject * obj)
{
	ValadocApiMethod * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, VALADOC_API_TYPE_METHOD, ValadocApiMethod);
	_g_free0 (self->priv->finish_function_cname);
	_g_free0 (self->priv->dbus_result_name);
	_g_free0 (self->priv->dbus_name);
	_g_free0 (self->priv->cname);
	_g_free0 (self->priv->_implicit_array_length_cparameter_name);
	_g_object_unref0 (self->priv->_return_type);
	G_OBJECT_CLASS (valadoc_api_method_parent_class)->finalize (obj);
}

/**
 * Represents a function or a method.
 */
static GType
valadoc_api_method_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (ValadocApiMethodClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) valadoc_api_method_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (ValadocApiMethod), 0, (GInstanceInitFunc) valadoc_api_method_instance_init, NULL };
	static const GInterfaceInfo valadoc_api_callable_info = { (GInterfaceInitFunc) valadoc_api_method_valadoc_api_callable_interface_init, (GInterfaceFinalizeFunc) NULL, NULL};
	GType valadoc_api_method_type_id;
	valadoc_api_method_type_id = g_type_register_static (VALADOC_API_TYPE_SYMBOL, "ValadocApiMethod", &g_define_type_info, 0);
	g_type_add_interface_static (valadoc_api_method_type_id, VALADOC_API_TYPE_CALLABLE, &valadoc_api_callable_info);
	ValadocApiMethod_private_offset = g_type_add_instance_private (valadoc_api_method_type_id, sizeof (ValadocApiMethodPrivate));
	return valadoc_api_method_type_id;
}

GType
valadoc_api_method_get_type (void)
{
	static volatile gsize valadoc_api_method_type_id__volatile = 0;
	if (g_once_init_enter (&valadoc_api_method_type_id__volatile)) {
		GType valadoc_api_method_type_id;
		valadoc_api_method_type_id = valadoc_api_method_get_type_once ();
		g_once_init_leave (&valadoc_api_method_type_id__volatile, valadoc_api_method_type_id);
	}
	return valadoc_api_method_type_id__volatile;
}

static void
_vala_valadoc_api_method_get_property (GObject * object,
                                       guint property_id,
                                       GValue * value,
                                       GParamSpec * pspec)
{
	ValadocApiMethod * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (object, VALADOC_API_TYPE_METHOD, ValadocApiMethod);
	switch (property_id) {
		case VALADOC_API_METHOD_IMPLICIT_ARRAY_LENGTH_CPARAMETER_NAME_PROPERTY:
		g_value_set_string (value, valadoc_api_callable_get_implicit_array_length_cparameter_name ((ValadocApiCallable*) self));
		break;
		case VALADOC_API_METHOD_BASE_METHOD_PROPERTY:
		g_value_set_object (value, valadoc_api_method_get_base_method (self));
		break;
		case VALADOC_API_METHOD_RETURN_TYPE_PROPERTY:
		g_value_set_object (value, valadoc_api_callable_get_return_type ((ValadocApiCallable*) self));
		break;
		case VALADOC_API_METHOD_IS_YIELDS_PROPERTY:
		g_value_set_boolean (value, valadoc_api_method_get_is_yields (self));
		break;
		case VALADOC_API_METHOD_IS_ABSTRACT_PROPERTY:
		g_value_set_boolean (value, valadoc_api_method_get_is_abstract (self));
		break;
		case VALADOC_API_METHOD_IS_VIRTUAL_PROPERTY:
		g_value_set_boolean (value, valadoc_api_method_get_is_virtual (self));
		break;
		case VALADOC_API_METHOD_IS_OVERRIDE_PROPERTY:
		g_value_set_boolean (value, valadoc_api_method_get_is_override (self));
		break;
		case VALADOC_API_METHOD_IS_STATIC_PROPERTY:
		g_value_set_boolean (value, valadoc_api_method_get_is_static (self));
		break;
		case VALADOC_API_METHOD_IS_CLASS_PROPERTY:
		g_value_set_boolean (value, valadoc_api_method_get_is_class (self));
		break;
		case VALADOC_API_METHOD_IS_CONSTRUCTOR_PROPERTY:
		g_value_set_boolean (value, valadoc_api_method_get_is_constructor (self));
		break;
		case VALADOC_API_METHOD_IS_INLINE_PROPERTY:
		g_value_set_boolean (value, valadoc_api_method_get_is_inline (self));
		break;
		case VALADOC_API_METHOD_IS_DBUS_VISIBLE_PROPERTY:
		g_value_set_boolean (value, valadoc_api_method_get_is_dbus_visible (self));
		break;
		case VALADOC_API_METHOD_NODE_TYPE_PROPERTY:
		g_value_set_enum (value, valadoc_api_node_get_node_type ((ValadocApiNode*) self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}

static void
_vala_valadoc_api_method_set_property (GObject * object,
                                       guint property_id,
                                       const GValue * value,
                                       GParamSpec * pspec)
{
	ValadocApiMethod * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (object, VALADOC_API_TYPE_METHOD, ValadocApiMethod);
	switch (property_id) {
		case VALADOC_API_METHOD_IMPLICIT_ARRAY_LENGTH_CPARAMETER_NAME_PROPERTY:
		valadoc_api_callable_set_implicit_array_length_cparameter_name ((ValadocApiCallable*) self, g_value_get_string (value));
		break;
		case VALADOC_API_METHOD_BASE_METHOD_PROPERTY:
		valadoc_api_method_set_base_method (self, g_value_get_object (value));
		break;
		case VALADOC_API_METHOD_RETURN_TYPE_PROPERTY:
		valadoc_api_callable_set_return_type ((ValadocApiCallable*) self, g_value_get_object (value));
		break;
		case VALADOC_API_METHOD_IS_YIELDS_PROPERTY:
		valadoc_api_method_set_is_yields (self, g_value_get_boolean (value));
		break;
		case VALADOC_API_METHOD_IS_CONSTRUCTOR_PROPERTY:
		valadoc_api_method_set_is_constructor (self, g_value_get_boolean (value));
		break;
		case VALADOC_API_METHOD_IS_DBUS_VISIBLE_PROPERTY:
		valadoc_api_method_set_is_dbus_visible (self, g_value_get_boolean (value));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}
