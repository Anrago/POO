// Antonio Ramos Gonzalez
// Mat: 372575
// Sobrecarga de operadores:
// 13/03/2024

#define _CRT_SECURE_NO_WARNINGS
#include "racional.h"
#include <ostream>
#include <string>
#include <sstream>
#include <iostream>

using std::cout;
using std::endl;
using std::string;

string EliminarEspacios(string frac);

int main()
{
    string cad = "8 / 9";
    string fracccion = "2 / 7";
    racional frac1 = fracccion;
    string ret;
    int numera, denomina;
    char operador;
    for (char c : cad)
    {
        if (c != ' ')
            ret.push_back(c);
    }
    cad = ret;
    std::istringstream in(cad);

    in >> numera >> operador >> denomina;
    racional frac2 = cad;
    racional frac3 = frac1 << frac2;
    cout << frac3.numerador << "/" << frac3.denominador << endl;

    return 0;
}
