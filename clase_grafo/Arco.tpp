#ifndef ARCO_H
#define ARCO_H

#include <iostream>
#include <tuple>

template <typename C>
class Arco {
private:
    int origen;
    int destino;
    C costo;

public:
    Arco(int origen, int destino, const C &costo);

    int devolver_origen() const;
    int devolver_destino() const;
    const C &devolver_costo() const;

    bool operator<(const Arco &otro) const;
};

// Implementación de los métodos

template <typename C>
Arco<C>::Arco(int origen, int destino, const C &costo)
        : origen(origen), destino(destino), costo(costo) {}

template <typename C>
int Arco<C>::devolver_origen() const {
    return origen;
}

template <typename C>
int Arco<C>::devolver_destino() const {
    return destino;
}

template <typename C>
const C &Arco<C>::devolver_costo() const {
    return costo;
}

template <typename C>
bool Arco<C>::operator<(const Arco &otro) const {
    return std::tie(origen, destino, costo) < std::tie(otro.origen, otro.destino, otro.costo);
}

#endif // ARCO_H
