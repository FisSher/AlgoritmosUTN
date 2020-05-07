/*Ejercicio Nro. 1: Dado un número N (<=30), genere e informe un vector VEC de N elementos que contenga los primeros N números naturales pares*/

#include <iostream>
#include "vectores.hpp";
using namespace std;

int main()
{
	int n;	
	int vec[30];
	int len=0;
	cout << "Ingrese N: ";
	cin >> n;
	while (n <=0  || n>30)
	{
		cout << "Ingrese N valido: ";
		cin >> n;
	}
	inicializar(vec, n);

	for (int i = 0; i < n; i++)
	{
		agregar(vec, n, len, 2 * i + 2);
	}
	cout << "Los " << n << " numeros pares son: " << endl;
	mostrar(vec, len);


}
