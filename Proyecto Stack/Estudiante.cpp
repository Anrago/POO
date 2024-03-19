#include "Estudiante.h"

ostream &operator<<(ostream &out, const Estudiante &e)
{
    out << "Estudiante [" << e.GetMatricula() << "," << e.GetNombre();
    out << "," << e.GetPuntuacion() << std::endl;
    return out;
}

Estudiante::Estudiante(int matricula, string nombre, int puntuacion)
{
    this->matricula = matricula;
    this->nombre = nombre;
    this->puntuacion = puntuacion;
}

bool operator<(const Estudiante &e1, const Estudiante &e2)
{
    //return e1.GetPuntuacion() < e2.GetPuntuacion();
    //return e1.GetNombre() < e2.GetNombre();
    return e1.GetMatricula() < e2.GetMatricula();
}

