#pragma once
#ifndef DATEADJ_HPP
#define DATEADJ_HPP

#include "cdate.hpp"
#include "cgeneral.hpp"  // IWYU pragma: keep
#include "code_cpp.hpp"

EXPORT_C {
  /*f
   ***************************************************************************
   ** Calculates a date being at a business or calendar days offset from the
   ** input date.
   ***************************************************************************
   */
  int JpmcdsDtFwdAdj(
      TDate startDate,          /* (I) Input date       */
      TDateAdjIntvl * interval, /* (I) Business days or calendar period  */
      TDate * result);          /* (O) Resulting date   */
}

#endif  // DATEADJ_HPP