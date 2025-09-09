#pragma once
#ifndef BUSCACHE_HPP
#define BUSCACHE_HPP

#include "cdate.hpp"
#include "cgeneral.hpp"  // IWYU pragma: keep
#include "code_cpp.hpp"

EXPORT_C {
  /*t
  ***************************************************************************
  ** Contains holiday dates and a series of flags that indicate that
  ** particular days of the week are always holidays.
  ***************************************************************************
  */
  struct THolidayList {
    TDateList *dateList; /* date list of holidays */
    long weekends;       /* weekends */
  };

  typedef struct _THolidayCache THolidayCache;

  /*
  ***************************************************************************
  ** This file is broken into two types of functions.
  **
  ** 1. Holiday cache manipulation functions. These are functions that
  **    manipulate the holiday cache but perform no significant analytics.
  **
  ** 2. Holiday list manipulation functions. These are functions that
  **    manipulate the holiday list structure but perform no significant
  **    analytics.
  ***************************************************************************
  */

  /*
  ***************************************************************************
  ** 1. Holiday cache manipulation functions. These are functions that
  **    manipulate the holiday cache but perform no significant analytics.
  ***************************************************************************
  */

  /*f
  ***************************************************************************
  ** The function first checks if the input name is really an encoded
  ** pointer. If it is, the function decodes the pointer and returns
  ** it. Otherwise, it checks whether the name is "NONE" or "NO_WEEKENDS".
  ** If it is either of those, the function returns a pointer to an
  ** appropriate static data structure (for efficiency). If it is
  ** none of the above, then the function searches for the name in the
  ** cache. If it finds the name, it returns a pointer to the cached
  ** holiday list. Otherwise, it interprets the name as a file name
  ** and tries to load the holiday file from disk.
  **
  ** You can use name = "NONE" or name = "NO_WEEKENDS" and the resulting
  ** holiday list will be defined appropriately.
  **
  ** This behaviour exactly duplicates the behaviour when using a holiday
  ** name as an input to any analytics function.
  **
  ** Returns NULL on failure, a valid THolidayList pointer on success.
  ***************************************************************************
  */
  THolidayList *JpmcdsHolidayListFromCache(
      char *name); /* (I) Name associated with the holidays */

  /*f
  ***************************************************************************
  ** Adds a holiday list to the holiday cache. If the entry already exists
  ** in the cache, then the old version will be deleted.
  ***************************************************************************
  */
  int JpmcdsHolidayListAddToCache(
      char *name,      /* (I) Name to associate holidays with */
      THolidayList *hl /* (I) Adds shallow copy */
  );

  /*f
  ***************************************************************************
  ** Empty holiday cache
  ***************************************************************************
  */
  void JpmcdsHolidayEmptyCache(void);

  /*
  ***************************************************************************
  ** 2. Holiday list manipulation functions. These are functions that
  **    manipulate the holiday list structure but perform no significant
  **    analytics.
  ***************************************************************************
  */

  /*f
  ***************************************************************************
  ** Creates a new holiday structure.
  **
  ** The date list can be NULL, in which case the resulting date list in the
  ** holiday structure will be a date list with no dates, e.g.
  **      hl->dateList->fNumItems = 0;
  ***************************************************************************
  */
  THolidayList *JpmcdsHolidayListNewGeneral(
      TDateList * dateList, /* (I) Date list to use */
      long weekends         /* (I) Weekends flag - use JPMCDS_WEEKEND_... */
  );

  /*f
  ***************************************************************************
  ** Deletes a holiday list structure.
  ***************************************************************************
  */
  void JpmcdsHolidayListDelete(THolidayList *
                               hl); /* (I) Holiday list to delete */

  /*f
  ***************************************************************************
  ** Reads a holiday file into memory as a holiday list.
  **
  ** Structure of holiday file, ascii text file of lines like:
  **     #            - commment (blank lines are also skipped)
  **     19631026     - means 10/26/1963 is a holiday
  **     # SATURDAY_NOT_ALWAYS_HOLIDAY  - sets "saturday isn't always a holiday"
  **     # SUNDAY_NOT_ALWAYS_HOLIDAY    - sets "sunday isn't always a holiday"
  **     # MONDAY_ALWAYS_HOLIDAY        - sets "monday as always a holiday"
  **     # TUESDAY_ALWAYS_HOLIDAY       - sets "tuesday as always a holiday"
  **     # WEDNESDAY_ALWAYS_HOLIDAY     - sets "wednesday as always a holiday"
  **     # THURDSAY_ALWAYS_HOLIDAY      - sets "thursday as always a holiday"
  **     # FRIDAY_ALWAYS_HOLIDAY        - sets "friday as always a holiday"
  **
  ** Dates must be in increasing order.
  ***************************************************************************
  */
  THolidayList *JpmcdsHolidayListRead(
      char *fileName /* (I) Name of file to read (may differ) */
  );
}

#endif /* BUSCACHE_HPP */