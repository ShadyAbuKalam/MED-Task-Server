cmake_minimum_required(VERSION 3.9)
project(MED_Task_Server)

# Set standard to 11
set(CMAKE_CXX_STANDARD 11)

# Set Binary output to bin/
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})


#include header files from include
include_directories(include)

#add .cpp files in src to executable
file(GLOB SOURCES "src/*.cpp")

find_library(XLNT_LIBRARY NAMES xlnt  XLNT HINTS "/usr/lib/" "/usr/local/lib/")

add_executable(Server ${SOURCES})
target_link_libraries(Server ${XLNT_LIBRARY})
