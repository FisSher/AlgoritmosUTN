/*Ejercicio Nro.  2: Dado un vector de notas que contiene el c�digo de la materia y la cantidad de alumnos inscriptos obtenida.
Se sabe que hay 50 materias, determinar: a- �Cu�l fue la materia que m�s inscriptos tuvo? 
b- �Cu�l fue la materia que menos inscriptos tuvo? 
c-  Calcular el promedio de inscriptos en todas las materias.*/

#include <iostream>
#include <string>
#include "vectores.hpp"
using namespace std;


int main()
{
    notas Notas[50] = { {123,40}, {852,66}, {423,32} };
    int lenNotas = 3;
    int posMin = 0; //Le cambie posici�n por c�digo
    int posMax = 0;
    int masInscriptos = contarMaximoAlumnos(Notas, lenNotas, posMax);
    cout <<"Maximo de inscriptos: "<< masInscriptos<<" del curso "<<posMax<<endl;
    int menosInscriptos = contarMinimoAlumnos(Notas, lenNotas, posMin);
    cout << "Minimo de inscriptos: "<<menosInscriptos <<" del curso "<< posMin<<endl;
    int promedio = calculaPromedioInscriptos(Notas, lenNotas);
    cout <<"Promedio: "<< promedio<<endl;



}

