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

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

struct pelicula {
    int idPeli;
    char nombrePeli[50];
    int cantEsp;
};

struct peliculaFinDeSemana {
    char nombrePeli[50];
    int cantEsp;
};

int main()
{
    /*FILE* cine = fopen("unicenter.dat", "wb+");
    pelicula reg;

    reg.idPeli = 1234;
    strcpy(reg.nombrePeli, "Toy Story");
    reg.cantEsp = 5000;
    fwrite(&reg,sizeof(pelicula),1,cine);

    reg.idPeli = 4567;
    strcpy(reg.nombrePeli, "Saw17");
    reg.cantEsp = 3500;
    fwrite(&reg, sizeof(pelicula), 1, cine);

    reg.idPeli = 9872;
    strcpy(reg.nombrePeli, "Rapidos y furiosos 67");
    reg.cantEsp = 11000;
    fwrite(&reg, sizeof(pelicula), 1, cine);

    reg.idPeli = 7890;
    strcpy(reg.nombrePeli, "Titanic");
    reg.cantEsp = 8750;
    fwrite(&reg, sizeof(pelicula), 1, cine);

    rewind(cine);

    fread(&reg,sizeof(pelicula),1,cine);

    while (!feof(cine))
    {
        cout << reg.idPeli << endl;
        cout << reg.nombrePeli << endl;
        cout << reg.cantEsp << endl;
        fread(&reg, sizeof(pelicula), 1, cine);
        cout << "_________________________" << endl;
    }
    fclose(cine);
    */

    pelicula vec[20] = {};



}

