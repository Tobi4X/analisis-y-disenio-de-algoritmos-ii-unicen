#include <iostream>
#include "../../clase_grafo/Arco.tpp"
#include "../../clase_grafo/Grafo.tpp"
#include <list>

using namespace std;

void dfs(Grafo<int> grafo, int origen, int &tiempo, map<int, string> &marcas, map<int, int> &predecesores, map<int, int> &tiemposDeInicio, map<int,int> &tiemposDeFinalizacion){
    tiempo += 1;
    tiemposDeInicio.emplace(origen,tiempo);
    marcas.at(origen) = "gris";

    list<Arco<int>> adyacentes;
    grafo.devolver_adyacentes(origen, adyacentes);

    for(Arco<int> arco : adyacentes){
        int ady = arco.devolver_destino();

        if(marcas.at(ady) == "blanco"){
            predecesores.emplace(ady, origen);
            dfs(grafo, ady, tiempo, marcas, predecesores, tiemposDeInicio, tiemposDeFinalizacion);
        }
    }

    marcas.at(origen) = "negro";
    tiempo += 1;
    tiemposDeFinalizacion.emplace(origen,tiempo);

}

void dfsForest(Grafo<int> grafo){
    list<int> vertices;
    grafo.devolver_vertices(vertices);

    map<int, string> marcas;
    map<int,int> predecesores;
    map<int,int> tiemposDeInicio;
    map<int,int> tiemposDeFinalizacion;

    for(int vertex : vertices){
        marcas.emplace(vertex, "blanco");
    }

    int tiempo = 0;

    for(int vertex : vertices){
        if(marcas.at(vertex) == "blanco"){
            dfs(grafo, vertex, tiempo,marcas, predecesores, tiemposDeInicio, tiemposDeFinalizacion);
        }
    }


    for(pair<int,string> mar : marcas){
        cout<<mar.second<<endl;
    }
    cout<<endl;
    for(pair<int,int> pre : predecesores){
        cout<<pre.second<<endl;
    }
    cout<<endl;
    for(pair<int,int> mar : tiemposDeInicio){
        cout<<mar.second<<endl;
    }
    cout<<endl;
    for(pair<int,int> mar : tiemposDeFinalizacion){
        cout<<mar.second<<endl;
    }

}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
