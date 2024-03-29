/* valayieldstatement.c generated by valac, the Vala compiler
 * generated from valayieldstatement.vala, do not modify */

/* valayieldstatement.vala
 *
 * Copyright (C) 2008-2010  Jürg Billeter
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

static gpointer vala_yield_statement_parent_class = NULL;
static ValaStatementIface * vala_yield_statement_vala_statement_parent_iface = NULL;

static void vala_yield_statement_real_accept (ValaCodeNode* base,
                                       ValaCodeVisitor* visitor);
static gboolean vala_yield_statement_real_check (ValaCodeNode* base,
                                          ValaCodeContext* context);
static void vala_yield_statement_real_emit (ValaCodeNode* base,
                                     ValaCodeGenerator* codegen);
static GType vala_yield_statement_get_type_once (void);

/**
 * Creates a new yield statement.
 *
 * @param source_reference reference to source code
 * @return                 newly created yield statement
 */
ValaYieldStatement*
vala_yield_statement_construct (GType object_type,
                                ValaSourceReference* source_reference)
{
	ValaYieldStatement* self = NULL;
	self = (ValaYieldStatement*) vala_code_node_construct (object_type);
	vala_code_node_set_source_reference ((ValaCodeNode*) self, source_reference);
	return self;
}

ValaYieldStatement*
vala_yield_statement_new (ValaSourceReference* source_reference)
{
	return vala_yield_statement_construct (VALA_TYPE_YIELD_STATEMENT, source_reference);
}

static void
vala_yield_statement_real_accept (ValaCodeNode* base,
                                  ValaCodeVisitor* visitor)
{
	ValaYieldStatement * self;
	self = (ValaYieldStatement*) base;
	g_return_if_fail (visitor != NULL);
	vala_code_visitor_visit_yield_statement (visitor, self);
}

static gboolean
vala_yield_statement_real_check (ValaCodeNode* base,
                                 ValaCodeContext* context)
{
	ValaYieldStatement * self;
	gboolean _tmp0_;
	gboolean _tmp1_;
	gboolean _tmp4_ = FALSE;
	ValaSemanticAnalyzer* _tmp5_;
	ValaSemanticAnalyzer* _tmp6_;
	ValaMethod* _tmp7_;
	ValaMethod* _tmp8_;
	gboolean _tmp17_;
	gboolean _tmp18_;
	gboolean result;
	self = (ValaYieldStatement*) base;
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
	_tmp5_ = vala_code_context_get_analyzer (context);
	_tmp6_ = _tmp5_;
	_tmp7_ = vala_semantic_analyzer_get_current_method (_tmp6_);
	_tmp8_ = _tmp7_;
	if (_tmp8_ == NULL) {
		_tmp4_ = TRUE;
	} else {
		ValaSemanticAnalyzer* _tmp9_;
		ValaSemanticAnalyzer* _tmp10_;
		ValaMethod* _tmp11_;
		ValaMethod* _tmp12_;
		gboolean _tmp13_;
		gboolean _tmp14_;
		_tmp9_ = vala_code_context_get_analyzer (context);
		_tmp10_ = _tmp9_;
		_tmp11_ = vala_semantic_analyzer_get_current_method (_tmp10_);
		_tmp12_ = _tmp11_;
		_tmp13_ = vala_method_get_coroutine (_tmp12_);
		_tmp14_ = _tmp13_;
		_tmp4_ = !_tmp14_;
	}
	if (_tmp4_) {
		ValaSourceReference* _tmp15_;
		ValaSourceReference* _tmp16_;
		vala_code_node_set_error ((ValaCodeNode*) self, TRUE);
		_tmp15_ = vala_code_node_get_source_reference ((ValaCodeNode*) self);
		_tmp16_ = _tmp15_;
		vala_report_error (_tmp16_, "yield statement not available outside async method");
	}
	_tmp17_ = vala_code_node_get_error ((ValaCodeNode*) self);
	_tmp18_ = _tmp17_;
	result = !_tmp18_;
	return result;
}

static void
vala_yield_statement_real_emit (ValaCodeNode* base,
                                ValaCodeGenerator* codegen)
{
	ValaYieldStatement * self;
	self = (ValaYieldStatement*) base;
	g_return_if_fail (codegen != NULL);
	vala_code_visitor_visit_yield_statement ((ValaCodeVisitor*) codegen, self);
}

static void
vala_yield_statement_class_init (ValaYieldStatementClass * klass,
                                 gpointer klass_data)
{
	vala_yield_statement_parent_class = g_type_class_peek_parent (klass);
	((ValaCodeNodeClass *) klass)->accept = (void (*) (ValaCodeNode*, ValaCodeVisitor*)) vala_yield_statement_real_accept;
	((ValaCodeNodeClass *) klass)->check = (gboolean (*) (ValaCodeNode*, ValaCodeContext*)) vala_yield_statement_real_check;
	((ValaCodeNodeClass *) klass)->emit = (void (*) (ValaCodeNode*, ValaCodeGenerator*)) vala_yield_statement_real_emit;
}

static void
vala_yield_statement_vala_statement_interface_init (ValaStatementIface * iface,
                                                    gpointer iface_data)
{
	vala_yield_statement_vala_statement_parent_iface = g_type_interface_peek_parent (iface);
}

static void
vala_yield_statement_instance_init (ValaYieldStatement * self,
                                    gpointer klass)
{
}

/**
 * Represents a yield statement in the source code.
 */
static GType
vala_yield_statement_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (ValaYieldStatementClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) vala_yield_statement_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (ValaYieldStatement), 0, (GInstanceInitFunc) vala_yield_statement_instance_init, NULL };
	static const GInterfaceInfo vala_statement_info = { (GInterfaceInitFunc) vala_yield_statement_vala_statement_interface_init, (GInterfaceFinalizeFunc) NULL, NULL};
	GType vala_yield_statement_type_id;
	vala_yield_statement_type_id = g_type_register_static (VALA_TYPE_CODE_NODE, "ValaYieldStatement", &g_define_type_info, 0);
	g_type_add_interface_static (vala_yield_statement_type_id, VALA_TYPE_STATEMENT, &vala_statement_info);
	return vala_yield_statement_type_id;
}

GType
vala_yield_statement_get_type (void)
{
	static volatile gsize vala_yield_statement_type_id__once = 0;
	if (g_once_init_enter (&vala_yield_statement_type_id__once)) {
		GType vala_yield_statement_type_id;
		vala_yield_statement_type_id = vala_yield_statement_get_type_once ();
		g_once_init_leave (&vala_yield_statement_type_id__once, vala_yield_statement_type_id);
	}
	return vala_yield_statement_type_id__once;
}

