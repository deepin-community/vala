/* valaccodefunction.c generated by valac, the Vala compiler
 * generated from valaccodefunction.vala, do not modify */

/* valaccodefunction.vala
 *
 * Copyright (C) 2006-2012  Jürg Billeter
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

#include "valaccode.h"
#include <stdlib.h>
#include <string.h>
#include <glib.h>
#include <valagee.h>
#include <glib-object.h>

#define _g_free0(var) (var = (g_free (var), NULL))
#define _vala_ccode_node_unref0(var) ((var == NULL) ? NULL : (var = (vala_ccode_node_unref (var), NULL)))
#define _vala_iterable_unref0(var) ((var == NULL) ? NULL : (var = (vala_iterable_unref (var), NULL)))
#define _vala_assert(expr, msg) if G_LIKELY (expr) ; else g_assertion_message_expr (G_LOG_DOMAIN, __FILE__, __LINE__, G_STRFUNC, msg);
#define _vala_return_if_fail(expr, msg) if G_LIKELY (expr) ; else { g_return_if_fail_warning (G_LOG_DOMAIN, G_STRFUNC, msg); return; }
#define _vala_return_val_if_fail(expr, msg, val) if G_LIKELY (expr) ; else { g_return_if_fail_warning (G_LOG_DOMAIN, G_STRFUNC, msg); return val; }
#define _vala_warn_if_fail(expr, msg) if G_LIKELY (expr) ; else g_warn_message (G_LOG_DOMAIN, __FILE__, __LINE__, G_STRFUNC, msg);

struct _ValaCCodeFunctionPrivate {
	gchar* _name;
	gchar* _return_type;
	gboolean _is_declaration;
	ValaCCodeBlock* _block;
	ValaCCodeLineDirective* _current_line;
	ValaCCodeBlock* _current_block;
	ValaList* parameters;
	ValaList* statement_stack;
};

static gint ValaCCodeFunction_private_offset;
static gpointer vala_ccode_function_parent_class = NULL;

static void vala_ccode_function_real_write (ValaCCodeNode* base,
                                     ValaCCodeWriter* writer);
static void vala_ccode_function_finalize (ValaCCodeNode * obj);
static GType vala_ccode_function_get_type_once (void);

static inline gpointer
vala_ccode_function_get_instance_private (ValaCCodeFunction* self)
{
	return G_STRUCT_MEMBER_P (self, ValaCCodeFunction_private_offset);
}

const gchar*
vala_ccode_function_get_name (ValaCCodeFunction* self)
{
	const gchar* result;
	const gchar* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_name;
	result = _tmp0_;
	return result;
}

void
vala_ccode_function_set_name (ValaCCodeFunction* self,
                              const gchar* value)
{
	gchar* _tmp0_;
	g_return_if_fail (self != NULL);
	_tmp0_ = g_strdup (value);
	_g_free0 (self->priv->_name);
	self->priv->_name = _tmp0_;
}

const gchar*
vala_ccode_function_get_return_type (ValaCCodeFunction* self)
{
	const gchar* result;
	const gchar* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_return_type;
	result = _tmp0_;
	return result;
}

void
vala_ccode_function_set_return_type (ValaCCodeFunction* self,
                                     const gchar* value)
{
	gchar* _tmp0_;
	g_return_if_fail (self != NULL);
	_tmp0_ = g_strdup (value);
	_g_free0 (self->priv->_return_type);
	self->priv->_return_type = _tmp0_;
}

gboolean
vala_ccode_function_get_is_declaration (ValaCCodeFunction* self)
{
	gboolean result;
	g_return_val_if_fail (self != NULL, FALSE);
	result = self->priv->_is_declaration;
	return result;
}

void
vala_ccode_function_set_is_declaration (ValaCCodeFunction* self,
                                        gboolean value)
{
	g_return_if_fail (self != NULL);
	self->priv->_is_declaration = value;
}

ValaCCodeBlock*
vala_ccode_function_get_block (ValaCCodeFunction* self)
{
	ValaCCodeBlock* result;
	ValaCCodeBlock* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_block;
	result = _tmp0_;
	return result;
}

static gpointer
_vala_ccode_node_ref0 (gpointer self)
{
	return self ? vala_ccode_node_ref (self) : NULL;
}

void
vala_ccode_function_set_block (ValaCCodeFunction* self,
                               ValaCCodeBlock* value)
{
	ValaCCodeBlock* _tmp0_;
	g_return_if_fail (self != NULL);
	_tmp0_ = _vala_ccode_node_ref0 (value);
	_vala_ccode_node_unref0 (self->priv->_block);
	self->priv->_block = _tmp0_;
}

ValaCCodeLineDirective*
vala_ccode_function_get_current_line (ValaCCodeFunction* self)
{
	ValaCCodeLineDirective* result;
	ValaCCodeLineDirective* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_current_line;
	result = _tmp0_;
	return result;
}

void
vala_ccode_function_set_current_line (ValaCCodeFunction* self,
                                      ValaCCodeLineDirective* value)
{
	ValaCCodeLineDirective* _tmp0_;
	g_return_if_fail (self != NULL);
	_tmp0_ = _vala_ccode_node_ref0 (value);
	_vala_ccode_node_unref0 (self->priv->_current_line);
	self->priv->_current_line = _tmp0_;
}

ValaCCodeBlock*
vala_ccode_function_get_current_block (ValaCCodeFunction* self)
{
	ValaCCodeBlock* result;
	ValaCCodeBlock* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_current_block;
	result = _tmp0_;
	return result;
}

void
vala_ccode_function_set_current_block (ValaCCodeFunction* self,
                                       ValaCCodeBlock* value)
{
	ValaCCodeBlock* _tmp0_;
	g_return_if_fail (self != NULL);
	_tmp0_ = _vala_ccode_node_ref0 (value);
	_vala_ccode_node_unref0 (self->priv->_current_block);
	self->priv->_current_block = _tmp0_;
}

ValaCCodeFunction*
vala_ccode_function_construct (GType object_type,
                               const gchar* name,
                               const gchar* return_type)
{
	ValaCCodeFunction* self = NULL;
	ValaCCodeBlock* _tmp0_;
	ValaCCodeBlock* _tmp1_;
	ValaCCodeBlock* _tmp2_;
	g_return_val_if_fail (name != NULL, NULL);
	g_return_val_if_fail (return_type != NULL, NULL);
	self = (ValaCCodeFunction*) vala_ccode_node_construct (object_type);
	vala_ccode_function_set_name (self, name);
	vala_ccode_function_set_return_type (self, return_type);
	_tmp0_ = vala_ccode_block_new ();
	_tmp1_ = _tmp0_;
	vala_ccode_function_set_block (self, _tmp1_);
	_vala_ccode_node_unref0 (_tmp1_);
	_tmp2_ = self->priv->_block;
	vala_ccode_function_set_current_block (self, _tmp2_);
	return self;
}

ValaCCodeFunction*
vala_ccode_function_new (const gchar* name,
                         const gchar* return_type)
{
	return vala_ccode_function_construct (VALA_TYPE_CCODE_FUNCTION, name, return_type);
}

/**
 * Appends the specified parameter to the list of function parameters.
 *
 * @param param a formal parameter
 */
