/* Ejercicio Nro. 7: Dados un mes y el año al que corresponde, informar cuantos días tiene el mes.
else 29
1,3,5,7,8,10,12 = 31
4,6,9,11 = 30
febrero  (anio % 4 == 0 && anio % 100 != 0 || anio % 400 == 0) 29 dias
else 28 dias
*/
#include <iostream>
using namespace std;

bool CalcularBiciesto(int year);

int main()
{
	int mes;
	int year;
	cout << "Ingrese mes: ";
	cin >> mes;
	cout << "Ingrese anio: ";
	cin >> year;
	switch (mes) {
	case 1: case 3: case 5: case 7: case 8: case 10: case 12:
		cout << "El mes tiene 31 dias. \n";
		break;
	case 4: case 6: case 9: case 11:
		cout << "El mes tiene 30 dias. \n";
		break;
	case 2:
		if (CalcularBiciesto(year)) {
			cout << "El mes tiene 29 dias. \n";
			break;
		}
		else {
			cout << "El mes tiene 28 dias. \n";
			break;
		}
	default:
		cout << "Error de ingreso \n";
	}
}

bool CalcularBiciesto(int year) {
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
		return true;
	}
	else {
		return false;
	}
}