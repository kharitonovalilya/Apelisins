cmake_minimum_required(VERSION 3.5)

project(seminar-2)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

set(CMAKE_CXX_STANDARD 17)

# --- Fetch Catch2 Dependency ---
include(FetchContent)
FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v3.4.0
)
FetchContent_MakeAvailable(Catch2)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0 -Werror=return-type")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -O0")

# --- Create lib ---
add_library(seminar2_lib 
    src/calculate.cpp
    src/input_checkers.cpp
)

target_include_directories(seminar2_lib
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# --- Main Application ---
add_executable(${CMAKE_PROJECT_NAME} src/main.cpp)
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE seminar2_lib)

# --- Testing ---
enable_testing()

# Tests for calculate
add_executable(test_calculate tests/test_calculate.cpp)
target_include_directories(test_calculate PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(test_calculate PRIVATE seminar2_lib Catch2::Catch2WithMain)
add_test(NAME calculate-tests COMMAND test_calculate)

# Tests for check_operations
add_executable(test_check_operations tests/test_check_operations.cpp)
target_include_directories(test_check_operations PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(test_check_operations PRIVATE seminar2_lib Catch2::Catch2WithMain)
add_test(NAME check-operations-tests COMMAND test_check_operations)

# Tests for check_symbols
add_executable(test_check_symbols tests/test_check_symbols.cpp)
target_include_directories(test_check_symbols PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(test_check_symbols PRIVATE seminar2_lib Catch2::Catch2WithMain)
add_test(NAME check-symbols-tests COMMAND test_check_symbols)

# Tests for esc_erase
add_executable(test_esc_erase tests/test_esc_erase.cpp)
target_include_directories(test_esc_erase PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(test_esc_erase PRIVATE seminar2_lib Catch2::Catch2WithMain)
add_test(NAME esc-erase-tests COMMAND test_esc_erase)

# Tests for parser
add_executable(test_parser tests/test_parser.cpp)
target_include_directories(test_parser PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(test_parser PRIVATE seminar2_lib Catch2::Catch2WithMain)
add_test(NAME parser-tests COMMAND test_parser)