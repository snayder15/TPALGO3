#include <iostream>
#include "ford.h"
#include <chrono>
#include <stdlib.h>
#include <vector>
#include <utility>
#include <iostream>
#include <climits>
#define ya chrono::high_resolution_clock::now

using namespace std;

int main(int argc,char const * argv[]){
	ford instancia;
	int ciudad,cant_rutas,origen,destino,peaje;
	cin>>ciudad;
	cin>>cant_rutas;
	instancia.init(ciudad,cant_rutas);
	for(unsigned int i=0;i<cant_rutas;i++){
		cin>>origen;
		cin>>destino;
		cin>>peaje;
		instancia.cargar_ejes(origen,destino,peaje);	
	}
	cerr<<"resolviendo problema"<<endl;
	cout<<ciudad<<";"<<cant_rutas<<";"<<instancia.max()<<";";
	int minimo=0;
	int maximo=instancia.max();
	int promedio;
	auto start = ya();
	while(minimo<=maximo){
		promedio=(minimo+maximo)/2;
		instancia.armar_grafo(promedio);
		if(instancia.resolver(0)){
			minimo=promedio+1;
		}
		else{
			maximo=promedio-1;
		}
		promedio=(minimo+maximo)/2;
	}
	if(instancia.resolver(0)){
		instancia.armar_grafo(promedio+1);
		if(instancia.resolver(0)){
			cout<<"infinito;";
		}
		else{
			cout<<instancia.mostrar_solucion()-1<<";";
		}

	}
	else{
		cout<<instancia.mostrar_solucion()-1<<";";
	}
	auto end = ya();
	cout << chrono::duration_cast<std::chrono::nanoseconds>(end-start).count() << ";"<<endl;
	return 0;
}