#pragma once
#ifndef MAINDEFINITIONS_HPP
#define MAINDEFINITIONS_HPP

#include "code_cpp.hpp"

EXPORT_C {
  /* Date constants */
  constexpr int MAX_DAYS_PER_MONTH = 31;
  constexpr int JPMCDS_MONTHS_PER_YEAR = 12;
  constexpr int JPMCDS_MONTHS_PER_SEMI = 6;
  constexpr int JPMCDS_MONTHS_PER_QUARTER = 3;
  constexpr int JPMCDS_DAYS_PER_WEEK = 7;
  constexpr int JPMCDS_DAYS_PER_YEAR = 365;
  constexpr double JPMCDS_YEARS_PER_DAY = 1. / 365;
  constexpr int JPMCDS_DAYS_PER_LUNAR_MONTH = 28;
  constexpr int JPMCDS_WEEKS_PER_LUNAR_MONTH = 4;

  /*t
   * TDateAdjIntvl is a time interval expressed in business
   * or calendar days or week days.
   */
  constexpr int JPMCDS_DATE_ADJ_TYPE_CALENDAR = 0;
  constexpr int JPMCDS_DATE_ADJ_TYPE_BUSINESS = 1;
  constexpr int JPMCDS_DATE_ADJ_TYPE_WEEKDAY = 2;

  /* Bad Day conventions
   */
  constexpr long JPMCDS_BAD_DAY_FOLLOW =
      static_cast<long>('F'); /* Use following good day */
  constexpr long JPMCDS_BAD_DAY_PREVIOUS =
      static_cast<long>('P'); /* Use previous good day */
  constexpr long JPMCDS_BAD_DAY_NONE =
      static_cast<long>('N'); /* Dont check for bad days */
  constexpr long JPMCDS_BAD_DAY_MODIFIED =
      static_cast<long>('M'); /* Try following, then previous*/
                              /* if a month boundary is crossed.*/
  constexpr long JPMCDS_NUM_BAD_DAY_CONVS = 4; /* # bad day conventions */
}

#endif