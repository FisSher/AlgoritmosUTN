// Pilas.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*Ejercicio Nro. 1:
Dada una pila y un valor X, desarrollar un procedimiento que elimine los 2 primeros
nodos de la pila y deje el valor X como primero.

Ejercicio Nro. 2:
Dada una pila y un valor X, desarrollar un procedimiento que inserte X como tercer
valor de la pila. Retornar un parámetro con valor 'S' o 'N' según haya sido exitoso o no
el requerimiento.

Ejercicio Nro. 3:
Dada una pila y dos valores X e Y, desarrollar un procedimiento que inserte el valor X
en la posición Y de la pila si es posible.

Ejercicio Nro. 4:
Dada una pila y dos valores X e Y, desarrollar un procedimiento que reemplace cada
valor igual a X que se encuentre en la pila por el valor Y retornando la pila modificada.
En caso de no haber ningún valor igual a X retornar la pila sin cambio.

Ejercicio Nro. 5:
Definir una función INVERSA que evalúe dos conjuntos de caracteres separados por un
punto y retorne True si los conjuntos son inversos (ej: ABcDe.eDcBA) o False si no lo
son. Los conjuntos deben ingresarse letra por letra por teclado.

Ejercicio Nro. 6:
Desarrollar un procedimiento que ingrese por teclado un conjunto de Apellidos de
estudiantes y los imprima en orden inverso al de ingreso.

Ejercicio Nro. 7:
Dada una pila desarrollar un procedimiento que ordene la misma de acuerdo al valor
de sus nodos y la retorne.
Para los siguientes ejercicios utilizaremos un nodo que contiene un registro con los
datos:
- Legajo
- Nombre y Apellido
- Curso*/

#include <iostream>
using namespace std;

struct Nodo {
    int info;
    Nodo* sig;
};

struct NodoInv {
    int info;
    Nodo* sig;
};


void push(Nodo*& p, int v);
int pop(Nodo*& p);
void push(NodoInv*& p, char v);
int pop(NodoInv*& p);
//Ejercicio 1 
void eliminarDosPrimeros(Nodo*& pila, int x);
//Ejercicio 2
void colocarTercerLugar(Nodo*& pila, int x, char& exitoso);
//Ejercicio 3
void colocarEnPosicionYLugar(Nodo*& pila, int x, int y, char& exitoso);
//Ejercicio 4
void reemplazarXporY(Nodo*& pila, int x, int y);
//Ejercicio 5
bool inversa(NodoInv *&colaFte, NodoInv*& colaFin);
void encolar(Nodo*& cFte, Nodo*& cFin, int v) {
    Nodo* nuevo = new Nodo();
    nuevo->info = v;
    nuevo->sig = NULL;
    if (cFte == NULL)
        cFte = nuevo;
    else
        cFin->sig = nuevo;

    cFin = nuevo;
}


int main()
{
   //Ejercicio 1 está mal definido, se quiere que X sea el primero en salir luego.
   /* 
   
   cout << "Ejercicio 1 ------" << endl;
    Nodo* pila = new Nodo();
    int x;
    cout << "Ingrese el valor X: ";
    cin >> x;
    cout << "________" << endl;
    push(pila, 90);
    push(pila, 100);
    push(pila, 1);
    eliminarDosPrimeros(pila, x);

    cout << "____________Fin ejercicio_________________" << endl;
    
    */

    //Ejercicio 2
    cout << "----------Ejercicio 2 ----------" << endl;

    Nodo* pila = new Nodo();
    push(pila, 4);
    char exitoso='N';
    
  
   
    int x;
    cout << "Ingrese x: ";
    cin >> x;
    colocarTercerLugar(pila, x, exitoso);
    if (exitoso == 'S')
        cout << "Se pudo realizar el requerimiento" << endl;
    else
        cout << "No se pudo realizar el requerimiento" << endl;


        

    cout << "____________Fin ejercicio_________________" << endl;
    




}
void push(Nodo*& p, int v) {
    Nodo* nuevo = new Nodo();
    nuevo->info = v;
    nuevo->sig = p;
    p = nuevo;
}

int pop(Nodo*& p)  {
    int retorno = p->info;
    Nodo* aux = p;
    p = aux->sig;
    delete aux;
    return retorno;
}



void eliminarDosPrimeros(Nodo*& pila, int x) {

    for (int i = 0; i < 2; i++)
    {
        pop(pila);
    }

    push(pila, x);
    while (pila != NULL) {
        cout << pop(pila) << endl;
    }
}

void colocarTercerLugar(Nodo*& pila, int x, char& exitoso) {
    Nodo* pilaAux = NULL;
    int i = 0;
    while (pila != NULL && i < 2) {
        push(pilaAux, pop(pila));
        i++;
        
    }
    if (i == 2)
    {
        exitoso = 'S';
        push(pila, x);
    }
    else
        exitoso = 'N';
    while (pilaAux != NULL) {
        push(pila, pop(pilaAux));
    }
    
}

void colocarEnPosicionYLugar(Nodo*& pila, int x,int y, char& exitoso) {
    Nodo* pilaAux = NULL;
    int i = 0;
    while (pila != NULL && i < y-1) {
        push(pilaAux, pop(pila));
        i++;

    }
    if (i == y-1)
    {
        exitoso = 'S';
        push(pila, x);
    }
    else {
        exitoso = 'N';
    }
    while (pilaAux != NULL) {
        push(pila, pop(pilaAux));
    }


}

void reemplazarXporY(Nodo*& pila, int x, int y) {
    Nodo* pilaAux = NULL;
    int valor;
    while (pila != NULL) {
        valor = pop(pila);
        if (valor == x)
            valor = y;
        push(pilaAux, valor);
    }

    while (pilaAux != NULL) {
        push(pila, pop(pilaAux));
    }
}

bool inversa(NodoInv*& colaFte, NodoInv*& colaFin) {
    NodoInv* pila = NULL;
    while (colaFte->info != '.') {
        push(pila, desencolar(colaFte, colaFin));
    }

}

