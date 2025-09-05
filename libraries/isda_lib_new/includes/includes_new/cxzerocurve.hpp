#pragma once
#ifndef CXZEROCURVE_HPP
#define CXZEROCURVE_HPP

#include "tcurve.hpp"

EXPORT_C {
  /*f
  ***************************************************************************
  ** Calculates the zero price for a given date. Returns NaN for errors.
  ***************************************************************************
  */
  EXPORTED double JpmcdsZeroPrice(TCurve * zeroCurve, TDate date);

  /*f
  ***************************************************************************
  ** Calculates the zero price for a given start date and maturity date.
  ** Returns NaN for errors.
  ***************************************************************************
  */
  double JpmcdsForwardZeroPrice(TCurve * zeroCurve, TDate startDate,
                                TDate maturityDate);

  /*f
  ***************************************************************************
  ** Calculates the zero rate for a given date using ACT/365F and continously
  ** compounded rates.
  ***************************************************************************
  */
  double JpmcdsZeroRate(TCurve * zeroCurve, TDate date);

  /*f
  ***************************************************************************
  ** Converts a compound rate from one frequency to another.
  ** Can also convert between ACT-style day count conventions.
  ***************************************************************************
  */
  int JpmcdsConvertCompoundRate(double inRate, double inBasis,
                                long inDayCountConv, double outBasis,
                                long outDayCountConv, double *outRate);
}

#endif  // CXZEROCURVE_HPP
