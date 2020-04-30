/*Ejercicio Nro. 9: Dadas dos fechas en formato AAAAMMDD, informar cual es la más reciente
*/

#include <iostream>
using namespace std;
int main()
{
	int fecha1 = 0;
	int fecha2 = 0;

	cout << "Ingrese la primera fecha: ";
	cin >> fecha1;
	cout << "Ingrese la segunda fecha:";
	cin >> fecha2;
	if (fecha1 > fecha2) {
		cout << "La fecha " << fecha1 << " es la mas reciente.";
	}
	else if (fecha2 > fecha1) {
		cout << "La fecha " << fecha2 << " es la mas reciente.";
	}
	else {
		cout << "Las fechas son iguales";
	}
}