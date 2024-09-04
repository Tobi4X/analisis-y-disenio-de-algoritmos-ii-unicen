#include <iostream>
#include "../../clase_grafo/Grafo.tpp"
#include "../../clase_grafo/Arco.tpp"
#include <list>

using namespace std;

void dijkstra(Grafo<int> g, int origen){
    map<int, int> distancias;
    map<int, int> predecesores;

    distancias.emplace(origen, 0);
    predecesores.emplace(origen,-1);

    list<int> vertices;
    g.devolver_vertices(vertices);

    for(int vertice : vertices){
        if (vertice != origen){
            try {
                distancias.emplace(vertice, g.costo_arco(origen, vertice));
            } catch (exception &e) {
                distancias.emplace(vertice, 9999);
                cout<<e.what()<<endl;
                cout<<endl;
            }
            predecesores.emplace(vertice, origen);
        }
    }

    while(!vertices.empty()) {
        const int ver = vertices.front();
        vertices.pop_front();
        list<Arco<int>> adyacentes;
        g.devolver_adyacentes(ver,adyacentes);
        for(Arco<int> ady : adyacentes) {
            if(distancias.at(ady.devolver_destino()) > distancias.at(ady.devolver_origen()) + ady.devolver_costo() ) {
                distancias.at(ady.devolver_destino()) = distancias.at(ady.devolver_origen()) + ady.devolver_costo();
                predecesores.at(ady.devolver_destino()) = ady.devolver_origen();
            }
        }
    }

    for (pair<int, int> dis : distancias) {
        cout << "para el vertice: " << dis.first << " el costo es : " << dis.second << endl;
    }

    cout << endl;

    for (pair<int, int> pre : predecesores) {
        cout << "para el vertice : " <<pre.first << " el predecesor es : " << pre.second << endl;
    }
}


int main() {
    Grafo<int> g;

    g.agregar_vertice(1);
    g.agregar_vertice(2);
    g.agregar_vertice(3);
    g.agregar_vertice(4);
    g.agregar_vertice(5);
    g.agregar_vertice(6);

    g.agregar_arco(1, 2, 2);
    g.agregar_arco(1, 3, 1);
    g.agregar_arco(2, 3, 4);
    g.agregar_arco(2, 5, 3);
    g.agregar_arco(2, 4, 1);
    g.agregar_arco(3, 5, 5);
    g.agregar_arco(3, 4, 4);
    g.agregar_arco(4, 6, 2);
    g.agregar_arco(5, 6, 1);

    dijkstra(g, 1);

    return 0;
}