void
vala_ccode_function_add_parameter (ValaCCodeFunction* self,
                                   ValaCCodeParameter* param)
{
	ValaList* _tmp0_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (param != NULL);
	_tmp0_ = self->priv->parameters;
	vala_collection_add ((ValaCollection*) _tmp0_, param);
}

void
vala_ccode_function_insert_parameter (ValaCCodeFunction* self,
                                      gint position,
                                      ValaCCodeParameter* param)
{
	ValaList* _tmp0_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (param != NULL);
	_tmp0_ = self->priv->parameters;
	vala_list_insert (_tmp0_, position, param);
}

gint
vala_ccode_function_get_parameter_count (ValaCCodeFunction* self)
{
	ValaList* _tmp0_;
	gint _tmp1_;
	gint _tmp2_;
	gint result = 0;
	g_return_val_if_fail (self != NULL, 0);
	_tmp0_ = self->priv->parameters;
	_tmp1_ = vala_collection_get_size ((ValaCollection*) _tmp0_);
	_tmp2_ = _tmp1_;
	result = _tmp2_;
	return result;
}

ValaCCodeParameter*
vala_ccode_function_get_parameter (ValaCCodeFunction* self,
                                   gint position)
{
	ValaList* _tmp0_;
	gpointer _tmp1_;
	ValaCCodeParameter* result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->parameters;
	_tmp1_ = vala_list_get (_tmp0_, position);
	result = (ValaCCodeParameter*) _tmp1_;
	return result;
}

/**
 * Returns a copy of this function.
 *
 * @return copied function
 */
ValaCCodeFunction*
vala_ccode_function_copy (ValaCCodeFunction* self)
{
	ValaCCodeFunction* func = NULL;
	const gchar* _tmp0_;
	const gchar* _tmp1_;
	ValaCCodeFunction* _tmp2_;
	ValaCCodeFunction* _tmp3_;
	ValaCCodeModifiers _tmp4_;
	ValaCCodeModifiers _tmp5_;
	ValaCCodeFunction* _tmp17_;
	gboolean _tmp18_;
	ValaCCodeFunction* _tmp19_;
	ValaCCodeBlock* _tmp20_;
	ValaCCodeFunction* result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_name;
	_tmp1_ = self->priv->_return_type;
	_tmp2_ = vala_ccode_function_new (_tmp0_, _tmp1_);
	func = _tmp2_;
	_tmp3_ = func;
	_tmp4_ = vala_ccode_node_get_modifiers ((ValaCCodeNode*) self);
	_tmp5_ = _tmp4_;
	vala_ccode_node_set_modifiers ((ValaCCodeNode*) _tmp3_, _tmp5_);
	{
		ValaList* _param_list = NULL;
		ValaList* _tmp6_;
		gint _param_size = 0;
		ValaList* _tmp7_;
		gint _tmp8_;
		gint _tmp9_;
		gint _param_index = 0;
		_tmp6_ = self->priv->parameters;
		_param_list = _tmp6_;
		_tmp7_ = _param_list;
		_tmp8_ = vala_collection_get_size ((ValaCollection*) _tmp7_);
		_tmp9_ = _tmp8_;
		_param_size = _tmp9_;
		_param_index = -1;
		while (TRUE) {
			gint _tmp10_;
			gint _tmp11_;
			ValaCCodeParameter* param = NULL;
			ValaList* _tmp12_;
			gpointer _tmp13_;
			ValaCCodeFunction* _tmp14_;
			ValaList* _tmp15_;
			ValaCCodeParameter* _tmp16_;
			_param_index = _param_index + 1;
			_tmp10_ = _param_index;
			_tmp11_ = _param_size;
			if (!(_tmp10_ < _tmp11_)) {
				break;
			}
			_tmp12_ = _param_list;
			_tmp13_ = vala_list_get (_tmp12_, _param_index);
			param = (ValaCCodeParameter*) _tmp13_;
			_tmp14_ = func;
			_tmp15_ = _tmp14_->priv->parameters;
			_tmp16_ = param;
			vala_collection_add ((ValaCollection*) _tmp15_, _tmp16_);
			_vala_ccode_node_unref0 (param);
		}
	}
	_tmp17_ = func;
	_tmp18_ = self->priv->_is_declaration;
	vala_ccode_function_set_is_declaration (_tmp17_, _tmp18_);
	_tmp19_ = func;
	_tmp20_ = self->priv->_block;
	vala_ccode_function_set_block (_tmp19_, _tmp20_);
	result = func;
	return result;
}

