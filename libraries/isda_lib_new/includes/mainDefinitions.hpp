#pragma once
#ifndef MAINDEFINITIONS_HPP
#define MAINDEFINITIONS_HPP

#include <cstdint>

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

  /*
  ** These constants define flags for determining whether a day is a weekend
  ** or not. This is to cope with countries for which weekends fall on Fridays
  ** and Saturdays etc.
  **
  ** Note the holiday file "NONE" corresponds to an empty date list and
  ** JPMCDS_WEEKEND_STANDARD, whereas the holiday file "NO_WEEKENDS"
  *corresponds
  ** to an empty date list and JPMCDS_WEEKEND_NO_WEEKENDS.
  **
  ** By default when reading holidays from file, the weekend status will be
  ** JPMCDS_WEEKEND_STANDARD unless specifically over-ridden.
  */
  constexpr unsigned int JPMCDS_WEEKEND_MONDAY = 0x0001;
  constexpr unsigned int JPMCDS_WEEKEND_TUESDAY = 0x0002;
  constexpr unsigned int JPMCDS_WEEKEND_WEDNESDAY = 0x0004;
  constexpr unsigned int JPMCDS_WEEKEND_THURSDAY = 0x0008;
  constexpr unsigned int JPMCDS_WEEKEND_FRIDAY = 0x0010;
  constexpr unsigned int JPMCDS_WEEKEND_SATURDAY = 0x0020;
  constexpr unsigned int JPMCDS_WEEKEND_SUNDAY = 0x0040;
  constexpr unsigned int JPMCDS_WEEKEND_NO_WEEKENDS = 0x0000;
  constexpr unsigned int JPMCDS_WEEKEND_STANDARD =
      JPMCDS_WEEKEND_SATURDAY | JPMCDS_WEEKEND_SUNDAY;

  /*m
   ***************************************************************************
   ** Determines whether a day is at a weekend as given by the weekends flag.
   ***************************************************************************
   */

  constexpr bool JpmcdsIsWeekend(int date, uint32_t weekends) {
    return (1U << (static_cast<unsigned int>(date) % 7)) & weekends;
  }

  constexpr bool JpmcdsIsWeekday(int date, uint32_t weekends) {
    return !JpmcdsIsWeekend(date, weekends);
  }

  // Deprecated fallbacks (for old macro calls)
  [[deprecated("Use Jpmcds::IsWeekend instead")]]
  inline bool JPMCDS_IS_WEEKEND(int date, uint32_t weekends) {
    return JpmcdsIsWeekend(date, weekends);
  }

  [[deprecated("Use Jpmcds::IsWeekday instead")]]
  inline bool JPMCDS_IS_WEEKDAY(int date, uint32_t weekends) {
    return JpmcdsIsWeekday(date, weekends);
  }
}

#endif