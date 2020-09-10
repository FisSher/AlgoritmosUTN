/*
Ejercicio Nro. 1:
Dada una lista, desarrollar una función que devuelva la cantidad de nodos que
tiene.

Ejercicio Nro. 2:
Dadas dos listas LISTA y LISTB, desarrollar un procedimiento que genere una
única lista LISTC a partir de ellas. (Primero los nodos de LISTA y luego los de
LISTB).

Ejercicio Nro. 3:
Dada una LISTA, imprimirla en orden natural si tiene más de 100 nodos, caso
contrario imprimirla en orden inverso.

Ejercicio Nro. 4:
Dadas dos listas LISTA y LISTB, desarrollar un procedimiento que genere otra
lista LISTC por apareo del campo LEGAJO del registro (define orden creciente
en ambas).
Nota: LISTA y LISTB dejan de ser útiles después del apareo.

Ejercicio Nro. 5:
Dado un archivo de registros de estudiantes (ARCHA). Se debe desarrollar el
programa que genere un archivo ARCHL igual al anterior pero ordenado por
número de legajo.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

struct Nodo {
	int info;
	Nodo* sig;
};

struct est {
	int legajo;
	char nya[50];
	int curso;
};

struct NodoEstudiante {
	est info;
	NodoEstudiante* sig;
};

void agregarNodo(Nodo*& p, int x);
void agregarNodo(NodoEstudiante*& p, est x);
void mostrar(Nodo* p);
void mostrar(NodoEstudiante* p);
void liberar(Nodo*& p);
Nodo* buscar(Nodo* p, int v);
void eliminar(Nodo*& p, int v);
int eliminarPrimerNodo(Nodo*& p);
Nodo* insertarOrdenado(Nodo*& p, int v);
void ordenar(Nodo*& p);
Nodo* buscaEInsertaOrdenado(Nodo*& p, int v, bool& enc);

//Ejercicio 1
int contarNodos(NodoEstudiante*& p);
//Ejercicio 2
void combinarListas(NodoEstudiante*& ListaA, NodoEstudiante*& ListaB, NodoEstudiante*& ListaC);
//Ejercicio 3
void imprimirLista(NodoEstudiante*& p);
//Ejercicio 4
NodoEstudiante* insertarOrdenado(NodoEstudiante*& p, est v);
void apareoListasSinEliminarNodo(NodoEstudiante* listaA, NodoEstudiante* listaB, NodoEstudiante*& listaC);
void apareoListas(NodoEstudiante*& listaA, NodoEstudiante*& listaB, NodoEstudiante*& listaC);
//Ejercicio 5
est pop(NodoEstudiante*& p);
void push(NodoEstudiante*& p, est v);
int main()
{
	/* Ejercicio 3
	NodoEstudiante* listaA = NULL;
	NodoEstudiante* listaB = NULL;
	NodoEstudiante* listaC = NULL;
	est aux;

	aux.legajo = 123444;
	strcpy(aux.nya, "pepe");
	aux.curso = 1053;
	agregarNodo(listaA, aux);

	aux.legajo = 1345678;
	strcpy(aux.nya, "ale");
	aux.curso = 1051;
	agregarNodo(listaA, aux);

	aux.legajo = 4451;
	strcpy(aux.nya, "vir");
	aux.curso = 1043;
	agregarNodo(listaB, aux);

	aux.legajo = 654;
	strcpy(aux.nya, "facu");
	aux.curso = 1034;
	agregarNodo(listaB, aux);


	cout << "La lista tiene " << contarNodos(listaA) << " nodos." << endl;

	combinarListas(listaA, listaB, listaC);
	*/
	//Listas - ejercicio 4
	NodoEstudiante* listaA = NULL;
	NodoEstudiante* listaB = NULL;
	NodoEstudiante* listaC = NULL;

	est datos;
	datos.legajo = 4451;
	strcpy(datos.nya, "pepe");
	datos.curso = 1053;
	agregarNodo(listaA,datos);

	datos.legajo = 153444;
	strcpy(datos.nya, "ale");
	datos.curso = 1051;
	agregarNodo(listaA,datos);

	datos.legajo = 654;
	strcpy(datos.nya, "vir");
	datos.curso = 1043;
	agregarNodo(listaB,datos);

	datos.legajo = 123444;
	strcpy(datos.nya, "facu");
	datos.curso = 1034;
	agregarNodo(listaB,datos);

	apareoListasSinEliminarNodo(listaA, listaB, listaC);

	while(listaC != NULL) {
		cout << listaC->info.legajo << endl;
		cout << listaC->info.nya << endl;
		cout << listaC->info.curso << endl;
		listaC = listaC->sig;
	}
	

	/*FILE* archa = fopen("archa.dat","wb+");

	est datos;
	datos.legajo = 153444 ;
	strcpy(datos.nya, "pepe");
	datos.curso = 1053;
	fwrite(&datos,sizeof(est),1,archa);

	datos.legajo = 4451;
	strcpy(datos.nya, "ale");
	datos.curso = 1051;
	fwrite(&datos,sizeof(est),1,archa);

	datos.legajo = 123444;
	strcpy(datos.nya, "vir");
	datos.curso = 1043;
	fwrite(&datos,sizeof(est),1,archa);

	datos.legajo = 654;
	strcpy(datos.nya, "facu");
	datos.curso = 1034;
	fwrite(&datos,sizeof(est),1,archa);

	datos.legajo = 0;
	strcpy(datos.nya,"");
	datos.curso = 0;

	rewind(archa);

	fread(&datos,sizeof(est),1,archa);

	while(!feof(archa)){
		cout << datos.legajo << endl;
		cout << datos.nya << endl;
		cout << datos.curso << endl;
		fread(&datos,sizeof(est),1,archa);
	}

	fclose(archa);*/

	//Ejercicio 5
