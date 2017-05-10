#ifndef aristas_h
#define aristas_h
using namespace std;
class aristas{
	public:
	aristas();
	aristas(int a,int b,int peso);
	int const a()const;
	int const b()const;
	int const peso()const;
	void definir(int a,int b,int peso);
	bool const operator <(const aristas a)const;
	bool const operator >(const aristas a)const;
	private:
	int origen;
	int destino;
	int w;
};
#endif