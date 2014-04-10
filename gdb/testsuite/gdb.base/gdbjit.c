/* This testcase is part of GDB, the GNU debugger.

   Copyright 2014 Free Software Foundation, Inc.

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

#define SOME_MACRO 23
#define ARG_MACRO(X, Y) ((X) + (Y) - 1)


enum enum_type {
  ONE = 1,
  TWO = 2
};

typedef int v4 __attribute__ ((vector_size (16)));

union union_type;

struct struct_type {
  char charfield;
  unsigned char ucharfield;
  short shortfield;
  unsigned short ushortfield;
  int intfield;
  unsigned int uintfield;
  long longfield;
  unsigned long ulongfield;
  enum enum_type enumfield;
  float floatfield;
  double doublefield;
  const union union_type *ptrfield;
  struct struct_type *selffield;
  int arrayfield[5];
  _Complex double complexfield;
  _Bool boolfield;
  v4 vectorfield;
};

typedef int inttypedef;

union union_type {
  int intfield;
  inttypedef typedeffield;
};

/* volatile provides some coverage of the conversion code.  */
volatile struct struct_type struct_object;

union union_type union_object;


enum ulonger_enum_type {
  REALLY_MINUS_1 = -1UL,
};

enum ulonger_enum_type ulonger;

enum longer_enum_type {
  MINUS_1 = -1,
  FORCE_TO_LONG = 1L << ((8 * sizeof (long)) - 2)
};

enum longer_enum_type longer;

int globalvar = 10;

static void
func_static (int addend)
{
  globalvar += addend;
}

void
func_global (int subtrahend)
{
  globalvar -= subtrahend;
}

void
no_args_or_locals (void)
{
  /* no_args_or_locals breakpoint */
}

int *intptr;

int
main (void)
{
  int localvar = 50;
  int shadowed = 51;

  {
    int another_local = 7;
    int shadowed = 52;

    func_static (0); /* break-here */
    no_args_or_locals ();
  }

 return 0;
}
