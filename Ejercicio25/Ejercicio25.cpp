/*Desarrollar la función pow que recibe una base y un exponente y retorne la potencia. El prototipo será: double pow(double x, double y);*/

#include <iostream>
using namespace std;

double pow(double x, double y);

int main()
{
	double x = 0;
	double y = 0;

	cout << "Ingrese base: ";
	cin >> x;
	cout << "Ingrese exponente: ";
	cin >> y;

	double resultado = pow(x, y);
	cout << resultado;
}

double pow(double x, double y) {
	double resultado = 1;
	for (int i = 0; i < y; i++) {
		resultado = resultado * x;
	}
	return resultado;
}