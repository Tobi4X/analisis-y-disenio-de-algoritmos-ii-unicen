#ifndef GRAFO_H
#define GRAFO_H

#include "Arco.tpp"
#include <set>
#include <list>
#include <map>
#include <algorithm>
#include <stdexcept>

template <typename C>
class Grafo {
private:
    std::set<int> vertices;               // Conjunto de vértices
    std::set<Arco<C>> arcos;            // Conjunto de arcos

public:
    Grafo() {}
    ~Grafo() {}

    bool esta_vacio() const { return vertices.empty(); }
    int cantidad_vertices() const { return vertices.size(); }
    int cantidad_arcos() const { return arcos.size(); }

    bool existe_vertice(int vertice) const {
        return vertices.find(vertice) != vertices.end();
    }

    bool existe_arco(int origen, int destino) const {
        for (const auto& arco : arcos) {
            if (arco.devolver_origen() == origen && arco.devolver_destino() == destino) {
                return true;
            }
        }
        return false;
    }

    const C& costo_arco(int origen, int destino) const {
        for (const auto& arco : arcos) {
            if (arco.devolver_origen() == origen && arco.devolver_destino() == destino) {
                return arco.devolver_costo();
            }
        }
        throw std::runtime_error("El arco no existe.");
    }

    void devolver_vertices(std::list<int> &listaVertices) const{
        for(const auto& ver : this->vertices) {
            listaVertices.push_back(ver);
        }
    }

    void devolver_adyacentes(int origen, std::list<Arco<C>> &adyacentes) const {
        for (const auto& arco : arcos) {
            if (arco.devolver_origen() == origen) {
                adyacentes.push_back(arco);
            }
        }
    }

    void devolver_arcos(std::list<Arco<C>> &arcos_lista) const {
        arcos_lista.assign(arcos.begin(), arcos.end());
    }

    void agregar_vertice(int vertice) {
        vertices.insert(vertice);
    }

    void eliminar_vertice(int vertice) {
        vertices.erase(vertice);
        arcos.erase(std::remove_if(arcos.begin(), arcos.end(),
                                   [vertice](const Arco<C>& arco) {
                                       return arco.devolver_origen() == vertice || arco.devolver_destino() == vertice;
                                   }), arcos.end());
    }

    void agregar_arco(int origen, int destino, const C& costo) {
        if (!existe_vertice(origen) || !existe_vertice(destino)) {
            throw std::runtime_error("Uno o ambos vértices no existen.");
        }
        arcos.insert(Arco<C>(origen, destino, costo));
    }

    void eliminar_arco(int origen, int destino) {
        arcos.erase(Arco<C>(origen, destino, C()));
    }

    void vaciar() {
        vertices.clear();
        arcos.clear();
    }
};

#endif // GRAFO_H
