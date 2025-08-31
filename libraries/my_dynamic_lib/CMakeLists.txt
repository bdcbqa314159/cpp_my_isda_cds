project(my_dynamic_lib)

set(includes includes/)
set(sources src/functions_api.cpp)

add_library(${PROJECT_NAME} SHARED ${sources})
target_include_directories(${PROJECT_NAME} PUBLIC ${includes} ${common_includes_dir})