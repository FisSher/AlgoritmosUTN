/*Se tiene un archivo �ventas.dat� que contiene los siguientes datos:
n�mero de cliente, art�culo comprado, cantidad comprada y precio
unitario. El art�culo comprado solo aparece 1 vez por cliente. El archivo
se encuentra ordenado por n�mero de cliente. Calcular e informar por
pantalla:
a) Cu�l es el cliente que m�s dinero gast�
b) Cu�l es el cliente que menos cantidad de art�culos compr�
c) Cu�nto dinero gast� cada cliente
d) Cu�l es el art�culo m�s comprado (con m�s cantidad) por
cada cliente*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

struct venta {
	int nroCli;
	char artComprado[50];
	int cantComprada;
	float precioUni;
};

int main()
{
	FILE* ventas = fopen("ventas.dat", "rb");
	venta reg;
	int nroCliAnterior;

	float cliMaxDineroGastado = -1;
	int nroCliMaxDineroGastado = 0;
	float sumaDineroGastadoXCliente;

	int cliMinArtComprados = 9999999999999999999;
	int nroCliMinArtComprados = 0;
	int sumaCantArticulosXCliente;

	int cantArtMaxCompradoXCliente;
	char artMaxCompradoXCliente[50];

	fread(&reg, sizeof(venta), 1, ventas);

	while (!feof(ventas)) {
		nroCliAnterior = reg.nroCli;
		sumaDineroGastadoXCliente = 0.0;
		sumaCantArticulosXCliente = 0;
		cantArtMaxCompradoXCliente = 0;

		while (!feof(ventas) && nroCliAnterior == reg.nroCli) {
			sumaDineroGastadoXCliente += reg.cantComprada * reg.precioUni;
			sumaCantArticulosXCliente += reg.cantComprada;

			if (reg.cantComprada > cantArtMaxCompradoXCliente) {
				cantArtMaxCompradoXCliente = reg.cantComprada;
				strcpy(artMaxCompradoXCliente, reg.artComprado);
			}

			fread(&reg, sizeof(venta), 1, ventas);
		}

		cout << "El cliente " << nroCliAnterior << " gasto $" << sumaDineroGastadoXCliente << endl;
		cout << "El articulo mas comprado fue " << artMaxCompradoXCliente << " con " << cantArtMaxCompradoXCliente << " unidades" << endl;

		cout << "_____________________________________________________" << endl;

		if (sumaDineroGastadoXCliente > cliMaxDineroGastado) {
			cliMaxDineroGastado = sumaDineroGastadoXCliente;
			nroCliMaxDineroGastado = nroCliAnterior;
		}

		if (sumaCantArticulosXCliente < cliMinArtComprados) {
			cliMinArtComprados = sumaCantArticulosXCliente;
			nroCliMinArtComprados = nroCliAnterior;
		}
	}

	cout << "______________________________________________" << endl;
	cout << "El cliente que mas dinero gasto es " << nroCliMaxDineroGastado << " con $" << cliMaxDineroGastado << endl;
	cout << "El cliente que menos articulos compro es " << nroCliMinArtComprados << " con " << cliMinArtComprados << " articulos" << endl;

	fclose(ventas);

	return 0;
}