/* hashset.c generated by valac, the Vala compiler
 * generated from hashset.vala, do not modify */

/* hashset.vala
 *
 * Copyright (C) 1995-1997  Peter Mattis, Spencer Kimball and Josh MacDonald
 * Copyright (C) 1997-2000  GLib Team and others
 * Copyright (C) 2007-2009  Jürg Billeter
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

#include "valagee.h"
#include <glib.h>
#include <glib-object.h>

#define VALA_HASH_SET_MIN_SIZE 11
#define VALA_HASH_SET_MAX_SIZE 13845163

typedef struct _ValaHashSetNode ValaHashSetNode;

#define VALA_HASH_SET_TYPE_ITERATOR (vala_hash_set_iterator_get_type ())
#define VALA_HASH_SET_ITERATOR(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), VALA_HASH_SET_TYPE_ITERATOR, ValaHashSetIterator))
#define VALA_HASH_SET_ITERATOR_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), VALA_HASH_SET_TYPE_ITERATOR, ValaHashSetIteratorClass))
#define VALA_HASH_SET_IS_ITERATOR(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), VALA_HASH_SET_TYPE_ITERATOR))
#define VALA_HASH_SET_IS_ITERATOR_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), VALA_HASH_SET_TYPE_ITERATOR))
#define VALA_HASH_SET_ITERATOR_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), VALA_HASH_SET_TYPE_ITERATOR, ValaHashSetIteratorClass))

typedef struct _ValaHashSetIterator ValaHashSetIterator;
typedef struct _ValaHashSetIteratorClass ValaHashSetIteratorClass;
#define _vala_hash_set_node_free0(var) ((var == NULL) ? NULL : (var = (vala_hash_set_node_free (var), NULL)))
typedef struct _ValaHashSetIteratorPrivate ValaHashSetIteratorPrivate;
#define _vala_iterable_unref0(var) ((var == NULL) ? NULL : (var = (vala_iterable_unref (var), NULL)))
#define _vala_assert(expr, msg) if G_LIKELY (expr) ; else g_assertion_message_expr (G_LOG_DOMAIN, __FILE__, __LINE__, G_STRFUNC, msg);
#define _vala_return_if_fail(expr, msg) if G_LIKELY (expr) ; else { g_return_if_fail_warning (G_LOG_DOMAIN, G_STRFUNC, msg); return; }
#define _vala_return_val_if_fail(expr, msg, val) if G_LIKELY (expr) ; else { g_return_if_fail_warning (G_LOG_DOMAIN, G_STRFUNC, msg); return val; }
#define _vala_warn_if_fail(expr, msg) if G_LIKELY (expr) ; else g_warn_message (G_LOG_DOMAIN, __FILE__, __LINE__, G_STRFUNC, msg);

struct _ValaHashSetPrivate {
	GType g_type;
	GBoxedCopyFunc g_dup_func;
	GDestroyNotify g_destroy_func;
	gint _array_size;
	gint _nnodes;
	ValaHashSetNode** _nodes;
	gint _nodes_length1;
	gint __nodes_size_;
	gint _stamp;
	GHashFunc _hash_func;
	GEqualFunc _equal_func;
};

struct _ValaHashSetNode {
	gpointer key;
	ValaHashSetNode* next;
	guint key_hash;
};

struct _ValaHashSetIterator {
	ValaIterator parent_instance;
	ValaHashSetIteratorPrivate * priv;
};

struct _ValaHashSetIteratorClass {
	ValaIteratorClass parent_class;
};

struct _ValaHashSetIteratorPrivate {
	GType g_type;
	GBoxedCopyFunc g_dup_func;
	GDestroyNotify g_destroy_func;
	ValaHashSet* _set;
	gint _index;
	ValaHashSetNode* _node;
	ValaHashSetNode* _next;
	gint _stamp;
};

static gint ValaHashSet_private_offset;
static gpointer vala_hash_set_parent_class = NULL;
static gint ValaHashSetIterator_private_offset;
static gpointer vala_hash_set_iterator_parent_class = NULL;

static void vala_hash_set_node_free (ValaHashSetNode * self);
static ValaHashSetNode** vala_hash_set_lookup_node (ValaHashSet* self,
                                             gconstpointer key);
static gboolean vala_hash_set_real_contains (ValaCollection* base,
                                      gconstpointer key);
static GType vala_hash_set_real_get_element_type (ValaIterable* base);
static ValaIterator* vala_hash_set_real_iterator (ValaIterable* base);
static ValaHashSetIterator* vala_hash_set_iterator_new (GType g_type,
                                                 GBoxedCopyFunc g_dup_func,
                                                 GDestroyNotify g_destroy_func,
                                                 ValaHashSet* set);
static ValaHashSetIterator* vala_hash_set_iterator_construct (GType object_type,
                                                       GType g_type,
                                                       GBoxedCopyFunc g_dup_func,
                                                       GDestroyNotify g_destroy_func,
                                                       ValaHashSet* set);
static GType vala_hash_set_iterator_get_type (void) G_GNUC_CONST  G_GNUC_UNUSED ;
static gboolean vala_hash_set_real_add (ValaCollection* base,
                                 gconstpointer key);
static ValaHashSetNode* vala_hash_set_node_new (gpointer k,
                                         guint hash);
static void vala_hash_set_resize (ValaHashSet* self);
static gboolean vala_hash_set_real_remove (ValaCollection* base,
                                    gconstpointer key);
static void vala_hash_set_real_clear (ValaCollection* base);
static inline gboolean vala_hash_set_remove_helper (ValaHashSet* self,
                                      gconstpointer key);
static void vala_hash_set_node_instance_init (ValaHashSetNode * self);
static void vala_hash_set_iterator_set_set (ValaHashSetIterator* self,
                                     ValaHashSet* value);
static gboolean vala_hash_set_iterator_real_next (ValaIterator* base);
static gboolean vala_hash_set_iterator_real_has_next (ValaIterator* base);
static gpointer vala_hash_set_iterator_real_get (ValaIterator* base);
static void vala_hash_set_iterator_real_remove (ValaIterator* base);
static void vala_hash_set_iterator_finalize (ValaIterator * obj);
static GType vala_hash_set_iterator_get_type_once (void);
static void vala_hash_set_finalize (ValaIterable * obj);
static GType vala_hash_set_get_type_once (void);
static void _vala_array_destroy (gpointer array,
                          gssize array_length,
                          GDestroyNotify destroy_func);
static void _vala_array_free (gpointer array,
                       gssize array_length,
                       GDestroyNotify destroy_func);

static inline gpointer
vala_hash_set_get_instance_private (ValaHashSet* self)
{
	return G_STRUCT_MEMBER_P (self, ValaHashSet_private_offset);
}

static gint
vala_hash_set_real_get_size (ValaCollection* base)
{
	gint result;
	ValaHashSet* self;
	self = (ValaHashSet*) base;
	result = self->priv->_nnodes;
	return result;
}

void
vala_hash_set_set_hash_func (ValaHashSet* self,
                             GHashFunc value)
{
	g_return_if_fail (self != NULL);
	self->priv->_hash_func = value;
}

void
vala_hash_set_set_equal_func (ValaHashSet* self,
                              GEqualFunc value)
{
	g_return_if_fail (self != NULL);
	self->priv->_equal_func = value;
}

ValaHashSet*
vala_hash_set_construct (GType object_type,
                         GType g_type,
                         GBoxedCopyFunc g_dup_func,
                         GDestroyNotify g_destroy_func,
                         GHashFunc hash_func,
                         GEqualFunc equal_func)
{
	ValaHashSet* self = NULL;
	ValaHashSetNode** _tmp0_;
	self = (ValaHashSet*) vala_set_construct (object_type, g_type, (GBoxedCopyFunc) g_dup_func, (GDestroyNotify) g_destroy_func);
	self->priv->g_type = g_type;
	self->priv->g_dup_func = g_dup_func;
	self->priv->g_destroy_func = g_destroy_func;
	vala_hash_set_set_hash_func (self, hash_func);
	vala_hash_set_set_equal_func (self, equal_func);
	self->priv->_array_size = VALA_HASH_SET_MIN_SIZE;
	_tmp0_ = g_new0 (ValaHashSetNode*, self->priv->_array_size + 1);
	self->priv->_nodes = (_vala_array_free (self->priv->_nodes, self->priv->_nodes_length1, (GDestroyNotify) vala_hash_set_node_free), NULL);
	self->priv->_nodes = _tmp0_;
	self->priv->_nodes_length1 = self->priv->_array_size;
	self->priv->__nodes_size_ = self->priv->_nodes_length1;
	return self;
}

ValaHashSet*
vala_hash_set_new (GType g_type,
                   GBoxedCopyFunc g_dup_func,
                   GDestroyNotify g_destroy_func,
                   GHashFunc hash_func,
                   GEqualFunc equal_func)
{
	return vala_hash_set_construct (VALA_TYPE_HASH_SET, g_type, g_dup_func, g_destroy_func, hash_func, equal_func);
}

static ValaHashSetNode**
vala_hash_set_lookup_node (ValaHashSet* self,
                           gconstpointer key)
{
	guint hash_value = 0U;
	GHashFunc _tmp0_;
	ValaHashSetNode** node = NULL;
	ValaHashSetNode** _tmp1_;
	gint _tmp1__length1;
	ValaHashSetNode** _tmp10_;
	ValaHashSetNode** result;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_hash_func;
	hash_value = _tmp0_ (key);
	_tmp1_ = self->priv->_nodes;
	_tmp1__length1 = self->priv->_nodes_length1;
	node = &_tmp1_[hash_value % self->priv->_array_size];
	while (TRUE) {
		gboolean _tmp2_ = FALSE;
		ValaHashSetNode** _tmp3_;
		ValaHashSetNode** _tmp9_;
		_tmp3_ = node;
		if ((*_tmp3_) != NULL) {
			gboolean _tmp4_ = FALSE;
			ValaHashSetNode** _tmp5_;
			_tmp5_ = node;
			if (hash_value != (*_tmp5_)->key_hash) {
				_tmp4_ = TRUE;
			} else {
				GEqualFunc _tmp6_;
				ValaHashSetNode** _tmp7_;
				gconstpointer _tmp8_;
				_tmp6_ = self->priv->_equal_func;
				_tmp7_ = node;
				_tmp8_ = (*_tmp7_)->key;
				_tmp4_ = !_tmp6_ (_tmp8_, key);
			}
			_tmp2_ = _tmp4_;
		} else {
			_tmp2_ = FALSE;
		}
		if (!_tmp2_) {
			break;
		}
		_tmp9_ = node;
		node = &(*_tmp9_)->next;
	}
	_tmp10_ = node;
	result = _tmp10_;
	return result;
}

static gboolean
vala_hash_set_real_contains (ValaCollection* base,
                             gconstpointer key)
{
	ValaHashSet * self;
	ValaHashSetNode** node = NULL;
	ValaHashSetNode** _tmp0_;
	gboolean result;
	self = (ValaHashSet*) base;
	_tmp0_ = vala_hash_set_lookup_node (self, key);
	node = _tmp0_;
	result = (*node) != NULL;
	return result;
}

static GType
vala_hash_set_real_get_element_type (ValaIterable* base)
{
	ValaHashSet * self;
	GType result;
	self = (ValaHashSet*) base;
	result = self->priv->g_type;
	return result;
}

static ValaIterator*
vala_hash_set_real_iterator (ValaIterable* base)
{
	ValaHashSet * self;
	ValaHashSetIterator* _tmp0_;
	ValaIterator* result;
	self = (ValaHashSet*) base;
	_tmp0_ = vala_hash_set_iterator_new (self->priv->g_type, (GBoxedCopyFunc) self->priv->g_dup_func, (GDestroyNotify) self->priv->g_destroy_func, self);
	result = (ValaIterator*) _tmp0_;
	return result;
}

static gboolean
vala_hash_set_real_add (ValaCollection* base,
                        gconstpointer key)
{
	ValaHashSet * self;
	ValaHashSetNode** node = NULL;
	ValaHashSetNode** _tmp0_;
	ValaHashSetNode** _tmp1_;
	gboolean result;
	self = (ValaHashSet*) base;
	_tmp0_ = vala_hash_set_lookup_node (self, key);
	node = _tmp0_;
	_tmp1_ = node;
	if ((*_tmp1_) != NULL) {
		result = FALSE;
		return result;
	} else {
		guint hash_value = 0U;
		GHashFunc _tmp2_;
		ValaHashSetNode** _tmp3_;
		gpointer _tmp4_;
		ValaHashSetNode* _tmp5_;
		gint _tmp6_;
		gint _tmp7_;
		_tmp2_ = self->priv->_hash_func;
		hash_value = _tmp2_ (key);
		_tmp3_ = node;
		_tmp4_ = ((key != NULL) && (self->priv->g_dup_func != NULL)) ? self->priv->g_dup_func ((gpointer) key) : ((gpointer) key);
		_tmp5_ = vala_hash_set_node_new (_tmp4_, hash_value);
		*_tmp3_ = _tmp5_;
		_tmp6_ = self->priv->_nnodes;
		self->priv->_nnodes = _tmp6_ + 1;
		vala_hash_set_resize (self);
		_tmp7_ = self->priv->_stamp;
		self->priv->_stamp = _tmp7_ + 1;
		result = TRUE;
		return result;
	}
}

static gboolean
vala_hash_set_real_remove (ValaCollection* base,
                           gconstpointer key)
{
	ValaHashSet * self;
	ValaHashSetNode** node = NULL;
	ValaHashSetNode** _tmp0_;
	ValaHashSetNode** _tmp1_;
	gboolean result;
	self = (ValaHashSet*) base;
	_tmp0_ = vala_hash_set_lookup_node (self, key);
	node = _tmp0_;
	_tmp1_ = node;
	if ((*_tmp1_) != NULL) {
		ValaHashSetNode* next = NULL;
		ValaHashSetNode** _tmp2_;
		ValaHashSetNode* _tmp3_;
		ValaHashSetNode** _tmp4_;
		ValaHashSetNode** _tmp5_;
		ValaHashSetNode** _tmp6_;
		ValaHashSetNode* _tmp7_;
		gint _tmp8_;
		gint _tmp9_;
		_tmp2_ = node;
		_tmp3_ = (*_tmp2_)->next;
		(*_tmp2_)->next = NULL;
		next = _tmp3_;
		_tmp4_ = node;
		(((*_tmp4_)->key == NULL) || (self->priv->g_destroy_func == NULL)) ? NULL : ((*_tmp4_)->key = (self->priv->g_destroy_func ((*_tmp4_)->key), NULL));
		(*_tmp4_)->key = NULL;
		_tmp5_ = node;
		_vala_hash_set_node_free0 (*_tmp5_);
		_tmp6_ = node;
		_tmp7_ = next;
		next = NULL;
		*_tmp6_ = _tmp7_;
		_tmp8_ = self->priv->_nnodes;
		self->priv->_nnodes = _tmp8_ - 1;
		vala_hash_set_resize (self);
		_tmp9_ = self->priv->_stamp;
		self->priv->_stamp = _tmp9_ + 1;
		result = TRUE;
		_vala_hash_set_node_free0 (next);
		return result;
	}
	result = FALSE;
	return result;
}

static void
vala_hash_set_real_clear (ValaCollection* base)
{
	ValaHashSet * self;
	self = (ValaHashSet*) base;
	{
		gint i = 0;
		i = 0;
		{
			gboolean _tmp0_ = FALSE;
			_tmp0_ = TRUE;
			while (TRUE) {
				ValaHashSetNode* node = NULL;
				ValaHashSetNode** _tmp2_;
				gint _tmp2__length1;
				ValaHashSetNode* _tmp3_;
				if (!_tmp0_) {
					gint _tmp1_;
					_tmp1_ = i;
					i = _tmp1_ + 1;
				}
				_tmp0_ = FALSE;
				if (!(i < self->priv->_array_size)) {
					break;
				}
				_tmp2_ = self->priv->_nodes;
				_tmp2__length1 = self->priv->_nodes_length1;
				_tmp3_ = _tmp2_[i];
				_tmp2_[i] = NULL;
				node = _tmp3_;
				while (TRUE) {
					ValaHashSetNode* _tmp4_;
					ValaHashSetNode* next = NULL;
					ValaHashSetNode* _tmp5_;
					ValaHashSetNode* _tmp6_;
					ValaHashSetNode* _tmp7_;
					ValaHashSetNode* _tmp8_;
					_tmp4_ = node;
					if (!(_tmp4_ != NULL)) {
						break;
					}
					_tmp5_ = node;
					_tmp6_ = _tmp5_->next;
					_tmp5_->next = NULL;
					next = _tmp6_;
					_tmp7_ = node;
					((_tmp7_->key == NULL) || (self->priv->g_destroy_func == NULL)) ? NULL : (_tmp7_->key = (self->priv->g_destroy_func (_tmp7_->key), NULL));
					_tmp7_->key = NULL;
					_tmp8_ = next;
					next = NULL;
					_vala_hash_set_node_free0 (node);
					node = _tmp8_;
					_vala_hash_set_node_free0 (next);
				}
				_vala_hash_set_node_free0 (node);
			}
		}
	}
	self->priv->_nnodes = 0;
	vala_hash_set_resize (self);
}

static inline gboolean
vala_hash_set_remove_helper (ValaHashSet* self,
                             gconstpointer key)
{
	ValaHashSetNode** node = NULL;
	ValaHashSetNode** _tmp0_;
	ValaHashSetNode** _tmp1_;
	gboolean result;
	g_return_val_if_fail (self != NULL, FALSE);
	_tmp0_ = vala_hash_set_lookup_node (self, key);
	node = _tmp0_;
	_tmp1_ = node;
	if ((*_tmp1_) != NULL) {
		ValaHashSetNode** _tmp2_;
		ValaHashSetNode* next = NULL;
		ValaHashSetNode** _tmp3_;
		ValaHashSetNode* _tmp4_;
		ValaHashSetNode** _tmp5_;
		ValaHashSetNode** _tmp6_;
		ValaHashSetNode** _tmp7_;
		ValaHashSetNode* _tmp8_;
		gint _tmp9_;
		gint _tmp10_;
		_tmp2_ = node;
		_vala_assert ((*_tmp2_) != NULL, "*node != null");
		_tmp3_ = node;
		_tmp4_ = (*_tmp3_)->next;
		(*_tmp3_)->next = NULL;
		next = _tmp4_;
		_tmp5_ = node;
		(((*_tmp5_)->key == NULL) || (self->priv->g_destroy_func == NULL)) ? NULL : ((*_tmp5_)->key = (self->priv->g_destroy_func ((*_tmp5_)->key), NULL));
		(*_tmp5_)->key = NULL;
		_tmp6_ = node;
		_vala_hash_set_node_free0 (*_tmp6_);
		_tmp7_ = node;
		_tmp8_ = next;
		next = NULL;
		*_tmp7_ = _tmp8_;
		_tmp9_ = self->priv->_nnodes;
		self->priv->_nnodes = _tmp9_ - 1;
		_tmp10_ = self->priv->_stamp;
		self->priv->_stamp = _tmp10_ + 1;
		result = TRUE;
		_vala_hash_set_node_free0 (next);
		return result;
	}
	result = FALSE;
	return result;
}

static void
vala_hash_set_resize (ValaHashSet* self)
{
	gboolean _tmp0_ = FALSE;
	gboolean _tmp1_ = FALSE;
	g_return_if_fail (self != NULL);
	if (self->priv->_array_size >= (3 * self->priv->_nnodes)) {
		_tmp1_ = self->priv->_array_size >= VALA_HASH_SET_MIN_SIZE;
	} else {
		_tmp1_ = FALSE;
	}
	if (_tmp1_) {
		_tmp0_ = TRUE;
	} else {
		gboolean _tmp2_ = FALSE;
		if ((3 * self->priv->_array_size) <= self->priv->_nnodes) {
			_tmp2_ = self->priv->_array_size < VALA_HASH_SET_MAX_SIZE;
		} else {
			_tmp2_ = FALSE;
		}
		_tmp0_ = _tmp2_;
	}
	if (_tmp0_) {
		gint new_array_size = 0;
		ValaHashSetNode** new_nodes = NULL;
		ValaHashSetNode** _tmp3_;
		gint new_nodes_length1;
		gint _new_nodes_size_;
		ValaHashSetNode** _tmp19_;
		gint _tmp19__length1;
		new_array_size = (gint) g_spaced_primes_closest ((guint) self->priv->_nnodes);
		new_array_size = CLAMP (new_array_size, VALA_HASH_SET_MIN_SIZE, VALA_HASH_SET_MAX_SIZE);
		_tmp3_ = g_new0 (ValaHashSetNode*, new_array_size + 1);
		new_nodes = _tmp3_;
		new_nodes_length1 = new_array_size;
		_new_nodes_size_ = new_nodes_length1;
		{
			gint i = 0;
			i = 0;
			{
				gboolean _tmp4_ = FALSE;
				_tmp4_ = TRUE;
				while (TRUE) {
					ValaHashSetNode* node = NULL;
					ValaHashSetNode* next = NULL;
					if (!_tmp4_) {
						gint _tmp5_;
						_tmp5_ = i;
						i = _tmp5_ + 1;
					}
					_tmp4_ = FALSE;
					if (!(i < self->priv->_array_size)) {
						break;
					}
					next = NULL;
					{
						ValaHashSetNode** _tmp6_;
						gint _tmp6__length1;
						ValaHashSetNode* _tmp7_;
						gboolean _tmp8_ = FALSE;
						_tmp6_ = self->priv->_nodes;
						_tmp6__length1 = self->priv->_nodes_length1;
						_tmp7_ = _tmp6_[i];
						_tmp6_[i] = NULL;
						_vala_hash_set_node_free0 (node);
						node = _tmp7_;
						_tmp8_ = TRUE;
						while (TRUE) {
							ValaHashSetNode* _tmp10_;
							ValaHashSetNode* _tmp11_;
							ValaHashSetNode* _tmp12_;
							guint hash_val = 0U;
							ValaHashSetNode* _tmp13_;
							ValaHashSetNode* _tmp14_;
							ValaHashSetNode** _tmp15_;
							gint _tmp15__length1;
							ValaHashSetNode* _tmp16_;
							ValaHashSetNode** _tmp17_;
							gint _tmp17__length1;
							ValaHashSetNode* _tmp18_;
							if (!_tmp8_) {
								ValaHashSetNode* _tmp9_;
								_tmp9_ = next;
								next = NULL;
								_vala_hash_set_node_free0 (node);
								node = _tmp9_;
							}
							_tmp8_ = FALSE;
							_tmp10_ = node;
							if (!(_tmp10_ != NULL)) {
								break;
							}
							_tmp11_ = node;
							_tmp12_ = _tmp11_->next;
							_tmp11_->next = NULL;
							_vala_hash_set_node_free0 (next);
							next = _tmp12_;
							_tmp13_ = node;
							hash_val = _tmp13_->key_hash % new_array_size;
							_tmp14_ = node;
							_tmp15_ = new_nodes;
							_tmp15__length1 = new_nodes_length1;
							_tmp16_ = _tmp15_[hash_val];
							_tmp15_[hash_val] = NULL;
							_vala_hash_set_node_free0 (_tmp14_->next);
							_tmp14_->next = _tmp16_;
							_tmp17_ = new_nodes;
							_tmp17__length1 = new_nodes_length1;
							_tmp18_ = node;
							node = NULL;
							_vala_hash_set_node_free0 (_tmp17_[hash_val]);
							_tmp17_[hash_val] = _tmp18_;
						}
					}
					_vala_hash_set_node_free0 (next);
					_vala_hash_set_node_free0 (node);
				}
			}
		}
		_tmp19_ = new_nodes;
		_tmp19__length1 = new_nodes_length1;
		new_nodes = NULL;
		new_nodes_length1 = 0;
		self->priv->_nodes = (_vala_array_free (self->priv->_nodes, self->priv->_nodes_length1, (GDestroyNotify) vala_hash_set_node_free), NULL);
		self->priv->_nodes = _tmp19_;
		self->priv->_nodes_length1 = _tmp19__length1;
		self->priv->__nodes_size_ = self->priv->_nodes_length1;
		self->priv->_array_size = new_array_size;
		new_nodes = (_vala_array_free (new_nodes, new_nodes_length1, (GDestroyNotify) vala_hash_set_node_free), NULL);
	}
}

static ValaHashSetNode*
vala_hash_set_node_new (gpointer k,
                        guint hash)
{
	ValaHashSetNode* self;
	gpointer _tmp0_;
	self = g_slice_new0 (ValaHashSetNode);
	vala_hash_set_node_instance_init (self);
	_tmp0_ = k;
	k = NULL;
	self->key = _tmp0_;
	self->key_hash = hash;
	return self;
}

static void
vala_hash_set_node_instance_init (ValaHashSetNode * self)
{
}

static void
vala_hash_set_node_free (ValaHashSetNode * self)
{
	_vala_hash_set_node_free0 (self->next);
	g_slice_free (ValaHashSetNode, self);
}

static inline gpointer
vala_hash_set_iterator_get_instance_private (ValaHashSetIterator* self)
{
	return G_STRUCT_MEMBER_P (self, ValaHashSetIterator_private_offset);
}

static gpointer
_vala_iterable_ref0 (gpointer self)
{
	return self ? vala_iterable_ref (self) : NULL;
}

static void
vala_hash_set_iterator_set_set (ValaHashSetIterator* self,
                                ValaHashSet* value)
{
	ValaHashSet* _tmp0_;
	ValaHashSet* _tmp1_;
	g_return_if_fail (self != NULL);
	_tmp0_ = _vala_iterable_ref0 (value);
	_vala_iterable_unref0 (self->priv->_set);
	self->priv->_set = _tmp0_;
	_tmp1_ = self->priv->_set;
	self->priv->_stamp = _tmp1_->priv->_stamp;
}

static ValaHashSetIterator*
vala_hash_set_iterator_construct (GType object_type,
                                  GType g_type,
                                  GBoxedCopyFunc g_dup_func,
                                  GDestroyNotify g_destroy_func,
                                  ValaHashSet* set)
{
	ValaHashSetIterator* self = NULL;
	g_return_val_if_fail (set != NULL, NULL);
	self = (ValaHashSetIterator*) vala_iterator_construct (object_type, g_type, (GBoxedCopyFunc) g_dup_func, (GDestroyNotify) g_destroy_func);
	self->priv->g_type = g_type;
	self->priv->g_dup_func = g_dup_func;
	self->priv->g_destroy_func = g_destroy_func;
	vala_hash_set_iterator_set_set (self, set);
	return self;
}

static ValaHashSetIterator*
vala_hash_set_iterator_new (GType g_type,
                            GBoxedCopyFunc g_dup_func,
                            GDestroyNotify g_destroy_func,
                            ValaHashSet* set)
{
	return vala_hash_set_iterator_construct (VALA_HASH_SET_TYPE_ITERATOR, g_type, g_dup_func, g_destroy_func, set);
}

static gboolean
vala_hash_set_iterator_real_next (ValaIterator* base)
{
	ValaHashSetIterator * self;
	ValaHashSet* _tmp0_;
	ValaHashSetNode* _tmp1_;
	ValaHashSetNode* _tmp2_;
	gboolean result;
	self = (ValaHashSetIterator*) base;
	_tmp0_ = self->priv->_set;
	_vala_assert (self->priv->_stamp == _tmp0_->priv->_stamp, "_stamp == _set._stamp");
	if (!vala_iterator_has_next ((ValaIterator*) self)) {
		result = FALSE;
		return result;
	}
	_tmp1_ = self->priv->_next;
	self->priv->_node = _tmp1_;
	self->priv->_next = NULL;
	_tmp2_ = self->priv->_node;
	result = _tmp2_ != NULL;
	return result;
}

static gboolean
vala_hash_set_iterator_real_has_next (ValaIterator* base)
{
	ValaHashSetIterator * self;
	ValaHashSet* _tmp0_;
	ValaHashSetNode* _tmp1_;
	ValaHashSetNode* _tmp13_;
	gboolean result;
	self = (ValaHashSetIterator*) base;
	_tmp0_ = self->priv->_set;
	_vala_assert (self->priv->_stamp == _tmp0_->priv->_stamp, "_stamp == _set._stamp");
	_tmp1_ = self->priv->_next;
	if (_tmp1_ == NULL) {
		ValaHashSetNode* _tmp2_;
		ValaHashSetNode* _tmp3_;
		_tmp2_ = self->priv->_node;
		self->priv->_next = _tmp2_;
		_tmp3_ = self->priv->_next;
		if (_tmp3_ != NULL) {
			ValaHashSetNode* _tmp4_;
			ValaHashSetNode* _tmp5_;
			_tmp4_ = self->priv->_next;
			_tmp5_ = _tmp4_->next;
			self->priv->_next = _tmp5_;
		}
		while (TRUE) {
			gboolean _tmp6_ = FALSE;
			ValaHashSetNode* _tmp7_;
			gint _tmp9_;
			ValaHashSet* _tmp10_;
			ValaHashSetNode** _tmp11_;
			gint _tmp11__length1;
			ValaHashSetNode* _tmp12_;
			_tmp7_ = self->priv->_next;
			if (_tmp7_ == NULL) {
				ValaHashSet* _tmp8_;
				_tmp8_ = self->priv->_set;
				_tmp6_ = (self->priv->_index + 1) < _tmp8_->priv->_array_size;
			} else {
				_tmp6_ = FALSE;
			}
			if (!_tmp6_) {
				break;
			}
			_tmp9_ = self->priv->_index;
			self->priv->_index = _tmp9_ + 1;
			_tmp10_ = self->priv->_set;
			_tmp11_ = _tmp10_->priv->_nodes;
			_tmp11__length1 = _tmp10_->priv->_nodes_length1;
			_tmp12_ = _tmp11_[self->priv->_index];
			self->priv->_next = _tmp12_;
		}
	}
	_tmp13_ = self->priv->_next;
	result = _tmp13_ != NULL;
	return result;
}

static gpointer
vala_hash_set_iterator_real_get (ValaIterator* base)
{
	ValaHashSetIterator * self;
	ValaHashSet* _tmp0_;
	ValaHashSetNode* _tmp1_;
	ValaHashSetNode* _tmp2_;
	gconstpointer _tmp3_;
	gpointer _tmp4_;
	gpointer result;
	self = (ValaHashSetIterator*) base;
	_tmp0_ = self->priv->_set;
	_vala_assert (self->priv->_stamp == _tmp0_->priv->_stamp, "_stamp == _set._stamp");
	_tmp1_ = self->priv->_node;
	_vala_assert (_tmp1_ != NULL, "_node != null");
	_tmp2_ = self->priv->_node;
	_tmp3_ = _tmp2_->key;
	_tmp4_ = ((_tmp3_ != NULL) && (self->priv->g_dup_func != NULL)) ? self->priv->g_dup_func ((gpointer) _tmp3_) : ((gpointer) _tmp3_);
	result = _tmp4_;
	return result;
}

static void
vala_hash_set_iterator_real_remove (ValaIterator* base)
{
	ValaHashSetIterator * self;
	ValaHashSet* _tmp0_;
	ValaHashSetNode* _tmp1_;
	ValaHashSet* _tmp2_;
	ValaHashSetNode* _tmp3_;
	gconstpointer _tmp4_;
	ValaHashSet* _tmp5_;
	self = (ValaHashSetIterator*) base;
	_tmp0_ = self->priv->_set;
	_vala_assert (self->priv->_stamp == _tmp0_->priv->_stamp, "_stamp == _set._stamp");
	_tmp1_ = self->priv->_node;
	_vala_assert (_tmp1_ != NULL, "_node != null");
	vala_iterator_has_next ((ValaIterator*) self);
	_tmp2_ = self->priv->_set;
	_tmp3_ = self->priv->_node;
	_tmp4_ = _tmp3_->key;
	vala_hash_set_remove_helper (_tmp2_, _tmp4_);
	self->priv->_node = NULL;
	_tmp5_ = self->priv->_set;
	self->priv->_stamp = _tmp5_->priv->_stamp;
}

static gboolean
vala_hash_set_iterator_real_get_valid (ValaIterator* base)
{
	gboolean result;
	ValaHashSetIterator* self;
	ValaHashSetNode* _tmp0_;
	self = (ValaHashSetIterator*) base;
	_tmp0_ = self->priv->_node;
	result = _tmp0_ != NULL;
	return result;
}

static void
vala_hash_set_iterator_class_init (ValaHashSetIteratorClass * klass,
                                   gpointer klass_data)
{
	vala_hash_set_iterator_parent_class = g_type_class_peek_parent (klass);
	((ValaIteratorClass *) klass)->finalize = vala_hash_set_iterator_finalize;
	g_type_class_adjust_private_offset (klass, &ValaHashSetIterator_private_offset);
	((ValaIteratorClass *) klass)->next = (gboolean (*) (ValaIterator*)) vala_hash_set_iterator_real_next;
	((ValaIteratorClass *) klass)->has_next = (gboolean (*) (ValaIterator*)) vala_hash_set_iterator_real_has_next;
	((ValaIteratorClass *) klass)->get = (gpointer (*) (ValaIterator*)) vala_hash_set_iterator_real_get;
	((ValaIteratorClass *) klass)->remove = (void (*) (ValaIterator*)) vala_hash_set_iterator_real_remove;
	VALA_ITERATOR_CLASS (klass)->get_valid = (gboolean (*) (ValaIterator*)) vala_hash_set_iterator_real_get_valid;
}

static void
vala_hash_set_iterator_instance_init (ValaHashSetIterator * self,
                                      gpointer klass)
{
	self->priv = vala_hash_set_iterator_get_instance_private (self);
	self->priv->_index = -1;
	self->priv->_stamp = 0;
}

static void
vala_hash_set_iterator_finalize (ValaIterator * obj)
{
	ValaHashSetIterator * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, VALA_HASH_SET_TYPE_ITERATOR, ValaHashSetIterator);
	_vala_iterable_unref0 (self->priv->_set);
	VALA_ITERATOR_CLASS (vala_hash_set_iterator_parent_class)->finalize (obj);
}

static GType
vala_hash_set_iterator_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (ValaHashSetIteratorClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) vala_hash_set_iterator_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (ValaHashSetIterator), 0, (GInstanceInitFunc) vala_hash_set_iterator_instance_init, NULL };
	GType vala_hash_set_iterator_type_id;
	vala_hash_set_iterator_type_id = g_type_register_static (VALA_TYPE_ITERATOR, "ValaHashSetIterator", &g_define_type_info, 0);
	ValaHashSetIterator_private_offset = g_type_add_instance_private (vala_hash_set_iterator_type_id, sizeof (ValaHashSetIteratorPrivate));
	return vala_hash_set_iterator_type_id;
}

static GType
vala_hash_set_iterator_get_type (void)
{
	static volatile gsize vala_hash_set_iterator_type_id__once = 0;
	if (g_once_init_enter (&vala_hash_set_iterator_type_id__once)) {
		GType vala_hash_set_iterator_type_id;
		vala_hash_set_iterator_type_id = vala_hash_set_iterator_get_type_once ();
		g_once_init_leave (&vala_hash_set_iterator_type_id__once, vala_hash_set_iterator_type_id);
	}
	return vala_hash_set_iterator_type_id__once;
}

static void
vala_hash_set_class_init (ValaHashSetClass * klass,
                          gpointer klass_data)
{
	vala_hash_set_parent_class = g_type_class_peek_parent (klass);
	((ValaIterableClass *) klass)->finalize = vala_hash_set_finalize;
	g_type_class_adjust_private_offset (klass, &ValaHashSet_private_offset);
	((ValaCollectionClass *) klass)->contains = (gboolean (*) (ValaCollection*, gconstpointer)) vala_hash_set_real_contains;
	((ValaIterableClass *) klass)->get_element_type = (GType (*) (ValaIterable*)) vala_hash_set_real_get_element_type;
	((ValaIterableClass *) klass)->iterator = (ValaIterator* (*) (ValaIterable*)) vala_hash_set_real_iterator;
	((ValaCollectionClass *) klass)->add = (gboolean (*) (ValaCollection*, gconstpointer)) vala_hash_set_real_add;
	((ValaCollectionClass *) klass)->remove = (gboolean (*) (ValaCollection*, gconstpointer)) vala_hash_set_real_remove;
	((ValaCollectionClass *) klass)->clear = (void (*) (ValaCollection*)) vala_hash_set_real_clear;
	VALA_COLLECTION_CLASS (klass)->get_size = (gint (*) (ValaCollection*)) vala_hash_set_real_get_size;
}

static void
vala_hash_set_instance_init (ValaHashSet * self,
                             gpointer klass)
{
	self->priv = vala_hash_set_get_instance_private (self);
	self->priv->_stamp = 0;
}

static void
vala_hash_set_finalize (ValaIterable * obj)
{
	ValaHashSet * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, VALA_TYPE_HASH_SET, ValaHashSet);
	vala_collection_clear ((ValaCollection*) self);
	self->priv->_nodes = (_vala_array_free (self->priv->_nodes, self->priv->_nodes_length1, (GDestroyNotify) vala_hash_set_node_free), NULL);
	VALA_ITERABLE_CLASS (vala_hash_set_parent_class)->finalize (obj);
}

/**
 * Hashtable implementation of the Set interface.
 */
