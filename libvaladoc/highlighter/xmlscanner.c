/* xmlscanner.c generated by valac, the Vala compiler
 * generated from xmlscanner.vala, do not modify */

/* xmlscanner.vala
 *
 * Copyright (C) 2015       Florian Brosch
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
#include <glib.h>
#include <stdlib.h>
#include <string.h>
#include <glib-object.h>

enum  {
	VALADOC_HIGHLIGHTER_XML_SCANNER_0_PROPERTY,
	VALADOC_HIGHLIGHTER_XML_SCANNER_NUM_PROPERTIES
};
static GParamSpec* valadoc_highlighter_xml_scanner_properties[VALADOC_HIGHLIGHTER_XML_SCANNER_NUM_PROPERTIES];
#define _g_free0(var) (var = (g_free (var), NULL))
#define _vala_assert(expr, msg) if G_LIKELY (expr) ; else g_assertion_message_expr (G_LOG_DOMAIN, __FILE__, __LINE__, G_STRFUNC, msg);
#define _vala_return_if_fail(expr, msg) if G_LIKELY (expr) ; else { g_return_if_fail_warning (G_LOG_DOMAIN, G_STRFUNC, msg); return; }
#define _vala_return_val_if_fail(expr, msg, val) if G_LIKELY (expr) ; else { g_return_if_fail_warning (G_LOG_DOMAIN, G_STRFUNC, msg); return val; }
#define _vala_warn_if_fail(expr, msg) if G_LIKELY (expr) ; else g_warn_message (G_LOG_DOMAIN, __FILE__, __LINE__, G_STRFUNC, msg);

struct _ValadocHighlighterXmlScannerPrivate {
	GQueue* token_queue;
	const gchar* content;
	const gchar* pos;
};

static gint ValadocHighlighterXmlScanner_private_offset;
static gpointer valadoc_highlighter_xml_scanner_parent_class = NULL;
static ValadocHighlighterScannerIface * valadoc_highlighter_xml_scanner_valadoc_highlighter_scanner_parent_iface = NULL;

static void _valadoc_highlighter_code_token_unref0_ (gpointer var);
static inline void _g_queue_free__valadoc_highlighter_code_token_unref0_ (GQueue* self);
static ValadocHighlighterCodeToken* valadoc_highlighter_xml_scanner_real_next (ValadocHighlighterScanner* base);
static gboolean valadoc_highlighter_xml_scanner_queue_escape (ValadocHighlighterXmlScanner* self);
static ValadocHighlighterCodeToken* valadoc_highlighter_xml_scanner_dispatch (ValadocHighlighterXmlScanner* self,
                                                                       const gchar* start,
                                                                       const gchar* end);
static gboolean valadoc_highlighter_xml_scanner_queue_end_element (ValadocHighlighterXmlScanner* self);
static gboolean valadoc_highlighter_xml_scanner_queue_comment (ValadocHighlighterXmlScanner* self);
static gboolean valadoc_highlighter_xml_scanner_queue_start_element (ValadocHighlighterXmlScanner* self,
                                                              const gchar* dispatch_start,
                                                              gboolean xml_decl);
static gboolean valadoc_highlighter_xml_scanner_skip_optional_spaces (const gchar** pos);
static gboolean valadoc_highlighter_xml_scanner_skip_id (const gchar** pos);
static void valadoc_highlighter_xml_scanner_queue_token (ValadocHighlighterXmlScanner* self,
                                                  const gchar* start,
                                                  const gchar* end,
                                                  ValadocHighlighterCodeTokenType token_type);
static gboolean valadoc_highlighter_xml_scanner_queue_attributes (ValadocHighlighterXmlScanner* self);
static inline gboolean valadoc_highlighter_xml_scanner_is_id_char (gchar c);
 G_GNUC_INTERNAL gboolean valadoc_highlighter_xml_scanner_is_xml (const gchar* source);
static void valadoc_highlighter_xml_scanner_finalize (GObject * obj);
static GType valadoc_highlighter_xml_scanner_get_type_once (void);

static inline gpointer
valadoc_highlighter_xml_scanner_get_instance_private (ValadocHighlighterXmlScanner* self)
{
	return G_STRUCT_MEMBER_P (self, ValadocHighlighterXmlScanner_private_offset);
}

static void
_valadoc_highlighter_code_token_unref0_ (gpointer var)
{
	(var == NULL) ? NULL : (var = (valadoc_highlighter_code_token_unref (var), NULL));
}

static inline void
_g_queue_free__valadoc_highlighter_code_token_unref0_ (GQueue* self)
{
	g_queue_free_full (self, (GDestroyNotify) _valadoc_highlighter_code_token_unref0_);
}

ValadocHighlighterXmlScanner*
valadoc_highlighter_xml_scanner_construct (GType object_type,
                                           const gchar* content)
{
	ValadocHighlighterXmlScanner * self = NULL;
	g_return_val_if_fail (content != NULL, NULL);
	self = (ValadocHighlighterXmlScanner*) g_object_new (object_type, NULL);
	self->priv->content = content;
	self->priv->pos = content;
	return self;
}

ValadocHighlighterXmlScanner*
valadoc_highlighter_xml_scanner_new (const gchar* content)
{
	return valadoc_highlighter_xml_scanner_construct (VALADOC_HIGHLIGHTER_TYPE_XML_SCANNER, content);
}

static gchar
string_get (const gchar* self,
            glong index)
{
	gchar _tmp0_;
	gchar result;
	g_return_val_if_fail (self != NULL, '\0');
	_tmp0_ = ((gchar*) self)[index];
	result = _tmp0_;
	return result;
}

static const gchar*
string_offset (const gchar* self,
               glong offset)
{
	const gchar* result;
	g_return_val_if_fail (self != NULL, NULL);
	result = (const gchar*) (((gchar*) self) + offset);
	return result;
}

static ValadocHighlighterCodeToken*
valadoc_highlighter_xml_scanner_real_next (ValadocHighlighterScanner* base)
{
	ValadocHighlighterXmlScanner * self;
	GQueue* _tmp0_;
	const gchar* start = NULL;
	GQueue* _tmp70_;
	ValadocHighlighterCodeToken* _tmp71_;
	const gchar* _tmp72_;
	const gchar* _tmp73_;
	ValadocHighlighterCodeToken* _tmp74_;
	ValadocHighlighterCodeToken* result;
	self = (ValadocHighlighterXmlScanner*) base;
	_tmp0_ = self->priv->token_queue;
	if (!g_queue_is_empty (_tmp0_)) {
		GQueue* _tmp1_;
		gpointer _tmp2_;
		_tmp1_ = self->priv->token_queue;
		_tmp2_ = g_queue_pop_head (_tmp1_);
		result = (ValadocHighlighterCodeToken*) _tmp2_;
		return result;
	}
	{
		const gchar* _tmp3_;
		gboolean _tmp4_ = FALSE;
		_tmp3_ = self->priv->pos;
		start = _tmp3_;
		_tmp4_ = TRUE;
		while (TRUE) {
			const gchar* _tmp7_;
			const gchar* _tmp8_;
			if (!_tmp4_) {
				const gchar* _tmp5_;
				const gchar* _tmp6_;
				_tmp5_ = self->priv->pos;
				_tmp6_ = g_utf8_next_char (_tmp5_);
				self->priv->pos = _tmp6_;
			}
			_tmp4_ = FALSE;
			_tmp7_ = self->priv->pos;
			if (!(string_get (_tmp7_, (glong) 0) != '\0')) {
				break;
			}
			_tmp8_ = self->priv->pos;
			if (string_get (_tmp8_, (glong) 0) == '&') {
				const gchar* begin = NULL;
				const gchar* _tmp9_;
				_tmp9_ = self->priv->pos;
				begin = _tmp9_;
				if (valadoc_highlighter_xml_scanner_queue_escape (self)) {
					const gchar* _tmp10_;
					const gchar* _tmp11_;
					ValadocHighlighterCodeToken* _tmp12_;
					_tmp10_ = start;
					_tmp11_ = begin;
					_tmp12_ = valadoc_highlighter_xml_scanner_dispatch (self, _tmp10_, _tmp11_);
					result = _tmp12_;
					return result;
				}
			} else {
				const gchar* _tmp13_;
				_tmp13_ = self->priv->pos;
				if (string_get (_tmp13_, (glong) 0) == '<') {
					const gchar* _tmp14_;
					_tmp14_ = self->priv->pos;
					if (string_get (_tmp14_, (glong) 1) == '/') {
						const gchar* end = NULL;
						const gchar* _tmp15_;
						_tmp15_ = self->priv->pos;
						end = _tmp15_;
						if (valadoc_highlighter_xml_scanner_queue_end_element (self)) {
							const gchar* _tmp16_;
							const gchar* _tmp17_;
							ValadocHighlighterCodeToken* _tmp18_;
							_tmp16_ = start;
							_tmp17_ = end;
							_tmp18_ = valadoc_highlighter_xml_scanner_dispatch (self, _tmp16_, _tmp17_);
							result = _tmp18_;
							return result;
						}
					} else {
						gboolean _tmp19_ = FALSE;
						gboolean _tmp20_ = FALSE;
						const gchar* _tmp21_;
						_tmp21_ = self->priv->pos;
						if (string_get (_tmp21_, (glong) 1) == '!') {
							const gchar* _tmp22_;
							_tmp22_ = self->priv->pos;
							_tmp20_ = string_get (_tmp22_, (glong) 2) == '-';
						} else {
							_tmp20_ = FALSE;
						}
						if (_tmp20_) {
							const gchar* _tmp23_;
							_tmp23_ = self->priv->pos;
							_tmp19_ = string_get (_tmp23_, (glong) 3) == '-';
						} else {
							_tmp19_ = FALSE;
						}
						if (_tmp19_) {
							const gchar* end = NULL;
							const gchar* _tmp24_;
							_tmp24_ = self->priv->pos;
							end = _tmp24_;
							if (valadoc_highlighter_xml_scanner_queue_comment (self)) {
								const gchar* _tmp25_;
								const gchar* _tmp26_;
								ValadocHighlighterCodeToken* _tmp27_;
								_tmp25_ = start;
								_tmp26_ = end;
								_tmp27_ = valadoc_highlighter_xml_scanner_dispatch (self, _tmp25_, _tmp26_);
								result = _tmp27_;
								return result;
							}
						} else {
							gboolean _tmp28_ = FALSE;
							gboolean _tmp29_ = FALSE;
							gboolean _tmp30_ = FALSE;
							gboolean _tmp31_ = FALSE;
							gboolean _tmp32_ = FALSE;
							gboolean _tmp33_ = FALSE;
							gboolean _tmp34_ = FALSE;
							const gchar* _tmp35_;
							_tmp35_ = self->priv->pos;
							if (string_get (_tmp35_, (glong) 1) == '!') {
								const gchar* _tmp36_;
								_tmp36_ = self->priv->pos;
								_tmp34_ = string_get (_tmp36_, (glong) 2) == '[';
							} else {
								_tmp34_ = FALSE;
							}
							if (_tmp34_) {
								const gchar* _tmp37_;
								_tmp37_ = self->priv->pos;
								_tmp33_ = string_get (_tmp37_, (glong) 3) == 'C';
							} else {
								_tmp33_ = FALSE;
							}
							if (_tmp33_) {
								const gchar* _tmp38_;
								_tmp38_ = self->priv->pos;
								_tmp32_ = string_get (_tmp38_, (glong) 4) == 'D';
							} else {
								_tmp32_ = FALSE;
							}
							if (_tmp32_) {
								const gchar* _tmp39_;
								_tmp39_ = self->priv->pos;
								_tmp31_ = string_get (_tmp39_, (glong) 5) == 'A';
							} else {
								_tmp31_ = FALSE;
							}
							if (_tmp31_) {
								const gchar* _tmp40_;
								_tmp40_ = self->priv->pos;
								_tmp30_ = string_get (_tmp40_, (glong) 6) == 'T';
							} else {
								_tmp30_ = FALSE;
							}
							if (_tmp30_) {
								const gchar* _tmp41_;
								_tmp41_ = self->priv->pos;
								_tmp29_ = string_get (_tmp41_, (glong) 7) == 'A';
							} else {
								_tmp29_ = FALSE;
							}
							if (_tmp29_) {
								const gchar* _tmp42_;
								_tmp42_ = self->priv->pos;
								_tmp28_ = string_get (_tmp42_, (glong) 8) == '[';
							} else {
								_tmp28_ = FALSE;
							}
							if (_tmp28_) {
								const gchar* end = NULL;
								const gchar* _tmp43_;
								const gchar* _tmp44_;
								const gchar* _tmp45_;
								GQueue* _tmp46_;
								ValadocHighlighterCodeToken* _tmp47_;
								const gchar* _tmp48_;
								const gchar* _tmp49_;
								ValadocHighlighterCodeToken* _tmp50_;
								_tmp43_ = self->priv->pos;
								end = _tmp43_;
								_tmp44_ = self->priv->pos;
								_tmp45_ = string_offset (_tmp44_, (glong) 9);
								self->priv->pos = _tmp45_;
								_tmp46_ = self->priv->token_queue;
								_tmp47_ = valadoc_highlighter_code_token_new (VALADOC_HIGHLIGHTER_CODE_TOKEN_TYPE_XML_CDATA, "<![CDATA[");
								g_queue_push_tail (_tmp46_, _tmp47_);
								_tmp48_ = start;
								_tmp49_ = end;
								_tmp50_ = valadoc_highlighter_xml_scanner_dispatch (self, _tmp48_, _tmp49_);
								result = _tmp50_;
								return result;
							} else {
								const gchar* end = NULL;
								const gchar* _tmp51_;
								const gchar* _tmp52_;
								const gchar* _tmp53_;
								_tmp51_ = self->priv->pos;
								end = _tmp51_;
								_tmp52_ = start;
								_tmp53_ = self->priv->pos;
								if (valadoc_highlighter_xml_scanner_queue_start_element (self, _tmp52_, string_get (_tmp53_, (glong) 1) == '?')) {
									const gchar* _tmp54_;
									const gchar* _tmp55_;
									ValadocHighlighterCodeToken* _tmp56_;
									_tmp54_ = start;
									_tmp55_ = end;
									_tmp56_ = valadoc_highlighter_xml_scanner_dispatch (self, _tmp54_, _tmp55_);
									result = _tmp56_;
									return result;
								} else {
									continue;
								}
							}
						}
					}
				} else {
					gboolean _tmp57_ = FALSE;
					gboolean _tmp58_ = FALSE;
					const gchar* _tmp59_;
					_tmp59_ = self->priv->pos;
					if (string_get (_tmp59_, (glong) 0) == ']') {
						const gchar* _tmp60_;
						_tmp60_ = self->priv->pos;
						_tmp58_ = string_get (_tmp60_, (glong) 1) == ']';
					} else {
						_tmp58_ = FALSE;
					}
					if (_tmp58_) {
						const gchar* _tmp61_;
						_tmp61_ = self->priv->pos;
						_tmp57_ = string_get (_tmp61_, (glong) 2) == '>';
					} else {
						_tmp57_ = FALSE;
					}
					if (_tmp57_) {
						const gchar* end = NULL;
						const gchar* _tmp62_;
						const gchar* _tmp63_;
						const gchar* _tmp64_;
						GQueue* _tmp65_;
						ValadocHighlighterCodeToken* _tmp66_;
						const gchar* _tmp67_;
						const gchar* _tmp68_;
						ValadocHighlighterCodeToken* _tmp69_;
						_tmp62_ = self->priv->pos;
						end = _tmp62_;
						_tmp63_ = self->priv->pos;
						_tmp64_ = string_offset (_tmp63_, (glong) 3);
						self->priv->pos = _tmp64_;
						_tmp65_ = self->priv->token_queue;
						_tmp66_ = valadoc_highlighter_code_token_new (VALADOC_HIGHLIGHTER_CODE_TOKEN_TYPE_XML_CDATA, "]]>");
						g_queue_push_tail (_tmp65_, _tmp66_);
						_tmp67_ = start;
						_tmp68_ = end;
						_tmp69_ = valadoc_highlighter_xml_scanner_dispatch (self, _tmp67_, _tmp68_);
						result = _tmp69_;
						return result;
					}
				}
			}
		}
	}
	_tmp70_ = self->priv->token_queue;
	_tmp71_ = valadoc_highlighter_code_token_new (VALADOC_HIGHLIGHTER_CODE_TOKEN_TYPE_EOF, "");
	g_queue_push_tail (_tmp70_, _tmp71_);
	_tmp72_ = start;
	_tmp73_ = self->priv->pos;
	_tmp74_ = valadoc_highlighter_xml_scanner_dispatch (self, _tmp72_, _tmp73_);
	result = _tmp74_;
	return result;
}

static gboolean
valadoc_highlighter_xml_scanner_queue_start_element (ValadocHighlighterXmlScanner* self,
                                                     const gchar* dispatch_start,
                                                     gboolean xml_decl)
{
	GQueue* _tmp0_;
	const gchar* element_start = NULL;
	const gchar* _tmp1_;
	gboolean _tmp6_;
	const gchar* _tmp9_;
	const gchar* _tmp10_;
	const gchar* element_end_start = NULL;
	const gchar* _tmp13_;
	gboolean _tmp14_ = FALSE;
	const gchar* _tmp32_;
	const gchar* _tmp33_;
	gboolean result;
	g_return_val_if_fail (self != NULL, FALSE);
	g_return_val_if_fail (dispatch_start != NULL, FALSE);
	_tmp0_ = self->priv->token_queue;
	_vala_assert (g_queue_is_empty (_tmp0_), "token_queue.is_empty ()");
	_tmp1_ = self->priv->pos;
	element_start = _tmp1_;
	if (xml_decl) {
		const gchar* _tmp2_;
		const gchar* _tmp3_;
		_tmp2_ = self->priv->pos;
		_tmp3_ = string_offset (_tmp2_, (glong) 2);
		self->priv->pos = _tmp3_;
	} else {
		const gchar* _tmp4_;
		const gchar* _tmp5_;
		_tmp4_ = self->priv->pos;
		_tmp5_ = string_offset (_tmp4_, (glong) 1);
		self->priv->pos = _tmp5_;
	}
	valadoc_highlighter_xml_scanner_skip_optional_spaces (&self->priv->pos);
	_tmp6_ = valadoc_highlighter_xml_scanner_skip_id (&self->priv->pos);
	if (_tmp6_ == FALSE) {
		GQueue* _tmp7_;
		const gchar* _tmp8_;
		_tmp7_ = self->priv->token_queue;
		g_queue_clear (_tmp7_);
		_tmp8_ = element_start;
		self->priv->pos = _tmp8_;
		result = FALSE;
		return result;
	}
	valadoc_highlighter_xml_scanner_skip_optional_spaces (&self->priv->pos);
	_tmp9_ = element_start;
	_tmp10_ = self->priv->pos;
	valadoc_highlighter_xml_scanner_queue_token (self, _tmp9_, _tmp10_, VALADOC_HIGHLIGHTER_CODE_TOKEN_TYPE_XML_ELEMENT);
	if (valadoc_highlighter_xml_scanner_queue_attributes (self) == FALSE) {
		GQueue* _tmp11_;
		const gchar* _tmp12_;
		_tmp11_ = self->priv->token_queue;
		g_queue_clear (_tmp11_);
		_tmp12_ = element_start;
		self->priv->pos = _tmp12_;
		result = FALSE;
		return result;
	}
	_tmp13_ = self->priv->pos;
	element_end_start = _tmp13_;
	if (!xml_decl) {
		const gchar* _tmp15_;
		_tmp15_ = self->priv->pos;
		_tmp14_ = string_get (_tmp15_, (glong) 0) == '>';
	} else {
		_tmp14_ = FALSE;
	}
	if (_tmp14_) {
		const gchar* _tmp16_;
		const gchar* _tmp17_;
		_tmp16_ = self->priv->pos;
		_tmp17_ = string_offset (_tmp16_, (glong) 1);
		self->priv->pos = _tmp17_;
	} else {
		gboolean _tmp18_ = FALSE;
		gboolean _tmp19_ = FALSE;
		if (!xml_decl) {
			const gchar* _tmp20_;
			_tmp20_ = self->priv->pos;
			_tmp19_ = string_get (_tmp20_, (glong) 0) == '/';
		} else {
			_tmp19_ = FALSE;
		}
		if (_tmp19_) {
			const gchar* _tmp21_;
			_tmp21_ = self->priv->pos;
			_tmp18_ = string_get (_tmp21_, (glong) 1) == '>';
		} else {
			_tmp18_ = FALSE;
		}
		if (_tmp18_) {
			const gchar* _tmp22_;
			const gchar* _tmp23_;
			_tmp22_ = self->priv->pos;
			_tmp23_ = string_offset (_tmp22_, (glong) 2);
			self->priv->pos = _tmp23_;
		} else {
			gboolean _tmp24_ = FALSE;
			gboolean _tmp25_ = FALSE;
			if (xml_decl) {
				const gchar* _tmp26_;
				_tmp26_ = self->priv->pos;
				_tmp25_ = string_get (_tmp26_, (glong) 0) == '?';
			} else {
				_tmp25_ = FALSE;
			}
			if (_tmp25_) {
				const gchar* _tmp27_;
				_tmp27_ = self->priv->pos;
				_tmp24_ = string_get (_tmp27_, (glong) 1) == '>';
			} else {
				_tmp24_ = FALSE;
			}
			if (_tmp24_) {
				const gchar* _tmp28_;
				const gchar* _tmp29_;
				_tmp28_ = self->priv->pos;
				_tmp29_ = string_offset (_tmp28_, (glong) 2);
				self->priv->pos = _tmp29_;
			} else {
				GQueue* _tmp30_;
				const gchar* _tmp31_;
				_tmp30_ = self->priv->token_queue;
				g_queue_clear (_tmp30_);
				_tmp31_ = element_start;
				self->priv->pos = _tmp31_;
				result = FALSE;
				return result;
			}
		}
	}
	_tmp32_ = element_end_start;
	_tmp33_ = self->priv->pos;
	valadoc_highlighter_xml_scanner_queue_token (self, _tmp32_, _tmp33_, VALADOC_HIGHLIGHTER_CODE_TOKEN_TYPE_XML_ELEMENT);
	result = TRUE;
	return result;
}

static gboolean
valadoc_highlighter_xml_scanner_queue_attributes (ValadocHighlighterXmlScanner* self)
{
	gboolean result;
	g_return_val_if_fail (self != NULL, FALSE);
	while (TRUE) {
		const gchar* _tmp0_;
		const gchar* begin = NULL;
		const gchar* _tmp1_;
		gboolean _tmp2_;
		const gchar* _tmp3_;
		const gchar* _tmp6_;
		const gchar* _tmp7_;
		const gchar* _tmp8_;
		const gchar* _tmp9_;
		const gchar* _tmp17_;
		const gchar* _tmp20_;
		const gchar* _tmp21_;
		_tmp0_ = self->priv->pos;
		if (!valadoc_highlighter_xml_scanner_is_id_char (string_get (_tmp0_, (glong) 0))) {
			break;
		}
		_tmp1_ = self->priv->pos;
		begin = _tmp1_;
		_tmp2_ = valadoc_highlighter_xml_scanner_skip_id (&self->priv->pos);
		if (_tmp2_ == FALSE) {
			result = FALSE;
			return result;
		}
		valadoc_highlighter_xml_scanner_skip_optional_spaces (&self->priv->pos);
		_tmp3_ = self->priv->pos;
		if (string_get (_tmp3_, (glong) 0) == '=') {
			const gchar* _tmp4_;
			const gchar* _tmp5_;
			_tmp4_ = self->priv->pos;
			_tmp5_ = string_offset (_tmp4_, (glong) 1);
			self->priv->pos = _tmp5_;
		} else {
			result = FALSE;
			return result;
		}
		valadoc_highlighter_xml_scanner_skip_optional_spaces (&self->priv->pos);
		_tmp6_ = begin;
		_tmp7_ = self->priv->pos;
		valadoc_highlighter_xml_scanner_queue_token (self, _tmp6_, _tmp7_, VALADOC_HIGHLIGHTER_CODE_TOKEN_TYPE_XML_ATTRIBUTE);
		_tmp8_ = self->priv->pos;
		begin = _tmp8_;
		_tmp9_ = self->priv->pos;
		if (string_get (_tmp9_, (glong) 0) == '"') {
			const gchar* _tmp10_;
			const gchar* _tmp11_;
			_tmp10_ = self->priv->pos;
			_tmp11_ = string_offset (_tmp10_, (glong) 1);
			self->priv->pos = _tmp11_;
		} else {
			result = FALSE;
			return result;
		}
		while (TRUE) {
			gboolean _tmp12_ = FALSE;
			const gchar* _tmp13_;
			const gchar* _tmp15_;
			const gchar* _tmp16_;
			_tmp13_ = self->priv->pos;
			if (string_get (_tmp13_, (glong) 0) != '"') {
				const gchar* _tmp14_;
				_tmp14_ = self->priv->pos;
				_tmp12_ = string_get (_tmp14_, (glong) 0) != '\0';
			} else {
				_tmp12_ = FALSE;
			}
			if (!_tmp12_) {
				break;
			}
			_tmp15_ = self->priv->pos;
			_tmp16_ = string_offset (_tmp15_, (glong) 1);
			self->priv->pos = _tmp16_;
		}
		_tmp17_ = self->priv->pos;
		if (string_get (_tmp17_, (glong) 0) == '"') {
			const gchar* _tmp18_;
			const gchar* _tmp19_;
			_tmp18_ = self->priv->pos;
			_tmp19_ = string_offset (_tmp18_, (glong) 1);
			self->priv->pos = _tmp19_;
		} else {
			result = FALSE;
			return result;
		}
		valadoc_highlighter_xml_scanner_skip_optional_spaces (&self->priv->pos);
		_tmp20_ = begin;
		_tmp21_ = self->priv->pos;
		valadoc_highlighter_xml_scanner_queue_token (self, _tmp20_, _tmp21_, VALADOC_HIGHLIGHTER_CODE_TOKEN_TYPE_XML_ATTRIBUTE_VALUE);
	}
	result = TRUE;
	return result;
}

static gboolean
valadoc_highlighter_xml_scanner_queue_end_element (ValadocHighlighterXmlScanner* self)
{
	const gchar* start = NULL;
	const gchar* _tmp0_;
	const gchar* _tmp1_;
	const gchar* _tmp2_;
	gboolean _tmp3_;
	const gchar* _tmp5_;
	const gchar* _tmp9_;
	const gchar* _tmp10_;
	gboolean result;
	g_return_val_if_fail (self != NULL, FALSE);
	_tmp0_ = self->priv->pos;
	start = _tmp0_;
	_tmp1_ = self->priv->pos;
	_tmp2_ = string_offset (_tmp1_, (glong) 2);
	self->priv->pos = _tmp2_;
	valadoc_highlighter_xml_scanner_skip_optional_spaces (&self->priv->pos);
	_tmp3_ = valadoc_highlighter_xml_scanner_skip_id (&self->priv->pos);
	if (_tmp3_ == FALSE) {
		const gchar* _tmp4_;
		_tmp4_ = start;
		self->priv->pos = _tmp4_;
		result = FALSE;
		return result;
	}
	valadoc_highlighter_xml_scanner_skip_optional_spaces (&self->priv->pos);
	_tmp5_ = self->priv->pos;
	if (string_get (_tmp5_, (glong) 0) == '>') {
		const gchar* _tmp6_;
		const gchar* _tmp7_;
		_tmp6_ = self->priv->pos;
		_tmp7_ = string_offset (_tmp6_, (glong) 1);
		self->priv->pos = _tmp7_;
	} else {
		const gchar* _tmp8_;
		_tmp8_ = start;
		self->priv->pos = _tmp8_;
		result = FALSE;
		return result;
	}
	_tmp9_ = start;
	_tmp10_ = self->priv->pos;
	valadoc_highlighter_xml_scanner_queue_token (self, _tmp9_, _tmp10_, VALADOC_HIGHLIGHTER_CODE_TOKEN_TYPE_XML_ELEMENT);
	result = TRUE;
	return result;
}

static gboolean
valadoc_highlighter_xml_scanner_queue_escape (ValadocHighlighterXmlScanner* self)
{
	const gchar* start = NULL;
	const gchar* _tmp0_;
	const gchar* _tmp1_;
	const gchar* _tmp2_;
	gboolean _tmp3_;
	const gchar* _tmp5_;
	const gchar* _tmp9_;
	const gchar* _tmp10_;
	gboolean result;
	g_return_val_if_fail (self != NULL, FALSE);
	_tmp0_ = self->priv->pos;
	start = _tmp0_;
	_tmp1_ = self->priv->pos;
	_tmp2_ = string_offset (_tmp1_, (glong) 1);
	self->priv->pos = _tmp2_;
	_tmp3_ = valadoc_highlighter_xml_scanner_skip_id (&self->priv->pos);
	if (_tmp3_ == FALSE) {
		const gchar* _tmp4_;
		_tmp4_ = start;
		self->priv->pos = _tmp4_;
		result = FALSE;
		return result;
	}
	_tmp5_ = self->priv->pos;
	if (string_get (_tmp5_, (glong) 0) == ';') {
		const gchar* _tmp6_;
		const gchar* _tmp7_;
		_tmp6_ = self->priv->pos;
		_tmp7_ = string_offset (_tmp6_, (glong) 1);
		self->priv->pos = _tmp7_;
	} else {
		const gchar* _tmp8_;
		_tmp8_ = start;
		self->priv->pos = _tmp8_;
		result = FALSE;
		return result;
	}
	_tmp9_ = start;
	_tmp10_ = self->priv->pos;
	valadoc_highlighter_xml_scanner_queue_token (self, _tmp9_, _tmp10_, VALADOC_HIGHLIGHTER_CODE_TOKEN_TYPE_XML_ESCAPE);
	result = TRUE;
	return result;
}

static gboolean
valadoc_highlighter_xml_scanner_queue_comment (ValadocHighlighterXmlScanner* self)
{
	const gchar* start = NULL;
	const gchar* _tmp0_;
	const gchar* _tmp1_;
	const gchar* _tmp2_;
	const gchar* _tmp8_;
	const gchar* _tmp12_;
	const gchar* _tmp13_;
	gboolean result;
	g_return_val_if_fail (self != NULL, FALSE);
	_tmp0_ = self->priv->pos;
	start = _tmp0_;
	_tmp1_ = self->priv->pos;
	_tmp2_ = string_offset (_tmp1_, (glong) 4);
	self->priv->pos = _tmp2_;
	while (TRUE) {
		gboolean _tmp3_ = FALSE;
		const gchar* _tmp4_;
		const gchar* _tmp6_;
		const gchar* _tmp7_;
		_tmp4_ = self->priv->pos;
		if (string_get (_tmp4_, (glong) 0) != '>') {
			const gchar* _tmp5_;
			_tmp5_ = self->priv->pos;
			_tmp3_ = string_get (_tmp5_, (glong) 0) != '\0';
		} else {
			_tmp3_ = FALSE;
		}
		if (!_tmp3_) {
			break;
		}
		_tmp6_ = self->priv->pos;
		_tmp7_ = string_offset (_tmp6_, (glong) 1);
		self->priv->pos = _tmp7_;
	}
	_tmp8_ = self->priv->pos;
	if (string_get (_tmp8_, (glong) 0) == '>') {
		const gchar* _tmp9_;
		const gchar* _tmp10_;
		_tmp9_ = self->priv->pos;
		_tmp10_ = string_offset (_tmp9_, (glong) 1);
		self->priv->pos = _tmp10_;
	} else {
		const gchar* _tmp11_;
		_tmp11_ = start;
		self->priv->pos = _tmp11_;
		result = FALSE;
		return result;
	}
	_tmp12_ = start;
	_tmp13_ = self->priv->pos;
	valadoc_highlighter_xml_scanner_queue_token (self, _tmp12_, _tmp13_, VALADOC_HIGHLIGHTER_CODE_TOKEN_TYPE_XML_COMMENT);
	result = TRUE;
	return result;
}

static gboolean
valadoc_highlighter_xml_scanner_skip_id (const gchar** pos)
{
	gboolean has_next_segment = FALSE;
	gboolean has_id = FALSE;
	gboolean result;
	g_return_val_if_fail (*pos != NULL, FALSE);
	has_next_segment = TRUE;
	has_id = FALSE;
	while (TRUE) {
		gboolean _tmp1_ = FALSE;
		if (!has_next_segment) {
			break;
		}
		has_id = FALSE;
		while (TRUE) {
			const gchar* _tmp0_;
			if (!valadoc_highlighter_xml_scanner_is_id_char (string_get (*pos, (glong) 0))) {
				break;
			}
			_tmp0_ = string_offset (*pos, (glong) 1);
			*pos = _tmp0_;
			has_id = TRUE;
		}
		if (string_get (*pos, (glong) 0) == ':') {
			_tmp1_ = has_id;
		} else {
			_tmp1_ = FALSE;
		}
		if (_tmp1_) {
			const gchar* _tmp2_;
			has_next_segment = TRUE;
			_tmp2_ = string_offset (*pos, (glong) 1);
			*pos = _tmp2_;
		} else {
			has_next_segment = FALSE;
		}
	}
	result = has_id;
	return result;
}

static gboolean
valadoc_highlighter_xml_scanner_skip_optional_spaces (const gchar** pos)
{
	gboolean skipped = FALSE;
	gboolean result;
	g_return_val_if_fail (*pos != NULL, FALSE);
	skipped = FALSE;
	while (TRUE) {
		const gchar* _tmp0_;
		if (!g_ascii_isspace (string_get (*pos, (glong) 0))) {
			break;
		}
		_tmp0_ = string_offset (*pos, (glong) 1);
		*pos = _tmp0_;
		skipped = TRUE;
	}
	result = skipped;
	return result;
}

static glong
string_pointer_to_offset (const gchar* self,
                          const gchar* pos)
{
	glong result;
	g_return_val_if_fail (self != NULL, 0L);
	g_return_val_if_fail (pos != NULL, 0L);
	result = (glong) (((gchar*) pos) - ((gchar*) self));
	return result;
}

static glong
string_strnlen (gchar* str,
                glong maxlen)
{
	gchar* end = NULL;
	gchar* _tmp0_;
	gchar* _tmp1_;
	glong result;
	_tmp0_ = memchr (str, 0, (gsize) maxlen);
	end = _tmp0_;
	_tmp1_ = end;
	if (_tmp1_ == NULL) {
		result = maxlen;
		return result;
	} else {
		gchar* _tmp2_;
		_tmp2_ = end;
		result = (glong) (_tmp2_ - str);
		return result;
	}
}

static gchar*
string_substring (const gchar* self,
                  glong offset,
                  glong len)
{
	glong string_length = 0L;
	gboolean _tmp0_ = FALSE;
	gchar* _tmp3_;
	gchar* result;
	g_return_val_if_fail (self != NULL, NULL);
	if (offset >= ((glong) 0)) {
		_tmp0_ = len >= ((glong) 0);
	} else {
		_tmp0_ = FALSE;
	}
	if (_tmp0_) {
		string_length = string_strnlen ((gchar*) self, offset + len);
	} else {
		gint _tmp1_;
		gint _tmp2_;
		_tmp1_ = strlen (self);
		_tmp2_ = _tmp1_;
		string_length = (glong) _tmp2_;
	}
	if (offset < ((glong) 0)) {
		offset = string_length + offset;
		g_return_val_if_fail (offset >= ((glong) 0), NULL);
	} else {
		g_return_val_if_fail (offset <= string_length, NULL);
	}
	if (len < ((glong) 0)) {
		len = string_length - offset;
	}
	g_return_val_if_fail ((offset + len) <= string_length, NULL);
	_tmp3_ = g_strndup (((gchar*) self) + offset, (gsize) len);
	result = _tmp3_;
	return result;
}

static ValadocHighlighterCodeToken*
valadoc_highlighter_xml_scanner_dispatch (ValadocHighlighterXmlScanner* self,
                                          const gchar* start,
                                          const gchar* end)
{
	GQueue* _tmp0_;
	glong length = 0L;
	gchar* content = NULL;
	gchar* _tmp3_;
	const gchar* _tmp4_;
	ValadocHighlighterCodeToken* _tmp5_;
	ValadocHighlighterCodeToken* result;
	g_return_val_if_fail (self != NULL, NULL);
	g_return_val_if_fail (start != NULL, NULL);
	g_return_val_if_fail (end != NULL, NULL);
	_tmp0_ = self->priv->token_queue;
	_vala_assert (g_queue_is_empty (_tmp0_) == FALSE, "token_queue.is_empty () == false");
	if (((gchar*) start) == ((gchar*) end)) {
		GQueue* _tmp1_;
		gpointer _tmp2_;
		_tmp1_ = self->priv->token_queue;
		_tmp2_ = g_queue_pop_head (_tmp1_);
		result = (ValadocHighlighterCodeToken*) _tmp2_;
		return result;
	}
	length = string_pointer_to_offset (start, end);
	_tmp3_ = string_substring (start, (glong) 0, length);
	content = _tmp3_;
	_tmp4_ = content;
	_tmp5_ = valadoc_highlighter_code_token_new (VALADOC_HIGHLIGHTER_CODE_TOKEN_TYPE_PLAIN, _tmp4_);
	result = _tmp5_;
	_g_free0 (content);
	return result;
}

static void
valadoc_highlighter_xml_scanner_queue_token (ValadocHighlighterXmlScanner* self,
                                             const gchar* start,
                                             const gchar* end,
                                             ValadocHighlighterCodeTokenType token_type)
{
	glong length = 0L;
	gchar* content = NULL;
	gchar* _tmp0_;
	GQueue* _tmp1_;
	ValadocHighlighterCodeToken* _tmp2_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (start != NULL);
	g_return_if_fail (end != NULL);
	length = string_pointer_to_offset (start, end);
	_tmp0_ = string_substring (start, (glong) 0, length);
	content = _tmp0_;
	_tmp1_ = self->priv->token_queue;
	_tmp2_ = valadoc_highlighter_code_token_new (token_type, content);
	g_queue_push_tail (_tmp1_, _tmp2_);
	_g_free0 (content);
}

static inline gboolean
valadoc_highlighter_xml_scanner_is_id_char (gchar c)
{
	gboolean _tmp0_ = FALSE;
	gboolean _tmp1_ = FALSE;
	gboolean result;
	if (g_ascii_isalnum (c)) {
		_tmp1_ = TRUE;
	} else {
		_tmp1_ = c == '_';
	}
	if (_tmp1_) {
		_tmp0_ = TRUE;
	} else {
		_tmp0_ = c == '-';
	}
	result = _tmp0_;
	return result;
}

 G_GNUC_INTERNAL gboolean
valadoc_highlighter_xml_scanner_is_xml (const gchar* source)
{
	const gchar* pos = NULL;
	const gchar* _tmp0_;
	gboolean result;
	g_return_val_if_fail (source != NULL, FALSE);
	pos = source;
	valadoc_highlighter_xml_scanner_skip_optional_spaces (&pos);
	_tmp0_ = pos;
	if (string_get (_tmp0_, (glong) 0) == '<') {
		const gchar* _tmp1_;
		const gchar* _tmp2_;
		gboolean proc_instr = FALSE;
		const gchar* _tmp3_;
		const gchar* _tmp4_;
		const gchar* _tmp5_;
		gboolean _tmp8_;
		gboolean _tmp26_ = FALSE;
		gboolean _tmp27_ = FALSE;
		gboolean _tmp30_ = FALSE;
		_tmp1_ = pos;
		if (g_str_has_prefix (_tmp1_, "<!--")) {
			result = TRUE;
			return result;
		}
		_tmp2_ = pos;
		if (g_str_has_prefix (_tmp2_, "<![CDATA[")) {
			result = TRUE;
			return result;
		}
		proc_instr = FALSE;
		_tmp3_ = pos;
		_tmp4_ = string_offset (_tmp3_, (glong) 1);
		pos = _tmp4_;
		_tmp5_ = pos;
		if (string_get (_tmp5_, (glong) 0) == '?') {
			const gchar* _tmp6_;
			const gchar* _tmp7_;
			_tmp6_ = pos;
			_tmp7_ = string_offset (_tmp6_, (glong) 1);
			pos = _tmp7_;
			proc_instr = TRUE;
		}
		_tmp8_ = valadoc_highlighter_xml_scanner_skip_id (&pos);
		if (_tmp8_ == FALSE) {
			result = FALSE;
			return result;
		}
		valadoc_highlighter_xml_scanner_skip_optional_spaces (&pos);
		while (TRUE) {
			gboolean _tmp9_;
			const gchar* _tmp10_;
			const gchar* _tmp13_;
			const gchar* _tmp23_;
			_tmp9_ = valadoc_highlighter_xml_scanner_skip_id (&pos);
			if (!_tmp9_) {
				break;
			}
			_tmp10_ = pos;
			if (string_get (_tmp10_, (glong) 0) == '=') {
				const gchar* _tmp11_;
				const gchar* _tmp12_;
				_tmp11_ = pos;
				_tmp12_ = string_offset (_tmp11_, (glong) 1);
				pos = _tmp12_;
			} else {
				result = FALSE;
				return result;
			}
			valadoc_highlighter_xml_scanner_skip_optional_spaces (&pos);
			_tmp13_ = pos;
			if (string_get (_tmp13_, (glong) 0) == '"') {
				const gchar* _tmp14_;
				const gchar* _tmp15_;
				_tmp14_ = pos;
				_tmp15_ = string_offset (_tmp14_, (glong) 1);
				pos = _tmp15_;
			} else {
				result = FALSE;
				return result;
			}
			while (TRUE) {
				gboolean _tmp16_ = FALSE;
				gboolean _tmp17_ = FALSE;
				const gchar* _tmp18_;
				const gchar* _tmp21_;
				const gchar* _tmp22_;
				_tmp18_ = pos;
				if (string_get (_tmp18_, (glong) 0) != '\0') {
					const gchar* _tmp19_;
					_tmp19_ = pos;
					_tmp17_ = string_get (_tmp19_, (glong) 0) != '\n';
				} else {
					_tmp17_ = FALSE;
				}
				if (_tmp17_) {
					const gchar* _tmp20_;
					_tmp20_ = pos;
					_tmp16_ = string_get (_tmp20_, (glong) 0) != '"';
				} else {
					_tmp16_ = FALSE;
				}
				if (!_tmp16_) {
					break;
				}
				_tmp21_ = pos;
				_tmp22_ = string_offset (_tmp21_, (glong) 1);
				pos = _tmp22_;
			}
			_tmp23_ = pos;
			if (string_get (_tmp23_, (glong) 0) == '"') {
				const gchar* _tmp24_;
				const gchar* _tmp25_;
				_tmp24_ = pos;
				_tmp25_ = string_offset (_tmp24_, (glong) 1);
				pos = _tmp25_;
			} else {
				result = FALSE;
				return result;
			}
			valadoc_highlighter_xml_scanner_skip_optional_spaces (&pos);
		}
		if (proc_instr) {
			const gchar* _tmp28_;
			_tmp28_ = pos;
			_tmp27_ = string_get (_tmp28_, (glong) 0) == '?';
		} else {
			_tmp27_ = FALSE;
		}
		if (_tmp27_) {
			const gchar* _tmp29_;
			_tmp29_ = pos;
			_tmp26_ = string_get (_tmp29_, (glong) 1) == '>';
		} else {
			_tmp26_ = FALSE;
		}
		if (_tmp26_) {
			result = TRUE;
			return result;
		}
		if (!proc_instr) {
			gboolean _tmp31_ = FALSE;
			const gchar* _tmp32_;
			_tmp32_ = pos;
			if (string_get (_tmp32_, (glong) 0) == '>') {
				_tmp31_ = TRUE;
			} else {
				gboolean _tmp33_ = FALSE;
				const gchar* _tmp34_;
				_tmp34_ = pos;
				if (string_get (_tmp34_, (glong) 0) == '/') {
					const gchar* _tmp35_;
					_tmp35_ = pos;
					_tmp33_ = string_get (_tmp35_, (glong) 1) == '>';
				} else {
					_tmp33_ = FALSE;
				}
				_tmp31_ = _tmp33_;
			}
			_tmp30_ = _tmp31_;
		} else {
			_tmp30_ = FALSE;
		}
		if (_tmp30_) {
			result = TRUE;
			return result;
		}
		result = FALSE;
		return result;
	} else {
		result = FALSE;
		return result;
	}
}

static void
valadoc_highlighter_xml_scanner_class_init (ValadocHighlighterXmlScannerClass * klass,
                                            gpointer klass_data)
{
	valadoc_highlighter_xml_scanner_parent_class = g_type_class_peek_parent (klass);
	g_type_class_adjust_private_offset (klass, &ValadocHighlighterXmlScanner_private_offset);
	G_OBJECT_CLASS (klass)->finalize = valadoc_highlighter_xml_scanner_finalize;
}

static void
valadoc_highlighter_xml_scanner_valadoc_highlighter_scanner_interface_init (ValadocHighlighterScannerIface * iface,
                                                                            gpointer iface_data)
{
	valadoc_highlighter_xml_scanner_valadoc_highlighter_scanner_parent_iface = g_type_interface_peek_parent (iface);
	iface->next = (ValadocHighlighterCodeToken* (*) (ValadocHighlighterScanner*)) valadoc_highlighter_xml_scanner_real_next;
}

static void
valadoc_highlighter_xml_scanner_instance_init (ValadocHighlighterXmlScanner * self,
                                               gpointer klass)
{
	GQueue* _tmp0_;
	self->priv = valadoc_highlighter_xml_scanner_get_instance_private (self);
	_tmp0_ = g_queue_new ();
	self->priv->token_queue = _tmp0_;
}

static void
valadoc_highlighter_xml_scanner_finalize (GObject * obj)
{
	ValadocHighlighterXmlScanner * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, VALADOC_HIGHLIGHTER_TYPE_XML_SCANNER, ValadocHighlighterXmlScanner);
	(self->priv->token_queue == NULL) ? NULL : (self->priv->token_queue = (_g_queue_free__valadoc_highlighter_code_token_unref0_ (self->priv->token_queue), NULL));
	G_OBJECT_CLASS (valadoc_highlighter_xml_scanner_parent_class)->finalize (obj);
}

/**
 * A cheap scanner used to highlight XML.
 */
