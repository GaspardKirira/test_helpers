cmake_minimum_required(VERSION 3.20)
project(test_helpers LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(test_helpers INTERFACE)
add_library(test_helpers::test_helpers ALIAS test_helpers)

target_include_directories(test_helpers INTERFACE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)

if (MSVC)
  target_compile_options(test_helpers INTERFACE /W4 /permissive-)
else()
  target_compile_options(test_helpers INTERFACE -Wall -Wextra -Wpedantic)
endif()

include(CTest)
enable_testing()

add_executable(test_helpers_basic_test tests/test_basic.cpp)
target_link_libraries(test_helpers_basic_test PRIVATE test_helpers::test_helpers)
add_test(NAME test_helpers.basic COMMAND test_helpers_basic_test)