static GType
vala_hash_set_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (ValaHashSetClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) vala_hash_set_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (ValaHashSet), 0, (GInstanceInitFunc) vala_hash_set_instance_init, NULL };
	GType vala_hash_set_type_id;
	vala_hash_set_type_id = g_type_register_static (VALA_TYPE_SET, "ValaHashSet", &g_define_type_info, 0);
	ValaHashSet_private_offset = g_type_add_instance_private (vala_hash_set_type_id, sizeof (ValaHashSetPrivate));
	return vala_hash_set_type_id;
}

GType
vala_hash_set_get_type (void)
{
	static volatile gsize vala_hash_set_type_id__once = 0;
	if (g_once_init_enter (&vala_hash_set_type_id__once)) {
		GType vala_hash_set_type_id;
		vala_hash_set_type_id = vala_hash_set_get_type_once ();
		g_once_init_leave (&vala_hash_set_type_id__once, vala_hash_set_type_id);
	}
	return vala_hash_set_type_id__once;
}

static void
_vala_array_destroy (gpointer array,
                     gssize array_length,
                     GDestroyNotify destroy_func)
{
	if ((array != NULL) && (destroy_func != NULL)) {
		gssize i;
		for (i = 0; i < array_length; i = i + 1) {
			if (((gpointer*) array)[i] != NULL) {
				destroy_func (((gpointer*) array)[i]);
			}
		}
	}
}

static void
_vala_array_free (gpointer array,
                  gssize array_length,
                  GDestroyNotify destroy_func)
{
	_vala_array_destroy (array, array_length, destroy_func);
	g_free (array);
}

