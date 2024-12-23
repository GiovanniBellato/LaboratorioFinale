cmake_minimum_required(VERSION 3.10)

project(ProgettoFinale VERSION 1.0)

include_directories(${CMAKE_SOURCE_DIR}/include) 

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCES
    src/main.cpp
    src/CycleDevice.cpp
    src/Device.cpp
    src/DomoticSystem.cpp
    src/ManualDevice.cpp
)

add_executable(ProgettoFinale ${SOURCES})
