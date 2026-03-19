cmake_minimum_required(VERSION 3.10)

project(practica4)

file(GLOB SOURCES "*.cc")

add_executable(practica4 ${SOURCES})

target_include_directories(mi_programa PRIVATE ./include)