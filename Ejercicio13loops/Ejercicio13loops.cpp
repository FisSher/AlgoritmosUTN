// Ejercicio Nro. 3: Se ingresa un conjunto de valores positivos terminado con un valor negativo. 
//Se pide desarrollar el programa que imprima el valor m�ximo del conjunto y su posici�n relativa
//dentro del mismo (el n�mero de orden en el que fue ingresado)

#include <iostream>
using namespace std;

int main()
{
	float numero = 0;
	int posicion = 0;
	int posicionMaxima = 0;
	float maximo = 0;
	while (numero >= 0)
	{
		cout << "Ingrese el numero " << posicion << " del conjunto: ";
		cin >> numero;
		if (numero > maximo) {
			maximo = numero;
			posicionMaxima = posicion;
		}
		posicion++;

	}
	cout << "El numero maximo fue: " << maximo;
	cout << " en la posicion " << posicionMaxima;



}

