#ifndef agm_h
#define agm_h

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>    // std::sort
#include "uds_listas.h"
#include "aristas.h"
using namespace std;

class agm{
	public:
	agm();
	void definir_nodos(int nodos);

	void agregar_ejes(int origen,int destino,int peso,int tipo);

	int buscar_AGMAXMIN(vector<aristas> &eliminados,vector<aristas> &construidos);
	int mostrar_solucion();
	void mostrar_adyacentes();
	private:
	unsigned int cant_nodos;
	vector<aristas> list_destruccion;
	vector<aristas> list_construccion;
	vector<aristas> list_ejes_solucion;
};
#endif