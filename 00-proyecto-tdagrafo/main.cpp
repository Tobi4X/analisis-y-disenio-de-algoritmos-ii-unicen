#include "include/Grafo.tpp"
#include "include/Arco.tpp"
#include <list>


#include "iostream"

using namespace std;

void dfsDos(const Grafo<int> & grafo, int pos, bool visitado[])
{
	visitado[pos] = true;

    std::list<Arco<int>> adyacentes;
	grafo.devolver_adyacentes(pos, adyacentes);

	for(Arco c : adyacentes)
	{
		if(!visitado[c.devolver_destino()])
		{
			cout<<c.devolver_destino()<<endl;;
			dfsDos(grafo,c.devolver_destino(),visitado);
		}
	}
}


void dfs(const Grafo<int> & grafo)
{
	std::list<int> vertices;
	grafo.devolver_vertices(vertices);

	cout<<"VERTICES ="<<endl;
	for(int i : vertices)
	{
		cout<<i<<endl;
	}
	cout<<"fin vertices"<<endl;
	cout<<endl;

	bool visitados[100];

	for(int v : vertices)
	{
		visitados[v] = false;
	}

	for(int v : vertices){
		if(v >= 0 and visitados[v] != true)
		{
            dfsDos(grafo, v, visitados);
		}
	}
}

int main(int argc, char **argv)
{
	Grafo<int> g;

	// Cargamos un grafo dirigido
	// Primero los vértices
	g.agregar_vertice(1);
	g.agregar_vertice(2);
	g.agregar_vertice(3);
	g.agregar_vertice(4);
	g.agregar_vertice(5);
	g.agregar_vertice(6);
	// Luego los arcos
	g.agregar_arco(1, 2, 12);
	g.agregar_arco(1, 4, 13);
	g.agregar_arco(2, 5, 14);
	g.agregar_arco(3, 5, 35);
	g.agregar_arco(3, 6, 47);
	g.agregar_arco(4, 2, 56);
	g.agregar_arco(5, 4, 89);
	g.agregar_arco(6, 6, 34);

	// Mostramos el grafo
	cout << "Estructura del grafo:\n" << "(" << g.cantidad_vertices()
        << " vertices, " << g.cantidad_arcos() << " arcos)" << endl;

    dfs(g);

	return 0;
}

void recorrer(const Grafo<int> & grafo)
{


}