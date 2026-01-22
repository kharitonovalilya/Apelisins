cmake_minimum_required(VERSION 3.5)

project(seminar-1)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif(NOT CMAKE_BUILD_TYPE)

set(CMAKE_CXX_STANDARD 17)

# the following options prevent compiler-optimization issues that are unwanted in an edu process
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0 -Werror=return-type")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -O0")

# --- 2. Create a Library for shared logic ---
# Instead of compiling calculator.cpp twice, we make it a library
add_library( sub_lib 
    OBJECT
        src/sub.cpp
        include/sub.h
)
    
target_include_directories( sub_lib
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# --- 3. Main Application ---
add_executable(${CMAKE_PROJECT_NAME} src/main.cpp)
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE sub_lib)