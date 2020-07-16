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
    int lenPeli = 0;

    FILE* uniArch = fopen("unicenter.dat", "rb");
    FILE* dotArch = fopen("dot.dat", "rb");
    FILE* findeArch = fopen("finDeSemana.dat", "wb+");

    pelicula reg;


    fread(&reg, sizeof(pelicula), 1, uniArch);
    fread(&reg, sizeof(pelicula), 1, dotArch);
    while (!feof(uniArch))
    {
        vec[lenPeli] = reg;
        lenPeli++;


        
        fread(&reg, sizeof(pelicula), 1, uniArch);
    }

    while (!feof(dotArch))
    {
        vec[lenPeli] = reg;
        lenPeli++;
        int pos = -1;
        pos = busquedasecuencial(vec, lenPeli, reg.idPeli);
        
        if (pos == -1) {
            vec[lenPeli] = reg;
            lenPeli++;
        }
        else {
            vec[pos].cantEsp += reg.cantEsp;
        }

        fread(&reg, sizeof(pelicula), 1, dotArch);
    }
        burbuja(vec, lenPeli);

   /* for (int i = 0; i < lenPeli; i++) {
        cout << vec[lenPeli].idPeli << endl;
        cout << vec[lenPeli].nombrePeli << endl;
        cout << vec[lenPeli].cantEsp << endl;
    }*/

    cout << "La pelicula menos vista fue " << vec[0].nombrePeli << " con " << vec[0].cantEsp << " espectadores." << endl;
    cout << "Las 3 peliculas mas vistas fueron " << endl;
    for (int i = lenPeli - 1; i > lenPeli-4; i--) {
        cout << "-" << vec[i].nombrePeli << " con " << vec[i].cantEsp << endl;
    }
    //FIN PUNTO 1 AHORA VIENE EL ARCHIVO

    peliculaFinDeSemana regFDS;

    for (int i = lenPeli - 1; i >= 0; i--) {
        strcpy(regFDS.nombrePeli, vec[i].nombrePeli);
        regFDS.cantEsp = vec[i].cantEsp;
        fwrite(&regFDS, sizeof(peliculaFinDeSemana), 1, findeArch);
    }

    rewind(findeArch);

    fread(&regFDS, sizeof(peliculaFinDeSemana), 1, findeArch);
    while (!feof(findeArch)) {
        cout << regFDS.nombrePeli << endl;
        cout << regFDS.cantEsp<< endl;
        cout << "________________________" << endl;
        fread(&regFDS, sizeof(peliculaFinDeSemana), 1, findeArch);

    }


    fclose(uniArch);
    fclose(dotArch);
    fclose(findeArch);

}

