//Dados 10 valores numéricos, informar cual es el mayor.
#include <iostream>
using namespace std;

int main()
{
	int Numero;
	int Mayor = -1;
	for (int i = 0; i < 10; i++)
	{
		cout << "Ingrese el numero " << i + 1 << ": ";
		cin >> Numero;
		if (Numero > Mayor) {
			Mayor = Numero;
		}
	}

	cout << "El mayor numero fue: " << Mayor;
}