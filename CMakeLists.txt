cmake_minimum_required(VERSION 3.30)

project(cpp_my_isda_cds LANGUAGES C CXX)

# set(CMAKE_CXX_STANDARD 20)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)
# set(CMAKE_CXX_EXTENSIONS OFF)

# Handle C standard for Clang vs. other compilers
if("${CMAKE_C_COMPILER_ID}" MATCHES "Clang|AppleClang")
    # Clang: Use GNU89 (C89 + extensions)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=gnu89")
else()
    # Other compilers (e.g., GCC): Use C89
    set(CMAKE_C_STANDARD 89)
    set(CMAKE_C_STANDARD_REQUIRED ON)
endif()

# Set C++ standard to C++17 (for C++ sources)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)  # Disable compiler-specific extensions
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(WIN32)
    message(STATUS "Windows detected")
    set(dlloader_include_dir_platform ${CMAKE_SOURCE_DIR}/dl_loader/windows)
    add_compile_definitions(WIN_EXPORT)
endif()

if(UNIX)
    message(STATUS "Unix system detected")
    set(dlloader_include_dir_platform ${CMAKE_SOURCE_DIR}/dl_loader/linux)
endif()

set(dlloader_include_dir ${CMAKE_SOURCE_DIR}/dl_loader)

MESSAGE(STATUS "the source directory is: ${CMAKE_SOURCE_DIR}")
MESSAGE(STATUS "the binary directory is: ${CMAKE_BINARY_DIR}")

set(CMAKE_INSTALL_PREFIX ${CMAKE_SOURCE_DIR}/install)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(libraries)
add_subdirectory(apps)
