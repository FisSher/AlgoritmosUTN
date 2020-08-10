// Busquedas.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

struct articulo {
	int nroArt;
	char desc[50];
	float precio;
};

int main()
{
	FILE* archivo = fopen("listaprecios.dat", "rb");
	articulo reg;

	reg.nroArt = 1234;
	strcpy(reg.desc, "alfajor");
	reg.precio = 50.2;

	fwrite(&reg, sizeof(articulo), 1, archivo);

	reg.nroArt = 4567;
	strcpy(reg.desc, "turron");
	reg.precio = 20.5;
	fwrite(&reg, sizeof(articulo), 1, archivo);

	reg.nroArt = 6784;
	strcpy(reg.desc, "gomitas");
	reg.precio = 35;
	fwrite(&reg, sizeof(articulo), 1, archivo);

	reg.nroArt = 8976;
	strcpy(reg.desc, "gaseosa");
	reg.precio = 75.5;
	fwrite(&reg, sizeof(articulo), 1, archivo);


	reg.nroArt = 0;
	strcpy(reg.desc, "");
	reg.precio = 0;

	fseek(archivo, 2 * sizeof(articulo), SEEK_SET);
	//SEEK_SET ->Desde el principio del archivo
	//SEEK_CUR ->Desde la posición donde estoy
	//SEEK_END ->Desde el final

	fread(&reg, sizeof(articulo), 1, archivo);

	cout << reg.nroArt << endl;
	cout << reg.desc << endl;
	cout << reg.precio << endl;




}

//Ordenamiento burbuja por machete
void bubbleSort(int arr[], int n)
{
	int i, j, temp, pass = 0;
	for ( i = 0; i < 10; i++) {
		for ( j = i + 1; j < 10; j++)
		{
			if (arr[j] < arr[i]) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

int busquedaBinaria(int vec[], int len, int valor) {
	int ultimo = len-1;
	int primero = 0;
	int medio = (primero+ultimo/2);
	int pos = -1;
	while (primero<=ultimo)
	{
		if (vec[medio] ==valor ) {
			pos = medio;
			break;
		}
		else if (vec[medio] < valor) {
			primero = medio + 1;
		}
		else {
			ultimo = medio -1;

		}
		medio = (primero + ultimo) / 2;

	}
	return pos;
}
