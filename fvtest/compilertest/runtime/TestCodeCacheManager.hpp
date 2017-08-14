/*******************************************************************************
 *
 * (c) Copyright IBM Corp. 2000, 2016
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

#ifndef TEST_CODECACHEMANAGER_INCL
#define TEST_CODECACHEMANAGER_INCL

#ifndef TEST_CODECACHEMANAGER_COMPOSED
#define TEST_CODECACHEMANAGER_COMPOSED
namespace TestCompiler { class CodeCacheManager; }
namespace TestCompiler { typedef CodeCacheManager CodeCacheManagerConnector; }
#endif

#include <stddef.h>
#include <stdint.h>
#include "runtime/OMRCodeCacheManager.hpp"

namespace TR { class CodeCacheMemorySegment; }
namespace TR { class CodeCache; }
namespace TR { class CodeCacheManager; }

namespace TestCompiler
{

class JitConfig;
class FrontEnd;

class OMR_EXTENSIBLE CodeCacheManager : public OMR::CodeCacheManagerConnector
   {
   TR::CodeCacheManager *self();

public:
   CodeCacheManager(TR::RawAllocator rawAllocator) : OMR::CodeCacheManagerConnector(rawAllocator)
      {
      _codeCacheManager = reinterpret_cast<TR::CodeCacheManager *>(this);
      }

   void *operator new(size_t s, TR::CodeCacheManager *m) { return m; }

   static TR::CodeCacheManager *instance()  { return _codeCacheManager; }

   void *getMemory(size_t sizeInBytes);
   void  freeMemory(void *memoryToFree);

   TR::CodeCacheMemorySegment *allocateCodeCacheSegment(size_t segmentSize,
                                                        size_t &codeCacheSizeToAllocate,
                                                        void *preferredStartAddress);

private :
   static TR::CodeCacheManager *_codeCacheManager;
   };

} // namespace TestCompiler

#endif // TEST_CODECACHEMANAGER_INCL
