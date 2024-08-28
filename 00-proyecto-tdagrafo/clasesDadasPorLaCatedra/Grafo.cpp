#include "Grafo.h"

#include <cassert>
#include <list>

using namespace std;

/*
 * Arco
 */

template <typename C> Grafo<C>::Arco::Arco(){
}

template <typename C> Grafo<C>::Arco::Arco(int origen, int destino, const C & costo) {
    this->origen = origen;
    this->destino = destino;
    this->costo = costo;
}

template <typename C> int Grafo<C>::Arco::devolver_origen() const {
    return origen;
}

template <typename C> int Grafo<C>::Arco::devolver_destino() const {
    return destino;
}

template <typename C> const C & Grafo<C>::Arco::devolver_costo() const {
    return costo;
}


/*
 * Grafo
 */

template <typename C> Grafo<C>::Grafo() {
    _cantidad_vertices = 0;
    _cantidad_arcos = 0;
}

template <typename C> Grafo<C>::Grafo(const Grafo & otroGrafo) {
    //Construir el grafo actual (this) a partir de otroGrafo
}

template <typename C> Grafo<C>::~Grafo() {
}

template <typename C> Grafo<C> & Grafo<C>::operator = (const Grafo & otroGrafo) {
    //Construir el grafo actual (this) a partir de otroGrafo
    return *this;
}

template <typename C> bool Grafo<C>::esta_vacio() const {
    return (this->_cantidad_vertices == 0);
}

template <typename C> int Grafo<C>::cantidad_vertices() const {
    return this->_cantidad_vertices;
}

template <typename C> int Grafo<C>::cantidad_arcos() const {
    return this->_cantidad_arcos;
}

template <typename C> bool Grafo<C>::existe_vertice(int vertice) const {
    bool existe = false;
    return existe;
}

template <typename C> bool Grafo<C>::existe_arco(Celda origen, int destino) const {
    return matriz[origen][destino].existe_celda();
}

template <typename C> const C & Grafo<C>::costo_arco(int origen, int destino) const {
    return matriz[origen][destino].devolver_costo();
}

template <typename C> void Grafo<C>::devolver_vertices(list<int> & vertices) const {
    for(unsigned int vertice=1; vertice <= cantidad_vertices(); vertice++) {
        vertices.push_back(vertice);
    }
}

template <typename C> void Grafo<C>::devolver_adyacentes(int origen, list<Arco> & adyacentes) const
{
    for(unsigned int destino=1; destino <= cantidad_vertices(); destino++) {
        Celda celda = matriz[origen][destino];
        if (celda.existe_celda()) {
            adyacentes.push_back(Arco(origen, destino, celda.devolver_costo()));
        }
    }
}

template <typename C> void Grafo<C>::devolver_arcos(list<Arco> & arcos) const
{
    for(unsigned int origen=1; origen <= cantidad_vertices(); origen++) {
        for(unsigned int destino=1; destino <= cantidad_vertices(); destino++) {
            Celda celda = matriz[origen][destino];
            if (celda.existe_celda()) {
                arcos.push_back(Arco(origen, destino, celda.devolver_costo()));
            }
        }
    }
}

template <typename C> void Grafo<C>::agregar_vertice(int vertice)
{
    _cantidad_vertices++;
}

template <typename C> void Grafo<C>::eliminar_vertice(int vertice)
{

}

template <typename C> void Grafo<C>::modificar_costo_arco(int origen, int destino, const C & costo)
{
    assert((origen <= cantidad_vertices()) && (destino <= cantidad_vertices()));

    matriz[origen][destino] = Celda(costo);
}

template <typename C> void Grafo<C>::agregar_arco(int origen, int destino, const C & costo)
{
    assert((origen <= cantidad_vertices()) && (destino <= cantidad_vertices()));

    matriz[origen][destino] = Celda(costo);
    _cantidad_arcos++;
}

template <typename C> void Grafo<C>::eliminar_arco(int origen, int destino)
{
    assert((origen <= cantidad_vertices()) && (destino <= cantidad_vertices()));
    matriz[origen][destino].borrar_celda();
    _cantidad_arcos--;
}

template <typename C> void Grafo<C>::vaciar()
{

}

template class Grafo<int>;
