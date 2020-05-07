/*Ejercicio Nro. 4: Escriba un programa que permita ingresar la tirada de un par de dados 50 veces y
muestre una lista donde se vea cuántas veces se dio cada uno de los resultados posibles. Por cada tirada se deberán ingresar 2 valores,
cada uno representa el valor de un dado. El formato de salida debe ser el siguiente: 2 salió X veces 3 salió X veces .. 12 salió X veces */

#include <iostream>
#include "vectores.hpp"
using namespace std;
int main()
{
    int dado1;
    int dado2;
    int suma;
    int resultado[11];
    int n = 11;
    int indice = 0;
    inicializar(resultado, n);

    //En realidad es i<50
    for (int i = 0; i < 5; i++)
    {
        cout << "Ingrese los dados de la tirada " << i + 1<<endl;
        cout << "Ingrese el dado 1: " << endl;
        cin >> dado1;
        cout << "Ingrese el dado 2: ";
        cin >> dado2;
        suma = dado1 + dado2;
        indice = suma - 2;
        resultado[indice]++;
    }
    for (int i = 0; i < n; i++)
    {
        cout << i + 2 << " salio " << resultado[i] << " veces"<<endl;

    }

}

