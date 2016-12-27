cmake_minimum_required(VERSION 2.6)

project(Raytracer)

set(EXECUTABLE_OUTPUT_PATH bin/)

file(
        GLOB_RECURSE

        source_files

        src/*.cpp
	      src/*.hpp
	)

add_executable(
  Raytracer
  ${source_files}
  )

find_package(Eigen3)

INCLUDE_DIRECTORIES ( "${EIGEN3_INCLUDE_DIR}" )
include_directories( "src/" )

find_package(OpenMP)
if (OPENMP_FOUND)
    set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
endif()

if(CMAKE_COMPILER_IS_GNUCXX)
    add_definitions(-std=c++14)
    add_definitions(-g)
endif()

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2 REQUIRED system window graphics network audio)
include_directories(${SFML_INCLUDE_DIR})
target_link_libraries(Raytracer ${SFML_LIBRARIES})
