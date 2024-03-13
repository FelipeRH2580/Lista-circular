#include <iostream>

using namespace::std;

struct nodo{
	int dato;
	int min;
	int max;
	nodo* siguiente;
} *primero, *ultimo;


void insertarNodo();
void desplegarLista();
void sumarTodos();


int main(){
	int tam;
	cout<<"Digita la cantidad de datos que deseas ingresar en la lista: "; cin>>tam;
	for(int i = 1; i <= tam; i++) {
		insertarNodo();
	}
	cout << " \n\n LISTA";
	desplegarLista();
	sumarTodos();
	return 0;
}


void insertarNodo(){
	nodo* nuevo = new nodo();
	cout << "\nIngrese el dato: ";
	cin >> nuevo->dato; 
	
	if(primero==NULL){
		primero = nuevo;
		primero->siguiente = primero;
		ultimo = primero;
	}else{
		ultimo->siguiente = nuevo;
		nuevo->siguiente = primero;
		ultimo = nuevo;
	}
}

void desplegarLista(){
	nodo* actual = new nodo();
	actual = primero;
	if(primero!=NULL){
		do{
			cout << "\n " << actual->dato << "\n";
			actual = actual->siguiente;
		}while(actual!=primero);
	}else{
		cout << "\n La lista se encuentra vacia\n\n";
	}
}

void sumarTodos() {
	nodo* actual = primero;
	int suma = 0;
	do {
		suma += actual->dato;
		actual = actual->siguiente;
	} while (actual != primero);
	cout << "\nLa suma de todos los elementos en la lista es: " << suma << endl;
}