static void
vala_ccode_function_real_write (ValaCCodeNode* base,
                                ValaCCodeWriter* writer)
{
	ValaCCodeFunction * self;
	ValaCCodeLineDirective* _tmp0_;
	ValaCCodeLineDirective* _tmp1_;
	ValaCCodeModifiers _tmp2_;
	ValaCCodeModifiers _tmp3_;
	gboolean _tmp9_ = FALSE;
	gboolean _tmp10_;
	ValaCCodeModifiers _tmp14_;
	ValaCCodeModifiers _tmp15_;
	ValaCCodeModifiers _tmp16_;
	ValaCCodeModifiers _tmp17_;
	const gchar* _tmp18_;
	gboolean _tmp19_;
	const gchar* _tmp20_;
	gint _tmp21_ = 0;
	gboolean _tmp22_;
	gint param_pos_begin = 0;
	const gchar* _tmp24_;
	gboolean _tmp25_ = FALSE;
	ValaCCodeModifiers _tmp26_;
	ValaCCodeModifiers _tmp27_;
	gboolean has_args = FALSE;
	gint i = 0;
	gint format_arg_index = 0;
	gint args_index = 0;
	gboolean _tmp52_;
	self = (ValaCCodeFunction*) base;
	g_return_if_fail (writer != NULL);
	_tmp0_ = vala_ccode_node_get_line ((ValaCCodeNode*) self);
	_tmp1_ = _tmp0_;
	vala_ccode_writer_write_indent (writer, _tmp1_);
	_tmp2_ = vala_ccode_node_get_modifiers ((ValaCCodeNode*) self);
	_tmp3_ = _tmp2_;
	if ((_tmp3_ & VALA_CCODE_MODIFIERS_INTERNAL) == VALA_CCODE_MODIFIERS_INTERNAL) {
		const gchar* _tmp4_;
		_tmp4_ = vala_GNUC_INTERNAL;
		vala_ccode_writer_write_string (writer, _tmp4_);
	} else {
		gboolean _tmp5_ = FALSE;
		gboolean _tmp6_;
		_tmp6_ = self->priv->_is_declaration;
		if (_tmp6_) {
			ValaCCodeModifiers _tmp7_;
			ValaCCodeModifiers _tmp8_;
			_tmp7_ = vala_ccode_node_get_modifiers ((ValaCCodeNode*) self);
			_tmp8_ = _tmp7_;
			_tmp5_ = (_tmp8_ & VALA_CCODE_MODIFIERS_EXTERN) == VALA_CCODE_MODIFIERS_EXTERN;
		} else {
			_tmp5_ = FALSE;
		}
		if (_tmp5_) {
			vala_ccode_writer_write_string (writer, "VALA_EXTERN ");
		}
	}
	_tmp10_ = self->priv->_is_declaration;
	if (!_tmp10_) {
		ValaCCodeModifiers _tmp11_;
		ValaCCodeModifiers _tmp12_;
		_tmp11_ = vala_ccode_node_get_modifiers ((ValaCCodeNode*) self);
		_tmp12_ = _tmp11_;
		_tmp9_ = (_tmp12_ & VALA_CCODE_MODIFIERS_NO_INLINE) == VALA_CCODE_MODIFIERS_NO_INLINE;
	} else {
		_tmp9_ = FALSE;
	}
	if (_tmp9_) {
		const gchar* _tmp13_;
		_tmp13_ = vala_GNUC_NO_INLINE;
		vala_ccode_writer_write_string (writer, _tmp13_);
	}
	_tmp14_ = vala_ccode_node_get_modifiers ((ValaCCodeNode*) self);
	_tmp15_ = _tmp14_;
	if ((_tmp15_ & VALA_CCODE_MODIFIERS_STATIC) == VALA_CCODE_MODIFIERS_STATIC) {
		vala_ccode_writer_write_string (writer, "static ");
	}
	_tmp16_ = vala_ccode_node_get_modifiers ((ValaCCodeNode*) self);
	_tmp17_ = _tmp16_;
	if ((_tmp17_ & VALA_CCODE_MODIFIERS_INLINE) == VALA_CCODE_MODIFIERS_INLINE) {
		vala_ccode_writer_write_string (writer, "inline ");
	}
	_tmp18_ = self->priv->_return_type;
	vala_ccode_writer_write_string (writer, _tmp18_);
	_tmp19_ = self->priv->_is_declaration;
	if (_tmp19_) {
		vala_ccode_writer_write_string (writer, " ");
	} else {
		vala_ccode_writer_write_newline (writer);
	}
	_tmp20_ = self->priv->_name;
	vala_ccode_writer_write_string (writer, _tmp20_);
	vala_ccode_writer_write_string (writer, " (");
	_tmp22_ = self->priv->_is_declaration;
	if (_tmp22_) {
		const gchar* _tmp23_;
		_tmp23_ = self->priv->_return_type;
		_tmp21_ = g_utf8_strlen (_tmp23_, (gssize) -1) + 1;
	} else {
		_tmp21_ = 0;
	}
	_tmp24_ = self->priv->_name;
	param_pos_begin = (_tmp21_ + g_utf8_strlen (_tmp24_, (gssize) -1)) + 2;
	_tmp26_ = vala_ccode_node_get_modifiers ((ValaCCodeNode*) self);
	_tmp27_ = _tmp26_;
	if ((_tmp27_ & VALA_CCODE_MODIFIERS_PRINTF) == VALA_CCODE_MODIFIERS_PRINTF) {
		_tmp25_ = TRUE;
	} else {
		ValaCCodeModifiers _tmp28_;
		ValaCCodeModifiers _tmp29_;
		_tmp28_ = vala_ccode_node_get_modifiers ((ValaCCodeNode*) self);
		_tmp29_ = _tmp28_;
		_tmp25_ = (_tmp29_ & VALA_CCODE_MODIFIERS_SCANF) == VALA_CCODE_MODIFIERS_SCANF;
	}
	has_args = _tmp25_;
	i = 0;
	format_arg_index = -1;
	args_index = -1;
	{
		ValaList* _param_list = NULL;
		ValaList* _tmp30_;
		gint _param_size = 0;
		ValaList* _tmp31_;
		gint _tmp32_;
		gint _tmp33_;
		gint _param_index = 0;
		_tmp30_ = self->priv->parameters;
		_param_list = _tmp30_;
		_tmp31_ = _param_list;
		_tmp32_ = vala_collection_get_size ((ValaCollection*) _tmp31_);
		_tmp33_ = _tmp32_;
		_param_size = _tmp33_;
		_param_index = -1;
		while (TRUE) {
			gint _tmp34_;
			gint _tmp35_;
			ValaCCodeParameter* param = NULL;
			ValaList* _tmp36_;
			gpointer _tmp37_;
			ValaCCodeParameter* _tmp38_;
			ValaCCodeParameter* _tmp39_;
			ValaCCodeModifiers _tmp40_;
			ValaCCodeModifiers _tmp41_;
			gboolean _tmp42_ = FALSE;
			gint _tmp51_;
			_param_index = _param_index + 1;
			_tmp34_ = _param_index;
			_tmp35_ = _param_size;
			if (!(_tmp34_ < _tmp35_)) {
				break;
			}
			_tmp36_ = _param_list;
			_tmp37_ = vala_list_get (_tmp36_, _param_index);
			param = (ValaCCodeParameter*) _tmp37_;
			if (i > 0) {
				vala_ccode_writer_write_string (writer, ",");
				vala_ccode_writer_write_newline (writer);
				vala_ccode_writer_write_nspaces (writer, (guint) param_pos_begin);
			}
			_tmp38_ = param;
			vala_ccode_node_write ((ValaCCodeNode*) _tmp38_, writer);
			_tmp39_ = param;
			_tmp40_ = vala_ccode_node_get_modifiers ((ValaCCodeNode*) _tmp39_);
			_tmp41_ = _tmp40_;
			if ((_tmp41_ & VALA_CCODE_MODIFIERS_FORMAT_ARG) == VALA_CCODE_MODIFIERS_FORMAT_ARG) {
				format_arg_index = i;
			}
			if (has_args) {
				ValaCCodeParameter* _tmp43_;
				gboolean _tmp44_;
				gboolean _tmp45_;
				_tmp43_ = param;
				_tmp44_ = vala_ccode_parameter_get_ellipsis (_tmp43_);
				_tmp45_ = _tmp44_;
				_tmp42_ = _tmp45_;
			} else {
				_tmp42_ = FALSE;
			}
			if (_tmp42_) {
				args_index = i;
			} else {
				gboolean _tmp46_ = FALSE;
				gboolean _tmp47_ = FALSE;
				if (has_args) {
					ValaCCodeParameter* _tmp48_;
					const gchar* _tmp49_;
					const gchar* _tmp50_;
					_tmp48_ = param;
					_tmp49_ = vala_ccode_parameter_get_type_name (_tmp48_);
					_tmp50_ = _tmp49_;
					_tmp47_ = g_strcmp0 (_tmp50_, "va_list") == 0;
				} else {
					_tmp47_ = FALSE;
				}
				if (_tmp47_) {
					_tmp46_ = format_arg_index < 0;
				} else {
					_tmp46_ = FALSE;
				}
				if (_tmp46_) {
					format_arg_index = i - 1;
				}
			}
			_tmp51_ = i;
			i = _tmp51_ + 1;
			_vala_ccode_node_unref0 (param);
		}
	}
	if (i == 0) {
		vala_ccode_writer_write_string (writer, "void");
	}
	vala_ccode_writer_write_string (writer, ")");
	_tmp52_ = self->priv->_is_declaration;
	if (_tmp52_) {
		ValaCCodeModifiers _tmp53_;
		ValaCCodeModifiers _tmp54_;
		ValaCCodeModifiers _tmp56_;
		ValaCCodeModifiers _tmp57_;
		ValaCCodeModifiers _tmp71_;
		ValaCCodeModifiers _tmp72_;
		ValaCCodeModifiers _tmp74_;
		ValaCCodeModifiers _tmp75_;
		ValaCCodeModifiers _tmp77_;
		ValaCCodeModifiers _tmp78_;
		_tmp53_ = vala_ccode_node_get_modifiers ((ValaCCodeNode*) self);
		_tmp54_ = _tmp53_;
		if ((_tmp54_ & VALA_CCODE_MODIFIERS_DEPRECATED) == VALA_CCODE_MODIFIERS_DEPRECATED) {
			const gchar* _tmp55_;
			_tmp55_ = vala_GNUC_DEPRECATED;
			vala_ccode_writer_write_string (writer, _tmp55_);
		}
		_tmp56_ = vala_ccode_node_get_modifiers ((ValaCCodeNode*) self);
		_tmp57_ = _tmp56_;
		if ((_tmp57_ & VALA_CCODE_MODIFIERS_PRINTF) == VALA_CCODE_MODIFIERS_PRINTF) {
			gint _tmp58_ = 0;
			const gchar* _tmp59_;
			gchar* _tmp60_;
			gchar* _tmp61_;
			if (format_arg_index >= 0) {
				_tmp58_ = format_arg_index + 1;
			} else {
				_tmp58_ = args_index;
			}
			format_arg_index = _tmp58_;
			_tmp59_ = vala_GNUC_PRINTF;
			_tmp60_ = g_strdup_printf (_tmp59_, format_arg_index, args_index + 1);
			_tmp61_ = _tmp60_;
			vala_ccode_writer_write_string (writer, _tmp61_);
			_g_free0 (_tmp61_);
		} else {
			ValaCCodeModifiers _tmp62_;
			ValaCCodeModifiers _tmp63_;
			_tmp62_ = vala_ccode_node_get_modifiers ((ValaCCodeNode*) self);
			_tmp63_ = _tmp62_;
			if ((_tmp63_ & VALA_CCODE_MODIFIERS_SCANF) == VALA_CCODE_MODIFIERS_SCANF) {
				gint _tmp64_ = 0;
				const gchar* _tmp65_;
				gchar* _tmp66_;
				gchar* _tmp67_;
				if (format_arg_index >= 0) {
					_tmp64_ = format_arg_index + 1;
				} else {
					_tmp64_ = args_index;
				}
				format_arg_index = _tmp64_;
				_tmp65_ = vala_GNUC_SCANF;
				_tmp66_ = g_strdup_printf (_tmp65_, format_arg_index, args_index + 1);
				_tmp67_ = _tmp66_;
				vala_ccode_writer_write_string (writer, _tmp67_);
				_g_free0 (_tmp67_);
			} else {
				if (format_arg_index >= 0) {
					const gchar* _tmp68_;
					gchar* _tmp69_;
					gchar* _tmp70_;
					_tmp68_ = vala_GNUC_FORMAT;
					_tmp69_ = g_strdup_printf (_tmp68_, format_arg_index + 1);
					_tmp70_ = _tmp69_;
					vala_ccode_writer_write_string (writer, _tmp70_);
					_g_free0 (_tmp70_);
				}
			}
		}
		_tmp71_ = vala_ccode_node_get_modifiers ((ValaCCodeNode*) self);
		_tmp72_ = _tmp71_;
		if ((_tmp72_ & VALA_CCODE_MODIFIERS_CONST) == VALA_CCODE_MODIFIERS_CONST) {
			const gchar* _tmp73_;
			_tmp73_ = vala_GNUC_CONST;
			vala_ccode_writer_write_string (writer, _tmp73_);
		}
		_tmp74_ = vala_ccode_node_get_modifiers ((ValaCCodeNode*) self);
		_tmp75_ = _tmp74_;
		if ((_tmp75_ & VALA_CCODE_MODIFIERS_UNUSED) == VALA_CCODE_MODIFIERS_UNUSED) {
			const gchar* _tmp76_;
			_tmp76_ = vala_GNUC_UNUSED;
			vala_ccode_writer_write_string (writer, _tmp76_);
		}
		_tmp77_ = vala_ccode_node_get_modifiers ((ValaCCodeNode*) self);
		_tmp78_ = _tmp77_;
		if ((_tmp78_ & VALA_CCODE_MODIFIERS_CONSTRUCTOR) == VALA_CCODE_MODIFIERS_CONSTRUCTOR) {
			vala_ccode_writer_write_string (writer, " __attribute__((constructor))");
		} else {
			ValaCCodeModifiers _tmp79_;
			ValaCCodeModifiers _tmp80_;
			_tmp79_ = vala_ccode_node_get_modifiers ((ValaCCodeNode*) self);
			_tmp80_ = _tmp79_;
			if ((_tmp80_ & VALA_CCODE_MODIFIERS_DESTRUCTOR) == VALA_CCODE_MODIFIERS_DESTRUCTOR) {
				vala_ccode_writer_write_string (writer, " __attribute__((destructor))");
			}
		}
		vala_ccode_writer_write_string (writer, ";");
	} else {
		ValaCCodeBlock* _tmp81_;
		vala_ccode_writer_write_newline (writer);
		_tmp81_ = self->priv->_block;
		vala_ccode_node_write ((ValaCCodeNode*) _tmp81_, writer);
		vala_ccode_writer_write_newline (writer);
	}
	vala_ccode_writer_write_newline (writer);
}

