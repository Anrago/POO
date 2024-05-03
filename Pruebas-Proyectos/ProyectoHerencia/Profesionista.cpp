#include "Profesionista.h"

Profesionista::Profesionista() : Persona("Nicolas", 25), cedula("De Tepito"), aniosExp(3)
{
    // cedula="De Te pito";
    // aniosExp=3;
}

Profesionista::Profesionista(string nombre, string cedula, int edad, int aniosExp) : Persona(nombre.c_str(), edad)
{
    this->cedula = cedula;
    this->aniosExp = aniosExp;
}

void Profesionista::Trabajar()
{
    cout << "Mi primera chamba ..." << endl;
}

void Profesionista::Saludar() const
{
    cout << "Hola, soy el profesionista " << nombre << ", tengo " << aniosExp << " anios de esperiencia";
    cout << " y mi cedula es " << cedula << endl;
}
