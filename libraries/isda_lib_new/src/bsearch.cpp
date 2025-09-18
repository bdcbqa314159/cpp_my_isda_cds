/*
 * ISDA CDS Standard Model
 *
 * Copyright (C) 2009 International Swaps and Derivatives Association, Inc.
 * Developed and supported in collaboration with Markit
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the ISDA CDS Standard Model Public License.
 */

#include "bsearch.hpp"

#include <math.h>

#include "cerror.hpp"
#include "cgeneral.hpp"

#define STR(x) #x
#define STRING(x) STR(x)

static TBoolean bSearchCheckOrder_g = TRUE;

/*
***************************************************************************
** Binary search through an array. This can be an array of doubles (set
** skip=sizeof(double)) or an array of some other structure which includes
** a double as one of its fields (skip=sizeof(structure)).
**
** Normally checks that the array is in sequence. This slows the function
** down to a linear search + binary search. You can either call
** JpmcdsBSearchCheckOrder to turn this checking off (and back on again), or
** else call JpmcdsBSearchDoubleFast.
***************************************************************************
*/
int JpmcdsBSearchDouble(double xDesired, /* (I) X for which Y is desired */
                        double *x,       /* (I) Ordered Array of X values */
                        int skip,        /* (I) # bytes between X values */
                                         /* (=sizeof(X_TYPE) if x is an array)*/
                        int N,           /* (I) # elements of X array */
                        int *lo_idx,     /* (O) Low index for X array */
                        int *hi_idx)     /* (O) High index for X array */
{
  static char routine[] = "JpmcdsBSearchDouble";

  if (bSearchCheckOrder_g &&
      JpmcdsCheckDoubleArrayOrder(routine, x, skip, N) != SUCCESS) {
    return FAILURE;
  }

  if (JpmcdsBSearchDoubleFast(xDesired, x, skip, N, lo_idx, hi_idx) !=
      SUCCESS) {
    JpmcdsErrMsg("%s: Failed.\n", routine);
    return FAILURE;
  }

  return SUCCESS;
}

#define X_TYPE double
#define XARRAY(IDX) (*((X_TYPE *)((char *)xp + (IDX) * skip)))
int JpmcdsBSearchDoubleFast(double xDesired, /* (I) X for which Y is desired */
                            double *x,       /* (I) Ordered Array of X values */
                            int skip,        /* (I) # bytes between X values */
                            /* (=sizeof(X_TYPE) if x is an array)*/
                            int N,       /* (I) # elements of X array */
                            int *lo_idx, /* (O) Low index for X array */
                            int *hi_idx  /* (O) High index for X array */
) {
  int count;            /* Used to check # search steps */
  int lo;               /* Index of low estimate */
  int hi;               /* Index of high estimate */
  int mid = 0;          /* Index of best estimate */
  char *xp = (char *)x; /* Ptr to x array */
  int shiftValue;

  /* Get base two log of skip, if skip is a power of 2. Otherwise 0.
   * Was getShift()...
   */
  switch (skip) {
    case 16:
      shiftValue = 4;
      break;
    case 8:
      shiftValue = 3;
      break;
    case 4:
      shiftValue = 2;
      break;
    case 2:
      shiftValue = 1;
      break;
    default:
      shiftValue = 0;
      break;
  }

  if (N < 2) {
    if (N < 1) /* Less than 1 point */
    {
      // JpmcdsErrMsg("%s: # points (%d) must be >= 1\n",
      //  STRING(SEARCH_ROUTINE_NAME), N);
      return FAILURE;
    } else /* Only 1 point */
    {
      *lo_idx = 0; /* Best estimate is that point */
      *hi_idx = 0;
      return SUCCESS;
    }
  }

  /* Extrapolate if desired X is less than smallest in X array.
   */
  if (xDesired <= XARRAY(0)) {
    *lo_idx = 0;
    *hi_idx = 1;
    return SUCCESS;
  }

  /* Extrapolate if desired X is greater than biggest in X array.
   */
  if (xDesired >= XARRAY(N - 1)) {
    *lo_idx = N - 2;
    *hi_idx = N - 1;
    return SUCCESS;
  }
  lo = 0;
  hi = N - 2;

  /* Do binary search to find pair of x's which surround the desired
   * X value.
   */
  for (count = N + 1; count > 0; count--) {
    mid = (hi + lo) / 2;

    if (xDesired < XARRAY(mid))
      hi = mid - 1;

    else if (xDesired > XARRAY(mid + 1))
      lo = mid + 1;

    else
      break; /* Done */
  }

  if (count == 0) {
    // JpmcdsErrMsg("%s: x array not in increasing order.\n",
    //  STRING(SEARCH_ROUTINE_NAME));
    return FAILURE;
  }

  /* Protect against a run of x values which are the same.
   * Set two surrounding indices to be lo and hi.
   * Note that there is no danger of running off the end
   * since the only way for x[lo] = x[hi] is for both
   * to be equal to xDesired. But from check at beginning,
   * we know X[N-1] <> xDesired.
   */
  lo = mid;
  hi = mid + 1;

  while (XARRAY(lo) == XARRAY(hi)) hi++;

  *lo_idx = lo;
  *hi_idx = hi;

  return SUCCESS;
}
#undef XARRAY
#undef X_TYPE

