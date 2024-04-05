#include <iostream>
#include <iomanip>
#include "Materia.h"
using std::cin;
using std::cout;
using std::endl;
using std::left;
using std::right;
using std::setfill;
using std::setw;


int main()
{
    Materia m1(12349, "Programacion", 7, true, Materia::Etapa::BASICA);
    Materia m2(23456, "Estadistica Avanzada", 6, true, Materia::Etapa::BASICA);

    cout << setw(6) << "Clave ";
    cout << setw(50) << left << "Nombre ";
    cout << setw(8) << left << "Creditos ";
    cout << setw(4) << left <<"Tipo ";
    cout << "Etapa"<< endl;

    cout <<m1.ToString()<<endl;
    cout <<m2.ToString()<<endl;
}