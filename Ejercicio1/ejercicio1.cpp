#include <iostream>
#include "dijstra.h"

using namespace std;

int main(int argc,char * argv[]){
	dijstra problema;
	problema.cargar_ejes();
	int k = 0;
	int ciudadOrigen = 0;
	int ciudadFinal = 0;
	cout << "ingrese ciudad inicial" <<endl;
	cin >> ciudadOrigen;
	cout << "ingrese ciudad final" <<endl;
	cin >> ciudadFinal;
	cout << "cantidad de rutas premium" <<endl;
	cin >> k;
	problema.armar_grafo(k);
	problema.resolver(ciudadOrigen);
	cout << problema.mostrar_solucion(ciudadOrigen,ciudadFinal,k) << endl;
	
	return 0;
}