#include <iostream>
#include <stdlib.h>
#include <conio.h>
using namespace std;

struct Nodo{
	Nodo *derecho;
	int dato;
	Nodo *izquierdo;
};

void menu();
Nodo *nDinamico(int dato);
void inNodo(Nodo *&,int);
void imprimirDatos(Nodo *,int);

int main(){
	char opcion;
	Nodo *arbol=NULL;
	int numero;
	int numDatos;
	
	do{
		int contador=0;
		menu();
		cin>>opcion;
		fflush(stdin);
		switch(opcion){
			case '1':
				cout<<"\n\t1.Ingresar datos que desees ."<<endl;
				cout<<"Cuantos numeros deseas agregar  "; cin>>numDatos;
				for(int i=0; i<numDatos; i++){
					cout<<"Ingrese el  numero "<<i+1<<" :"; cin>>numero;
					nDinamico(numero);
					inNodo(arbol,numero);
				}
				break;
			case '2':
				cout<<"\n\t2.Mostrar datos.\n\n\n";
				imprimirDatos(arbol,contador);
				cout<<endl;
				break;
			case '3':
				cout<<"\nSalio del programa."<<endl;
				break;
			default:
				cout<<"\nError: Opcion invalida."<<endl;
				break;
		}
		cout<<"\nPresione una tecla para continuar.."<<endl;
		getch();
		system("cls");
	}while(opcion !='3');
	
	return 0;
}


void menu(){
	cout<<"\tMENU"<<endl
	    <<"1.Anotar los datos ."<<endl
	    <<"2.Mostrar los  datos."<<endl
	    <<"3.Salir."<<endl
	    <<"Ingrese el numero que quiera------> ";
	    
}

Nodo *nDinamico(int dato){
    Nodo *nNodo = new Nodo();

	nNodo->dato = dato;
	nNodo->derecho = NULL;
	nNodo->izquierdo = NULL;
	
	return nNodo;
}

 
void inNodo(Nodo *&arbol,int dato){
	
	if(arbol==NULL){
		Nodo *nNodo = nDinamico(dato);
		arbol = nNodo;
	}else{
		if(dato < arbol->dato){
			inNodo(arbol->izquierdo,dato);
		}else{
			inNodo(arbol->derecho,dato);
		}
	}
}

void imprimirDatos(Nodo *arbol,int contador){
	
	if(arbol == NULL){
		return;
	}else{
		imprimirDatos(arbol->derecho,contador+1);
		for(int i=0; i<contador; i++){
			cout<<"   ";
		}
		cout<<arbol->dato<<endl;
		imprimirDatos(arbol->izquierdo,contador+1);
	}
	
}
