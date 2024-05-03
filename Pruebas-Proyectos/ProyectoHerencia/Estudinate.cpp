#include <iostream>
#include "Estudiante.h"

using std::cout;
using std::endl;

Estudiante::Estudiante()
{
    nombre = "Esteban";
    edad = 18;
    carrera = "Ing. Computacion";
    matricula = 000000;
}

Estudiante::Estudiante(int matricula, string nombre, string carrera, int semestre, int edad):
    Persona(nombre.c_str(),edad)
{
    //Inicializamos los atributos extras
    this->matricula=matricula;
    this->carrera=carrera;
    this->semestre=semestre;

}

void Estudiante::Estudiar()
{
    cout << "Estudiando duro, y viendo a don pollo" << endl;
}

void Estudiante::Saludar() const
{
    cout<<"Hola, soy "<< nombre <<", estudio " << carrera << " en ";
    cout<<semestre << " semestre, y me gusta don pollo."<< endl; 
}
