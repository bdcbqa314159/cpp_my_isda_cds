/*
 * ISDA CDS Standard Model
 *
 * Copyright (C) 2009 International Swaps and Derivatives Association, Inc.
 * Developed and supported in collaboration with Markit
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the ISDA CDS Standard Model Public License.
 */

#include "cmemory.hpp"

#include <memory.h>
#include <stdlib.h>

#include <iostream>

// #include "cerror.hpp"

/*
***************************************************************************
** Memory allocator.
**
** Returns NULL if no memory left.
***************************************************************************
*/
void *JpmcdsMallocSafe(size_t theSize) {
  static char routine[] = "JpmcdsMallocSafe";
  void *ptr;

  if (theSize <= 0) {
    // TODO work here
    std::cout << routine << ": Number of bytes (" << (unsigned long)theSize
              << ") must be at least 1.\n";
    // JpmcdsErrMsg("%s: Number of bytes (%lu) must be at least 1.\n", routine,
    //              (unsigned long)theSize);
    return NULL;
  }
  ptr = malloc(theSize); /* Don't use calloc due to RS6000. */
  if (ptr == NULL) {
    // TODO work here
    //  JpmcdsErrMsg("%s: Insufficient memory to allocate %lu bytes.\n",
    //  routine,
    //               (unsigned long)theSize);
    std::cout << routine << ": Insufficient memory to allocate "
              << (unsigned long)theSize << " bytes.\n";
  } else {
    /* Clear out the memory for safety. */
    (void)memset((char *)ptr, (size_t)0, theSize);
  }
  return ptr;
}

/*
***************************************************************************
** Memory deallocator.
***************************************************************************
*/
void JpmcdsFreeSafe(void *ptr) {
  if (ptr != NULL) free(ptr);
}
