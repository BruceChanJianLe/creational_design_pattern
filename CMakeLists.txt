cmake_minimum_required(VERSION 3.12)

# Project name
project(design_patter)

# Select c++17
SET(CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)

# Create executable
add_executable(factory_method factory_method.cpp)
add_executable(abstract_factory_method abstract_factory_method.cpp)
add_executable(builder_method builder_method.cpp)
add_executable(prototype_method prototype_method.cpp)