#pragma once
#ifndef CGENERAL_HPP
#define CGENERAL_HPP

#include <stdio.h>
#include <stdlib.h>

#include "code_cpp.hpp"
// #include "exported.hpp"

EXPORT_C {
  typedef int TBoolean;

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

#ifndef SUCCESS
#define SUCCESS 0
#endif

#ifndef FAILURE
#define FAILURE -1
#endif

/* This special value means one of three things:  "use the default value",
   "this value does not exist", or "it doesn't matter what this value is".
   This symbol must be set to a negative number, although it need not be
   set to -1. */
#ifndef JPMCDS_DEFAULT
#define JPMCDS_DEFAULT -1
#endif
}

#endif  // CGENERAL_HPP