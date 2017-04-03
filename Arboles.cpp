#include <iostream>
using namespace std;
struct Nodo{
	int elemento;
	Nodo *izq;
	Nodo * der;
};

class ArbolBinario{
	private:
		Nodo *raiz;
	public:
		ArbolBinario();
		Nodo *getRaiz();
		void setRaiz(Nodo *);
		Nodo *agregar(Nodo* ,int);
		int eliminar();
		int profundidad(Nodo *);
		void mostrarPreorden(Nodo *);
	
};
ArbolBinario::ArbolBinario(){
	raiz=NULL;	
}

Nodo*ArbolBinario::getRaiz(){
	return raiz;
}

void ArbolBinario::setRaiz(Nodo *raiz){
	this->raiz=raiz;
	
}

Nodo *ArbolBinario::agregar(Nodo *raiz,int elemento){
	Nodo *p=new Nodo;
	if(raiz)
		if (profundidad(raiz->izq)<profundidad(raiz->der))
			raiz->izq=agregar(raiz->izq,elemento);
		else
			raiz->der=agregar(raiz->der,elemento);
	else{
		raiz=p;
		raiz->elemento=elemento;
		raiz->izq=NULL;
		raiz->der=NULL;
		
	}
	return raiz;
}
ArbolBinario::eliminar(){
}
ArbolBinario::profundidad(Nodo *raiz){
	int profIzq,profDer;
	if(raiz){
		profIzq=profundidad(raiz->izq);
		profDer=profundidad(raiz->der);
		if(profIzq>profDer)
			return profIzq+1;
		return profDer+1;
	}
	return 0;	
}
void ArbolBinario::mostrarPreorden(Nodo *raiz){
	if (raiz){
		cout<<raiz->elemento<<" ";
		mostrarPreorden(raiz->izq);
		mostrarPreorden(raiz->der);
	}
}
int main(){
	ArbolBinario arbol;
	Nodo *raiz=arbol.getRaiz();
	raiz=arbol.agregar(raiz,30);
	arbol.setRaiz(raiz);
	raiz=arbol.agregar(raiz,70);
	arbol.setRaiz(raiz);
	raiz=arbol.agregar(raiz,10);
	arbol.setRaiz(raiz);
	raiz=arbol.agregar(raiz,88);
	arbol.setRaiz(raiz);
	cout<<"Elementos en el arbol \n";
	arbol.mostrarPreorden(raiz);
}

