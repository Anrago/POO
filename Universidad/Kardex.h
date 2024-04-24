#pragma once
#include <vector>
#include "Estudiante.h"
#include "Calificacion.h"

using std::vector;
class Estudiante;
class Kardex
{
protected:
    double promedio=0;
    int creditos=0;
    vector<Calificacion> calificaciones;
    Estudiante* estudiante;
public:
    Kardex(Estudiante* est=nullptr){estudiante=est;};
    double GetPromedio()const {return promedio;};
    int GetCreditos()const{return creditos;};

    void RegistrarCalificacion(Calificacion cal);

    string ToString()const;

};

