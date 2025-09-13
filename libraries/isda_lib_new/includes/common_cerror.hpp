#pragma once

#include "code_cpp.hpp"
#ifndef COMMON_CERROR_HPP
#define COMMON_CERROR_HPP

#include "cerror.hpp"

EXPORT_C {
  inline void ProgramBug(const char* file, int line) {
    Jpmcds::ErrMsg("Program bug: %s line %d\n", file, line);
  }

  // Deprecated function (fallback for old macro calls)
  [[deprecated("Use Jpmcds::ProgramBug(__FILE__, __LINE__) instead")]]
  inline void PROGRAM_BUG(const char* file = __FILE__, int line = __LINE__) {
    ProgramBug(file, line);
  }
}

#endif  // COMMON_CERROR_HPP