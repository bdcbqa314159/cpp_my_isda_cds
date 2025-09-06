#pragma once
#ifndef CDATE_HPP
#define CDATE_HPP

#include <stdio.h>
#include <stdlib.h>

// #include "cgeneral.hpp"  // IWYU pragma: keep
#include "mainDefinitions.hpp"

EXPORT_C {
  using TDate = long;

  /*
   * (double) value of TDate with any fractional part
   * being a fraction of elapsed day.
   */

  using TDateTime = double;

  /* --------- Definition of a date interval -------------------- */
  struct TDateInterval {
    int prd;      /* number of periods from offset date                  */
    char prd_typ; /* type of periods                                     */
                  /* D - day; M - month; W - week                        */
                  /* Q - 3 months; S - 6 months                          */
                  /* A - 12 months; Y - 12 months                        */
                  /* I - quarterly IMM period                            */
                  /* F - flexible end of month                           */
                  /* E - end of month                                    */
                  /* J - monthly IMM period                              */
                  /* K - quarterly Australian futures period             */
                  /* L - quarterly New Zealand (kiwi) futures period     */
                  /* T - equity derivatives expiry - 3rd Friday monthly  */
                  /* U - Lunar (i.e. 28 Day) period                      */

    int flag; /* 0 - offset is value date
                 -1 - offset is the previous date in the date array
                 x - any other number is index into array of intervals.
                     the date at that location is an offset */

    void setInterval(int periods, char period_type) {
      prd = periods;
      prd_typ = period_type;
      flag = 0;
    }

    bool operator==(const TDateInterval &other) const {
      return (prd == other.prd && prd_typ == other.prd_typ);
    }
  };

// TODO: replace these macros with the methods above
/*
 * SET_TDATE_INTERVAL macro.
 */
#define SET_TDATE_INTERVAL(di, periods, period_type) \
  do {                                               \
    (di).prd = (periods);                            \
    (di).prd_typ = (period_type);                    \
    (di).flag = 0;                                   \
  } while (0)

#define TDATE_INTERVALS_EQUAL(d1, d2) \
  ((d1).prd == (d2).prd && (d1).prd_typ == (d2).prd_typ)
}

/*t
 *  TDateList is a list of dates.
 */

struct TDateList {
  int fNumItems;
  TDate *fArray;
};

/*t
** TDateAdjIntvl is a holiday-adjusted date interval.
**
** Note that isBusDays used to be TBoolean. Now it can have three
** possible values - the third value (JPMCDS_DATE_ADJ_TYPE_WEEKDAY)
** indicates that we move forward a number of weekdays and then
** adjust for bad days.
**
** The interval can be daily based or monthly based. If it is
** monthly based and the isBusDays flag is not calendar, then
** this indicates that business end of month adjustment applies,
** i.e. if the start date is the last business day of the month,
** then the end date is the chosen to be the last day of the month
** (which can subsequently be adjusted via the badDayConv to be
** the last business day of the month, but this is not done
** automatically).
*/

struct TDateAdjIntvl {
  TDateInterval interval; /* Must be in days if isBusDays=T */
  int isBusDays;          /* see JPMCDS_DATE_ADJ_TYPE_... constants */
  char *holidayFile;      /* Holiday file specification */
  long badDayConv;        /* Only applies if isBusDays=F */

  void setAdjIntervalDays(int days) {
    interval.prd = days;
    interval.prd_typ = 'D';
    isBusDays = JPMCDS_DATE_ADJ_TYPE_CALENDAR;
    holidayFile = nullptr;
    badDayConv = JPMCDS_BAD_DAY_NONE;
  }
};

// TODO: replace these macros with the methods above
#define JPMCDS_SET_ADJ_INTERVAL_DAYS(adjIntval, days)  \
  adjIntval.interval.prd = days;                       \
  adjIntval.interval.prd_typ = 'D';                    \
  adjIntval.isBusDays = JPMCDS_DATE_ADJ_TYPE_CALENDAR; \
  adjIntval.holidayFile = NULL;                        \
  adjIntval.badDayConv = JPMCDS_BAD_DAY_NONE;

#endif  // CDATE_HPP