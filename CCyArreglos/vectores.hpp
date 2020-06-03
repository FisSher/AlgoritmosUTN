#pragma once
#include <string>
using namespace std;

struct venta {
	string sucursal;
	int dia;
	float recaudacion;
};

#ifndef vectores
#define vectores

//vec: El vector en si.
//n: Cantidad de elementos totales que puede almacenar el vector.
//len: cantidad de elementos reales que hay dentro del vector actualmente.
//v: valor a ser agregado.
void inicializar(int vec[], int n);
void agregar(int arr[], int n, int& len, int v);
void mostrar(int arr[], int len);
int buscar(int arr[], int len, int v);
void eliminar(int arr[], int& len, int pos);
void insertar(int arr[], int& len, int v, int pos);
int insertarOrdenado(int arr[], int& len, int v);
int buscaEInserta(int arr[], int& len, int v, bool& enc);

#endif