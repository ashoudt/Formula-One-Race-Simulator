cmake_minimum_required(VERSION 3.15)
project(M2OEP)

set(CMAKE_CXX_STANDARD 17)

add_executable(M2OEP main.cpp
        Participant.h
        Participant.cpp
        Driver.cpp
        Driver.h
        Team.cpp
        Team.h
        Race.cpp
        Race.h
        Circuit.cpp
        Circuit.h
)
add_executable(test
        testing.cpp
        Participant.h
        Participant.cpp
        Driver.cpp
        Driver.h
        Team.cpp
        Team.h
        Race.cpp
        Race.h
        Circuit.cpp
        Circuit.h
)