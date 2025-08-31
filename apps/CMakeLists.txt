project(app)

set(includes ./ 
            ../libraries/ 
            ../libraries/common/ 
            ../libraries/my_static_lib/ 
            ../libraries/my_dynamic_lib/ 
            ${dlloader_include_dir} 
            ${dlloader_include_dir_platform}
)

set(project1 static_link_test)
set(project2 dynamic_link_test)

add_executable(${project1} ${project1}.cpp)
target_include_directories(${project1} PUBLIC ${includes})
target_link_libraries(${project1} my_static_lib)

add_executable(${project2} ${project2}.cpp)
target_include_directories(${project2} PUBLIC ${includes})
target_link_libraries(${project2} my_dynamic_lib)