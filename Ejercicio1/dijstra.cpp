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
	for(int i=0; i < cant_rutas; i++){
		cout << "ingresar ciudad de origen" << endl;
		cin >> nodoOrigen;
		cout << "ingresar ciudad final" << endl;
		cin >> nodoFin;
		cout << "ingresar premium" << endl;
		cin >> premium;
		cout << "ingresar distancia" << endl;
		cin >> distancia;
		pair <int,int> arista;
		arista = make_pair(nodofin-1,distancia);
		if(premium == 1){
			lista_adyacencia_premium[nodoOrigen-1].push_back (arista);			
		}else{
			lista_adyacencia_normal[nodoOrigen-1].push_back (arista);
		}
	}

}
void dijstra::armar_grafo(int k){


}

void dijstra::resolver(){

}

void dijstra::mostrar_solucion(){
	
}