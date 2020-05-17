cmake_minimum_required (VERSION 3.5)

project (rpg_project)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -std=c++14")
set (source_dir "${PROJECT_SOURCE_DIR}/src/")
set(EXECUTABLE_NAME "rpg_project")

include_directories("/usr/include/SFML/")

link_directories("/usr/lib/x86_64-linux-gnu/")

file (GLOB source_files "${source_dir}/*.cpp" "${source_dir}/*.h")

add_executable (${EXECUTABLE_NAME} ${source_files})

target_link_libraries(${EXECUTABLE_NAME} "sfml-graphics" "sfml-window" "sfml-system")
