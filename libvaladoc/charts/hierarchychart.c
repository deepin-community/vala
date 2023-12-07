/* hierarchychart.c generated by valac, the Vala compiler
 * generated from hierarchychart.vala, do not modify */

/* hierarchychart.vala
 *
 * Copyright (C) 2008  Florian Brosch
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
#include <glib-object.h>
#include <glib.h>
#include <gvc.h>
#include <valagee.h>

enum  {
	VALADOC_CHARTS_HIERARCHY_0_PROPERTY,
	VALADOC_CHARTS_HIERARCHY_NUM_PROPERTIES
};
static GParamSpec* valadoc_charts_hierarchy_properties[VALADOC_CHARTS_HIERARCHY_NUM_PROPERTIES];
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _vala_iterator_unref0(var) ((var == NULL) ? NULL : (var = (vala_iterator_unref (var), NULL)))
#define _vala_iterable_unref0(var) ((var == NULL) ? NULL : (var = (vala_iterable_unref (var), NULL)))

static gpointer valadoc_charts_hierarchy_parent_class = NULL;

static void valadoc_charts_hierarchy_draw_implemented_interfaces (ValadocChartsHierarchy* self,
                                                           Agnode_t* child,
                                                           ValaCollection* interfaces);
static void valadoc_charts_hierarchy_draw_parent_classes (ValadocChartsHierarchy* self,
                                                   ValadocApiClass* item,
                                                   Agnode_t* child);
static void valadoc_charts_hierarchy_draw_parent_structs (ValadocChartsHierarchy* self,
                                                   ValadocApiStruct* item,
                                                   Agnode_t* child);
static void valadoc_charts_hierarchy_real_visit_interface (ValadocApiVisitor* base,
                                                    ValadocApiInterface* item);
static void valadoc_charts_hierarchy_real_visit_class (ValadocApiVisitor* base,
                                                ValadocApiClass* item);
static void valadoc_charts_hierarchy_real_visit_struct (ValadocApiVisitor* base,
                                                 ValadocApiStruct* item);
static GType valadoc_charts_hierarchy_get_type_once (void);

ValadocChartsHierarchy*
valadoc_charts_hierarchy_construct (GType object_type,
                                    ValadocChartsFactory* factory,
                                    ValadocApiNode* node)
{
	ValadocChartsHierarchy * self = NULL;
	g_return_val_if_fail (factory != NULL, NULL);
	g_return_val_if_fail (node != NULL, NULL);
	self = (ValadocChartsHierarchy*) valadoc_charts_chart_construct (object_type, factory, node);
	return self;
}

ValadocChartsHierarchy*
valadoc_charts_hierarchy_new (ValadocChartsFactory* factory,
                              ValadocApiNode* node)
{
	return valadoc_charts_hierarchy_construct (VALADOC_CHARTS_TYPE_HIERARCHY, factory, node);
}

static void
valadoc_charts_hierarchy_draw_implemented_interfaces (ValadocChartsHierarchy* self,
                                                      Agnode_t* child,
                                                      ValaCollection* interfaces)
{
	g_return_if_fail (self != NULL);
	g_return_if_fail (child != NULL);
	g_return_if_fail (interfaces != NULL);
	{
		ValaIterator* _typeref_it = NULL;
		ValaIterator* _tmp0_;
		_tmp0_ = vala_iterable_iterator ((ValaIterable*) interfaces);
		_typeref_it = _tmp0_;
		while (TRUE) {
			ValaIterator* _tmp1_;
			ValadocApiTypeReference* typeref = NULL;
			ValaIterator* _tmp2_;
			gpointer _tmp3_;
			Agnode_t* parent = NULL;
			ValadocChartsFactory* _tmp4_;
			Agraph_t* _tmp5_;
			ValadocApiTypeReference* _tmp6_;
			ValadocApiItem* _tmp7_;
			ValadocApiItem* _tmp8_;
			Agnode_t* _tmp9_;
			ValadocChartsFactory* _tmp10_;
			Agraph_t* _tmp11_;
			Agnode_t* _tmp12_;
			Agedge_t* _tmp13_;
			_tmp1_ = _typeref_it;
			if (!vala_iterator_next (_tmp1_)) {
				break;
			}
			_tmp2_ = _typeref_it;
			_tmp3_ = vala_iterator_get (_tmp2_);
			typeref = (ValadocApiTypeReference*) _tmp3_;
			_tmp4_ = ((ValadocChartsChart*) self)->factory;
			_tmp5_ = ((ValadocChartsChart*) self)->graph;
			_tmp6_ = typeref;
			_tmp7_ = valadoc_api_typereference_get_data_type (_tmp6_);
			_tmp8_ = _tmp7_;
			_tmp9_ = valadoc_charts_factory_create_interface (_tmp4_, _tmp5_, G_TYPE_CHECK_INSTANCE_CAST (_tmp8_, VALADOC_API_TYPE_INTERFACE, ValadocApiInterface));
			parent = _tmp9_;
			_tmp10_ = ((ValadocChartsChart*) self)->factory;
			_tmp11_ = ((ValadocChartsChart*) self)->graph;
			_tmp12_ = parent;
			_tmp13_ = valadoc_charts_factory_add_children (_tmp10_, _tmp11_, _tmp12_, child);
			_g_object_unref0 (typeref);
		}
		_vala_iterator_unref0 (_typeref_it);
	}
}

static void
valadoc_charts_hierarchy_draw_parent_classes (ValadocChartsHierarchy* self,
                                              ValadocApiClass* item,
                                              Agnode_t* child)
{
	Agnode_t* parent = NULL;
	ValadocChartsFactory* _tmp0_;
	Agraph_t* _tmp1_;
	Agnode_t* _tmp2_;
	ValadocApiTypeReference* _tmp7_;
	ValadocApiTypeReference* _tmp8_;
	Agnode_t* _tmp14_;
	ValaCollection* _tmp15_;
	ValaCollection* _tmp16_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (item != NULL);
	_tmp0_ = ((ValadocChartsChart*) self)->factory;
	_tmp1_ = ((ValadocChartsChart*) self)->graph;
	_tmp2_ = valadoc_charts_factory_create_class (_tmp0_, _tmp1_, item);
	parent = _tmp2_;
	if (child != NULL) {
		ValadocChartsFactory* _tmp3_;
		Agraph_t* _tmp4_;
		Agnode_t* _tmp5_;
		Agedge_t* _tmp6_;
		_tmp3_ = ((ValadocChartsChart*) self)->factory;
		_tmp4_ = ((ValadocChartsChart*) self)->graph;
		_tmp5_ = parent;
		_tmp6_ = valadoc_charts_factory_add_children (_tmp3_, _tmp4_, _tmp5_, child);
	}
	_tmp7_ = valadoc_api_class_get_base_type (item);
	_tmp8_ = _tmp7_;
	if (_tmp8_ != NULL) {
		ValadocApiTypeReference* _tmp9_;
		ValadocApiTypeReference* _tmp10_;
		ValadocApiItem* _tmp11_;
		ValadocApiItem* _tmp12_;
		Agnode_t* _tmp13_;
		_tmp9_ = valadoc_api_class_get_base_type (item);
		_tmp10_ = _tmp9_;
		_tmp11_ = valadoc_api_typereference_get_data_type (_tmp10_);
		_tmp12_ = _tmp11_;
		_tmp13_ = parent;
		valadoc_charts_hierarchy_draw_parent_classes (self, G_TYPE_CHECK_INSTANCE_CAST (_tmp12_, VALADOC_API_TYPE_CLASS, ValadocApiClass), _tmp13_);
	}
	_tmp14_ = parent;
	_tmp15_ = valadoc_api_class_get_implemented_interface_list (item);
	_tmp16_ = _tmp15_;
	valadoc_charts_hierarchy_draw_implemented_interfaces (self, _tmp14_, _tmp16_);
	_vala_iterable_unref0 (_tmp16_);
}

static void
valadoc_charts_hierarchy_draw_parent_structs (ValadocChartsHierarchy* self,
                                              ValadocApiStruct* item,
                                              Agnode_t* child)
{
	Agnode_t* parent = NULL;
	ValadocChartsFactory* _tmp0_;
	Agraph_t* _tmp1_;
	Agnode_t* _tmp2_;
	ValadocApiTypeReference* _tmp7_;
	ValadocApiTypeReference* _tmp8_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (item != NULL);
	_tmp0_ = ((ValadocChartsChart*) self)->factory;
	_tmp1_ = ((ValadocChartsChart*) self)->graph;
	_tmp2_ = valadoc_charts_factory_create_struct (_tmp0_, _tmp1_, item);
	parent = _tmp2_;
	if (child != NULL) {
		ValadocChartsFactory* _tmp3_;
		Agraph_t* _tmp4_;
		Agnode_t* _tmp5_;
		Agedge_t* _tmp6_;
		_tmp3_ = ((ValadocChartsChart*) self)->factory;
		_tmp4_ = ((ValadocChartsChart*) self)->graph;
		_tmp5_ = parent;
		_tmp6_ = valadoc_charts_factory_add_children (_tmp3_, _tmp4_, _tmp5_, child);
	}
	_tmp7_ = valadoc_api_struct_get_base_type (item);
	_tmp8_ = _tmp7_;
	if (_tmp8_ != NULL) {
		ValadocApiTypeReference* _tmp9_;
		ValadocApiTypeReference* _tmp10_;
		ValadocApiItem* _tmp11_;
		ValadocApiItem* _tmp12_;
		Agnode_t* _tmp13_;
		_tmp9_ = valadoc_api_struct_get_base_type (item);
		_tmp10_ = _tmp9_;
		_tmp11_ = valadoc_api_typereference_get_data_type (_tmp10_);
		_tmp12_ = _tmp11_;
		_tmp13_ = parent;
		valadoc_charts_hierarchy_draw_parent_structs (self, G_TYPE_CHECK_INSTANCE_CAST (_tmp12_, VALADOC_API_TYPE_STRUCT, ValadocApiStruct), _tmp13_);
	}
}

static void
valadoc_charts_hierarchy_real_visit_interface (ValadocApiVisitor* base,
                                               ValadocApiInterface* item)
{
	ValadocChartsHierarchy * self;
	Agnode_t* iface = NULL;
	ValadocChartsFactory* _tmp0_;
	Agraph_t* _tmp1_;
	Agnode_t* _tmp2_;
	ValadocApiTypeReference* _tmp3_;
	ValadocApiTypeReference* _tmp4_;
	Agnode_t* _tmp10_;
	ValaCollection* _tmp11_;
	ValaCollection* _tmp12_;
	self = (ValadocChartsHierarchy*) base;
	g_return_if_fail (item != NULL);
	_tmp0_ = ((ValadocChartsChart*) self)->factory;
	_tmp1_ = ((ValadocChartsChart*) self)->graph;
	_tmp2_ = valadoc_charts_factory_create_interface (_tmp0_, _tmp1_, item);
	iface = _tmp2_;
	_tmp3_ = valadoc_api_interface_get_base_type (item);
	_tmp4_ = _tmp3_;
	if (_tmp4_ != NULL) {
		ValadocApiTypeReference* _tmp5_;
		ValadocApiTypeReference* _tmp6_;
		ValadocApiItem* _tmp7_;
		ValadocApiItem* _tmp8_;
		Agnode_t* _tmp9_;
		_tmp5_ = valadoc_api_interface_get_base_type (item);
		_tmp6_ = _tmp5_;
		_tmp7_ = valadoc_api_typereference_get_data_type (_tmp6_);
		_tmp8_ = _tmp7_;
		_tmp9_ = iface;
		valadoc_charts_hierarchy_draw_parent_classes (self, G_TYPE_CHECK_INSTANCE_CAST (_tmp8_, VALADOC_API_TYPE_CLASS, ValadocApiClass), _tmp9_);
	}
	_tmp10_ = iface;
	_tmp11_ = valadoc_api_interface_get_implemented_interface_list (item);
	_tmp12_ = _tmp11_;
	valadoc_charts_hierarchy_draw_implemented_interfaces (self, _tmp10_, _tmp12_);
	_vala_iterable_unref0 (_tmp12_);
}

static void
valadoc_charts_hierarchy_real_visit_class (ValadocApiVisitor* base,
                                           ValadocApiClass* item)
{
	ValadocChartsHierarchy * self;
	self = (ValadocChartsHierarchy*) base;
	g_return_if_fail (item != NULL);
	valadoc_charts_hierarchy_draw_parent_classes (self, item, NULL);
}

static void
valadoc_charts_hierarchy_real_visit_struct (ValadocApiVisitor* base,
                                            ValadocApiStruct* item)
{
	ValadocChartsHierarchy * self;
	self = (ValadocChartsHierarchy*) base;
	g_return_if_fail (item != NULL);
	valadoc_charts_hierarchy_draw_parent_structs (self, item, NULL);
}

static void
valadoc_charts_hierarchy_class_init (ValadocChartsHierarchyClass * klass,
                                     gpointer klass_data)
{
	valadoc_charts_hierarchy_parent_class = g_type_class_peek_parent (klass);
	((ValadocApiVisitorClass *) klass)->visit_interface = (void (*) (ValadocApiVisitor*, ValadocApiInterface*)) valadoc_charts_hierarchy_real_visit_interface;
	((ValadocApiVisitorClass *) klass)->visit_class = (void (*) (ValadocApiVisitor*, ValadocApiClass*)) valadoc_charts_hierarchy_real_visit_class;
	((ValadocApiVisitorClass *) klass)->visit_struct = (void (*) (ValadocApiVisitor*, ValadocApiStruct*)) valadoc_charts_hierarchy_real_visit_struct;
}

static void
valadoc_charts_hierarchy_instance_init (ValadocChartsHierarchy * self,
                                        gpointer klass)
{
}

static GType
valadoc_charts_hierarchy_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (ValadocChartsHierarchyClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) valadoc_charts_hierarchy_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (ValadocChartsHierarchy), 0, (GInstanceInitFunc) valadoc_charts_hierarchy_instance_init, NULL };
	GType valadoc_charts_hierarchy_type_id;
	valadoc_charts_hierarchy_type_id = g_type_register_static (VALADOC_CHARTS_TYPE_CHART, "ValadocChartsHierarchy", &g_define_type_info, 0);
	return valadoc_charts_hierarchy_type_id;
}

GType
valadoc_charts_hierarchy_get_type (void)
{
	static volatile gsize valadoc_charts_hierarchy_type_id__once = 0;
	if (g_once_init_enter (&valadoc_charts_hierarchy_type_id__once)) {
		GType valadoc_charts_hierarchy_type_id;
		valadoc_charts_hierarchy_type_id = valadoc_charts_hierarchy_get_type_once ();
		g_once_init_leave (&valadoc_charts_hierarchy_type_id__once, valadoc_charts_hierarchy_type_id);
	}
	return valadoc_charts_hierarchy_type_id__once;
}

