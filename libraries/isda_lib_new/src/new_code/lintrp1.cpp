/*
 * ISDA CDS Standard Model
 *
 * Copyright (C) 2009 International Swaps and Derivatives Association, Inc.
 * Developed and supported in collaboration with Markit
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the ISDA CDS Standard Model Public License.
 */

#include "lintrp1.hpp"

#include "bsearch.hpp"
#include "cerror.hpp"
#include "cgeneral.hpp"
// #include "lintrp.hpp"

// Helper macro to access array elements with stride
#define ARRAY_ELEMENT(ptr, idx, stride, type) \
  (*(const type*)((const char*)(ptr) + (idx) * (stride)))

// --- Long routines ---
int JpmcdsLinInterpLongArray1(long* x, int xskip, int N, const double* f,
                              int fskip, const long* xDesired, int dskip,
                              int numInterps, TMetricDoubleFunc mfunc,
                              int oskip, double* fInterp) {
  const char* xdp = (const char*)xDesired;
  char* fp = (char*)fInterp;
  for (int i = 0; i < numInterps; ++i) {
    long currentX = ARRAY_ELEMENT(xDesired, i, dskip, long);
    if (JpmcdsLinInterpLongPoint1(x, xskip, N, f, fskip, (double)currentX,
                                  mfunc, (double*)fp) == FAILURE) {
      JpmcdsErrMsg("JpmcdsLinInterpLongArray1: Failed.\n");
      return FAILURE;
    }
    xdp += dskip;
    fp += oskip;
  }
  return SUCCESS;
}

int JpmcdsLinInterpLongPoint1(long* x, int xskip, int N, const double* f,
                              int fskip, double xDesired,
                              TMetricDoubleFunc mfunc, double* fInterp) {
  int lo, hi;
  if (JpmcdsBSearchLong(xDesired, x, xskip, N, &lo, &hi) == FAILURE) {
    JpmcdsErrMsg("JpmcdsLinInterpLongPoint1: Failed.\n");
    return FAILURE;
  }

  if (lo == hi) {
    *fInterp = ARRAY_ELEMENT(f, lo, fskip, double);
  } else {
    double xLo = (double)ARRAY_ELEMENT(x, lo, xskip, long);
    double xHi = (double)ARRAY_ELEMENT(x, hi, xskip, long);
    double stepFraction = (mfunc == NULL)
                              ? (xDesired - xLo) / (xHi - xLo)
                              : mfunc(xDesired, xLo) / mfunc(xHi, xLo);
    double fLo = ARRAY_ELEMENT(f, lo, fskip, double);
    double fHi = ARRAY_ELEMENT(f, hi, fskip, double);
    *fInterp = fLo + stepFraction * (fHi - fLo);
  }
  return SUCCESS;
}

int JpmcdsLinInterpLongPoint1Discontinuous(long* x, int xskip, int N,
                                           const double* f, int fskip,
                                           double xDesired,
                                           TMetricDoubleFunc mfunc,
                                           int rightLimit, double* fInterp) {
  int checkOrder = JpmcdsBSearchCheckOrder(FALSE);
  for (int idx = 0; idx < N - 1; ++idx) {
    double xCurr = (double)ARRAY_ELEMENT(x, idx, xskip, long);
    double xNext = (double)ARRAY_ELEMENT(x, idx + 1, xskip, long);
    if (xCurr > xNext) {
      JpmcdsErrMsg(
          "JpmcdsLinInterpLongPoint1Discontinuous: "
          "Domain array element %d (%f) < element %d (%f).\n",
          idx + 1, xNext, idx, xCurr);
      JpmcdsBSearchCheckOrder(checkOrder);
      return FAILURE;
    }
  }

  int lo, hi;
  if (JpmcdsBSearchLong(xDesired, x, xskip, N, &lo, &hi) == FAILURE) {
    JpmcdsBSearchCheckOrder(checkOrder);
    JpmcdsErrMsg("JpmcdsLinInterpLongPoint1Discontinuous: Failed.\n");
    return FAILURE;
  }

  if (lo == hi) {
    *fInterp = ARRAY_ELEMENT(f, lo, fskip, double);
  } else if (xDesired != (double)ARRAY_ELEMENT(x, lo, xskip, long)) {
    double xLo = (double)ARRAY_ELEMENT(x, lo, xskip, long);
    double xHi = (double)ARRAY_ELEMENT(x, hi, xskip, long);
    double stepFraction = (mfunc == NULL)
                              ? (xDesired - xLo) / (xHi - xLo)
                              : mfunc(xDesired, xLo) / mfunc(xHi, xLo);
    double fLo = ARRAY_ELEMENT(f, lo, fskip, double);
    double fHi = ARRAY_ELEMENT(f, hi, fskip, double);
    *fInterp = fLo + stepFraction * (fHi - fLo);
  } else {
    while (lo > 0 && (double)ARRAY_ELEMENT(x, lo, xskip, long) ==
                         (double)ARRAY_ELEMENT(x, lo - 1, xskip, long)) {
      lo--;
    }
    while (hi < N - 1 && (double)ARRAY_ELEMENT(x, hi + 1, xskip, long) ==
                             (double)ARRAY_ELEMENT(x, lo, xskip, long)) {
      hi++;
    }
    if (hi - lo >= 2) {
      *fInterp = ARRAY_ELEMENT(f, (hi + lo) / 2, fskip, double);
    } else if (rightLimit) {
      *fInterp = ARRAY_ELEMENT(f, hi, fskip, double);
    } else {
      *fInterp = ARRAY_ELEMENT(f, lo, fskip, double);
    }
  }
  JpmcdsBSearchCheckOrder(checkOrder);
  return SUCCESS;
}

