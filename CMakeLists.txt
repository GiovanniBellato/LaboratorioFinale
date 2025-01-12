cmake_minimum_required(VERSION 3.10)

project(ProgettoFinale VERSION 1.0)

set (MYDIR $PWD)

include_directories($MYDIR) 

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCES
    src/main.cpp
    src/CycleDevice.cpp
    src/DomoticSystem.cpp
    src/ManualDevice.cpp
    src/Time.cpp
    src/Interface.cpp
)

add_executable(ProgettoFinale ${SOURCES})
