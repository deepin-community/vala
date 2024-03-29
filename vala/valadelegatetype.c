/* valadelegatetype.c generated by valac, the Vala compiler
 * generated from valadelegatetype.vala, do not modify */

/* valadelegatetype.vala
 *
 * Copyright (C) 2007-2012  Jürg Billeter
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
#include <glib-object.h>
#include <valagee.h>

#define _vala_code_node_unref0(var) ((var == NULL) ? NULL : (var = (vala_code_node_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))
#define _vala_iterator_unref0(var) ((var == NULL) ? NULL : (var = (vala_iterator_unref (var), NULL)))
#define _vala_iterable_unref0(var) ((var == NULL) ? NULL : (var = (vala_iterable_unref (var), NULL)))

struct _ValaDelegateTypePrivate {
	gboolean _is_called_once;
	ValaDelegateTargetField* target_field;
	ValaDelegateDestroyField* destroy_field;
};

static gint ValaDelegateType_private_offset;
static gpointer vala_delegate_type_parent_class = NULL;

static ValaSymbol* vala_delegate_type_real_get_member (ValaDataType* base,
                                                const gchar* member_name);
static ValaDelegateTargetField* vala_delegate_type_get_target_field (ValaDelegateType* self);
static ValaDelegateDestroyField* vala_delegate_type_get_destroy_field (ValaDelegateType* self);
static ValaDataType* vala_delegate_type_real_copy (ValaDataType* base);
static gboolean vala_delegate_type_real_equals (ValaDataType* base,
                                         ValaDataType* type2);
static gboolean vala_delegate_type_real_is_accessible (ValaDataType* base,
                                                ValaSymbol* sym);
static gboolean vala_delegate_type_real_check (ValaCodeNode* base,
                                        ValaCodeContext* context);
static gboolean vala_delegate_type_real_compatible (ValaDataType* base,
                                             ValaDataType* target_type);
static gboolean vala_delegate_type_real_is_disposable (ValaDataType* base);
static void vala_delegate_type_finalize (ValaCodeNode * obj);
static GType vala_delegate_type_get_type_once (void);

static inline gpointer
vala_delegate_type_get_instance_private (ValaDelegateType* self)
{
	return G_STRUCT_MEMBER_P (self, ValaDelegateType_private_offset);
}

ValaDelegate*
vala_delegate_type_get_delegate_symbol (ValaDelegateType* self)
{
	ValaDelegate* result;
	ValaSymbol* _tmp0_;
	ValaSymbol* _tmp1_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = vala_data_type_get_symbol ((ValaDataType*) self);
	_tmp1_ = _tmp0_;
	result = G_TYPE_CHECK_INSTANCE_CAST (_tmp1_, VALA_TYPE_DELEGATE, ValaDelegate);
	return result;
}

gboolean
vala_delegate_type_get_is_called_once (ValaDelegateType* self)
{
	gboolean result;
	g_return_val_if_fail (self != NULL, FALSE);
	result = self->priv->_is_called_once;
	return result;
}

void
vala_delegate_type_set_is_called_once (ValaDelegateType* self,
                                       gboolean value)
{
	g_return_if_fail (self != NULL);
	self->priv->_is_called_once = value;
}

ValaDelegateType*
vala_delegate_type_construct (GType object_type,
                              ValaDelegate* delegate_symbol,
                              ValaSourceReference* source_reference)
{
	ValaDelegateType* self = NULL;
	gchar* _tmp0_;
	gchar* _tmp1_;
	g_return_val_if_fail (delegate_symbol != NULL, NULL);
	self = (ValaDelegateType*) vala_callable_type_construct (object_type, (ValaSymbol*) delegate_symbol, source_reference);
	_tmp0_ = vala_code_node_get_attribute_string ((ValaCodeNode*) delegate_symbol, "CCode", "scope", NULL);
	_tmp1_ = _tmp0_;
	vala_delegate_type_set_is_called_once (self, g_strcmp0 (_tmp1_, "async") == 0);
	_g_free0 (_tmp1_);
	return self;
}

ValaDelegateType*
vala_delegate_type_new (ValaDelegate* delegate_symbol,
                        ValaSourceReference* source_reference)
{
	return vala_delegate_type_construct (VALA_TYPE_DELEGATE_TYPE, delegate_symbol, source_reference);
}

static gpointer
_vala_code_node_ref0 (gpointer self)
{
	return self ? vala_code_node_ref (self) : NULL;
}

static ValaSymbol*
vala_delegate_type_real_get_member (ValaDataType* base,
                                    const gchar* member_name)
{
	ValaDelegateType * self;
	ValaSymbol* result;
	self = (ValaDelegateType*) base;
	g_return_val_if_fail (member_name != NULL, NULL);
	if (g_strcmp0 (member_name, "target") == 0) {
		ValaDelegateTargetField* _tmp0_;
		ValaSymbol* _tmp1_;
		_tmp0_ = vala_delegate_type_get_target_field (self);
		_tmp1_ = _vala_code_node_ref0 ((ValaSymbol*) _tmp0_);
		result = _tmp1_;
		return result;
	} else {
		if (g_strcmp0 (member_name, "destroy") == 0) {
			ValaDelegateDestroyField* _tmp2_;
			ValaSymbol* _tmp3_;
			_tmp2_ = vala_delegate_type_get_destroy_field (self);
			_tmp3_ = _vala_code_node_ref0 ((ValaSymbol*) _tmp2_);
			result = _tmp3_;
			return result;
		}
	}
	result = NULL;
	return result;
}

static ValaDelegateTargetField*
vala_delegate_type_get_target_field (ValaDelegateType* self)
{
	ValaDelegateTargetField* _tmp0_;
	ValaDelegateTargetField* _tmp5_;
	ValaDelegateTargetField* result;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->target_field;
	if (_tmp0_ == NULL) {
		ValaSourceReference* _tmp1_;
		ValaSourceReference* _tmp2_;
		ValaDelegateTargetField* _tmp3_;
		ValaDelegateTargetField* _tmp4_;
		_tmp1_ = vala_code_node_get_source_reference ((ValaCodeNode*) self);
		_tmp2_ = _tmp1_;
		_tmp3_ = vala_delegate_target_field_new (_tmp2_);
		_vala_code_node_unref0 (self->priv->target_field);
		self->priv->target_field = _tmp3_;
		_tmp4_ = self->priv->target_field;
		vala_symbol_set_access ((ValaSymbol*) _tmp4_, VALA_SYMBOL_ACCESSIBILITY_PUBLIC);
	}
	_tmp5_ = self->priv->target_field;
	result = _tmp5_;
	return result;
}

static ValaDelegateDestroyField*
vala_delegate_type_get_destroy_field (ValaDelegateType* self)
{
	ValaDelegateDestroyField* _tmp0_;
	ValaDelegateDestroyField* _tmp5_;
	ValaDelegateDestroyField* result;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->destroy_field;
	if (_tmp0_ == NULL) {
		ValaSourceReference* _tmp1_;
		ValaSourceReference* _tmp2_;
		ValaDelegateDestroyField* _tmp3_;
		ValaDelegateDestroyField* _tmp4_;
		_tmp1_ = vala_code_node_get_source_reference ((ValaCodeNode*) self);
		_tmp2_ = _tmp1_;
		_tmp3_ = vala_delegate_destroy_field_new (_tmp2_);
		_vala_code_node_unref0 (self->priv->destroy_field);
		self->priv->destroy_field = _tmp3_;
		_tmp4_ = self->priv->destroy_field;
		vala_symbol_set_access ((ValaSymbol*) _tmp4_, VALA_SYMBOL_ACCESSIBILITY_PUBLIC);
	}
	_tmp5_ = self->priv->destroy_field;
	result = _tmp5_;
	return result;
}

static ValaDataType*
vala_delegate_type_real_copy (ValaDataType* base)
{
	ValaDelegateType * self;
	ValaDelegateType* _result_ = NULL;
	ValaDelegate* _tmp0_;
	ValaDelegate* _tmp1_;
	ValaSourceReference* _tmp2_;
	ValaSourceReference* _tmp3_;
	ValaDelegateType* _tmp4_;
	ValaDelegateType* _tmp5_;
	gboolean _tmp6_;
	gboolean _tmp7_;
	ValaDelegateType* _tmp8_;
	gboolean _tmp9_;
	gboolean _tmp10_;
	ValaDelegateType* _tmp23_;
	gboolean _tmp24_;
	ValaDataType* result;
	self = (ValaDelegateType*) base;
	_tmp0_ = vala_delegate_type_get_delegate_symbol (self);
	_tmp1_ = _tmp0_;
	_tmp2_ = vala_code_node_get_source_reference ((ValaCodeNode*) self);
	_tmp3_ = _tmp2_;
	_tmp4_ = vala_delegate_type_new (_tmp1_, _tmp3_);
	_result_ = _tmp4_;
	_tmp5_ = _result_;
	_tmp6_ = vala_data_type_get_value_owned ((ValaDataType*) self);
	_tmp7_ = _tmp6_;
	vala_data_type_set_value_owned ((ValaDataType*) _tmp5_, _tmp7_);
	_tmp8_ = _result_;
	_tmp9_ = vala_data_type_get_nullable ((ValaDataType*) self);
	_tmp10_ = _tmp9_;
	vala_data_type_set_nullable ((ValaDataType*) _tmp8_, _tmp10_);
	{
		ValaList* _arg_list = NULL;
		ValaList* _tmp11_;
		gint _arg_size = 0;
		ValaList* _tmp12_;
		gint _tmp13_;
		gint _tmp14_;
		gint _arg_index = 0;
		_tmp11_ = vala_data_type_get_type_arguments ((ValaDataType*) self);
		_arg_list = _tmp11_;
		_tmp12_ = _arg_list;
		_tmp13_ = vala_collection_get_size ((ValaCollection*) _tmp12_);
		_tmp14_ = _tmp13_;
		_arg_size = _tmp14_;
		_arg_index = -1;
		while (TRUE) {
			gint _tmp15_;
			gint _tmp16_;
			ValaDataType* arg = NULL;
			ValaList* _tmp17_;
			gpointer _tmp18_;
			ValaDelegateType* _tmp19_;
			ValaDataType* _tmp20_;
			ValaDataType* _tmp21_;
			ValaDataType* _tmp22_;
			_arg_index = _arg_index + 1;
			_tmp15_ = _arg_index;
			_tmp16_ = _arg_size;
			if (!(_tmp15_ < _tmp16_)) {
				break;
			}
			_tmp17_ = _arg_list;
			_tmp18_ = vala_list_get (_tmp17_, _arg_index);
			arg = (ValaDataType*) _tmp18_;
			_tmp19_ = _result_;
			_tmp20_ = arg;
			_tmp21_ = vala_data_type_copy (_tmp20_);
			_tmp22_ = _tmp21_;
			vala_data_type_add_type_argument ((ValaDataType*) _tmp19_, _tmp22_);
			_vala_code_node_unref0 (_tmp22_);
			_vala_code_node_unref0 (arg);
		}
	}
	_tmp23_ = _result_;
	_tmp24_ = self->priv->_is_called_once;
	vala_delegate_type_set_is_called_once (_tmp23_, _tmp24_);
	result = (ValaDataType*) _result_;
	return result;
}

static gboolean
vala_delegate_type_real_equals (ValaDataType* base,
                                ValaDataType* type2)
{
	ValaDelegateType * self;
	gboolean result;
	self = (ValaDelegateType*) base;
	g_return_val_if_fail (type2 != NULL, FALSE);
	result = vala_data_type_compatible ((ValaDataType*) self, type2);
	return result;
}

static gboolean
vala_delegate_type_real_is_accessible (ValaDataType* base,
                                       ValaSymbol* sym)
{
	ValaDelegateType * self;
	ValaDelegate* _tmp0_;
	ValaDelegate* _tmp1_;
	gboolean result;
	self = (ValaDelegateType*) base;
	g_return_val_if_fail (sym != NULL, FALSE);
	_tmp0_ = vala_delegate_type_get_delegate_symbol (self);
	_tmp1_ = _tmp0_;
	result = vala_symbol_is_accessible ((ValaSymbol*) _tmp1_, sym);
	return result;
}

static gboolean
vala_delegate_type_real_check (ValaCodeNode* base,
                               ValaCodeContext* context)
{
	ValaDelegateType * self;
	gboolean _tmp0_ = FALSE;
	gboolean _tmp1_;
	ValaDelegate* _tmp6_;
	ValaDelegate* _tmp7_;
	gboolean result;
	self = (ValaDelegateType*) base;
	g_return_val_if_fail (context != NULL, FALSE);
	_tmp1_ = self->priv->_is_called_once;
	if (_tmp1_) {
		gboolean _tmp2_;
		gboolean _tmp3_;
		_tmp2_ = vala_data_type_get_value_owned ((ValaDataType*) self);
		_tmp3_ = _tmp2_;
		_tmp0_ = !_tmp3_;
	} else {
		_tmp0_ = FALSE;
	}
	if (_tmp0_) {
		ValaSourceReference* _tmp4_;
		ValaSourceReference* _tmp5_;
		_tmp4_ = vala_code_node_get_source_reference ((ValaCodeNode*) self);
		_tmp5_ = _tmp4_;
		vala_report_warning (_tmp5_, "delegates with scope=\"async\" must be owned");
	}
	_tmp6_ = vala_delegate_type_get_delegate_symbol (self);
	_tmp7_ = _tmp6_;
	if (!vala_code_node_check ((ValaCodeNode*) _tmp7_, context)) {
		vala_code_node_set_error ((ValaCodeNode*) self, TRUE);
		result = FALSE;
		return result;
	}
	if (!vala_data_type_check_type_arguments ((ValaDataType*) self, context, TRUE)) {
		vala_code_node_set_error ((ValaCodeNode*) self, TRUE);
		result = FALSE;
		return result;
	}
	result = TRUE;
	return result;
}

static gpointer
_vala_iterable_ref0 (gpointer self)
{
	return self ? vala_iterable_ref (self) : NULL;
}

static gboolean
vala_delegate_type_real_compatible (ValaDataType* base,
                                    ValaDataType* target_type)
{
	ValaDelegateType * self;
	ValaDelegateType* dt_target = NULL;
	ValaDelegateType* _tmp0_;
	ValaDelegate* _tmp1_;
	ValaDelegate* _tmp2_;
	ValaDelegateType* _tmp3_;
	ValaDelegate* _tmp4_;
	ValaDelegate* _tmp5_;
	ValaDelegate* _tmp6_;
	ValaDelegate* _tmp7_;
	gboolean _tmp8_;
	gboolean _tmp9_;
	ValaDelegateType* _tmp10_;
	ValaDelegate* _tmp11_;
	ValaDelegate* _tmp12_;
	gboolean _tmp13_;
	gboolean _tmp14_;
	ValaDataType* _tmp15_;
	ValaDelegateType* _tmp16_;
	ValaDataType* _tmp17_;
	ValaDelegateType* _tmp18_;
	ValaDataType* _tmp19_;
	ValaDataType* _tmp20_;
	gboolean _tmp21_;
	ValaList* parameters = NULL;
	ValaList* _tmp22_;
	ValaList* _tmp23_;
	ValaIterator* params_it = NULL;
	ValaList* _tmp24_;
	ValaIterator* _tmp25_;
	gboolean _tmp26_ = FALSE;
	gboolean _tmp27_ = FALSE;
	ValaDelegateType* _tmp28_;
	ValaDelegate* _tmp29_;
	ValaDelegate* _tmp30_;
	ValaSymbol* _tmp31_;
	ValaSymbol* _tmp32_;
	ValaIterator* _tmp99_;
	ValaArrayList* error_types = NULL;
	GEqualFunc _tmp100_;
	ValaArrayList* _tmp101_;
	ValaDelegate* _tmp102_;
	ValaDelegate* _tmp103_;
	ValaArrayList* _tmp104_;
	gboolean result;
	self = (ValaDelegateType*) base;
	g_return_val_if_fail (target_type != NULL, FALSE);
	dt_target = VALA_IS_DELEGATE_TYPE (target_type) ? ((ValaDelegateType*) target_type) : NULL;
	_tmp0_ = dt_target;
	if (_tmp0_ == NULL) {
		result = FALSE;
		return result;
	}
	_tmp1_ = vala_delegate_type_get_delegate_symbol (self);
	_tmp2_ = _tmp1_;
	_tmp3_ = dt_target;
	_tmp4_ = vala_delegate_type_get_delegate_symbol (_tmp3_);
	_tmp5_ = _tmp4_;
	if (_tmp2_ == _tmp5_) {
		result = TRUE;
		return result;
	}
	_tmp6_ = vala_delegate_type_get_delegate_symbol (self);
	_tmp7_ = _tmp6_;
	_tmp8_ = vala_delegate_get_has_target (_tmp7_);
	_tmp9_ = _tmp8_;
	_tmp10_ = dt_target;
	_tmp11_ = vala_delegate_type_get_delegate_symbol (_tmp10_);
	_tmp12_ = _tmp11_;
	_tmp13_ = vala_delegate_get_has_target (_tmp12_);
	_tmp14_ = _tmp13_;
	if (_tmp9_ != _tmp14_) {
		result = FALSE;
		return result;
	}
	_tmp15_ = vala_data_type_get_return_type ((ValaDataType*) self);
	_tmp16_ = dt_target;
	_tmp17_ = vala_data_type_get_return_type ((ValaDataType*) _tmp16_);
	_tmp18_ = dt_target;
	_tmp19_ = vala_data_type_get_actual_type (_tmp17_, (ValaDataType*) _tmp18_, NULL, (ValaCodeNode*) self);
	_tmp20_ = _tmp19_;
	_tmp21_ = !vala_data_type_stricter (_tmp15_, _tmp20_);
	_vala_code_node_unref0 (_tmp20_);
	if (_tmp21_) {
		result = FALSE;
		return result;
	}
	_tmp22_ = vala_data_type_get_parameters ((ValaDataType*) self);
	_tmp23_ = _vala_iterable_ref0 (_tmp22_);
	parameters = _tmp23_;
	_tmp24_ = parameters;
	_tmp25_ = vala_iterable_iterator ((ValaIterable*) _tmp24_);
	params_it = _tmp25_;
	_tmp28_ = dt_target;
	_tmp29_ = vala_delegate_type_get_delegate_symbol (_tmp28_);
	_tmp30_ = _tmp29_;
	_tmp31_ = vala_symbol_get_parent_symbol ((ValaSymbol*) _tmp30_);
	_tmp32_ = _tmp31_;
	if (VALA_IS_SIGNAL (_tmp32_)) {
		ValaDelegateType* _tmp33_;
		ValaDelegate* _tmp34_;
		ValaDelegate* _tmp35_;
		ValaDataType* _tmp36_;
		ValaDataType* _tmp37_;
		_tmp33_ = dt_target;
		_tmp34_ = vala_delegate_type_get_delegate_symbol (_tmp33_);
		_tmp35_ = _tmp34_;
		_tmp36_ = vala_delegate_get_sender_type (_tmp35_);
		_tmp37_ = _tmp36_;
		_tmp27_ = _tmp37_ != NULL;
	} else {
		_tmp27_ = FALSE;
	}
	if (_tmp27_) {
		ValaList* _tmp38_;
		gint _tmp39_;
		gint _tmp40_;
		ValaDelegateType* _tmp41_;
		ValaList* _tmp42_;
		gint _tmp43_;
		gint _tmp44_;
		_tmp38_ = parameters;
		_tmp39_ = vala_collection_get_size ((ValaCollection*) _tmp38_);
		_tmp40_ = _tmp39_;
		_tmp41_ = dt_target;
		_tmp42_ = vala_data_type_get_parameters ((ValaDataType*) _tmp41_);
		_tmp43_ = vala_collection_get_size ((ValaCollection*) _tmp42_);
		_tmp44_ = _tmp43_;
		_tmp26_ = _tmp40_ == (_tmp44_ + 1);
	} else {
		_tmp26_ = FALSE;
	}
	if (_tmp26_) {
		ValaIterator* _tmp45_;
		ValaParameter* p = NULL;
		ValaIterator* _tmp46_;
		gpointer _tmp47_;
		ValaDelegateType* _tmp48_;
		ValaDelegate* _tmp49_;
		ValaDelegate* _tmp50_;
		ValaDataType* _tmp51_;
		ValaDataType* _tmp52_;
		ValaParameter* _tmp53_;
		ValaDataType* _tmp54_;
		ValaDataType* _tmp55_;
		_tmp45_ = params_it;
		vala_iterator_next (_tmp45_);
		_tmp46_ = params_it;
		_tmp47_ = vala_iterator_get (_tmp46_);
		p = (ValaParameter*) _tmp47_;
		_tmp48_ = dt_target;
		_tmp49_ = vala_delegate_type_get_delegate_symbol (_tmp48_);
		_tmp50_ = _tmp49_;
		_tmp51_ = vala_delegate_get_sender_type (_tmp50_);
		_tmp52_ = _tmp51_;
		_tmp53_ = p;
		_tmp54_ = vala_variable_get_variable_type ((ValaVariable*) _tmp53_);
		_tmp55_ = _tmp54_;
		if (!vala_data_type_stricter (_tmp52_, _tmp55_)) {
			result = FALSE;
			_vala_code_node_unref0 (p);
			_vala_iterator_unref0 (params_it);
			_vala_iterable_unref0 (parameters);
			return result;
		}
		_vala_code_node_unref0 (p);
	}
	{
		ValaList* _param_list = NULL;
		ValaDelegateType* _tmp56_;
		ValaList* _tmp57_;
		gint _param_size = 0;
		ValaList* _tmp58_;
		gint _tmp59_;
		gint _tmp60_;
		gint _param_index = 0;
		_tmp56_ = dt_target;
		_tmp57_ = vala_data_type_get_parameters ((ValaDataType*) _tmp56_);
		_param_list = _tmp57_;
		_tmp58_ = _param_list;
		_tmp59_ = vala_collection_get_size ((ValaCollection*) _tmp58_);
		_tmp60_ = _tmp59_;
		_param_size = _tmp60_;
		_param_index = -1;
		while (TRUE) {
			gint _tmp61_;
			gint _tmp62_;
			ValaParameter* param = NULL;
			ValaList* _tmp63_;
			gpointer _tmp64_;
			ValaIterator* _tmp65_;
			ValaParameter* p = NULL;
			ValaIterator* _tmp66_;
			gpointer _tmp67_;
			gboolean _tmp68_ = FALSE;
			ValaParameter* _tmp69_;
			ValaParameter* _tmp90_;
			ValaDataType* _tmp91_;
			ValaDataType* _tmp92_;
			ValaDataType* _tmp93_;
			ValaDataType* _tmp94_;
			ValaParameter* _tmp95_;
			ValaDataType* _tmp96_;
			ValaDataType* _tmp97_;
			gboolean _tmp98_;
			_param_index = _param_index + 1;
			_tmp61_ = _param_index;
			_tmp62_ = _param_size;
			if (!(_tmp61_ < _tmp62_)) {
				break;
			}
			_tmp63_ = _param_list;
			_tmp64_ = vala_list_get (_tmp63_, _param_index);
			param = (ValaParameter*) _tmp64_;
			_tmp65_ = params_it;
			if (!vala_iterator_next (_tmp65_)) {
				result = FALSE;
				_vala_code_node_unref0 (param);
				_vala_iterator_unref0 (params_it);
				_vala_iterable_unref0 (parameters);
				return result;
			}
			_tmp66_ = params_it;
			_tmp67_ = vala_iterator_get (_tmp66_);
			p = (ValaParameter*) _tmp67_;
			_tmp69_ = p;
			if (_tmp69_ != NULL) {
				gboolean _tmp70_ = FALSE;
				ValaParameter* _tmp71_;
				gboolean _tmp72_;
				gboolean _tmp73_;
				_tmp71_ = param;
				_tmp72_ = vala_parameter_get_ellipsis (_tmp71_);
				_tmp73_ = _tmp72_;
				if (_tmp73_) {
					_tmp70_ = TRUE;
				} else {
					ValaParameter* _tmp74_;
					gboolean _tmp75_;
					gboolean _tmp76_;
					_tmp74_ = param;
					_tmp75_ = vala_parameter_get_params_array (_tmp74_);
					_tmp76_ = _tmp75_;
					_tmp70_ = _tmp76_;
				}
				_tmp68_ = _tmp70_;
			} else {
				_tmp68_ = FALSE;
			}
			if (_tmp68_) {
				gboolean _tmp77_ = FALSE;
				ValaParameter* _tmp78_;
				gboolean _tmp79_;
				gboolean _tmp80_;
				ValaParameter* _tmp81_;
				gboolean _tmp82_;
				gboolean _tmp83_;
				_tmp78_ = param;
				_tmp79_ = vala_parameter_get_ellipsis (_tmp78_);
				_tmp80_ = _tmp79_;
				_tmp81_ = p;
				_tmp82_ = vala_parameter_get_ellipsis (_tmp81_);
				_tmp83_ = _tmp82_;
				if (_tmp80_ != _tmp83_) {
					_tmp77_ = TRUE;
				} else {
					ValaParameter* _tmp84_;
					gboolean _tmp85_;
					gboolean _tmp86_;
					ValaParameter* _tmp87_;
					gboolean _tmp88_;
					gboolean _tmp89_;
					_tmp84_ = param;
					_tmp85_ = vala_parameter_get_params_array (_tmp84_);
					_tmp86_ = _tmp85_;
					_tmp87_ = p;
					_tmp88_ = vala_parameter_get_params_array (_tmp87_);
					_tmp89_ = _tmp88_;
					_tmp77_ = _tmp86_ != _tmp89_;
				}
				if (_tmp77_) {
					result = FALSE;
					_vala_code_node_unref0 (p);
					_vala_code_node_unref0 (param);
					_vala_iterator_unref0 (params_it);
					_vala_iterable_unref0 (parameters);
					return result;
				}
				_vala_code_node_unref0 (p);
				_vala_code_node_unref0 (param);
				break;
			}
			_tmp90_ = param;
			_tmp91_ = vala_variable_get_variable_type ((ValaVariable*) _tmp90_);
			_tmp92_ = _tmp91_;
			_tmp93_ = vala_data_type_get_actual_type (_tmp92_, (ValaDataType*) self, NULL, (ValaCodeNode*) self);
			_tmp94_ = _tmp93_;
			_tmp95_ = p;
			_tmp96_ = vala_variable_get_variable_type ((ValaVariable*) _tmp95_);
			_tmp97_ = _tmp96_;
			_tmp98_ = !vala_data_type_stricter (_tmp94_, _tmp97_);
			_vala_code_node_unref0 (_tmp94_);
			if (_tmp98_) {
				result = FALSE;
				_vala_code_node_unref0 (p);
				_vala_code_node_unref0 (param);
				_vala_iterator_unref0 (params_it);
				_vala_iterable_unref0 (parameters);
				return result;
			}
			_vala_code_node_unref0 (p);
			_vala_code_node_unref0 (param);
		}
	}
	_tmp99_ = params_it;
	if (vala_iterator_next (_tmp99_)) {
		result = FALSE;
		_vala_iterator_unref0 (params_it);
		_vala_iterable_unref0 (parameters);
		return result;
	}
	_tmp100_ = g_direct_equal;
	_tmp101_ = vala_array_list_new (VALA_TYPE_DATA_TYPE, (GBoxedCopyFunc) vala_code_node_ref, (GDestroyNotify) vala_code_node_unref, _tmp100_);
	error_types = _tmp101_;
	_tmp102_ = vala_delegate_type_get_delegate_symbol (self);
	_tmp103_ = _tmp102_;
	_tmp104_ = error_types;
	vala_code_node_get_error_types ((ValaCodeNode*) _tmp103_, (ValaCollection*) _tmp104_, NULL);
	{
		ValaArrayList* _error_type_list = NULL;
		ValaArrayList* _tmp105_;
		gint _error_type_size = 0;
		ValaArrayList* _tmp106_;
		gint _tmp107_;
		gint _tmp108_;
		gint _error_type_index = 0;
		_tmp105_ = error_types;
		_error_type_list = _tmp105_;
		_tmp106_ = _error_type_list;
		_tmp107_ = vala_collection_get_size ((ValaCollection*) _tmp106_);
		_tmp108_ = _tmp107_;
		_error_type_size = _tmp108_;
		_error_type_index = -1;
		while (TRUE) {
			gint _tmp109_;
			gint _tmp110_;
			ValaDataType* error_type = NULL;
			ValaArrayList* _tmp111_;
			gpointer _tmp112_;
			gboolean match = FALSE;
			ValaArrayList* delegate_error_types = NULL;
			GEqualFunc _tmp113_;
			ValaArrayList* _tmp114_;
			ValaDelegateType* _tmp115_;
			ValaDelegate* _tmp116_;
			ValaDelegate* _tmp117_;
			ValaArrayList* _tmp118_;
			_error_type_index = _error_type_index + 1;
			_tmp109_ = _error_type_index;
			_tmp110_ = _error_type_size;
			if (!(_tmp109_ < _tmp110_)) {
				break;
			}
			_tmp111_ = _error_type_list;
			_tmp112_ = vala_list_get ((ValaList*) _tmp111_, _error_type_index);
			error_type = (ValaDataType*) _tmp112_;
			match = FALSE;
			_tmp113_ = g_direct_equal;
			_tmp114_ = vala_array_list_new (VALA_TYPE_DATA_TYPE, (GBoxedCopyFunc) vala_code_node_ref, (GDestroyNotify) vala_code_node_unref, _tmp113_);
			delegate_error_types = _tmp114_;
			_tmp115_ = dt_target;
			_tmp116_ = vala_delegate_type_get_delegate_symbol (_tmp115_);
			_tmp117_ = _tmp116_;
			_tmp118_ = delegate_error_types;
			vala_code_node_get_error_types ((ValaCodeNode*) _tmp117_, (ValaCollection*) _tmp118_, NULL);
			{
				ValaArrayList* _delegate_error_type_list = NULL;
				ValaArrayList* _tmp119_;
				gint _delegate_error_type_size = 0;
				ValaArrayList* _tmp120_;
				gint _tmp121_;
				gint _tmp122_;
				gint _delegate_error_type_index = 0;
				_tmp119_ = delegate_error_types;
				_delegate_error_type_list = _tmp119_;
				_tmp120_ = _delegate_error_type_list;
				_tmp121_ = vala_collection_get_size ((ValaCollection*) _tmp120_);
				_tmp122_ = _tmp121_;
				_delegate_error_type_size = _tmp122_;
				_delegate_error_type_index = -1;
				while (TRUE) {
					gint _tmp123_;
					gint _tmp124_;
					ValaDataType* delegate_error_type = NULL;
					ValaArrayList* _tmp125_;
					gpointer _tmp126_;
					ValaDataType* _tmp127_;
					ValaDataType* _tmp128_;
					_delegate_error_type_index = _delegate_error_type_index + 1;
					_tmp123_ = _delegate_error_type_index;
					_tmp124_ = _delegate_error_type_size;
					if (!(_tmp123_ < _tmp124_)) {
						break;
					}
					_tmp125_ = _delegate_error_type_list;
					_tmp126_ = vala_list_get ((ValaList*) _tmp125_, _delegate_error_type_index);
					delegate_error_type = (ValaDataType*) _tmp126_;
					_tmp127_ = error_type;
					_tmp128_ = delegate_error_type;
					if (vala_data_type_compatible (_tmp127_, _tmp128_)) {
						match = TRUE;
						_vala_code_node_unref0 (delegate_error_type);
						break;
					}
					_vala_code_node_unref0 (delegate_error_type);
				}
			}
			if (!match) {
				result = FALSE;
				_vala_iterable_unref0 (delegate_error_types);
				_vala_code_node_unref0 (error_type);
				_vala_iterable_unref0 (error_types);
				_vala_iterator_unref0 (params_it);
				_vala_iterable_unref0 (parameters);
				return result;
			}
			_vala_iterable_unref0 (delegate_error_types);
			_vala_code_node_unref0 (error_type);
		}
	}
	result = TRUE;
	_vala_iterable_unref0 (error_types);
	_vala_iterator_unref0 (params_it);
	_vala_iterable_unref0 (parameters);
	return result;
}

static gboolean
vala_delegate_type_real_is_disposable (ValaDataType* base)
{
	ValaDelegateType * self;
	gboolean _tmp0_ = FALSE;
	gboolean _tmp1_ = FALSE;
	ValaDelegate* _tmp2_;
	ValaDelegate* _tmp3_;
	gboolean _tmp4_;
	gboolean _tmp5_;
	gboolean result;
	self = (ValaDelegateType*) base;
	_tmp2_ = vala_delegate_type_get_delegate_symbol (self);
	_tmp3_ = _tmp2_;
	_tmp4_ = vala_delegate_get_has_target (_tmp3_);
	_tmp5_ = _tmp4_;
	if (_tmp5_) {
		gboolean _tmp6_;
		gboolean _tmp7_;
		_tmp6_ = vala_data_type_get_value_owned ((ValaDataType*) self);
		_tmp7_ = _tmp6_;
		_tmp1_ = _tmp7_;
	} else {
		_tmp1_ = FALSE;
	}
	if (_tmp1_) {
		gboolean _tmp8_;
		_tmp8_ = self->priv->_is_called_once;
		_tmp0_ = !_tmp8_;
	} else {
		_tmp0_ = FALSE;
	}
	result = _tmp0_;
	return result;
}

static void
vala_delegate_type_class_init (ValaDelegateTypeClass * klass,
                               gpointer klass_data)
{
	vala_delegate_type_parent_class = g_type_class_peek_parent (klass);
	((ValaCodeNodeClass *) klass)->finalize = vala_delegate_type_finalize;
	g_type_class_adjust_private_offset (klass, &ValaDelegateType_private_offset);
	((ValaDataTypeClass *) klass)->get_member = (ValaSymbol* (*) (ValaDataType*, const gchar*)) vala_delegate_type_real_get_member;
	((ValaDataTypeClass *) klass)->copy = (ValaDataType* (*) (ValaDataType*)) vala_delegate_type_real_copy;
	((ValaDataTypeClass *) klass)->equals = (gboolean (*) (ValaDataType*, ValaDataType*)) vala_delegate_type_real_equals;
	((ValaDataTypeClass *) klass)->is_accessible = (gboolean (*) (ValaDataType*, ValaSymbol*)) vala_delegate_type_real_is_accessible;
	((ValaCodeNodeClass *) klass)->check = (gboolean (*) (ValaCodeNode*, ValaCodeContext*)) vala_delegate_type_real_check;
	((ValaDataTypeClass *) klass)->compatible = (gboolean (*) (ValaDataType*, ValaDataType*)) vala_delegate_type_real_compatible;
	((ValaDataTypeClass *) klass)->is_disposable = (gboolean (*) (ValaDataType*)) vala_delegate_type_real_is_disposable;
}

static void
vala_delegate_type_instance_init (ValaDelegateType * self,
                                  gpointer klass)
{
	self->priv = vala_delegate_type_get_instance_private (self);
}

static void
vala_delegate_type_finalize (ValaCodeNode * obj)
{
	ValaDelegateType * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, VALA_TYPE_DELEGATE_TYPE, ValaDelegateType);
	_vala_code_node_unref0 (self->priv->target_field);
	_vala_code_node_unref0 (self->priv->destroy_field);
	VALA_CODE_NODE_CLASS (vala_delegate_type_parent_class)->finalize (obj);
}

/**
 * The type of an instance of a delegate.
 */
static GType
vala_delegate_type_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (ValaDelegateTypeClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) vala_delegate_type_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (ValaDelegateType), 0, (GInstanceInitFunc) vala_delegate_type_instance_init, NULL };
	GType vala_delegate_type_type_id;
	vala_delegate_type_type_id = g_type_register_static (VALA_TYPE_CALLABLE_TYPE, "ValaDelegateType", &g_define_type_info, 0);
	ValaDelegateType_private_offset = g_type_add_instance_private (vala_delegate_type_type_id, sizeof (ValaDelegateTypePrivate));
	return vala_delegate_type_type_id;
}

GType
vala_delegate_type_get_type (void)
{
	static volatile gsize vala_delegate_type_type_id__once = 0;
	if (g_once_init_enter (&vala_delegate_type_type_id__once)) {
		GType vala_delegate_type_type_id;
		vala_delegate_type_type_id = vala_delegate_type_get_type_once ();
		g_once_init_leave (&vala_delegate_type_type_id__once, vala_delegate_type_type_id);
	}
	return vala_delegate_type_type_id__once;
}

