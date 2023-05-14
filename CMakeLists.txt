cmake_minimum_required(VERSION 3.25)
project(ex2___matam)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(ex2---matam)

add_executable(ex2___matam Card.cpp Mtmchkin.cpp Player.cpp test.cpp utilities.cpp)
