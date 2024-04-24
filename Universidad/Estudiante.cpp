#include <sstream>
#include <iomanip>
#include "Estudiante.h"

using std::endl;
using std::left;
using std::right;
using std::setw;

Estudiante::Estudiante(int matricula = 0, string nombre = "", string carrera = "")
{
    this->matricula = matricula;
    this->nombre = nombre;
    this->carrera = carrera;
    kardex = Kardex(this);
}

string Estudiante::ToString() const
{
    std::ostringstream out;
    out << setw(8) << left << matricula << ' ';
    out << setw(50) << left << nombre << ' ';
    out << carrera;
    return out.str();
}
