dnl Autoconf configure script for GDB, the GNU debugger.
dnl Copyright (C) 1995-2013 Free Software Foundation, Inc.
dnl
dnl This file is part of GDB.
dnl 
dnl This program is free software; you can redistribute it and/or modify
dnl it under the terms of the GNU General Public License as published by
dnl the Free Software Foundation; either version 3 of the License, or
dnl (at your option) any later version.
dnl
dnl This program is distributed in the hope that it will be useful,
dnl but WITHOUT ANY WARRANTY; without even the implied warranty of
dnl MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
dnl GNU General Public License for more details.
dnl
dnl You should have received a copy of the GNU General Public License
dnl along with this program.  If not, see <http://www.gnu.org/licenses/>.

dnl Process this file with autoconf to produce a configure script.

AC_PREREQ(2.59)
AC_CONFIG_AUX_DIR(..)
AC_INIT([libgdb], [0.1])
AC_CONFIG_SRCDIR([common/ptid.h])
AC_CANONICAL_TARGET
AM_INIT_AUTOMAKE([foreign no-dist no-define silent-rules subdir-objects 1.11 -Wall])

AC_CONFIG_HEADER(libgdb-config.h:config.in)
AM_MAINTAINER_MODE



dnl These must be called before LT_INIT, because it may want
dnl to call AC_CHECK_PROG.
AC_CHECK_TOOL(AR, ar)
AC_CHECK_TOOL(RANLIB, ranlib, :)

LT_INIT([dlopen])

AC_PROG_CC
AM_PROG_CC_STDC

AC_USE_SYSTEM_EXTENSIONS
AC_GNU_SOURCE

ACX_LARGEFILE

GDB_AC_COMMON

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
