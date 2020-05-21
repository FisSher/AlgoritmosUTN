/*Ejercicio Nro. 1: Se cuenta con dos vectores ordenados que tendrán como máximo 5 elementos cada uno.
Generar un nuevo vector con el apareo de ambos vectores y mostrarlo por pantalla. */

#include <iostream>
#include <string>
#include "../Arrays1/Vectores.cpp"
using namespace std;

int main()
{
    int vecA[5] = { 3,7,9,14,20 };
    int vecB[6] = { 2,5,10,11,25,30 };
    int vecC[11];
    int lenA = 5;
    int lenB = 6;
    int lenC = 0;
    int posA = 0;
    int posB = 0;
    int posC = 0;

    while (posA < lenA && posB < lenB) {
        if (vecA[posA] < vecB[posB]) {
            agregar(vecC, 11, lenC, vecA[posA]);
            posA++;

        }
        else {
            agregar(vecC, 11, lenC, vecB[posB]);
            posB++;
        }
    }

    while (posA < lenA) {
        agregar(vecC, 11, lenC, vecA[posA]);
        posA++;
    }

    while (posB < lenB) {
        agregar(vecC, 11, lenC, vecB[posB]);
        posB++;
    }

    mostrar(vecC, lenC);
    

}

