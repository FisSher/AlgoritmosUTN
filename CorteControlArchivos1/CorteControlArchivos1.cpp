/*Ejercicio Nro. 1: Se tiene el archivo “ventas052018.dat” que contiene las ventas del mes de Mayo 2018 de la librería “El buen libro”.
El archivo contiene código de artículo, cantidad vendida y precio de unitario, y se encuentra ordenado por código de artículo.
Se pide obtener:
a- Las ventas facturadas en el mes.
b- La cantidad vendida de cada artículo.
c- El artículo más vendido.

Nota: el struct que fue utilizado para cargar el archivo fue:

struct Venta {
Int codArt;
Int cantVendida;
float precioUnitario;
}
 */

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "vectores.hpp"
#include <string.h>
using namespace std;

int main()
{
	FILE* ventas = fopen("ventas052018.dat", "rb");
	Venta registro;
	float ventasFacturadasMes = 0;
	float cantVendida = 0;
	float precioUnitario = 0;
	int cantVendidaPorArt;
	int maxCantArticulo = -1;
	int codArtMasVendido = 0;

	fread(&registro, sizeof(Venta), 1, ventas);
	while (!feof(ventas)) {
		int codAnterior = registro.codArt;
		cantVendidaPorArt = 0;

		while (!feof(ventas) && codAnterior == registro.codArt) {
			ventasFacturadasMes += registro.cantVendida * registro.precioUnitario;
			cantVendidaPorArt += registro.cantVendida;

			fread(&registro, sizeof(Venta), 1, ventas);
		}

		if (cantVendidaPorArt > maxCantArticulo) {
			codArtMasVendido = codAnterior;
			maxCantArticulo = cantVendidaPorArt;
		}

		cout << "Del articulo " << codAnterior << " se vendieron " << cantVendidaPorArt << endl;
	}
	cout << "El mes de mayo se facturaron $" << ventasFacturadasMes << endl;
	cout << "El articulo mas vendido fue " << codArtMasVendido << " con " << maxCantArticulo << " ventas." << endl;

	fclose(ventas);
}

/*
Abrir archivo
wb: escritura binaria
rb: lectura binaria
rb+:lectura y escritura binaria
wb+: escritura y lectura binaria
Si se abre un archivo que no existe en escritura, lo crea.

struct del tipo de dato a leer y nombre variable registro:
Venta registro;
FILE * variablePrueba = fopen("NombreArchivo.dat","formaApertura")
---------------------------------------------------------------

Leer archivo

No usar string, usar char algo[x]  x:entero  algo: nombre variable
struct registro;  --> tengo que leer el mismo tipo de dato que está guardado el archivo

fread(&registro,sizeof(Venta),1,variablePrueba);
----------------------------------------------------------------

Escribir archivo
strcpy(registro.algo,"string"); ---> Esto convierte el tipo de dato para que entre en el char
fwrite(&registro,sizeof(Venta),1,variablePrueba);

----------------------------------------------------------------

rewind(variablePrueba): -----> Volver al principio para leerlo después de escribir.

Procesar:
fread(&registro,sizeof(Venta),1,variablePrueba);
while(!feof(variablePrueba)){
	fread(&registro,sizeof(Venta),1,variablePrueba);
}

Cerrar archivo
fclose(variable);
*/