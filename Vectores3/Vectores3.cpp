/*Ejercicio Nro. 3: Dado un número N (<=25), y dos vectores A y B de N elementos que contenga valores reales. 
• Genere e informe un tercer vector C intercalando los valores de posición impar de A y los valores de posición par de B. 
• Genere e informe un cuarto vector D donde cada elemento contenga un valor cero si los elementos de una misma posición de A y B son iguales, 
o un valor 1 si no los son.*/

#include <iostream>
#include "vectores.hpp"
using namespace std;



int main()
{
    int vecA[25];
    int vecB[25];
    int vecC[25];
    int vecD[25];
    int n = 25;
    int lenA = 0;
    int lenB = 0;
    int lenC = 0;
    int lenD = 0;

    for (int i = 0; i < 25; i++) {
        agregar(vecA, n, lenA, i * 2 + 1);
    }

    for (int i = 0; i < 25; i++) {
        agregar(vecB, n, lenB, i * 2 + 2);
    }

    for (int i = 0; i < 25; i++) {
        if (i % 2 == 0) {
            agregar(vecC, n, lenC, vecB[i]);
        }
        else {
            agregar(vecC, n, lenC, vecA[i]);
        }

        if (vecA[i] == vecB[i]) {
            agregar(vecD, n, lenD, 0);
        }
        else {
            agregar(vecD, n, lenD, 1);
        }
    }

    mostrar(vecC, lenC);

    

    mostrar(vecD, lenD);
}

