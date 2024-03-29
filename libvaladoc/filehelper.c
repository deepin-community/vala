/* filehelper.c generated by valac, the Vala compiler
 * generated from filehelper.vala, do not modify */

/* filehelper.vala
 *
 * Copyright (C) 2008-2009 Florian Brosch
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
 * 	Brosch Florian <flo.brosch@gmail.com>
 */

#include "valadoc.h"
#include <stdlib.h>
#include <string.h>
#include <glib.h>
#include <stdio.h>
#include <glib/gstdio.h>

#define _fclose0(var) ((var == NULL) ? NULL : (var = (fclose (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_dir_close0(var) ((var == NULL) ? NULL : (var = (g_dir_close (var), NULL)))

/**
 * Makes a copy of the file src to dest.
 *
 * @param src the file to copy
 * @param dest the destination path
 */
gboolean
valadoc_copy_file (const gchar* src,
                   const gchar* dest)
{
	FILE* fsrc = NULL;
	FILE* _tmp0_;
	FILE* _tmp1_;
	FILE* fdest = NULL;
	FILE* _tmp2_;
	FILE* _tmp3_;
	gboolean result;
	g_return_val_if_fail (src != NULL, FALSE);
	g_return_val_if_fail (dest != NULL, FALSE);
	_tmp0_ = g_fopen (src, "rb");
	fsrc = _tmp0_;
	_tmp1_ = fsrc;
	if (_tmp1_ == NULL) {
		result = FALSE;
		_fclose0 (fsrc);
		return result;
	}
	_tmp2_ = g_fopen (dest, "wb");
	fdest = _tmp2_;
	_tmp3_ = fdest;
	if (_tmp3_ == NULL) {
		result = FALSE;
		_fclose0 (fdest);
		_fclose0 (fsrc);
		return result;
	}
	{
		gint c = 0;
		FILE* _tmp4_;
		_tmp4_ = fsrc;
		c = fgetc (_tmp4_);
		{
			gboolean _tmp5_ = FALSE;
			_tmp5_ = TRUE;
			while (TRUE) {
				FILE* _tmp7_;
				FILE* _tmp8_;
				if (!_tmp5_) {
					FILE* _tmp6_;
					_tmp6_ = fsrc;
					c = fgetc (_tmp6_);
				}
				_tmp5_ = FALSE;
				_tmp7_ = fsrc;
				if (!(!feof (_tmp7_))) {
					break;
				}
				_tmp8_ = fdest;
				fputc ((gchar) c, _tmp8_);
			}
		}
	}
	result = TRUE;
	_fclose0 (fdest);
	_fclose0 (fsrc);
	return result;
}

/**
 * Makes a copy of the directory src to dest.
 *
 * @param src the directory to copy
 * @param dest the destination path
 */
gboolean
valadoc_copy_directory (const gchar* src,
                        const gchar* dest)
{
	GError* _inner_error0_ = NULL;
	gboolean result;
	g_return_val_if_fail (src != NULL, FALSE);
	g_return_val_if_fail (dest != NULL, FALSE);
	{
		GDir* dir = NULL;
		GDir* _tmp0_;
		_tmp0_ = g_dir_open (src, (guint) 0, &_inner_error0_);
		dir = _tmp0_;
		if (G_UNLIKELY (_inner_error0_ != NULL)) {
			gboolean _tmp1_ = FALSE;
			if (_inner_error0_->domain == G_FILE_ERROR) {
				goto __catch0_g_file_error;
			}
			g_critical ("file %s: line %d: unexpected error: %s (%s, %d)", __FILE__, __LINE__, _inner_error0_->message, g_quark_to_string (_inner_error0_->domain), _inner_error0_->code);
			g_clear_error (&_inner_error0_);
			return _tmp1_;
		}
		{
			gchar* file = NULL;
			const gchar* _tmp2_;
			gchar* _tmp3_;
			_tmp2_ = g_dir_read_name (dir);
			_tmp3_ = g_strdup (_tmp2_);
			file = _tmp3_;
			{
				gboolean _tmp4_ = FALSE;
				_tmp4_ = TRUE;
				while (TRUE) {
					const gchar* _tmp7_;
					gchar* src_file_path = NULL;
					const gchar* _tmp8_;
					gchar* _tmp9_;
					gchar* dest_file_path = NULL;
					const gchar* _tmp10_;
					gchar* _tmp11_;
					const gchar* _tmp12_;
					if (!_tmp4_) {
						const gchar* _tmp5_;
						gchar* _tmp6_;
						_tmp5_ = g_dir_read_name (dir);
						_tmp6_ = g_strdup (_tmp5_);
						_g_free0 (file);
						file = _tmp6_;
					}
					_tmp4_ = FALSE;
					_tmp7_ = file;
					if (!(_tmp7_ != NULL)) {
						break;
					}
					_tmp8_ = file;
					_tmp9_ = g_build_filename (src, _tmp8_, NULL);
					src_file_path = _tmp9_;
					_tmp10_ = file;
					_tmp11_ = g_build_filename (dest, _tmp10_, NULL);
					dest_file_path = _tmp11_;
					_tmp12_ = src_file_path;
					if (g_file_test (_tmp12_, G_FILE_TEST_IS_DIR)) {
						const gchar* _tmp13_;
						const gchar* _tmp14_;
						const gchar* _tmp15_;
						_tmp13_ = dest_file_path;
						g_mkdir (_tmp13_, 0755);
						_tmp14_ = src_file_path;
						_tmp15_ = dest_file_path;
						if (!valadoc_copy_directory (_tmp14_, _tmp15_)) {
							result = FALSE;
							_g_free0 (dest_file_path);
							_g_free0 (src_file_path);
							_g_free0 (file);
							_g_dir_close0 (dir);
							return result;
						}
					} else {
						const gchar* _tmp16_;
						const gchar* _tmp17_;
						_tmp16_ = src_file_path;
						_tmp17_ = dest_file_path;
						if (!valadoc_copy_file (_tmp16_, _tmp17_)) {
							result = FALSE;
							_g_free0 (dest_file_path);
							_g_free0 (src_file_path);
							_g_free0 (file);
							_g_dir_close0 (dir);
							return result;
						}
					}
					_g_free0 (dest_file_path);
					_g_free0 (src_file_path);
				}
			}
			_g_free0 (file);
		}
		_g_dir_close0 (dir);
	}
	goto __finally0;
	__catch0_g_file_error:
	{
		g_clear_error (&_inner_error0_);
		result = FALSE;
		return result;
	}
	__finally0:
	if (G_UNLIKELY (_inner_error0_ != NULL)) {
		gboolean _tmp18_ = FALSE;
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error0_->message, g_quark_to_string (_inner_error0_->domain), _inner_error0_->code);
		g_clear_error (&_inner_error0_);
		return _tmp18_;
	}
	result = TRUE;
	return result;
}

