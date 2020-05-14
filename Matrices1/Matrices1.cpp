/*
Matrices  
Ejercicio Nro.  1: Ingresar los datos de una matriz de 3x3 y mostrar su traspuesta (el resultado de intercambiar filas por columnas). 
Ejercicio Nro.  2: Ingresar los datos de una matriz de 3x3, y mostrar su determinante. 
Ejercicio Nro.  3: Ingresar los datos de una matriz de 3x3, y mostrar su matriz adjunta.  
Ejercicio Nro.  4: Ingresar los datos de una matriz de 3x3, y mostrar su matriz inversa.  
Ejercicio Nro.  5: Ingresar los datos de dos matrices de 2x2, y mostrar su producto. 
*/



//No lo terminé porque matemáticamente hice un desastre y tendría que rehacerlos.
#include <iostream>
#include "vectores.hpp"
using namespace std;
void mostrar(int matriz[][3], int filas, int columnas);
void mostrar(int matriz[][2], int filas, int columnas);
void transponer(int matriz[][3], int filas, int columnas);
int determinante(int matriz[][3]);
void adjunta(int matriz[][3], int filas, int columnas);
void multiplicar(int matrizA[][2], int matrizB[][2], int filas, int columnas);

int main()
{
	
	int matrizA[3][3] = {1,2,3,4,5,6,7,8,9};
	int matrizB[2][2] = { 1,2,3,4 };
	int matrizC[2][2] = { 4,3,2,1 };
	int filasA = 3;
	int columnasA = 3;
	int filasB = 2;
	int columnasB = 2;

	cout << "La matriz A es: " << endl;
	mostrar(matrizA, filasA, columnasA);
	cout << "###################" << endl;
	cout << "La matriz B es: " << endl;
	mostrar(matrizB, filasB, columnasB);
	cout << "###################" << endl;
	cout << "La transpuesta de la matriz A es: " << endl;
	transponer(matrizA, filasA, columnasA);
	cout << "###################" << endl;
	cout<<"El determinante de la matriz A es: "<<determinante(matrizA)<<endl;
	cout << "###################" << endl;
	adjunta(matrizA, filasA, columnasA);
	cout << "###################" << endl;
	multiplicar(matrizB, matrizC, filasB, columnasB);

}

//Tengo un overload de 3 funciones por necesidad del ejercicio.
void transponer(int matriz[][3],int filas,int columnas) {
	for (int i = 0; i < filas; i++)
	{
		for (int j = 0; j < columnas; j++)
		{

			cout << matriz[j][i];

		}
		cout << endl;

	}
}
void mostrar(int matriz[][2], int filas, int columnas) {
	for (int i = 0; i < filas; i++)
	{
		for (int j = 0; j < columnas; j++)
		{

			cout << matriz[i][j];

		}
		cout << endl;

	}
}
void mostrar(int matriz[][3], int filas, int columnas) {
	for (int i = 0; i < filas; i++)
	{
		for (int j = 0; j < columnas; j++)
		{

			cout << matriz[i][j];

		}
		cout << endl;

	}
}
int determinante(int matriz[][3]) {
	return matriz[0][0]* matriz[1][1]* matriz[2][2]+ matriz[0][1]* matriz[1][2]* matriz[2][0]+ matriz[0][2]*matriz[1][0]*matriz[2][1];
	
}
//Acá tengo dudas
void adjunta(int matriz[][3], int filas, int columnas) {
	int det=determinante(matriz);
	for (int i = 0; i < filas; i++)
	{
		for (int j = 0; j < columnas; j++)
		{

			 matriz[i][j]=(1/matriz[i][j])/det; //no recuerdo este cálculo, hay mucha teoría con diferentes posibilidades pero 
			 //debería poder reciclar o poder hacer 1/det de la matriz era?

		}
	}
	mostrar(matriz,filas,columnas);
}
void multiplicar(int matrizA[][2], int matrizB[][2], int filas, int columnas) {
	int resultado[2][2];
	for (int i = 0; i < filas; i++)
	{
		for (int j = 0; j < columnas; j++)
		{
			resultado[i][j] = matrizA[i][j] * matrizB[i][j];
			

		}
		

	}
	mostrar(resultado, filas, columnas);
}
