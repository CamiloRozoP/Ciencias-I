#include <iostream>
using namespace std;

struct Nodo {
	int elemento;
	int izq;
	int der;
};
class Arbolbinario{
	int numNodos;
	Nodo *arbol[];
	public:
		ArbolBinario();
		int agregar (int ,int); //recursivo
		void mostrarInorden(int ); //recursivo 
		void mostrarPostorden(int);
		void mostrarPreorden(int );
		int buscar(int);
		
};

Arbolbinario::ArbolBinario(int numNodos){
	this->numNodos=numNodos;
	arbol=new Nodos[numNodos];
	arbol[0].der=-1;
	for (int k=0;k<numNodos-1;k++)
	arbol[k].izq=k+1;  // indica que el siguiente esta disponible en la lista
	arbol[numNodos-1].izq=-1; //el ultimo tiene que ser -1 
}

int Arbolbinario::agregar(int raiz , int elemento){
	if(raiz!=-1){
		if(arbol[raiz].elemento>elemento)
			arbol[raiz].izq=agregar(arbol[raiz].izq,elemento)
		else
			 arbol[raiz].der=agregar(arbol[raiz].der, elemento)
	}
	else {
		raiz=arbol[0].izq;
		arbol[0].izq=arbol[raiz].izq; //actualiza el valor en la lista
		arbol[raiz].elemento=elemento;
		arbol[raiz].izq=-1;
		arbol[raiz].der=-1;
		
	}
	return raiz;
}


void Arbolbinario::mostrarInorden(int raiz){
		
} 
void Arbolbinario::mostrarPostorden(int raiz){
		
} 
void Arbolbinario::mostrarPreorden(int raiz){	
} 

int ArbolBinario::buscar(int elemento){
} 
