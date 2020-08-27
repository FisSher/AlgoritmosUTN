/*
Para los siguientes ejercicios utilizaremos un nodo que contiene un registro con los
datos:
- Legajo
- Nombre y Apellido
- Curso

Ejercicio Nro. 1:
Dada una cola, desarrollar un procedimiento que elimine 2 nodos de la misma (indicar
con un parámetro 'S'/'N' si ello fue‚ o no posible)

Ejercicio Nro. 2:
Dada una cola, desarrollar una función que devuelva la cantidad de nodos que tiene.

Ejercicio Nro. 3:
Dadas dos colas COLA y COLB, desarrollar un procedimiento que genere una única cola
COLC a partir de ellas. (Primero los nodos de COLA y luego los de COLB).

Ejercicio Nro. 4:
Dada una cola, imprimirla en orden natural si tiene más de 100 nodos, caso contrario
imprimirla en orden inverso.

Ejercicio Nro. 5:
Dadas dos colas COLA y COLB, desarrollar un procedimiento que genere otra cola COLC
por apareo del campo LEGAJO del registro (define orden creciente en ambas).
Nota: COLA y COLB dejan de ser útiles después del apareo.
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

void encolar(Nodo*& cFte, Nodo*& cFin, int v);
void encolar(NodoEstudiante*& cFte, NodoEstudiante*& cFin, est v);
int desencolar(Nodo*& cFte, Nodo*& cFin);
//Ejercicio 1
est desencolar(NodoEstudiante*& cFte, NodoEstudiante*& cFin);
char eliminarNodos(NodoEstudiante*& cfte, NodoEstudiante*& cfin, int cantNodosAEliminar);
//Ejercicio 2
int contarNodos(NodoEstudiante*& cfte, NodoEstudiante*& cfin);
void agregarNodo(NodoEstudiante*& p, est x);
est eliminarPrimerNodo(NodoEstudiante*& p);
//Ejercicio 3
void combinarColas(NodoEstudiante*& cfteA, NodoEstudiante*& cfinA,
	NodoEstudiante*& cfteB, NodoEstudiante*& cfinB,
	NodoEstudiante*& cfteC, NodoEstudiante*& cfinC);
//Ejercicio 4
void imprimirCola(NodoEstudiante*& cfte, NodoEstudiante*& cfin);
est pop(NodoEstudiante*& p);
void push(NodoEstudiante*& p, est v);
//Ejercicio 5
void apareo(NodoEstudiante*& cfteA, NodoEstudiante*& cfinA,
	NodoEstudiante*& cfteB, NodoEstudiante*& cfinB,
	NodoEstudiante*& cfteC, NodoEstudiante*& cfinC);

int main()
{
	est aux;
	//Ejercicio 1

	NodoEstudiante* cfte = NULL;
	NodoEstudiante* cfin = NULL;

	aux.legajo = 123444;
	strcpy(aux.nya, "pepe");
	aux.curso = 1053;
	encolar(cfte, cfin, aux);

	aux.legajo = 1345678;
	strcpy(aux.nya, "ale");
	aux.curso = 1051;
	encolar(cfte, cfin, aux);

	aux.legajo = 4451;
	strcpy(aux.nya, "vir");
	aux.curso = 1043;
	encolar(cfte, cfin, aux);

	aux.legajo = 654;
	strcpy(aux.nya, "facu");
	aux.curso = 1034;
	encolar(cfte, cfin, aux);

	/*
	char resultado = eliminarNodos(cfte, cfin, 1);
	if (resultado == 'S') {
		cout << "Se pudo eliminar" << endl;
	}
	else
	{
		cout << "No se pudo eliminar" << endl;
	}

	while (cfte != NULL)
	{
		aux = desencolar(cfte, cfin);
		cout << aux.legajo << endl;
		cout << aux.nya << endl;
		cout << aux.curso << endl;
	}

	*/
	//EJ 2
	/*
	cout << "En la cola hay: " << contarNodos(cfte, cfin) << " nodos" << endl;

	while (cfte!=NULL)
	{
		aux = desencolar(cfte, cfin);
		cout << aux.legajo << endl;
		cout << aux.nya << endl;
		cout << aux.curso << endl;
	}
	*/

	//Ejercicio 3

	NodoEstudiante* cfte1 = NULL;
	NodoEstudiante* cfin1 = NULL;
	NodoEstudiante* cfte2 = NULL;
	NodoEstudiante* cfin2 = NULL;
	NodoEstudiante* cfte3 = NULL;
	NodoEstudiante* cfin3 = NULL;

	aux.legajo = 1;
	strcpy(aux.nya, "pepe");
	aux.curso = 1053;
	encolar(cfte1, cfin1, aux);

	aux.legajo = 3;
	strcpy(aux.nya, "ale");
	aux.curso = 1051;
	encolar(cfte1, cfin1, aux);

	aux.legajo = 2;
	strcpy(aux.nya, "vir");
	aux.curso = 1043;
	encolar(cfte2, cfin2, aux);

	aux.legajo = 4;
	strcpy(aux.nya, "facu");
	aux.curso = 1034;
	encolar(cfte2, cfin2, aux);

	/*
	combinarColas(cfte1, cfin1, cfte2, cfin2, cfte3, cfin3);

	while (cfte3 != NULL)
	{
		aux = desencolar(cfte3, cfin3);
		cout << aux.legajo << endl;
		cout << aux.nya << endl;
		cout << aux.curso << endl;
	}
	*/
	//Ejercicio 4

	imprimirCola(cfte, cfin);

	//Ejercicio 5

	apareo(cfte1, cfin1, cfte2, cfin2, cfte3, cfin3);
	while (cfte3 != NULL)
	{
		aux = desencolar(cfte3, cfin3);
		cout << aux.legajo << endl;
		cout << aux.nya << endl;
		cout << aux.curso << endl;
	}
}

