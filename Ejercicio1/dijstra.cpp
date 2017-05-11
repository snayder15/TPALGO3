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
			for(unsigned int t=0; t < k+1;t++){
				lista_adyacencia_total[t*ciudades + i].push_back(lista_adyacencia_normal[i][j]);
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
	vector<int> distancias; 
	vector<int> antecesor;
	inicializacion (visitados,distancias,antecesor);

	

}

void dijstra::inicializacion(vector<bool>& visitados,vector<int>& distancias,vector<int>& antecesor){
	visitados.resize(lista_adyacencia_total.size());
	distancias.resize(lista_adyacencia_total.size());
	antecesor.resize(lista_adyacencia_total.size());
	for(unsigned i = 0; i < lista_adyacencia_total.size(),i++){
		visitados[i] = 0;
		distancias[i] = INT_MAX;
		antecesor[i] = -1;
	}
}



void dijstra::mostrar_solucion(){
	unsigned int n = lista_adyacencia_total.size();
	cout<<"nodos: "<< n <<" aristas: "<<cant_rutas<<endl;
	for(unsigned int i=0;i<n;i++){
		for(unsigned int j=0;j<lista_adyacencia_total[i].size();j++){
			cout<<"("<<i<<","<<lista_adyacencia_total[i][j].first<<" peso "<<lista_adyacencia_total[i][j].second<<") ";
		}
		cout<<endl;
	}
}