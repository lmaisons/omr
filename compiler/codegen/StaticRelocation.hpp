/*******************************************************************************
 *
 * (c) Copyright IBM Corp. 2017, 2017
 *
 *  This program and the accompanying materials are made available
 *  under the terms of the Eclipse Public License v1.0 and
 *  Apache License v2.0 which accompanies this distribution.
 *
 *      The Eclipse Public License is available at
 *      http://www.eclipse.org/legal/epl-v10.html
 *
 *      The Apache License v2.0 is available at
 *      http://www.opensource.org/licenses/apache2.0.php
 *
 * Contributors:
 *    Multiple authors (IBM Corp.) - initial implementation and documentation
 *******************************************************************************/

#ifndef STATICRELOCATION_HPP
#define STATICRELOCATION_HPP

#pragma once

#include <inttypes.h>

class TR_ResolvedMethod;

namespace TR {

enum class StaticRelocationType
   {
   Absolute,
   Relative,
   };

enum class StaticRelocationSize
   {
   word8,
   word16,
   word32,
   word64,
   };

class StaticRelocation
   {
public:
   StaticRelocation(
      uint8_t *location,
      TR_ResolvedMethod *symbol,
      StaticRelocationSize size,
      StaticRelocationType relocationType
      ) :
      _location(location),
      _symbol(symbol),
      _size(size),
      _type(relocationType)
      {
      }

   uint8_t * location() const { return _location; }
   TR_ResolvedMethod * symbol() const { return _symbol; }
   StaticRelocationSize size() const { return _size; }
   StaticRelocationType type() const { return _type; }

private:
   uint8_t * const _location;
   TR_ResolvedMethod * _symbol;
   const StaticRelocationSize _size;
   const StaticRelocationType _type;
   };

}

#endif // STATICRELOCATION_HPP
