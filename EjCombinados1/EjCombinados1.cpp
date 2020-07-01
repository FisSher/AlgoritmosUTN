/*Ejercicio 1
Crear un procedimiento que dados dos vectores con los datos de los
estudiantes de dos cursos vecK1051 y vecK1052 (20 estudiantes como
máximo cada uno) cree un archivo “estudiantes.dat” que contenga los
estudiantes de ambos cursos ordenados por legajo.

De los estudiantes
sabemos el nombre, el legajo y el mail.

Los vectores se encuentran
ordenados por legajo. En el archivo colocar además de los datos
originales, el curso de donde proviene cada uno

struct  nombre, el legajo y el mail
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

struct estudiante {
	char nombre[50];
	int legajo;
	char email[50];
};

struct estConsolidado {
	estudiante est;
	char curso[20];
};

int main()
{
	estudiante vecK1051[20] = { { "Facundo",1000,"12@3" }, { "Virginia",1345,"1@23" }, { "Sofia",4321,"12@3" } };
	estudiante vecK1052[20] = { {"Gaston",1222,"1@23"}, {"Hernan",1400,"12@3"} };
	int lenA = 3;
	int lenB = 2;
	int posA = 0;
	int posB = 0;
	FILE* estudiantes = fopen("estudiantes.dat", "wb+");

	estudiante reg;
	estConsolidado regCons;

	while (posA << lenA && posB << lenB)
	{
		if (vecK1051[posA].legajo < vecK1052[posB].legajo)
		{
			regCons.est = vecK1051[posA];
			strcpy(regCons.curso, "K1051");
			fwrite(&regCons, sizeof(estConsolidado), 1, estudiantes);
			posA++;
		}
		else
		{
			regCons.est = vecK1052[posB];
			strcpy(regCons.curso, "K1052");
			fwrite(&regCons, sizeof(estConsolidado), 1, estudiantes);
			posB++;
		}
	}

	while (posA < lenA)
	{
		regCons.est = vecK1051[posA];
		strcpy(regCons.curso, "K1051");
		fwrite(&regCons, sizeof(estConsolidado), 1, estudiantes);
		posA++;
	}

	while (posB < lenB)
	{
		regCons.est = vecK1052[posB];
		strcpy(regCons.curso, "K1052");
		fwrite(&regCons, sizeof(estConsolidado), 1, estudiantes);
		posB++;
	}

	fclose(estudiantes);
}