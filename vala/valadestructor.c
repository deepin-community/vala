/* valadestructor.c generated by valac, the Vala compiler
 * generated from valadestructor.vala, do not modify */

/* valadestructor.vala
 *
 * Copyright (C) 2006-2010  Jürg Billeter
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
#include <glib-object.h>
#include <valagee.h>
#include <stdlib.h>
#include <string.h>

#define _vala_code_node_unref0(var) ((var == NULL) ? NULL : (var = (vala_code_node_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))
#define _vala_iterable_unref0(var) ((var == NULL) ? NULL : (var = (vala_iterable_unref (var), NULL)))

struct _ValaDestructorPrivate {
	ValaParameter* _this_parameter;
	ValaMemberBinding _binding;
};

static gint ValaDestructor_private_offset;
static gpointer vala_destructor_parent_class = NULL;

static void vala_destructor_real_accept (ValaCodeNode* base,
                                  ValaCodeVisitor* visitor);
static void vala_destructor_real_accept_children (ValaCodeNode* base,
                                           ValaCodeVisitor* visitor);
static gboolean vala_destructor_real_check (ValaCodeNode* base,
                                     ValaCodeContext* context);
static void vala_destructor_finalize (ValaCodeNode * obj);
static GType vala_destructor_get_type_once (void);

static inline gpointer
vala_destructor_get_instance_private (ValaDestructor* self)
{
	return G_STRUCT_MEMBER_P (self, ValaDestructor_private_offset);
}

ValaParameter*
vala_destructor_get_this_parameter (ValaDestructor* self)
{
	ValaParameter* result;
	ValaParameter* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_this_parameter;
	result = _tmp0_;
	return result;
}

static gpointer
_vala_code_node_ref0 (gpointer self)
{
	return self ? vala_code_node_ref (self) : NULL;
}

void
vala_destructor_set_this_parameter (ValaDestructor* self,
                                    ValaParameter* value)
{
	ValaParameter* _tmp0_;
	g_return_if_fail (self != NULL);
	_tmp0_ = _vala_code_node_ref0 (value);
	_vala_code_node_unref0 (self->priv->_this_parameter);
	self->priv->_this_parameter = _tmp0_;
}

ValaMemberBinding
vala_destructor_get_binding (ValaDestructor* self)
{
	ValaMemberBinding result;
	g_return_val_if_fail (self != NULL, 0);
	result = self->priv->_binding;
	return result;
}

void
vala_destructor_set_binding (ValaDestructor* self,
                             ValaMemberBinding value)
{
	g_return_if_fail (self != NULL);
	self->priv->_binding = value;
}

static gboolean
vala_destructor_real_get_has_result (ValaSubroutine* base)
{
	gboolean result;
	ValaDestructor* self;
	self = (ValaDestructor*) base;
	result = FALSE;
	return result;
}

/**
 * Creates a new destructor.
 *
 * @param source_reference reference to source code
 * @return                 newly created destructor
 */
ValaDestructor*
vala_destructor_construct (GType object_type,
                           ValaSourceReference* source_reference)
{
	ValaDestructor* self = NULL;
	self = (ValaDestructor*) vala_subroutine_construct (object_type, NULL, source_reference, NULL);
	return self;
}

ValaDestructor*
vala_destructor_new (ValaSourceReference* source_reference)
{
	return vala_destructor_construct (VALA_TYPE_DESTRUCTOR, source_reference);
}

static void
vala_destructor_real_accept (ValaCodeNode* base,
                             ValaCodeVisitor* visitor)
{
	ValaDestructor * self;
	self = (ValaDestructor*) base;
	g_return_if_fail (visitor != NULL);
	vala_code_visitor_visit_destructor (visitor, self);
}

static void
vala_destructor_real_accept_children (ValaCodeNode* base,
                                      ValaCodeVisitor* visitor)
{
	ValaDestructor * self;
	ValaBlock* _tmp0_;
	ValaBlock* _tmp1_;
	self = (ValaDestructor*) base;
	g_return_if_fail (visitor != NULL);
	_tmp0_ = vala_subroutine_get_body ((ValaSubroutine*) self);
	_tmp1_ = _tmp0_;
	if (_tmp1_ != NULL) {
		ValaBlock* _tmp2_;
		ValaBlock* _tmp3_;
		_tmp2_ = vala_subroutine_get_body ((ValaSubroutine*) self);
		_tmp3_ = _tmp2_;
		vala_code_node_accept ((ValaCodeNode*) _tmp3_, visitor);
	}
}

