/* valaphifunction.c generated by valac, the Vala compiler
 * generated from valaphifunction.vala, do not modify */

/* valaphifunction.vala
 *
 * Copyright (C) 2008  Jürg Billeter
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
#include <valagee.h>
#include <glib-object.h>
#include <glib.h>
#include <gobject/gvaluecollector.h>

#define _vala_code_node_unref0(var) ((var == NULL) ? NULL : (var = (vala_code_node_unref (var), NULL)))
#define _vala_iterable_unref0(var) ((var == NULL) ? NULL : (var = (vala_iterable_unref (var), NULL)))
typedef struct _ValaParamSpecPhiFunction ValaParamSpecPhiFunction;

struct _ValaPhiFunctionPrivate {
	ValaVariable* _original_variable;
	ValaList* _operands;
};

struct _ValaParamSpecPhiFunction {
	GParamSpec parent_instance;
};

static gint ValaPhiFunction_private_offset;
static gpointer vala_phi_function_parent_class = NULL;

static void vala_phi_function_set_original_variable (ValaPhiFunction* self,
                                              ValaVariable* value);
static void vala_phi_function_set_operands (ValaPhiFunction* self,
                                     ValaList* value);
static void vala_phi_function_finalize (ValaPhiFunction * obj);
static GType vala_phi_function_get_type_once (void);

static inline gpointer
vala_phi_function_get_instance_private (ValaPhiFunction* self)
{
	return G_STRUCT_MEMBER_P (self, ValaPhiFunction_private_offset);
}

ValaVariable*
vala_phi_function_get_original_variable (ValaPhiFunction* self)
{
	ValaVariable* result;
	ValaVariable* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_original_variable;
	result = _tmp0_;
	return result;
}

static gpointer
_vala_code_node_ref0 (gpointer self)
{
	return self ? vala_code_node_ref (self) : NULL;
}

static void
vala_phi_function_set_original_variable (ValaPhiFunction* self,
                                         ValaVariable* value)
{
	ValaVariable* _tmp0_;
	g_return_if_fail (self != NULL);
	_tmp0_ = _vala_code_node_ref0 (value);
	_vala_code_node_unref0 (self->priv->_original_variable);
	self->priv->_original_variable = _tmp0_;
}

ValaList*
vala_phi_function_get_operands (ValaPhiFunction* self)
{
	ValaList* result;
	ValaList* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_operands;
	result = _tmp0_;
	return result;
}

static gpointer
_vala_iterable_ref0 (gpointer self)
{
	return self ? vala_iterable_ref (self) : NULL;
}

static void
vala_phi_function_set_operands (ValaPhiFunction* self,
                                ValaList* value)
{
	ValaList* _tmp0_;
	g_return_if_fail (self != NULL);
	_tmp0_ = _vala_iterable_ref0 (value);
	_vala_iterable_unref0 (self->priv->_operands);
	self->priv->_operands = _tmp0_;
}

ValaPhiFunction*
vala_phi_function_construct (GType object_type,
                             ValaVariable* variable,
                             gint num_of_ops)
{
	ValaPhiFunction* self = NULL;
	GEqualFunc _tmp0_;
	ValaArrayList* _tmp1_;
	ValaArrayList* _tmp2_;
	g_return_val_if_fail (variable != NULL, NULL);
	self = (ValaPhiFunction*) g_type_create_instance (object_type);
	vala_phi_function_set_original_variable (self, variable);
	_tmp0_ = g_direct_equal;
	_tmp1_ = vala_array_list_new (VALA_TYPE_VARIABLE, (GBoxedCopyFunc) vala_code_node_ref, (GDestroyNotify) vala_code_node_unref, _tmp0_);
	_tmp2_ = _tmp1_;
	vala_phi_function_set_operands (self, (ValaList*) _tmp2_);
	_vala_iterable_unref0 (_tmp2_);
	{
		gint i = 0;
		i = 0;
		{
			gboolean _tmp3_ = FALSE;
			_tmp3_ = TRUE;
			while (TRUE) {
				ValaList* _tmp5_;
				if (!_tmp3_) {
					gint _tmp4_;
					_tmp4_ = i;
					i = _tmp4_ + 1;
				}
				_tmp3_ = FALSE;
				if (!(i < num_of_ops)) {
					break;
				}
				_tmp5_ = self->priv->_operands;
				vala_collection_add ((ValaCollection*) _tmp5_, G_TYPE_CHECK_INSTANCE_CAST (NULL, VALA_TYPE_VARIABLE, ValaVariable));
			}
		}
	}
	return self;
}

ValaPhiFunction*
vala_phi_function_new (ValaVariable* variable,
                       gint num_of_ops)
{
	return vala_phi_function_construct (VALA_TYPE_PHI_FUNCTION, variable, num_of_ops);
}

static void
vala_value_phi_function_init (GValue* value)
{
	value->data[0].v_pointer = NULL;
}

static void
vala_value_phi_function_free_value (GValue* value)
{
	if (value->data[0].v_pointer) {
		vala_phi_function_unref (value->data[0].v_pointer);
	}
}

static void
vala_value_phi_function_copy_value (const GValue* src_value,
                                    GValue* dest_value)
{
	if (src_value->data[0].v_pointer) {
		dest_value->data[0].v_pointer = vala_phi_function_ref (src_value->data[0].v_pointer);
	} else {
		dest_value->data[0].v_pointer = NULL;
	}
}

static gpointer
vala_value_phi_function_peek_pointer (const GValue* value)
{
	return value->data[0].v_pointer;
}

static gchar*
vala_value_phi_function_collect_value (GValue* value,
                                       guint n_collect_values,
                                       GTypeCValue* collect_values,
                                       guint collect_flags)
{
	if (collect_values[0].v_pointer) {
		ValaPhiFunction * object;
		object = collect_values[0].v_pointer;
		if (object->parent_instance.g_class == NULL) {
			return g_strconcat ("invalid unclassed object pointer for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		} else if (!g_value_type_compatible (G_TYPE_FROM_INSTANCE (object), G_VALUE_TYPE (value))) {
			return g_strconcat ("invalid object type `", g_type_name (G_TYPE_FROM_INSTANCE (object)), "' for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		}
		value->data[0].v_pointer = vala_phi_function_ref (object);
	} else {
		value->data[0].v_pointer = NULL;
	}
	return NULL;
}

static gchar*
vala_value_phi_function_lcopy_value (const GValue* value,
                                     guint n_collect_values,
                                     GTypeCValue* collect_values,
                                     guint collect_flags)
{
	ValaPhiFunction ** object_p;
	object_p = collect_values[0].v_pointer;
	if (!object_p) {
		return g_strdup_printf ("value location for `%s' passed as NULL", G_VALUE_TYPE_NAME (value));
	}
	if (!value->data[0].v_pointer) {
		*object_p = NULL;
	} else if (collect_flags & G_VALUE_NOCOPY_CONTENTS) {
		*object_p = value->data[0].v_pointer;
	} else {
		*object_p = vala_phi_function_ref (value->data[0].v_pointer);
	}
	return NULL;
}

GParamSpec*
vala_param_spec_phi_function (const gchar* name,
                              const gchar* nick,
                              const gchar* blurb,
                              GType object_type,
                              GParamFlags flags)
{
	ValaParamSpecPhiFunction* spec;
	g_return_val_if_fail (g_type_is_a (object_type, VALA_TYPE_PHI_FUNCTION), NULL);
	spec = g_param_spec_internal (G_TYPE_PARAM_OBJECT, name, nick, blurb, flags);
	G_PARAM_SPEC (spec)->value_type = object_type;
	return G_PARAM_SPEC (spec);
}

gpointer
vala_value_get_phi_function (const GValue* value)
{
	g_return_val_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, VALA_TYPE_PHI_FUNCTION), NULL);
	return value->data[0].v_pointer;
}

void
vala_value_set_phi_function (GValue* value,
                             gpointer v_object)
{
	ValaPhiFunction * old;
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, VALA_TYPE_PHI_FUNCTION));
	old = value->data[0].v_pointer;
	if (v_object) {
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, VALA_TYPE_PHI_FUNCTION));
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
		value->data[0].v_pointer = v_object;
		vala_phi_function_ref (value->data[0].v_pointer);
	} else {
		value->data[0].v_pointer = NULL;
	}
	if (old) {
		vala_phi_function_unref (old);
	}
}

void
vala_value_take_phi_function (GValue* value,
                              gpointer v_object)
{
	ValaPhiFunction * old;
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, VALA_TYPE_PHI_FUNCTION));
	old = value->data[0].v_pointer;
	if (v_object) {
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, VALA_TYPE_PHI_FUNCTION));
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
		value->data[0].v_pointer = v_object;
	} else {
		value->data[0].v_pointer = NULL;
	}
	if (old) {
		vala_phi_function_unref (old);
	}
}

static void
vala_phi_function_class_init (ValaPhiFunctionClass * klass,
                              gpointer klass_data)
{
	vala_phi_function_parent_class = g_type_class_peek_parent (klass);
	((ValaPhiFunctionClass *) klass)->finalize = vala_phi_function_finalize;
	g_type_class_adjust_private_offset (klass, &ValaPhiFunction_private_offset);
}

static void
vala_phi_function_instance_init (ValaPhiFunction * self,
                                 gpointer klass)
{
	self->priv = vala_phi_function_get_instance_private (self);
	self->ref_count = 1;
}

static void
vala_phi_function_finalize (ValaPhiFunction * obj)
{
	ValaPhiFunction * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, VALA_TYPE_PHI_FUNCTION, ValaPhiFunction);
	g_signal_handlers_destroy (self);
	_vala_code_node_unref0 (self->priv->_original_variable);
	_vala_iterable_unref0 (self->priv->_operands);
}

static GType
vala_phi_function_get_type_once (void)
{
	static const GTypeValueTable g_define_type_value_table = { vala_value_phi_function_init, vala_value_phi_function_free_value, vala_value_phi_function_copy_value, vala_value_phi_function_peek_pointer, "p", vala_value_phi_function_collect_value, "p", vala_value_phi_function_lcopy_value };
	static const GTypeInfo g_define_type_info = { sizeof (ValaPhiFunctionClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) vala_phi_function_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (ValaPhiFunction), 0, (GInstanceInitFunc) vala_phi_function_instance_init, &g_define_type_value_table };
	static const GTypeFundamentalInfo g_define_type_fundamental_info = { (G_TYPE_FLAG_CLASSED | G_TYPE_FLAG_INSTANTIATABLE | G_TYPE_FLAG_DERIVABLE | G_TYPE_FLAG_DEEP_DERIVABLE) };
	GType vala_phi_function_type_id;
	vala_phi_function_type_id = g_type_register_fundamental (g_type_fundamental_next (), "ValaPhiFunction", &g_define_type_info, &g_define_type_fundamental_info, 0);
	ValaPhiFunction_private_offset = g_type_add_instance_private (vala_phi_function_type_id, sizeof (ValaPhiFunctionPrivate));
	return vala_phi_function_type_id;
}

GType
vala_phi_function_get_type (void)
{
	static volatile gsize vala_phi_function_type_id__once = 0;
	if (g_once_init_enter (&vala_phi_function_type_id__once)) {
		GType vala_phi_function_type_id;
		vala_phi_function_type_id = vala_phi_function_get_type_once ();
		g_once_init_leave (&vala_phi_function_type_id__once, vala_phi_function_type_id);
	}
	return vala_phi_function_type_id__once;
}

gpointer
vala_phi_function_ref (gpointer instance)
{
	ValaPhiFunction * self;
	self = instance;
	g_atomic_int_inc (&self->ref_count);
	return instance;
}

void
vala_phi_function_unref (gpointer instance)
{
	ValaPhiFunction * self;
	self = instance;
	if (g_atomic_int_dec_and_test (&self->ref_count)) {
		VALA_PHI_FUNCTION_GET_CLASS (self)->finalize (self);
		g_type_free_instance ((GTypeInstance *) self);
	}
}