/**
 * A recursive directory delete function
 *
 * @param rpath the directory to remove
 */
gboolean
valadoc_remove_directory (const gchar* rpath)
{
	GError* _inner_error0_ = NULL;
	gboolean result;
	g_return_val_if_fail (rpath != NULL, FALSE);
	{
		GDir* dir = NULL;
		GDir* _tmp0_;
		GDir* _tmp2_;
		_tmp0_ = g_dir_open (rpath, (guint) 0, &_inner_error0_);
		dir = _tmp0_;
		if (G_UNLIKELY (_inner_error0_ != NULL)) {
			gboolean _tmp1_ = FALSE;
			if (_inner_error0_->domain == G_FILE_ERROR) {
				goto __catch0_g_file_error;
			}
			g_critical ("file %s: line %d: unexpected error: %s (%s, %d)", __FILE__, __LINE__, _inner_error0_->message, g_quark_to_string (_inner_error0_->domain), _inner_error0_->code);
			g_clear_error (&_inner_error0_);
			return _tmp1_;
		}
		_tmp2_ = dir;
		if (_tmp2_ == NULL) {
			result = FALSE;
			_g_dir_close0 (dir);
			return result;
		}
		{
			const gchar* entry = NULL;
			GDir* _tmp3_;
			const gchar* _tmp4_;
			_tmp3_ = dir;
			_tmp4_ = g_dir_read_name (_tmp3_);
			entry = _tmp4_;
			{
				gboolean _tmp5_ = FALSE;
				_tmp5_ = TRUE;
				while (TRUE) {
					const gchar* _tmp8_;
					gchar* path = NULL;
					const gchar* _tmp9_;
					gchar* _tmp10_;
					gboolean is_dir = FALSE;
					const gchar* _tmp11_;
					if (!_tmp5_) {
						GDir* _tmp6_;
						const gchar* _tmp7_;
						_tmp6_ = dir;
						_tmp7_ = g_dir_read_name (_tmp6_);
						entry = _tmp7_;
					}
					_tmp5_ = FALSE;
					_tmp8_ = entry;
					if (!(_tmp8_ != NULL)) {
						break;
					}
					_tmp9_ = entry;
					_tmp10_ = g_strconcat (rpath, _tmp9_, NULL);
					path = _tmp10_;
					_tmp11_ = path;
					is_dir = g_file_test (_tmp11_, G_FILE_TEST_IS_DIR);
					if (is_dir == TRUE) {
						gboolean tmp = FALSE;
						const gchar* _tmp12_;
						_tmp12_ = path;
						tmp = valadoc_remove_directory (_tmp12_);
						if (tmp == FALSE) {
							result = FALSE;
							_g_free0 (path);
							_g_dir_close0 (dir);
							return result;
						}
					} else {
						gint tmp = 0;
						const gchar* _tmp13_;
						_tmp13_ = path;
						tmp = g_unlink (_tmp13_);
						if (tmp > 0) {
							result = FALSE;
							_g_free0 (path);
							_g_dir_close0 (dir);
							return result;
						}
					}
					_g_free0 (path);
				}
			}
		}
		_g_dir_close0 (dir);
	}
	goto __finally0;
	__catch0_g_file_error:
	{
		g_clear_error (&_inner_error0_);
		result = FALSE;
		return result;
	}
	__finally0:
	if (G_UNLIKELY (_inner_error0_ != NULL)) {
		gboolean _tmp14_ = FALSE;
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error0_->message, g_quark_to_string (_inner_error0_->domain), _inner_error0_->code);
		g_clear_error (&_inner_error0_);
		return _tmp14_;
	}
	result = TRUE;
	return result;
}

