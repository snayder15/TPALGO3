#include <iostream>
#include "agm.h"
#include "aristas.h"
#include <chrono>
#include <stdlib.h>
#include <vector>
#include <utility>
#include <iostream>

#define ya chrono::high_resolution_clock::now

using namespace std;

int main(int argc,char const * argv[]){
	int ciudad;
	cin>>ciudad;
	agm instancia;
	instancia.definir_nodos(ciudad);
	int kn=ciudad*(ciudad-1)/2;
	int origen,dest,tipo,peso;
	for(unsigned int i=0;i<kn;i++){
		cin>>origen;
		cin>>dest;
		cin>>tipo;
		cin>>peso;
		instancia.agregar_ejes(origen-1,dest-1,peso,tipo);
	}
	cerr<<"Resolviendo problema "<<endl;	
	auto start = ya();
	vector<aristas> solucion=instancia.buscar_AGMAXMIN();
	auto end = ya();
	cout<<ciudad<<";";
	cout << chrono::duration_cast<std::chrono::nanoseconds>(end-start).count() << ";";
	cout<<instancia.costo()<<";"<<solucion.size()<<";";
	for(unsigned int i=0;i<solucion.size();i++){
		cout<<"("<<solucion[i].a()<<","<<solucion[i].b()<<")";
		if(i+1<solucion.size())
			cout<<" ";
	}
	cout<<";"<<endl;
	return 0;
}