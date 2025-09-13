/*
 * ISDA CDS Standard Model
 *
 * Copyright (C) 2009 International Swaps and Derivatives Association, Inc.
 * Developed and supported in collaboration with Markit
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the ISDA CDS Standard Model Public License.
 */

#define STR(x) #x
#define STRING(x) STR(x)

// /* Define ONE-dimension routine for LONG arguments
// #define ARRAY_ROUTINE_NAME JpmcdsLinInterpLongArray1
// #define POINT_ROUTINE_NAME JpmcdsLinInterpLongPoint1
// #define DISCONTINUOUS_POINT_ROUTINE_NAME
// JpmcdsLinInterpLongPoint1Discontinuous #define SEARCH_ROUTINE_NAME
// JpmcdsBSearchLong #define ARG_TYPE long #include "lintrp1.inc" #undef
// ARRAY_ROUTINE_NAME #undef POINT_ROUTINE_NAME #undef
// DISCONTINUOUS_POINT_ROUTINE_NAME #undef SEARCH_ROUTINE_NAME #undef ARG_TYPE

#include <stddef.h>  // For size_t

// Function pointer type for metric functions
typedef double (*TMetricDoubleFunc)(double, double);

// Declare routines for each type (e.g., long, double)
int JpmcdsLinInterpLongArray1(long* x, int xskip, int N, const double* f,
                              int fskip, const long* xDesired, int dskip,
                              int numInterps, TMetricDoubleFunc mfunc,
                              int oskip, double* fInterp);

int JpmcdsLinInterpLongPoint1(long* x, int xskip, int N, const double* f,
                              int fskip, double xDesired,
                              TMetricDoubleFunc mfunc, double* fInterp);

int JpmcdsLinInterpLongPoint1Discontinuous(long* x, int xskip, int N,
                                           const double* f, int fskip,
                                           double xDesired,
                                           TMetricDoubleFunc mfunc,
                                           int rightLimit, double* fInterp);

int JpmcdsLinInterpDoubleArray1(double* x, int xskip, int N, const double* f,
                                int fskip, const double* xDesired, int dskip,
                                int numInterps, TMetricDoubleFunc mfunc,
                                int oskip, double* fInterp);

int JpmcdsLinInterpDoublePoint1(double* x, int xskip, int N, const double* f,
                                int fskip, double xDesired,
                                TMetricDoubleFunc mfunc, double* fInterp);

int JpmcdsLinInterpDoublePoint1Discontinuous(double* x, int xskip, int N,
                                             const double* f, int fskip,
                                             double xDesired,
                                             TMetricDoubleFunc mfunc,
                                             int rightLimit, double* fInterp);
