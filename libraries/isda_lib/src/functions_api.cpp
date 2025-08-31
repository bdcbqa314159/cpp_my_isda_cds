#include "functions_api.hpp"

MyLibraryFunctions *allocator() { return new MyLibraryFunctions(); }

void deallocator(MyLibraryFunctions *ptr) { delete ptr; }

double MyLibraryFunctions::simple_addition(double a, double b) { return a + b; }

double MyLibraryFunctions::simple_multiplication(double a, double b) {
  return a * b;
}

std::string MyLibraryFunctions::my_library() {
  return "Hello from my_library!";
}