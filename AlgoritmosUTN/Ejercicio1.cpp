/*Se ingresan 2 números, calcular la suma de ellos, la multiplicación y la resta.
Considerando que esta última operación tiene que dar >0. */
#include <iostream>;
using namespace std;

void restar(float a, float b);
void multiplicar(float a, float b);
void sumar(float a, float b);

int main() {

	float a;
	float b;
	cout << "Ingrese a: ";
	cin >> a;
	cout << "Ingrese b: ";
	cin >> b;
	restar(a, b);
	multiplicar(a, b);
	sumar(a,b);
}

void restar(float a, float b) {
	float resultado;
	resultado = a - b;
	if (resultado <= 0){
		cout << "El resultado es menor o igual a 0"<<endl;
	}
	else {
		cout << "El resultado de la resta es: ";
		cout << resultado << endl;
	}
}

void multiplicar(float a, float b)
{
	cout << "El resultado de la multiplicacion es: ";
	cout << a * b << endl;;
}

void sumar(float a, float b)
{
	cout << "El resultado de la suma es: ";
	cout << a + b << endl;
}
