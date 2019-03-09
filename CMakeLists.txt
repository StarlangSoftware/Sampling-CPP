cmake_minimum_required(VERSION 3.12)

project(Sampling)

set(CMAKE_CXX_STANDARD 17)

add_library(Sampling Bootstrap.h CrossValidation.h KFoldCrossValidation.h StratifiedKFoldCrossValidation.h)

# CMake can't determine which language it is with only header files
# https://stackoverflow.com/questions/31130612/cmake-error-cmake-can-not-determine-linker-language-for-target-myapp
set_target_properties(Sampling PROPERTIES LINKER_LANGUAGE CXX)
