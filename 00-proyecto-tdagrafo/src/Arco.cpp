//
// Created by Tobias on 27/8/2024.
//

#include "../include/Arco.h"
#include "../include/Vertice.h"

using namespace std;

template<typename C>
Arco<C>::Arco(Vertice origen, Vertice destino, int costo) {
    this->origen = origen;
    this->destino = destino;
    this->costo = costo;
}

template<typename C>
Arco<C>::~Arco() {

}


