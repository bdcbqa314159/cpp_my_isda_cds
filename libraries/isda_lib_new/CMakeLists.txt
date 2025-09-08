project(isda_lib)

set(includes ./includes/)
set(sources src/new_code/badday.cpp
            src/new_code/bsearch.cpp
            src/new_code/cmemory.cpp
            src/new_code/lprintf.cpp
            src/new_code/lscanf.cpp
            src/new_code/cfileio.cpp
            src/new_code/dateconv.cpp
            src/new_code/cerror.cpp
            # src/new_code/busday.cpp
)
# file(GLOB SOURCES "src/*.c" "src/*.cpp")


add_library(${PROJECT_NAME} SHARED ${sources})
target_include_directories(${PROJECT_NAME} PUBLIC ${includes} ${common_includes_dir})

target_compile_options(${PROJECT_NAME} PRIVATE
    $<$<COMPILE_LANGUAGE:CXX>:
        -Wno-logical-not-parentheses
        -Wno-writable-strings
        -Wno-implicit-function-declaration
        -Wdeprecated-declarations
        -Wgcc-compat
    >
)

# Optionally, add it for C sources as well
target_compile_options(${PROJECT_NAME} PRIVATE
    $<$<COMPILE_LANGUAGE:C>:
        -Wno-logical-not-parentheses
        -Wno-writable-strings
        -Wno-implicit-function-declaration
        -Wdeprecated-declarations
        -Wgcc-compat
    >
)