#include <iostream>
#include "../../clase_grafo/Grafo.tpp"
#include "../../clase_grafo/Arco.tpp"
#include <list>

using namespace std;

void restarSoluciones(list<int> vertices, set<int> soluciones, list<int> &resultado){
    for(int solucion : soluciones){
        vertices.remove(solucion);
    }
    resultado.erase(resultado.begin(), resultado.end());
    resultado.insert(resultado.end(), vertices.begin(), vertices.end());
}

void obtenerVerticeMasCercano(Grafo<int> g, int vertice, int &verticeCercano ){
    list<Arco<int>> adyacentes;
    g.devolver_adyacentes(vertice, adyacentes);

    int costoActual = 999999999999999999;
    int costoNuevo = 0;

    for(Arco<int> arco : adyacentes){
        costoNuevo = arco.devolver_costo();
        if(costoNuevo < costoActual){
            costoActual = costoNuevo;
            verticeCercano = arco.devolver_destino();
        }
    }
}

void dijkstra(Grafo<int> g, int origen){
    set<int> soluciones;
    map<int, int> distancias;
    map<int, int> predecesores;

    soluciones.emplace(origen);

    distancias.emplace(origen, 0);
    predecesores.emplace(origen,-1);

    list<int> vertices;
    g.devolver_vertices(vertices);

    list<int> verticesMenosSoluciones;

    verticesMenosSoluciones.insert(verticesMenosSoluciones.end(),vertices.begin(), vertices.end());

    for(int vertice : vertices){
        if (vertice != origen){
            distancias.emplace(vertice, g.costo_arco(origen,vertice));
            predecesores.emplace(vertice, origen);
        }
    }

    while(verticesMenosSoluciones.size() > 0){
        restarSoluciones(vertices, soluciones, verticesMenosSoluciones);
        int verticeCercano = 0;
        obtenerVerticeMasCercano(g, origen, verticeCercano);
        soluciones.emplace(verticeCercano);
    //para cada vertice adyacente a este que no este en verticesMenosSoluciones
        list<Arco<int>> adyacentes;
        g.devolver_adyacentes(verticeCercano, adyacentes);
        for(Arco<int> adyacente : adyacentes)
            if (g.costo_arco(predecesores.))
        //comparo si la distancia al vertice adyacente desde el vertice que predecesor es mayor al vertice w + costo de ir al vertice
        //en caso afirmativo cambio la distancia al vertice actual del foreach por la distancia desde el w + el costo
        //asigno el predecesor del vertice del foreach a el vertice w
    }


}


int main() {
    cout << "Hello, World!" << endl;
    return 0;
}
