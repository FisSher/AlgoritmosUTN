/* Ejercicio Nro. 8: Se ingresa una terna de números naturales que representan el día, el mes y el año de una determinada fecha informarla
como un solo número natural de 8 dígitos (AAAAMMDD).
*/

#include <iostream>
using namespace std;
int main()
{
	int anio;
	int mes;
	int dia;

	cout << "Ingrese anio: ";
	cin >> anio;
	cout << "Ingrese mes: ";
	cin >> mes;
	cout << "Ingrese dia: ";
	cin >> dia;

	int fecha = anio * 1000 + mes * 100 + dia;
	cout << "La fecha es: " << fecha << endl;
}