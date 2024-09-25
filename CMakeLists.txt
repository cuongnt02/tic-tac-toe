cmake_minimum_required(VERSION 3.5)
project(tic-tac-toe)

option(TIC-TAC-TOE_VENDORED "Use vendored libraries" OFF)

if(TIC-TAC-TOE_VENDORED)
    add_subdirectory(vendored/SDL EXCLUDE_FROM_ALL)
else()
    find_package(SDL3 REQUIRED CONFIG REQUIRED COMPONENTS SDL3-shared)
endif()

find_package(SDL3_image REQUIRED)

set(CMAKE_CXX_FLAGS "-g")

file(GLOB SOURCES "src/*.cpp")
add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE include)
target_link_libraries(${PROJECT_NAME} PRIVATE SDL3::SDL3 SDL3_image)



