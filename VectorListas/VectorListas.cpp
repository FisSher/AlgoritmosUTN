
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;


struct ventaAnual {
	int idMes;
	int idTicket;
	char descProducto[50];
	int cantVendida;
	float precioUnitario;
};
struct infoProducto {
	char descProducto[50];
	int cantVendida;
	float precioUnitario;
};

struct Producto {
	infoProducto info;
	Producto* sig;
};

struct infoTicket {
	int idTicket;
	Producto* productos;
};

struct Ticket {
	infoTicket info;
	Ticket* sig;
};



Ticket* buscarEInsertaTicket(Ticket*& lista, infoTicket v, bool& enc);
Ticket* buscarTicket(Ticket* lista, infoTicket v);
Ticket* agregarTicketOrdenado(Ticket*& lista, infoTicket x);
Producto* agregarProducto(Producto*& lista, infoProducto x);

int main() {

	Ticket* vecMes[12];

	for (int i = 0; i < 12; i++) {
		vecMes[i] = NULL;
	}

	FILE* venta = fopen("ventas2018.dat", "rb");
	ventaAnual reg;

	fread(&reg, sizeof(ventaAnual), 1, venta);

	infoTicket infoT;
	infoProducto infoP;
	Ticket* ticketBuscado;
	bool enc;

	while (!feof(venta)) {

		infoT.idTicket = reg.idTicket;
		infoT.productos = NULL;
		ticketBuscado = buscarEInsertaTicket(vecMes[reg.idMes - 1], infoT, enc);

		infoP.cantVendida = reg.cantVendida;
		infoP.precioUnitario = reg.precioUnitario;
		strcpy(infoP.descProducto, reg.descProducto);

		agregarProducto(ticketBuscado->info.productos, infoP);

		fread(&reg, sizeof(ventaAnual), 1, venta);
	}

	fclose(venta);

	Ticket* auxT;
	Producto* auxP;
	float montoTotalItem;
	float montoTotalTicket;
	float ticketMayorMontoPorMes;
	int idTicketMayorMontoPorMes;
	float ticketMenorMontoPorMes;
	int idTicketMenorMontoPorMes;
	float importePromedioPorMes;
	int cantTicketPorMes;
	float montoTotalTicketPorMes;

	float ticketMayorMontoPorAnio = 0;
	int idMesMayorMontoPorAnio = 0;
	float ticketMenorMontoPorAnio = 99999999999999;
	int idMesMenorMontoPorAnio = 0;
	int cantTicketPorAnio = 0;
	float montoTotalTicketPorAnio = 0;
	int maxCantidadTicket = 0;
	int idMesMaxCantidadTicket = 0;

	for (int i = 0; i < 12; i++) {
		cout << "Mes: " << i + 1 << endl;
		ticketMayorMontoPorMes = 0;
		idTicketMayorMontoPorMes = 0;
		ticketMenorMontoPorMes = 999999999999999;
		idTicketMenorMontoPorMes = 0;
		importePromedioPorMes = 0;
		cantTicketPorMes = 0;
		montoTotalTicketPorMes = 0;
		auxT = vecMes[i];
		while (auxT != NULL) {
			cout << "Ticket: " << auxT->info.idTicket << endl;
			auxP = auxT->info.productos;
			montoTotalTicket = 0;
			while (auxP != NULL) {
				montoTotalItem = auxP->info.cantVendida * auxP->info.precioUnitario;
				cout << auxP->info.descProducto << " " << auxP->info.cantVendida << " unidades  $" <<
					auxP->info.precioUnitario << " pu  $" << montoTotalItem << " total" << endl;
				montoTotalTicket += montoTotalItem;
				auxP = auxP->sig;
			}
			montoTotalTicketPorMes += montoTotalTicket;
			cantTicketPorMes++;
			montoTotalTicketPorAnio += montoTotalTicket;
			cantTicketPorAnio++;
			cout << "Monto Total del Ticket $" << montoTotalTicket << endl;
			if (montoTotalTicket > ticketMayorMontoPorMes) {
				ticketMayorMontoPorMes = montoTotalTicket;
				idTicketMayorMontoPorMes = auxT->info.idTicket;
			}
			if (montoTotalTicket < ticketMenorMontoPorMes) {
				ticketMenorMontoPorMes = montoTotalTicket;
				idTicketMenorMontoPorMes = auxT->info.idTicket;
			}

			if (montoTotalTicket > ticketMayorMontoPorAnio) {
				ticketMayorMontoPorAnio = montoTotalTicket;
				idMesMayorMontoPorAnio = i + 1;
			}
			if (montoTotalTicket < ticketMenorMontoPorAnio) {
				ticketMenorMontoPorAnio = montoTotalTicket;
				idMesMenorMontoPorAnio = i + 1;
			}

			auxT = auxT->sig;
		}

		if (cantTicketPorMes > maxCantidadTicket) {
			maxCantidadTicket = cantTicketPorMes;
			idMesMaxCantidadTicket = i + 1;
		}

		cout << "El ticket de mayor monto fue " << idTicketMayorMontoPorMes << " con $" << ticketMayorMontoPorMes << endl;
		cout << "El ticket de menor monto fue " << idTicketMenorMontoPorMes << " con $" << ticketMenorMontoPorMes << endl;
		cout << "El ticket promedio fue $" << montoTotalTicketPorMes / cantTicketPorMes << endl;

		cout << endl;
		cout << "--------------------------------------------------------------" << endl;
		cout << endl;
	}

	cout << "El ticket de mayor monto del anio fue en el mes " << idMesMayorMontoPorAnio << " con $" << ticketMayorMontoPorAnio << endl;
	cout << "El ticket de menor monto del anio fue en el mes " << idMesMenorMontoPorAnio << " con $" << ticketMenorMontoPorAnio << endl;
	cout << "El ticket promedio del anio fue $" << montoTotalTicketPorAnio / cantTicketPorAnio << endl;
	cout << "El mes con mas cantidad de tickets fue " << idMesMaxCantidadTicket << endl;
}

