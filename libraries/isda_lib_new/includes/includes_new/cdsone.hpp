#pragma once
#ifndef CDSONE_HPP
#define CDSONE_HPP

// #include "cx.hpp"
#include "bastypes.hpp"
#include "exported.hpp"
#include "stub.hpp"

EXPORT_C {
  /*f
   ***************************************************************************
   ** Computes the upfront charge for a flat spread par curve.
   ***************************************************************************
   */
  EXPORTED int JpmcdsCdsoneUpfrontCharge(
      TDate today, TDate valueDate,
      TDate benchmarkStartDate, /* start date of benchmark CDS for
                                ** internal clean spread bootstrapping */
      TDate stepinDate,
      TDate startDate, /* CDS start date, can be in the past */
      TDate endDate, double couponRate, TBoolean payAccruedOnDefault,
      TDateInterval *dateInterval, TStubMethod *stubType, long accrueDCC,
      long badDayConv, char *calendar, TCurve *discCurve, double oneSpread,
      double recoveryRate, TBoolean payAccruedAtStart, double *upfrontCharge);

  /*f
  ***************************************************************************
  ** Computes the flat spread required to match the upfront charge.
  ***************************************************************************
  */
  EXPORTED int JpmcdsCdsoneSpread(
      TDate today, TDate valueDate,
      TDate benchmarkStartDate, /* start date of benchmark CDS for
                                ** internal clean spread bootstrapping */
      TDate stepinDate,
      TDate startDate, /* CDS start date, can be in the past */
      TDate endDate, double couponRate, TBoolean payAccruedOnDefault,
      TDateInterval *dateInterval, TStubMethod *stubType, long accrueDCC,
      long badDayConv, char *calendar, TCurve *discCurve, double upfrontCharge,
      double recoveryRate, TBoolean payAccruedAtStart, double *oneSpread);
}

#endif  // CDSONE_HPP