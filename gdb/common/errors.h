/* Declarations for error-reporting facilities.

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

#ifndef COMMON_ERRORS_H
#define COMMON_ERRORS_H

/* The declarations in this file are, for the time being, separately
   implemented by gdb and gdbserver.  However they share a common
   definition so that they can be used by code in common/.  */

/* Like "perror" but throws an exception with the appropriate
   text.  */

extern void perror_with_name (const char *) ATTRIBUTE_NORETURN;

/* Throw an exception.  */

extern void error (const char *fmt, ...)
     ATTRIBUTE_NORETURN ATTRIBUTE_PRINTF (1, 2);

/* Cause a fatal error.  */

extern void fatal (const char *fmt, ...)
     ATTRIBUTE_NORETURN ATTRIBUTE_PRINTF (1, 2);

/* Issue a warning.  */

extern void warning (const char *, ...) ATTRIBUTE_PRINTF (1, 2);

#endif /* COMMON_ERRORS_H */
