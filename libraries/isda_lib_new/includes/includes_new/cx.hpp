#pragma once
#include "code_cpp.hpp"
#ifndef CX_HPP
#define CX_HPP

#include "bastypes.hpp"  // IWYU pragma: keep

EXPORT_C {
  /** Protection payment convention for CDS in case of default. */
  typedef enum {
    /** Protection payment is due at default */
    PROT_PAY_DEF, /* Default */
    /** Protection payment is only due at the maturity of the protection leg. */
    PROT_PAY_MAT /* Maturity */
  } TProtPayConv;

  /** Accrual payment convention for CDS in case of default. */
  typedef enum {
    /** No accrual in case of default. */
    ACCRUAL_PAY_NONE, /* None */
    /** Interest since the last accrual date is due in case of default. */
    ACCRUAL_PAY_ALL /* All */
  } TAccrualPayConv;

  /** Contingent leg (a.k.a. protection leg). Defines notional amount and
      protection start and end dates. */
  typedef struct _TContingentLeg {
    /** Start date of protection. You are protected from the end of this date.
     */
    TDate startDate;
    /** End date of protection. */
    TDate endDate;
    /** Notional. */
    double notional;
    TProtPayConv payType;
    /** if TRUE, startDate -= 1  */
    TBoolean protectStart;
  } TContingentLeg;

  /** Fee leg with fixed payments. */
  typedef struct _TFeeLeg {
    /** Defines array size for accStartDates, accEndDates, payDates, notionals,
     * couponRates. */
    int nbDates;
    /** Array of size nbDates.
        Start date for calculating accrued interest. */
    TDate* accStartDates;
    /** Array of size nbDates.
        End date for calculating accrued interest. */
    TDate* accEndDates;
    /** Array of size nbDates.
        Payment date for each fee payment. */
    TDate* payDates;
    /** Notional */
    double notional;
    /** Coupon rate of fee payment. */
    double couponRate;
    /** Day count convention for computing fee payments and accruals in
        case of default. */
    long dcc;
    /** Determines how accruals are handled in case of default. */
    TAccrualPayConv accrualPayConv;
    /** Denotes whether observation of defaults is at the start of the day
        or the end of the day for the accrual start and end dates. */
    TBoolean obsStartOfDay;
  } TFeeLeg;

  /*f
  ***************************************************************************
  ** Memory allocator for TFeeLeg
  ***************************************************************************
  */
  TFeeLeg* JpmcdsFeeLegMakeEmpty(
      /** Defines array size for accStartDates, accEndDates, payDates. */
      int nbDates);

  /*
  ***************************************************************************
  ** Constructor for TContingentLeg
  ***************************************************************************
  */
  TContingentLeg* JpmcdsContingentLegMake(TDate startDate,      /* (I) */
                                          TDate endDate,        /* (I) */
                                          double notional,      /* (I) */
                                          TProtPayConv payType, /* (I) */
                                          TBoolean protectStart /* (I) */
  );

  /*f
  ***************************************************************************
  ** Destructor for TFeeLeg
  ***************************************************************************
  */
  void JpmcdsFeeLegFree(TFeeLeg * p);
}

#endif /* CX_HPP */