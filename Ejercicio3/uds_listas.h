#ifndef uds_listas_h
#define uds_listas_h
#include <vector>
using namespace std;
//Defino la clase de conjuntos disjuntos
class uds_vector{
	public:
	uds_vector();
	void init(int n);
	int encontrar(int x);
	void union_uds(int x,int y);
	private:
	vector<int> altura;
	vector<int> padre;
};
#endif