// Listas.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

struct Nodo {
	int info;
	Nodo* sig;
};

void agregarNodo(Nodo*& p, int x);
void mostrar(Nodo* p);
void liberar(Nodo*& p);
Nodo* buscar(Nodo* p, int v);
void eliminar(Nodo*& p, int v);
int eliminarPrimerNodo(Nodo*& p);
Nodo* insertarOrdenado(Nodo*& p, int v);
void ordenar(Nodo*& p);
Nodo* buscaEInsertaOrdenado(Nodo*& p, int v, bool& enc);


int main()
{


}

void agregarNodo(Nodo*& p, int x)
{
	Nodo* nuevo = new Nodo();
	nuevo->info = x;
	nuevo->sig = NULL;
	if (p == NULL) //La lista p esta vacia
	{
		p = nuevo;
	}
	else
	{
		Nodo* aux = p;
		while (aux->sig != NULL)
		{
			aux = aux->sig;
		}
		aux->sig = nuevo;
	}
}

void mostrar(Nodo* p) {
	Nodo* aux = p;
	while (aux != NULL)
	{
		cout << aux->info << endl;
		aux = aux->sig;
	}
}

void liberar(Nodo*& p) {
	Nodo* aux;
	while (p != NULL)
	{
		aux = p;
		p = p->sig;
		delete aux;
	}
}

Nodo* buscar(Nodo* p, int v)
{
	Nodo* aux = p;
	while (aux != NULL && aux->info != v)
	{
		aux = aux->sig;
	}
	return aux;
}

void eliminar(Nodo*& p, int v) {
	Nodo* aux = p;
	Nodo* ant = NULL;
	while (aux != NULL && aux->info != v)
	{
		ant = aux;
		aux = aux->sig;
	}
	if (ant == NULL) { //Estamos eliminando el primer nodo
		p = aux->sig;
	}
	else {
		ant->sig = aux->sig;
	}
	delete aux;
}

int eliminarPrimerNodo(Nodo*& p) {
	int retorno = p->info;
	Nodo* aux = p;
	p = p->sig;
	delete aux;
	return retorno;
}

Nodo* insertarOrdenado(Nodo*& p, int v) {
	Nodo* nuevo = new Nodo();
	nuevo->info = v;
	nuevo->sig = NULL;
	Nodo* ant = NULL;
	Nodo* aux = p;
	while (aux != NULL && aux->info <= v)
	{
		ant = aux;
		aux = aux->sig;
	}
	if (ant == NULL) { //estoy insertando al principio.
		p = nuevo;
	}
	else
	{
		ant->sig = nuevo;
	}
	nuevo->sig = aux;

	return nuevo;
}

void ordenar(Nodo*& p) {

	Nodo* q = NULL;
	int valor;
	while (p != NULL) {
		valor = eliminarPrimerNodo(p);
		insertarOrdenado(q, valor);
	}
	p = q;
}

Nodo* buscaEInsertaOrdenado(Nodo*& p, int v, bool& enc) {
	Nodo* nodoBuscado = buscar(p, v);
	if (nodoBuscado != NULL)
	{
		enc = true;
	}
	else {
		nodoBuscado = insertarOrdenado(p, v);
		enc = false;
	}
	return nodoBuscado;
}
