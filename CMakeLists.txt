cmake_minimum_required(VERSION 3.12)  # Versión mínima de CMake requerida

project(my_cpp_project)  # Nombre de tu proyecto

enable_testing()  # Habilita la funcionalidad de pruebas

add_subdirectory(googletest)  # Agrega el subdirectorio de googletest

include_directories(googletest/include)  # Esto permite #include <gtest/gtest.h>

add_executable(TriangleTest TriangleTest.cpp)  # Agrega este ejecutable

target_link_libraries(TriangleTest PRIVATE gtest)  # Vincula Google Test con este ejecutable

include(GoogleTest)

gtest_discover_tests(TriangleTest)