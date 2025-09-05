#pragma once

#ifndef TIMELINE_HPP
#define TIMELINE_HPP

#include "cx.hpp"

EXPORT_C {
  /*f
  ***************************************************************************
  ** Returns a timeline for use with risky integrations assuming flat
  ** forward curves.
  **
  ** The timeline will contain the following dates:
  ** - startDate
  ** - endDate
  ** - all the points in the discount curve
  ** - all the points in the risky curve
  ** - nothing before startDate
  ** - nothing after endDate
  ***************************************************************************
  */
  TDateList* JpmcdsRiskyTimeLine(TDate startDate, TDate endDate,
                                 TCurve * discCurve, TCurve * riskyCurve);

  /*f
  ***************************************************************************
  ** Truncate timeline.
  **
  ** Truncates a timeline so that it will contain the following:
  ** - startDate
  ** - endDate
  ** - criticalDates (can be NULL)
  ** - nothing before startDate
  ** - nothing after endDate
  ***************************************************************************
  */
  TDateList* JpmcdsTruncateTimeLine(TDateList * criticalDates, TDate startDate,
                                    TDate endDate);
}

#endif  // TIMELINE_HPP