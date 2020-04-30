/*Desarrolle la función calcularPorcentajeDiferencia que recibe dos valores a, b y retorna el siguiente cálculo: (b-a) *100 / (a+b).
El prototipo será: float calcularPorcentajeDiferencia(long a, long b); */

#include <iostream>
using namespace std;

float calcularPorcentajeDiferencia(long a, long b);

int main()
{
	long a = 0;
	long b = 0;
	cout << "Ingrese el primer numero: ";
	cin >> a;
	cout << "Ingrese el segundo numero: ";
	cin >> b;
	if (b >= a) {
		float res = calcularPorcentajeDiferencia(a, b);
		cout << "El resultado es: " << "%" << res;
	}
	else {
		cout << "a no puede ser mayor que b porque da porcentaje negativo" << endl;
	}
}

float calcularPorcentajeDiferencia(long a, long b) {
	return((b - a) * 100 / (a + b));
}