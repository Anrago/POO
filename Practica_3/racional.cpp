// Antonio Ramos Gonzalez
// Mat: 372575
// Sobrecarga de operadores:
// 13/03/2024
#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <iostream>
#include <sstream>
#include "racional.h"

using std::cout;
using std::endl;
using std::string;

string EliminarEspacios(string frac)
{
    string temp;
    for (char i : frac)
    {
        if (i != ' ')
        {
            temp.push_back(i);
        }
    }
    return temp;
}

racional::racional()
{
    numerador = "6";
    denominador = "12";
    result = "1";
}

racional::racional(string frac)
{
    int numera;
    int denomi;
    char opera;

    frac = EliminarEspacios(frac);
    std::istringstream in(frac);

    in >> numera >> opera >> denomi;

    numerador = std::to_string(numera);
    denominador = std::to_string(denomi);
}

racional racional::operator+(racional frac)
{
    racional result;
    result.numerador = "(" + numerador + "*" + frac.denominador + "+" + denominador + "*" + frac.numerador + ")";
    result.denominador = denominador + "*" + frac.denominador;
    return result;
}

racional racional::operator-(racional frac)
{
    racional result;
    result.numerador = "(" + numerador + "*" + frac.denominador + "-" + denominador + "*" + frac.numerador + ")";
    result.denominador = denominador + "*" + frac.denominador;
    return result;
}

racional racional::operator*(racional frac)
{
    racional result;
    result.numerador = "(" + numerador + "*" + frac.numerador + ")";
    result.denominador = "(" + denominador + "*" + frac.denominador + ")";
    return result;
}

racional racional::operator/(racional frac)
{
    racional result;
    result.numerador = "(" + numerador + "*" + frac.denominador + ")";
    result.denominador = "(" + denominador + "*" + frac.numerador + ")";
    return result;
}

racional racional::operator=(racional frac)
{
    numerador = frac.numerador;
    denominador = frac.denominador;
    return *this;
}

racional racional::operator<<(racional frac)
{
    cout << frac.numerador << "/" << frac.denominador << endl;
    return *this;
}
