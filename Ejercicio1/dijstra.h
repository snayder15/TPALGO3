#ifndef dijstra_h
#define dijstra_h

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class dijstra{
	public:
		dijstra();
		void cargar_ejes();
		void armar_grafo(unsigned int k, int cuidadEntrada ,int cuidadSalida);
		void resolver(int nodoOrigen);
		void mostrar_solucion();
	private:
		vector<vector<pair<int,int> > > lista_adyacencia_normal;
		vector<vector<pair<int,int> > > lista_adyacencia_premium;
		vector<vector<pair<int,int> > > lista_adyacencia_total;
		unsigned int ciudades;
		unsigned int cant_rutas;
		//funciones auxiliares
		void inicializacion(vector<bool>& visitados,vector<int>& distancias,vector<int>& antecesor);
};
#endif