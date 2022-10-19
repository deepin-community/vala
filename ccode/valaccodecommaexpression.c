/* valaccodecommaexpression.c generated by valac, the Vala compiler
 * generated from valaccodecommaexpression.vala, do not modify */

/* valaccodecommaexpression.vala
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

#include "valaccode.h"
#include <valagee.h>
#include <glib-object.h>
#include <glib.h>

#define _vala_iterable_unref0(var) ((var == NULL) ? NULL : (var = (vala_iterable_unref (var), NULL)))
#define _vala_ccode_node_unref0(var) ((var == NULL) ? NULL : (var = (vala_ccode_node_unref (var), NULL)))

struct _ValaCCodeCommaExpressionPrivate {
	ValaList* inner;
};

static gint ValaCCodeCommaExpression_private_offset;
static gpointer vala_ccode_comma_expression_parent_class = NULL;

static void vala_ccode_comma_expression_real_write (ValaCCodeNode* base,
                                             ValaCCodeWriter* writer);
static void vala_ccode_comma_expression_finalize (ValaCCodeNode * obj);
static GType vala_ccode_comma_expression_get_type_once (void);

static inline gpointer
vala_ccode_comma_expression_get_instance_private (ValaCCodeCommaExpression* self)
{
	return G_STRUCT_MEMBER_P (self, ValaCCodeCommaExpression_private_offset);
}

/**
 * Appends the specified expression to the expression list.
 *
 * @param expr a C code expression
 */
void
vala_ccode_comma_expression_append_expression (ValaCCodeCommaExpression* self,
                                               ValaCCodeExpression* expr)
{
	ValaList* _tmp0_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (expr != NULL);
	_tmp0_ = self->priv->inner;
	vala_collection_add ((ValaCollection*) _tmp0_, expr);
}

void
vala_ccode_comma_expression_set_expression (ValaCCodeCommaExpression* self,
                                            gint index,
                                            ValaCCodeExpression* expr)
{
	ValaList* _tmp0_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (expr != NULL);
	_tmp0_ = self->priv->inner;
	vala_list_set (_tmp0_, index, expr);
}

ValaList*
vala_ccode_comma_expression_get_inner (ValaCCodeCommaExpression* self)
{
	ValaList* _tmp0_;
	ValaList* result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->inner;
	result = _tmp0_;
	return result;
}

static void
vala_ccode_comma_expression_real_write (ValaCCodeNode* base,
                                        ValaCCodeWriter* writer)
{
	ValaCCodeCommaExpression * self;
	gboolean first = FALSE;
	self = (ValaCCodeCommaExpression*) base;
	g_return_if_fail (writer != NULL);
	first = TRUE;
	vala_ccode_writer_write_string (writer, "(");
	{
		ValaList* _expr_list = NULL;
		ValaList* _tmp0_;
		gint _expr_size = 0;
		ValaList* _tmp1_;
		gint _tmp2_;
		gint _tmp3_;
		gint _expr_index = 0;
		_tmp0_ = self->priv->inner;
		_expr_list = _tmp0_;
		_tmp1_ = _expr_list;
		_tmp2_ = vala_collection_get_size ((ValaCollection*) _tmp1_);
		_tmp3_ = _tmp2_;
		_expr_size = _tmp3_;
		_expr_index = -1;
		while (TRUE) {
			gint _tmp4_;
			gint _tmp5_;
			ValaCCodeExpression* expr = NULL;
			ValaList* _tmp6_;
			gpointer _tmp7_;
			ValaCCodeExpression* _tmp8_;
			_expr_index = _expr_index + 1;
			_tmp4_ = _expr_index;
			_tmp5_ = _expr_size;
			if (!(_tmp4_ < _tmp5_)) {
				break;
			}
			_tmp6_ = _expr_list;
			_tmp7_ = vala_list_get (_tmp6_, _expr_index);
			expr = (ValaCCodeExpression*) _tmp7_;
			if (!first) {
				vala_ccode_writer_write_string (writer, ", ");
			} else {
				first = FALSE;
			}
			_tmp8_ = expr;
			vala_ccode_node_write ((ValaCCodeNode*) _tmp8_, writer);
			_vala_ccode_node_unref0 (expr);
		}
	}
	vala_ccode_writer_write_string (writer, ")");
}

