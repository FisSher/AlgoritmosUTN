// OrdenamientoBurbuja.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string.h>

using namespace std;

void burbuja(int vec[], int len);



int main()
{
    int vector[10] = { 6,8,1,3,9,7,2,34,15,18 };
    int len = 10;
    burbuja(vector, len);

    for (int i = 0; i < len; i++) {
        cout << vector[i] << endl;
    }


    return 0;
}
void burbuja(int vec[], int len) {
    int temp = 0;
    for (int i = 0; i < len;i++) {
        for (int j = 0; j < len-1; j++)
        {
            if (vec[j]>vec[j+1])
            {
                temp = vec[j+1];
                vec[j+1] = vec[j];
                vec[j] = temp;
            }
        }

    }
}