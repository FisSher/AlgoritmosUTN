#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "funciones.hpp"
using namespace std;

//EJSublistas1
/*
Se tiene un archivo “ventas.dat” que contiene los siguientes datos:
número de cliente, artículo comprado, cantidad comprada y precio
unitario.

Con estos datos llenar una lista que debe contener número de cliente y dinero gastado.
A su vez cada nodo de esa lista va a poseer una sublista de los artículos comprados, junto
con su cantidad comprada y precio unitario.
Nota: El precio unitario para cada artículo no varía.

Si el artículo se repite por cada cliente debe incrementarse su cantidad vendida.

Luego, mostrar un listado con la siguiente estructura:
Número de Cliente:
$ dineroGastado por el cliente
Detalle:
 Artículo-> cantidadDeUnidades-> precioUnitario-> total
 Total de Dinero Recaudado: $dineroGastadoPorTodosLosClientes
 */
/*
struct Ventas {
    int nroCliente;
    char id[50]; //articulo comprado
    int cant;
    float precioUnitario;
};

struct infoArt {
    char id[50];
    int cantidad;
    float precioUnitario;

};

struct Articulo {
    infoArt info;
    Articulo* sig;

};

struct infoCliente {
    int id;
    float dineroGastado;
    Articulo* articulosComprado;

};

struct Cliente {
    infoCliente info;
    Cliente* sig;
};


int main()
{
    FILE* ventas = fopen("ventas.dat", "rb");
    Ventas regVenta;
    infoCliente infoC;
    infoArt infoA;
    Cliente* clienteBuscado;
    Articulo* articuloBuscado;
    bool enc;


    Cliente* listaClientes = NULL;

    fread(&regVenta,sizeof(Ventas),1,ventas);
    while (!feof(ventas))
    {
        infoC.id = regVenta.nroCliente;
        infoC.dineroGastado = 0;
        infoC.articulosComprado = NULL;
        clienteBuscado = buscaEInserta(listaClientes, infoC, enc);

        strcpy(infoA.id, regVenta.id);
        infoA.cantidad = regVenta.cant;
        infoA.precioUnitario = regVenta.precioUnitario;
        articuloBuscado = buscaEInserta(clienteBuscado->info.articulosComprado,infoA,enc);

        if (enc) {
            articuloBuscado->info.cantidad += regVenta.cant;
        }

        clienteBuscado->info.dineroGastado = regVenta.precioUnitario * regVenta.cant;

        fread(&regVenta, sizeof(Ventas), 1, ventas);
    }

    fclose(ventas);

    float totalGastadoPorTodoCliente = 0;

    Cliente* listaAuxCliente = listaClientes;

    while (listaAuxCliente!=NULL)
    {
        cout << "El cliente " << listaAuxCliente->info.id << " gasto: " << listaAuxCliente->info.dineroGastado << " pesos " << endl;
        cout << "Detalle: " << endl;
        cout << "==================" << endl;
        Articulo* articuloAux = listaAuxCliente->info.articulosComprado;
        while (articuloAux!=NULL)
        {
            cout << "Articulo: " << articuloAux->info.id << " Cantidad: " << articuloAux->info.cantidad << " Precio unitario: " << articuloAux->info.precioUnitario << endl;
            cout << "Total: " << articuloAux->info.cantidad * articuloAux->info.precioUnitario << "$" << endl;
            cout << "-------------------------------------------------------------------" << endl;
            articuloAux = articuloAux->sig;
        }

        totalGastadoPorTodoCliente += listaAuxCliente->info.dineroGastado;
        listaAuxCliente = listaAuxCliente->sig;
    }
    cout << "Total gastado por todos los clientes: " << totalGastadoPorTodoCliente << "$" << endl;
}
*/
//EjSublistas2
/*
Se tiene un archivo “ingresos.dat” que contiene datos de los ingresos a los gimnasios de la
cadena “Fitness” para el mes de septiembre. 

En el archivo se encuentran: nro. de socio, nro. de sucursal y estadía (en minutos).

Con estos datos llenar una lista que debe contener nro. de sucursal, cantidad de personas
distintas que la visitaron en el mes y la cantidad total de visitas. 

A su vez cada nodo de esa lista va a poseer una sublista con los socios que la visitaron,
junto con su estadía total y cantidad de veces que visitaron la sucursal en el mes.

Informar cuál fue el socio que más estadía tuvo en una misma sucursal e imprimir el siguiente listado:
Septiembre
Nro. de Sucursal: XXXX Cantidad de Visitas: XXXXXX Cantidad de Personas Distintas: XXXXXX
*/

/*
struct DatosSocio {
    int id;
    int nroSucursal;
    int estadia;
};

struct infoSocio {
    int id;
    int estadia;
    int visitas;
};

struct Socio {
    Socio* sig;
    infoSocio info;
};

struct infoSucursal {
    int id;
    int cantPersonas;
    int cantVisitas;
    Socio* socios;
};

struct Sucursal {
    Sucursal* sig;
    infoSucursal info;
};


int main() {

    FILE* ingresosArch = fopen("ingreso.dat", "rb");
    DatosSocio regArch;
    infoSucursal regSucursal;
    infoSocio regInfoSocio;
    Sucursal* listaSucursal = NULL;
    bool encSuc;
    bool encSoc;
    Sucursal* sucursalBuscada;
    Socio* socioBuscado;

    fread(&regArch, sizeof(DatosSocio), 1, ingresosArch);
    while (!feof(ingresosArch))
    {
        regSucursal.id = regArch.nroSucursal;
        regSucursal.cantPersonas = 0;
        regSucursal.socios = NULL;
        regSucursal.cantVisitas = 0;
        sucursalBuscada=buscaEInserta(listaSucursal, regSucursal, encSuc);

        regInfoSocio.id = regArch.id;
        regInfoSocio.estadia = regArch.estadia;
        regInfoSocio.visitas = 1;
        socioBuscado=buscaEInserta(sucursalBuscada->info.socios, regInfoSocio, encSoc);

        if (encSoc) {
            socioBuscado->info.visitas++;
            socioBuscado->info.estadia += regArch.estadia;
        
        }
        else {
            sucursalBuscada->info.cantPersonas++;

        }

        sucursalBuscada->info.cantVisitas++;

        fread(&regArch, sizeof(DatosSocio), 1, ingresosArch);
    }
    fclose(ingresosArch);


    Sucursal* listaAux = listaSucursal;
    int tiempoMaximo = 0;
    int socioTiempoMaximo = 0;
    int sucursalTiempoMaximo = 0;

    while (listaAux!=NULL)
    {
        cout << "Sucursal: " << listaAux->info.id << " visitas: " << listaAux->info.cantVisitas << " cant personas distintas: " << listaAux->info.cantPersonas << endl;
        Socio* auxSocio = listaSucursal->info.socios;
        
        while (auxSocio!=NULL)
        {
            if(auxSocio->info.estadia > tiempoMaximo) {
                tiempoMaximo = auxSocio->info.estadia;
                socioTiempoMaximo = auxSocio->info.id;
                sucursalTiempoMaximo = listaAux->info.id;
            }


            auxSocio = auxSocio->sig;
        }
        listaAux = listaAux->sig;
    }
    cout << "El que estuvo mayor tiempo en la sucursal " << sucursalTiempoMaximo << 
        " fue el socio " << socioTiempoMaximo << " con " << tiempoMaximo << " minutos." << endl;
}


*/