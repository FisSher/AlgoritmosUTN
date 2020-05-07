#include <iostream>
#include <string>
#include "matrices.hpp"
using namespace std;

int main() {
	float matriz[MAX_FILAS][MAX_COLUMNAS];
	int cantFilas;
	int cantColumnas;
	float maxMedicion;
	float minMedicion;
	int posFilMax;
	int posColMax;
	int posFilMin=0;
	int posColMin=0;

	cout << "Ingrese la cantidad de filas" << endl;
	cin >> cantFilas;

	//Validar que se ingrese un numero correcto de filas

	cout << "Ingrese la cantidad de Columnas" << endl;
	cin >> cantColumnas;

	//Validar que se ingrese un numero correcto de columnas

	inicializar(matriz, cantFilas, cantColumnas);
	cargar(matriz, cantFilas, cantColumnas);
	mostrar(matriz, cantFilas, cantColumnas);
	maxMedicion = buscarMaximaMedicion(matriz, cantFilas, cantColumnas, posFilMax, posColMax);
	mostrarResultado("La maxima medicion ", maxMedicion, posFilMax, posColMax);
	minMedicion = buscarMinimaMedicion(matriz, cantFilas, cantColumnas, posFilMax, posColMax);
	mostrarResultado("La minima medicion ", minMedicion, posFilMin, posColMin);
	return 0;
}

