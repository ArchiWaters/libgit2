/*
 * Copyright (C) the libgit2 contributors. All rights reserved.
 *
 * This file is part of libgit2, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included COPYING file.
 */

/*
 * This file provides the necessary indirection between xdiff and
 * libgit2.  libgit2-specific functionality should live here, so
 * that git and libgit2 can share a common xdiff implementation.
 */

#ifndef INCLUDE_git_xdiff_h__
#define INCLUDE_git_xdiff_h__

#include "regexp.h"

#define xdl_malloc(x) git__malloc(x)
#define xdl_free(ptr) git__free(ptr)
#define xdl_realloc(ptr, x) git__realloc(ptr, x)

#define BUG(str) GIT_ASSERT(str)
#define XDL_UNUSED(x) GIT_UNUSED(x)

#define xdl_regex_t git_regexp
#define xdl_regmatch_t git_regmatch

GIT_INLINE(int) regexec_buf(
	const xdl_regex_t *preg, const char *buf, size_t size,
	size_t nmatch, xdl_regmatch_t pmatch[], int eflags)
{
	GIT_ASSERT(nmatch > 0 && pmatch && eflags == 0);

	return git_regexp_search_n(preg, buf, size, nmatch, pmatch);
}

#endif
