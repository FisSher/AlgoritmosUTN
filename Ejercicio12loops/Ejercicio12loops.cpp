// Ejercicio Nro. 2: Dados 50 números enteros, informar el promedio de los mayores que 100 y la suma de los menores que –10.

#include <iostream>
using namespace std;

int main()
{
	float numero = 0;
	float mayoresCien = 0;
	float menoresMenosDiez = 0;
	float sumaNumerosMayorCien = 0;
	float sumaNumerosMenosDiez = 0;

	for (int i = 0; i < 10; i++) //50 sería para no explotar hago 10
	{
		cout << "Ingresar el numero " << i + 1 << ": ";
		cin >> numero;
		if (numero > 100)
		{
			mayoresCien++;
			sumaNumerosMayorCien += numero;
		}
		else if (numero < -10)
		{
			menoresMenosDiez++;
			sumaNumerosMenosDiez += numero;
		}
		else {
			cout << "No es un numero valido" << endl;
		}
	}

	float promedioMayor100 = sumaNumerosMayorCien / mayoresCien;
	float promedioMenorMenos10 = sumaNumerosMenosDiez / menoresMenosDiez;

	cout << "El promedio de los mayores a 100 es: " << promedioMayor100 << endl;
	cout << "El promedio de los menores a menos diez es: " << promedioMenorMenos10 << endl;
}