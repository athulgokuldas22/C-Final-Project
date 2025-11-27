cmake_minimum_required(VERSION 3.16)

project(smart_home c)

set(CMAKE_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

if (MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

file(GLOB SOURCES
    "src/*.c"
    "src/sensors/*.c"
    "src/utils/*.c"
    "main.c"
)

add_executable(smart_home ${SOURCES})

target_include_directories(smart_home PRIVATE include)

find_package(Threade REQUIRED)
target_link_libraries(smart_home PRIVATE Threads::Threads)

target_compile_definitions(smart_home PRIVATE DATA_DIR=\"${CMAKE_SOURCE_DIR}/data\")