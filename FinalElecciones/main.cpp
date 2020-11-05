#include <iostream>
#include <string.h>
using namespace std;

struct candidato {
	string nombre;
	int lista;
};

struct resultado {
	candidato cand;
	int pos;
};

void generarListaConsejerosDocentes(candidato vecCandidatos[], int lenCan, resultado vecResultado[], int& lenRes);
void ordenarVector(resultado vecAuxiliar[], int lenAux);

int votos1 = 50;
int votos2 = 35;
int votos3 = 15;

int main() {
	candidato vecCand[15] = {
{"1A",1},{"1B",1},{"1C",1},{"1D",1},{"1E",1},
{"2A",2},{"2B",2},{"2C",2},{"2D",2},{"2E",2},
{"3A",3},{"3B",3},{"3C",3},{"3D",3},{"3E",3},
	};
	int lenCand = 15;

	resultado vecRes[5];
	int lenRes = 0;

	generarListaConsejerosDocentes(vecCand, lenCand, vecRes, lenRes);

	for (int i = 0; i < lenRes; i++) {
		cout << "Posicion: " << vecRes[i].pos << endl;
		cout << "Lista: " << vecRes[i].cand.lista << endl;
		cout << "Nombre: " << vecRes[i].cand.nombre << endl;
		cout << "--------------------------------" << endl;
	}
}

void generarListaConsejerosDocentes(candidato vecCandidatos[], int lenCan, resultado vecResultado[], int& lenRes) {
	float votos[3] = { votos1, votos2, votos3 };
	float votosLista;
	int k = 0;

	resultado vecAuxiliar[15];
	int lenAux = 15;

	for (int i = 0; i < 3; i++) {
		votosLista = votos[i];
		for (int j = 0; j < 5; j++) {
			vecAuxiliar[k].cand = vecCandidatos[k];
			vecAuxiliar[k].pos = votosLista / (j + 1);
			k++;
		}
	}

	ordenarVector(vecAuxiliar, lenAux); // ordenar de mayor a menor

	for (int i = 0; i < 5; i++) {
		vecResultado[i].pos = i + 1;
		vecResultado[i].cand = vecAuxiliar[i].cand;
		lenRes++;
	}
}

void ordenarVector(resultado vecAuxiliar[], int lenAux) {
	resultado temp;
	bool huboIntercambio = true;

	for (int i = 0; i < lenAux && huboIntercambio; i++) {
		huboIntercambio = false;
		for (int j = 0; j < lenAux - 1; j++) {
			if (vecAuxiliar[j].pos < vecAuxiliar[j + 1].pos) {
				huboIntercambio = true;
				temp = vecAuxiliar[j + 1];
				vecAuxiliar[j + 1] = vecAuxiliar[j];
				vecAuxiliar[j] = temp;
			}
		}
	}
}