void
vala_ccode_function_add_statement (ValaCCodeFunction* self,
                                   ValaCCodeNode* stmt)
{
	ValaCCodeLineDirective* _tmp0_;
	ValaCCodeBlock* _tmp1_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (stmt != NULL);
	_tmp0_ = self->priv->_current_line;
	vala_ccode_node_set_line (stmt, _tmp0_);
	_tmp1_ = self->priv->_current_block;
	vala_ccode_block_add_statement (_tmp1_, stmt);
}

void
vala_ccode_function_open_block (ValaCCodeFunction* self)
{
	ValaList* _tmp0_;
	ValaCCodeBlock* _tmp1_;
	ValaCCodeBlock* parent_block = NULL;
	ValaCCodeBlock* _tmp2_;
	ValaCCodeBlock* _tmp3_;
	ValaCCodeBlock* _tmp4_;
	ValaCCodeBlock* _tmp5_;
	ValaCCodeBlock* _tmp6_;
	g_return_if_fail (self != NULL);
	_tmp0_ = self->priv->statement_stack;
	_tmp1_ = self->priv->_current_block;
	vala_collection_add ((ValaCollection*) _tmp0_, (ValaCCodeStatement*) _tmp1_);
	_tmp2_ = self->priv->_current_block;
	_tmp3_ = _vala_ccode_node_ref0 (_tmp2_);
	parent_block = _tmp3_;
	_tmp4_ = vala_ccode_block_new ();
	_tmp5_ = _tmp4_;
	vala_ccode_function_set_current_block (self, _tmp5_);
	_vala_ccode_node_unref0 (_tmp5_);
	_tmp6_ = self->priv->_current_block;
	vala_ccode_block_add_statement (parent_block, (ValaCCodeNode*) _tmp6_);
	_vala_ccode_node_unref0 (parent_block);
}

