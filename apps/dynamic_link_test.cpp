#include <iostream>

#include "dl_loader"       // IWYU pragma: keep
#include "my_dynamic_lib"  // IWYU pragma: keep

int main() {
  std::cout << "working with dynamic loading...\n";

  dlloader::DLLoader<MyLibraryFunctions> my_library_loader(
      LIBRARY_NAME, "allocator", "deallocator");

  my_library_loader.DLOpenLib();

  std::shared_ptr<MyLibraryFunctions> my_library_functions =
      my_library_loader.DLGetInstance();

  std::cout << my_library_functions->my_library() << std::endl;
  std::cout << "simple_addition(1.0, 2.0) = "
            << my_library_functions->simple_addition(1.0, 2.0) << std::endl;
  std::cout << "simple_multiplication(1.0, 2.0) = "
            << my_library_functions->simple_multiplication(1.0, 2.0)
            << std::endl;

  return 0;
}