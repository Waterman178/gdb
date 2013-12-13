## Process this file with automake to generate Makefile.in
#
#   Copyright 2013 Free Software Foundation
#
# This file is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 3 of the License, or
# (at your option) any later version.
# 
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
# 
# You should have received a copy of the GNU General Public License
# along with this program; see the file COPYING3.  If not see
# <http://www.gnu.org/licenses/>.
#

ACLOCAL_AMFLAGS = -I . -I .. -I ../config -I common

noinst_LTLIBRARIES = libcommon.la

libcommon_la_SOURCES = common/agent.c common/agent.h \
    common/break-common.h common/btrace-common.h common/buffer.c \
    common/buffer.h common/common-utils.c common/common-utils.h	\
    common/filestuff.c common/filestuff.h common/format.c \
    common/format.h common/gdb_assert.h common/gdb_locale.h \
    common/gdb_signals.h common/gdb_thread_db.h common/gdb_vecs.c \
    common/gdb_vecs.h common/gdb_wait.h common/glibc_thread_db.h \
    common/host-defs.h common/i386-cpuid.h common/i386-gcc-cpuid.h \
    common/i386-xstate.h common/linux-btrace.c common/linux-btrace.h \
    common/linux-osdata.c common/linux-osdata.h common/linux-procfs.c \
    common/linux-procfs.h common/linux-ptrace.c common/linux-ptrace.h \
    common/mips-linux-watch.c common/mips-linux-watch.h common/ptid.c \
    common/ptid.h common/queue.h common/signals.c common/vec.c \
    common/vec.h common/version.h common/xml-utils.c \
    common/xml-utils.h nat/linux-nat.h nat/linux-waitpid.c \
    nat/linux-waitpid.h target/resume.h target/wait.h \
    target/waitstatus.c target/waitstatus.h

