#include <iostream>
#include "ford.h"

using namespace std;

int main(int argc,char * argv[]){
	vector<ford> problemas;
	int ciudad=0,cant_rutas=0;
	cout<<"ingrese el numero de ciudades"<<endl;
	cin>>ciudad;
	cout<<"ingrese el numero de rutas"<<endl;
	cin>>cant_rutas;
	while((ciudad!=-1)&&(cant_rutas!=-1)){
		ford instancia;
		instancia.cargar_ejes(ciudad,cant_rutas);
		problemas.push_back(instancia);
		cout<<"ingrese el numero de ciudades"<<endl;
		cin>>ciudad;
		cout<<"ingrese el numero de rutas"<<endl;
		cin>>cant_rutas;
	}
	problemas[0].mostrar_adyacentes();
	for(unsigned int i=0;i<problemas.size();i++){
		cout<<"Resolviendo "<<i<<" problemas"<<endl;
		int minimo=0;
		int maximo=problemas[i].max();
		int promedio;
		while(minimo<=maximo){
			promedio=(minimo+maximo)/2;
			problemas[i].armar_grafo(promedio);
			if(problemas[i].resolver(0)){
				minimo=promedio+1;
			}
			else{
				maximo=promedio-1;
			}
			promedio=(minimo+maximo)/2;
		}
		if(problemas[i].resolver(0)){
			problemas[i].armar_grafo(promedio+1);
			if(problemas[i].resolver(0)){
				cout<<"infinito"<<endl;
			}
			else{
				cout<<problemas[i].mostrar_solucion()-1<<endl;
			}

		}
		else{
			cout<<problemas[i].mostrar_solucion()-1<<endl;
		}

		
	}
	return 0;
}