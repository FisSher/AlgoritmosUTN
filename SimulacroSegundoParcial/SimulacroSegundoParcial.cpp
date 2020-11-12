#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "funciones.hpp"
using namespace std;

//Ej1
/*Crear un procedimiento que dadas dos listas A y B, 
llene una lista C con la uni�n (sin repetidos) de las listas A y B.*/
/*

struct infoB {
    int id;
};

struct NodoB {
    NodoB* sig;
    infoB info;
};

struct infoA {
    int id;
};

struct NodoA {
    NodoA* sig;
    infoA info;

};

struct infoC {
    int id;
};

struct NodoC {
    NodoC* sig;
    infoC info;
};


void llenarLista(NodoA* listaA, NodoB* listaB,  NodoC* listaC) {
    bool enc;
    while (listaA != NULL)
    {
        buscaEInserta(&listaC, listaA->info.id, &enc);  //--------> 1)No dec�a nada del orden o no, pero aprovech� esta funci�n para evitar repetir
        listaA = listaA->sig;
    }
    while (listaB!=NULL)
    { 
        buscaEInserta(&listaC, listaB->info.id, &enc);
        listaB = listaB->sig;
    }

}



*/
//Ej2
/* En el archivo �turnos20201031.dat� tenemos el listado de turnos de un consultorio para un d�a en particular. 
De los turnos sabemos la hora (integer) y el nombre del paciente. 
Ordenar la informaci�n contenida en el archivo por hora y colocarlo en una cola para que puedan ser llamados.*/
/*
struct turno {
    int hora;
    char paciente[50];
};

struct NodoCola {
    NodoCola* sig;
    turno info;
};


struct NodoLista {
    NodoLista* sig;
    turno info;
};

void encolar(NodoCola*& p, NodoCola*& q, turno v);
NodoLista* insertarOrdenado(NodoLista*& p, int v);

int main() {

    NodoLista* listaPacientes = NULL;
    NodoCola* cfte = NULL;
    NodoCola* cfin = NULL;
    FILE* turnos = fopen("turnos20201031.dat", "rb");
    turno regTurno;
    turno regLista;
    turno regCola;

    fread(&regTurno, sizeof(turno), 1, turnos);
    while (!feof(turnos))
    {
        regLista.hora = regTurno.hora;
        strcpy(regLista.paciente, regTurno.paciente);
        insertarOrdenado(listaPacientes, regLista.hora); ------> 2)Ac� es regLista? porque necesito comparar por hora, pero no sab�a bien que pasarle.

        fread(&regTurno, sizeof(turno), 1, turnos);
    }
    fclose(turnos);

    //Ahora tengo la lista con los turnos ordenados de menor a mayor.

    while (listaPacientes!=NULL)
    {
        encolar(cfte,cfin,listaPacientes->info); -------> 3) Esto al final quedaba as�? hab�amos hablado de unificar el struct "turno"
        listaPacientes = listaPacientes->sig;
    }

    //ac� est� encolada la lista.


}*/
//Ej3   -------> Sin dudas en este
/*Desarrollar un procedimiento que permita ingresar caracteres por teclado.
Si se ingresa una letra(A - Z) se inserta en la pila.  
Si se ingresa un asterisco se saca un elemento de la pila. char
Imprimir la secuencia de caracteres que se sacaron de la pila.
El ingreso de caracteres termina cuando se ingresa un punto.

Nota: El valor ascii de la A es 65 y el de la Z es 90.*/
/*
struct infoPila {
    char letra;
};

struct NodoPila {
    NodoPila* sig;
    infoPila info;
};
void push(NodoPila*& p, char v);
char pop(NodoPila*& p);

int main() {
    NodoPila* pila = NULL;
    char valorIngresado = NULL;

    cout << "Ingresar valor: ";
    cin >> valorIngresado;

    while (valorIngresado!='.')
    {
        if (valorIngresado >= 65 || valorIngresado <= 90) 
             push(pila, valorIngresado);
        if (valorIngresado == '*')
            pop(pila);


        cout << "Ingresar valor: ";
        cin >> valorIngresado;
    }
    //Ahora queda hacer el pop de todo lo que hay dentro de la pila

    while (pila != NULL) {
        cout << "Los valores son: " << endl;
        cout << pop(pila) << endl;
        
    }



}*/
//Ej4 -------> 4) podr�s revisar en este que haya operado bien en las listas de la primera parte? llega un punto que me empiezo a marear de tanto que anido.
/* 
Se tiene un archivo �ventas.dat� que contiene los siguientes datos: 
n�mero de cliente, art�culo comprado, cantidad comprada y precio unitario. 
Con estos datos llenar una lista que debe contener n�mero de cliente y dinero gastado. 
A su vez cada nodo de esa lista, va a poseer una sublista de los art�culos comprados, 
junto con su cantidad comprada y precio unitario. 
Nota: El precio unitario para cada art�culo no var�a. 
Si el art�culo se repite por cada cliente debe incrementarse su cantidad vendida.

Informar:

    Cu�l es el cliente que menos dinero gast�.
    Cu�l es el cliente que m�s unidades totales de productos compr�.
*/
/*
struct Venta {
    int numeroCliente;
    int articulo;
    int cantidad;
    float precioUnitario;
};

struct InfoArt {
    int cantidadComprada;
    float precioUnitario;
    int id;
};

struct Articulo {
    Articulo* sig;
    InfoArt info;
};

struct InfoCliente {
    int numeroCliente;
    float dineroGastado;
    Articulo* articulos;
};

struct Cliente {
    Cliente* sig;
    InfoCliente info;
};

int main() {
    FILE* ventas = fopen("ventas.dat", "rb");
    Venta regVenta;
    InfoCliente regCli;
    InfoArt regArt;
    Cliente* listaClientes = NULL;
    bool enc;
    Articulo* artBuscado;
    Cliente* cliBuscado;


    fread(&regVenta, sizeof(Venta), 1, ventas);

    while (!feof(ventas))
    {
        regCli.numeroCliente = regVenta.numeroCliente;
        regCli.dineroGastado = 0;
        regCli.articulos = NULL;
        cliBuscado = buscaEInserta(listaClientes, regCli.numeroCliente, enc);

        regArt.id = regVenta.articulo;
        regArt.cantidadComprada = regVenta.cantidad;
        regArt.precioUnitario = regVenta.precioUnitario;

        artBuscado = buscaEInserta(listaClientes->info.articulos, regArt.id, enc);
        if (enc)
            artBuscado->info.cantidadComprada += regArt.cantidadComprada;

        listaClientes->info.dineroGastado += regArt.cantidadComprada * regArt.precioUnitario;


        fread(&regVenta, sizeof(Venta), 1, ventas);
    }
    fclose(ventas);

    float menosDineroGastado = 9999999;
    int MasUniProdCompradas = 0;
    int clienteMasCompras = 0;
    int cliMenosDineroGastado = 0;

    Cliente* listaAux = listaClientes;

    while (listaAux!=NULL)
    {
        if (listaAux->info.articulos->info.cantidadComprada>MasUniProdCompradas)
            MasUniProdCompradas = listaAux->info.articulos->info.cantidadComprada;
        
        if (listaAux->info.dineroGastado < menosDineroGastado)
            cliMenosDineroGastado = listaAux->info.numeroCliente;

        listaAux = listaAux->sig;
    }
    cout << "El cliente que menos dinero gasto fue: " << cliMenosDineroGastado<<endl;
    cout << "El cliente que mas productos compro fue: " << clienteMasCompras << endl;

}
*/