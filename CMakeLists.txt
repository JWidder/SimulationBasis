project(simulation)
cmake_minimum_required(VERSION 3.5)

SET(BOOST_MIN_VERSION "1.63.0")

# configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
# execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
#   WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )
# execute_process(COMMAND ${CMAKE_COMMAND} --build .
#   WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )
 
# Prevent GoogleTest from overriding our compiler/linker options
# when building with Visual Studio
# set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
 
# Add googletest directly to our build. This adds
# the following targets: gtest, gtest_main, gmock
# and gmock_main
# add_subdirectory(${CMAKE_BINARY_DIR}/googletest-src ${CMAKE_BINARY_DIR}/googletest-build)
 
# The gtest/gmock targets carry header search path
# dependencies automatically when using CMake 2.8.11 or
# later. Otherwise we have to add them here ourselves.
# if (CMAKE_VERSION VERSION_LESS 2.8.11)
#   include_directories("${gtest_SOURCE_DIR}/include"
#                       "${gmock_SOURCE_DIR}/include")
# endif()

set(BOOST_ROOT "c:/boost")
set( DIR "c:/boost")
set(Boost_USE_STATIC_LIBS OFF)
add_definitions("-DBOOST_ALL_DYN_LINK")

find_package(Boost 1.64 REQUIRED system date_time regex thread unit_test_framework)

add_subdirectory(SimulationServer)
add_subdirectory(Simulation)
add_subdirectory(SimulationDokumentation)