void
vala_ccode_function_open_if (ValaCCodeFunction* self,
                             ValaCCodeExpression* condition)
{
	ValaList* _tmp0_;
	ValaCCodeBlock* _tmp1_;
	ValaCCodeBlock* parent_block = NULL;
	ValaCCodeBlock* _tmp2_;
	ValaCCodeBlock* _tmp3_;
	ValaCCodeBlock* _tmp4_;
	ValaCCodeBlock* _tmp5_;
	ValaCCodeIfStatement* cif = NULL;
	ValaCCodeBlock* _tmp6_;
	ValaCCodeIfStatement* _tmp7_;
	ValaCCodeLineDirective* _tmp8_;
	ValaList* _tmp9_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (condition != NULL);
	_tmp0_ = self->priv->statement_stack;
	_tmp1_ = self->priv->_current_block;
	vala_collection_add ((ValaCollection*) _tmp0_, (ValaCCodeStatement*) _tmp1_);
	_tmp2_ = self->priv->_current_block;
	_tmp3_ = _vala_ccode_node_ref0 (_tmp2_);
	parent_block = _tmp3_;
	_tmp4_ = vala_ccode_block_new ();
	_tmp5_ = _tmp4_;
	vala_ccode_function_set_current_block (self, _tmp5_);
	_vala_ccode_node_unref0 (_tmp5_);
	_tmp6_ = self->priv->_current_block;
	_tmp7_ = vala_ccode_if_statement_new (condition, (ValaCCodeStatement*) _tmp6_, NULL);
	cif = _tmp7_;
	_tmp8_ = self->priv->_current_line;
	vala_ccode_node_set_line ((ValaCCodeNode*) cif, _tmp8_);
	_tmp9_ = self->priv->statement_stack;
	vala_collection_add ((ValaCollection*) _tmp9_, (ValaCCodeStatement*) cif);
	vala_ccode_block_add_statement (parent_block, (ValaCCodeNode*) cif);
	_vala_ccode_node_unref0 (cif);
	_vala_ccode_node_unref0 (parent_block);
}

void
vala_ccode_function_add_else (ValaCCodeFunction* self)
{
	ValaCCodeBlock* _tmp0_;
	ValaCCodeBlock* _tmp1_;
	ValaCCodeIfStatement* cif = NULL;
	ValaList* _tmp2_;
	ValaList* _tmp3_;
	gint _tmp4_;
	gint _tmp5_;
	gpointer _tmp6_;
	ValaCCodeLineDirective* _tmp7_;
	ValaCCodeStatement* _tmp8_;
	ValaCCodeStatement* _tmp9_;
	ValaCCodeBlock* _tmp10_;
	g_return_if_fail (self != NULL);
	_tmp0_ = vala_ccode_block_new ();
	_tmp1_ = _tmp0_;
	vala_ccode_function_set_current_block (self, _tmp1_);
	_vala_ccode_node_unref0 (_tmp1_);
	_tmp2_ = self->priv->statement_stack;
	_tmp3_ = self->priv->statement_stack;
	_tmp4_ = vala_collection_get_size ((ValaCollection*) _tmp3_);
	_tmp5_ = _tmp4_;
	_tmp6_ = vala_list_get (_tmp2_, _tmp5_ - 1);
	cif = G_TYPE_CHECK_INSTANCE_CAST ((ValaCCodeStatement*) _tmp6_, VALA_TYPE_CCODE_IF_STATEMENT, ValaCCodeIfStatement);
	_tmp7_ = self->priv->_current_line;
	vala_ccode_node_set_line ((ValaCCodeNode*) cif, _tmp7_);
	_tmp8_ = vala_ccode_if_statement_get_false_statement (cif);
	_tmp9_ = _tmp8_;
	_vala_assert (_tmp9_ == NULL, "cif.false_statement == null");
	_tmp10_ = self->priv->_current_block;
	vala_ccode_if_statement_set_false_statement (cif, (ValaCCodeStatement*) _tmp10_);
	_vala_ccode_node_unref0 (cif);
}

