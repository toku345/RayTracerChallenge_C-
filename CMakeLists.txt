cmake_minimum_required(VERSION 3.10)

project(RayTracerChallenge VERSION 1.0)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)


add_executable(raytracer src/main.cpp)

target_include_directories(raytracer
  PUBLIC
  "${PROJECT_BINARY_DIR}"
  )


Include(FetchContent)
FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v2.13.1)
FetchContent_MakeAvailable(Catch2)


add_executable(unit_tests
  tests/main.cpp)
target_include_directories(unit_tests
  PUBLIC
  tests/
  src/)
target_link_libraries(unit_tests
  Catch2::Catch2)

if (MSVC)
  target_compile_options(unit_tests PRIVATE /W4 /WX /bigobj)
else ()
  target_compile_options(unit_tests PRIVATE -Wall -Wextra -Werror -pedantic -Wshadow -Wunused-parameter)
endif ()
