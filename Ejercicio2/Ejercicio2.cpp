/*Se necesita obtener el promedio de un estudiante a partir de sus tres notas parciales,
las mismas son ingresadas por el usuario.*/

#include <iostream>;
using namespace std;

float CalcularPromedio(float nota1, float nota2, float nota3);

int main() {
	float nota1, nota2, nota3;
	cout << "Ingrese la primera nota: ";
	cin >> nota1;
	cout << "Ingrese la segunda nota: ";
	cin >> nota2;
	cout << "Ingrese la tercera nota: ";
	cin >> nota3;
	float resultado = CalcularPromedio(nota1, nota2, nota3);
	cout << "El promedio es: ";
	cout << resultado << endl;
	cout << "Fin del programa" << endl;
}

float CalcularPromedio(float nota1, float nota2, float nota3) {
	return (nota1 + nota2 + nota3) / 3;
}