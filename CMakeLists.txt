cmake_minimum_required(VERSION 3.31)
project(watertempcpp)

set(CMAKE_CXX_STANDARD 20)

if(DEFINED VCPKG_ROOT)
    include(${VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake)
    list(APPEND CMAKE_PREFIX_PATH ${VCPKG_ROOT}/installed/${VCPKG_TARGET})
endif ()

find_package(curl CONFIG REQUIRED)
find_package(cpr CONFIG REQUIRED)

find_package(wxWidgets CONFIG REQUIRED)

add_executable(watertempcpp WIN32
        src/main.cpp
        src/WxWatertemp.cpp
)
target_include_directories(watertempcpp PRIVATE
        src/WxWatertemp.h
)
target_link_libraries(watertempcpp PRIVATE cpr::cpr wx::core wx::base)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/icon.bmp ${CMAKE_BINARY_DIR} COPYONLY)