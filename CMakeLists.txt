cmake_minimum_required (VERSION 3.0.0)
project (most-active-cookie
LANGUAGES CXX)

add_executable(most-active-cookie
src/most-active-cookie.cpp
src/cookie-helpers.hpp
src/cookie-helpers.cpp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)