static gboolean
vala_destructor_real_check (ValaCodeNode* base,
                            ValaCodeContext* context)
{
	ValaDestructor * self;
	gboolean _tmp0_;
	gboolean _tmp1_;
	ValaParameter* _tmp4_;
	ValaSymbol* old_symbol = NULL;
	ValaSemanticAnalyzer* _tmp6_;
	ValaSemanticAnalyzer* _tmp7_;
	ValaSymbol* _tmp8_;
	ValaSymbol* _tmp9_;
	ValaSymbol* _tmp10_;
	ValaSemanticAnalyzer* _tmp11_;
	ValaSemanticAnalyzer* _tmp12_;
	ValaBlock* _tmp13_;
	ValaBlock* _tmp14_;
	gboolean _tmp17_ = FALSE;
	ValaBlock* _tmp18_;
	ValaBlock* _tmp19_;
	ValaSemanticAnalyzer* _tmp46_;
	ValaSemanticAnalyzer* _tmp47_;
	ValaSymbol* _tmp48_;
	gboolean _tmp49_;
	gboolean _tmp50_;
	gboolean result;
	self = (ValaDestructor*) base;
	g_return_val_if_fail (context != NULL, FALSE);
	_tmp0_ = vala_code_node_get_checked ((ValaCodeNode*) self);
	_tmp1_ = _tmp0_;
	if (_tmp1_) {
		gboolean _tmp2_;
		gboolean _tmp3_;
		_tmp2_ = vala_code_node_get_error ((ValaCodeNode*) self);
		_tmp3_ = _tmp2_;
		result = !_tmp3_;
		return result;
	}
	vala_code_node_set_checked ((ValaCodeNode*) self, TRUE);
	_tmp4_ = self->priv->_this_parameter;
	if (_tmp4_ != NULL) {
		ValaParameter* _tmp5_;
		_tmp5_ = self->priv->_this_parameter;
		vala_code_node_check ((ValaCodeNode*) _tmp5_, context);
	}
	_tmp6_ = vala_code_context_get_analyzer (context);
	_tmp7_ = _tmp6_;
	_tmp8_ = vala_semantic_analyzer_get_current_symbol (_tmp7_);
	_tmp9_ = _tmp8_;
	_tmp10_ = _vala_code_node_ref0 (_tmp9_);
	old_symbol = _tmp10_;
	_tmp11_ = vala_code_context_get_analyzer (context);
	_tmp12_ = _tmp11_;
	vala_semantic_analyzer_set_current_symbol (_tmp12_, (ValaSymbol*) self);
	_tmp13_ = vala_subroutine_get_body ((ValaSubroutine*) self);
	_tmp14_ = _tmp13_;
	if (_tmp14_ != NULL) {
		ValaBlock* _tmp15_;
		ValaBlock* _tmp16_;
		_tmp15_ = vala_subroutine_get_body ((ValaSubroutine*) self);
		_tmp16_ = _tmp15_;
		vala_code_node_check ((ValaCodeNode*) _tmp16_, context);
	}
	_tmp18_ = vala_subroutine_get_body ((ValaSubroutine*) self);
	_tmp19_ = _tmp18_;
	if (_tmp19_ != NULL) {
		ValaBlock* _tmp20_;
		ValaBlock* _tmp21_;
		gboolean _tmp22_;
		gboolean _tmp23_;
		_tmp20_ = vala_subroutine_get_body ((ValaSubroutine*) self);
		_tmp21_ = _tmp20_;
		_tmp22_ = vala_code_node_get_error ((ValaCodeNode*) _tmp21_);
		_tmp23_ = _tmp22_;
		_tmp17_ = !_tmp23_;
	} else {
		_tmp17_ = FALSE;
	}
	if (_tmp17_) {
		ValaArrayList* body_errors = NULL;
		GEqualFunc _tmp24_;
		ValaArrayList* _tmp25_;
		ValaBlock* _tmp26_;
		ValaBlock* _tmp27_;
		ValaArrayList* _tmp28_;
		_tmp24_ = g_direct_equal;
		_tmp25_ = vala_array_list_new (VALA_TYPE_DATA_TYPE, (GBoxedCopyFunc) vala_code_node_ref, (GDestroyNotify) vala_code_node_unref, _tmp24_);
		body_errors = _tmp25_;
		_tmp26_ = vala_subroutine_get_body ((ValaSubroutine*) self);
		_tmp27_ = _tmp26_;
		_tmp28_ = body_errors;
		vala_code_node_get_error_types ((ValaCodeNode*) _tmp27_, (ValaCollection*) _tmp28_, NULL);
		{
			ValaArrayList* _body_error_type_list = NULL;
			ValaArrayList* _tmp29_;
			gint _body_error_type_size = 0;
			ValaArrayList* _tmp30_;
			gint _tmp31_;
			gint _tmp32_;
			gint _body_error_type_index = 0;
			_tmp29_ = body_errors;
			_body_error_type_list = _tmp29_;
			_tmp30_ = _body_error_type_list;
			_tmp31_ = vala_collection_get_size ((ValaCollection*) _tmp30_);
			_tmp32_ = _tmp31_;
			_body_error_type_size = _tmp32_;
			_body_error_type_index = -1;
			while (TRUE) {
				gint _tmp33_;
				gint _tmp34_;
				ValaDataType* body_error_type = NULL;
				ValaArrayList* _tmp35_;
				gpointer _tmp36_;
				ValaDataType* _tmp37_;
				gboolean _tmp38_;
				gboolean _tmp39_;
				_body_error_type_index = _body_error_type_index + 1;
				_tmp33_ = _body_error_type_index;
				_tmp34_ = _body_error_type_size;
				if (!(_tmp33_ < _tmp34_)) {
					break;
				}
				_tmp35_ = _body_error_type_list;
				_tmp36_ = vala_list_get ((ValaList*) _tmp35_, _body_error_type_index);
				body_error_type = (ValaDataType*) _tmp36_;
				_tmp37_ = body_error_type;
				_tmp38_ = vala_error_type_get_dynamic_error (G_TYPE_CHECK_INSTANCE_CAST (_tmp37_, VALA_TYPE_ERROR_TYPE, ValaErrorType));
				_tmp39_ = _tmp38_;
				if (!_tmp39_) {
					ValaDataType* _tmp40_;
					ValaSourceReference* _tmp41_;
					ValaSourceReference* _tmp42_;
					ValaDataType* _tmp43_;
					gchar* _tmp44_;
					gchar* _tmp45_;
					_tmp40_ = body_error_type;
					_tmp41_ = vala_code_node_get_source_reference ((ValaCodeNode*) _tmp40_);
					_tmp42_ = _tmp41_;
					_tmp43_ = body_error_type;
					_tmp44_ = vala_code_node_to_string ((ValaCodeNode*) _tmp43_);
					_tmp45_ = _tmp44_;
					vala_report_warning (_tmp42_, "unhandled error `%s'", _tmp45_);
					_g_free0 (_tmp45_);
				}
				_vala_code_node_unref0 (body_error_type);
			}
		}
		_vala_iterable_unref0 (body_errors);
	}
	_tmp46_ = vala_code_context_get_analyzer (context);
	_tmp47_ = _tmp46_;
	_tmp48_ = old_symbol;
	vala_semantic_analyzer_set_current_symbol (_tmp47_, _tmp48_);
	_tmp49_ = vala_code_node_get_error ((ValaCodeNode*) self);
	_tmp50_ = _tmp49_;
	result = !_tmp50_;
	_vala_code_node_unref0 (old_symbol);
	return result;
}

