#pragma once
#ifndef MY_LIBRARY_FUNCTIONS_API_HPP
#define MY_LIBRARY_FUNCTIONS_API_HPP

#include <string>

#include "code_cpp.hpp"
#include "exported.hpp"

class EXPORTED MyLibraryFunctions {
 public:
  MyLibraryFunctions() = default;
  ~MyLibraryFunctions() = default;

  double simple_addition(double a, double b);

  double simple_multiplication(double a, double b);

  std::string my_library();
};

EXPORT_C {
  EXPORTED MyLibraryFunctions *allocator();

  EXPORTED void deallocator(MyLibraryFunctions * ptr);
}

#endif  // MY_LIBRARY_FUNCTIONS_API_HPP