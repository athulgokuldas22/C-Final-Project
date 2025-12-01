cmake_minimum_required(VERSION 3.16)

project(smart_home C)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)


file(GLOB SOURCES
    "src/*.c"
    "src/sensors/*.c"
    "src/utils/*.c"
)

add_executable(smart_home ${SOURCES})

target_include_directories(smart_home PRIVATE include)

find_package(Threads REQUIRED)
target_link_libraries(smart_home PRIVATE Threads::Threads)

target_compile_definitions(smart_home PRIVATE DATA_DIR=\"${CMAKE_SOURCE_DIR}/data\")