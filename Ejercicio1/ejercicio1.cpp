#include <iostream>
#include "dijstra.h"

using namespace std;

int main(int argc,char * argv[]){
	dijstra problema;
	problema.cargar_ejes();
	problema.armar_grafo(10,1,3);
	problema.resolver();
	problema.mostrar_solucion();
	return 0;
}