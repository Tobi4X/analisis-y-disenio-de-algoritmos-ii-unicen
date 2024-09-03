cmake_minimum_required(VERSION 3.28)
project(TDAGrafoClion)

set(CMAKE_CXX_STANDARD 17)

add_executable(TDAGrafoClion main.cpp
        include/Grafo.tpp
        include/Arco.tpp
)
