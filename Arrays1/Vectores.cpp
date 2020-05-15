#include <iostream>
#include "vectores.hpp"
#include "../Structs1/vectores.hpp"
#include <string>
#include "../Structs2/vectores.hpp"
#include "../Struct3/vectores.hpp"
#include "../Structs4/vectores.hpp"

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
int buscarMaximaVelocidad(pais vec[], int len, int& pos) {
	int max = -1;
	for (int i = 0; i < len; i++)
	{
		if (vec[i].velocidadMax > max)
		{
			max = vec[i].velocidadMax;
			pos = i;
		}
	}
	return max;
}
int buscarMinimaVelocidad(pais vec[], int len, int& pos) {
	int min = 99999;
	for (int i = 0; i < len; i++)
	{
		if (vec[i].velocidadMin > min)
		{
			min = vec[i].velocidadMin;
			pos = i;
		}
	}
	return min;
}
float sacarPromedioVelocidadMaxima(pais vec[], int len) {
	float suma = 0;;
	for (int i = 0; i < len; i++)
	{
		suma += vec[i].velocidadMax;
	}
	return suma / len;
}
int contarMaximoAlumnos(notas vec[], int len, int& pos) {
	int max = 0;
	for (int i = 0; i < len; i++)
	{
		if (vec[i].cantAlumnos > max) {
			max = vec[i].cantAlumnos;
			pos = vec[i].codigo;
		}
	}
	return max;
}
int contarMinimoAlumnos(notas vec[], int len, int& pos) {
	int min = 9999;
	for (int i = 0; i < len; i++)
	{
		if (vec[i].cantAlumnos < min) {
			min = vec[i].cantAlumnos;
			pos = vec[i].codigo;
		}
	}
	return min;
}
float calculaPromedioInscriptos(notas vec[], int len) {
	float suma = 0;
	for (int i = 0; i < len; i++)
	{
		suma += vec[i].cantAlumnos;
	}
	return suma / len;
}
void agregar(producto arr[], int n, int& len, producto v) {
	if (len < n) {
		arr[len] = v;
		len++;
	}
	else {
		cout << "El vector esta lleno" << endl;
	}
}
int buscar(producto arr[], int len, int codigo) {
	int i = 0;
	int pos = -1;
	while (i < len && arr[i].codigo != codigo)
	{
		i++;
	}
	if (i < len)
		pos = i;
	return pos;
}
void mostrarProducto(producto arr[], int len) {
	for (int i = 0; i < len; i++)
	{
		cout << "Codigo: " << arr[i].codigo << endl;
		cout << "Nombre: " << arr[i].nombre << endl;
		cout << "Precio: " << arr[i].precio << endl;
		cout << "Stock: " << arr[i].stock << endl;
		cout << "---------------------------" << endl;
	}
}
int buscar(estudiante arr[], int len, string nombre) {
	int i = 0;
	int pos = -1;
	while (i<len && arr[i].nombre != nombre)
	{
		i++;
	}
	if (i < len) 
		pos = i;
	return pos;
	
}
float calcularPromedio(estudiante arr[], int len) {
	float suma = 0;
	int i = 0;
	while (i < len) {
		suma += arr[i].nota;
		i++;
	}
	return suma / len;
}