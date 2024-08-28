//
// Created by Tobias on 27/8/2024.
//
using namespace std;

#ifndef ARCO_H
#define ARCO_H

#include "list"
#include "Vertice.h"

template <typename C> class Arco
{
public:
    Arco(Vertice origen, Vertice destino, int costo );
    void obtenerOrigen();
    void obtenerDestino();
    void obtenerCosto();
    void setCosto();

    virtual ~Arco();

private:
    Vertice origen;
    Vertice destino;
    int costo;
};
#endif //ARCO_H
