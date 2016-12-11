cmake_minimum_required(VERSION 2.6)

project(Raytracer)

set(EXECUTABLE_OUTPUT_PATH bin/)

find_package(Eigen3)

INCLUDE_DIRECTORIES ( "${EIGEN3_INCLUDE_DIR}" )

file(
        GLOB_RECURSE

        source_files

        *.cpp
	*.hpp
	)


if(CMAKE_COMPILER_IS_GNUCXX)
    add_definitions(-std=c++14)
endif()

add_executable(
  Raytracer
  ${source_files}
  )

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML)
target_link_libraries(Raytracer ${SFML_LIBRARIES})
