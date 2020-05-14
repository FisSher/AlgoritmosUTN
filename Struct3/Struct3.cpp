/*Ejercicio Nro.  3: Realizar un programa que gestione los datos de stock de un quiosco, la información a guardar será:
código del producto, nombre del producto, precio y cantidad en stock. El quiosco dispone de 10 productos distintos. El programa debe ser capaz de:
a- Dar de alta un producto nuevo.
b- Buscar un producto por su nombre.
c- Modificar el stock y precio de un producto dado.*/
#include <iostream>
#include "vectores.hpp"
#include <string>
#include "Struct3.h"
using namespace std;

void imprimirMenu();

int main()
{
	producto listado[10] = { {1,"alfajor",40.5,10}, {2,"galletitas",35,5}, {3,"bizcochos",25.2,3} };
	int listadoLen = 3;
	int opcion = -1;
	imprimirMenu();
	int n = 10;

	cin >> opcion;
	while (opcion != 0) {
		switch (opcion) {
		case 1: {
			producto productoNuevo;
			cout << "Ingrese codigo de producto" << endl;
			cin >> productoNuevo.codigo;
			cout << "Ingrese nombre" << endl;
			cin >> productoNuevo.nombre;
			cout << "Ingrese precio" << endl;
			cin >> productoNuevo.precio;
			cout << "Ingrese stock" << endl;
			cin >> productoNuevo.stock;
			agregar(listado, n, listadoLen, productoNuevo);
			mostrarProducto(listado, listadoLen);
			break;
		}
		case 2: {
			int codigo = 0;
			cout << "---------------------" << endl;
			cout << "Ingrese codigo a buscar" << endl;
			cin >> codigo;
			cout << "---------------------" << endl;
			int pos = buscar(listado, listadoLen, codigo);
			if (pos == -1) {
				cout << "No se encontro el producto" << endl;
			}
			else {
				cout << "Codigo: " << listado[pos].codigo << endl;
				cout << "Nombre: " << listado[pos].nombre << endl;
				cout << "Precio: " << listado[pos].precio << endl;
				cout << "Stock: " << listado[pos].stock << endl;
			}
			cout << "---------------------" << endl;
			break;
		}
		case 3: {
			int codigo = 0;
			cout << "---------------------" << endl;
			cout << "Ingrese codigo a modificar" << endl;
			cin >> codigo;
			cout << "---------------------" << endl;
			int pos = buscar(listado, listadoLen, codigo);
			if (pos == -1) {
				cout << "No se encontro el producto" << endl;
			}
			else {
				cout << "El stock actual es: " << listado[pos].stock << endl;;
				cout << "Ingrese el nuevo stock: ";
				cin >> listado[pos].stock;

				cout << "---------------------" << endl;

				cout << "Codigo: " << listado[pos].codigo << endl;
				cout << "Nombre: " << listado[pos].nombre << endl;
				cout << "Precio: " << listado[pos].precio << endl;
				cout << "Stock: " << listado[pos].stock << endl;
			}
			cout << "---------------------" << endl;
			break;
		}
		case 4: {
			int codigo = 0;
			cout << "---------------------" << endl;
			cout << "Ingrese codigo a modificar" << endl;
			cin >> codigo;
			cout << "---------------------" << endl;
			int pos = buscar(listado, listadoLen, codigo);
			if (pos == -1) {
				cout << "No se encontro el producto" << endl;
			}
			else {
				cout << "El precio actual es: " << listado[pos].precio << endl;;
				cout << "Ingrese el nuevo precio: ";
				cin >> listado[pos].precio;

				cout << "---------------------" << endl;

				cout << "Codigo: " << listado[pos].codigo << endl;
				cout << "Nombre: " << listado[pos].nombre << endl;
				cout << "Precio: " << listado[pos].precio << endl;
				cout << "Stock: " << listado[pos].stock << endl;
			}
			cout << "---------------------" << endl;
			break;
		}
		}
		imprimirMenu();
		cin >> opcion;
	}
}

void imprimirMenu() {
	cout << "Ingrese opcion: " << endl;
	cout << "1 Agregar" << endl;
	cout << "2 Buscar" << endl;
	cout << "3 Editar stock" << endl;
	cout << "4 Editar precio" << endl;
	cout << "0 Salir" << endl;
}