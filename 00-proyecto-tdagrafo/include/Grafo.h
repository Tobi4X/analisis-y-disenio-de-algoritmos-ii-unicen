#ifndef GRAFO_H
#define GRAFO_H

#include <list>
#include <map>


template <typename C> class Grafo {
	public:
	    /**
	     * Representa un arco en un grafo dirigido.
	     * Se define como una clase inmutable (no puede ser modificada).
	    **/
		class Arco {
			public:
				Arco();
				Arco(int origen, int destino, const C & costo);
				int devolver_origen() const;
				int devolver_destino() const;
				const C & devolver_costo() const;
			private:
				int origen;
				int destino;
				C costo;
		}; // class Arco

	public:
		// NOTA: Dependiendo de la implementación puede ser necesario incluir otras funciones constructuras
		Grafo();
		Grafo(const Grafo & otroGrafo);

		~Grafo();

		Grafo & operator = (const Grafo & otroGrafo);

		// Devuelve true si la cantidad de vértices es cero
		bool esta_vacio() const;

		int cantidad_vertices() const;
		int cantidad_arcos() const;

		bool existe_vertice(int vertice) const;

		bool existe_arco(int origen, int destino) const;

		// PRE CONDICION: existe_arco(origen, destino)
		const C & costo_arco(int origen, int destino) const;

		void devolver_vertices(std::list<int> & vertices) const;

		void devolver_adyacentes(int origen, std::list<Arco> & adyacentes) const;

	    void devolver_arcos(std::list<Arco> & arcos) const;

		void agregar_vertice(int vertice);

		// POST CONDICION: Para todo vértice v != vertice: !existeArco(v, vertice) && !existeArco(vertice, v)
		void eliminar_vertice(int vertice);

		// PRE CONDICION: existeArco(origen, destino)
		void modificar_costo_arco(int origen, int destino, const C & costo);

		// PRE CONDICION: existeVertice(origen) && existeVertice(destino)
		// POST CONDICION: existeArco(origen, destino)
		void agregar_arco(int origen, int destino, const C & costo);

		// POST CONDICION: !existeArco(origen, destino)
		void eliminar_arco(int origen, int destino);

		void vaciar();

	private:
		/*
		 * Definir la estructura interna
		 */
		 /**
		  * Muy mala decisión de implementación.
		  * Además, asumimos que los vértices empiezan en el vértice 0 y se numeran de forma consecutiva.
		  * Sólo se realiza una implementación parcial del grafo que permite conocer su configuración.
		  **/
	class Celda {
	         bool existe;
	         C costo;
	     public:
	            Celda() {
	                existe = false;
	            }

	            Celda(C costo) {
	                existe = true;
	                this->costo = costo;
	            }
	            bool existe_celda() const { return existe; }
	            const C & devolver_costo() const { return costo; }
	            void borrar_celda() { existe = false; }
	     };

		std::map<Celda, std::list<Celda>> celdas;

	    int _cantidad_vertices;
		int _cantidad_arcos;

}; // class Grafo

#endif // GRAFO_H