static GType
valadoc_highlighter_xml_scanner_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (ValadocHighlighterXmlScannerClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) valadoc_highlighter_xml_scanner_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (ValadocHighlighterXmlScanner), 0, (GInstanceInitFunc) valadoc_highlighter_xml_scanner_instance_init, NULL };
	static const GInterfaceInfo valadoc_highlighter_scanner_info = { (GInterfaceInitFunc) valadoc_highlighter_xml_scanner_valadoc_highlighter_scanner_interface_init, (GInterfaceFinalizeFunc) NULL, NULL};
	GType valadoc_highlighter_xml_scanner_type_id;
	valadoc_highlighter_xml_scanner_type_id = g_type_register_static (G_TYPE_OBJECT, "ValadocHighlighterXmlScanner", &g_define_type_info, 0);
	g_type_add_interface_static (valadoc_highlighter_xml_scanner_type_id, VALADOC_HIGHLIGHTER_TYPE_SCANNER, &valadoc_highlighter_scanner_info);
	ValadocHighlighterXmlScanner_private_offset = g_type_add_instance_private (valadoc_highlighter_xml_scanner_type_id, sizeof (ValadocHighlighterXmlScannerPrivate));
	return valadoc_highlighter_xml_scanner_type_id;
}

GType
valadoc_highlighter_xml_scanner_get_type (void)
{
	static volatile gsize valadoc_highlighter_xml_scanner_type_id__once = 0;
	if (g_once_init_enter (&valadoc_highlighter_xml_scanner_type_id__once)) {
		GType valadoc_highlighter_xml_scanner_type_id;
		valadoc_highlighter_xml_scanner_type_id = valadoc_highlighter_xml_scanner_get_type_once ();
		g_once_init_leave (&valadoc_highlighter_xml_scanner_type_id__once, valadoc_highlighter_xml_scanner_type_id);
	}
	return valadoc_highlighter_xml_scanner_type_id__once;
}

