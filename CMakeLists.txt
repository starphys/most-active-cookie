cmake_minimum_required (VERSION 3.10.0)

project (most-active-cookie
LANGUAGES CXX)

add_executable(most-active-cookie
src/most-active-cookie.cpp
src/cookie-helpers.hpp
src/cookie-helpers.cpp
src/CookieMap.hpp
src/CookieMap.cpp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
 
# Link runTests with what we want to test and the GTest and pthread library
add_executable(test-cookies tests/tests.cpp)
target_link_libraries(test-cookies ${GTEST_LIBRARIES} pthread)