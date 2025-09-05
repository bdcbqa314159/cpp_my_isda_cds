#pragma once

#ifndef FLTRATE_HPP
#define FLTRATE_HPP

#include "bastypes.hpp"
// #include "cgeneral.hpp"
// #include "interp.hpp"

EXPORT_C {
  /*f
   ***************************************************************************
   ** Sets a TFloatRate.
   ***************************************************************************
   */
  int JpmcdsFloatRateSet(
      TDateInterval * matInterval, /* (I) */
      TDateInterval * payInterval, /* (I) */
      long dayCountConv,           /* (I) */
      long spotOffsetDays,         /* (I) */
      double spread,               /* (I) */
      double weight,               /* (I) */
      TFloatRate *floatRate);      /* (O) Floating rate definition */
}

#endif  // FLTRATE_HPP