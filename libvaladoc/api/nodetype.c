/* nodetype.c generated by valac, the Vala compiler
 * generated from nodetype.vala, do not modify */

/* node.vala
 *
 * Copyright (C) 2008-2009	Didier Villevalois
 * Copyright (C) 2007-2012	Florian Brosch
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
 * 	Didier 'Ptitjes Villevalois <ptitjes@free.fr>
 */

#include "valadoc.h"

/**
 * Specifies the context of a node.
 */
static GType
valadoc_api_node_type_get_type_once (void)
{
	static const GEnumValue values[] = {{VALADOC_API_NODE_TYPE_CLASS, "VALADOC_API_NODE_TYPE_CLASS", "class"}, {VALADOC_API_NODE_TYPE_CONSTANT, "VALADOC_API_NODE_TYPE_CONSTANT", "constant"}, {VALADOC_API_NODE_TYPE_CREATION_METHOD, "VALADOC_API_NODE_TYPE_CREATION_METHOD", "creation-method"}, {VALADOC_API_NODE_TYPE_DELEGATE, "VALADOC_API_NODE_TYPE_DELEGATE", "delegate"}, {VALADOC_API_NODE_TYPE_ENUM, "VALADOC_API_NODE_TYPE_ENUM", "enum"}, {VALADOC_API_NODE_TYPE_ENUM_VALUE, "VALADOC_API_NODE_TYPE_ENUM_VALUE", "enum-value"}, {VALADOC_API_NODE_TYPE_ERROR_CODE, "VALADOC_API_NODE_TYPE_ERROR_CODE", "error-code"}, {VALADOC_API_NODE_TYPE_ERROR_DOMAIN, "VALADOC_API_NODE_TYPE_ERROR_DOMAIN", "error-domain"}, {VALADOC_API_NODE_TYPE_FIELD, "VALADOC_API_NODE_TYPE_FIELD", "field"}, {VALADOC_API_NODE_TYPE_FORMAL_PARAMETER, "VALADOC_API_NODE_TYPE_FORMAL_PARAMETER", "formal-parameter"}, {VALADOC_API_NODE_TYPE_INTERFACE, "VALADOC_API_NODE_TYPE_INTERFACE", "interface"}, {VALADOC_API_NODE_TYPE_METHOD, "VALADOC_API_NODE_TYPE_METHOD", "method"}, {VALADOC_API_NODE_TYPE_NAMESPACE, "VALADOC_API_NODE_TYPE_NAMESPACE", "namespace"}, {VALADOC_API_NODE_TYPE_PACKAGE, "VALADOC_API_NODE_TYPE_PACKAGE", "package"}, {VALADOC_API_NODE_TYPE_PROPERTY, "VALADOC_API_NODE_TYPE_PROPERTY", "property"}, {VALADOC_API_NODE_TYPE_PROPERTY_ACCESSOR, "VALADOC_API_NODE_TYPE_PROPERTY_ACCESSOR", "property-accessor"}, {VALADOC_API_NODE_TYPE_SIGNAL, "VALADOC_API_NODE_TYPE_SIGNAL", "signal"}, {VALADOC_API_NODE_TYPE_STATIC_METHOD, "VALADOC_API_NODE_TYPE_STATIC_METHOD", "static-method"}, {VALADOC_API_NODE_TYPE_STRUCT, "VALADOC_API_NODE_TYPE_STRUCT", "struct"}, {VALADOC_API_NODE_TYPE_TYPE_PARAMETER, "VALADOC_API_NODE_TYPE_TYPE_PARAMETER", "type-parameter"}, {0, NULL, NULL}};
	GType valadoc_api_node_type_type_id;
	valadoc_api_node_type_type_id = g_enum_register_static ("ValadocApiNodeType", values);
	return valadoc_api_node_type_type_id;
}

GType
valadoc_api_node_type_get_type (void)
{
	static volatile gsize valadoc_api_node_type_type_id__once = 0;
	if (g_once_init_enter (&valadoc_api_node_type_type_id__once)) {
		GType valadoc_api_node_type_type_id;
		valadoc_api_node_type_type_id = valadoc_api_node_type_get_type_once ();
		g_once_init_leave (&valadoc_api_node_type_type_id__once, valadoc_api_node_type_type_id);
	}
	return valadoc_api_node_type_type_id__once;
}