void
vala_ccode_function_else_if (ValaCCodeFunction* self,
                             ValaCCodeExpression* condition)
{
	ValaCCodeIfStatement* parent_if = NULL;
	ValaList* _tmp0_;
	ValaList* _tmp1_;
	gint _tmp2_;
	gint _tmp3_;
	gpointer _tmp4_;
	ValaCCodeStatement* _tmp5_;
	ValaCCodeStatement* _tmp6_;
	ValaCCodeBlock* _tmp7_;
	ValaCCodeBlock* _tmp8_;
	ValaCCodeIfStatement* cif = NULL;
	ValaCCodeBlock* _tmp9_;
	ValaCCodeIfStatement* _tmp10_;
	ValaCCodeLineDirective* _tmp11_;
	ValaList* _tmp12_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (condition != NULL);
	_tmp0_ = self->priv->statement_stack;
	_tmp1_ = self->priv->statement_stack;
	_tmp2_ = vala_collection_get_size ((ValaCollection*) _tmp1_);
	_tmp3_ = _tmp2_;
	_tmp4_ = vala_list_remove_at (_tmp0_, _tmp3_ - 1);
	parent_if = G_TYPE_CHECK_INSTANCE_CAST ((ValaCCodeStatement*) _tmp4_, VALA_TYPE_CCODE_IF_STATEMENT, ValaCCodeIfStatement);
	_tmp5_ = vala_ccode_if_statement_get_false_statement (parent_if);
	_tmp6_ = _tmp5_;
	_vala_assert (_tmp6_ == NULL, "parent_if.false_statement == null");
	_tmp7_ = vala_ccode_block_new ();
	_tmp8_ = _tmp7_;
	vala_ccode_function_set_current_block (self, _tmp8_);
	_vala_ccode_node_unref0 (_tmp8_);
	_tmp9_ = self->priv->_current_block;
	_tmp10_ = vala_ccode_if_statement_new (condition, (ValaCCodeStatement*) _tmp9_, NULL);
	cif = _tmp10_;
	_tmp11_ = self->priv->_current_line;
	vala_ccode_node_set_line ((ValaCCodeNode*) cif, _tmp11_);
	vala_ccode_if_statement_set_false_statement (parent_if, (ValaCCodeStatement*) cif);
	_tmp12_ = self->priv->statement_stack;
	vala_collection_add ((ValaCollection*) _tmp12_, (ValaCCodeStatement*) cif);
	_vala_ccode_node_unref0 (cif);
	_vala_ccode_node_unref0 (parent_if);
}

void
vala_ccode_function_open_while (ValaCCodeFunction* self,
                                ValaCCodeExpression* condition)
{
	ValaList* _tmp0_;
	ValaCCodeBlock* _tmp1_;
	ValaCCodeBlock* parent_block = NULL;
	ValaCCodeBlock* _tmp2_;
	ValaCCodeBlock* _tmp3_;
	ValaCCodeBlock* _tmp4_;
	ValaCCodeBlock* _tmp5_;
	ValaCCodeWhileStatement* cwhile = NULL;
	ValaCCodeBlock* _tmp6_;
	ValaCCodeWhileStatement* _tmp7_;
	ValaCCodeLineDirective* _tmp8_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (condition != NULL);
	_tmp0_ = self->priv->statement_stack;
	_tmp1_ = self->priv->_current_block;
	vala_collection_add ((ValaCollection*) _tmp0_, (ValaCCodeStatement*) _tmp1_);
	_tmp2_ = self->priv->_current_block;
	_tmp3_ = _vala_ccode_node_ref0 (_tmp2_);
	parent_block = _tmp3_;
	_tmp4_ = vala_ccode_block_new ();
	_tmp5_ = _tmp4_;
	vala_ccode_function_set_current_block (self, _tmp5_);
	_vala_ccode_node_unref0 (_tmp5_);
	_tmp6_ = self->priv->_current_block;
	_tmp7_ = vala_ccode_while_statement_new (condition, (ValaCCodeStatement*) _tmp6_);
	cwhile = _tmp7_;
	_tmp8_ = self->priv->_current_line;
	vala_ccode_node_set_line ((ValaCCodeNode*) cwhile, _tmp8_);
	vala_ccode_block_add_statement (parent_block, (ValaCCodeNode*) cwhile);
	_vala_ccode_node_unref0 (cwhile);
	_vala_ccode_node_unref0 (parent_block);
}

void
vala_ccode_function_open_for (ValaCCodeFunction* self,
                              ValaCCodeExpression* initializer,
                              ValaCCodeExpression* condition,
                              ValaCCodeExpression* iterator)
{
	ValaList* _tmp0_;
	ValaCCodeBlock* _tmp1_;
	ValaCCodeBlock* parent_block = NULL;
	ValaCCodeBlock* _tmp2_;
	ValaCCodeBlock* _tmp3_;
	ValaCCodeBlock* _tmp4_;
	ValaCCodeBlock* _tmp5_;
	ValaCCodeForStatement* cfor = NULL;
	ValaCCodeBlock* _tmp6_;
	ValaCCodeForStatement* _tmp7_;
	ValaCCodeForStatement* _tmp8_;
	ValaCCodeLineDirective* _tmp9_;
	ValaCCodeBlock* _tmp12_;
	ValaCCodeForStatement* _tmp13_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (condition != NULL);
	_tmp0_ = self->priv->statement_stack;
	_tmp1_ = self->priv->_current_block;
	vala_collection_add ((ValaCollection*) _tmp0_, (ValaCCodeStatement*) _tmp1_);
	_tmp2_ = self->priv->_current_block;
	_tmp3_ = _vala_ccode_node_ref0 (_tmp2_);
	parent_block = _tmp3_;
	_tmp4_ = vala_ccode_block_new ();
	_tmp5_ = _tmp4_;
	vala_ccode_function_set_current_block (self, _tmp5_);
	_vala_ccode_node_unref0 (_tmp5_);
	_tmp6_ = self->priv->_current_block;
	_tmp7_ = vala_ccode_for_statement_new (condition, (ValaCCodeStatement*) _tmp6_);
	cfor = _tmp7_;
	_tmp8_ = cfor;
	_tmp9_ = self->priv->_current_line;
	vala_ccode_node_set_line ((ValaCCodeNode*) _tmp8_, _tmp9_);
	if (initializer != NULL) {
		ValaCCodeForStatement* _tmp10_;
		_tmp10_ = cfor;
		vala_ccode_for_statement_add_initializer (_tmp10_, initializer);
	}
	if (iterator != NULL) {
		ValaCCodeForStatement* _tmp11_;
		_tmp11_ = cfor;
		vala_ccode_for_statement_add_iterator (_tmp11_, iterator);
	}
	_tmp12_ = parent_block;
	_tmp13_ = cfor;
	vala_ccode_block_add_statement (_tmp12_, (ValaCCodeNode*) _tmp13_);
	_vala_ccode_node_unref0 (cfor);
	_vala_ccode_node_unref0 (parent_block);
}

