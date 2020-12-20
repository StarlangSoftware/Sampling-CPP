cmake_minimum_required(VERSION 3.12)
project(Sampling)

set(CMAKE_CXX_STANDARD 17)

add_library(Sampling Bootstrap.h CrossValidation.h KFoldCrossValidation.h StratifiedKFoldCrossValidation.h)

add_executable(Test Test/catch.hpp Test/BootstrapTest.cpp Test/KFoldCrossValidationTest.cpp Test/StratifiedKFoldCrossValidationTest.cpp)