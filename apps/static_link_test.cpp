#include <iostream>

#include "my_static_lib"  // IWYU pragma: keep

// This works because the library is statically linked.
// Hence we can use the functions and the EXPORTED / NOT_EXPORTED macros
// are not needed.
// If the library is dynamically linked simple_multiplication would not be
// available here.

int main() {
  std::cout << my_library() << std::endl;

  std::cout << "simple_addition(1.0, 2.0) = " << simple_addition(1.0, 2.0)
            << std::endl;

  std::cout << "simple_multiplication(1.0, 2.0) = "
            << simple_multiplication(1.0, 2.0) << std::endl;

  // MyLibraryFunctions *my_library_functions = allocator();

  // std::cout << my_library_functions->my_library() << std::endl;
  // std::cout << "simple_addition(1.0, 2.0) = "
  //           << my_library_functions->simple_addition(1.0, 2.0) << std::endl;
  // std::cout << "simple_multiplication(1.0, 2.0) = "
  //           << my_library_functions->simple_multiplication(1.0, 2.0)
  //           << std::endl;
  // deallocator(my_library_functions);

  return 0;
}