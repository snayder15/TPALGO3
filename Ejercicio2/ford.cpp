#include "ford.h"

ford::ford(){
	maximo=INT_MIN;
	reduccion_peso_arista=0;
	cant_nodos=0;
}

void ford::init(int nodos,int aristas){
	maximo=INT_MIN;
	cant_nodos=nodos+1;
	cant_rutas=aristas;
	lista_adyacencia.resize(cant_nodos);
	for(unsigned int i=1;i<cant_nodos;i++){
		lista_adyacencia[0].push_back(make_pair(i,0));
	}
}

int ford::max(){
	return maximo;
}

void ford::cargar_ejes(int origen,int destino,int peaje){
	lista_adyacencia[origen].push_back(make_pair(destino,peaje));
	if(peaje>maximo)
		maximo=peaje;
}

void ford::mostrar_adyacentes(){
	cout<<"nodos: "<< cant_nodos<<" aristas: "<<cant_rutas<<endl;
	for(unsigned int i=0;i<cant_nodos;i++){
		for(unsigned int j=0;j<lista_adyacencia[i].size();j++){
			cout<<"("<<i<<","<<lista_adyacencia[i][j].first<<" peso "<<lista_adyacencia[i][j].second<<") ";
		}
		cout<<endl;
	}
}

void ford::armar_grafo(int k){
	reduccion_peso_arista=k;
}

bool ford::resolver(int origen){
	// inicializamos el grafo. Ponemos distancias a INFINITO menos el nodo origen que 
    // tiene distancia 0
    vector<int> distancia(cant_nodos,INT_MAX);
	distancia[origen]=0;
	// relajamos cada arista del grafo tantas veces como número de nodos -1 haya en el grafo
	for (unsigned int i=0;i<cant_nodos-1	;i++){
		for(unsigned int origen=0;origen<lista_adyacencia.size();origen++){
			for(unsigned int vecino=0;vecino<lista_adyacencia[origen].size();vecino++){
				int peso=lista_adyacencia[origen][vecino].second-reduccion_peso_arista;
				int nodo_vecino=lista_adyacencia[origen][vecino].first;
				if(distancia[origen]!=INT_MAX){
					if (distancia[nodo_vecino]>distancia[origen] + peso){
						distancia[nodo_vecino] = distancia[origen] + peso;
					}
				}
			}
		}
	}	

	// comprobamos si hay ciclos negativo
	for(unsigned int origen=0;origen<lista_adyacencia.size();origen++){
		for(unsigned int vecino=0;vecino<lista_adyacencia[origen].size();vecino++){
			int peso=lista_adyacencia[origen][vecino].second-reduccion_peso_arista;
			int nodo_vecino=lista_adyacencia[origen][vecino].first;
			if (distancia[nodo_vecino]>distancia[origen] + peso){
				return false;
			}
		}
	}
	return true;
}

int ford::mostrar_solucion(){
	return reduccion_peso_arista;
}