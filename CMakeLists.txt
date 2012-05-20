project(sfmle)
cmake_minimum_required(VERSION 2.8)

set(CMAKE_MODULE_PATH ${sfmle_SOURCE_DIR}/cmake/modules
                      ${CMAKE_MODULE_PATH})

# Require all components from SFML
find_package(SFML REQUIRED audio graphics network system window)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g --std=c++11 -Wall -Wextra -pedantic")

# Include SFML stuff for everything, and link SFML
# to everything.
include_directories(${SFML_INCLUDE_DIR})
link_libraries(${SFML_LIBRARIES})

# Build a simple program
add_executable(test test.cpp)
