#include "dijstra.h"

dijstra::dijstra(){
}

void dijstra::cargar_ejes(){
	cout << "ingresar el numero de ciudades" << endl;
	cin >> ciudades;
	cout << "ingresar el numero de rutas" << endl;
	cin >> cant_rutas;
	lista_adyacencia_normal.resize(ciudades);
	lista_adyacencia_premium.resize(ciudades);
	int nodoOrigen = 0;
	int nodoFin = 0;
	int premium = 0;
	int distancia = 0;
	for(unsigned int i=0; i < cant_rutas; i++){
		cout << "ingresar ciudad de origen" << endl;
		cin >> nodoOrigen;
		cout << "ingresar ciudad final" << endl;
		cin >> nodoFin;
		cout << "ingresar premium" << endl;
		cin >> premium;
		cout << "ingresar distancia" << endl;
		cin >> distancia;
		if(premium == 1){
			lista_adyacencia_premium[nodoOrigen-1].push_back (make_pair(nodoFin-1,distancia));			
		}else{
			lista_adyacencia_normal[nodoOrigen-1].push_back (make_pair(nodoFin-1,distancia));
		}
	}

}
void dijstra::armar_grafo(unsigned int k, int cuidadSalidad, int cuidadEntrada){
	vector<vector<pair<int,int> > > lista_adyacencia_total;
	lista_adyacencia_total.resize(ciudades*(k+1));	
	int distanciaPremium;
	// Creo el grafo G' el cual tiene nodos (n*k+1)
	for (unsigned int i=0; i < cuidades; i++){
		for (unsigned int j=0; j < lista_adyacencia_normal[i].size();j++){
			for(unsigned int t=0; t < k+1;t++){
				lista_adyacencia_total[k*ciudades + i][j].push_back(lista_adyacencia_normal[i][j]);
			}
		}
		for (unsigned int j=0; j < lista_adyacencia_normal[i].size();j++){
			for(unsigned int t=0; t < k+1;t++){
				if(t < k){
					pair arista = lista_adyacencia_normal[i][j]
					lista_adyacencia_total[k*ciudades + i][j].push_back(make_pair((k+1)*arista.first,arista.second));
				}
			}
		}
	}
	
}


void dijstra::resolver(){

}

void dijstra::mostrar_solucion(){
	
}