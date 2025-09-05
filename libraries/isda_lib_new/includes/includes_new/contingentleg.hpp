#pragma once
#ifndef CONTINGENTLEG_HPP
#define CONTINGENTLEG_HPP

#include "cx.hpp"

EXPORT_C {
  /*f
   ***************************************************************************
   ** Computes the PV of a contingent leg as a whole.
   **
   ** For each payment period this is the integral of LGD(t) . Z(t) . dS/dt dt
   ** where S is the survival function and LGD is the loss given default
   ** function and Z is the discount function. Discounting is calculated at the
   ** payment date and not at the observation date.
   ***************************************************************************
   */
  int JpmcdsContingentLegPV(
      TContingentLeg * cl,    /* (I) Contingent leg                  */
      TDate today,            /* (I) No observations before today    */
      TDate valueDate,        /* (I) Value date for discounting      */
      TDate stepinDate,       /* (I) Step-in date                    */
      TCurve * discountCurve, /* (I) Risk-free curve                 */
      TCurve * spreadCurve,   /* (I) Spread curve                    */
      double recoveryRate,    /* (I) Recovery rate                   */
      double *pv);            /* (O) Present value of contingent leg */
}

#endif  // CONTINGENTLEG_HPP