int JpmcdsCheckDoubleArrayOrder(char *routine, /* (I) For error messages only */
                                double *x, /* (I) Ordered Array of X values */
                                int skip,  /* (I) # bytes between X values */
                                /* (=sizeof(double ) if x is an array)*/
                                int N /* (I) # elements of X array */
) {
  int idx;
  double *cur;
  double *nxt;

  nxt = x;

  for (idx = 0; idx < N - 1; idx++) {
    cur = nxt;
    nxt = (double *)((char *)cur + skip);
    if (*cur >= *nxt) {
      // JpmcdsErrMsg("%s: Domain array element %d (%f) <= element %d (%f).\n",
      //  routine, idx + 1, (double)(*nxt), idx, (double)(*cur));
      return FAILURE;
    }
  }

  return SUCCESS;
}

/*
***************************************************************************
** Binary search through an array. This can be an array of longs (set
** skip=sizeof(long)) or an array of some other structure which includes
** a long as one of its fields (skip=sizeof(structure)).
**
** Normally checks that the array is in sequence. This slows the function
** down to a linear search + binary search. You can either call
** JpmcdsBSearchCheckOrder to turn this checking off (and back on again), or
** else call JpmcdsBSearchLongFast).
***************************************************************************
*/

int JpmcdsBSearchLong(double xDesired, /* (I) X for which Y is desired */
                      long *x,         /* (I) Ordered Array of X values */
                      int skip,        /* (I) # bytes between X values */
                                       /* (=sizeof(X_TYPE) if x is an array)*/
                      int N,           /* (I) # elements of X array */
                      int *lo_idx,     /* (O) Low index for X array */
                      int *hi_idx)     /* (O) High index for X array */
{
  static char routine[] = "JpmcdsBSearchLong";

  if (bSearchCheckOrder_g &&
      JpmcdsCheckLongArrayOrder(routine, x, skip, N) != SUCCESS) {
    return FAILURE;
  }

  if (JpmcdsBSearchLongFast(xDesired, x, skip, N, lo_idx, hi_idx) != SUCCESS) {
    // JpmcdsErrMsg("%s: Failed.\n", routine);
    return FAILURE;
  }

  return SUCCESS;
}

