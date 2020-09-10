/*
1. Realizar una función que reciba un array de char con una secuencia de
paréntesis y llaves, y devuelva si está balanceada o no. Por ejemplo:
a. Entrada: “[()]{}{[()()]()}”
Salida: true
b. Entrada: “[(])”
Salida: false
2. Realizar una función que reciba un array de char con una expresión en notación
polaca inversa, y devuelva el resultado.
Por ejemplo: La expresión algebraica 5+((1+2)*4)-3 se traduce a la notación
polaca inversa como 5 1 2 + 4 * + 3 - y se evalúa de izquierda a derecha
3. Ingresar una secuencia de caracteres, que termine con -1 e imprimirla en orden
inverso.
a. Imitar el funcionamiento de la pila utilizando un array.
b. Imitar el funcionamiento de la pila utilizando dos colas.
Redefinir PUSH y POP.

*/

#include <iostream>
using namespace std;

struct Nodo {
	char info;
	Nodo* sig;
};

struct NodoInt {
	int info;
	NodoInt* sig;
};

bool verificarBalanceo(char arr[], int len);
int calculoPolaco(char arr[], int len);
void pushConArray(char vec[], int& len, char valor);
char popConArray(char vec[], int& len);
void pushConCola(Nodo*& cfte, Nodo*& cfin, char valor);

int main()
{
	//Ejercicio 1
	/*
	char arr[4] = { '[','(',')',']' };
	int lenarr = 4;

	bool res=verificarBalanceo(arr, lenarr);

	if (res)
		cout << "Balancea";
	else
		cout << "No balancea";
		*/
		//Ejercicio 2
		/*
		char vec[5] = { '2','4','+','5','-' };
		int len = 5;
		cout<<calculoPolaco(vec, len);
		*/
		//Ejercicio 3

	char vecPila[50];
	int len = 0;
	pushConArray(vecPila, len, 'c');
	pushConArray(vecPila, len, 'd');
	pushConArray(vecPila, len, 'r');
	pushConArray(vecPila, len, 'f');
}

char pop(Nodo*& p) {
	char retorno = p->info;
	Nodo* aux = p;
	p = aux->sig;
	delete aux;
	return retorno;
}

int pop(NodoInt*& p) {
	char retorno = p->info;
	NodoInt* aux = p;
	p = aux->sig;
	delete aux;
	return retorno;
}

void push(Nodo*& p, int v) {
	Nodo* nuevo = new Nodo();
	nuevo->info = v;
	nuevo->sig = p;
	p = nuevo;
}
void push(NodoInt*& p, int v) {
	NodoInt* nuevo = new NodoInt();
	nuevo->info = v;
	nuevo->sig = p;
	p = nuevo;
}

bool verificarBalanceo(char arr[], int len) {
	Nodo* pila = new Nodo();
	bool resultado = true;
	for (int x = 0; x < len; x++)
	{
		switch (arr[x])
		{
		case '[':
			push(pila, arr[x]);
			break;
		case '(':
			push(pila, arr[x]);
			break;
		case '{':
			push(pila, arr[x]);
			break;
		case ')':
			if (pop(pila) != '(')
				resultado = false;
			break;
		case ']':
			if (pop(pila) != '[')
				resultado = false;
			break;
		case '}':
			if (pop(pila) != '{')
				resultado = false;
			break;
		default:
			break;
		}
	}

	return resultado;
}
int calculoPolaco(char arr[], int len) {
	NodoInt* pila = new NodoInt();
	int numero1 = 0;
	int numero2 = 0;
	for (int i = 0; i < len; i++)
	{
		switch (arr[i])
		{
		case'+':
			numero1 = pop(pila);
			numero2 = pop(pila);
			push(pila, (numero1 + numero2));
			break;
		case'*':
			numero1 = pop(pila);
			numero2 = pop(pila);
			push(pila, (numero1 * numero2));
			break;
		case'-':
			numero1 = pop(pila);
			numero2 = pop(pila);
			push(pila, (numero2 - numero1));
			break;
		default:
			push(pila, arr[i] - '0');
			break;
		}
	}
	return pop(pila);
}
//Ej3
void pushConArray(char vec[], int& len, char valor) {
	for (int i = len - 1; i >= 0; i--)
	{
		vec[i + 1] = vec[i];
	}
	vec[0] = valor;
	len++;
}

char popConArray(char vec[], int& len) {
	char ret = vec[0];
	for (int i = 0; i < len; i++)
	{
		vec[i] = vec[i + 1];
	}

	len--;
	return ret;
}

void pushConCola(Nodo*& cfte, Nodo*& cfin, char valor) {
	Nodo* cfteAxu = NULL;
	Nodo* cfinAux = NULL;
	encolar(cfteAxu, cfinAux, valor);

	while (cfte != NULL)
	{
		encolar(cfteAxu, cfinAux, desencolar(cfte, cfin));
	}

	cfte = cfteAxu;
	cfin = cfinAux;
}

char popConCola(Nodo*& cfte, Nodo*& cfin) {
	return desencolar(cfte, cfin);
}

void encolar(Nodo*& cFte, Nodo*& cFin, char v) {
	Nodo* nuevo = new Nodo();
	nuevo->info = v;
	nuevo->sig = NULL;
	if (cFte == NULL)
		cFte = nuevo;
	else
		cFin->sig = nuevo;

	cFin = nuevo;
}

char desencolar(Nodo*& cFte, Nodo*& cFin) {
	char retorno = cFte->info;
	Nodo* aux = cFte;
	cFte = aux->sig;
	if (cFte == NULL)
		cFin = NULL;

	delete aux;

	return retorno;
}