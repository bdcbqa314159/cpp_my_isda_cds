project(my_static_lib)

set(includes includes/)
set(sources src/common_functions.cpp)

add_library(${PROJECT_NAME} ${sources})
target_include_directories(${PROJECT_NAME} PUBLIC ${includes} ${common_includes_dir})