ValaCCodeCommaExpression*
vala_ccode_comma_expression_construct (GType object_type)
{
	ValaCCodeCommaExpression* self = NULL;
	self = (ValaCCodeCommaExpression*) vala_ccode_expression_construct (object_type);
	return self;
}

ValaCCodeCommaExpression*
vala_ccode_comma_expression_new (void)
{
	return vala_ccode_comma_expression_construct (VALA_TYPE_CCODE_COMMA_EXPRESSION);
}

static void
vala_ccode_comma_expression_class_init (ValaCCodeCommaExpressionClass * klass,
                                        gpointer klass_data)
{
	vala_ccode_comma_expression_parent_class = g_type_class_peek_parent (klass);
	((ValaCCodeNodeClass *) klass)->finalize = vala_ccode_comma_expression_finalize;
	g_type_class_adjust_private_offset (klass, &ValaCCodeCommaExpression_private_offset);
	((ValaCCodeNodeClass *) klass)->write = (void (*) (ValaCCodeNode*, ValaCCodeWriter*)) vala_ccode_comma_expression_real_write;
}

static void
vala_ccode_comma_expression_instance_init (ValaCCodeCommaExpression * self,
                                           gpointer klass)
{
	GEqualFunc _tmp0_;
	ValaArrayList* _tmp1_;
	self->priv = vala_ccode_comma_expression_get_instance_private (self);
	_tmp0_ = g_direct_equal;
	_tmp1_ = vala_array_list_new (VALA_TYPE_CCODE_EXPRESSION, (GBoxedCopyFunc) vala_ccode_node_ref, (GDestroyNotify) vala_ccode_node_unref, _tmp0_);
	self->priv->inner = (ValaList*) _tmp1_;
}

static void
vala_ccode_comma_expression_finalize (ValaCCodeNode * obj)
{
	ValaCCodeCommaExpression * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, VALA_TYPE_CCODE_COMMA_EXPRESSION, ValaCCodeCommaExpression);
	_vala_iterable_unref0 (self->priv->inner);
	VALA_CCODE_NODE_CLASS (vala_ccode_comma_expression_parent_class)->finalize (obj);
}

/**
 * Represents a comma separated expression list in the C code.
 */
static GType
vala_ccode_comma_expression_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (ValaCCodeCommaExpressionClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) vala_ccode_comma_expression_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (ValaCCodeCommaExpression), 0, (GInstanceInitFunc) vala_ccode_comma_expression_instance_init, NULL };
	GType vala_ccode_comma_expression_type_id;
	vala_ccode_comma_expression_type_id = g_type_register_static (VALA_TYPE_CCODE_EXPRESSION, "ValaCCodeCommaExpression", &g_define_type_info, 0);
	ValaCCodeCommaExpression_private_offset = g_type_add_instance_private (vala_ccode_comma_expression_type_id, sizeof (ValaCCodeCommaExpressionPrivate));
	return vala_ccode_comma_expression_type_id;
}

GType
vala_ccode_comma_expression_get_type (void)
{
	static volatile gsize vala_ccode_comma_expression_type_id__volatile = 0;
	if (g_once_init_enter (&vala_ccode_comma_expression_type_id__volatile)) {
		GType vala_ccode_comma_expression_type_id;
		vala_ccode_comma_expression_type_id = vala_ccode_comma_expression_get_type_once ();
		g_once_init_leave (&vala_ccode_comma_expression_type_id__volatile, vala_ccode_comma_expression_type_id);
	}
	return vala_ccode_comma_expression_type_id__volatile;
}
