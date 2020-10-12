/*
Se tiene un archivo “ingresos.dat” que contiene datos de los ingresos a los gimnasios de la
cadena “Fitness” para el mes de septiembre. En el archivo se encuentran: nro. de socio, nro. de
sucursal y estadía (en minutos).
Con estos datos llenar una lista que debe contener nro. de sucursal, cantidad de personas
distintas que la visitaron en el mes y la cantidad total de visitas. A su vez cada nodo de esa lista
va a poseer una sublista con los socios que la visitaron, junto con su estadía total y cantidad de
veces que visitaron la sucursal en el mes.
Informar cuál fue el socio que más estadía tuvo en una misma sucursal e imprimir el siguiente
listado:
Septiembre
Nro. de Sucursal: XXXX Cantidad de Visitas: XXXXXX Cantidad de Personas Distintas: XXXXXX
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "funciones.hpp"
using namespace std;

struct ingreso {
	int id;
	int nroSucursal;
	int estadia;
};

struct infoSocio {
	int id;
	int cantVisitas;
	int estadiaTotal;
};

struct Socio {
	infoSocio info;
	Socio* sig;
};

struct infoSuc {
	int id;
	int cantPersonasDistintas;
	int cantVisitas;
	Socio* listaSocios;
};

struct Sucursal {
	infoSuc info;
	Sucursal* sig;
};

/*
Sucursal* buscaEInsertaSucursal(Sucursal*& p, infoSuc v, bool& enc);
Sucursal* buscarSucursal(Sucursal* p, infoSuc v);
Sucursal* agregarSucursal(Sucursal*& p, infoSuc x);

Socio* buscaEInsertaSocio(Socio*& p, infoSocio  v, bool& enc);
Socio* buscarSocio(Socio* p, infoSocio v);
Socio* agregarSocio(Socio*& p, infoSocio x);
*/

int main()
{
	FILE* archIngreso = fopen("ingreso.dat", "rb");
	ingreso reg;
	Sucursal* listaSucursales = NULL;
	Sucursal* sucursalBuscada;
	Socio* socioBuscado;
	bool encSuc;
	bool encSoc;
	infoSuc infoS;
	infoSocio infoSoc;

	fread(&reg, sizeof(ingreso), 1, archIngreso);
	while (!feof(archIngreso)) {
		infoS.id = reg.nroSucursal;
		infoS.cantPersonasDistintas = 0;
		infoS.cantVisitas = 0;
		infoS.listaSocios = NULL;

		sucursalBuscada = buscaEInserta(listaSucursales, infoS, encSuc);

		infoSoc.id = reg.id;
		infoSoc.cantVisitas = 1;
		infoSoc.estadiaTotal = reg.estadia;

		socioBuscado = buscaEInserta(sucursalBuscada->info.listaSocios, infoSoc, encSoc);

		if (encSoc) {
			socioBuscado->info.cantVisitas++;
			socioBuscado->info.estadiaTotal += reg.estadia;
		}
		else {
			sucursalBuscada->info.cantPersonasDistintas++;
		}

		sucursalBuscada->info.cantVisitas++;

		fread(&reg, sizeof(ingreso), 1, archIngreso);
	}

	fclose(archIngreso);

	Sucursal* auxSuc = listaSucursales;
	int maxEstadia = 0;
	int maxSocio = 0;
	int maxSucursal = 0;

	cout << "Septiembre" << endl;
	while (auxSuc != NULL) {
		cout << "Nro de Suc: " << auxSuc->info.id << " - " << "Cantidad de Visitas: " <<
			auxSuc->info.cantVisitas << " - " << "Cantidad de Personas Distintas: " << auxSuc->info.cantPersonasDistintas << endl;

		Socio* auxSoc = auxSuc->info.listaSocios;
		while (auxSoc != NULL) {
			if (auxSoc->info.estadiaTotal > maxEstadia) {
				maxEstadia = auxSoc->info.estadiaTotal;
				maxSocio = auxSoc->info.id;
				maxSucursal = auxSuc->info.id;
			}
			auxSoc = auxSoc->sig;
		}

		auxSuc = auxSuc->sig;
	}

	cout << "El socio de mas estadia en septiembre fue: " << maxSocio << " con " <<
		maxEstadia << " minutos, en la sucursal " << maxSucursal << endl;
}
/*
Socio* buscarSocio(Socio* p, infoSocio v) {
	Socio* aux = p;
	while (aux != NULL && aux->info.id != v.id) {
		aux = aux->sig;
	}
	return aux;
}

Socio* agregarSocio(Socio*& p, infoSocio x) {
	Socio* nuevo = new Socio();
	nuevo->info = x;
	nuevo->sig = NULL;
	if (p == NULL) { // la lista p esta vacía
		p = nuevo;
	}
	else {
		Socio* aux = p;
		while (aux->sig != NULL) {
			aux = aux->sig;
		}
		aux->sig = nuevo;
	}

	return nuevo;
}

Socio* buscaEInsertaSocio(Socio*& p, infoSocio v, bool& enc) {
	Socio* nodoBuscado = buscarSocio(p, v);
	if (nodoBuscado != NULL) { // el nodo está en la lista
		enc = true;
	}
	else { // el nodo no está
		nodoBuscado = agregarSocio(p, v);
		enc = false;
	}

	return nodoBuscado;
}

Sucursal* buscarSucursal(Sucursal* p, infoSuc v) {
	Sucursal* aux = p;
	while (aux != NULL && aux->info.id != v.id) {
		aux = aux->sig;
	}
	return aux;
}

Sucursal* agregarSucursal(Sucursal*& p, infoSuc x) {
	Sucursal* nuevo = new Sucursal();
	nuevo->info = x;
	nuevo->sig = NULL;
	if (p == NULL) { // la lista p esta vacía
		p = nuevo;
	}
	else {
		Sucursal* aux = p;
		while (aux->sig != NULL) {
			aux = aux->sig;
		}
		aux->sig = nuevo;
	}

	return nuevo;
}

Sucursal* buscaEInsertaSucursal(Sucursal*& p, infoSuc v, bool& enc) {
	Sucursal* nodoBuscado = buscarSucursal(p, v);
	if (nodoBuscado != NULL) { // el nodo está en la lista
		enc = true;
	}
	else { // el nodo no está
		nodoBuscado = agregarSucursal(p, v);
		enc = false;
	}

	return nodoBuscado;
}*/