/* Shared general utility routines for GDB, the GNU debugger.

   Copyright (C) 1986-2014 Free Software Foundation, Inc.

   This file is part of GDB.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

#include <libgdb-config.h>

#include "libiberty.h"
#include "common-utils.h"
#include "gdb_locale.h"
#include "gdb_assert.h"
#include <string.h>

#include <stdlib.h>
#include <stdio.h>

void *
xzalloc (size_t size)
{
  return xcalloc (1, size);
}

void
xfree (void *ptr)
{
  if (ptr != NULL)
    free (ptr);		/* ARI: free */
}

/* Like asprintf/vasprintf but get an internal_error if the call
   fails. */

char *
xstrprintf (const char *format, ...)
{
  char *ret;
  va_list args;

  va_start (args, format);
  ret = xstrvprintf (format, args);
  va_end (args);
  return ret;
}

char *
xstrvprintf (const char *format, va_list ap)
{
  char *ret = NULL;
  int status = vasprintf (&ret, format, ap);

  /* NULL is returned when there was a memory allocation problem, or
     any other error (for instance, a bad format string).  A negative
     status (the printed length) with a non-NULL buffer should never
     happen, but just to be sure.  */
  if (ret == NULL || status < 0)
    internal_error (__FILE__, __LINE__, _("vasprintf call failed"));
  return ret;
}

int
xsnprintf (char *str, size_t size, const char *format, ...)
{
  va_list args;
  int ret;

  va_start (args, format);
  ret = vsnprintf (str, size, format, args);
  gdb_assert (ret < size);
  va_end (args);

  return ret;
}

char *
savestring (const char *ptr, size_t len)
{
  char *p = (char *) xmalloc (len + 1);

  memcpy (p, ptr, len);
  p[len] = 0;
  return p;
}
