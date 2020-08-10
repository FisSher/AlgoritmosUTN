/*
Ejercicio 1:
Se tienen dos archivos “deposito1.dat” y “deposito2.dat” con los siguientes datos: nroArt
(numérico), descripción (50 caracteres) y cantidad (numérico). Estos archivos se encuentran
ordenados por nroArt y los artículos no se repiten entre depósitos (cada depósito maneja sus
artículos). Generar un archivo “stock.dat”, consolidando los artículos de ambos depósitos

Ejercicio 2:
Generar un archivo “stock.dat”, consolidando los artículos de ambos depósitos y colocando en
cuál depósito se encuentra cada artículo.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>

using namespace std;

struct articulo {
    int nroArt;
    char descripcion[50];
    int cantidad;
};

struct articuloDeposito {
    articulo art;
    char deposito[25];

};

int main()
{
    //Genero archivos aca
    /*
    FILE* dep1 = fopen("deposito1.dat", "wb+");
    

    articulo reg;

    reg.nroArt = 1236;
    strcpy(reg.descripcion, "martillo");
    reg.cantidad = 100;

    fwrite(&reg, sizeof(articulo), 1, dep1);

    reg.nroArt = 6789;
    strcpy(reg.descripcion, "tornillo");
    reg.cantidad = 200;

    fwrite(&reg, sizeof(articulo), 1, dep1);
    cout << "____________Archivo 1_________________" << endl;
    rewind(dep1);

    fread(&reg, sizeof(articulo), 1, dep1);
    while (!feof(dep1)) {
        cout << "Nro art: " << reg.nroArt << endl;
        cout << "Descripcion: " << reg.descripcion << endl;
        cout << "Cantidad: " << reg.cantidad << endl;
        cout << "_____________________________" << endl;

        fread(&reg, sizeof(articulo), 1, dep1);
    }
    fclose(dep1);

    FILE* dep2 = fopen("deposito2.dat", "wb+");

    reg.nroArt = 1100;
    strcpy(reg.descripcion, "pinza");
    reg.cantidad = 18;

    fwrite(&reg, sizeof(articulo), 1, dep2);

    reg.nroArt = 7900;
    strcpy(reg.descripcion, "pegamento");
    reg.cantidad = 500;

    fwrite(&reg, sizeof(articulo), 1, dep2);


    cout << "____________Archivo 2_________________" << endl;
    rewind(dep2);

    fread(&reg, sizeof(articulo), 1, dep2);
    while (!feof(dep2)) {
        cout << "Nro art: " << reg.nroArt << endl;
        cout << "Descripcion: " << reg.descripcion << endl;
        cout << "Cantidad: " << reg.cantidad << endl;
        cout << "_____________________________" << endl;

        fread(&reg, sizeof(articulo), 1, dep2);
    }
    fclose(dep2);
    */

    FILE* dep1 = fopen("deposito1.dat", "rb");
    FILE* dep2 = fopen("deposito2.dat", "rb");
    FILE* stock = fopen("stock.dat", "wb+");
    articulo reg1;
    articulo reg2;
    articuloDeposito regArtDeposito;

    fread(&reg1, sizeof(articulo), 1, dep1);
    fread(&reg2, sizeof(articulo), 1, dep2);

    while (!feof(dep1) && !feof(dep2)) {
        if (reg1.nroArt < reg2.nroArt) {
            regArtDeposito.art = reg1;
            strcpy(regArtDeposito.deposito, "Dep 1");
            fwrite(&regArtDeposito, sizeof(articuloDeposito), 1, stock);
            fread(&reg1, sizeof(articulo), 1, dep1);
        }
        else {
            regArtDeposito.art = reg2;
            strcpy(regArtDeposito.deposito, "Dep 2");
            fwrite(&regArtDeposito, sizeof(articuloDeposito), 1, stock);
            fread(&reg2, sizeof(articulo), 1, dep2);
        }

        
        
    }

    while (!feof(dep1))
    {
        regArtDeposito.art = reg1;
        strcpy(regArtDeposito.deposito, "Dep 1");
        fwrite(&regArtDeposito, sizeof(articuloDeposito), 1, stock);
        fread(&reg1, sizeof(articulo), 1, dep1);

    }

    while (!feof(dep2))
    {
        strcpy(regArtDeposito.deposito, "Dep 2");
        fwrite(&regArtDeposito, sizeof(articuloDeposito), 1, stock);
        fread(&reg2, sizeof(articulo), 1, dep2);
    }
    fclose(dep1);
    fclose(dep2);
    rewind(stock);

    articuloDeposito regStock;
    fread(&regStock, sizeof(articuloDeposito), 1, stock);
    while (!feof(stock)) {
        cout << "Nro art: " << regStock.art.nroArt << endl;
        cout << "Descripcion: " << regStock.art.descripcion << endl;
        cout << "Cantidad: " << regStock.art.cantidad << endl;
        cout << "Deposito: " << regStock.deposito<< endl;
        cout << "_____________________________" << endl;
     fread(&regStock, sizeof(articuloDeposito), 1, stock);
    }
    fclose(stock);

}

