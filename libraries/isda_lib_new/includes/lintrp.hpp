#pragma once

#include "code_cpp.hpp"
#ifndef LINTRP_HPP
#define LINTRP_HPP

#include "cgeneral.hpp"
#include "metric.hpp"

EXPORT_C {
  int JpmcdsLinInterpLongPoint1(
      long *x,                 /* (I) Ordered Array of X values */
      int xskip,               /* (I) # bytes between x values */
      int N,                   /* (I) Length of X & F arrays */
      double *f,               /* (I) Ordered Array of F values */
      int fskip,               /* (I) # bytes between f values */
      double xDesired,         /* (I) X for which F is desired */
      TMetricDoubleFunc mfunc, /* (I) Metric Function */
      double *fInterp);        /* (O) Interpolated value */

  int JpmcdsLinInterpLongArray1(
      long *x,                 /* (I) Ordered Array of X values */
      int xskip,               /* (I) # bytes between x values */
      int N,                   /* (I) Length of X & F arrays */
      double *f,               /* (I) Ordered Array of F values */
      int fskip,               /* (I) # bytes between f values */
      long *xDesired,          /* (I) Unordered array desired x */
      int dskip,               /* (I) # bytes between xDesired vals */
      int numInterps,          /* (I) Length of xDesired & yInterp */
      TMetricDoubleFunc mfunc, /* (I) Metric Function */
      int oskip,               /* (I) # bytes between fInterp vals */
      double *fInterp);        /* (O) Interpolated F values */
}

#endif  // LINTRP_HPP