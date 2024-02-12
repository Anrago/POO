#include <iostream>
#include "Persona.h"

using std::cout;
using std::cin;
using std::endl;

void Persona::Reir()
{
    cout << "jajaja" << endl;
}

void Persona::Comer()
{
    cout << "Nom,nom,nom,nom" << endl;
}

void Persona::Saludar()
{
    cout << "Hola, soy" << nombre;
    cout << "y tengo "<< edad << "anios"  << endl;
}

void Persona::HacerReir(int motivo)
{
    if ((motivo%3)==0)
    {
        Reir();
    }
    else
    {
        cout << ":|" << endl;
    }
}
