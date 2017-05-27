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
	int cant_ciudad,cant_rutas,ciudadOrigen,ciudadFinal,max_k;
	dijstra instancia;
	int nodoOrigen,nodoFin,premium,distancia;
	cin>>cant_ciudad;
	cin>>cant_rutas;
	cin>>ciudadOrigen;
	cin>>ciudadFinal;
	cin>>max_k;
	instancia.init(cant_ciudad,cant_rutas);
	for(int i=0;i<cant_rutas;i++){
		cin>>nodoOrigen;
		cin>>nodoFin;
		cin>>premium;
		cin>>distancia;
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