cmake_minimum_required(VERSION 3.22)
project(ElevatorGraph C)

set(CMAKE_C_STANDARD 23)

add_executable(ElevatorGraph main.c Elevator.c Elevator.h)
