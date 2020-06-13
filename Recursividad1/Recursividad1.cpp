/*
Recursividad
Ejercicio 1: Factorial
• Ecuación de Recurrencia: n! = n * (n-1)!
• Caso base: 0! = 1

Ejercicio 2: Potencia
• Ecuación de Recurrencia: an = a (n-1) * a si n > 1
• Caso base: a0 = 1

Ejercicio 3: División Natural
• Ecuación de Recurrencia: dividendo / divisor = 1 + (dividendo-divisor) / divisor
• Caso base: divisor > dividendo = 0 y (dividendo = divisor) = 1

Ejercicio 4: Sucesión de Fibonacci
• Ecuación de Recurrencia: Fib(n) = Fib(n-1) + Fib(n-2)
• Caso base: Fib(0) = 1 y Fib(1) = 1 */


#include <iostream>

using namespace std;

int factorial(int numero);
int potencia(int base, int exp);
int fibonacci(int n);

int main()
{
	int n=0;
	int base=0;
	int exp=0;
	//cout << "Factorial de: ";
	//cout << "Factorial de: ";
	cin >> n;
	/*cout << "El factorial de " << n << " es " << factorial(n) << endl;
	cout << "------------" << endl;
	cout << "Potencia base:  ";
	cin >> base;
	cout << "Exponente: ";
	cin >> exp;*/
	cout << "La potencia es: " << potencia(base, exp) << endl;
	cout << "Fibonacci en " << n << " es " << fibonacci(n) << endl;
}
int factorial(int numero) {
	int resultado;
	if (numero == 0) {
		resultado = 1;
	}
	else {
		resultado = numero * factorial(numero - 1);
	}

	return resultado;
}
int potencia(int base, int exp) {
	int resultado;
	if (exp == 0) {
		resultado = 1;
	}
	else {
		resultado = base * potencia(base, exp - 1);
	}
	return resultado;
}
int fibonacci(int n) {
	if (n == 0 || n == 1)
		return n;
	else
		return fibonacci(n - 2) + fibonacci(n - 1);
	
}