//
// Created by Tobias on 27/8/2024.
//
using namespace std;

#ifndef VERTIE_H
#define VERTIE_H

#include "list"

template <typename C> class Vertice
{
public:
    void obtenerAdyacentes();
    void obtenerId();
private:
    list<Arco> destinos;
    int id;
};
#endif //VERTIE_H
