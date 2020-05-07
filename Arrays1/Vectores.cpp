#include <iostream>
#include "vectores.hpp"
using namespace std;

void inicializar(int vec[], int n) {
	for (int i = 0; i < n; i++)
	{
		vec[i] = 0;
	}
}

void agregar(int arr[], int n, int& len, int v) {
	if (len < n) {
		arr[len] = v;
		len++;
	}
	else {
		cout << "El vector esta lleno" << endl;
	}
}

void mostrar(int arr[], int len) {
	for (int i = 0; i < len; i++)
	{
		cout << "Elemento [" << i << "]: " << arr[i] << endl;
	}
}

int buscar(int arr[], int len, int v) {
	int i = 0;
	int pos = -1;
	while (i < len && arr[i] != v) {
		i++;
	}
	if (i < len) {
		pos = i;
	}

	return pos;
}

void eliminar(int arr[], int& len, int pos) {
	for (int i = pos; i < len - 1; i++)
	{
		arr[i] = arr[i + 1];
	}
	len--;
	arr[len] = 0;
}

void insertar(int arr[], int& len, int v, int pos) {
	for (int i = len - 1; i >= pos; i--)
	{
		arr[i + 1] = arr[i];
	}
	arr[pos] = v;
	len++;
}

int insertarOrdenado(int arr[], int& len, int v) {
	int i = 0;
	while (i < len && arr[i] <= v)
	{
		i++;
	}
	insertar(arr, len, v, i);
	return i;
}

int buscaEInserta(int arr[], int& len, int v, bool& enc) {
	int pos = buscar(arr, len, v);
	if (pos == -1) {
		enc = false;
		pos = insertarOrdenado(arr, len, v);
	}
	else {
		enc = true;
	}
	return pos;
}

int buscarMinimo(int arr[], int& len) {
	int min = 999999;
	for (int i = 0; i < len; i++)
	{
		if (arr[i] < min) {
			min = arr[i];
		}

	}
	return min;
}