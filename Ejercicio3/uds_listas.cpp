#include "uds_listas.h"
//Defino la clase de conjuntos disjuntos
uds_vector::uds_vector(){
}

void uds_vector::init(int n){
	padre.resize(n);
	altura.resize(n);
	for (int i=0;i<n;i++){
		altura[i]=1;
		padre[i]=i;
	}
}

int uds_vector::encontrar(int x){
	if(padre[x]!=x){
		padre[x]=encontrar(padre[x]);
	}
	return padre[x];
}

void uds_vector::union_uds(int x, int y){
	x = encontrar (x);
	y = encontrar (y); //Tomo los representantes de cada conjunto
	if (altura [x] < altura [y ]){
		padre[x]= y;
	}
	else{
		padre[y]= x;
	}
	if (altura[x] == altura[y]){
		altura [x]++;
	}
}
