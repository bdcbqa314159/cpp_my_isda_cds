#pragma once
#ifndef CMEMORY_HPP
#define CMEMORY_HPP

#include <stdlib.h>

#include "cgeneral.hpp"  // IWYU pragma: keep

EXPORT_C {
  /*f
   ***************************************************************************
   ** Memory allocator.
   **
   ** Returns NULL if no memory left.
   ***************************************************************************
   */
  void* JpmcdsMallocSafe(size_t theSize);

  /*f
  ***************************************************************************
  ** Memory deallocator.
  ***************************************************************************
  */
  void JpmcdsFreeSafe(void* x); /* (I) */
}

#endif  // CMEMORY_HPP