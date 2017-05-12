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
			lista_adyacencia_premium[nodoFin-1].push_back (make_pair(nodoOrigen-1,distancia));			
		}else{
			lista_adyacencia_normal[nodoOrigen-1].push_back (make_pair(nodoFin-1,distancia));
			lista_adyacencia_normal[nodoFin-1].push_back (make_pair(nodoOrigen-1,distancia));
		}
	}

}
void dijstra::armar_grafo(unsigned int k, int cuidadEntrada ,int cuidadSalida){
	lista_adyacencia_total.resize(ciudades*(k+1));	
	// Creo el grafo G' el cual tiene nodos (n*k+1)
	for (unsigned int i=0; i < ciudades; i++){
		for (unsigned int j=0; j < lista_adyacencia_normal[i].size();j++){
			pair<int,int> arista1 = lista_adyacencia_normal[i][j];
			for(unsigned int t=0; t < k+1;t++){
				lista_adyacencia_total[t*ciudades + i].push_back(make_pair((t)*ciudades + arista1.first,arista1.second));
			}
		}
		for (unsigned int j=0; j < lista_adyacencia_premium[i].size();j++){
			pair<int,int> arista = lista_adyacencia_premium[i][j];
			for(unsigned int t=0; t < k;t++){
				lista_adyacencia_total[t*ciudades + i].push_back(make_pair((t+1)*ciudades + arista.first,arista.second));
			}
		}
	}
}


void dijstra::resolver(int nodoOrigen){
	vector<bool> visitados;  
	inicializacion (visitados);
	distancias[nodoOrigen-1] = 0;
	for(unsigned i = 0; i < lista_adyacencia_total.size();i++){
		int vertice = -1;
		int minimo = INT_MAX;
		//busco el nodo con menor distancia que no fue visitado
		for(unsigned j = 0; j < lista_adyacencia_total.size();j++){
			if(!(visitados[j])&& visitados[j] < minimo ){
				vertice = j;
			}
		}
		visitados[vertice] = true;
		//solo reviso los adyacente de vertice (W) que no fueron visitados
		for(unsigned t = 0; t < lista_adyacencia_total[vertice].size();t++){
			if(!(visitados[t])){
				int x = distancias[vertice] + lista_adyacencia_total[vertice][t].second;
				if(distancias[t] > x){
					distancias[t] = x;
				}
			}
		}
	}

}

void dijstra::inicializacion(vector<bool>& visitados){
	visitados.resize(lista_adyacencia_total.size());
	distancias.resize(lista_adyacencia_total.size());
	for(unsigned i = 0; i < lista_adyacencia_total.size();i++){
		visitados[i] = false;
		distancias[i] = INT_MAX;
	}
}

void dijstra::mostrar_solucion(){

}

void dijstra::mostrar_grafo(){
	unsigned int n = lista_adyacencia_total.size();
	cout<<"nodos: "<< n <<" aristas: "<<cant_rutas<<endl;
	for(unsigned int i=0;i<n;i++){
		for(unsigned int j=0;j<lista_adyacencia_total[i].size();j++){
			cout<<"("<<i<<","<<lista_adyacencia_total[i][j].first<<" peso "<<lista_adyacencia_total[i][j].second<<") ";
		}
		cout<<endl;
	}
}