#define X_TYPE long
#define XARRAY(IDX) (*((X_TYPE *)((char *)xp + (IDX) * skip)))
int JpmcdsBSearchLongFast(long xDesired, /* (I) X for which Y is desired */
                          long *x,       /* (I) Ordered Array of X values */
                          int skip,      /* (I) # bytes between X values */
                          /* (=sizeof(X_TYPE) if x is an array)*/
                          int N,       /* (I) # elements of X array */
                          int *lo_idx, /* (O) Low index for X array */
                          int *hi_idx  /* (O) High index for X array */
) {
  int count;            /* Used to check # search steps */
  int lo;               /* Index of low estimate */
  int hi;               /* Index of high estimate */
  int mid = 0;          /* Index of best estimate */
  char *xp = (char *)x; /* Ptr to x array */
  int shiftValue;

  /* Get base two log of skip, if skip is a power of 2. Otherwise 0.
   * Was getShift()...
   */
  switch (skip) {
    case 16:
      shiftValue = 4;
      break;
    case 8:
      shiftValue = 3;
      break;
    case 4:
      shiftValue = 2;
      break;
    case 2:
      shiftValue = 1;
      break;
    default:
      shiftValue = 0;
      break;
  }

  if (N < 2) {
    if (N < 1) /* Less than 1 point */
    {
      // JpmcdsErrMsg("%s: # points (%d) must be >= 1\n",
      //  STRING(SEARCH_ROUTINE_NAME), N);
      return FAILURE;
    } else /* Only 1 point */
    {
      *lo_idx = 0; /* Best estimate is that point */
      *hi_idx = 0;
      return SUCCESS;
    }
  }

  /* Extrapolate if desired X is less than smallest in X array.
   */
  if (xDesired <= XARRAY(0)) {
    *lo_idx = 0;
    *hi_idx = 1;
    return SUCCESS;
  }

  /* Extrapolate if desired X is greater than biggest in X array.
   */
  if (xDesired >= XARRAY(N - 1)) {
    *lo_idx = N - 2;
    *hi_idx = N - 1;
    return SUCCESS;
  }
  lo = 0;
  hi = N - 2;

  /* Do binary search to find pair of x's which surround the desired
   * X value.
   */
  for (count = N + 1; count > 0; count--) {
    mid = (hi + lo) / 2;

    if (xDesired < XARRAY(mid))
      hi = mid - 1;

    else if (xDesired > XARRAY(mid + 1))
      lo = mid + 1;

    else
      break; /* Done */
  }

  if (count == 0) {
    // JpmcdsErrMsg("%s: x array not in increasing order.\n",
    //  STRING(SEARCH_ROUTINE_NAME));
    return FAILURE;
  }

  /* Protect against a run of x values which are the same.
   * Set two surrounding indices to be lo and hi.
   * Note that there is no danger of running off the end
   * since the only way for x[lo] = x[hi] is for both
   * to be equal to xDesired. But from check at beginning,
   * we know X[N-1] <> xDesired.
   */
  lo = mid;
  hi = mid + 1;

  while (XARRAY(lo) == XARRAY(hi)) hi++;

  *lo_idx = lo;
  *hi_idx = hi;

  return SUCCESS;
}
#undef XARRAY
#undef X_TYPE

int JpmcdsCheckLongArrayOrder(char *routine, /* (I) For error messages only */
                              long *x,       /* (I) Ordered Array of X values */
                              int skip,      /* (I) # bytes between X values */
                              /* (=sizeof(long) if x is an array)*/
                              int N /* (I) # elements of X array */
) {
  int idx;
  long *cur;
  long *nxt;

  nxt = x;

  for (idx = 0; idx < N - 1; idx++) {
    cur = nxt;
    nxt = (long *)((char *)cur + skip);
    if (*cur >= *nxt) {
      // JpmcdsErrMsg("%s: Domain array element %d (%f) <= element %d
      //  (%f).\n",
      //               routine, idx + 1, (double)(*nxt), idx, (double)(*cur));
      return FAILURE;
    }
  }

  return SUCCESS;
}

TBoolean JpmcdsBSearchCheckOrder(
    TBoolean
        doCheckOrder) /* (I) TRUE=> Default Yes check; FALSE=>Assume in order */
{
  TBoolean checkOrderWas = bSearchCheckOrder_g;

  bSearchCheckOrder_g = doCheckOrder;

  return checkOrderWas;
}
