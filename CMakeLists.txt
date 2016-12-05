cmake_minimum_required(VERSION 2.6)

project(Raytracer)

set(EXECUTABLE_OUTPUT_PATH bin/)

find_package(PkgConfig)
pkg_search_module(Eigen3 REQUIRED eigen3)

  
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
