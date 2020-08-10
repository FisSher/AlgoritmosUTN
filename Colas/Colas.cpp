// Colas.cpp : This file contains the 'main' function. Program execution begins and ends there.



#include <iostream>
using namespace std;
struct Nodo {
	int info;
	Nodo* sig;
};

void encolar(Nodo*& cFte, Nodo*& cFin, int v);
int desencolar(Nodo*& cFte, Nodo*& cFin);

int main()
{
	//Ejercicio 1 

}

void encolar(Nodo*& cFte, Nodo*& cFin, int v) {
	Nodo* nuevo = new Nodo();
	nuevo->info = v;
	nuevo->sig = NULL;
	if (cFte == NULL)
		cFte = nuevo;
	else
		cFin->sig = nuevo;

	cFin = nuevo;
}

int desencolar(Nodo*& cFte, Nodo*& cFin) {
	int retorno = cFte->info;
	Nodo* aux = cFte;
	cFte = aux->sig;
	if (cFte == NULL)
		cFin = NULL;

	delete aux;

	return retorno;
}