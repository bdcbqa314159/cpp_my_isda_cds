project(isda_lib_new)

set(includes includes/)
# set(sources src/my_isda_cds_lib.cpp)
file(GLOB SOURCES "src/*.c" "src/*.cpp")


add_library(${PROJECT_NAME} SHARED ${SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC ${includes} ${common_includes_dir})

target_compile_options(${PROJECT_NAME} PRIVATE
    $<$<COMPILE_LANGUAGE:CXX>:
        -Wno-logical-not-parentheses
        -Wno-writable-strings
        -Wno-implicit-function-declaration
    >
)

# Optionally, add it for C sources as well
target_compile_options(${PROJECT_NAME} PRIVATE
    $<$<COMPILE_LANGUAGE:C>:
        -Wno-logical-not-parentheses
        -Wno-writable-strings
        -Wno-implicit-function-declaration
    >
)