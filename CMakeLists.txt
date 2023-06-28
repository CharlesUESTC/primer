cmake_minimum_required(VERSION 3.21)

set (PROJECT_NAME "primer")
project($PROJECT_NAME)

add_executable(avg_price avg_price.cpp Sales_data.cpp)
add_executable(useBlob useBlob.cpp)
