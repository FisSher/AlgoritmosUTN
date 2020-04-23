/* Ejercicio21Desarrolle la funci�n unificarFecha que recibe tres par�metros que representan el d�a, mes y a�o de una fecha y retorna la fecha unificada en un entero largo de 8 d�gitos 
con el siguiente formato: aaaammdd. El prototipo de la funci�n debe ser el siguiente: long unificarFecha(int dia, int mes, int anio);*/

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