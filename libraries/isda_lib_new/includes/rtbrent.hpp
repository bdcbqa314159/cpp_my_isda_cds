#pragma once

#ifndef RTBRENT_HPP
#define RTBRENT_HPP

#include "cgeneral.hpp"

EXPORT_C {
  typedef int (*TObjectFunc)(double x, void *para, double *f);

  /*f
  ***************************************************************************
  ** Finds the root of f(x) = 0 using a combination of secant, bisection and
  ** an inverse quadratic interpolation method.
  ***************************************************************************
  */
  int JpmcdsRootFindBrent(
      TObjectFunc funcd,    /* (I) function to be solved */
      void *data,           /* (I) data to pass into funcd */
      double boundLo,       /* (I) lower bound on legal X */
      double boundHi,       /* (I) upper bound on legal X */
      int numIterations,    /* (I) Maximum number of iterations */
      double guess,         /* (I) Initial guess */
      double initalXStep,   /* (I) Size of step in x */
      double initialFDeriv, /* (I) Derivative, defaults to 0 */
      double xacc,          /* (I) X accuracy tolerance */
      double facc,          /* (I) function accuracy tolerance */
      double *solution);    /* (O) root found */
}

#endif  // RTBRENT_HPP