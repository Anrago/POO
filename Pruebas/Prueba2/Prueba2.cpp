#include <iostream>
#include "Persona.h"
using std::cout;
using std::endl;

void usarPersona(Persona *Persona)
{
    cout << "----------Utilizando Persona-------------" << endl;
    Persona->saludar();
    Persona->hacerReir(rand());
    cout << "----------Persona Utilizada-------------" << endl;
}


int main()
{
    srand(time(0));
    Persona persona("Sempronio",20);
    Persona persona2("AMLO",15);
    Persona* persona3 = new Persona("SEPONSIO",23);

    persona.saludar();
    usarPersona(&persona2);
    usarPersona(persona3);

    cout << "bye" << endl;

    delete persona3;
}
