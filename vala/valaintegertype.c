/* valaintegertype.c generated by valac, the Vala compiler
 * generated from valaintegertype.vala, do not modify */

/* valaintegertype.vala
 *
 * Copyright (C) 2008-2009  Jürg Billeter
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.

 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.

 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301  USA
 *
 * Author:
 * 	Jürg Billeter <j@bitron.ch>
 */

#include "vala.h"
#include <stdlib.h>
#include <string.h>
#include <glib.h>
#include <glib-object.h>

#define _g_free0(var) (var = (g_free (var), NULL))
#define _vala_code_node_unref0(var) ((var == NULL) ? NULL : (var = (vala_code_node_unref (var), NULL)))

struct _ValaIntegerTypePrivate {
	gchar* literal_value;
	gchar* literal_type_name;
};

static gint ValaIntegerType_private_offset;
static gpointer vala_integer_type_parent_class = NULL;

static ValaDataType* vala_integer_type_real_copy (ValaDataType* base);
static gboolean vala_integer_type_real_compatible (ValaDataType* base,
                                            ValaDataType* target_type);
static void vala_integer_type_finalize (ValaCodeNode * obj);
static GType vala_integer_type_get_type_once (void);

static inline gpointer
vala_integer_type_get_instance_private (ValaIntegerType* self)
{
	return G_STRUCT_MEMBER_P (self, ValaIntegerType_private_offset);
}

ValaIntegerType*
vala_integer_type_construct (GType object_type,
                             ValaStruct* type_symbol,
                             const gchar* literal_value,
                             const gchar* literal_type_name,
                             ValaSourceReference* source_reference)
{
	ValaIntegerType* self = NULL;
	gchar* _tmp0_;
	gchar* _tmp1_;
	g_return_val_if_fail (type_symbol != NULL, NULL);
	self = (ValaIntegerType*) vala_value_type_construct (object_type, (ValaTypeSymbol*) type_symbol, source_reference);
	_tmp0_ = g_strdup (literal_value);
	_g_free0 (self->priv->literal_value);
	self->priv->literal_value = _tmp0_;
	_tmp1_ = g_strdup (literal_type_name);
	_g_free0 (self->priv->literal_type_name);
	self->priv->literal_type_name = _tmp1_;
	return self;
}

ValaIntegerType*
vala_integer_type_new (ValaStruct* type_symbol,
                       const gchar* literal_value,
                       const gchar* literal_type_name,
                       ValaSourceReference* source_reference)
{
	return vala_integer_type_construct (VALA_TYPE_INTEGER_TYPE, type_symbol, literal_value, literal_type_name, source_reference);
}

static ValaDataType*
vala_integer_type_real_copy (ValaDataType* base)
{
	ValaIntegerType * self;
	ValaIntegerType* _result_ = NULL;
	ValaTypeSymbol* _tmp0_;
	ValaTypeSymbol* _tmp1_;
	const gchar* _tmp2_;
	const gchar* _tmp3_;
	ValaSourceReference* _tmp4_;
	ValaSourceReference* _tmp5_;
	ValaIntegerType* _tmp6_;
	gboolean _tmp7_;
	gboolean _tmp8_;
	gboolean _tmp9_;
	gboolean _tmp10_;
	ValaDataType* result;
	self = (ValaIntegerType*) base;
	_tmp0_ = vala_data_type_get_type_symbol ((ValaDataType*) self);
	_tmp1_ = _tmp0_;
	_tmp2_ = self->priv->literal_value;
	_tmp3_ = self->priv->literal_type_name;
	_tmp4_ = vala_code_node_get_source_reference ((ValaCodeNode*) self);
	_tmp5_ = _tmp4_;
	_tmp6_ = vala_integer_type_new (G_TYPE_CHECK_INSTANCE_CAST (_tmp1_, VALA_TYPE_STRUCT, ValaStruct), _tmp2_, _tmp3_, _tmp5_);
	_result_ = _tmp6_;
	_tmp7_ = vala_data_type_get_value_owned ((ValaDataType*) self);
	_tmp8_ = _tmp7_;
	vala_data_type_set_value_owned ((ValaDataType*) _result_, _tmp8_);
	_tmp9_ = vala_data_type_get_nullable ((ValaDataType*) self);
	_tmp10_ = _tmp9_;
	vala_data_type_set_nullable ((ValaDataType*) _result_, _tmp10_);
	result = (ValaDataType*) _result_;
	return result;
}

