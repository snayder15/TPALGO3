#include <stdio.h>
#include <disjtra.h>

int main(int argc,char * argv[]){
	disjtra problema;
	problema.cargar_ejes();
	problema.armar_grafo();
	problema.resolver();
	problema.mostrar_solucion();
	return 0;
}