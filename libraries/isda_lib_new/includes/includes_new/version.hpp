#pragma once
#ifndef VERSION_HPP
#define VERSION_HPP

#include "cgeneral.hpp"
#include "exported.hpp"

EXPORT_C {
  /*
  ***************************************************************************
  ** Return library version number.
  ***************************************************************************
  */
  EXPORTED int JpmcdsVersionString(char*);
}

#endif  // VERSION_HPP