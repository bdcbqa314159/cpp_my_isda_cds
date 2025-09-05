#pragma once
#ifndef MDYDATE_HPP
#define MDYDATE_HPP

#include <stdio.h>
#include <stdlib.h>

#include "cdate.hpp"  // IWYU pragma: keep

EXPORT_C {
  typedef struct _TMDYDate {
    long month; /* In range [1,12] */
    long day;   /* In range [1-31] */
    long year;  /* In range [1600-] */
  } TMonthDayYear;
}

#endif  // MDYDATE_HPP