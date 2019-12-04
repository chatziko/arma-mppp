cmake_minimum_required(VERSION 3.3.0)

project(arma-mppp)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(mppp)
add_subdirectory(armadillo)


include_directories(include)
add_executable(main src/main.cpp)
target_link_libraries(main mp++ armadillo)