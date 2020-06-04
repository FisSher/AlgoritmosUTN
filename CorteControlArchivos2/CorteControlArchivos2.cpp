/*Ejercicio Nro. 2: Se tiene un archivo “notas.dat” que contiene todas las notas obtenidas en el cuatrimestre por los estudiantes.
El archivo contiene legajo, nombre de materia y nota obtenida, y se encuentra ordenado por legajo. Se pide obtener:
a) La cantidad de notas procesadas.
b) El promedio de calificaciones total de los estudiantes.
c) Por cada estudiante la materia donde obtuvo la calificación más alta.
Nota: Sólo se informaron las notas de los exámenes en los cuales el estudiante estuvo presente.

El struct que fue utilizado para cargar el archivo fue:

struct Nota {
Int legajo;
char materia[50];
float nota;
}
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "vectores.hpp"
#include <string.h>
using namespace std;

int main()
{
	FILE* notas = fopen("notas.dat", "rb");
	Nota reg;

	int cantNotasProcesadasGlobal = 0;
	float promedioGlobal = 0;
	float sumaNotasGlobal = 0;

	fread(&reg, sizeof(Nota), 1, notas);
	while (!feof(notas)) {
		char materiaMasAlta[50];
		float promedioEst = 0;
		int legajoAnterior = reg.legajo;
		float sumaNotas = 0;
		int cantNotasProcesadas = 0;
		float notaMasAlta = 0;
		while (!feof(notas) && legajoAnterior == reg.legajo) {
			cantNotasProcesadas += 1;
			sumaNotas += reg.nota;
			if (reg.nota > notaMasAlta) {
				strcpy(materiaMasAlta, reg.materia);

				notaMasAlta = reg.nota;
			}

			fread(&reg, sizeof(Nota), 1, notas);
		}
		sumaNotasGlobal += sumaNotas;
		cantNotasProcesadasGlobal += cantNotasProcesadas;
		float promedio = sumaNotas / cantNotasProcesadas;
		cout << "El promedio del estudiante " << legajoAnterior << " fue: " << promedio << endl;
	}
	promedioGlobal = sumaNotasGlobal / cantNotasProcesadasGlobal;
	cout << "La cantidad de notas procesadas fue: " << cantNotasProcesadasGlobal << endl;
	cout << "El promedio global fue de " << promedioGlobal;

	fclose(notas);
}