/*Ejercicio Nro. 5: Se ingresa un conjunto de valores reales, cada uno de los cuales representan el sueldo de un empleado,
excepto el último valor que será 0 para indicar el fin del ingreso de datos. Se pide desarrollar un programa que determine e informe:
• Cuántos empleados ganan menos $2000. • Cuántos ganan $2000 o más pero menos de $3000. 
• Cuántos ganan $3000 o más pero menos de $5000.
• Cuántos ganan $5000 o más.
*/

#include <iostream>
using namespace std;
int main()
{
    float sueldo;
    int menosDe2000 = 0;
    int entre2000yMenosDe3000 = 0;
    int entre3000yMenosDe5000 = 0;
    int masDe5000 = 0;

    cout << "Ingrese el sueldo: ";
    cin >> sueldo;

    while (sueldo !=0)
    {
        if (sueldo < 2000) {
            menosDe2000++;
        }
        else if (sueldo < 3000) {
            entre2000yMenosDe3000++;
        }
        else if (sueldo < 5000) {
            entre3000yMenosDe5000++;
        }
        else
        {
            masDe5000++;
        }
        cout << "Ingrese el sueldo: ";
        cin >> sueldo;
    }
    cout << "La cantidad de empleados que ganan menos de 2000: " << menosDe2000;
    cout << "La cantidad que gana entre 2000 y 3000: " << entre2000yMenosDe3000;
    cout << "La cantidad que gana entre 3000 y 5000: " << entre3000yMenosDe5000;
    cout << "La cantidad que gana mas de 5000: " << masDe5000;

}


