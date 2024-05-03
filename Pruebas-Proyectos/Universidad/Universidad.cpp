#include "Universidad.h"
#include <iostream>
#include <iomanip>

using std::cout;
using std::endl;
using std::left;
using std::right;
using std::setw;

Universidad::~Universidad()
{
    //Eliminamos a lo estudiantes que se habian creado
    for(auto pe:Estudiantes)
        delete pe.second;
    for(auto pm:Materias)
        delete pm.second;
}

Estudiante *Universidad::RegistrarEstudainte(string nombre, string carrera)
{
    Estudiante *new_est = new Estudiante(++ContrMat, nombre, carrera);
    // Registramos al estudiante en el mapa de los estudiantes

    Estudiantes[ContrMat] = new_est;
    return new_est;
}

Materia *Universidad::RegistrarMateria(string nombre, int creditos, bool obligatoria, Materia::Etapa etapa)
{
    Materia *New_Mat = new Materia(++ControlClaveMat, nombre, creditos, obligatoria, etapa);
    // Registramos la materia en el mapa de materias
    Materias.insert({ControlClaveMat, New_Mat});
    return New_Mat;
}

void Universidad::RegistrarCalificacion(int matricula, int clave, int valor)
{
    // Primero buscamos al estudiante
    auto iter = Estudiantes.find(matricula);
    // Verificar si el estudiante existe
    if (iter == Estudiantes.end())
        throw "Estudiante no existente";
    // Despues buscamos la materia

    auto item = Materias.find(clave);

    if (item == Materias.end())
        throw "Materia no encontrada";

    (*iter).second->GetKardex().RegistrarCalificacion({valor, (*item).second});
}

void Universidad::ReporteEstudiante() const
{
    cout << "------------------------------------------------------------------" << endl;
    cout << "Matricula" << setw(50) << left << "Nombre";
    cout << " Carrera" << endl;
    cout << "------------------------------------------------------------------" << endl;
    // imprimimos todos los estudiantes

    for (auto pe : Estudiantes)
        cout << pe.second->ToString() << endl;
    cout << "------------------------------------------------------------------" << endl;
}

void Universidad::ReporteMaterias() const
{
    cout << "------------------------------------------------------------------" << endl;
    cout << "Clave  " << setw(50) << left << "Nombre";
    cout << " Creditos Tipo Etapa" << endl;
    cout << "------------------------------------------------------------------" << endl;
    // imprimimos todos los estudiantes

    for (auto pm : Materias)
        cout << pm.second->ToString() << endl;
    cout << "------------------------------------------------------------------" << endl;
}

Kardex Universidad::GetKardex(int main)
{
    
    return Kardex();
}
