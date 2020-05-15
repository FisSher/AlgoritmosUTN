/*Ejercicio Nro. 4: Realizar un programa que sea capaz de gestionar las notas de una clase de 20 estudiantes
de los cuales sabemos el legajo, el nombre y la nota.
El programa debe ser capaz de:
a- Buscar un alumno.
b- Modificar su nota.
c- Mostrar el promedio de todas las notas.
d- Mostrar el estudiante que mejor nota se ha sacado.
e- Mostrar el estudiante que menor nota se ha sacado.
 */

void escribirMenu();

#include <iostream>
#include <string>
#include "vectores.hpp"
using namespace std;

int main()
{
	estudiante listado[20] = { {1234,"Facundo",2.4}, {3215,"Virginia",10}, {4532,"Carlos",8.5} };
	int listadoLen = 3;
	int n = 20;
	int opcion = -1;

	escribirMenu();
	cin >> opcion;

	while (opcion != 0) {
		switch (opcion)
		{
		case 1:
		{
			string alumnoBuscado = " ";
			cout << "Escriba el nombre del alumno a buscar (primera letra con mayuscula): ";
			cin >> alumnoBuscado;
			int pos = buscar(listado, listadoLen, alumnoBuscado);
			if (pos == -1)
				cout << "No se encontró el alumno" << endl;
			else {
				cout << "Los datos del alumno son: " << endl;
				cout << "Legajo: " << listado[pos].legajo << endl;
				cout << "Nombre: " << listado[pos].nombre << endl;
				cout << "Nota: " << listado[pos].nota << endl;
			}
			break;
		}
		case 2:
		{
			int legajo = 0;
			string nombre = "";
			float nota = 0.0;

			string alumnoBuscado = "";
			cout << "Escriba el nombre del alumno a buscar (primera letra con mayuscula): ";
			cin >> alumnoBuscado;

			int pos = buscar(listado, listadoLen, alumnoBuscado);
			if (pos == -1)
				cout << "No se encontró el alumno" << endl;
			else {
				cout << "Ingrese los datos a editar " << endl;
				//----
				cout << "Legajo (0 omite): ";
				cin >> legajo;
				if (legajo > 0)
					listado[pos].legajo = legajo;
				//----
				cout << "Nombre(0 Omite): ";
				cin >> nombre;
				if (nombre != "0")
					listado[pos].nombre = nombre;
				//----
				cout << "Nota (0 omite): ";
				cin >> nota;
				if (nota > 0)
					listado[pos].nota = nota;
				cout << "Los nuevos datos son: " << endl;
				cout << "Legajo: " << listado[pos].legajo << endl;
				cout << "Nombre: " << listado[pos].nombre << endl;
				cout << "Nota: " << listado[pos].nota << endl;
			}
			break;
		}
		case 3: 
		{
			float promedio = calcularPromedio(listado, listadoLen);
			cout << "El promedio es: " << promedio << endl;
			break;
		}
		case 4:
		{
			float maximo = -1;
			int pos = -1;
			for (int i = 0; i < listadoLen; i++)
			{
				if (listado[i].nota > maximo) {
					maximo = listado[i].nota;
					pos = i;
				}
			}
			cout << "El estudiante con mejor nota es: " << listado[pos].nombre << endl;
			cout << "con una nota de " << maximo << endl;
			break;
		}
		case 5: 
		{
			float minimo = 999;
			int pos = -1;
			for (int i = 0; i < listadoLen; i++)
			{
				if (listado[i].nota < minimo) {
					minimo = listado[i].nota;
					pos = i;
				}
			}
			cout << "El alumno con la menor nota es: " << listado[pos].nombre << endl;
			cout << "con una nota de " << minimo << endl;
			break;
		}
		default: {
			cout << "Elija una opcion correcta" << endl;
			break; 
			}
		}

		escribirMenu();
		cin >> opcion;
	}
}

void escribirMenu() {
	cout << "-------------------------------------------------" << endl;
	cout << "Elija la opcion: " << endl;
	cout << "1 Para Buscar alumno" << endl;
	cout << "2 Para Modificar alumno" << endl;
	cout << "3 Para calcular el promedio de todas las notas" << endl;
	cout << "4 Para mostrar el estudiante de nota mas alta" << endl;
	cout << "5 Para mostrar el estudiante de nota mas baja" << endl;
	cout << "0 Para salir" << endl;
	cout << "-------------------------------------------------" << endl;
	cout << "Su eleccion: ";
}