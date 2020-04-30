/*Desarrollar y probar la funci�n esPrimo que, dado un valor num�rico que recibe como par�metro
retorna true o false indicando si se trata o no de un n�mero primo. bool esPrimo(int n); */

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