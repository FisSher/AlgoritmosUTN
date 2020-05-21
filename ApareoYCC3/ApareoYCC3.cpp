/*Corte de Control de Arreglos 
Ejercicio Nro. 1: Se cuenta con un vector que contiene los datos de los estudiantes de 
primer año.
Cada registro de estudiante tiene: el legajo, nombre y apellido, materia y nota final. Es decir que, si el estudiante cursó 3 materias aparecerá 3 veces
en el vector.
Hay como máximo 1000 estudiantes en primer año y pueden cursar hasta 8 materias cada uno. 
----------------------------------------------
El vector se encuentra ordenado por legajo. 
----------------------------------------------
Se pide obtener: - El promedio de cada estudiante. - El mejor promedio de primer año (sólo hay un mejor promedio). */

#include <iostream>
#include <string>
#include "vectores.hpp"

using namespace std;
int main()
{
	estudiantes vec[8000] = { { 123,"Perez","Discreta",6 },{ 123,"Perez","Analisis",7.5 },{ 123,"Perez","AED",8 },
		{ 100,"Lopez","Algebra",9 },
		{ 100,"Lopez","AED",10 },
		{ 100,"Lopez","Arq",8 },
		{ 540,"Rodriguez","IngYSoc",9.5 },
		{ 540,"Rodriguez","Quimica",7 }
	};
	int len = 8;
	int pos = 0;
	float promedioPorEstudiante = 0;
	float sumaNotasPorEstudiante = 0;
	int cantidadNotasPorEstudiante = 0;
	float maxPromedio = 0;
	int legajoMaxPromedio = 0;
	//Inicializo todas las variables que me sirvan para procesar de forma global, ejemplo MEJOR promedio.

	while (pos < len)
	{//Inicializo todas las variables que me sirvan para procesar lotes, ejemplo promedio de CADA estudiante
		
		int legajoAnterior = vec[pos].legajo;
		promedioPorEstudiante = 0;
		cantidadNotasPorEstudiante = 0;
		sumaNotasPorEstudiante = 0;

		while (vec[pos].legajo == legajoAnterior && pos<len)
		{//Proceso cada lote (misma clave)
			sumaNotasPorEstudiante += vec[pos].notaFinal;
			cantidadNotasPorEstudiante++;
			pos++;
		}
		//Informo  procesamiento por lote
		promedioPorEstudiante = sumaNotasPorEstudiante / cantidadNotasPorEstudiante;
		//Proceso datos globales
		if (promedioPorEstudiante>maxPromedio)
		{
			maxPromedio = promedioPorEstudiante;
			legajoMaxPromedio = legajoAnterior;
		}





		cout << "El promedio del estudiante nro legajo " << legajoAnterior << endl;
		cout << promedioPorEstudiante << endl;

	}
	//Informo procesamiento global
	cout << "El maximo promedio es " << maxPromedio << endl;
	cout << "Para el legajo " << legajoMaxPromedio << endl;
	return 0;
}

