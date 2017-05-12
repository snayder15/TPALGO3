#include "agm.h"

#include <functional>
//Defino la clase agm
agm::agm(){
	cant_nodos=0;
}

void agm::definir_nodos(int nodos){
	cant_nodos=nodos;
	list_ejes_solucion.resize(0);
}

void agm::agregar_ejes(int origen,int destino,int peso,int tipo){
	aristas eje(origen,destino,peso);
	if(tipo==0){
		list_destruccion.push_back(eje);
	}
	else{
		list_construccion.push_back(eje);
	}
}

bool menor(aristas a,aristas b){
	return a<b;	
}

bool mayor(aristas a,aristas b){
	return a>b;	
}

vector<aristas> agm::buscar_AGMAXMIN(){
	uds_vector comp_conex;
	sort(list_destruccion.begin(),list_destruccion.end(),mayor);
	sort(list_construccion.begin(),list_construccion.end(),menor);
	vector<aristas> e_dest=list_destruccion;
	vector<aristas> e_const=list_construccion;
	comp_conex.init(cant_nodos);
	costo_total=0;
	//Primero destruimos todos los ciclos
	for (unsigned int i=0;i<e_dest.size();i++){
		if(comp_conex.encontrar(e_dest[i].a())!=comp_conex.encontrar(e_dest[i].b())){
			comp_conex.union_uds(e_dest[i].a(),e_dest[i].b());
			list_ejes_solucion.push_back(e_dest[i]);
		}
		else{
			//La ruta fue destruida, aumenta el costo
			costo_total+=e_dest[i].peso();
		}
	}
	//Ahora agregamos las rutas que falten para reducir el costo
	for(unsigned int j=0;j<e_const.size();j++){
		if(comp_conex.encontrar(e_const[j].a())!=comp_conex.encontrar(e_const[j].b())){
			comp_conex.union_uds(e_const[j].a(),e_const[j].b());
			costo_total+=e_const[j].peso();
		}
	}
	return list_ejes_solucion;
}

void agm::mostrar_adyacentes(){
	cout<<"nodos: "<< cant_nodos<<endl;
	for(unsigned int i=0;i<list_destruccion.size();i++){
		cout<<"("<<list_destruccion[i].a()<<","<<list_destruccion[i].b()<<" peso "<<list_destruccion[i].peso()<<") ";
	}
	for(unsigned int i=0;i<list_construccion.size();i++)
		cout<<"("<<list_construccion[i].a()<<","<<list_construccion[i].b()<<" peso "<<list_construccion[i].peso()<<") ";
}

int agm::costo(){
	return costo_total;
}

vector<aristas> agm::solucion(){
	return list_ejes_solucion;
}

ostream& operator<<( ostream &output,const agm &a ) { 
	output <<a.costo_total<<" "<<a.list_ejes_solucion.size();
	for(unsigned int i=0;i<a.list_ejes_solucion.size();i++){
		output<<" ("<<a.list_ejes_solucion[i].a()<<","<<a.list_ejes_solucion[i].b()<<")";
	}
	return output;            
}