static gpointer
_vala_code_node_ref0 (gpointer self)
{
	return self ? vala_code_node_ref (self) : NULL;
}

static gboolean
vala_integer_type_real_compatible (ValaDataType* base,
                                   ValaDataType* target_type)
{
	ValaIntegerType * self;
	gboolean _tmp0_ = FALSE;
	ValaTypeSymbol* _tmp1_;
	ValaTypeSymbol* _tmp2_;
	gboolean result;
	self = (ValaIntegerType*) base;
	g_return_val_if_fail (target_type != NULL, FALSE);
	_tmp1_ = vala_data_type_get_type_symbol (target_type);
	_tmp2_ = _tmp1_;
	if (VALA_IS_STRUCT (_tmp2_)) {
		const gchar* _tmp3_;
		_tmp3_ = self->priv->literal_type_name;
		_tmp0_ = g_strcmp0 (_tmp3_, "int") == 0;
	} else {
		_tmp0_ = FALSE;
	}
	if (_tmp0_) {
		ValaStruct* target_st = NULL;
		ValaTypeSymbol* _tmp4_;
		ValaTypeSymbol* _tmp5_;
		ValaStruct* _tmp6_;
		ValaStruct* _tmp7_;
		_tmp4_ = vala_data_type_get_type_symbol (target_type);
		_tmp5_ = _tmp4_;
		_tmp6_ = _vala_code_node_ref0 (G_TYPE_CHECK_INSTANCE_CAST (_tmp5_, VALA_TYPE_STRUCT, ValaStruct));
		target_st = _tmp6_;
		_tmp7_ = target_st;
		if (vala_struct_is_integer_type (_tmp7_)) {
			ValaAttribute* int_attr = NULL;
			ValaStruct* _tmp8_;
			ValaAttribute* _tmp9_;
			ValaAttribute* _tmp10_;
			gboolean _tmp11_ = FALSE;
			gboolean _tmp12_ = FALSE;
			ValaAttribute* _tmp13_;
			_tmp8_ = target_st;
			_tmp9_ = vala_code_node_get_attribute ((ValaCodeNode*) _tmp8_, "IntegerType");
			_tmp10_ = _vala_code_node_ref0 (_tmp9_);
			int_attr = _tmp10_;
			_tmp13_ = int_attr;
			if (_tmp13_ != NULL) {
				ValaAttribute* _tmp14_;
				_tmp14_ = int_attr;
				_tmp12_ = vala_attribute_has_argument (_tmp14_, "min");
			} else {
				_tmp12_ = FALSE;
			}
			if (_tmp12_) {
				ValaAttribute* _tmp15_;
				_tmp15_ = int_attr;
				_tmp11_ = vala_attribute_has_argument (_tmp15_, "max");
			} else {
				_tmp11_ = FALSE;
			}
			if (_tmp11_) {
				gint val = 0;
				const gchar* _tmp16_;
				gboolean _tmp17_ = FALSE;
				ValaAttribute* _tmp18_;
				_tmp16_ = self->priv->literal_value;
				val = atoi (_tmp16_);
				_tmp18_ = int_attr;
				if (val >= vala_attribute_get_integer (_tmp18_, "min", 0)) {
					ValaAttribute* _tmp19_;
					_tmp19_ = int_attr;
					_tmp17_ = val <= vala_attribute_get_integer (_tmp19_, "max", 0);
				} else {
					_tmp17_ = FALSE;
				}
				result = _tmp17_;
				_vala_code_node_unref0 (int_attr);
				_vala_code_node_unref0 (target_st);
				return result;
			} else {
				result = TRUE;
				_vala_code_node_unref0 (int_attr);
				_vala_code_node_unref0 (target_st);
				return result;
			}
			_vala_code_node_unref0 (int_attr);
		}
		_vala_code_node_unref0 (target_st);
	} else {
		gboolean _tmp20_ = FALSE;
		ValaTypeSymbol* _tmp21_;
		ValaTypeSymbol* _tmp22_;
		_tmp21_ = vala_data_type_get_type_symbol (target_type);
		_tmp22_ = _tmp21_;
		if (VALA_IS_ENUM (_tmp22_)) {
			gboolean _tmp23_ = FALSE;
			const gchar* _tmp24_;
			_tmp24_ = self->priv->literal_type_name;
			if (g_strcmp0 (_tmp24_, "int") == 0) {
				_tmp23_ = TRUE;
			} else {
				const gchar* _tmp25_;
				_tmp25_ = self->priv->literal_type_name;
				_tmp23_ = g_strcmp0 (_tmp25_, "uint") == 0;
			}
			_tmp20_ = _tmp23_;
		} else {
			_tmp20_ = FALSE;
		}
		if (_tmp20_) {
			const gchar* _tmp26_;
			_tmp26_ = self->priv->literal_value;
			if (atoi (_tmp26_) == 0) {
				result = TRUE;
				return result;
			}
		}
	}
	result = VALA_DATA_TYPE_CLASS (vala_integer_type_parent_class)->compatible ((ValaDataType*) G_TYPE_CHECK_INSTANCE_CAST (self, VALA_TYPE_VALUE_TYPE, ValaValueType), target_type);
	return result;
}

