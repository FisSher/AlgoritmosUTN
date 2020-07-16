/*
Se cuenta con un archivo “listaDePrecios.dat” que contiene el código
de artículo y el precio unitario del mismo. ok

También, se tiene un vector de
stock con los siguientes datos: nro. de artículo, cantidad de unidades y
posición en la lista de precios.

Se pide generar un programa que permita persistir la cabecera
(“cabecer.dat”) y detalle (“detalle.dat”) de las facturas generadas.

- En la cabecera se pide el identificador de factura (que se saca
de “proximoIdentificador.dat”), la fecha del día (en formato
YYYYMMDD), el número de cliente (que es ingresado por teclado)
y el total de la factura.

- En el detalle se pide el identificador de la factura (utilizado en la
cabecera), el nro. de artículo comprado, la cantidad, el precio y
el total por artículo.

Hay que tener en cuenta que se puede
comprar más de un artículo en una misma compra, es decir que
el detalle podrá tener varias líneas para una misma factura.

Antes de realizar una compra es necesario chequear si hay stock
suficiente. Una vez realizada la compra, se actualiza el stock y el
próximo identificador de la factura.*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

struct listaDePrecios {
	int nroArticulo;
	float precioUnitario;
};
struct stock {
	int nroArticulo;
	int cantUnidades;
	int posListaDePrecios;
};

struct cabecera {
	int idFactura;
	int fecha;
	int nroCliente;
	float totalFactura;
};

struct detalle {
	int idFactura;
	int nroArticulo;
	int cant;
	float precioUnitario;
	float totalArticulo;
};



void imprimirCabeceras(FILE* cabeceraArch, cabecera regCabecera);

int busquedaSecuencial(stock vec[], int len, int valorBuscado);
void imprimirDetalles(FILE* detallesArch, detalle regDetalle);

int main()
{
	//Creo el identificador que no tengo el archivo
   /*FILE* proximoidentificador = fopen("proximoidentificador.dat", "wb+");
	int reg= 1;
	fwrite(&reg, sizeof(int), 1, proximoidentificador);
	rewind(proximoidentificador);

	fread(&reg, sizeof(int), 1, proximoidentificador);

	while (!feof(proximoidentificador))
	{
		cout << reg << endl;
		fread(&reg, sizeof(int), 1, proximoidentificador);
	}
	fclose(proximoidentificador);*/

	/* FILE* listaArch = fopen("listaDePrecios.dat", "wb+");
	 listaDePrecios reg;

	 reg.codigoArt = 123;
	 reg.precioUnitario = 50.5;
	 fwrite(&reg, sizeof(listaDePrecios), 1, listaArch);

	 reg.codigoArt = 234;
	 reg.precioUnitario = 75;
	 fwrite(&reg, sizeof(listaDePrecios), 1, listaArch);

	 reg.codigoArt = 478;
	 reg.precioUnitario = 37.7;
	 fwrite(&reg, sizeof(listaDePrecios), 1, listaArch);

	 reg.codigoArt = 567;
	 reg.precioUnitario = 66;
	 fwrite(&reg, sizeof(listaDePrecios), 1, listaArch);

	 reg.codigoArt = 854;
	 reg.precioUnitario = 105;
	 fwrite(&reg, sizeof(listaDePrecios), 1, listaArch);

	 rewind(listaArch);

	 fread(&reg, sizeof(listaDePrecios), 1, listaArch);

	 fclose(listaArch);
	 */

	stock vecStock[100] = { {478,34,4},{123,78,1},{234,100,2},{345,300,3},{567,46,5} };
	int lenStock = 5;
	FILE* listaArch = fopen("listaDePrecios.dat", "rb");
	FILE* proximoIdentificadorArch = fopen("proximoIdentificador.dat", "rb+");
	FILE* cabeceraArch = fopen("cabecera.dat", "wb+");
	FILE* detalleArch = fopen("detalle.dat", "wb+");

	int terminarIngresoDeFacturas;
	int terminarIngresoDeArticulos;
	int proximoIdentificador;
	int posArtEnStock = -1;

	detalle regDetalle;
	cabecera regCabecera;
	listaDePrecios regListaDePrecios;

	cout << "Bienvenido" << endl;
	cout << "Para terminar el ingreso de facturas, presione 0" << endl;
	cin >> terminarIngresoDeFacturas;
	while (terminarIngresoDeFacturas != 0)
	{
		cout << "Ingrese numero de cliente: ";
		cin >> regCabecera.nroCliente;

		cout << "Ingrese la fecha: ";
		cin >> regCabecera.fecha;

		fread(&regCabecera.idFactura, sizeof(int), 1, proximoIdentificadorArch);

		regCabecera.totalFactura = 0;

		cout << "Para terminar el ingreso de articulos, presione 0" << endl;
		cin >> terminarIngresoDeArticulos;
		while (terminarIngresoDeArticulos != 0)
		{
			cout << "Ingrese el articulo: ";
			cin >> regDetalle.nroArticulo;

			cout << "Ingrese la cantidiad: ";
			cin >> regDetalle.cant;

			busquedaSecuencial(vecStock, lenStock, regDetalle.nroArticulo);

			if (posArtEnStock == -1)
			{
				cout << "El articulo no existe" << endl;
			}
			else
			{
				if (vecStock[posArtEnStock].cantUnidades >= regDetalle.cant)
				{
					vecStock[posArtEnStock].cantUnidades -= regDetalle.cant;
					fseek(listaArch, (vecStock[posArtEnStock].posListaDePrecios - 1) * sizeof(listaDePrecios), SEEK_SET);
					fread(&regListaDePrecios, sizeof(listaDePrecios), 1, listaArch);
					regDetalle.precioUnitario = regListaDePrecios.precioUnitario;
					regDetalle.totalArticulo = regDetalle.precioUnitario * regDetalle.cant;
					regCabecera.totalFactura += regDetalle.precioUnitario * regDetalle.cant;
					fwrite(&regDetalle, sizeof(detalle), 1, detalleArch);
				}
				else
				{
					cout << "No hay cantidad suficiente, solo quedan las siguientes unidades: " << vecStock[posArtEnStock].cantUnidades << endl;
				}
			}

			cout << "Para terminar el ingreso de articulos, presione 0" << endl;
			cin >> terminarIngresoDeArticulos;
		}

		fwrite(&regCabecera, sizeof(cabecera), 1, cabeceraArch);
		rewind(proximoIdentificadorArch);
		regCabecera.idFactura++;
		fwrite(&regCabecera, sizeof(int), 1, proximoIdentificadorArch);
		rewind(proximoIdentificadorArch);

		cout << "Para terminar el ingreso de facturas, presione 0" << endl;
		cin >> terminarIngresoDeFacturas;
	}

	imprimirCabeceras(cabeceraArch, regCabecera);

	imprimirDetalles(detalleArch, regDetalle);

	fclose(listaArch);
	fclose(proximoIdentificadorArch);
	fclose(cabeceraArch);
	fclose(detalleArch);

	//fseek(listaDePrecios, (posLista - 1) * sizeof(lista), SEEK_SET);
	//posLista que sale del vector
	return 0;
}

