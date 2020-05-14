/*Ejercicio Nro. 
1: Dado un vector de velocidades contiene el país y su velocidad máxima y su velocidad mínima en autopistas
(Se sabe que hay 150 países listados), determinar:
a- ¿Qué país tiene la velocidad máxima más alta permitida y cuál es la misma?
b- ¿Cuál es el promedio de velocidades máximas para la lista de países? 
c- ¿Qué país tiene la velocidad mínima más baja permitida y cuál es la misma? 
 
 */


#include <iostream>
#include "vectores.hpp"
#include <string>
using namespace std;


int main()
{
    
    //Defino e inicializo el struct
    pais velocidad[150] = { {"Argentina",120,60},{"Uruguay",198,70},{"Chile",150,50} };
    int lenVelocidad = 3;
    int posMax = 0;
    int posMin = 0;
    int maxVelocidad = buscarMaximaVelocidad(velocidad,lenVelocidad,posMax);
    int minVelocidad = buscarMinimaVelocidad(velocidad, lenVelocidad, posMin);

    cout << "La maxima velocidad es " << maxVelocidad <<" en "<<velocidad[posMax].nombre <<endl;
    cout << "La minima velocidad es " << minVelocidad <<" en "<<velocidad[posMin].nombre <<endl;

    float promedio = sacarPromedioVelocidadMaxima(velocidad, lenVelocidad);
    cout << "El promedio de la velocidad maxima de los paises es " << promedio;
}
