#pragma once

#ifndef DL_LOADER_LIBRARY_NAMES_HPP
#define DL_LOADER_LIBRARY_NAMES_HPP
#include <string>

#ifdef __APPLE__
static const std::string LIBRARY_NAME = "libmy_dynamic_lib.dylib";
#endif

#ifdef __linux__
static const std::string LIBRARY_NAME = "libmy_dynamic_lib.so";
#endif

#ifdef WIN32
static const std::string LIBRARY_NAME = "my_dynamic_lib.dll";
#endif

#endif  // DL_LOADER_LIBRARY_NAMES_HPP