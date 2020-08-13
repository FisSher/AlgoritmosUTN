/*
#include <iostream>
using namespace std;

--------------------------------------------------
EJERCICIO 1
-------------------------------------------------
int main() 
{

#include <iostream>
    using namespace std;

    void insertarOrdenado(articulo arr[], int& len, articulo v);
    int buscar(articulo arr[], int len, articulo v);

    struct articulo {
        int codigo;
        char descripcion;
        int cantidadVendida;
        float precioUnitario;
    };

    int main()
    {
        FILE* suc1 = fopen("suc1.dat", "rb");
        FILE* suc2 = fopen("suc2.dat", "rb");
        articulo vec[100] = {};
        articulo reg1;
        articulo reg2;
        int len = 0;

        float totalSuc1 = 0;
        float totalSuc2 = 0;

        fread(&reg1, sizeof(articulo), 1, suc1);
        fread(&reg2, sizeof(articulo), 1, suc2);

        while (!feof(suc1))
        {
            vec[len] = reg1;
            len++;
            totalSuc1 += reg1.cantidadVendida * reg1.precioUnitario;
            fread(&reg1, sizeof(articulo), 1, suc1);
        }

        while (!feof(suc2))
        {
            totalSuc2 += reg2.cantidadVendida * reg2.precioUnitario;

            int pos = -1;
            bool enc = false;
            pos = buscar(vec, len, reg2.codigo);

            if (pos != -1)
            {
                vec[pos].cantidadVendida += reg2.cantidadVendida;
            }
            else
            {
                //Ordena de mayor a menor
                insertarOrdenado(vec, len, reg2.cantidadVendida);
            }

            fread(&reg2, sizeof(articulo), 1, suc2);
        }

        cout << "Los 3 articulos mas vendidos fueron: " << endl;

        for (int i = 0; i < len; i++)
        {
            cout << vec[i].descripcion << " con " << vec[i].cantidadVendida << " unidades vendidas " << endl;
        }

        if (totalSuc1 > totalSuc2)
            cout << "La sucursal 1 recaudo mas dinero" << endl;
        else
            cout << "La sucursal 2 recaudo mas dinero" << endl;

        fclose(suc1);
        fclose(suc2);
    }

}

--------------------------------------------------
EJERCICIO 3
-------------------------------------------------

int main() {
    void llenarVector(int vecA[], int vecB[], int lenA, int lenB, int vecC[], int lenC) {
        int i = 0;
        int j = 0;
        int pos = -1;
        while (vecA[i] < lenA)
        {
            if (lenC == 20) {
                cout << "El vector esta lleno" << endl;
            }
            else {
                vecC[lenC] = vecA[i];
                lenC++;
            }
        }

        while (vecB[j] < lenB)
        {
            pos = buscar(vecC, lenC, vecB[j]);
            if (pos != -1 && lenC < 20)
            {
                vecC[lenC] = vecB[j];
                lenC++;
            }
            else {
                cout << "El vector esta lleno" << endl;
            }
        }
    }

}



--------------------------------------------------
EJERCICIO 4
-------------------------------------------------

int main() {
#include <iostream>
    using namespace std;

    int diaSemana(int dia, int mes, int anio);

    int main()
    {
        int dia;
        int mes;
        int anio;
        int res = -1;
        cout << "Ingrese dia: ";
        cin >> dia;
        cout << "Ingrese mes: ";
        cin >> mes;
        cout << "Ingrese anio: ";
        cin >> anio;

        res = diaSemana(dia, mes, anio);

        switch (res)
        {
        case 0:
            cout << "El dia fue domingo" << endl;
            break;
        case 1:
            cout << "El dia fue lunes" << endl;
            break;
        case 2:
            cout << "El dia fue martes" << endl;
            break;
        case 3:
            cout << "El dia fue miercoles" << endl;
            break;
        case 4:
            cout << "El dia fue jueves" << endl;
            break;
        case 5:
            cout << "El dia fue viernes" << endl;
            break;
        case 6:
            cout << "El dia fue sabado" << endl;
            break;
        default:
            cout << "Error en el calculo" << endl;
            break;
        }
    }

    int diaSemana(int dia, int mes, int anio)
    {
        int vecRegular[12] = { 0,3,3,6,1,4,6,2,5,0,3,5 };
        int vecBisiesto[12] = { 0,3,4,0,2,5,0,3,6,1,4,6 };
        int x;
        int d;
        if (anio % 4 == 0 && anio % 100 != 0 || anio % 400 == 0)
        {
            x = vecBisiesto[mes - 1];
        }
        else
        {
            x = vecRegular[mes - 1];
        }

        d = ((anio - 1) % 7 + ((anio - 1) / 4 - (3 * (anio - 1) / 100 + 1) / 4) % 7 + x + dia % 7) % 7;

        return d;
    }
}

*/