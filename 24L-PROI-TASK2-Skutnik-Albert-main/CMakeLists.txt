cmake_minimum_required(VERSION 3.0.0)
project(time_test VERSION 0.1.0 LANGUAGES C CXX)

include(FetchContent)

FetchContent_Declare(
    googletest
    GIT_REPOSITORY      https://github.com/google/googletest.git
    GIT_TAG main
)

FetchContent_MakeAvailable(googletest)

set(TIME_SOURCE_FILES Time.cpp Time.h)
add_executable(time_test.exe time_tests.cpp ${TIME_SOURCE_FILES})
add_executable(test_google.exe test_google.cpp ${TIME_SOURCE_FILES})
target_link_libraries(test_google.exe PUBLIC gtest_main)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
