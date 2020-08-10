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

struct artStock {
    articulo art;
    char deposito[20];
};

int main()
{
    FILE* dep1 = fopen("deposito1.dat", "rb");
    FILE* dep2 = fopen("deposito2.dat", "rb");
    FILE* stock = fopen("stock.dat", "wb+"); //Lo quiero leer despues a ver como quedo.
    articulo reg1;
    articulo reg2;
    artStock regStock;

    fread(&reg1, sizeof(articulo), 1, dep1);
    fread(&reg2, sizeof(articulo), 1, dep2);

    while (!feof(dep1)&&!feof(dep2))
    {
        //2 formas
        if (reg1.nroArt<reg2.nroArt)
        {
            regStock.art.cantidad = reg1.cantidad;
            regStock.art.nroArt = reg1.nroArt;
            strcpy(regStock.art.descripcion, reg1.descripcion);
            strcpy(regStock.deposito, "Deposito1");
            fwrite(&regStock, sizeof(regStock), 1, stock);
            fread(&reg1, sizeof(articulo), 1, dep1);
        }
        else
        {
            regStock.art = reg2;
            strcpy(regStock.deposito, "Deposito2");
            fwrite(&regStock, sizeof(artStock), 1, stock);
            fread(&reg2, sizeof(articulo), 1, dep2);
        }

    }

    while (!feof(dep1))
    {
        regStock.art = reg1;
        strcpy(regStock.deposito, "Deposito1");
        fwrite(&regStock, sizeof(artStock), 1, stock);
        fread(&reg1, sizeof(articulo), 1, dep1);
    }

    while (!feof(dep2))
    {
        regStock.art = reg2;
        strcpy(regStock.deposito, "Deposito2");
        fwrite(&regStock, sizeof(artStock), 1, stock);
        fread(&reg2, sizeof(articulo), 1, dep2);
    }


    fclose(dep1);
    fclose(dep2);

    rewind(stock);

    fread(&regStock, sizeof(artStock), 1, stock);
    while (!feof(stock))
    {
        cout << regStock.art.nroArt << endl;
        cout << regStock.art.descripcion << endl;
        cout << regStock.art.cantidad << endl;
        cout << regStock.deposito << endl;
        cout << "----------------------------" << endl;
        fread(&regStock, sizeof(artStock), 1, stock);
    }






    fclose(stock);
}

