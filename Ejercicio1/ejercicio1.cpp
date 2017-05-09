#include <iostream>
#include "disjtra.h"
#include "disjtra.h"
using namespace std;

int main(int argc,char * argv[]){
	disjtra problema;
	problema.cargar_ejes();
	problema.armar_grafo();
	problema.resolver();
	problema.mostrar_solucion();
	return 0;
}