cmake_minimum_required(VERSION 3.21)

set (PROJECT_NAME "primer")
project($PROJECT_NAME)


# CMAKE MODULE SETUP.
#####################
# Paths that are searched when `include(...)` is called.
list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/operations/cmake)

# CONFIGURATION.
################
include(OJConfigure)

# SUBDIRECTORIES.
#################
add_subdirectory(source)
