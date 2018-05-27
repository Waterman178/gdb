/* task-queue.h, a simple thread-safe queue

   Copyright (C) 2018 Free Software Foundation, Inc.

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

#ifndef GDB_COMMON_TASK_QUEUE_H
#define GDB_COMMON_TASK_QUEUE_H

#include <condition_variable>
#include <mutex>
#include <queue>

namespace gdb
{

template<typename T>
class task_queue
{
public:

  task_queue (int writer_count)
    : m_done (false),
      m_writer_count (writer_count)
  {
    gdb_assert (m_writer_count > 0);
  }

  ~task_queue ()
  {
  }

  DISABLE_COPY_AND_ASSIGN (task_queue);

  void push (T &&item)
  {
    std::unique_lock<std::mutex> guard (m_mutex);
    gdb_assert (!m_done);
    m_items.push (std::move (item));
    m_condvar.notify_one ();
  }

  void push (const T &item)
  {
    std::unique_lock<std::mutex> guard (m_mutex);
    gdb_assert (!m_done);
    m_items.push (item);
    m_condvar.notify_one ();
  }

  bool pop (T *item)
  {
    std::unique_lock<std::mutex> guard (m_mutex);
    while (true)
      {
	if (!m_items.empty ())
	  {
	    *item = std::move (m_items.front ());
	    m_items.pop ();
	    return true;
	  }
	if (m_done)
	  return false;
	m_condvar.wait (guard);
      }
  }

  void end_writing ()
  {
    std::unique_lock<std::mutex> guard (m_mutex);
    gdb_assert (!m_done);
    gdb_assert (m_writer_count > 0);
    --m_writer_count;
    if (m_writer_count == 0)
      {
	m_done = true;
	m_condvar.notify_all ();
      }
  }

private:

  std::mutex m_mutex;
  std::condition_variable m_condvar;
  bool m_done;
  int m_writer_count;
  std::queue<T> m_items;
};

} /* namespace gdb */

#endif /* GDB_COMMON_TASK_QUEUE_H */
