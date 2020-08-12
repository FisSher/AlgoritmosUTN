/*
Se tienen dos archivos, “unicenter.dat” y “dot.dat”, que contienen los datos de las películas
vistas el último fin de semana. Los datos que contienen ambos archivos son: identificador de
película, nombre y número de espectadores. Puede haber alguna película que no se proyecte
en ambos cines.
- Informar las 3 películas más vistas y la película menos vista del fin de semana.
- Guardar en el archivo “finDeSemana.dat” (nombre de la película y cantidad de
espectadores) todas las películas vistas el fin de semana, ordenadas de forma
descendente por cantidad de espectadores

20 peliculas = vec[20]

*/

//Sin esto el visual me dice que tenga cuidado y no me deja compilar.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//Me pide para leer
struct pelicula {
    int idPeli;
    char nombre[50];
    int cantEsp;
};

//Me pide que guarde solo esto.
struct pelifinde {
    char nombre[50];
    int cantEsp;
};

//Funciones
void burbuja(pelicula vec[],int len);
int busquedaSecuencial(pelicula vec[], int len, int valor);



int main()
{

    //Voy a leer y ordenar.
    pelicula vec[20] = {};
    int len = 0;
    FILE* dot = fopen("dot.dat", "rb");
    FILE* uni = fopen("unicenter.dat", "rb");
    pelicula reg;

    //Completo uno
    fread(&reg, sizeof(pelicula), 1, dot);
    while (!feof(dot))
    {
        vec[len] = reg;
        len++;

        fread(&reg, sizeof(pelicula), 1, dot);
    }
    
    //Comparo y completo el otro
    fread(&reg, sizeof(pelicula), 1, uni);
    while (!feof(uni))
    {
        int pos = -1;
        pos = busquedaSecuencial(vec, len, reg.idPeli);

        if (pos == -1) {
            vec[len] = reg;
            len++;
        }
        else 
        {
            vec[pos].cantEsp += reg.cantEsp;
        }
        fread(&reg, sizeof(pelicula), 1, uni);
    }
    
    //ordeno
    burbuja(vec, len);

    cout << "Las tres peliculas mas vistas son: " << endl;
    for (int i = len-1; i>len-4 ; i--) {  //el -1 es mi 0 entonces para contar hasta 3 tengo que contar hasta -4
        cout << vec[i].nombre << " con " << vec[i].cantEsp << " espectadores." << endl; //Me tira un warning de size pero no uso todo.
    }

    //Cierro los archivos
    fclose(dot);
    fclose(uni);
    cout << "______________________________________________" << endl;
    //Aca voy a crear el archivo nuevo

    FILE* finde = fopen("finDeSemana.dat", "wb+"); //quizás intente leerlo
    pelifinde regFinde;

    //Ya lo tengo en el vector puedo aprovechar a leerlo para sacar los datos

    for (int i = len-1; i >= 0; i--)
    {
        strcpy(regFinde.nombre, vec[i].nombre);
        regFinde.cantEsp = vec[i].cantEsp;
        fwrite(&regFinde, sizeof(pelifinde), 1, finde);
    }

    //Voy a leer el archivo a ver como quedo
    rewind(finde);

    fread(&regFinde, sizeof(pelifinde), 1, finde);
    while (!feof(finde))
    {
        cout << regFinde.nombre << " espectadores: " << regFinde.cantEsp << endl;

        fread(&regFinde, sizeof(pelifinde), 1, finde);
    }

    
    
    
    fclose(finde);

}

//Sacado de un ejercicio, no lo hice de 0
void burbuja(pelicula vec[], int len) {
    pelicula temp;
    bool huboIntercambio = true;

    for (int i = 0; i < len && huboIntercambio; i++) {

        huboIntercambio = false;
        for (int j = 0; j < len - 1; j++) {
            if (vec[j].cantEsp > vec[j + 1].cantEsp) {
                huboIntercambio = true;
                temp = vec[j + 1];
                vec[j + 1] = vec[j];
                vec[j] = temp;
            }
        }

    }

} 
//Sacado de un ejercicio, tampoco lo hice de 0, pero funciona.
int busquedaSecuencial(pelicula vec[], int len, int valorBuscado) {
    int pos = -1;

    int i = 0;
    while (i < len && vec[i].idPeli != valorBuscado) {
        i++;
    }

    if (vec[i].idPeli == valorBuscado) {
        pos = i;
    }

    return pos;
}