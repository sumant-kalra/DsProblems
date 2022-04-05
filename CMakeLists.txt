cmake_minimum_required(VERSION 3.5)
project(DS_Problems)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -std=c++14 -save-temps")
add_compile_definitions(PR_RELEASE=1)
add_executable(runApp 
                        src/Main.cpp
                        src/Bitwise.h
                        src/Bitwise.cpp
                        src/Random.h
                        src/Random.cpp)