#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "funciones.hpp"
using namespace std;

//Ej1
/*Crear un procedimiento que dadas dos listas A y B,
llene una lista C con la unión (sin repetidos) de las listas A y B.*/
/*
struct NodoB {
	NodoB* sig;
	int info;
};

struct NodoA {
	NodoA* sig;
	int info;
};

struct NodoC {
	NodoC* sig;
	int info;
};

void llenarLista(NodoA* listaA, NodoB* listaB, NodoC*& listaC) {
	bool enc;

	while (listaA != NULL)
	{
		buscaEInserta(listaC, listaA->info, enc);
		listaA = listaA->sig;
	}
	while (listaB != NULL)
	{
		buscaEInserta(listaC, listaB->info, enc);
		listaB = listaB->sig;
	}
}

int main() {
	NodoA* listaA = NULL;
	NodoB* listaB = NULL;
	NodoC* listaC = NULL;

	for (int i = 1; i < 5; i++)
	{
		agregar(listaA, i);
	}
	for (int j = 1; j < 8; j++)
	{
		agregar(listaB, j);
	}

	llenarLista(listaA, listaB, listaC);
	mostrar(listaC);
}
*/

//Ej2
/* En el archivo “turnos20201031.dat” tenemos el listado de turnos de un consultorio para un día en particular.
De los turnos sabemos la hora (integer) y el nombre del paciente.
Ordenar la información contenida en el archivo por hora y colocarlo en una cola para que puedan ser llamados.*/
/*
struct turno {
	int hora;
	char paciente[50];
};

struct NodoCola {
	NodoCola* sig;
	turno info;
};

struct NodoLista {
	NodoLista* sig;
	turno info;
};

void encolar(NodoCola*& p, NodoCola*& q, turno v);
NodoLista* insertarOrdenado(NodoLista*& p, turno v);

int main() {
	NodoLista* listaPacientes = NULL;
	NodoCola* cfte = NULL;
	NodoCola* cfin = NULL;
	FILE* turnos = fopen("turnos20201031.dat", "rb");
	turno regTurno;
	turno regLista;
	turno regCola;

	fread(&regTurno, sizeof(turno), 1, turnos);
	while (!feof(turnos))
	{
		regLista.hora = regTurno.hora;
		strcpy(regLista.paciente, regTurno.paciente);
		insertarOrdenado(listaPacientes, regLista);

		fread(&regTurno, sizeof(turno), 1, turnos);
	}
	fclose(turnos);

	//Ahora tengo la lista con los turnos ordenados de menor a mayor.

	while (listaPacientes!=NULL)
	{
		encolar(cfte,cfin,listaPacientes->info);
		listaPacientes = listaPacientes->sig;
	}

	//acá está encolada la lista.
}
*/
//Ej3
/*Desarrollar un procedimiento que permita ingresar caracteres por teclado.
Si se ingresa una letra(A - Z) se inserta en la pila.
Si se ingresa un asterisco se saca un elemento de la pila. char
Imprimir la secuencia de caracteres que se sacaron de la pila.
El ingreso de caracteres termina cuando se ingresa un punto.

Nota: El valor ascii de la A es 65 y el de la Z es 90.*/

/*
struct NodoPila {
	NodoPila* sig;
	char info;
};
void push(NodoPila*& p, char v);
char pop(NodoPila*& p);

int main() {
	NodoPila* pila = NULL;
	char valorIngresado;

	cout << "Ingresar caracter: ";
	cin >> valorIngresado;

	while (valorIngresado !='.')
	{
		if (valorIngresado >= 65 && valorIngresado <= 90)
			 push(pila, valorIngresado);
		if (valorIngresado == '*')
			cout << "Letra extraida: " << pop(pila) << endl;;

		cout << "Ingresar caracter: ";
		cin >> valorIngresado;
	}

	//Ahora queda hacer el pop de todo lo que hay dentro de la pila
	cout << "Los valores restantes son: " << endl;
	while (pila != NULL) {
		cout << pop(pila) << endl;
	}
}
*/

//Ej4
/*
Se tiene un archivo “ventas.dat” que contiene los siguientes datos:
número de cliente, artículo comprado, cantidad comprada y precio unitario.
Con estos datos llenar una lista que debe contener número de cliente y dinero gastado.
A su vez cada nodo de esa lista, va a poseer una sublista de los artículos comprados,
junto con su cantidad comprada y precio unitario.
Nota: El precio unitario para cada artículo no varía.
Si el artículo se repite por cada cliente debe incrementarse su cantidad vendida.

Informar:

	Cuál es el cliente que menos dinero gastó.
	Cuál es el cliente que más unidades totales de productos compró.
*/

struct Venta {
	int numeroCliente;
	int articulo;
	int cantidad;
	float precioUnitario;
};

