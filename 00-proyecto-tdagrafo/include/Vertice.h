//
// Created by Tobias on 27/8/2024.
//
using namespace std;

#ifndef VERTIE_H
#define VERTIE_H

#include "set"
#include "Arco.h"

template <typename C> class Vertice
{
public:
    Vertice(int id);

    ~Vertice();

    void obtenerAdyacentes(set<Arco> destinos);
    void obtenerId();
    void agregarDestino();

private:
    set<Arco> destinos;
    int id;
};
#endif //VERTIE_H
