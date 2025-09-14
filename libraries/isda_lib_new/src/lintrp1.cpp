/*
 * ISDA CDS Standard Model
 *
 * Copyright (C) 2009 International Swaps and Derivatives Association, Inc.
 * Developed and supported in collaboration with Markit
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the ISDA CDS Standard Model Public License.
 */

#include "bsearch.hpp"
#include "cerror.hpp"
#include "cgeneral.hpp"
#include "lintrp.hpp"

#define STR(x) #x
#define STRING(x) STR(x)

/* Define ONE-dimension routine for LONG arguments
 */
#define ARRAY_ROUTINE_NAME JpmcdsLinInterpLongArray1
#define POINT_ROUTINE_NAME JpmcdsLinInterpLongPoint1
#define DISCONTINUOUS_POINT_ROUTINE_NAME JpmcdsLinInterpLongPoint1Discontinuous
#define SEARCH_ROUTINE_NAME JpmcdsBSearchLong
#define ARG_TYPE long
#include "lintrp1.inc"
#undef ARRAY_ROUTINE_NAME
#undef POINT_ROUTINE_NAME
#undef DISCONTINUOUS_POINT_ROUTINE_NAME
#undef SEARCH_ROUTINE_NAME
#undef ARG_TYPE
