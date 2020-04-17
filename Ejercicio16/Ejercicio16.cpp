/*Ejercicio Nro. 6: Dado un valor numérico entero m, determinar e imprimir un listado con los m primeros múltiplos de 3 que no sean múltiples de 5. */


#include <iostream>
using namespace std;
int main()
{
	int m;
	int cantidadMultiplos = 0;
	int dividendo = 3;

	cout << "Ingrese cuantos multiplos de 3 y no de 5 desea: ";
	cin >> m;
	

	cout << "Listado de multiplos: "<<endl;
	while (cantidadMultiplos < m) {
		if (dividendo % 3 == 0 && dividendo % 5 != 0) {
			cantidadMultiplos++;
			cout << dividendo << endl;
		}
		dividendo += 3;

	}





}

