/*Desarrollar la funci�n esMultiplo que recibe dos valores a y b y retorna true o false seg�n a sea o no m�ltiplo de b.
El prototipo ser�: bool esMultiplo(int a, int b);*/

#include <iostream>
using namespace std;

bool esMultiplo(int a, int b);

int main()
{
	int a = 0;
	int b = 0;
	cout << "Ingrese el primer numero: ";
	cin >> a;
	cout << "Ingrese el segundo numero: ";
	cin >> b;
	bool respuesta = esMultiplo(a, b);
	if (respuesta) {
		cout << "Es multiplo" << endl;
	}
	else {
		cout << "No es multiplo" << endl;
	}
}

bool esMultiplo(int a, int b) {
	bool res;
	if (a % b == 0) {
		res = true;
	}
	else {
		res = false;
	}
	return res;
}