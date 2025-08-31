#pragma once
#ifndef YEARFRAC_HPP
#define YEARFRAC_HPP

#include <stdio.h>
#include <stdlib.h>

#include "metric.hpp"  // IWYU pragma: keep

EXPORT_C {
  /*f
  ***************************************************************************
  ** Returns metric function to use for interpolation routines for a given
  ** day count convention.
  ***************************************************************************
  */
  TMetricDoubleFunc JpmcdsDayCountToMetricFunc(long dayCountConv);

  /*f
  ***************************************************************************
  ** Maps day count conventions to (private) strings.
  ***************************************************************************
  */
  char *JpmcdsFormatDayCountConv(long dayCountConv);

  /*f
  ***************************************************************************
  ** Converts String to Day Count Convention.
  **
  ** This function is fairly permissive in terms of what it will accept.
  ** For example, "Actual/360", "A", etc.
  ** Strings of the form "30/Actual" are disallowed, however.
  ***************************************************************************
  */
  int JpmcdsStringToDayCountConv(char *dayCountString, long *type);

  /*f
  ***************************************************************************
  ** Returns SUCCESS if day count convention is valid, FAILURE otherwise.
  **
  ** If routine != NULL, then populates the error log on FAILURE. Otherwise
  ** if routine IS NULL, then the error log is not populated on FAILURE.
  ***************************************************************************
  */
  int JpmcdsDayCountValid(char *routine, long dayCountConv);
}

#endif  // YEARFRAC_HPP