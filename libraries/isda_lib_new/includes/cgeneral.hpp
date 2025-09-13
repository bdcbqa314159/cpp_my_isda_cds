#pragma once
#ifndef CGENERAL_HPP
#define CGENERAL_HPP

#include <stdio.h>
#include <stdlib.h>

#include "code_cpp.hpp"

EXPORT_C {
  using TBoolean = int;

  constexpr int TRUE = 1;
  constexpr int FALSE = 0;
  constexpr int SUCCESS = 0;
  constexpr int FAILURE = -1;

  /* This special value means one of three things:  "use the default value",
     "this value does not exist", or "it doesn't matter what this value is".
     This symbol must be set to a negative number, although it need not be
     set to -1. */
  constexpr int JPMCDS_DEFAULT = -1;
}

#endif  // CGENERAL_HPP