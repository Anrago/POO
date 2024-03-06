#include <string.h>
#include <iostream>
#include "racional.h"

using std::cout;
using std::endl;

racional::racional(int num, int deno)
{
    numerador = num;
    denominador = deno;
}

racional::racional(char cad[])
{
    char cadNom[10];
    char cadDeno[10];
    int band = 0;

    for (int i = 0; i < strlen(cad); i++)
    {
        if (isdigit(cad[i]))
        {
            strcat(cad, cadNom);
        }

        else
            band = 1;

        if (band = 1)
        {
            strcat(cad, cadDeno);
        }
    }
    numerador = atof(cadNom);
    denominador = atof(cadDeno);
    cout << cadNom << endl;
    cout << cadDeno << endl;
    cout << "Numerador: " << numerador << endl;
    cout << "Denominador: " << denominador << endl;
}
