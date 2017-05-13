#ifndef dijstra_h
#define dijstra_h

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class dijstra{
	public:
		dijstra();
		void init(int nodos,int aristas);
		void cargar_ejes(int origen,int destino,int peso, int premium);
		void armar_grafo(int k);
		void resolver(int nodoOrigen);
		void mostrar_grafo();
		int distancia(int ciudad);
	private:
		vector<vector<pair<int,int> > > lista_adyacencia_normal;
		vector<vector<pair<int,int> > > lista_adyacencia_premium;
		vector<vector<pair<int,int> > > lista_adyacencia_total;
		int cant_ciudad;
		int cant_rutas;
		vector<int> distancias;
};
#endif