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

FIND_PACKAGE(Eigen3)
INCLUDE_DIRECTORIES ( "${EIGEN3_INCLUDE_DIR}")


FIND_PACKAGE(PythonLibs 2.7 REQUIRED)
target_link_libraries(Raytracer python2.7)

FIND_PACKAGE(Boost  ${BOOST_VERSION}  COMPONENTS python)
INCLUDE_DIRECTORIES("${Boost_INCLUDE_DIR}"   "${PYTHON_INCLUDE_DIRS}")
LINK_DIRECTORIES("${PYTHON_INCLUDE_DIRS}" "${Boost_LIBRARY_DIRS}")


include_directories( "src/" )

find_package(OpenMP)
if (OPENMP_FOUND)
    set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
endif()

SET(GCC_COVERAGE_LINK_FLAGS    "-lpython2.7")

if(CMAKE_COMPILER_IS_GNUCXX)
    add_definitions(-std=c++14)
    add_definitions(-g)
    add_definitions(${GCC_COVERAGE_LINK_FLAGS}$)
endif()

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2 REQUIRED system window graphics network audio)
include_directories(${SFML_INCLUDE_DIR})
target_link_libraries(Raytracer ${SFML_LIBRARIES})