void
vala_ccode_function_open_switch (ValaCCodeFunction* self,
                                 ValaCCodeExpression* expression)
{
	ValaList* _tmp0_;
	ValaCCodeBlock* _tmp1_;
	ValaCCodeBlock* parent_block = NULL;
	ValaCCodeBlock* _tmp2_;
	ValaCCodeBlock* _tmp3_;
	ValaCCodeSwitchStatement* cswitch = NULL;
	ValaCCodeSwitchStatement* _tmp4_;
	ValaCCodeLineDirective* _tmp5_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (expression != NULL);
	_tmp0_ = self->priv->statement_stack;
	_tmp1_ = self->priv->_current_block;
	vala_collection_add ((ValaCollection*) _tmp0_, (ValaCCodeStatement*) _tmp1_);
	_tmp2_ = self->priv->_current_block;
	_tmp3_ = _vala_ccode_node_ref0 (_tmp2_);
	parent_block = _tmp3_;
	_tmp4_ = vala_ccode_switch_statement_new (expression);
	cswitch = _tmp4_;
	_tmp5_ = self->priv->_current_line;
	vala_ccode_node_set_line ((ValaCCodeNode*) cswitch, _tmp5_);
	vala_ccode_function_set_current_block (self, (ValaCCodeBlock*) cswitch);
	vala_ccode_block_add_statement (parent_block, (ValaCCodeNode*) cswitch);
	_vala_ccode_node_unref0 (cswitch);
	_vala_ccode_node_unref0 (parent_block);
}

void
vala_ccode_function_add_label (ValaCCodeFunction* self,
                               const gchar* label)
{
	ValaCCodeLabel* _tmp0_;
	ValaCCodeLabel* _tmp1_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (label != NULL);
	_tmp0_ = vala_ccode_label_new (label);
	_tmp1_ = _tmp0_;
	vala_ccode_function_add_statement (self, (ValaCCodeNode*) _tmp1_);
	_vala_ccode_node_unref0 (_tmp1_);
}

void
vala_ccode_function_add_case (ValaCCodeFunction* self,
                              ValaCCodeExpression* expression)
{
	ValaCCodeCaseStatement* _tmp0_;
	ValaCCodeCaseStatement* _tmp1_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (expression != NULL);
	_tmp0_ = vala_ccode_case_statement_new (expression);
	_tmp1_ = _tmp0_;
	vala_ccode_function_add_statement (self, (ValaCCodeNode*) _tmp1_);
	_vala_ccode_node_unref0 (_tmp1_);
}

void
vala_ccode_function_add_default (ValaCCodeFunction* self)
{
	ValaCCodeLabel* _tmp0_;
	ValaCCodeLabel* _tmp1_;
	g_return_if_fail (self != NULL);
	_tmp0_ = vala_ccode_label_new ("default");
	_tmp1_ = _tmp0_;
	vala_ccode_function_add_statement (self, (ValaCCodeNode*) _tmp1_);
	_vala_ccode_node_unref0 (_tmp1_);
}

void
vala_ccode_function_add_goto (ValaCCodeFunction* self,
                              const gchar* target)
{
	ValaCCodeGotoStatement* _tmp0_;
	ValaCCodeGotoStatement* _tmp1_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (target != NULL);
	_tmp0_ = vala_ccode_goto_statement_new (target);
	_tmp1_ = _tmp0_;
	vala_ccode_function_add_statement (self, (ValaCCodeNode*) _tmp1_);
	_vala_ccode_node_unref0 (_tmp1_);
}

void
vala_ccode_function_add_expression (ValaCCodeFunction* self,
                                    ValaCCodeExpression* expression)
{
	ValaCCodeExpressionStatement* _tmp0_;
	ValaCCodeExpressionStatement* _tmp1_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (expression != NULL);
	_tmp0_ = vala_ccode_expression_statement_new (expression);
	_tmp1_ = _tmp0_;
	vala_ccode_function_add_statement (self, (ValaCCodeNode*) _tmp1_);
	_vala_ccode_node_unref0 (_tmp1_);
}

void
vala_ccode_function_add_assignment (ValaCCodeFunction* self,
                                    ValaCCodeExpression* left,
                                    ValaCCodeExpression* right)
{
	ValaCCodeAssignment* _tmp0_;
	ValaCCodeAssignment* _tmp1_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (left != NULL);
	g_return_if_fail (right != NULL);
	_tmp0_ = vala_ccode_assignment_new (left, right, VALA_CCODE_ASSIGNMENT_OPERATOR_SIMPLE);
	_tmp1_ = _tmp0_;
	vala_ccode_function_add_expression (self, (ValaCCodeExpression*) _tmp1_);
	_vala_ccode_node_unref0 (_tmp1_);
}

void
vala_ccode_function_add_return (ValaCCodeFunction* self,
                                ValaCCodeExpression* expression)
{
	ValaCCodeReturnStatement* _tmp0_;
	ValaCCodeReturnStatement* _tmp1_;
	g_return_if_fail (self != NULL);
	_tmp0_ = vala_ccode_return_statement_new (expression);
	_tmp1_ = _tmp0_;
	vala_ccode_function_add_statement (self, (ValaCCodeNode*) _tmp1_);
	_vala_ccode_node_unref0 (_tmp1_);
}

