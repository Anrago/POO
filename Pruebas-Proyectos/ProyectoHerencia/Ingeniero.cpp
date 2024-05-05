#include "Ingeniero.h"

Ingeniero::Ingeniero(string nombre, string cedula, int edad, int aniosExp)
    :Profesionista(nombre,cedula,edad,aniosExp)
{

}

void Ingeniero::ResolverProblemas()
{
    cout << "Resolviendo problemas con creatividad e ingenio..." << endl;
}

void Ingeniero::Trabajar()
{
    //Para invocar el metodo trabajar de la clase padre
    //Utilizamos el operador de resolucion de ambito
    Profesionista::Trabajar(); // Trabajar profesionista
    ResolverProblemas();

}
