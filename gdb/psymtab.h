/* Public partial symbol table definitions.

   Copyright (C) 2009-2018 Free Software Foundation, Inc.

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

#ifndef PSYMTAB_H
#define PSYMTAB_H

#include "symfile.h"

/* A bcache for partial symbols.  */

struct compunit_symtab;
struct partial_symbol;
struct partial_symtab;
struct psymbol_bcache;

/* An instance of this class manages the partial symbol tables and
   partial symbols for a given objfile.  */

class psymtab_storage
{
public:

  explicit psymtab_storage (struct objfile *objfile);

  ~psymtab_storage ();

  DISABLE_COPY_AND_ASSIGN (psymtab_storage);

  /* Discard all partial symbol tables starting with "psymtabs" and
     proceeding until "to" has been discarded.  */

  void discard_psymtabs_to (struct partial_symtab *to)
  {
    while (psymtabs != to)
      discard_psymtab (psymtabs);
  }

  /* Discard the partial symbol table.  */

  void discard_psymtab (struct partial_symtab *pst);


  /* Each objfile points to a linked list of partial symtabs derived from
     this file, one partial symtab structure for each compilation unit
     (source file).  */

  struct partial_symtab *psymtabs = nullptr;

  /* Map addresses to the entries of PSYMTABS.  It would be more efficient to
     have a map per the whole process but ADDRMAP cannot selectively remove
     its items during FREE_OBJFILE.  This mapping is already present even for
     PARTIAL_SYMTABs which still have no corresponding full SYMTABs read.  */

  struct addrmap *psymtabs_addrmap = nullptr;

  /* List of freed partial symtabs, available for re-use.  */

  struct partial_symtab *free_psymtabs = nullptr;

  /* The obstack where allocations are made.  */

  struct obstack *obstack;

  /* A byte cache where we can stash arbitrary "chunks" of bytes that
     will not change.  */

  struct psymbol_bcache *psymbol_cache;

  /* Vectors of all partial symbols read in from file.  The actual data
     is stored in the objfile_obstack.  */

  std::vector<partial_symbol *> global_psymbols;
  std::vector<partial_symbol *> static_psymbols;
};


extern struct psymbol_bcache *psymbol_bcache_init (void);
extern void psymbol_bcache_free (struct psymbol_bcache *);
extern struct bcache *psymbol_bcache_get_bcache (struct psymbol_bcache *);

extern const struct quick_symbol_functions psym_functions;

extern const struct quick_symbol_functions dwarf2_gdb_index_functions;
extern const struct quick_symbol_functions dwarf2_debug_names_functions;

/* Ensure that the partial symbols for OBJFILE have been loaded.  If
   VERBOSE is non-zero, then this will print a message when symbols
   are loaded.  This function always returns its argument, as a
   convenience.  */

extern struct objfile *require_partial_symbols (struct objfile *objfile,
						int verbose);

/* Record that, for the given objfile, PST has expanded to SYMTAB.
   SYMTAB may be nullptr, indicating that an attempt to expand PST was
   made, but yielded no results (perhaps this was an included
   psymtab).  By default, this association is always made, but if
   ALWAYS_SET is false, then an association is only made if one has
   not been made previously.  */

extern void associate_psymtab_with_symtab (struct objfile *objfile,
					   partial_symtab *pst,
					   compunit_symtab *symtab,
					   bool always_set = true);

/* Return true if PST was ever read in for the given objfile, false
   otherwise.  This only records whether an attempt was made -- not
   whether it yielded a full symtab.  */

extern bool psymtab_read_in_p (struct objfile *objfile, partial_symtab *pst);

/* Return the full symtab corresponding to PST.  Returns NULL if the
   partial symtab was never read, or if the attempt to read it yielded
   no results.  */

extern compunit_symtab *get_psymtab_compunit (struct objfile *objfile,
					      partial_symtab *pst);

#endif /* PSYMTAB_H */
