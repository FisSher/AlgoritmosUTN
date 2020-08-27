#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
/*
--------------------------------------------------
EJERCICIO 1
-------------------------------------------------
*/

struct articulo {
	int codigo;
	char descripcion[50];
	int cantidadVendida;
	float precioUnitario;
};

struct alumno {
	int legajo;
	char materia[50];
	int curso;
	float nota;
};

struct aprobado {
	int legajo;
	char materia[50];
	int curso;
};

void burbuja(articulo a[], int& len) {
	articulo temp;
	int i, j;
	for (i = 0; i < len; i++) {
		for (j = i + 1; j < len; j++)
		{
			if (a[j].cantidadVendida < a[i].cantidadVendida) {
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}
void insertar(articulo arr[], int& len, articulo v, int pos) {
	for (int i = len - 1; i >= pos; i--)
	{
		arr[i + 1] = arr[i];
	}
	arr[pos] = v;
	len++;
}
void insertarOrdenado(articulo arr[], int& len, articulo v) {
	int i = 0;
	while (i < len && arr[i].cantidadVendida <= v.cantidadVendida)
	{
		i++;
	}
	insertar(arr, len, v, i);
}
int buscar(articulo arr[], int len, int v) {
	int i = 0;
	int pos = -1;
	while (i < len && arr[i].codigo != v) {
		i++;
	}
	if (i < len) {
		pos = i;
	}

	return pos;
}

int main()
{
	/*
	FILE* suc1 = fopen("suc1.dat", "wb+");
	FILE* suc2 = fopen("suc2.dat", "wb+");
	articulo reg;

	reg.codigo = 1;
	reg.cantidadVendida = 10;
	reg.precioUnitario = 5.12;
	strcpy(reg.descripcion, "Tuercas");
	fwrite(&reg, sizeof(articulo), 1, suc1);

	reg.codigo = 2;
	reg.cantidadVendida = 14;
	reg.precioUnitario = 20.3;
	strcpy(reg.descripcion, "Tornillos");
	fwrite(&reg, sizeof(articulo), 1, suc1);

	reg.codigo = 4;
	reg.cantidadVendida = 30;
	reg.precioUnitario = 120.45;
	strcpy(reg.descripcion, "Destornillador");
	fwrite(&reg, sizeof(articulo), 1, suc1);

	reg.codigo = 5;
	reg.cantidadVendida = 12;
	reg.precioUnitario = 244.12;
	strcpy(reg.descripcion, "Pinzas");
	fwrite(&reg, sizeof(articulo), 1, suc1);

	reg.codigo = 3;
	reg.cantidadVendida = 200;
	reg.precioUnitario = 500;
	strcpy(reg.descripcion, "Pinzas");
	fwrite(&reg, sizeof(articulo), 1, suc2);

	reg.codigo = 6;
	reg.cantidadVendida = 1;
	reg.precioUnitario = 10;
	strcpy(reg.descripcion, "Tijeras");
	fwrite(&reg, sizeof(articulo), 1, suc2);

	reg.codigo = 1;
	reg.cantidadVendida = 10;
	reg.precioUnitario = 5.12;
	strcpy(reg.descripcion, "Tuercas");
	fwrite(&reg, sizeof(articulo), 1, suc2);

	reg.codigo =0 ;
	reg.cantidadVendida = 110;
	reg.precioUnitario = 11;
	strcpy(reg.descripcion, "Cinta");
	fwrite(&reg, sizeof(articulo), 1, suc2);

	rewind(suc1);
	rewind(suc2);

	fread(&reg, sizeof(articulo), 1, suc1);
	while (!feof(suc1)) {
		cout << reg.codigo << endl;
		cout << reg.descripcion << endl;
		cout << reg.cantidadVendida << endl;
		cout << reg.precioUnitario << endl;

		fread(&reg, sizeof(articulo), 1, suc1);
	}

	fread(&reg, sizeof(articulo), 1, suc2);
	while (!feof(suc2)) {
		cout << reg.codigo << endl;
		cout << reg.descripcion << endl;
		cout << reg.cantidadVendida << endl;
		cout << reg.precioUnitario << endl;

		fread(&reg, sizeof(articulo), 1, suc2);
	}

	fclose(suc1);
	fclose(suc2);

	*/

	/*

	FILE* suc1 = fopen("suc1.dat", "rb");
	FILE* suc2 = fopen("suc2.dat", "rb");
	articulo vec[100] = {};
	articulo reg1;
	articulo reg2;
	int len = 0;

	float totalSuc1 = 0;
	float totalSuc2 = 0;

	fread(&reg1, sizeof(articulo), 1, suc1);

	while (!feof(suc1))
	{
		insertarOrdenado(vec, len, reg1);
		totalSuc1 += reg1.cantidadVendida * reg1.precioUnitario;
		fread(&reg1, sizeof(articulo), 1, suc1);
	}

	fread(&reg2, sizeof(articulo), 1, suc2);
	while (!feof(suc2))
	{
		totalSuc2 += reg2.cantidadVendida * reg2.precioUnitario;

		int pos = -1;
		bool enc = false;
		pos = buscar(vec, len, reg2.codigo);

		if (pos != -1)
		{
			vec[pos].cantidadVendida += reg2.cantidadVendida;
		}
		else
		{
			insertarOrdenado(vec, len, reg2);
		}

		fread(&reg2, sizeof(articulo), 1, suc2);
	}

	burbuja(vec, len);
	cout << "Los 3 articulos mas vendidos fueron: " << endl;

	for (int i = len-1; i >len-4; i--)
	{
		cout << vec[i].descripcion << " con " << vec[i].cantidadVendida << " unidades vendidas " << endl;
	}
	cout << "___________________________" << endl;
	if (totalSuc1 > totalSuc2)
		cout << "La sucursal 1 recaudo mas dinero" << endl;
	else
		cout << "La sucursal 2 recaudo mas dinero" << endl;

	fclose(suc1);
	fclose(suc2);
}  //<------------------------------ Acá hay una llave, ojo

*/

/*--------------------------------------------------
EJERCICIO 2
------------------------------------------------ -
*/

/*
FILE* notas = fopen("notas.dat", "wb+");

alumno vec[15] = { { 1233,"Discreta",444, 8 },
					{ 1233,"Algoritmos",4256, 6.5 },
					{ 1233,"AM1",4234, 7 },
					{ 1233,"Algebra",2454, 7.5 },
					{ 1233,"Ingles",5524, 9 },
					{ 456,"Discreta",423, 5 },
					{ 456,"Algoritmos",436, 4.5 },
					{ 456,"AM1",8564, 7 },
					{ 456,"Algebra",4564, 8.5 },
					{ 456,"Ingles",8876, 6 },
					{ 321,"Discreta",466, 6 },
					{ 321,"Algoritmos",746, 5 },
					{ 321,"AM1",8564, 7 },
					{ 321,"Algebra",4564, 7 },
					{ 321,"Ingles",8876, 9 },
};
int len = 15;
alumno reg;

for (int i = 0; i < len; i++)
{
	reg.curso = vec[i].curso;
	reg.legajo = vec[i].legajo;
	reg.nota = vec[i].nota;
	strcpy(reg.materia, vec[i].materia);
	fwrite(&reg, sizeof(alumno), 1, notas);
}

rewind(notas);
fclose(notas);
*/

	FILE* notas = fopen("notas.dat", "rb");
	FILE* aprobados = fopen("aprobados.dat", "wb+");
	alumno reg;
	aprobado regAprob;

	int legajoAnterior = 0;
	float mejorPromedio = 0;
	float peorNota = 90;

	fread(&reg, sizeof(alumno), 1, notas);
	while (!feof(notas))
	{
		float promedioAlumno = 0;
		legajoAnterior = reg.legajo;
		float sumaNotas = 0;
		int cantidadNotas = 0;

		while (!feof(notas) && reg.legajo == legajoAnterior)
		{
			sumaNotas += reg.nota;
			cantidadNotas++;
			promedioAlumno = sumaNotas / cantidadNotas;
			
			if (reg.nota < peorNota) {
				peorNota = reg.nota;
			}

			if (reg.nota > 6) {
				regAprob.curso = reg.curso;
				regAprob.legajo = reg.legajo;
				strcpy(regAprob.materia, reg.materia);
				fwrite(&regAprob, sizeof(aprobado), 1, aprobados);
			}

			fread(&reg, sizeof(alumno), 1, notas);
		}
		if (promedioAlumno > mejorPromedio) {
			mejorPromedio = promedioAlumno;
		}

		cout << "El promedio del alumno " << legajoAnterior << " es " << promedioAlumno<<endl;
	}
	cout << "El mejor promedio fue " << mejorPromedio << endl;
	cout << "La peor nota fue " << peorNota << endl;

	fclose(notas);
	rewind(aprobados);

	fread(&regAprob, sizeof(aprobado), 1, aprobados);
	while (!feof(aprobados))
	{
		cout << regAprob.legajo << endl;
		cout << regAprob.curso << endl;
		cout << regAprob.materia << endl;
		cout << "____________________________" << endl;

		fread(&regAprob, sizeof(aprobado), 1, aprobados);
	}
	fclose(aprobados);
}

/*
--------------------------------------------------
EJERCICIO 3
-------------------------------------------------

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
void agregar(int arr[], int n, int& len, int v) {
	if (len < n) {
		arr[len] = v;
		len++;
	}
	else {
		cout << "El vector esta lleno" << endl;
	}
}

void llenarVector(int vecA[], int vecB[], int lenA, int lenB, int vecC[], int& lenC) {
	int i = 0;
	int j = 0;
	int pos = -1;
	while (i < lenA) {
		agregar(vecC, 20, lenC, vecA[i]);
		i++;
	}
	while (j < lenB)
	{
		pos = buscar(vecC, lenC, vecB[j]);
		if (pos == -1) {
			agregar(vecC, 20, lenC, vecB[j]);
		}
		else {
			cout << "El valor " << vecB[j] << " ya esta en el vector c" << endl;
		}
		j++;
	}
}

int main() {
	int vecA[10] = { 5,4,6,8,7 };
	int vecB[10] = { 1,3,2,8 };
	int vecC[20] = {};
	int lenA = 5;
	int lenB = 4;
	int lenC = 0;
	int n = 20;
	llenarVector(vecA, vecB, lenA, lenB, vecC, lenC);
	mostrar(vecC, lenC);
}
*/

/*
--------------------------------------------------
EJERCICIO 4
-------------------------------------------------

int main() {
#include <iostream>
	using namespace std;

	int diaSemana(int dia, int mes, int anio);

	int main()
	{
		int dia;
		int mes;
		int anio;
		int res = -1;
		cout << "Ingrese dia: ";
		cin >> dia;
		cout << "Ingrese mes: ";
		cin >> mes;
		cout << "Ingrese anio: ";
		cin >> anio;

		res = diaSemana(dia, mes, anio);

		switch (res)
		{
		case 0:
			cout << "El dia fue domingo" << endl;
			break;
		case 1:
			cout << "El dia fue lunes" << endl;
			break;
		case 2:
			cout << "El dia fue martes" << endl;
			break;
		case 3:
			cout << "El dia fue miercoles" << endl;
			break;
		case 4:
			cout << "El dia fue jueves" << endl;
			break;
		case 5:
			cout << "El dia fue viernes" << endl;
			break;
		case 6:
			cout << "El dia fue sabado" << endl;
			break;
		default:
			cout << "Error en el calculo" << endl;
			break;
		}
	}

	int diaSemana(int dia, int mes, int anio)
	{
		int vecRegular[12] = { 0,3,3,6,1,4,6,2,5,0,3,5 };
		int vecBisiesto[12] = { 0,3,4,0,2,5,0,3,6,1,4,6 };
		int x;
		int d;
		if (anio % 4 == 0 && anio % 100 != 0 || anio % 400 == 0)
		{
			x = vecBisiesto[mes - 1];
		}
		else
		{
			x = vecRegular[mes - 1];
		}

		d = ((anio - 1) % 7 + ((anio - 1) / 4 - (3 * (anio - 1) / 100 + 1) / 4) % 7 + x + dia % 7) % 7;

		return d;
	}
}

*/