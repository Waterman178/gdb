/* Header file for GDB GCC JIT.
   Copyright (C) 2014 Free Software Foundation, Inc.

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

#ifndef GDB_GCCJIT_GCCJIT_H
#define GDB_GCCJIT_GCCJIT_H

extern void eval_gcc_jit_command (struct command_line *cmd, char *cmd_string);
extern void _initialize_gcc_jit (void);

#endif /* GDB_GCCJIT_GCCJIT_H */
