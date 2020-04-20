/*Ejercicio Nro.  7: Se ingresa un número con el formato YYYYMMDD. A partir de ese número mostrar el año(YYYY), el mes(MM) y el día (DD). */

#include <iostream>
using namespace std;
int main()
{
    
    int fecha;
    int mes;
    int anio;
    int dia;

    cout << "Ingrese una fecha en formato YYYYMMDD: ";
    cin >> fecha;
    anio = fecha / 10000;
    mes = (fecha % 10000)/100;
    dia = (fecha % 1000) % 100;
    //Otra opcion dia = fecha % 100

    cout << "El anio es: " << anio<<endl;
    cout << "El mes es: " << mes<<endl;
    cout << "El dia es: " << dia<<endl;


}

