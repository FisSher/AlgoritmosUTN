/*Desarrollar una función void tal que dada una hora (hhmmss) y un tiempo también en formato hhmmss devuelva la nueva hora que surge de sumar 
el tiempo a la hora inicial, considere también un posible cambio el día. El prototipo de la función debe ser el siguiente:
void sumarHora(long h, long t, long& res);*/
#include <iostream>
using namespace std;


void sumarHora(long h, long t, long &res, bool &nuevoDia);

int main()
{
    long hora1 = 0;
    long hora2 = 0;
    long res = 0;
    bool nuevoDia = false;

    cout << "Ingrese el primer horario HHMMSS: ";
    cin >> hora1;
    cout << "Ingrese el segundo horario HHMMSS: ";
    cin >> hora2;
    sumarHora(hora1,hora2,res,nuevoDia);
    cout << res<<endl;
    if (nuevoDia) {
        cout << "Es un nuevo día";
    }
    
}

void sumarHora(long h, long t, long &res, bool &nuevoDia) {
    long hHora = hHora = h / 10000;
    long hMinutos = (h / 10000) / 100;
    long hSegundos = h % 100;

    long tHora = t / 10000;
    long tMinutos = (t % 10000) / 100;
    long tSegundos = t % 100;

    long segundosFinales = hSegundos + tSegundos;
    long minutosFinales = hMinutos + tMinutos;
    long horasFinales = hHora + tHora;

    if (segundosFinales >= 60) {
        segundosFinales = segundosFinales - 60;
        minutosFinales++;
    }

    if (minutosFinales >= 60) {
        minutosFinales = minutosFinales - 60;
        horasFinales++;        
    }

    if (horasFinales >= 24) {
        horasFinales = horasFinales - 24;
        nuevoDia = true;
    }

    res = horasFinales * 10000 + minutosFinales * 100 + segundosFinales;
    

}