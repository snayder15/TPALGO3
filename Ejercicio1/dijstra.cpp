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
	for (unsigned int i=0; i < k+1; i++){
		for (unsigned int j=0; j < ciudades;j++){
			if(i < k){
				lista_adyacencia_total[k*ciudades + j] = lista_adyacencia_normal[j];
				//creo las aristas diagonales
				for (unsigned int t=0; t < ciudades;t++){
					//veo si existe la arista en diagonal premium y si exite me traigo la distancia
					if(esVecinoPremium(j,t,distanciaPremium)){
						lista_adyacencia_total[k*ciudades +j].push_back (make_pair((k+1)*ciudades + t,distanciaPremium));
					}
				}		
			}else{
				lista_adyacencia_total[k*ciudades + j] = lista_adyacencia_normal[j];
			}
		}
	}

}

bool dijstra::esVecinoPremium(int cuidadOrigen, int ciudadFin, int& distancia){
	bool existeArista = false;
	for (unsigned int i=0; i < lista_adyacencia_premium[cuidadOrigen].size();i++){
		if(lista_adyacencia_premium[cuidadOrigen][i].first == ciudadFin){
			distancia = lista_adyacencia_premium[cuidadOrigen][i].second;
			existeArista = true;
		}	
	}
	return existeArista;
}

void dijstra::resolver(){

}

void dijstra::mostrar_solucion(){
	
}