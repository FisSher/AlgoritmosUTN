/*Ejercicio Nro. 6: Dado un valor numérico entero que se ingresa por teclado, se pide informar: 
• La quinta parte de dicho valor, 
• el resto de la división por 5  
• la séptima parte de la quinta parte. */

#include <iostream>
using namespace std;

int CalcQuintaParte(float numero);
int RestoDivisionPorCinco(int numero);

int main()
{
    int numero;
    cout << "Ingresar el numero entero: ";
    cin >> numero;

    int resultado = CalcQuintaParte(numero);
    cout << "La quinta parte es: "<<resultado<<endl;

    resultado = RestoDivisionPorCinco(numero);
    cout << "El resto de la division es: "<<resultado<<endl;

    resultado = CalcQuintaParte(numero)/7;
    cout << "La septima parte de la quinta parte es: "<<resultado<<endl;
}   


int CalcQuintaParte(float numero)
{
    return (numero / 5);

}

int RestoDivisionPorCinco(int numero)
{
    return (numero % 5);
}


