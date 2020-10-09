/*
Se tiene un archivo �ingresos.dat� que contiene datos de los ingresos a los gimnasios de la
cadena �Fitness� para el mes de septiembre. En el archivo se encuentran: nro. de socio, nro. de
sucursal y estad�a (en minutos).
Con estos datos llenar una lista que debe contener nro. de sucursal, cantidad de personas
distintas que la visitaron en el mes y la cantidad total de visitas. A su vez cada nodo de esa lista
va a poseer una sublista con los socios que la visitaron, junto con su estad�a total y cantidad de
veces que visitaron la sucursal en el mes.
Informar cu�l fue el socio que m�s estad�a tuvo en una misma sucursal e imprimir el siguiente
listado:
Septiembre
Nro. de Sucursal: XXXX Cantidad de Visitas: XXXXXX Cantidad de Personas Distintas: XXXXXX
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;


struct ingreso {
	int nroSocio;
	int nroSucursal;
	int estadia;
};

struct infoSocio {
	int nroSocio;
	int cantVisitas;
	int estadiaTotal;
};

struct Socio {
	infoSocio info;
	Socio* sig;
};

struct infoSuc {
	int nroSucusal;
	int cantPersonasDistintas;
	int cantVisitas;
	Socio* listaSocios;
};

struct Sucursal {
	infoSuc info;
	Sucursal* sig;
};


int main()
{
  



}