static void
vala_integer_type_class_init (ValaIntegerTypeClass * klass,
                              gpointer klass_data)
{
	vala_integer_type_parent_class = g_type_class_peek_parent (klass);
	((ValaCodeNodeClass *) klass)->finalize = vala_integer_type_finalize;
	g_type_class_adjust_private_offset (klass, &ValaIntegerType_private_offset);
	((ValaDataTypeClass *) klass)->copy = (ValaDataType* (*) (ValaDataType*)) vala_integer_type_real_copy;
	((ValaDataTypeClass *) klass)->compatible = (gboolean (*) (ValaDataType*, ValaDataType*)) vala_integer_type_real_compatible;
}

static void
vala_integer_type_instance_init (ValaIntegerType * self,
                                 gpointer klass)
{
	self->priv = vala_integer_type_get_instance_private (self);
}

static void
vala_integer_type_finalize (ValaCodeNode * obj)
{
	ValaIntegerType * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, VALA_TYPE_INTEGER_TYPE, ValaIntegerType);
	_g_free0 (self->priv->literal_value);
	_g_free0 (self->priv->literal_type_name);
	VALA_CODE_NODE_CLASS (vala_integer_type_parent_class)->finalize (obj);
}

/**
 * An integer type.
 */
static GType
vala_integer_type_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (ValaIntegerTypeClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) vala_integer_type_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (ValaIntegerType), 0, (GInstanceInitFunc) vala_integer_type_instance_init, NULL };
	GType vala_integer_type_type_id;
	vala_integer_type_type_id = g_type_register_static (VALA_TYPE_VALUE_TYPE, "ValaIntegerType", &g_define_type_info, 0);
	ValaIntegerType_private_offset = g_type_add_instance_private (vala_integer_type_type_id, sizeof (ValaIntegerTypePrivate));
	return vala_integer_type_type_id;
}

GType
vala_integer_type_get_type (void)
{
	static volatile gsize vala_integer_type_type_id__once = 0;
	if (g_once_init_enter (&vala_integer_type_type_id__once)) {
		GType vala_integer_type_type_id;
		vala_integer_type_type_id = vala_integer_type_get_type_once ();
		g_once_init_leave (&vala_integer_type_type_id__once, vala_integer_type_type_id);
	}
	return vala_integer_type_type_id__once;
}

