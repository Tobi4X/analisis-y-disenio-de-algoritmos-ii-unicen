cmake_minimum_required(VERSION 3.28)
project(TDAGrafoClion)

set(CMAKE_CXX_STANDARD 17)

add_executable(TDAGrafoClion main.cpp
        clasesDadasPorLaCatedra/Grafo.cpp
        clasesDadasPorLaCatedra/Grafo.h
        include/GrafoPiola.h
        include/Arco.h
        include/Vertice.h
        src/GrafoPiola.cpp
        src/Arco.cpp
        src/Vertice.cpp
)
