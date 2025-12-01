cmake_minimum_required(VERSION 3.16)

project(smart_home C)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_library(sensor_lib
    src/sensors/temperature.c
    src/sensors/humidity.c
    src/sensors/light_sensor.c
    src/sensors/motion.c
    src/sensors/door.c
)

add_library(utils_lib
    src/utils/logger.c
    src/utils/csv_reader.c
    src/utils/random_gen.c
)

add_executable(smart_home
    src/core.c
    src/menu.c
    src/graph.c
    src/main.c
)


target_include_directories(sensor_lib PUBLIC include)
target_include_directories(utils_lib PUBLIC include)
target_include_directories(smart_home PUBLIC include)

find_package(Threads REQUIRED)
target_link_libraries(smart_home
    PRIVATE
        sensor_lib
        utils_lib
        Threads::Threads
)
target_compile_definitions(smart_home PRIVATE DATA_DIR=\"data\")