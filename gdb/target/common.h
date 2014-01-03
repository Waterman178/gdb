/* Declarations for common target functions.

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

#ifndef TARGET_COMMON_H
#define TARGET_COMMON_H

/* This header is a stopgap until more code is shared.  */

extern int target_read_memory (CORE_ADDR memaddr, gdb_byte *myaddr,
			       ssize_t len);


extern int target_read_uint32 (CORE_ADDR memaddr, unsigned int *result);

extern int target_write_memory (CORE_ADDR memaddr, const gdb_byte *myaddr,
				ssize_t len);

#endif /* TARGET_COMMON_H */