void encolar(NodoEstudiante*& cFte, NodoEstudiante*& cFin, est v) {
	NodoEstudiante* nuevo = new NodoEstudiante();
	nuevo->info = v;
	nuevo->sig = NULL;
	if (cFte == NULL)
		cFte = nuevo;
	else
		cFin->sig = nuevo;

	cFin = nuevo;
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
est desencolar(NodoEstudiante*& cFte, NodoEstudiante*& cFin) {
	est retorno = cFte->info;
	NodoEstudiante* aux = cFte;
	cFte = aux->sig;
	if (cFte == NULL)
		cFin = NULL;

	delete aux;

	return retorno;
}
char eliminarNodos(NodoEstudiante*& cfte, NodoEstudiante*& cfin, int cantNodosAEliminar) {
	int contador = 0;
	char resultado;

	while (cfte != NULL && contador < cantNodosAEliminar)
	{
		desencolar(cfte, cfin);
		contador++;
	}

	if (contador == cantNodosAEliminar)
	{
		resultado = 'S';
	}
	else
	{
		resultado = 'N';
	}

	return resultado;
}
int contarNodos(NodoEstudiante*& cfte, NodoEstudiante*& cfin) {
	int contador = 0;
	NodoEstudiante* lista = NULL;
	while (cfte != NULL)
	{
		agregarNodo(lista, desencolar(cfte, cfin));

		contador++;
	}
	while (lista != NULL)
	{
		encolar(cfte, cfin, eliminarPrimerNodo(lista));
	}

	return contador;
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
est eliminarPrimerNodo(NodoEstudiante*& p) {
	est retorno = p->info;
	NodoEstudiante* aux = p;
	p = p->sig;
	delete aux;
	return retorno;
}
void combinarColas(NodoEstudiante*& cfteA, NodoEstudiante*& cfinA, NodoEstudiante*& cfteB, NodoEstudiante*& cfinB, NodoEstudiante*& cfteC, NodoEstudiante*& cfinC) {
	while (cfteA != NULL)
	{
		encolar(cfteC, cfinC, desencolar(cfteA, cfinA));
	}
	while (cfteB != NULL)
	{
		encolar(cfteC, cfinC, desencolar(cfteB, cfinB));
	}
}
void imprimirCola(NodoEstudiante*& cfte, NodoEstudiante*& cfin) {
	int resultado = contarNodos(cfte, cfin);
	est aux;
	if (resultado > 100) {
		while (cfte != NULL)
		{
			aux = desencolar(cfte, cfin);
			cout << aux.legajo << endl;
			cout << aux.nya << endl;
			cout << aux.curso << endl;
		}
	}
	else
	{
		NodoEstudiante* pila = NULL;
		while (cfte != NULL)
		{
			push(pila, desencolar(cfte, cfin));
		}
		while (pila != NULL)
		{
			aux = pop(pila);
			cout << aux.legajo << endl;
			cout << aux.nya << endl;
			cout << aux.curso << endl;
		}
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
void apareo(NodoEstudiante*& cfteA, NodoEstudiante*& cfinA, NodoEstudiante*& cfteB, NodoEstudiante*& cfinB, NodoEstudiante*& cfteC, NodoEstudiante*& cfinC)
{
	while (cfteA != NULL && cfteB != NULL)
	{
		if (cfteA->info.legajo > cfteB->info.legajo) {
			encolar(cfteC, cfinC, desencolar(cfteA, cfinA));
		}
		else
		{
			encolar(cfteC, cfinC, desencolar(cfteB, cfinB));
		}
	}
	while (cfteA != NULL)
	{
		encolar(cfteC, cfinC, desencolar(cfteA, cfinA));
	}
	while (cfteB != NULL)
	{
		encolar(cfteC, cfinC, desencolar(cfteB, cfinB));
	}
}
NodoEstudiante* insertarOrdenado(NodoEstudiante*& p, est v) {
	NodoEstudiante* nuevo = new NodoEstudiante();
	nuevo->info = v;
	nuevo->sig = NULL;
	NodoEstudiante* ant = NULL;
	NodoEstudiante* aux = p;
	while (aux != NULL && aux->info.legajo <= v.legajo)
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