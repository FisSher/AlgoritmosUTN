/*Ejercicio 1  
 
Prototipo del procedimiento:  void agregar(int arr[], int n, int& len, int v);  
 
Entrada:  
arr: vector donde voy a agregar un elemento.  
n: cantidad m�xima de elementos que puede tener el vector.  
len: cantidad de elementos ocupados en el vector.  
v: valor a agregar en el vector.  
 
Salida:  Ninguna.  
 
En qu� consiste el algoritmo:  El procedimiento agrega el valor v al final del array arr e incrementa su longitud len.  
 */

/*Ejercicio 2

Prototipo del procedimiento : void mostrar(int arr[], int len);

Entrada:  arr: el vector del que tengo que mostrar todos sus elementos.len : cantidad de elementos ocupados en el vector.

Salida : Ninguna.

En qu� consiste el algoritmo : Recorre el vector arr mostrando por consola el valor de cada uno de sus elementos.*/

/*Ejercicio 3  
 
Prototipo de la funci�n:  int buscar(int arr[], int len, int v);  
 
Entrada:  arr: vector donde voy a buscar un elemento.  
len: cantidad de elementos ocupados en el vector.  
v: valor a buscar en el vector.  
 
Salida:  Posici�n de v o -1 si no se encuentra en el vector.  
 
En qu� consiste el algoritmo: Permite determinar si el array arr contiene o no al elemento v; retorna la posici�n que v ocupa dentro de arr o -1 si arr no contiene a v.  
 */

/*Ejercicio 4  
 
Prototipo del procedimiento:  void eliminar(int arr[], int& len, int pos);  
Entrada:  arr: vector donde voy a eliminar un elemento.  
len: cantidad de elementos ocupados en el vector.  
pos: posici�n donde se encuentra el valor a eliminar.  
 
Salida:  Ninguna.  
 
En qu� consiste el algoritmo:  Elimina el valor que se encuentra en la posici�n pos del array arr, desplazando al i�simo elemento hacia la posici�n i-1, para todo valor de i>pos y i<len.  
 */

/*Ejercicio 5  
 
Prototipo del procedimiento:  void insertar(int arr[], int& len, int v, int pos);  
 
Entrada:  arr: vector donde voy a insertar un elemento.  len: cantidad de elementos ocupados en el vector.  v: valor a insertar.  pos: posici�n donde se va insertar el valor.  
 
Salida:  Ninguna.  
 
En qu� consiste el algoritmo:  Inserta el valor v en la posici�n pos del array arr, desplazando al i-�simo elemento hacia la posici�n i+1, para todo valor de i que verifique: i>=pos e i<len.  
 */

/*Ejercicio 6  
 
Prototipo de la funci�n:  int insertarOrdenado(int arr[], int& len, int v);  
 
Entrada:  arr: vector donde voy a insertar el elemento.  len: cantidad de elementos ocupados en el vector.  v: valor a insertar. 
 
Salida:  Posici�n donde se insert� el valor.  
 
En qu� consiste el algoritmo:  Inserta el valor v en el array arr, en la posici�n que corresponda seg�n el criterio de precedencia de los n�meros enteros. El array debe estar ordenado o vac�o.  
 */

/*Ejercicio 7  
 
Prototipo de la funci�n:  int buscaEInserta(int arr[], int& len, int v, bool& enc);  
 
Entrada:  arr: vector donde voy a insertar el elemento.  len: cantidad de elementos ocupados en el vector. 
v: valor a insertar.  enc: me indica si el valor se encontr� en el vector.  
 
Salida:  Posici�n donde est� o se insert� el valor.  
 
En qu� consiste el algoritmo:  Busca el valor v en el array arr; si lo encuentra entonces asigna true a enc y
retorna la posici�n que v ocupa dentro de arr. De lo contrario asigna false a enc, 
inserta a v en arr respetando el orden de los n�meros enteros y retorna la posici�n en la que finalmente v qued� ubicado.
*/

#include <iostream>
#include "vectores.hpp";
using namespace std;

int main()
{
    int n = 3;
    int vec[3];
    int len = 0;
    int m = 6;
    int vec2[6];
    int len2 = 0;
    inicializar(vec, n);
    inicializar(vec2, m);
    cout << "-------------------" << endl;
    cout << "Agrego" << endl;
    cout << "-------------------" << endl;
    agregar(vec, n, len, 1);
    agregar(vec, n, len, 2);
    agregar(vec, n, len, 3);



    cout << "-------------------" << endl;
    cout << "Mostrar" << endl;
    cout << "-------------------" << endl;
    mostrar(vec, 3);


    cout << "-------------------" << endl;
    cout << "Buscar" << endl;
    cout << "-------------------" << endl;
    int valor=buscar(vec, 3, 25);
    if (valor != -1) {
        cout << "Se encontro en la posicion: " << valor << endl;
    }
    else {
        cout << "No se encontro" << endl;
    }

    cout << "-------------------" << endl;
    cout << "Eliminar y mostrar de nuevo" << endl;
    cout << "-------------------" << endl;
    eliminar(vec,len, 1);
    mostrar(vec, len);

    cout << "-------------------" << endl;
    cout << "Insertar" << endl;
    cout << "-------------------" << endl;
    insertar(vec, len, 44, 2);
    mostrar(vec, len);

    cout << "-------------------" << endl;
    cout << "Insertar ordenado" << endl;
    cout << "-------------------" << endl;
    agregar(vec2, m, len2, 5);
    agregar(vec2, m, len2, 15);
    agregar(vec2, m, len2, 30);
    agregar(vec2, m, len2, 45);
    insertarOrdenado(vec2, len2, 25);
    mostrar(vec2, len2);

    cout << "-------------------" << endl;
    cout << "Busca e inserta" << endl;
    cout << "-------------------" << endl;

    bool encontrado;
    int pos=buscaEInserta(vec2, len2, 30, encontrado);
    if (encontrado) {
        cout << "Ya estaba en la posicion [" << pos << "]" << endl;
    }
    else {
        cout << "No estaba y se agrego en la posicion [" << pos << "]" << endl;
    }

}



