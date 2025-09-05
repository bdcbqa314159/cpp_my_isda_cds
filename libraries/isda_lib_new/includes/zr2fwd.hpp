#pragma once

#ifndef ZR2FWD_HPP
#define ZR2FWD_HPP

#include "bastypes.hpp"
#include "cfinanci.hpp"
#include "interp.hpp"
#include "ldate.hpp"

EXPORT_C {
  /*f
  ***************************************************************************
  ** Computes the zero-coupon forward rate from startDate to the maturity
  ** date using a zero-coupon curve.
  **
  ** Note the routine does not check to make sure that the start date comes
  ** before the maturity date, since zero curve creation requires the
  ** calculation of forwards which go backwards (JpmcdsDiscountToRate should
  ** handle that check anyway).
  ***************************************************************************
  */
  int JpmcdsForwardFromZCurve(
      TCurve * zeroCurve, /* (I) Zero Curve */
      long interpType,    /* (I) */
      TDate startDate,    /* (I) Start Date */
      TDate endDate,      /* (I) End Date */
      long dayCountConv,  /* (I) See JpmcdsDayCountFraction */
      long basis,         /* (I) See JpmcdsDiscountToRate */
      double *rate);      /* (O) Rate from start to end */
}

#endif  // ZR2FWD_HPP