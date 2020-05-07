/*Ejercicio Nro.  2: Dado un conjunto (<=100) de valores enteros de los cuales el �ltimo es cero y no debe procesarse:
� Informar el valor m�nimo y su posici�n dentro del conjunto. Si el m�nimo no es �nico, informar todas las posiciones donde se encuentre.
� Informar todos los elementos impares que ocupan una posici�n par. */

#include <iostream>
#include "vectores.hpp"
using namespace std;
int main()
{
	int vec[100];
	int n = 100;
	int len = 0;
	int numero;

	cout << "Ingrese un n�mero positivo " << endl;
	cin >> numero;

	while (numero > 0 && len < n) {
		agregar(vec, n, len, numero);
		cout << "Ingresar un n�mero positivo " << endl;
		cin >> numero;
	}

	int minimo = buscarMinimo(vec, len);

	int vecMinimos[100];
	int lenMinimo = 0;

	for (int i = 0; i < len; i++) {
		if (vec[i] == minimo) {
			agregar(vecMinimos, 100, lenMinimo, i);
		}
	}

	cout << "El valor m�nimo: " << minimo << " est� en las siguientes posiciones " << endl;

	mostrar(vecMinimos, lenMinimo);

	for (int i = 0; i < len; i += 2) {
		if (vec[i] % 2 != 0) {
			cout << "En la posici�n " << i << " se encuentra el valor impar " << vec[i] << endl;
		}
	}
}