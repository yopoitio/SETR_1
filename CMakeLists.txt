cmake_minimum_required(VERSION 3.20)

project(project1 VERSION 1.0)

set (sources main.c DLL.c)

add_executable(exec ${sources})