void
vala_ccode_function_add_break (ValaCCodeFunction* self)
{
	ValaCCodeBreakStatement* _tmp0_;
	ValaCCodeBreakStatement* _tmp1_;
	g_return_if_fail (self != NULL);
	_tmp0_ = vala_ccode_break_statement_new ();
	_tmp1_ = _tmp0_;
	vala_ccode_function_add_statement (self, (ValaCCodeNode*) _tmp1_);
	_vala_ccode_node_unref0 (_tmp1_);
}

void
vala_ccode_function_add_continue (ValaCCodeFunction* self)
{
	ValaCCodeContinueStatement* _tmp0_;
	ValaCCodeContinueStatement* _tmp1_;
	g_return_if_fail (self != NULL);
	_tmp0_ = vala_ccode_continue_statement_new ();
	_tmp1_ = _tmp0_;
	vala_ccode_function_add_statement (self, (ValaCCodeNode*) _tmp1_);
	_vala_ccode_node_unref0 (_tmp1_);
}

void
vala_ccode_function_add_declaration (ValaCCodeFunction* self,
                                     const gchar* type_name,
                                     ValaCCodeDeclarator* declarator,
                                     ValaCCodeModifiers modifiers)
{
	ValaCCodeDeclaration* stmt = NULL;
	ValaCCodeDeclaration* _tmp0_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (type_name != NULL);
	g_return_if_fail (declarator != NULL);
	_tmp0_ = vala_ccode_declaration_new (type_name);
	stmt = _tmp0_;
	vala_ccode_declaration_add_declarator (stmt, declarator);
	vala_ccode_node_set_modifiers ((ValaCCodeNode*) stmt, modifiers);
	vala_ccode_function_add_statement (self, (ValaCCodeNode*) stmt);
	_vala_ccode_node_unref0 (stmt);
}

void
vala_ccode_function_close (ValaCCodeFunction* self)
{
	g_return_if_fail (self != NULL);
	{
		gboolean _tmp0_ = FALSE;
		_tmp0_ = TRUE;
		while (TRUE) {
			ValaCCodeStatement* top = NULL;
			ValaList* _tmp2_;
			ValaList* _tmp3_;
			gint _tmp4_;
			gint _tmp5_;
			gpointer _tmp6_;
			ValaCCodeStatement* _tmp7_;
			if (!_tmp0_) {
				ValaCCodeBlock* _tmp1_;
				_tmp1_ = self->priv->_current_block;
				if (!(_tmp1_ == NULL)) {
					break;
				}
			}
			_tmp0_ = FALSE;
			_tmp2_ = self->priv->statement_stack;
			_tmp3_ = self->priv->statement_stack;
			_tmp4_ = vala_collection_get_size ((ValaCollection*) _tmp3_);
			_tmp5_ = _tmp4_;
			_tmp6_ = vala_list_remove_at (_tmp2_, _tmp5_ - 1);
			top = (ValaCCodeStatement*) _tmp6_;
			_tmp7_ = top;
			vala_ccode_function_set_current_block (self, VALA_IS_CCODE_BLOCK (_tmp7_) ? ((ValaCCodeBlock*) _tmp7_) : NULL);
			_vala_ccode_node_unref0 (top);
		}
	}
}

static void
vala_ccode_function_class_init (ValaCCodeFunctionClass * klass,
                                gpointer klass_data)
{
	vala_ccode_function_parent_class = g_type_class_peek_parent (klass);
	((ValaCCodeNodeClass *) klass)->finalize = vala_ccode_function_finalize;
	g_type_class_adjust_private_offset (klass, &ValaCCodeFunction_private_offset);
	((ValaCCodeNodeClass *) klass)->write = (void (*) (ValaCCodeNode*, ValaCCodeWriter*)) vala_ccode_function_real_write;
}

static void
vala_ccode_function_instance_init (ValaCCodeFunction * self,
                                   gpointer klass)
{
	GEqualFunc _tmp0_;
	ValaArrayList* _tmp1_;
	GEqualFunc _tmp2_;
	ValaArrayList* _tmp3_;
	self->priv = vala_ccode_function_get_instance_private (self);
	_tmp0_ = g_direct_equal;
	_tmp1_ = vala_array_list_new (VALA_TYPE_CCODE_PARAMETER, (GBoxedCopyFunc) vala_ccode_node_ref, (GDestroyNotify) vala_ccode_node_unref, _tmp0_);
	self->priv->parameters = (ValaList*) _tmp1_;
	_tmp2_ = g_direct_equal;
	_tmp3_ = vala_array_list_new (VALA_TYPE_CCODE_STATEMENT, (GBoxedCopyFunc) vala_ccode_node_ref, (GDestroyNotify) vala_ccode_node_unref, _tmp2_);
	self->priv->statement_stack = (ValaList*) _tmp3_;
}

static void
vala_ccode_function_finalize (ValaCCodeNode * obj)
{
	ValaCCodeFunction * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, VALA_TYPE_CCODE_FUNCTION, ValaCCodeFunction);
	_g_free0 (self->priv->_name);
	_g_free0 (self->priv->_return_type);
	_vala_ccode_node_unref0 (self->priv->_block);
	_vala_ccode_node_unref0 (self->priv->_current_line);
	_vala_ccode_node_unref0 (self->priv->_current_block);
	_vala_iterable_unref0 (self->priv->parameters);
	_vala_iterable_unref0 (self->priv->statement_stack);
	VALA_CCODE_NODE_CLASS (vala_ccode_function_parent_class)->finalize (obj);
}

/**
 * Represents a function declaration in the C code.
 */
static GType
vala_ccode_function_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (ValaCCodeFunctionClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) vala_ccode_function_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (ValaCCodeFunction), 0, (GInstanceInitFunc) vala_ccode_function_instance_init, NULL };
	GType vala_ccode_function_type_id;
	vala_ccode_function_type_id = g_type_register_static (VALA_TYPE_CCODE_NODE, "ValaCCodeFunction", &g_define_type_info, 0);
	ValaCCodeFunction_private_offset = g_type_add_instance_private (vala_ccode_function_type_id, sizeof (ValaCCodeFunctionPrivate));
	return vala_ccode_function_type_id;
}

GType
vala_ccode_function_get_type (void)
{
	static volatile gsize vala_ccode_function_type_id__volatile = 0;
	if (g_once_init_enter (&vala_ccode_function_type_id__volatile)) {
		GType vala_ccode_function_type_id;
		vala_ccode_function_type_id = vala_ccode_function_get_type_once ();
		g_once_init_leave (&vala_ccode_function_type_id__volatile, vala_ccode_function_type_id);
	}
	return vala_ccode_function_type_id__volatile;
}
