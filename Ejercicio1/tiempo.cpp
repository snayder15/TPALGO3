#include <iostream>
#include "dijstra.h"

#include <chrono>
#include <stdlib.h>
#include <vector>
#include <utility>
#include <iostream>
#include <climits>
#define ya chrono::high_resolution_clock::now

using namespace std;

int main(int argc,char * argv[]){
	int cant_ciudad=atoi(argv[1]);
	int cant_rutas=atoi(argv[2]);
	int ciudadOrigen=atoi(argv[3]);
	int ciudadFinal=atoi(argv[4]);
	int max_k=atoi(argv[5]);
	dijstra instancia;
	cerr<<"cargando ejes"<<endl;
	cerr<<"ciudades: "<<cant_ciudad<<" rutas: "<<cant_rutas<<" origen: "<<ciudadOrigen<<" destino: "<<ciudadFinal<<endl;
	cerr<<"max premium"<<max_k<<endl;
	instancia.init(cant_ciudad,cant_rutas);
	for(int i=0;i<cant_rutas;i++){

		int nodoOrigen=atoi(argv[i*4+6]);
		int nodoFin=atoi(argv[i*4+7]);
		int premium=atoi(argv[i*4+8]);
		int distancia=atoi(argv[i*4+9]);
		cerr<<"nodo ("<<nodoOrigen<<","<<nodoFin<<") "<<premium<<" peso: "<<distancia<<endl;
		instancia.cargar_ejes(nodoOrigen,nodoFin,distancia,premium);
	}
	cerr<<"Iniciando medicion de tiempo"<<endl;
	auto start = ya();
	instancia.armar_grafo(max_k);
	instancia.resolver(ciudadOrigen);
	auto end = ya();
	cout<<cant_ciudad<<";"<<max_k<<";";
	cout << instancia.distancia(ciudadFinal) <<";";
	cout << chrono::duration_cast<std::chrono::nanoseconds>(end-start).count() << ";"<<endl;
	
	return 0;
}