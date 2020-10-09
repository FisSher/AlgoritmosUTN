
#include <iostream>
using namespace std;



struct Nota {
	int nota;
	Nota* sig;
};
struct infoestudiante {
	int id;
	Nota* notas[4];
};
struct Estudiante {
	infoestudiante infoEst;
	Estudiante* sigEst;
};
struct infocurso {
	int id;
	int promocionados;
	int regularizados;
	int recursantes;
	Estudiante* listaEstudiantes;
};
struct Curso {
	infocurso infoCur;
	Curso* sigCur;
};

struct novedad {
	int idCurso;
	int idEstudiante;
	int nroEvaluacion;
	int nota;
};


void ProcesarNovedades(FILE* novedades, Curso*& listaCursos);
void AgregarNota(Curso*& listaCursos, int idCurso, int idEstudiante, int nroEvaluacion, int nota);
Curso* buscaEInsertaCurso(Curso*& p, infocurso v, bool& enc);
void CalcularEstadísiticas(cursos);
int GetEstado();
Curso* agregarNodo(Curso*& p, infocurso x);
Curso* buscar(Curso* p, infocurso v);


int main()
{
	Curso* listaCursos = NULL;

	FILE* novedades = fopen("novedades.dat","rb");

	ProcesarNovedades(novedades,listaCursos);
}

void ProcesarNovedades(FILE* novedades, Curso*& listaCursos) {
	novedad reg;
	fread(&reg, sizeof(novedad), 1, novedades);

	while (!feof (novedades))
	{
		AgregarNota(listaCursos,reg.idCurso,reg.idEstudiante,reg.nroEvaluacion,reg.nota);

		fread(&reg, sizeof(novedad), 1, novedades);
	}


}

void AgregarNota(Curso*&listaCursos, int idCurso, int idEstudiante, int nroEvaluacion, int nota) {
	bool enc;

	infocurso datos;
	datos.id = idCurso;
	datos.listaEstudiantes = 0;
	datos.promocionados = 0;
	datos.recursantes = 0;
	datos.regularizados = 0;
	datos.listaEstudiantes = NULL;

	Curso* cursoDeInteres = buscaEInsertaCurso(listaCursos, datos, enc);


}
void CalcularEstadísiticas(cursos) {

}

int GetEstado() {

}

Curso* buscaEInsertaCurso(Curso*& p, infocurso v, bool& enc) {
	Curso* nodoBuscado = buscar(p, v);
	if (nodoBuscado != NULL)
	{
		enc = true;
	}
	else {
		nodoBuscado = agregarNodo(p, v);
		enc = false;
	}
	return nodoBuscado;

}
Estudiante* buscaEInsertaEstudiante(Estudiante*& p, infocurso v, bool& enc) {
	Curso* nodoBuscado = buscar(p, v);
	if (nodoBuscado != NULL)
	{
		enc = true;
	}
	else {
		nodoBuscado = agregarNodo(p, v);
		enc = false;
	}
	return nodoBuscado;

}

Curso* agregarNodo(Curso*& p, infocurso x)
{
	Curso* nuevo = new Curso();
	nuevo->infoCur = x;
	nuevo->sigCur = NULL;
	if (p == NULL) //La lista p esta vacia
	{
		p = nuevo;
	}
	else
	{
		Curso* aux = p;
		while (aux->sigCur != NULL)
		{
			aux = aux->sigCur;
		}
		aux->sigCur = nuevo;
	}

	return nuevo;
}
Curso* buscar(Curso* p, infocurso v)
{
	Curso* aux = p;
	while (aux != NULL && aux->infoCur.id != v.id)
	{
		aux = aux->sigCur;
	}
	return aux;
}