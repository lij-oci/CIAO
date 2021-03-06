
/* -*- c++ -*- */
//=============================================================================
/**
 *  @file    identifier_helper.h
 *
 *  Utilities associated with UTL_Identifier.
 *
 *  @author Jeff Parsons <j.parsons@vanderbilt.edu>
 */
//=============================================================================


#ifndef IDENTIFIER_HELPER_H
#define IDENTIFIER_HELPER_H

#include "utl_scoped_name.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/SString.h"

class Identifier;

/**
 * 1) keeps escape (leading underscore character in generated identifier in IDL
 * 2) removes the '_' escape character when the identifier is
 * part of another identifier such as in provides_XXX
 * 3) removes any '_cxx_' in generated IDL
 */
struct IdentifierHelper
{
  static Identifier *
  original_local_name (Identifier * local_name);

  // Removes '_cxx_ from segments of a scoped name, and optionally
  // de-escape the last segment, if it's to be appended to.
  static ACE_CString
  orig_sn (UTL_ScopedName * scoped_name, bool appended_to = false);

  // Detects case-insensitive match with IDL keyword.
  static bool
  is_idl_keyword (Identifier * local_name);

  // Preserves the 'escape' (leading underscore) in a
  // generated identifier if necessary.
  static ACE_CString
  try_escape (Identifier * local_name);
};

#endif /* IDENTIFIER_HELPER_H */