static void
vala_destructor_class_init (ValaDestructorClass * klass,
                            gpointer klass_data)
{
	vala_destructor_parent_class = g_type_class_peek_parent (klass);
	((ValaCodeNodeClass *) klass)->finalize = vala_destructor_finalize;
	g_type_class_adjust_private_offset (klass, &ValaDestructor_private_offset);
	((ValaCodeNodeClass *) klass)->accept = (void (*) (ValaCodeNode*, ValaCodeVisitor*)) vala_destructor_real_accept;
	((ValaCodeNodeClass *) klass)->accept_children = (void (*) (ValaCodeNode*, ValaCodeVisitor*)) vala_destructor_real_accept_children;
	((ValaCodeNodeClass *) klass)->check = (gboolean (*) (ValaCodeNode*, ValaCodeContext*)) vala_destructor_real_check;
	VALA_SUBROUTINE_CLASS (klass)->get_has_result = (gboolean (*) (ValaSubroutine*)) vala_destructor_real_get_has_result;
}

static void
vala_destructor_instance_init (ValaDestructor * self,
                               gpointer klass)
{
	self->priv = vala_destructor_get_instance_private (self);
	self->priv->_binding = VALA_MEMBER_BINDING_INSTANCE;
}

static void
vala_destructor_finalize (ValaCodeNode * obj)
{
	ValaDestructor * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, VALA_TYPE_DESTRUCTOR, ValaDestructor);
	_vala_code_node_unref0 (self->priv->_this_parameter);
	VALA_CODE_NODE_CLASS (vala_destructor_parent_class)->finalize (obj);
}

/**
 * Represents a class or instance destructor.
 */
static GType
vala_destructor_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (ValaDestructorClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) vala_destructor_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (ValaDestructor), 0, (GInstanceInitFunc) vala_destructor_instance_init, NULL };
	GType vala_destructor_type_id;
	vala_destructor_type_id = g_type_register_static (VALA_TYPE_SUBROUTINE, "ValaDestructor", &g_define_type_info, 0);
	ValaDestructor_private_offset = g_type_add_instance_private (vala_destructor_type_id, sizeof (ValaDestructorPrivate));
	return vala_destructor_type_id;
}

GType
vala_destructor_get_type (void)
{
	static volatile gsize vala_destructor_type_id__once = 0;
	if (g_once_init_enter (&vala_destructor_type_id__once)) {
		GType vala_destructor_type_id;
		vala_destructor_type_id = vala_destructor_get_type_once ();
		g_once_init_leave (&vala_destructor_type_id__once, vala_destructor_type_id);
	}
	return vala_destructor_type_id__once;
}