/*


	FILE* archa = fopen("archa.dat", "rb");

	est reg;
	NodoEstudiante* lista = NULL;

	fread(&reg, sizeof(est), 1, archa);

	while (!feof(archa)) {
		insertarOrdenado(lista, reg);
		fread(&reg, sizeof(est), 1, archa);
	}

	fclose(archa);

	FILE* archl = fopen("archl.dat", "wb+");

	NodoEstudiante * aux = lista;
	while (aux != NULL) {
		fwrite(&aux->info, sizeof(est), 1, archl);
		aux = aux->sig;
	}

	rewind(archl);

	fread(&reg, sizeof(est), 1, archl);

	while (!feof(archl)) {
		cout << reg.legajo << endl;
		cout << reg.nya << endl;
		cout << reg.curso << endl;
		fread(&reg, sizeof(est), 1, archl);
	}

	fclose(archl);*/
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

void agregarNodo(NodoEstudiante*& p, est x)
{
	NodoEstudiante* nuevo = new NodoEstudiante();
	nuevo->info = x;
	nuevo->sig = NULL;
	if (p == NULL) //La lista p esta vacia
	{
		p = nuevo;
	}
	else
	{
		NodoEstudiante* aux = p;
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

void mostrar(NodoEstudiante* p) {
	NodoEstudiante* aux = p;
	while (aux != NULL)
	{
		cout << aux->info.nya << endl;
		cout << aux->info.curso << endl;
		cout << aux->info.legajo << endl;
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

est eliminarPrimerNodo(NodoEstudiante*& p) {
	est retorno = p->info;
	NodoEstudiante* aux = p;
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

NodoEstudiante* insertarOrdenado(NodoEstudiante*& p, est v) {
	NodoEstudiante* nuevo = new NodoEstudiante();
	nuevo->info = v;
	nuevo->sig = NULL;
	NodoEstudiante* ant = NULL;
	NodoEstudiante* aux = p;

	while (aux != NULL && aux->info.legajo <= v.legajo) {
		ant = aux;
		aux = aux->sig;
	}

	if (ant == NULL) { //Estoy insertando al principio
		p = nuevo;
	}
	else {
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

int contarNodos(NodoEstudiante*& p) {
	NodoEstudiante* aux = p;
	int contador = 0;
	while (aux != NULL ) {
		aux = aux->sig;
		contador++;
	}
	return contador;
}

void combinarListas(NodoEstudiante*& ListaA, NodoEstudiante*& ListaB, NodoEstudiante*& ListaC) {
	NodoEstudiante* auxA = ListaA;
	NodoEstudiante* auxB = ListaB;
	
	while (auxA != NULL)
	{
		agregarNodo(ListaC, auxA->info);
	}
	while (auxB !=NULL)
	{
		agregarNodo(ListaC, auxB->info);
	}
}

void combinarListasEliminando(NodoEstudiante*& ListaA, NodoEstudiante*& ListaB, NodoEstudiante*& ListaC) {
	while (ListaA!=NULL)
	{
		agregarNodo(ListaC, eliminarPrimerNodo(ListaA));
	}
	
	while (ListaB!=NULL)
	{
		agregarNodo(ListaC, eliminarPrimerNodo(ListaA));
	}
	
}

void imprimirLista(NodoEstudiante*& p) {
	int cantNodos = contarNodos(p);

	if (cantNodos > 100) {
		mostrar(p);
	}
	else
	{
		NodoEstudiante* pila = NULL;
		NodoEstudiante* aux = NULL;
		while (p!=NULL)
		{
			push(pila, aux->info);
			aux = aux->sig;
		}
		est datosDelNodo;
		while (pila!=NULL)
		{
			datosDelNodo = pop(pila);
			cout << datosDelNodo.legajo << endl;
			cout << datosDelNodo.nya << endl;
			cout << datosDelNodo.curso << endl;

		}

	}
}

void apareoListasSinEliminarNodo(NodoEstudiante* listaA, NodoEstudiante* listaB, NodoEstudiante*& listaC) {
	NodoEstudiante* auxA = listaA;
	NodoEstudiante* auxB = listaB;

	while (auxA != NULL && auxB != NULL) {
		if (auxA->info.legajo < auxB->info.legajo) {
			agregarNodo(listaC, auxA->info);
			auxA = auxA->sig;
		}
		else {
			agregarNodo(listaC, auxB->info);
			auxB = auxB->sig;
		}
	}

	while (auxA != NULL) {
		agregarNodo(listaC, auxA->info);
		auxA = auxA->sig;
	}

	while (auxB != NULL) {
		agregarNodo(listaC, auxB->info);
		auxB = auxB->sig;
	}
}

void apareoListas(NodoEstudiante*& listaA, NodoEstudiante*& listaB, NodoEstudiante*& listaC) {
	while (listaA != NULL && listaB != NULL) {
		if (listaA->info.legajo < listaB->info.legajo) {
			agregarNodo(listaC, eliminarPrimerNodo(listaA));
		}
		else {
			agregarNodo(listaC, eliminarPrimerNodo(listaB));
		}
	}

	while (listaA != NULL) {
		agregarNodo(listaC, eliminarPrimerNodo(listaA));
	}

	while (listaB != NULL) {
		agregarNodo(listaC, eliminarPrimerNodo(listaB));
	}
}

est pop(NodoEstudiante*& p) {
	est retorno = p->info;
	NodoEstudiante* aux = p;
	p = aux->sig;
	delete aux;
	return retorno;
}

void push(NodoEstudiante*& p, est v) {
	NodoEstudiante* nuevo = new NodoEstudiante();
	nuevo->info = v;
	nuevo->sig = p;
	p = nuevo;
}