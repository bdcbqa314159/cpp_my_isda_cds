#pragma once
#ifndef COMMONDEFS_HPP
#define COMMONDEFS_HPP

#include "code_cpp.hpp"

EXPORT_C {
  // from cdate.hpp
  //   typedef long int TDate;

  //   /*
  //    * (double) value of TDate with any fractional part
  //    * being a fraction of elapsed day.
  //    */
  //   typedef double TDateTime;

  // /* Date constants */
  // #define MAX_DAYS_PER_MONTH 31
  // #define JPMCDS_MONTHS_PER_YEAR 12
  // #define JPMCDS_MONTHS_PER_SEMI 6
  // #define JPMCDS_MONTHS_PER_QUARTER 3
  // #define JPMCDS_DAYS_PER_WEEK 7
  // #define JPMCDS_DAYS_PER_YEAR 365
  // #define JPMCDS_YEARS_PER_DAY (1. / 365.)
  // #define JPMCDS_DAYS_PER_LUNAR_MONTH 28
  // #define JPMCDS_WEEKS_PER_LUNAR_MONTH 4

  // from busday.hpp

  /* Bad Day conventions
   */
#define JPMCDS_BAD_DAY_FOLLOW ((long)'F')   /* Use following good day */
#define JPMCDS_BAD_DAY_PREVIOUS ((long)'P') /* Use previous good day */
#define JPMCDS_BAD_DAY_NONE ((long)'N')     /* Dont check for bad days */
#define JPMCDS_BAD_DAY_MODIFIED ((long)'M') /* Try following, then previous*/
                                            /* if a month boundary is crossed.*/
#define JPMCDS_NUM_BAD_DAY_CONVS 4          /* # bad day conventions */

/*m
***************************************************************************
** Determines whether a day is at a weekend as given by the weekends flag.
***************************************************************************
*/
#define JPMCDS_IS_WEEKEND(date, weekends) ((1 << ((date) % 7)) & (weekends))
#define JPMCDS_IS_WEEKDAY(date, weekends) \
  (!(JPMCDS_IS_WEEKEND((date), (weekends))))
}

#endif /* COMMONDEFS_HPP */