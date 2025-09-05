#pragma once

#ifndef FEELEG_HPP
#define FEELEG_HPP

#include "cx.hpp"

/*f
***************************************************************************
** Calculates the PV of a fee leg with fixed fee payments.
***************************************************************************
*/
int JpmcdsFeeLegPV(TFeeLeg *fl, TDate today, TDate stepinDate, TDate valueDate,
                   TCurve *discCurve, TCurve *spreadCurve,
                   TBoolean payAccruedAtStart, double *pv);

/*f
***************************************************************************
** Calculates the PV of the accruals which occur on default with delay.
***************************************************************************
*/
int JpmcdsAccrualOnDefaultPVWithTimeLine(TDate today, TDate stepinDate,
                                         TDate startDate, TDate endDate,
                                         double amount, TCurve *discCurve,
                                         TCurve *spreadCurve, TDateList *tl,
                                         double *pv);

/*f
***************************************************************************
** Computes the non-contingent cash flows for a fee leg.
***************************************************************************
*/
TCashFlowList *JpmcdsFeeLegFlows(TFeeLeg *fl);

#endif  // FEELEG_HPP