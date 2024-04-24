#include "Materia.h"
#include <sstream>
#include <iomanip>

using std::left;
using std::right;
using std::setfill;
using std::setw;

Materia::Materia(int clave, string nombre, int creditos, bool obligatoria, Etapa etapa)
{
    this->clave = clave;
    this->nombre = nombre;
    this->creditos = creditos;
    this->obligatoria = obligatoria;
    this->etapa = etapa;
}

string Materia::ToString() const
{
    std::ostringstream out;

    out << setw(6) << clave << " ";
    out << setw(50) << left << nombre << " ";
    out << setw(8) << left << creditos << " ";
    out << setw(4) << left;

    if (obligatoria)
        out << "Obl ";
    else
        out << "Opt ";
    switch (etapa)
    {
    case BASICA:out << "Basica"; break;
    case DISCIPLINARIA:out << "Diciplinaria";break;
    case TERMINAL:out << "Terminal";break;
    }

    return out.str();
}