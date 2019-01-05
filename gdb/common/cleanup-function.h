/* Copyright (C) 2019 Free Software Foundation, Inc.

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

#ifndef COMMON_CLEANUP_FUNCTION_H
#define COMMON_CLEANUP_FUNCTION_H

#include "common/function-view.h"

/* A cleanup function is one that is run at the end of the current
   scope.  It is just a function of no arguments.  A cleanup function
   may be canceled by calling the "reset" method.  */

class cleanup_function
{
public:

  explicit cleanup_function (gdb::function_view<void ()> func)
    : m_func (func)
  {
  }

  DISABLE_COPY_AND_ASSIGN (cleanup_function);

  ~cleanup_function ()
  {
    m_func ();
  }

  /* If this is called, then the breakpoint will not be deleted on
     destruction.  */
  void reset ()
  {
    m_func = do_nothing;
  }

private:

  /* The function to call.  */
  gdb::function_view<void ()> m_func;

  /* A helper function that is used as the value of m_func when reset
     is called.  */
  static void do_nothing ()
  {
  }
};


#endif /* COMMON_CLEANUP_FUNCTION_H */
