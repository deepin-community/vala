/* valasignaltype.c generated by valac, the Vala compiler
 * generated from valasignaltype.vala, do not modify */

/* valasignaltype.vala
 *
 * Copyright (C) 2007-2011  Jürg Billeter
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
#include <glib.h>
#include <stdlib.h>
#include <string.h>
#include <valagee.h>
#include <glib-object.h>

#define _vala_code_node_unref0(var) ((var == NULL) ? NULL : (var = (vala_code_node_unref (var), NULL)))
#define _vala_code_context_unref0(var) ((var == NULL) ? NULL : (var = (vala_code_context_unref (var), NULL)))

struct _ValaSignalTypePrivate {
	ValaMethod* connect_method;
	ValaMethod* connect_after_method;
	ValaMethod* disconnect_method;
};

static gint ValaSignalType_private_offset;
static gpointer vala_signal_type_parent_class = NULL;

static ValaDataType* vala_signal_type_real_copy (ValaDataType* base);
static gboolean vala_signal_type_real_compatible (ValaDataType* base,
                                           ValaDataType* target_type);
static gchar* vala_signal_type_real_to_qualified_string (ValaDataType* base,
                                                  ValaScope* scope);
static ValaMethod* vala_signal_type_get_connect_method (ValaSignalType* self);
static ValaMethod* vala_signal_type_get_connect_after_method (ValaSignalType* self);
static ValaMethod* vala_signal_type_get_disconnect_method (ValaSignalType* self);
static ValaSymbol* vala_signal_type_real_get_member (ValaDataType* base,
                                              const gchar* member_name);
static gboolean vala_signal_type_real_is_accessible (ValaDataType* base,
                                              ValaSymbol* sym);
static void vala_signal_type_finalize (ValaCodeNode * obj);
static GType vala_signal_type_get_type_once (void);

static inline gpointer
vala_signal_type_get_instance_private (ValaSignalType* self)
{
	return G_STRUCT_MEMBER_P (self, ValaSignalType_private_offset);
}

ValaSignal*
vala_signal_type_get_signal_symbol (ValaSignalType* self)
{
	ValaSignal* result;
	ValaSymbol* _tmp0_;
	ValaSymbol* _tmp1_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = vala_data_type_get_symbol ((ValaDataType*) self);
	_tmp1_ = _tmp0_;
	result = G_TYPE_CHECK_INSTANCE_CAST (_tmp1_, VALA_TYPE_SIGNAL, ValaSignal);
	return result;
}

ValaSignalType*
vala_signal_type_construct (GType object_type,
                            ValaSignal* signal_symbol)
{
	ValaSignalType* self = NULL;
	g_return_val_if_fail (signal_symbol != NULL, NULL);
	self = (ValaSignalType*) vala_callable_type_construct (object_type, (ValaSymbol*) signal_symbol);
	return self;
}

ValaSignalType*
vala_signal_type_new (ValaSignal* signal_symbol)
{
	return vala_signal_type_construct (VALA_TYPE_SIGNAL_TYPE, signal_symbol);
}

static ValaDataType*
vala_signal_type_real_copy (ValaDataType* base)
{
	ValaSignalType * self;
	ValaSignal* _tmp0_;
	ValaSignal* _tmp1_;
	ValaSignalType* _tmp2_;
	ValaDataType* result = NULL;
	self = (ValaSignalType*) base;
	_tmp0_ = vala_signal_type_get_signal_symbol (self);
	_tmp1_ = _tmp0_;
	_tmp2_ = vala_signal_type_new (_tmp1_);
	result = (ValaDataType*) _tmp2_;
	return result;
}

static gboolean
vala_signal_type_real_compatible (ValaDataType* base,
                                  ValaDataType* target_type)
{
	ValaSignalType * self;
	gboolean result = FALSE;
	self = (ValaSignalType*) base;
	g_return_val_if_fail (target_type != NULL, FALSE);
	result = FALSE;
	return result;
}

static gchar*
vala_signal_type_real_to_qualified_string (ValaDataType* base,
                                           ValaScope* scope)
{
	ValaSignalType * self;
	ValaSignal* _tmp0_;
	ValaSignal* _tmp1_;
	gchar* _tmp2_;
	gchar* result = NULL;
	self = (ValaSignalType*) base;
	_tmp0_ = vala_signal_type_get_signal_symbol (self);
	_tmp1_ = _tmp0_;
	_tmp2_ = vala_symbol_get_full_name ((ValaSymbol*) _tmp1_);
	result = _tmp2_;
	return result;
}

static gpointer
_vala_code_node_ref0 (gpointer self)
{
	return self ? vala_code_node_ref (self) : NULL;
}

ValaDelegateType*
vala_signal_type_get_handler_type (ValaSignalType* self)
{
	ValaObjectTypeSymbol* type_sym = NULL;
	ValaSignal* _tmp0_;
	ValaSignal* _tmp1_;
	ValaSymbol* _tmp2_;
	ValaSymbol* _tmp3_;
	ValaObjectTypeSymbol* _tmp4_;
	ValaDataType* sender_type = NULL;
	ValaObjectTypeSymbol* _tmp5_;
	ValaDataType* _tmp6_;
	ValaDelegateType* _result_ = NULL;
	ValaSignal* _tmp7_;
	ValaSignal* _tmp8_;
	ValaDataType* _tmp9_;
	ValaDelegate* _tmp10_;
	ValaDelegate* _tmp11_;
	ValaDelegateType* _tmp12_;
	ValaDelegateType* _tmp13_;
	ValaDelegateType* _tmp14_;
	ValaSourceReference* _tmp15_;
	ValaSourceReference* _tmp16_;
	ValaDelegateType* _tmp17_;
	ValaDelegateType* _tmp18_;
	ValaDelegate* _tmp19_;
	ValaDelegate* _tmp20_;
	ValaDelegateType* result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = vala_signal_type_get_signal_symbol (self);
	_tmp1_ = _tmp0_;
	_tmp2_ = vala_symbol_get_parent_symbol ((ValaSymbol*) _tmp1_);
	_tmp3_ = _tmp2_;
	_tmp4_ = _vala_code_node_ref0 (G_TYPE_CHECK_INSTANCE_CAST (_tmp3_, VALA_TYPE_OBJECT_TYPE_SYMBOL, ValaObjectTypeSymbol));
	type_sym = _tmp4_;
	_tmp5_ = type_sym;
	_tmp6_ = vala_semantic_analyzer_get_data_type_for_symbol ((ValaSymbol*) _tmp5_);
	sender_type = _tmp6_;
	_tmp7_ = vala_signal_type_get_signal_symbol (self);
	_tmp8_ = _tmp7_;
	_tmp9_ = sender_type;
	_tmp10_ = vala_signal_get_delegate (_tmp8_, _tmp9_, (ValaCodeNode*) self);
	_tmp11_ = _tmp10_;
	_tmp12_ = vala_delegate_type_new (_tmp11_);
	_tmp13_ = _tmp12_;
	_vala_code_node_unref0 (_tmp11_);
	_result_ = _tmp13_;
	_tmp14_ = _result_;
	_tmp15_ = vala_code_node_get_source_reference ((ValaCodeNode*) self);
	_tmp16_ = _tmp15_;
	vala_code_node_set_source_reference ((ValaCodeNode*) _tmp14_, _tmp16_);
	_tmp17_ = _result_;
	vala_data_type_set_value_owned ((ValaDataType*) _tmp17_, TRUE);
	_tmp18_ = _result_;
	_tmp19_ = vala_delegate_type_get_delegate_symbol (_tmp18_);
	_tmp20_ = _tmp19_;
	if (vala_delegate_has_type_parameters (_tmp20_)) {
		{
			ValaList* _type_param_list = NULL;
			ValaObjectTypeSymbol* _tmp21_;
			ValaList* _tmp22_;
			gint _type_param_size = 0;
			ValaList* _tmp23_;
			gint _tmp24_;
			gint _tmp25_;
			gint _type_param_index = 0;
			_tmp21_ = type_sym;
			_tmp22_ = vala_object_type_symbol_get_type_parameters (_tmp21_);
			_type_param_list = _tmp22_;
			_tmp23_ = _type_param_list;
			_tmp24_ = vala_collection_get_size ((ValaCollection*) _tmp23_);
			_tmp25_ = _tmp24_;
			_type_param_size = _tmp25_;
			_type_param_index = -1;
			while (TRUE) {
				gint _tmp26_;
				gint _tmp27_;
				ValaTypeParameter* type_param = NULL;
				ValaList* _tmp28_;
				gpointer _tmp29_;
				ValaGenericType* type_arg = NULL;
				ValaTypeParameter* _tmp30_;
				ValaGenericType* _tmp31_;
				ValaGenericType* _tmp32_;
				ValaSourceReference* _tmp33_;
				ValaSourceReference* _tmp34_;
				ValaGenericType* _tmp35_;
				ValaDelegateType* _tmp36_;
				ValaGenericType* _tmp37_;
				_type_param_index = _type_param_index + 1;
				_tmp26_ = _type_param_index;
				_tmp27_ = _type_param_size;
				if (!(_tmp26_ < _tmp27_)) {
					break;
				}
				_tmp28_ = _type_param_list;
				_tmp29_ = vala_list_get (_tmp28_, _type_param_index);
				type_param = (ValaTypeParameter*) _tmp29_;
				_tmp30_ = type_param;
				_tmp31_ = vala_generic_type_new (_tmp30_);
				type_arg = _tmp31_;
				_tmp32_ = type_arg;
				_tmp33_ = vala_code_node_get_source_reference ((ValaCodeNode*) self);
				_tmp34_ = _tmp33_;
				vala_code_node_set_source_reference ((ValaCodeNode*) _tmp32_, _tmp34_);
				_tmp35_ = type_arg;
				vala_data_type_set_value_owned ((ValaDataType*) _tmp35_, TRUE);
				_tmp36_ = _result_;
				_tmp37_ = type_arg;
				vala_data_type_add_type_argument ((ValaDataType*) _tmp36_, (ValaDataType*) _tmp37_);
				_vala_code_node_unref0 (type_arg);
				_vala_code_node_unref0 (type_param);
			}
		}
	}
	result = _result_;
	_vala_code_node_unref0 (sender_type);
	_vala_code_node_unref0 (type_sym);
	return result;
}

static ValaMethod*
vala_signal_type_get_connect_method (ValaSignalType* self)
{
	ValaMethod* _tmp0_;
	ValaMethod* _tmp26_;
	ValaMethod* result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->connect_method;
	if (_tmp0_ == NULL) {
		ValaDataType* ulong_type = NULL;
		ValaCodeContext* _tmp1_;
		ValaCodeContext* _tmp2_;
		ValaSemanticAnalyzer* _tmp3_;
		ValaSemanticAnalyzer* _tmp4_;
		ValaDataType* _tmp5_;
		ValaDataType* _tmp6_;
		ValaDataType* _tmp7_;
		ValaDataType* _tmp8_;
		ValaSourceReference* _tmp9_;
		ValaSourceReference* _tmp10_;
		ValaMethod* _tmp11_;
		ValaMethod* _tmp12_;
		ValaMethod* _tmp13_;
		ValaMethod* _tmp14_;
		ValaSignal* _tmp15_;
		ValaSignal* _tmp16_;
		ValaScope* _tmp17_;
		ValaScope* _tmp18_;
		ValaMethod* _tmp19_;
		ValaDelegateType* _tmp20_;
		ValaDelegateType* _tmp21_;
		ValaSourceReference* _tmp22_;
		ValaSourceReference* _tmp23_;
		ValaParameter* _tmp24_;
		ValaParameter* _tmp25_;
		_tmp1_ = vala_code_context_get ();
		_tmp2_ = _tmp1_;
		_tmp3_ = vala_code_context_get_analyzer (_tmp2_);
		_tmp4_ = _tmp3_;
		_tmp5_ = _tmp4_->ulong_type;
		_tmp6_ = vala_data_type_copy (_tmp5_);
		_tmp7_ = _tmp6_;
		_vala_code_context_unref0 (_tmp2_);
		ulong_type = _tmp7_;
		_tmp8_ = ulong_type;
		_tmp9_ = vala_code_node_get_source_reference ((ValaCodeNode*) self);
		_tmp10_ = _tmp9_;
		_tmp11_ = vala_method_new ("connect", _tmp8_, _tmp10_, NULL);
		_vala_code_node_unref0 (self->priv->connect_method);
		self->priv->connect_method = _tmp11_;
		_tmp12_ = self->priv->connect_method;
		vala_symbol_set_access ((ValaSymbol*) _tmp12_, VALA_SYMBOL_ACCESSIBILITY_PUBLIC);
		_tmp13_ = self->priv->connect_method;
		vala_symbol_set_external ((ValaSymbol*) _tmp13_, TRUE);
		_tmp14_ = self->priv->connect_method;
		_tmp15_ = vala_signal_type_get_signal_symbol (self);
		_tmp16_ = _tmp15_;
		_tmp17_ = vala_symbol_get_scope ((ValaSymbol*) _tmp16_);
		_tmp18_ = _tmp17_;
		vala_symbol_set_owner ((ValaSymbol*) _tmp14_, _tmp18_);
		_tmp19_ = self->priv->connect_method;
		_tmp20_ = vala_signal_type_get_handler_type (self);
		_tmp21_ = _tmp20_;
		_tmp22_ = vala_code_node_get_source_reference ((ValaCodeNode*) self);
		_tmp23_ = _tmp22_;
		_tmp24_ = vala_parameter_new ("handler", (ValaDataType*) _tmp21_, _tmp23_);
		_tmp25_ = _tmp24_;
		vala_callable_add_parameter ((ValaCallable*) _tmp19_, _tmp25_);
		_vala_code_node_unref0 (_tmp25_);
		_vala_code_node_unref0 (_tmp21_);
		_vala_code_node_unref0 (ulong_type);
	}
	_tmp26_ = self->priv->connect_method;
	result = _tmp26_;
	return result;
}

static ValaMethod*
vala_signal_type_get_connect_after_method (ValaSignalType* self)
{
	ValaMethod* _tmp0_;
	ValaMethod* _tmp26_;
	ValaMethod* result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->connect_after_method;
	if (_tmp0_ == NULL) {
		ValaDataType* ulong_type = NULL;
		ValaCodeContext* _tmp1_;
		ValaCodeContext* _tmp2_;
		ValaSemanticAnalyzer* _tmp3_;
		ValaSemanticAnalyzer* _tmp4_;
		ValaDataType* _tmp5_;
		ValaDataType* _tmp6_;
		ValaDataType* _tmp7_;
		ValaDataType* _tmp8_;
		ValaSourceReference* _tmp9_;
		ValaSourceReference* _tmp10_;
		ValaMethod* _tmp11_;
		ValaMethod* _tmp12_;
		ValaMethod* _tmp13_;
		ValaMethod* _tmp14_;
		ValaSignal* _tmp15_;
		ValaSignal* _tmp16_;
		ValaScope* _tmp17_;
		ValaScope* _tmp18_;
		ValaMethod* _tmp19_;
		ValaDelegateType* _tmp20_;
		ValaDelegateType* _tmp21_;
		ValaSourceReference* _tmp22_;
		ValaSourceReference* _tmp23_;
		ValaParameter* _tmp24_;
		ValaParameter* _tmp25_;
		_tmp1_ = vala_code_context_get ();
		_tmp2_ = _tmp1_;
		_tmp3_ = vala_code_context_get_analyzer (_tmp2_);
		_tmp4_ = _tmp3_;
		_tmp5_ = _tmp4_->ulong_type;
		_tmp6_ = vala_data_type_copy (_tmp5_);
		_tmp7_ = _tmp6_;
		_vala_code_context_unref0 (_tmp2_);
		ulong_type = _tmp7_;
		_tmp8_ = ulong_type;
		_tmp9_ = vala_code_node_get_source_reference ((ValaCodeNode*) self);
		_tmp10_ = _tmp9_;
		_tmp11_ = vala_method_new ("connect_after", _tmp8_, _tmp10_, NULL);
		_vala_code_node_unref0 (self->priv->connect_after_method);
		self->priv->connect_after_method = _tmp11_;
		_tmp12_ = self->priv->connect_after_method;
		vala_symbol_set_access ((ValaSymbol*) _tmp12_, VALA_SYMBOL_ACCESSIBILITY_PUBLIC);
		_tmp13_ = self->priv->connect_after_method;
		vala_symbol_set_external ((ValaSymbol*) _tmp13_, TRUE);
		_tmp14_ = self->priv->connect_after_method;
		_tmp15_ = vala_signal_type_get_signal_symbol (self);
		_tmp16_ = _tmp15_;
		_tmp17_ = vala_symbol_get_scope ((ValaSymbol*) _tmp16_);
		_tmp18_ = _tmp17_;
		vala_symbol_set_owner ((ValaSymbol*) _tmp14_, _tmp18_);
		_tmp19_ = self->priv->connect_after_method;
		_tmp20_ = vala_signal_type_get_handler_type (self);
		_tmp21_ = _tmp20_;
		_tmp22_ = vala_code_node_get_source_reference ((ValaCodeNode*) self);
		_tmp23_ = _tmp22_;
		_tmp24_ = vala_parameter_new ("handler", (ValaDataType*) _tmp21_, _tmp23_);
		_tmp25_ = _tmp24_;
		vala_callable_add_parameter ((ValaCallable*) _tmp19_, _tmp25_);
		_vala_code_node_unref0 (_tmp25_);
		_vala_code_node_unref0 (_tmp21_);
		_vala_code_node_unref0 (ulong_type);
	}
	_tmp26_ = self->priv->connect_after_method;
	result = _tmp26_;
	return result;
}

static ValaMethod*
vala_signal_type_get_disconnect_method (ValaSignalType* self)
{
	ValaMethod* _tmp0_;
	ValaMethod* _tmp20_;
	ValaMethod* result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->disconnect_method;
	if (_tmp0_ == NULL) {
		ValaVoidType* _tmp1_;
		ValaVoidType* _tmp2_;
		ValaSourceReference* _tmp3_;
		ValaSourceReference* _tmp4_;
		ValaMethod* _tmp5_;
		ValaMethod* _tmp6_;
		ValaMethod* _tmp7_;
		ValaMethod* _tmp8_;
		ValaSignal* _tmp9_;
		ValaSignal* _tmp10_;
		ValaScope* _tmp11_;
		ValaScope* _tmp12_;
		ValaMethod* _tmp13_;
		ValaDelegateType* _tmp14_;
		ValaDelegateType* _tmp15_;
		ValaSourceReference* _tmp16_;
		ValaSourceReference* _tmp17_;
		ValaParameter* _tmp18_;
		ValaParameter* _tmp19_;
		_tmp1_ = vala_void_type_new (NULL);
		_tmp2_ = _tmp1_;
		_tmp3_ = vala_code_node_get_source_reference ((ValaCodeNode*) self);
		_tmp4_ = _tmp3_;
		_tmp5_ = vala_method_new ("disconnect", (ValaDataType*) _tmp2_, _tmp4_, NULL);
		_vala_code_node_unref0 (self->priv->disconnect_method);
		self->priv->disconnect_method = _tmp5_;
		_vala_code_node_unref0 (_tmp2_);
		_tmp6_ = self->priv->disconnect_method;
		vala_symbol_set_access ((ValaSymbol*) _tmp6_, VALA_SYMBOL_ACCESSIBILITY_PUBLIC);
		_tmp7_ = self->priv->disconnect_method;
		vala_symbol_set_external ((ValaSymbol*) _tmp7_, TRUE);
		_tmp8_ = self->priv->disconnect_method;
		_tmp9_ = vala_signal_type_get_signal_symbol (self);
		_tmp10_ = _tmp9_;
		_tmp11_ = vala_symbol_get_scope ((ValaSymbol*) _tmp10_);
		_tmp12_ = _tmp11_;
		vala_symbol_set_owner ((ValaSymbol*) _tmp8_, _tmp12_);
		_tmp13_ = self->priv->disconnect_method;
		_tmp14_ = vala_signal_type_get_handler_type (self);
		_tmp15_ = _tmp14_;
		_tmp16_ = vala_code_node_get_source_reference ((ValaCodeNode*) self);
		_tmp17_ = _tmp16_;
		_tmp18_ = vala_parameter_new ("handler", (ValaDataType*) _tmp15_, _tmp17_);
		_tmp19_ = _tmp18_;
		vala_callable_add_parameter ((ValaCallable*) _tmp13_, _tmp19_);
		_vala_code_node_unref0 (_tmp19_);
		_vala_code_node_unref0 (_tmp15_);
	}
	_tmp20_ = self->priv->disconnect_method;
	result = _tmp20_;
	return result;
}

static ValaSymbol*
vala_signal_type_real_get_member (ValaDataType* base,
                                  const gchar* member_name)
{
	ValaSignalType * self;
	ValaSymbol* result = NULL;
	self = (ValaSignalType*) base;
	g_return_val_if_fail (member_name != NULL, NULL);
	if (g_strcmp0 (member_name, "connect") == 0) {
		ValaMethod* _tmp0_;
		ValaSymbol* _tmp1_;
		_tmp0_ = vala_signal_type_get_connect_method (self);
		_tmp1_ = _vala_code_node_ref0 ((ValaSymbol*) _tmp0_);
		result = _tmp1_;
		return result;
	} else {
		if (g_strcmp0 (member_name, "connect_after") == 0) {
			ValaMethod* _tmp2_;
			ValaSymbol* _tmp3_;
			_tmp2_ = vala_signal_type_get_connect_after_method (self);
			_tmp3_ = _vala_code_node_ref0 ((ValaSymbol*) _tmp2_);
			result = _tmp3_;
			return result;
		} else {
			if (g_strcmp0 (member_name, "disconnect") == 0) {
				ValaMethod* _tmp4_;
				ValaSymbol* _tmp5_;
				_tmp4_ = vala_signal_type_get_disconnect_method (self);
				_tmp5_ = _vala_code_node_ref0 ((ValaSymbol*) _tmp4_);
				result = _tmp5_;
				return result;
			}
		}
	}
	result = NULL;
	return result;
}

static gboolean
vala_signal_type_real_is_accessible (ValaDataType* base,
                                     ValaSymbol* sym)
{
	ValaSignalType * self;
	ValaSignal* _tmp0_;
	ValaSignal* _tmp1_;
	gboolean result = FALSE;
	self = (ValaSignalType*) base;
	g_return_val_if_fail (sym != NULL, FALSE);
	_tmp0_ = vala_signal_type_get_signal_symbol (self);
	_tmp1_ = _tmp0_;
	result = vala_symbol_is_accessible ((ValaSymbol*) _tmp1_, sym);
	return result;
}

static void
vala_signal_type_class_init (ValaSignalTypeClass * klass,
                             gpointer klass_data)
{
	vala_signal_type_parent_class = g_type_class_peek_parent (klass);
	((ValaCodeNodeClass *) klass)->finalize = vala_signal_type_finalize;
	g_type_class_adjust_private_offset (klass, &ValaSignalType_private_offset);
	((ValaDataTypeClass *) klass)->copy = (ValaDataType* (*) (ValaDataType*)) vala_signal_type_real_copy;
	((ValaDataTypeClass *) klass)->compatible = (gboolean (*) (ValaDataType*, ValaDataType*)) vala_signal_type_real_compatible;
	((ValaDataTypeClass *) klass)->to_qualified_string = (gchar* (*) (ValaDataType*, ValaScope*)) vala_signal_type_real_to_qualified_string;
	((ValaDataTypeClass *) klass)->get_member = (ValaSymbol* (*) (ValaDataType*, const gchar*)) vala_signal_type_real_get_member;
	((ValaDataTypeClass *) klass)->is_accessible = (gboolean (*) (ValaDataType*, ValaSymbol*)) vala_signal_type_real_is_accessible;
}

static void
vala_signal_type_instance_init (ValaSignalType * self,
                                gpointer klass)
{
	self->priv = vala_signal_type_get_instance_private (self);
}

static void
vala_signal_type_finalize (ValaCodeNode * obj)
{
	ValaSignalType * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, VALA_TYPE_SIGNAL_TYPE, ValaSignalType);
	_vala_code_node_unref0 (self->priv->connect_method);
	_vala_code_node_unref0 (self->priv->connect_after_method);
	_vala_code_node_unref0 (self->priv->disconnect_method);
	VALA_CODE_NODE_CLASS (vala_signal_type_parent_class)->finalize (obj);
}

/**
 * The type of a signal referencea.
 */
static GType
vala_signal_type_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (ValaSignalTypeClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) vala_signal_type_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (ValaSignalType), 0, (GInstanceInitFunc) vala_signal_type_instance_init, NULL };
	GType vala_signal_type_type_id;
	vala_signal_type_type_id = g_type_register_static (VALA_TYPE_CALLABLE_TYPE, "ValaSignalType", &g_define_type_info, 0);
	ValaSignalType_private_offset = g_type_add_instance_private (vala_signal_type_type_id, sizeof (ValaSignalTypePrivate));
	return vala_signal_type_type_id;
}

GType
vala_signal_type_get_type (void)
{
	static volatile gsize vala_signal_type_type_id__volatile = 0;
	if (g_once_init_enter (&vala_signal_type_type_id__volatile)) {
		GType vala_signal_type_type_id;
		vala_signal_type_type_id = vala_signal_type_get_type_once ();
		g_once_init_leave (&vala_signal_type_type_id__volatile, vala_signal_type_type_id);
	}
	return vala_signal_type_type_id__volatile;
}
