/*
 * ***** BEGIN GPL LICENSE BLOCK *****
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 * The Original Code is Copyright (C) 2015 by Blender Foundation
 * All rights reserved.
 *
 * The Original Code is: all of this file.
 *
 * Contributor(s): none yet.
 *
 * ***** END GPL LICENSE BLOCK *****
 */

/** \file DNA_cache_library_types.h
 *  \ingroup DNA
 */

#ifndef __DNA_CACHE_LIBRARY_TYPES_H__
#define __DNA_CACHE_LIBRARY_TYPES_H__

#include "DNA_defs.h"
#include "DNA_ID.h"
#include "DNA_listBase.h"

#define MAX_CACHE_GROUP_LEVEL 8

typedef struct CacheItemPath {
	char value[8][64]; /* MAX_CACHE_GROUP_LEVEL, MAX_NAME */
} CacheItemPath;

typedef struct CacheItem {
	struct CacheItem *next, *prev;
	
	CacheItemPath path;
} CacheItem;

typedef struct CacheLibrary {
	ID id;
	
	char filepath[1024]; /* 1024 = FILE_MAX */
	struct Group *group;
	
	ListBase items;				/* cached items */
	struct GHash *items_hash;	/* runtime: cached items hash for fast lookup */
} CacheLibrary;

#endif

