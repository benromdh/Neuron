cmake_minimum_required (VERSION 2.6)
project (Neuron)

set(CMAKE_CXX_FLAGS "-O3 -W -Wall -pedantic -std=c++11")
add_executable (Neuron Neuron.cpp Nmain.cpp Network.cpp)

enable_testing()
add_subdirectory(gtest)
include_directories(${src/gtest/googletest}/include ${src/gtest/googletest})

add_executable (Neuron_unittest Neuron.cpp Network.cpp Neuron_unittest.cpp)
target_link_libraries(Neuron_unittest gtest gtest_main)
add_test( Neuron_unittest Neuron_unittest )


