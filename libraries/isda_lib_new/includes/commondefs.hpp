#pragma once
#ifndef COMMONDEFS_HPP
#define COMMONDEFS_HPP

#include "code_cpp.hpp"

EXPORT_C {
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