#pragma once

#include "code_cpp.hpp"
#ifndef GTOZC_HPP
#define GTOZC_HPP

#include "bastypes.hpp"
#include "stub.hpp"
// #include "cheaders.hpp"
// #include "ldate.hpp"
// #include "tcurve.hpp"

EXPORT_C {
  /*f
  ***************************************************************************
  ** Adds cash points to a given zero curve.
  ***************************************************************************
  */
  TCurve *JpmcdsZCCash(TCurve * zeroCurve, /* (I) Zero curve to add to */
                       TDate * dates, /* (I) Array of cash dates             */
                       double *rates, /* (I) Array of cash rates (0.06 for 6%)*/
                       int numRates,  /* (I) Number of cash rates to add     */
                       long dayCountConv); /* (I) See JpmcdsDayCountFraction */

  /*f
  ***************************************************************************
  ** Adds swap points to a given zero curve.
  ***************************************************************************
  */
  TCurve *JpmcdsZCSwaps(
      TCurve * zeroCurve,     /* (I) Zero curve to add swap points to*/
      TCurve * discZC,        /* (I) Zero curve used for discounting */
      TDate * dates,          /* (I) Unadjusted swap maturity dates  */
      double *rates,          /* (I) Swap par fixed rates (0.06=6%)  */
      int numSwaps,           /* (I) Len of dates,rates,prices       */
      int fixedSwapFreq,      /* (I) Fixed leg coupon frequency      */
      int floatSwapFreq,      /* (I) Floating leg coupon frequency   */
      long fixDayCountConv,   /* (I) See JpmcdsDayCountConvention       */
      long floatDayCountConv, /* (I) See JpmcdsDayCountConvention       */
      char fwdLength,         /* (I) For fwd smoothing, length of fwds*/
      TBadDayAndStubPos badDayAndStubPos, /* (I) Bad day conv + stub pos */
      char *holidayFile); /* (I) See JpmcdsBusinessDay              */
}

#endif  // GTOZC_HPP