cmake_minimum_required(VERSION 3.21)

set (PROJECT_NAME "primer")
project($PROJECT_NAME)


# CMAKE MODULE SETUP.
#####################
# Paths that are searched when `include(...)` is called.
list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/operations/cmake)

# Configuration.
include(OJConfigure)

add_executable(avg_price avg_price.cpp Sales_data.cpp)
add_executable(useBlob useBlob.cpp)
