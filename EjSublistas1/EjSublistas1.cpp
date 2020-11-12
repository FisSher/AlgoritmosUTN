/*
Se tiene un archivo “ventas.dat” que contiene los siguientes datos:
número de cliente, artículo comprado, cantidad comprada y precio
unitario.

Con estos datos llenar una lista que debe contener número de cliente y dinero gastado.
A su vez cada nodo de esa lista va a poseer una sublista de los artículos comprados, junto 
con su cantidad comprada y precio unitario.
Nota: El precio unitario para cada artículo no varía.

Si el artículo se repite por cada cliente debe incrementarse su cantidad vendida.

Luego, mostrar un listado con la siguiente estructura:
Número de Cliente:
$ dineroGastado por el cliente
Detalle:
 Artículo-> cantidadDeUnidades-> precioUnitario-> total
 Total de Dinero Recaudado: $dineroGastadoPorTodosLosClientes
 */

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "funciones.hpp"

using namespace std;


struct venta {
	int nroCliente;
	char id[50];
	int cant;
	float precioUnitario;
};

struct infoArt {
	char id[50];
	float precioUnitario;
	int cantidad;
};

struct Articulo {
	infoArt info;
	Articulo* sig;
};

struct infoCliente {
	int id;
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
		infoC.id = reg.nroCliente;
		infoC.dineroGastado = 0;
		infoC.articulosComprados = NULL;
		clienteBuscado = buscaEInserta(listaClientes, infoC, enc);
		strcpy(infoA.id, reg.id);
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

	while (clienteAux != NULL)
	{
		cout << "El cliente (ID): " << clienteAux->info.id << " gasto: " << clienteAux->info.dineroGastado<<"$"<<endl;

		cout << "Detalle:" << endl;
		Articulo* articuloAux = clienteAux->info.articulosComprados;
		while (articuloAux != NULL)
		{
			cout <<"Articulo: " <<articuloAux->info.id << " Cantidad:" << articuloAux->info.cantidad << " Precio unitario: " << articuloAux->info.precioUnitario <<
				" Precio Total: " << articuloAux->info.precioUnitario * articuloAux->info.cantidad << endl;

			articuloAux = articuloAux->sig;
		}

		dineroGastadoPorTodosLosClientes += clienteAux->info.dineroGastado;
		clienteAux = clienteAux->sig;
	}
}
