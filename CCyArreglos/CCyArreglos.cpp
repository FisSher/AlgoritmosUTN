/*Corte de Control con Arreglos 
 
Se cuenta con un vector que contiene los datos de las ventas del mes de abril de una cadena de supermercados. 
Cada registro de venta tiene: la sucursal, el día y el dinero recaudado. 
El vector se encuentra agrupado por sucursal.
Se pide obtener:  
- El dinero recaudado por cada sucursal en el mes. 
- El día en que cada sucursal recaudó más dinero (sólo hay uno). 
- La sucursal que menos dinero recaudó en el mes (sólo hay una).*/
#include <iostream>
#include "vectores.hpp"
#include <string>
using namespace std;


int main()
{
    venta vect[60] = { { "Sucursal1" , 23, 123 },
    { "Sucursal1",2,534.3 },
    { "Sucursal1",5,232.44 },
    { "Sucursal1",6,1232 },
    { "Sucursal2",23,3333 },
    { "Sucursal2",14,1231 },
    { "Sucursal2",24,1231 },
    { "Sucursal2",5,900.1 }
    };

    int len = 7;
    int pos = 0;
    float menorRecaudacion = 99999999;
    string sucMenorRecaudacion="";

    while (pos<len)
    {
        string sucAnterior = vect[pos].sucursal;
        float recaudacionMensual = 0;
        int diaMayorRecaudacion = 0;
        float maxRecaudacion = 0;
        while (sucAnterior==vect[pos].sucursal && pos<len)
        {
            recaudacionMensual += vect[pos].recaudacion;


            if (vect[pos].recaudacion > maxRecaudacion) 
            {
                diaMayorRecaudacion = vect[pos].dia;
                maxRecaudacion = vect[pos].recaudacion;
            }
            
            pos++;
        }
        cout << "Para " << sucAnterior << " su recaudacion mensual fue de " << recaudacionMensual << " la mayor recaudacion fue el dia " << diaMayorRecaudacion << endl;

        if (recaudacionMensual < menorRecaudacion) {
            menorRecaudacion = recaudacionMensual;
            sucMenorRecaudacion = vect[pos].sucursal;
        }
    }

    cout << "La menor recaudacion fue de " << menorRecaudacion;
};

