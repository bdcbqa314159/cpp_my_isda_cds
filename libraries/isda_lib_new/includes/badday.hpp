/*
 * ISDA CDS Standard Model
 *
 * Copyright (C) 2009 International Swaps and Derivatives Association, Inc.
 * Developed and supported in collaboration with Markit
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the ISDA CDS Standard Model Public License.
 *
 * -------------------------------------------------------------------
 * Modified by: Bernardo David Cohen Beraun, 2025
 * Description: Refactored from C to C++. Just because is fun ;-).
 * -------------------------------------------------------------------
 */

#ifndef BADDAY_H
#define BADDAY_H

#include "cdate.hpp"
#include "code_cpp.hpp"

EXPORT_C {
  struct TBadDayList { /* Bad day list */
    int count;         /* number of items currently in list */
    int maxAllowed;    /* max no of items allowed in arrays */
    TDate *badDay;     /* array of bad business days */
    TDate *goodDay;    /* array of corresponding good ays */
  };

  /*f
  ***************************************************************************
  ** This function converts a bad day to a good one (if it's in list).
  ***************************************************************************
  */
  TDate JpmcdsBad2GoodBadDayList(TBadDayList * bdl, /* (I) bad day list */
                                 long d); /* (I) bad date to convert */

  /*f
  ***************************************************************************
  ** This function converts a good day to a bad one (if it's in list).
  ***************************************************************************
  */
  TDate JpmcdsGood2BadBadDayList(TBadDayList * bdl, /* (I) bad day list */
                                 long d); /* (I) bad date to convert */

  /*f
  ***************************************************************************
  ** This function converts bad dates in a date list to good ones based on a
  ** BadDayList.  DateList passed in is MODIFIED to contain "good" dates.
  ***************************************************************************
  */
  void JpmcdsFixBadDLBadDayList(TBadDayList * bdl, /* (I) bad day list */
                                TDateList * dl); /* (M) date list to convert */
}

#endif /* BADDAY_H */
