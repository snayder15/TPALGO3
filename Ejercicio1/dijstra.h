#ifndef dijstra_h
#define dijstra_h

#include <iostream>
#include <vector>
using namespace std;

class dijstra{
	public:
		dijstra();
		void cargar_ejes();
		void armar_grafo(int k);
		void resolver();
		void mostrar_solucion();
	private:
		vector<vector<pair<int,int> > > lista_adyacencia_normal;
		vector<vector<pair<int,int> > > lista_adyacencia_premium;
		int ciudades;
		int cant_rutas;
};
#endif