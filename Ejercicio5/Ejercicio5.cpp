/*Ejercicio Nro.  5: Se necesita saber el tipo de un triángulo, ingresando las dimensiones de los lados por separado*/

#include <iostream>
using namespace std;

void DeterminarTriangulo(float a,float b,float hip);

int main()
{
    float ladoA, ladoB, hip;
    cout << "Ingrese el lado A: ";
    cin >> ladoA;
    cout << "Ingrese el lado B: ";
    cin >> ladoB;
    cout << "Ingrese la hipotenusa o lado C: ";
    cin >> hip;
    DeterminarTriangulo(ladoA, ladoB, hip);
}

void DeterminarTriangulo(float a, float b, float hip) 
{
    if (a == b && a == hip && hip == b) {
        cout << "Es un triangulo equilatero \n";
    }
    else if (hip != a && hip != b && a == b) {
        cout << "Es un triangulo isosceles \n";
    }
    else if (a!=b && a!=hip && b!=hip){
        cout << "Es un triangulo escaleno \n";
    }
    else {
        cout << "Error de datos ingresados \n";
    }
}
