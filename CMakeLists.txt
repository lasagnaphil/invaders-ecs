cmake_minimum_required(VERSION 3.3)
project(invaders_ecs)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

set(SOURCE_FILES main.cpp)
add_executable(invaders_ecs ${SOURCE_FILES})

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(EntityX REQUIRED)
find_package(SFML 2 REQUIRED audio graphics window system network)

include_directories(include ${ENTITYX_INCLUDE_DIR})
include_directories(include ${SFML_INCLUDE_DIR})

target_link_libraries(invaders_ecs
        ${ENTITYX_LIBRARY}
        ${SFML_LIBRARIES})