/* Ejercicio21Desarrolle la función unificarFecha que recibe tres parámetros que representan el día, mes y año de una fecha y retorna la fecha unificada en un entero largo de 8 dígitos 
con el siguiente formato: aaaammdd. El prototipo de la función debe ser el siguiente: long unificarFecha(int dia, int mes, int anio);*/

#include <iostream>
using namespace std;

long unificarFecha(int dia, int mes, int anio);


int main()
{
    int dia;
    int mes;
    int anio;

    cout << "Ingrese un anio: ";
    cin >> anio;
    cout << "Ingrese mes: ";
    cin >> mes;
    cout << "Ingrese dia: ";
    cin >> dia;

    long fecha = unificarFecha(dia, mes, anio);
    cout << "La fecha es: " << fecha;
}


long unificarFecha(int dia, int mes, int anio) {
    long fecha;
    fecha = anio * 10000 + mes * 100 + dia;
    return fecha;
}