/*
Se tiene un archivo “ventas.dat” que contiene los siguientes datos:
número de cliente, artículo comprado, cantidad comprada y precio
unitario.

Con estos datos llenar una lista que debe contener número de cliente y dinero gastado.
A su vez cada nodo de esa lista va a poseer una sublista de los artículos comprados, junto con su cantidad
comprada y precio unitario.
Nota: El precio unitario para cada artículo no varía.

Si el artículo se repite por cada cliente debe incrementarse su cantidad vendida.

Luego, mostrar un listado con la siguiente estructura:
Número de Cliente:
$ dineroGastado por el cliente
Detalle:
● Artículo cantidadDeUnidades precioUnitario total
 Total de Dinero Recaudado: $dineroGastadoPorTodosLosClientes
 */

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "funciones.hpp"

using namespace std;

/*
Cliente* buscaEInsertaCliente(Cliente*& p, infoCliente v, bool& enc);
Cliente* buscarCliente(Cliente* p, infoCliente v);
Cliente* agregarCliente(Cliente*& p, infoCliente x);

Articulo* buscaEInsertaArticulo(Articulo*& p, infoArt v, bool& enc);
Articulo* buscarArticulo(Articulo* p, infoArt v);
Articulo* agregarArticulo(Articulo*& p, infoArt x);
*/
struct venta {
	int nroCliente;
	char articulo[50];
	int cant;
	float precioUnitario;
};

struct infoArt {
	char articulo[50];
	float precioUnitario;
	int cantidad;
};

struct Articulo {
	infoArt info;
	Articulo* sig;
};

struct infoCliente {
	int nroCliente;
	float  dineroGastado;
	Articulo* articulosComprados;
};

struct Cliente {
	infoCliente info;
	Cliente* sig;
};





int main()
{
	FILE* ventas = fopen("ventas.dat", "rb");
	venta reg;
	Cliente* listaClientes = NULL;
	bool enc;
	infoCliente infoC;
	infoArt infoA;
	Articulo* articuloBuscado;
	Cliente* clienteBuscado;

	fread(&reg, sizeof(venta), 1, ventas);
	while (!feof(ventas))
	{
		infoC.nroCliente = reg.nroCliente;
		infoC.dineroGastado = 0;
		infoC.articulosComprados = NULL;
		clienteBuscado = buscaEInserta(listaClientes, infoC, enc);
		strcpy(infoA.articulo, reg.articulo);
		infoA.cantidad = reg.cant;
		infoA.precioUnitario = reg.precioUnitario;

		articuloBuscado = buscaEInserta(clienteBuscado->info.articulosComprados, infoA, enc);
		if (enc) {
			articuloBuscado->info.cantidad += reg.cant;
		}

		clienteBuscado->info.dineroGastado += reg.cant * reg.precioUnitario;

		fread(&reg, sizeof(venta), 1, ventas);
	}

	fclose(ventas);

	float dineroGastadoPorTodosLosClientes = 0;

	Cliente* clienteAux = listaClientes;


	while (clienteAux!=NULL)
	{
		std::cout << "El cliente " << clienteAux->info.nroCliente << " gasto: " << clienteAux->info.dineroGastado;

		cout << "Detalle:" << endl;
		Articulo* articuloAux = clienteAux->info.articulosComprados;
		while (articuloAux != NULL)
		{
			cout << articuloAux->info.articulo << "-" << articuloAux->info.cantidad << "-" << articuloAux->info.precioUnitario <<
				"-"<<articuloAux->info.precioUnitario * articuloAux->info.cantidad;

			articuloAux = articuloAux->sig;
		}

			dineroGastadoPorTodosLosClientes += clienteAux->info.dineroGastado;
		clienteAux = clienteAux->sig;
	}






}
/*
Articulo* buscarArticulo(Articulo* p, infoArt v) {
	Articulo* aux = p;
	while (aux != NULL && strcmp(aux->info.articulo, v.articulo) != 0) {
		aux = aux->sig;
	}
	return aux;
}

Articulo* agregarArticulo(Articulo*& p, infoArt x) {
	Articulo* nuevo = new Articulo();
	nuevo->info = x;
	nuevo->sig = NULL;
	if (p == NULL) { // la lista p esta vacía
		p = nuevo;
	}
	else {
		Articulo* aux = p;
		while (aux->sig != NULL) {
			aux = aux->sig;
		}
		aux->sig = nuevo;
	}

	return nuevo;
}

Articulo* buscaEInsertaArticulo(Articulo*& p, infoArt v, bool& enc) {
	Articulo* nodoBuscado = buscarArticulo(p, v);
	if (nodoBuscado != NULL) { // el nodo está en la lista
		enc = true;
	}
	else { // el nodo no está
		nodoBuscado = agregarArticulo(p, v);
		enc = false;
	}

	return nodoBuscado;
}


Cliente* buscarCliente(Cliente* p, infoCliente v) {
	Cliente* aux = p;
	while (aux != NULL && aux->info.nroCliente != v.nroCliente) {
		aux = aux->sig;
	}
	return aux;
}

Cliente* agregarCliente(Cliente*& p, infoCliente x) {
	Cliente* nuevo = new Cliente();
	nuevo->info = x;
	nuevo->sig = NULL;
	if (p == NULL) { // la lista p esta vacía
		p = nuevo;
	}
	else {
		Cliente* aux = p;
		while (aux->sig != NULL) {
			aux = aux->sig;
		}
		aux->sig = nuevo;
	}

	return nuevo;
}

Cliente* buscaEInsertaCliente(Cliente*& p, infoCliente v, bool& enc) {
	Cliente* nodoBuscado = buscarCliente(p, v);
	if (nodoBuscado != NULL) { // el nodo está en la lista
		enc = true;
	}
	else { // el nodo no está
		nodoBuscado = agregarCliente(p, v);
		enc = false;
	}

	return nodoBuscado;
}*/