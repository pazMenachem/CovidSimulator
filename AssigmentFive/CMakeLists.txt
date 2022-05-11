cmake_minimum_required(VERSION 3.20)
project(AssigmentFive)

set(CMAKE_CXX_STANDARD 98)

add_executable(AssigmentFive main.cpp Element.h ElementImp.h Simulator.h Setup.cpp Setup.h Simulator.cpp FileNotFound.cpp FileNotFound.h InvalidDefinition.cpp InvalidDefinition.h PopulationDefinition.h PopulationDefinition.cpp)
