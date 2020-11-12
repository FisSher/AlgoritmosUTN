#include <iostream>
#include <string.h>
#include <string>

using namespace std;

struct infoConver {
	int idConversacion;
	string nombre;
	bool vistaPrevia;
	bool notificar;
};

struct Conversacion {
	infoConver info;
	Conversacion* sig;
};

struct contacto {
	int idUsuario;
	string nombre;
	bool bloqueado;
};

void notificarMensajeRecibido(Conversacion* lista, contacto vec[], int len, int idConversacion, int idUsuarioEmisor, string mensaje);
int buscarContacto(contacto arr[], int len, int v);
Conversacion* buscarConversacion(Conversacion* p, int v);
string numeroTelefonicoUsuario(int idUsuarioEmisor);
string vistaPreviaConver(string mensaje);
void emitirNotificacion(string titulo, string descripcion);

int main()
{
	Conversacion* conversaciones = NULL;
	contacto vecContactos[200] = { {3462,"Pepito",false} ,{7893,"pirulo",true} };
	int len = 2;

	notificarMensajeRecibido(conversaciones, vecContactos, len, 8953, 3462, "Nos vemos a las 9");
}

void notificarMensajeRecibido(Conversacion* lista, contacto vec[], int len, int idConversacion, int idUsuarioEmisor, string mensaje) {
	Conversacion* converBuscada = buscarConversacion(lista, idConversacion);
	int posContactoBuscado = buscarContacto(vec, len, idUsuarioEmisor);
	bool bloqueado;
	string nombreContacto;
	bool vistaPrevia;

	if (posContactoBuscado != -1) {
		bloqueado = vec[posContactoBuscado].bloqueado;
		nombreContacto = vec[posContactoBuscado].nombre;
	}
	else {
		bloqueado = false;
		nombreContacto = numeroTelefonicoUsuario(idUsuarioEmisor);
	}

	string titulo;
	string descripcion;

	if (!bloqueado && converBuscada->info.notificar) { //Se puede notificar
		vistaPrevia = converBuscada->info.vistaPrevia;

		if (converBuscada->info.nombre != "") { //Conver grupal
			titulo = converBuscada->info.nombre;
			if (vistaPrevia) {
				descripcion = nombreContacto + " : " + vistaPreviaConver("a");
			}
			else {
				descripcion = "nuevo mensaje de: " + nombreContacto;
			}
		}
		else {//Conver directa
			titulo = nombreContacto;
			if (vistaPrevia) {//Directa sin vista previa
				descripcion = vistaPreviaConver("aasd");
			}
			else {
				descripcion = "Nuevo mensaje.";
			}
		}
	}

	emitirNotificacion(titulo, descripcion);
}

Conversacion* buscarConversacion(Conversacion* p, int v)
{
	Conversacion* aux = p;
	while (aux != NULL && aux->info.idConversacion != v)
	{
		aux = aux->sig;
	}
	return aux;
}

int buscarContacto(contacto arr[], int len, int v) {
	int i = 0;
	int pos = -1;
	while (i < len && arr[i].idUsuario != v) {
		i++;
	}
	if (i < len) {
		pos = i;
	}

	return pos;
}
string numeroTelefonicoUsuario(int idUsuarioEmisor) {
	return "154484621563";
}

string vistaPreviaConver(string mensaje) {
	return "Este es el mensaje de vista previa";
}

void emitirNotificacion(string titulo, string descripcion) {
	cout << "Titulo: " << titulo << endl;
	cout << "Descripcion: " << descripcion << endl;
}