#include "dijstra.h"

dijstra::dijstra(){
}

void dijstra::init(int nodos,int aristas){
	cant_ciudad=nodos;
	cant_rutas=aristas;	
	lista_adyacencia_normal.resize(nodos);
	lista_adyacencia_premium.resize(nodos);
}

void dijstra::cargar_ejes(int origen,int destino,int peso, int premium){
	if(premium == 1){
		lista_adyacencia_premium[origen-1].push_back (make_pair(destino-1,peso));
		lista_adyacencia_premium[destino-1].push_back (make_pair(origen-1,peso));			
	}else{
		lista_adyacencia_normal[origen-1].push_back (make_pair(destino-1,peso));
		lista_adyacencia_normal[destino-1].push_back (make_pair(origen-1,peso));
	}
}
void dijstra::armar_grafo(int k){
	lista_adyacencia_total.resize(cant_ciudad*(k+1));	
	// Creo el grafo G' el cual tiene nodos (n*k+1)
	for (int i=0; i < cant_ciudad; i++){
		for (unsigned int j=0; j < lista_adyacencia_normal[i].size();j++){
			pair<int,int> arista1 = lista_adyacencia_normal[i][j];
			for(int t=0; t < k+1;t++){
				lista_adyacencia_total[t*cant_ciudad + i].push_back(make_pair((t)*cant_ciudad + arista1.first,arista1.second));
			}
		}
		for (unsigned int j=0; j < lista_adyacencia_premium[i].size();j++){
			pair<int,int> arista = lista_adyacencia_premium[i][j];
			for(int t=0; t < k;t++){
				lista_adyacencia_total[t*cant_ciudad + i].push_back(make_pair((t+1)*cant_ciudad + arista.first,arista.second));
			}
		}
	}
}


void dijstra::resolver(int nodoOrigen){
	//Inicializo las distancias al maximo posible
	vector<bool> visitados(lista_adyacencia_total.size(),false);
	vector<int> dist(lista_adyacencia_total.size(),INT_MAX);
	//Pongo el nodo origen con distancia 0
	dist[nodoOrigen-1] = 0;
	for(unsigned i = 0; i < lista_adyacencia_total.size();i++){
		int vertice = 0;
		int minimo = INT_MAX;
		//busco el nodo con menor distancia que no fue visitado
		for(unsigned j = 0; j < dist.size();j++){
			if(!(visitados[j])&& (dist[j] < minimo ))
				vertice = j;
		}
		if(!visitados[vertice]){
			visitados[vertice] = true;
			//solo reviso los adyacente de vertice (W) que no fueron visitados
			for(unsigned t = 0; t < lista_adyacencia_total[vertice].size();t++){
				pair<int,int> arista=lista_adyacencia_total[vertice][t];
				int x = dist[vertice] + arista.second;
				//actualizo si la distancia es menor
				if(dist[arista.first] > x)
					dist[arista.first] = x;
			}
		}
	}
	distancias=dist;
}

int dijstra::distancia(int ciudad){
	int resultado=INT_MAX;
	for(int i=0;i<int(distancias.size());i++){
		if((i%cant_ciudad)==(ciudad-1)){
			if(resultado>distancias[i])
				resultado=distancias[i];
		}
	}
	if(resultado==INT_MAX)
		return -1;
	return resultado;
}

void dijstra::mostrar_grafo(){
	unsigned int n = lista_adyacencia_total.size();
	cout<<"nodos: "<< n <<" aristas: "<<cant_rutas<<endl;
	for(unsigned int i=0;i<n;i++){
		if(i/cant_ciudad==0)
			cout<<endl;
		for(unsigned int j=0;j<lista_adyacencia_total[i].size();j++){
			cout<<"("<<i+1<<","<<lista_adyacencia_total[i][j].first+1<<" peso "<<lista_adyacencia_total[i][j].second<<") ";
		}	
	}
}

