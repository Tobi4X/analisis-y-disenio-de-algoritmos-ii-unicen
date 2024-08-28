//
// Created by Tobias on 27/8/2024.
//
#include <set>
#include "../include/Vertice.h"
#include "../src/Arco.cpp"

using namespace std;

template <typename C>
Vertice<C>::Vertice(int id){
    this->id = id;
}

void obtenerAdyacentes(set<Arco> & set1) {
    set1 = this->destinos;
    return set1;
}

void obtenerId();
void agregarDestino();
