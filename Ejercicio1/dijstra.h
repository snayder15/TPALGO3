#ifndef dijstra_h
#define dijstra_h

class dijstra{
	public:
		void cargar_ejes();
		void armar_grafo(int k);
		void resolver();
	private:
		vector<vector<pair<int,int> > > lista_adyacencia_solucion;
		int ciudades;
		int cant_rutas;
};
#endif