void imprimirCabeceras(FILE* cabeceraArch, cabecera regCabecera) {
	rewind(cabeceraArch);

	cout << "Cabeceras de las facturas: " << endl;

	fread(&regCabecera, sizeof(cabecera), 1, cabeceraArch);
	while (!feof(cabeceraArch))
	{
		cout << regCabecera.idFactura << endl;
		cout << regCabecera.fecha << endl;
		cout << regCabecera.nroCliente << endl;
		cout << regCabecera.totalFactura << endl;
		fread(&regCabecera, sizeof(cabecera), 1, cabeceraArch);
		cout << "______________________________________________________" << endl;
	}
}

void imprimirDetalles(FILE* detallesArch, detalle regDetalle) {
	rewind(detallesArch);

	cout << "Detalle de las facturas: " << endl;

	fread(&regDetalle, sizeof(detalle), 1, detallesArch);
	while (!feof(detallesArch))
	{
		cout << regDetalle.idFactura << endl;
		cout << regDetalle.nroArticulo << endl;
		cout << regDetalle.cant << endl;
		cout << regDetalle.precioUnitario << endl;
		cout << regDetalle.totalArticulo << endl;
		fread(&regDetalle, sizeof(detalle), 1, detallesArch);
		cout << "______________________________________________________" << endl;
	}
}

int busquedaSecuencial(stock vec[], int len, int valorBuscado) {
	int pos = -1;

	int i = 0;
	while (i < len && vec[i].nroArticulo != valorBuscado) {
		i++;
	}

	if (vec[i].nroArticulo == valorBuscado) {
		pos = i;
	}

	return pos;
}