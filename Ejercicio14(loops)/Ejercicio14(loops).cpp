/*Ejercicio Nro. 4: En un torneo de fútbol participan k equipos. 
El torneo se juega con el sistema de “todos contra todos”. 
Por cada partido en el que participa un equipo se dispone de la siguiente información: 
• código de equipo (codEq) y 
• código de resultadp (“P” = perdido, “E” = empatado, “G”= ganado). 
Se dispone de un lote de datos conteniendo todos los resultados del torneo, agrupados por codEq.
Desarrollar el programa que imprima, por cada equipo, su código y el puntaje total que obtuvo considerando que suma 3 
puntos por cada partido ganado y 1 punto por cada partido empatado.*/


//Ingresar el numero de equipos para saber cuantos son
// K-1 partidos jugados
// 2 for 1 de o a K, otro de 0 a K-1 que es la cantidad de partidos jugados

#include <iostream>
using namespace std;

int main()
{
    int numeroEquipos=0;
    int codigoEq=0;
    char respuesta;
    cout << "Ingrese el numero de equipos: ";
    cin >> numeroEquipos;


    for (int equipo = 0; equipo < numeroEquipos; equipo++) {
        int puntos = 0;
        cout << "Ingrese el codigo del equipo "<<equipo<<" -> ";
        cin >> codigoEq;
        cout << "Completar partidos para el equipo: " << codigoEq <<  endl;
        for (int partido = 0; partido < numeroEquipos - 1 ; partido++)
        {
            cout << "Partido: " << partido << endl;
            cout << "Elija un resultado: 'P' = perdido, 'E' = empatado, 'G'= ganado " << endl;
            cout << "Su respuesta: ";
            cin >> respuesta;
            switch (respuesta) {

            case 'G':
                cout << "Victoria suma 3 puntos" << endl;
                puntos = puntos + 3;
                cout << "Llevamos un total de " << puntos << " puntos." << endl;
                break;
            case 'E':

                cout << "Empate suma 1 punto" << endl;
                puntos = puntos + 1;
                cout << "Llevamos un total de " << puntos << " puntos." << endl;
                break;
            case 'P':
                cout << "Derrota no suma puntos" << endl;
                cout << "Llevamos un total de " << puntos << " puntos." << endl;
                break;
            }
        }
        cout << "#######################################################################################" << endl;
        cout << "La carga del equipo ha finalizado, su total es de " << puntos << " puntos." << endl;
        cout << "#######################################################################################" << endl;
    }
}
