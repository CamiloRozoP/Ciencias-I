#include <iostream>
using namespace std;



struct Nodo{
	int elemento;
	Nodo * izq;
	Nodo* der;
};

class ArbolBinario{
	private:
	Nodo *raiz;
	public:
		ArbolBinario()
		{
		raiz=NULL;
					} 
		void agregar(int);
		int eliminar();
		int profundidad();	
		void recorridoPreorden();
		void recorridoInorden();
		void recorridoPostorden();
		void recorridoNiveles();
		int cantidadNodos();
		int cantidadHojas();
		Nodo *buscar(int);
};
int ArbolBinario::profundidad(Nodo * raiz){
	int profizq  , profder;
	if (raiz){
		profizq=profundidad(raiz->izq)
		profder=profundidad(raiz-der)
		if(profizq>profder)
			return profizq+1;
		return profder+1;
	}
	return 0;
}

int ArbolBinario::agregar(){
	
	
	
	
	
}


