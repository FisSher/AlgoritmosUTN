/*Ejercicio Nro.  7: Se ingresa un n�mero con el formato YYYYMMDD. A partir de ese n�mero mostrar el a�o(YYYY), el mes(MM) y el d�a (DD). */

#include <iostream>
using namespace std;
int main()
{
	int fecha = 0;
	int mes = 0;
	int anio = 0;
	int dia = 0;

	cout << "Ingrese una fecha en formato YYYYMMDD: ";
	cin >> fecha;
	anio = fecha / 10000;
	mes = (fecha % 10000) / 100;
	dia = (fecha % 1000) % 100;
	mes = (fecha / 1000) % 100;
	dia = fecha % 100;
	//Otra opcion dia = fecha % 100

	cout << "El anio es: " << anio << endl;
	cout << "El mes es: " << mes << endl;
	cout << "El dia es: " << dia << endl;
}