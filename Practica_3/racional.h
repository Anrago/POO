// Antonio Ramos Gonzalez
// Mat: 372575
// Sobrecarga de operadores:
// 13/03/2024
#pragma once
#include <iostream>
#include <ostream>
#include <string>

using std::ostream;
using std::string;

class racional
{
public:
    string numerador;
    string denominador;
    string result;

    racional();
    racional(string frac);

    racional operator+(racional frac);
    racional operator-(racional frac);
    racional operator*(racional frac);
    racional operator/(racional frac);
    racional operator=(racional frac);
    racional operator<<(racional frac);
};
