/* Ejercicio Nro. 8: Se ingresa una terna de n�meros naturales que representan el d�a, el mes y el a�o de una determinada fecha informarla
como un solo n�mero natural de 8 d�gitos (AAAAMMDD).
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