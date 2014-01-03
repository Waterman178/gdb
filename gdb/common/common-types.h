/* Declarations for common types.

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

#ifndef COMMON_TYPES_H
#define COMMON_TYPES_H

/* Note that we cannot actually use BFD, as gdbserver doesn't link
   against it.  However, we can include the header to pick up some
   types.  It would be better to do this via configury -- even just
   extracting the types from the generated bfd.h.  */

#include "bfd.h"

/* A byte from the program being debugged.  */
typedef bfd_byte gdb_byte;

/* An address in the program being debugged.  Host byte order.  */
typedef bfd_vma CORE_ADDR;

/* The largest CORE_ADDR value.  */
#define CORE_ADDR_MAX (~ (CORE_ADDR) 0)

/* This is to make sure that LONGEST is at least as big as CORE_ADDR.  */

#ifdef BFD64

typedef BFD_HOST_64_BIT LONGEST;
typedef BFD_HOST_U_64_BIT ULONGEST;

#else /* No BFD64 */

typedef long long LONGEST;
typedef unsigned long long ULONGEST;

#endif /* No BFD64 */

#endif /* COMMON_TYPES_H */
