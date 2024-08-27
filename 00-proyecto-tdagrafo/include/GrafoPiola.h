//
// Created by Tobias on 27/8/2024.
//

using namespace std;

#ifndef GRAFOPIOLA_H
#define GRAFOPIOLA_H

#include "list"
#include "map"

template <typename C> class GrafoPiola
{
public:
    GrafoPiola();
    ~GrafoPiola();

    int catidadVertices() const;
    int cantidadArcos() const;

    bool existeVertice(Vertice vertice) const;

    bool existeArco(Arco arco) const;

    list<Vertice> obtenerVertices() const;

    list<Arco> obtenerArcos() const;

    void agregarVertice(Vertice vertice);

    void eliminarVertice(Vertice vertice);

    void agregarArco(Arco arco);

    void eliminarArco(Arco arco);

private:
    list<Vertice> vertices;
    list<Arco> arcos;
};

#endif //GRAFOPIOLA_H
