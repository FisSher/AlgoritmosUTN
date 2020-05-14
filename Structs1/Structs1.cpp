/*Ejercicio Nro. 
1: Dado un vector de velocidades contiene el pa�s y su velocidad m�xima y su velocidad m�nima en autopistas
(Se sabe que hay 150 pa�ses listados), determinar:
a- �Qu� pa�s tiene la velocidad m�xima m�s alta permitida y cu�l es la misma?
b- �Cu�l es el promedio de velocidades m�ximas para la lista de pa�ses? 
c- �Qu� pa�s tiene la velocidad m�nima m�s baja permitida y cu�l es la misma? 
 
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
