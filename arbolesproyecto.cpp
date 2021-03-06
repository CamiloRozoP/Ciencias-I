#include<iostream>
using namespace std;
struct Nodo{
	int elemento;
	Nodo *izq;
	Nodo *der;
};
class ArbolBinario{
	protected:
		Nodo *raiz;
	public:
		ArbolBinario();
		Nodo *getRaiz();
		void setRaiz(Nodo *);
		Nodo *agregar(Nodo *,int);
		int eliminar(Nodo*);
		int profundidad(Nodo *);
		Nodo *buscar(Nodo*,int);
		int contar(Nodo*);
		int contarHojas(Nodo *);
		void mostrarPreorden(Nodo *);
		void mostrarPosorden(Nodo *);
		void mostrarInorden(Nodo *);
		void mostrarNiveles(Nodo *);
};
// EL GRADO ES EL NUMERO DE HIJOS DEL NODO
class ArbolBinarioOrdenado: public ArbolBinario{
		public:
			ArbolBinarioOrdenado();
			Nodo *agregar(Nodo*,int);
			Nodo *buscar(int);
			void eliminarElemento(int);
};
ArbolBinarioOrdenado::ArbolBinarioOrdenado(){  //CONSTRUCTOR ARBOL BINARIO ORDENADO
	raiz=NULL;
}
Nodo *ArbolBinarioOrdenado::agregar(Nodo *raiz,int elemento){ //METODO AGREGAR ARBOL BINARIO ORDENADO
	
	Nodo *p;
	if(raiz){
		if(elemento<raiz->elemento){
			raiz->izq=agregar(raiz->izq,elemento);
		}
		else{
			raiz->der=agregar(raiz->der,elemento);
		}
	}
	else
	{
		p=new Nodo;
		raiz=p;
		raiz->elemento=elemento;
		raiz->der=NULL;
		raiz->izq=NULL;
	}
	return raiz;
		
}
ArbolBinario::ArbolBinario(){ //CONSTRUCTOR ARBOL BINARIO 
	raiz=NULL;
}
Nodo *ArbolBinario::getRaiz(){ // GET ARBOL BINARIO 
	return raiz;
}
void ArbolBinario::setRaiz(Nodo *raiz){ //SET ARBOL BINARIO 
	this->raiz=raiz;
}
Nodo *ArbolBinario::agregar(Nodo *raiz,int elemento){//METODO AGREGAR ARBOL BINARIO.
	Nodo *p;
	if(raiz){
		if(profundidad(raiz->izq)<profundidad(raiz->der)){
			raiz->izq=agregar(raiz->izq,elemento);
		}
		else{
			raiz->der=agregar(raiz->der,elemento);
		}
	}
	else
	{
		p=new Nodo;
		raiz=p;
		raiz->elemento=elemento;
		raiz->der=NULL;
		raiz->izq=NULL;
	}
	return raiz;
	
}
int ArbolBinario::eliminar(Nodo *raiz){ // METODO ELIMINAR ARBOL BINARIO (X)
	Nodo *p=raiz;
	Nodo *q;
	int eliminado=p->elemento;
	if(raiz){
		if(profundidad(raiz->izq)>profundidad(raiz->der)){
			eliminado=eliminar(raiz->izq);
			q=raiz->izq;
		}
		else{
			q=raiz->der;
			eliminado=eliminar(raiz->der);
		}
	}
	else{
	eliminado=q->elemento;	
			
	}
	return eliminado;
		
}
int ArbolBinario::profundidad(Nodo *raiz){ //METODO PROFUNDIDAD ARBOL BINARIO 
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
void ArbolBinario::mostrarPreorden(Nodo *raiz){//METODO ARBOLBINARIO PRE-ORDEN 
	if(raiz){
		cout<<raiz->elemento<<" ";
		mostrarPreorden(raiz->izq);
		mostrarPreorden(raiz->der);
	}	
}
void ArbolBinario::mostrarPosorden(Nodo *raiz){//METODO ARBOLBINARIO POST-ORDEN 
	if(raiz){
		
		mostrarPosorden(raiz->izq);
		mostrarPosorden(raiz->der);
		cout<<raiz->elemento<<" ";
	}	
}
void ArbolBinario::mostrarInorden(Nodo *raiz){//METODO ARBOLBINARIO IN-ORDEN 
	if(raiz){
		
		mostrarInorden(raiz->izq);
		cout<<raiz->elemento<<" ";
		mostrarInorden(raiz->der);
	}	
}
int ArbolBinario::contar(Nodo *raiz){ //METODO CONTAR NODOS ARBOL BINARIO (X)
	
	
	
	return 0;
}

int ArbolBinario::contarHojas(Nodo * raiz){ //METODO CONTAR HOJAS ARBOL BINARIO (X)
	
return 0;	
}

Nodo * ArbolBinario::buscar(Nodo * raiz, int elemento){ //METODO  BUSCAR ARBOL BINARIO (X)
	
	return raiz;
}




char menuPrincipal(){
	char opcion;
	cout<<"\n MENU \n";
	cout<<"Arbol (B)inario \n";
	cout<<"Arbol Binario (O)rdenado \n";
	cout<<"(A)VL \n";
	cout<<"(S)alir \n";
	cin>>opcion;
	return opcion;
	
}
char menu(){
	char opcion;
	cout<<"(A)gregar \n";
	cout<<"(E)liminar \n";
	cout<<"(M)ostrar \n";
	cout<<"(B)uscar \n";
	cout<<"(C)ontar Nodos \n";
	cout<<"Contar (H)ojas  \n";
	cout<<"(T)erminar \n";
	cout<<"Escoja una opcion: ";
	cin>>opcion;
	return opcion;			
}	


int main(){
	int elemento;
	char opcionprincipal;
	char opcion;
	Nodo *raiz;
	do{
		opcionprincipal=menuPrincipal();
		switch(opcionprincipal){
		case 'b':
		case 'B':
		{
			cout<<"Bienvenido a Arbol Binario \n";
			ArbolBinario arbol;
			raiz=arbol.getRaiz();
			do{
				opcion=menu();
				switch(opcion){
					case 'a':
					case 'A':
						cout<<"Por favor ingrese el valor a a�adir al arbol \n";
						cin>>elemento;
						raiz=arbol.agregar(raiz,elemento);
						arbol.setRaiz(raiz);
						break;
					case 'e':
					case 'E':
						cout<<"El elemento eliminado es \n"<<arbol.eliminar(raiz);
						break;
					case 'm':
					case 'M':
						cout<<"Arbol en inorden \n";
						arbol.mostrarInorden(raiz);
						cout<<"\n";
						cout<<"Arbol preorden \n";
						arbol.mostrarPreorden(raiz);
						cout<<"\n";
						cout<<"Arbol postorden \n";
						arbol.mostrarPosorden(raiz);
						cout<<"\n";
						break;
					case 'b':
					case 'B':
						cout<<"Por favor ingrese el valor a buscar \n";
						cin>>elemento;
						arbol.buscar(raiz,elemento);
						break;
					case 'c':
					case 'C':
						cout<<"La cantidad de nodos del arbol es \n";
						arbol.contar(raiz);
						break;
					case 'h':
					case 'H':
						cout<<"La cantidad de hojas del arbol es \n"
						arbol.contarHojas(raiz);
						break;
					case 't':
					case 'T':
						break;
							
				}
			}while (opcion!='t' && opcion!='T');
			break;
		}
		case 'o':
		case 'O':
		{
			cout<<"Bienvenido a Arbol Binario Ordenado \n";
			ArbolBinarioOrdenado arbol;
			raiz=arbol.getRaiz();
			do{
				opcion=menu();
				switch(opcion){
					case 'a':
					case 'A':
						cout<<"Por favor ingrese el valor a a�adir al arbol \n";
						cin>>elemento;
						raiz=arbol.agregar(raiz,elemento);
						arbol.setRaiz(raiz);
						break;
					case 'e':
					case 'E':
						cout<<"El elemento eliminado es \n"<<arbol.eliminar(raiz);
						break;
					case 'm':
					case 'M':
						cout<<"Arbol en inorden \n";
						arbol.mostrarInorden(raiz);
						cout<<"\n";
						cout<<"Arbol preorden \n";
						arbol.mostrarPreorden(raiz);
						cout<<"\n";
						cout<<"Arbol postorden \n";
						arbol.mostrarPosorden(raiz);
						cout<<"\n";
						break;
					case 'b':
					case 'B':
						break;
					case 'c':
					case 'C':
						break;
					case 'h':
					case 'H':
						break;
					case 't':
					case 'T':
						break;
							
				}
			}while (opcion!='t' && opcion!='T');
			break;
		}
		case 'a':
		case 'A':
		{
			cout<<"Bienvenido a Arbol AVL";
			ArbolBinarioOrdenado arbol;
			raiz=arbol.getRaiz();
			do{
				opcion=menu();
				switch(opcion){
					case 'a':
					case 'A':
						cout<<"Por favor ingrese el valor a a�adir al arbol \n";
						cin>>elemento;
						raiz=arbol.agregar(raiz,elemento);
						arbol.setRaiz(raiz);
						break;
					case 'e':
					case 'E':
						cout<<"El elemento eliminado es \n"<<arbol.eliminar(raiz);
						break;
					case 'm':
					case 'M':
						cout<<"Arbol en inorden \n";
						arbol.mostrarInorden(raiz);
						cout<<"\n";
						cout<<"Arbol preorden \n";
						arbol.mostrarPreorden(raiz);
						cout<<"\n";
						cout<<"Arbol postorden \n";
						arbol.mostrarPosorden(raiz);
						cout<<"\n";
						break;
					case 'b':
					case 'B':
						break;
					case 'c':
					case 'C':
						break;
					case 'h':
					case 'H':
						break;
					case 't':
					case 'T':
						break;
							
				}
			}while (opcion!='t' && opcion!='T');
			break;
		}
		}
	}while (opcion!='s' && opcion!='S');
	/*
	ArbolBinarioOrdenado arbol;
	Nodo *raiz=arbol.getRaiz();
	
	char opcion;
	int elemento;
	do{
		opcion=menu();
		switch(opcion){
			case 'a':
			case 'A':
				cout<<"Por favor ingrese el valor a a�adir al arbol \n";
				cin>>elemento;
				raiz=arbol.agregar(raiz,elemento);
				arbol.setRaiz(raiz);
				break;
			case 'e':
			case 'E':
				cout<<"El elemento eliminado es \n"<<arbol.eliminar(raiz);
				break;
			case 'm':
			case 'M':
				cout<<"Arbol en inorden \n";
				arbol.mostrarInorden(raiz);
				cout<<"\n";
				cout<<"Arbol preorden \n";
				arbol.mostrarPreorden(raiz);
				cout<<"\n";
				cout<<"Arbol postorden \n";
				arbol.mostrarPosorden(raiz);
				cout<<"\n";
				break;
			case 'b':
			case 'B':
				break;
			case 'c':
			case 'C':
				break;
			case 'h':
			case 'H':
				break;
			case 't':
			case 'T':
				break;
				
		}
	}while (opcion!='t' && opcion!='T');
	
	ArbolBinario arbol;
	Nodo *raiz=arbol.getRaiz();
	raiz=arbol.agregar(raiz,30);
	arbol.setRaiz(raiz);
	raiz=arbol.agregar(raiz,70);
	arbol.setRaiz(raiz);
	raiz=arbol.agregar(raiz,10);
	arbol.setRaiz(raiz);
	raiz=arbol.agregar(raiz,80);
	arbol.setRaiz(raiz);
	cout<<"elementos del arbol \n";
	arbol.mostrarPreorden(raiz);
	*/
	
}
