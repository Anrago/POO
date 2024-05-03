#include <iostream>
#include "Estudiante.h"
#include "Profesionista.h"
using std::cin;
using std::cout;
using std::endl;

int main()
{
    Estudiante estudiante, estudiante2(5555, "Elizabeth", "Bioingeria", 5, 20);
    Persona La_Persona("N", 23);
    Profesionista profesor;
    La_Persona.Saludar();
    cout << endl;
    estudiante2.Saludar();
    cout << endl;
    profesor.Saludar();
    profesor.Trabajar();
    cout << endl;
    Persona *persona;
    persona = new Estudiante(777777, "George", "Ing.Civil");
    Persona &ref=profesor;
    persona->Saludar();
    ref.Saludar();


    return 0;
}
