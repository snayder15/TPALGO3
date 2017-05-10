#include "aristas.h"
//Defino la clase eje
aristas::aristas(){
	origen=0;
	destino=0;
	w=-1;
}
aristas::aristas(int a, int b,int peso){
	if(a<b){
		origen=a;
		destino=b;
	}
	else{
		origen=b;
		destino=a;
	}
	w=peso;
}

int const aristas::a()const{
	return origen;
}

int const aristas::b()const{
	return destino;
}
int const aristas::peso()const{
	return w;
}

void aristas::definir(int a,int b,int peso){
	origen=a;
	destino=b;
	w=peso;
}

bool const aristas::operator <(const aristas a)const{
	return w<a.w;
}

bool const aristas::operator >(const aristas a)const{
	return w>a.w;
}
