/*Ejercicio Nro.  4: Dado un número ingresado por el usuario determinar si el mismo es IMPAR.*/

#include <iostream>
using namespace std;

bool ValidarParidad(int numero);

int main()
{
    int numero;
    cout << "Ingrese el numero a validar: ";
    cin >> numero;
    bool resultado = ValidarParidad(numero);
    if (resultado) {
        cout << "Es par";
    }
    else {
        cout << "Es impar";
    }
    
}

bool ValidarParidad(int numero) 
{
    if (numero % 2 == 0) {
        return true;
    }
    else {
        return false;
    }

}

