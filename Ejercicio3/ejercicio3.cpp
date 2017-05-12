#include <iostream>
#include "agm.h"
#include "aristas.h"

using namespace std;

int main(int argc,char * argv[]){
	vector<agm> problema;
	int ciudad=0;	
	cout<<"ingrese el numero de ciudades"<<endl;
	cin>>ciudad;
	while(ciudad!=-1){
		agm instancia;
		instancia.definir_nodos(ciudad);
		int kn=ciudad*(ciudad-1)/2;
		for(int i=0;i<kn;i++){
			int origen,dest,tipo,peso;
			cin>>origen;
			cin>>dest;
			cin>>tipo;
			cin>>peso;
			instancia.agregar_ejes(origen-1,dest-1,peso,tipo);
		}
		problema.push_back(instancia);
		cout<<"ingrese el numero de ciudades"<<endl;
		cin>>ciudad;
	}
	for(unsigned int i=0;i<problema.size();i++){
		cout<<"Resolviendo problema "<<i<<endl;	
		vector<aristas> solucion=problema[i].buscar_AGMAXMIN();
		cout<<problema[i].costo()<<" "<<solucion.size();
		for(unsigned int j=0;j<solucion.size();j++)
			cout<<"("<<solucion[j].a()<<", "<<solucion[j].b()<<") ";
		cout<<endl;	
	}
	return 0;
}