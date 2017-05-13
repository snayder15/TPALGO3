#include <iostream>
#include "dijstra.h"

using namespace std;

int main(int argc,char * argv[]){
	vector<dijstra> problema;
	vector<pair<int,int> > ciudades;
	vector<int> max_k;
	int cant_ciudad,cant_rutas,k,ciudadOrigen,ciudadFinal;
	cout << "ingresar el numero de ciudades" << endl;
	cin >> cant_ciudad;
	cout << "ingresar el numero de rutas" << endl;
	cin >> cant_rutas;
	while(cant_ciudad!=-1&&cant_rutas!=-1){
		dijstra instancia;
		instancia.init(cant_ciudad,cant_rutas);
		cout << "ingrese ciudad inicial" <<endl;
		cin >> ciudadOrigen;
		cout << "ingrese ciudad final" <<endl;
		cin >> ciudadFinal;
		cout << "maxima de rutas premium a utilizar" <<endl;
		cin >> k;
		ciudades.push_back(make_pair(ciudadOrigen,ciudadFinal));
		max_k.push_back(k);
		for(int i=0; i < cant_rutas; i++){
			int nodoOrigen,nodoFin,premium,distancia;
			cout << "ingresar ciudad 1 ciudad 2 premium distancia" << endl;
			cin >> nodoOrigen;
			//cout << "ingresar ciudad final" << endl;
			cin >> nodoFin;
			//cout << "ingresar premium" << endl;
			cin >> premium;
			//cout << "ingresar distancia" << endl;
			cin >> distancia;
			instancia.cargar_ejes(nodoOrigen,nodoFin,distancia,premium);
		}
		problema.push_back(instancia);
		cout << "ingresar el numero de ciudades" << endl;
		cin >> cant_ciudad;
		cout << "ingresar el numero de rutas" << endl;
		cin >> cant_rutas;
	}

	for(unsigned int i=0;i<problema.size();i++){
		problema[i].armar_grafo(max_k[i]);
		problema[i].resolver(ciudades[i].first);
		cout << problema[i].distancia(ciudades[i].second) << endl;
	}

	
	return 0;
}