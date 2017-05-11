#ifndef dijstra_h
#define dijstra_h

#include <iostream>
#include <vector>
using namespace std;

class dijstra{
	public:
		dijstra();
		void cargar_ejes();
		void armar_grafo(unsigned int k, int cuidadEntrada ,int cuidadSalida);
		void resolver();
		void mostrar_solucion();
	private:
		vector<vector<pair<int,int> > > lista_adyacencia_normal;
		vector<vector<pair<int,int> > > lista_adyacencia_premium;
		vector<vector<pair<int,int> > > lista_adyacencia_total;
		unsigned int ciudades;
		unsigned int cant_rutas;
};
#endif