Producto* agregarProducto(Producto*& lista, infoProducto x) {
	Producto* nuevo = new Producto();
	nuevo->info = x;
	nuevo->sig = NULL;
	if (lista == NULL) { // la lista p esta vacía
		lista = nuevo;
	}
	else {
		Producto* aux = lista;
		while (aux->sig != NULL) {
			aux = aux->sig;
		}
		aux->sig = nuevo;
	}

	return nuevo;
}

Ticket* buscarEInsertaTicket(Ticket*& lista, infoTicket v, bool& enc) {
	Ticket* nodoBuscado = buscarTicket(lista, v);
	if (nodoBuscado != NULL) { // el nodo está en la lista
		enc = true;
	}
	else { // el nodo no está
		nodoBuscado = agregarTicketOrdenado(lista, v);
		enc = false;
	}

	return nodoBuscado;
}
Ticket* buscarTicket(Ticket* lista, infoTicket v) {
	Ticket* aux = lista;
	while (aux != NULL && aux->info.idTicket != v.idTicket) {
		aux = aux->sig;
	}
	return aux;
}
Ticket* agregarTicketOrdenado(Ticket*& lista, infoTicket x) {
	Ticket* nuevo = new Ticket();
	nuevo->info = x;
	nuevo->sig = NULL;
	Ticket* ant = NULL;
	Ticket* aux = lista;

	while (aux != NULL && aux->info.idTicket <= x.idTicket) {
		ant = aux;
		aux = aux->sig;
	}

	if (ant == NULL) { //Estoy insertando al principio
		lista = nuevo;
	}
	else {
		ant->sig = nuevo;
	}
	nuevo->sig = aux;

	return nuevo;
}
