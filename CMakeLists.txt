cmake_minimum_required(VERSION 3.10)

project(Kino VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_executable(Kino src/main.cpp src/Console.cpp src/Process.cpp)

target_include_directories(Kino PUBLIC include)