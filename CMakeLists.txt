cmake_minimum_required(VERSION 3.9)
project(MED_Task_Server)

#Set AutoMOC
set(CMAKE_AUTOMOC ON)

# Set standard to 11
set(CMAKE_CXX_STANDARD 11)

# Set Binary output to bin/
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})


#include header files from include
include_directories(include)


#add .cpp files in src to executable
file(GLOB SOURCES "src/*.cpp")
file(GLOB INCLUDES "include/*.h")

find_library(XLNT_LIBRARY NAMES xlnt  XLNT HINTS "/usr/lib/" "/usr/local/lib/")

#Adding QT4 support here
find_package(Qt4 4.8 REQUIRED QtCore QtNetwork QtGui )

# header files must be added to the executable, so the auto-moc feature can find it
add_executable(Server ${SOURCES} ${INCLUDES})
target_link_libraries(Server ${XLNT_LIBRARY} Qt4::QtCore Qt4::QtNetwork Qt4::QtGui)
