cmake_minimum_required(VERSION 3.10)

project(SBOMBER LANGUAGES CXX)

#-------------------------------------------------------------------------------
if(CMAKE_SOURCE_DIR STREQUAL CMAKE_BINARY_DIR)
  message(FATAL_ERROR "The build directory can not equal source!!!")
endif()

if(NOT (CMAKE_BUILD_TYPE))
  set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Тип сборки" FORCE)
  message(STATUS "Set default build type: ${CMAKE_BUILD_TYPE}")
else()
  message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
endif()

if(NOT DEFINED UNIX)
  message(FATAL_ERROR "Building and working project is possible only Linux")
endif()

#-------------------------------------------------------------------------------
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_VERBOSE_MAKEFILE ON)

#-------------------------------------------------------------------------------
find_package(Curses REQUIRED)

#-------------------------------------------------------------------------------
set(SOURCES_FILES
  sbomber_project.cpp
  global.cpp
  window_console.cpp
  bomb.cpp
  ground.cpp
  house.cpp
  level_gui.cpp
  plane.cpp
  sbomber.cpp
  tank.cpp
  file_logger_singletone.cpp
)

set(HEADERS_FILES
  global.h
  window_console.h
  bomb.h
  destroyable_ground_object.h
  dynamic_object.h
  game_object.h
  ground.h
  house.h
  level_gui.h
  plane.h
  sbomber.h
  tank.h
  file_logger_singletone.h
  command.hpp
  object_deleter.h
)

#-------------------------------------------------------------------------------
set(PROJECT_LABEL sbomber)
add_executable(${PROJECT_LABEL}
  ${SOURCES_FILES}
  ${HEADERS_FILES}
)

target_compile_features(${PROJECT_LABEL} PRIVATE
    cxx_auto_type
    cxx_generic_lambdas
)

target_compile_options(${PROJECT_LABEL} PRIVATE
  -Wall
  -Wextra
  -Wpedantic
  -Wno-deprecated-copy
  -Wnonnull
  # -save-temps
)

#-------------------------------------------------------------------------------
target_include_directories(${PROJECT_LABEL} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

#-------------------------------------------------------------------------------
target_link_libraries(${PROJECT_LABEL} PRIVATE ${CURSES_LIBRARIES})
