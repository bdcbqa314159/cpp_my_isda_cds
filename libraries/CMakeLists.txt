project(libraries)

set(common_includes_dir ${CMAKE_CURRENT_SOURCE_DIR}/common/)

add_subdirectory(my_static_lib)
add_subdirectory(my_dynamic_lib)
