#pragma once

#ifndef ZEROCURVE_HPP
#define ZEROCURVE_HPP

#include "bastypes.hpp"
#include "exported.hpp"

EXPORT_C {
  /*f
  ***************************************************************************
  ** Build zero curve from money market, and swap instruments.
  ***************************************************************************
  */
  EXPORTED TCurve *JpmcdsBuildIRZeroCurve(
      TDate valueDate,    /* (I) Value date                       */
      char *instrNames,   /* (I) Array of 'M' or 'S'              */
      TDate *dates,       /* (I) Array of swaps dates             */
      double *rates,      /* (I) Array of swap rates              */
      long nInstr,        /* (I) Number of benchmark instruments  */
      long mmDCC,         /* (I) DCC of MM instruments            */
      long fixedSwapFreq, /* (I) Fixed leg freqency               */
      long floatSwapFreq, /* (I) Floating leg freqency            */
      long fixedSwapDCC,  /* (I) DCC of fixed leg                 */
      long floatSwapDCC,  /* (I) DCC of floating leg              */
      long badDayConv,    /* (I) Bad day convention               */
      char *holidayFile); /* (I) Holiday file                     */
}

#endif  // ZEROCURVE_HPP