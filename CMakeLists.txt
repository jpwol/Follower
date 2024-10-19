cmake_minimum_required(VERSION 3.10)
project(follower)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

file(GLOB SRC_FILES "src/*.cpp")

set(BIN_DIR ${CMAKE_SOURCE_DIR}/bin)
file(MAKE_DIRECTORY ${BIN_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BIN_DIR})

add_executable(follower ${SRC_FILES})

if(WIN32)

elseif(UNIX)
  target_include_directories(follower PRIVATE include)
  target_link_libraries(follower SDL2main SDL2)
endif()
