#include <iostream>
#include <iomanip>
#include "Universidad.h"
using std::cin;
using std::cout;
using std::endl;
using std::left;
using std::right;
using std::setfill;
using std::setw;


int main()
{
    Universidad uni;
    uni.RegistrarEstudainte("Jose Martinez", "Tronco comun");
    uni.RegistrarEstudainte("Daniela Lara", "Tronco comun");
    uni.RegistrarEstudainte("Elizabet perez", "Ing. computacion");
    uni.ReporteEstudiante();

    uni.RegistrarMateria("Algebra superior",7);
    uni.RegistrarMateria("COE",5);
    uni.RegistrarMateria("ATE",7);
    uni.RegistrarMateria("POO",8);
}