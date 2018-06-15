/* A "next" iterator for GDB, the GNU debugger.
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

#ifndef NEXT_ITERATOR_H
#define NEXT_ITERATOR_H

/* An iterator that uses the 'next' field of a type to iterate.  This
   can be used with various GDB types that are stored as linked
   lists.  */

template<typename T>
struct next_iterator
{
  typedef next_iterator self_type;
  typedef T *value_type;
  typedef T *&reference;
  typedef T **pointer;
  typedef std::forward_iterator_tag iterator_category;
  typedef int difference_type;

  explicit next_iterator (T *item)
    : m_item (item)
  {
  }

  /* Create a one-past-the-end iterator.  */
  next_iterator ()
    : m_item (nullptr)
  {
  }

  value_type operator* () const
  {
    return m_item;
  }

  bool operator== (const self_type &other) const
  {
    return m_item == other.m_item;
  }

  bool operator!= (const self_type &other) const
  {
    return m_item != other.m_item;
  }

  self_type &operator++ ()
  {
    m_item = m_item->next;
    return *this;
  }

private:

  T *m_item;
};

/* A range adapter that allows iterating over a linked list.  */

template<typename T>
class next_adapter
{
public:

  explicit next_adapter (T *item)
    : m_item (item)
  {
  }

  using iterator = next_iterator<T>;

  iterator begin () const
  {
    return iterator (m_item);
  }

  iterator end () const
  {
    return iterator ();
  }

private:

  T *m_item;
};

#endif /* NEXT_ITERATOR_H */
