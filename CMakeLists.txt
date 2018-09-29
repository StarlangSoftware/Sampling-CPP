cmake_minimum_required(VERSION 3.12)
project(Sampling)

set(CMAKE_CXX_STANDARD 17)

add_library(Sampling Bootstrap.cpp Bootstrap.h CrossValidation.cpp CrossValidation.h KFoldCrossValidation.cpp KFoldCrossValidation.h StratifiedKFoldCrossValidation.cpp StratifiedKFoldCrossValidation.h)