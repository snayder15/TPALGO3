#ifndef ford_h
#define ford_h

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class ford{
	public:
	ford();
	void cargar_ejes(int nodos,int aristas);
	void armar_grafo(int k);
	int max();
	int min();
	bool resolver(int origen);
	int mostrar_solucion();
	void mostrar_adyacentes();
	private:
	int ciudades;
	int cant_rutas;
	int maximo;
	int minimo;
	int reduccion_peso_arista;
	unsigned int cant_nodos;
	vector<vector<pair<int,int> > > lista_adyacencia;
};
#endif