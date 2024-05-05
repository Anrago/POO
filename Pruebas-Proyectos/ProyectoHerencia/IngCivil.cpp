#include "IngCivil.h"

IngCivil::IngCivil(string nombre, string cedula, int edad, int aniosExp)
    : Ingeniero(nombre,cedula,edad,aniosExp)
{
}

void IngCivil::Construir()
{
    cout << "Construyendo... meneando la cuchara con estilo" << endl;

}

void IngCivil::ResolverProblemas()
{
    Construir();
}
