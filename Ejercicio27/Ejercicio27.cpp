/*Desarrollar y probar la función esPrimo que, dado un valor numérico que recibe como parámetro
retorna true o false indicando si se trata o no de un número primo. bool esPrimo(int n); */

#include <iostream>
using namespace std;

bool esPrimo(int num);

int main()
{
	int num;
	cout << "Ingrese el numero a evaluar: ";
	cin >> num;
	bool respuesta = esPrimo(num);
	if (respuesta) {
		cout << "El numero es primo";
	}
	else {
		cout << "El numero no es primo";
	}
}

bool esPrimo(int num) {
	bool respuesta = true;
	for (int i = 2; i <= num / 2; i++) {
		if (num % i == 0) {
			respuesta = false;
			break;
		}
	}
	return respuesta;
}