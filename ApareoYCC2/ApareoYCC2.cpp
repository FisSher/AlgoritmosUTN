/*Ejercicio Nro. 2: Se cuenta con dos vectores que contienen los datos de los estudiantes que pertenecen a dos cursos de AED.
Los cursos tienen como máximo 10 estudiantes cada uno. De cada estudiante sabemos: legajo, apellido y promedio. 
Los datos se encuentran ordenados por legajo. Obtener un vector consolidado con los estudiantes de ambos cursos y mostrarlo por pantalla. 
 */

#include <iostream>
#include <string>
#include "vectores.hpp"
using namespace std;

int main()
{
    estudiantes curso1[3] = {{ 1,"Paolini",6.1 }, { 2,"Gonzales",7.6 }, { 4,"Cassandra",3.4 }};
    estudiantes curso2[2] = { {3,"Carrasco",9.9}, {5,"Perez",8.6} };
    estudiantes cursoO[5];
    int len1 = 3;
    int len2 = 2;
    int lenO = 0;
    int pos1 = 0;
    int pos2 = 0;
    int posO = 0;

    while (pos1<len1 && pos2<len2)
    {
        if (curso1[pos1].legajo < curso2[pos2].legajo) {
            agregar(cursoO, 5, lenO, curso1[pos1]);
            pos1++;
        }
        else {
            agregar(cursoO, 5, lenO, curso2[pos2]);
            pos2++;
        }
    }
    while (pos1<len1)
    {
        agregar(cursoO, 5, lenO, curso1[pos1]);
        pos1++;
    }
    while (pos2<len2)
    {
        agregar(cursoO, 5, lenO, curso2[pos2]);
        pos2++;
    }
    mostrar(cursoO, lenO);
}

