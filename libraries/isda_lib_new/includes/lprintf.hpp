#pragma once

#ifndef LPRINTF_HPP
#define LPRINTF_HPP

#include <stdarg.h>

#include "cfileio.hpp"
#include "cgeneral.hpp"  // IWYU pragma: keep

EXPORT_C {
  /*f
   *******************************************************************************
   ** vprintf functionality using a TFile
   *******************************************************************************
   */
  int JpmcdsVfprintf(TFile * tFile, char *fmt, va_list arg);
}

#endif  // LPRINTF_HPP