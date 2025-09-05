#pragma once

#ifndef ZR2COUP_HPP
#define ZR2COUP_HPP

#include "bastypes.hpp"
#include "cashflow.hpp"
#include "interp.hpp"
#include "ldate.hpp"

EXPORT_C {
  /*f
  ***************************************************************************
  ** A convenience function for JpmcdsZerosToCouponsPointAdj with no bad-day
  ** adjustment.
  **
  ** Calls JpmcdsZerosToCouponsPoint with badDayConv = JPMCDS_BAD_DAY_NONE.
  ***************************************************************************
  */
  int JpmcdsZerosToCouponsPoint(
      TCurve * zc,             /* (I) Zero-coupon rate curve */
      long interpType,         /* (I) */
      TDate startDate,         /* (I) Date instrument begins at */
      TDateInterval *interval, /* (I) Time between payments */
      TDate maturityDate,      /* (I) Date instrument matures at*/
      long fixedDayCountConv,  /* (I) See JpmcdsDayCountFraction */
      TBoolean stubAtEnd,      /* (I) TRUE=Back, FALSE=Front*/
      double *couponRate);     /* (O) Rate for this instrument */

  /*f
  ***************************************************************************
  ** Calculates a par swap rate for the swap starting at startDate,
  ** maturing at maturityDate, with fixed day count convention
  ** fixedDayCountConv and fixed payments occuring at time
  ** intervals defined by interval. In other words, the routine calculates
  ** the fixed rate such that the present value of the fixed and
  ** floating sides are equal. The floating side is assumed to be at par.
  **
  ** Bad day adjustment is performed on the startDate, maturityDate,
  ** and all fixed coupon payment dates.
  **
  ** The arguments stubType and stubAtEnd only have an effect if
  ** startDate and maturityDate are not on cycle.
  ***************************************************************************
  */
  int JpmcdsZerosToCouponsPointAdj(
      TCurve * zc,             /* (I) Zero-coupon rate curve */
      long interpType,         /* (I) */
      TDate startDate,         /* (I) Date instrument begins at */
      TDateInterval *interval, /* (I) Time between payments */
      TDate maturityDate,      /* (I) Date instrument matures at*/
      long fixedDayCountConv,  /* (I) See JpmcdsDayCountFraction */
      TBoolean stubAtEnd,      /* (I) TRUE=Back, FALSE=Front*/
      long accBadDayConv,      /* (I) See JpmcdsBusinessDay for methods*/
      long payBadDayConv,      /* (I) See JpmcdsBusinessDay for methods*/
      char *holidayFile,       /* (I) Used to adjust swap dates */
      double *couponRate);     /* (O) Rate for this instrument */
}

#endif  // ZR2COUP_HPP