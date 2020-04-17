/*Ejercicio Nro.  3: Se desea saber si se ha formado “generala” (es decir, si los 5 dados muestran el mismo número)
de una sola tirada de 5 dados. */
#include <iostream>
using namespace std;

bool ValidarGenerala(int a, int b, int c, int d, int e);

int main()
{
   int a, b, c, d, e; //Variables genericas debido a que el programa es sencillo
   cout << "Ingrese el primer numero: ";
   cin >> a;
   cout << "Ingrese el segundo numero: ";
   cin >> b;
   cout << "Ingrese el tercer numero: ";
   cin >> c;
   cout << "Ingrese el cuarto numero: ";
   cin >> d;
   cout << "Ingrese el quinto numero: ";
   cin >> e;
   bool respuesta = ValidarGenerala(a, b, c, d, e);
   if (respuesta == true) 
   {
       cout << "Es generala";
   }
   else 
   {
       cout << "No es generala";
   }
}

bool ValidarGenerala(int a, int b, int c, int d, int e) 
{
    if (a == b && a == c && a == d && a == e) {
        return true;
    }
    else {
        return false;
    }
}