// --- Double routines ---
int JpmcdsLinInterpDoubleArray1(double* x, int xskip, int N, const double* f,
                                int fskip, const double* xDesired, int dskip,
                                int numInterps, TMetricDoubleFunc mfunc,
                                int oskip, double* fInterp) {
  const char* xdp = (const char*)xDesired;
  char* fp = (char*)fInterp;
  for (int i = 0; i < numInterps; ++i) {
    double currentX = ARRAY_ELEMENT(xDesired, i, dskip, double);
    if (JpmcdsLinInterpDoublePoint1(x, xskip, N, f, fskip, currentX, mfunc,
                                    (double*)fp) == FAILURE) {
      JpmcdsErrMsg("JpmcdsLinInterpDoubleArray1: Failed.\n");
      return FAILURE;
    }
    xdp += dskip;
    fp += oskip;
  }
  return SUCCESS;
}

int JpmcdsLinInterpDoublePoint1(double* x, int xskip, int N, const double* f,
                                int fskip, double xDesired,
                                TMetricDoubleFunc mfunc, double* fInterp) {
  int lo, hi;
  if (JpmcdsBSearchDouble(xDesired, x, xskip, N, &lo, &hi) == FAILURE) {
    JpmcdsErrMsg("JpmcdsLinInterpDoublePoint1: Failed.\n");
    return FAILURE;
  }

  if (lo == hi) {
    *fInterp = ARRAY_ELEMENT(f, lo, fskip, double);
  } else {
    double xLo = ARRAY_ELEMENT(x, lo, xskip, double);
    double xHi = ARRAY_ELEMENT(x, hi, xskip, double);
    double stepFraction = (mfunc == NULL)
                              ? (xDesired - xLo) / (xHi - xLo)
                              : mfunc(xDesired, xLo) / mfunc(xHi, xLo);
    double fLo = ARRAY_ELEMENT(f, lo, fskip, double);
    double fHi = ARRAY_ELEMENT(f, hi, fskip, double);
    *fInterp = fLo + stepFraction * (fHi - fLo);
  }
  return SUCCESS;
}

int JpmcdsLinInterpDoublePoint1Discontinuous(double* x, int xskip, int N,
                                             const double* f, int fskip,
                                             double xDesired,
                                             TMetricDoubleFunc mfunc,
                                             int rightLimit, double* fInterp) {
  int checkOrder = JpmcdsBSearchCheckOrder(FALSE);
  for (int idx = 0; idx < N - 1; ++idx) {
    double xCurr = ARRAY_ELEMENT(x, idx, xskip, double);
    double xNext = ARRAY_ELEMENT(x, idx + 1, xskip, double);
    if (xCurr > xNext) {
      JpmcdsErrMsg(
          "JpmcdsLinInterpDoublePoint1Discontinuous: "
          "Domain array element %d (%f) < element %d (%f).\n",
          idx + 1, xNext, idx, xCurr);
      JpmcdsBSearchCheckOrder(checkOrder);
      return FAILURE;
    }
  }

  int lo, hi;
  if (JpmcdsBSearchDouble(xDesired, x, xskip, N, &lo, &hi) == FAILURE) {
    JpmcdsBSearchCheckOrder(checkOrder);
    JpmcdsErrMsg("JpmcdsLinInterpDoublePoint1Discontinuous: Failed.\n");
    return FAILURE;
  }

  if (lo == hi) {
    *fInterp = ARRAY_ELEMENT(f, lo, fskip, double);
  } else if (xDesired != ARRAY_ELEMENT(x, lo, xskip, double)) {
    double xLo = ARRAY_ELEMENT(x, lo, xskip, double);
    double xHi = ARRAY_ELEMENT(x, hi, xskip, double);
    double stepFraction = (mfunc == NULL)
                              ? (xDesired - xLo) / (xHi - xLo)
                              : mfunc(xDesired, xLo) / mfunc(xHi, xLo);
    double fLo = ARRAY_ELEMENT(f, lo, fskip, double);
    double fHi = ARRAY_ELEMENT(f, hi, fskip, double);
    *fInterp = fLo + stepFraction * (fHi - fLo);
  } else {
    while (lo > 0 && ARRAY_ELEMENT(x, lo, xskip, double) ==
                         ARRAY_ELEMENT(x, lo - 1, xskip, double)) {
      lo--;
    }
    while (hi < N - 1 && ARRAY_ELEMENT(x, hi + 1, xskip, double) ==
                             ARRAY_ELEMENT(x, lo, xskip, double)) {
      hi++;
    }
    if (hi - lo >= 2) {
      *fInterp = ARRAY_ELEMENT(f, (hi + lo) / 2, fskip, double);
    } else if (rightLimit) {
      *fInterp = ARRAY_ELEMENT(f, hi, fskip, double);
    } else {
      *fInterp = ARRAY_ELEMENT(f, lo, fskip, double);
    }
  }
  JpmcdsBSearchCheckOrder(checkOrder);
  return SUCCESS;
}
