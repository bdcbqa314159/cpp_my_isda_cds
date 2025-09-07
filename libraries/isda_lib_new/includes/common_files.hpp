#pragma once
#ifndef COMMON_FILES_HPP
#define COMMON_FILES_HPP
#include "cgeneral.hpp"  // IWYU pragma: keep
#include "code_cpp.hpp"

EXPORT_C {
  struct TFile {
    void *fileP;
    char *filename;
    int type;
    char *charPtr;
    int size;
    int curSize;
    int lastChar;         /* Make this int instead of char */
    TBoolean hasLastChar; /* to avoid problems with char/int */
    int stringBufSize;    /* conversion. */
  };

  enum TMODE {
    JPMCDS_FWRITE = 1,
    JPMCDS_APPEND = 2,
    JPMCDS_FREAD = 3,
    JPMCDS_FAPPEND = 4
  };
}

#endif  // COMMON_FILES_HPP