cmake_minimum_required(VERSION 3.12)
project(Sampling)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-O3")

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(Test Test/catch.hpp Test/BootstrapTest.cpp Test/KFoldCrossValidationTest.cpp Test/StratifiedKFoldCrossValidationTest.cpp)