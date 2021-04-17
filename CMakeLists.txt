cmake_minimum_required(VERSION 2.4)

project(jde_task)

include_directories(${PROJECT_SOURCE_DIR})
add_executable(app main.cpp helper.cpp)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/labyrinth.txt
     DESTINATION ${CMAKE_CURRENT_BINARY_DIR})