struct InfoArt {
	int cantidadComprada;
	float precioUnitario;
	int id;
};

struct Articulo {
	Articulo* sig;
	InfoArt info;
};

struct InfoCliente {
	int numeroCliente;
	float dineroGastado;
	Articulo* articulos;
};

struct Cliente {
	Cliente* sig;
	InfoCliente info;
};

int main() {
	FILE* ventas = fopen("ventas.dat", "rb");
	Venta regVenta;
	InfoCliente regCli;
	InfoArt regArt;
	Cliente* listaClientes = NULL;
	bool enc;
	Articulo* artBuscado;
	Cliente* cliBuscado;

	fread(&regVenta, sizeof(Venta), 1, ventas);

	while (!feof(ventas))
	{
		//Extraigo datos del cliente.
		regCli.numeroCliente = regVenta.numeroCliente;
		regCli.dineroGastado = 0;
		regCli.articulos = NULL;
		//Busco si el cliente existe.
		cliBuscado = buscaEInserta(listaClientes, regCli, enc);

		//Extraigo datos del articulo
		regArt.id = regVenta.articulo;
		regArt.cantidadComprada = regVenta.cantidad;

		//Busco e inserto el articulo en la lista de articulos de clientes.
		artBuscado = buscaEInserta(listaClientes->info.articulos, regArt, enc);

		//Si lo encuentra lo suma
		if (enc)
			artBuscado->info.cantidadComprada += regArt.cantidadComprada;

		listaClientes->info.dineroGastado += regArt.cantidadComprada * regArt.precioUnitario;

		fread(&regVenta, sizeof(Venta), 1, ventas);
	}
	fclose(ventas);

	float menosDineroGastado = 9999999;  //Menor dinero gastado global
	int MasUniProdCompradas = 0; //La cantidad de unidades compradas maxima
	int clienteMasCompras = 0;  //El cliente que mas unidades compro
	int cliMenosDineroGastado = 0;  //El cliente que menos dinero gasto
	int unidadesCompradas = 0; //Unidades compradas local

	//Copio la lista total por comodidad
	Cliente* listaAux = listaClientes;

	//Recorro
	while (listaAux != NULL)
	{
		//Hago una copia de la lista de articulos.
		Articulo* listaArtAux = listaAux->info.articulos;

		//Vacio la lista de los articulos
		while (listaArtAux != NULL)
		{
			//Sumo la cantidad de unidades que compro el cliente de todos los articulos (no decia que sea uno solo)
			unidadesCompradas += listaArtAux->info.cantidadComprada;
			//avanzo
			listaArtAux = listaArtAux->sig;
		}

		//Cuando termino el recorrido de la lista, comparo.
		if (unidadesCompradas > MasUniProdCompradas) {
			MasUniProdCompradas = unidadesCompradas;
			clienteMasCompras = listaAux->info.numeroCliente;
		}

		//Puedo comparar el dinero gastado directamente.
		if (listaAux->info.dineroGastado < menosDineroGastado) {
			menosDineroGastado = listaAux->info.dineroGastado;
			cliMenosDineroGastado = listaAux->info.numeroCliente;
		}

		//Avanzo la lista padre.
		listaAux = listaAux->sig;
	}
	cout << "El cliente que menos dinero gasto fue: " << cliMenosDineroGastado << endl;
	cout << "El cliente que mas productos compro fue: " << clienteMasCompras << endl;
}

//Funciones
//Ej2
/*
void encolar(NodoCola*& cFte, NodoCola*& cFin, turno v) {
	NodoCola* nuevo = new NodoCola();
	nuevo->info = v;
	nuevo->sig = NULL;
	if (cFte == NULL)
		cFte = nuevo;
	else
		cFin->sig = nuevo;

	cFin = nuevo;
}
turno desencolar(NodoCola*& cFte, NodoCola*& cFin) {
	turno retorno = cFte->info;
	NodoCola* aux = cFte;
	cFte = aux->sig;
	if (cFte == NULL)
		cFin = NULL;

	delete aux;

	return retorno;
}
*/
//Ej1
/*
NodoLista* insertarOrdenado(NodoLista*& p, turno v) {
	NodoLista* nuevo = new NodoLista();
	nuevo->info = v;
	nuevo->sig = NULL;
	NodoLista* ant = NULL;
	NodoLista* aux = p;

	while (aux != NULL && aux->info.hora <= v.hora) {
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
	*/
	//Ej3
	/*
		char pop(NodoPila*& p) {
			char retorno = p->info;
			NodoPila* aux = p;
			p = aux->sig;
			delete aux;
			return retorno;
		}
		void push(NodoPila*& p, char v) {
			NodoPila* nuevo = new NodoPila();
			nuevo->info = v;
			nuevo->sig = p;
			p = nuevo;
		}
		*/