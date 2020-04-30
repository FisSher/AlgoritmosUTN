/*Desarrollar la función continuar de forma tal que imprima un mensaje en la pantalla con el texto “Presione una tecla para continuar...”. */
#include <iostream>
using namespace std;

void continuar();

int main()
{
	continuar();
}

void continuar() {
	int tecla;
	while (true) {
		cout << "Presione una tecla para continuar...";
		cin >> tecla;
		break;
	}
}