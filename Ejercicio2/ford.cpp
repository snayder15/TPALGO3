#include "ford.h"

ford::ford(){
	minimo=INT_MAX;
	maximo=INT_MIN;
	reduccion_peso_arista=0;
	cant_nodos=0;
}

int ford::max(){
	return maximo;
}

int ford::min(){
	return minimo;
}

void ford::cargar_ejes(int nodos,int aristas){
	ciudades=nodos;
	lista_adyacencia.resize(nodos+1);
	cant_rutas=aristas;
	for(int i=0;i<cant_rutas;i++){
		cout<<"ingresar ruta "<<i+1<<endl;
		int origen,destino,peaje;
		cin>>origen; //Cargamos la primer ciudad
		cin>>destino;
		cin>>peaje;
		lista_adyacencia[origen].push_back(make_pair(destino,peaje));
		if(peaje>maximo)
			maximo=peaje;
		if(peaje<minimo)
			minimo=peaje;
	}
	for(int i=1;i<nodos+1;i++){
		lista_adyacencia[0].push_back(make_pair(i,0));
	}
	cant_nodos=nodos+1;
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