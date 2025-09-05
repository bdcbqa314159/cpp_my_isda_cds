#pragma once
#ifndef DEFAULTED_HPP
#define DEFAULTED_HPP

#include "cdate.hpp"
#include "exported.hpp"
#include "stub.hpp"

EXPORT_C {
  /*f
   */
  EXPORTED int JpmcdsDefaultAccrual(
      TDate tradeDate, TDate edd, TDate startDate, TDate endDate,
      TDateInterval * couponInterval, TStubMethod * stubType, double notional,
      double couponRate, long paymentDcc, long badDayConv, char *calendar,
      double *accrualDays, double *defaultAccrual);

  EXPORTED int test(double *testvar);
}

#endif  // DEFAULTED_HPP