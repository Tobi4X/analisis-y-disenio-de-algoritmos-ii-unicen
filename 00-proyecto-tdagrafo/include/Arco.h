//
// Created by Tobias on 27/8/2024.
//
using namespace std;

#ifndef ARCO_H
#define ARCO_H

#include "list"

template <typename C> class Arco
{
public:
    void obtenerOrigen();
    void obtenerDestino();
    void obtenerCosto();
    void setCosto();
private:
    Vertice origen;
    Vertice destino;
    int costo;
};
#endif //ARCO_H
