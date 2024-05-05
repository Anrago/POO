#include <iostream>
#include "Estudiante.h"
#include "IngSoftware.h"
#include "IngCivil.h"
using std::cin;
using std::cout;
using std::endl;

void UsarProfesionista(Profesionista *prof);
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
    Persona &ref = profesor;
    persona->Saludar();
    ref.Saludar();




    IngSoftware is;
    IngCivil ic;
    UsarProfesionista(&is);
    UsarProfesionista(&ic);

    return 0;
}

void UsarProfesionista(Profesionista *prof)
{
    cout << "Usando profesionista (" << prof->GetNombre() << ")" << endl;
    prof->Saludar();
    prof->Trabajar();
    cout << "----------------------------------------------------" << endl;
}
