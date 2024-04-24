#include <iostream>
#include <string>
#include "Estudiante.h"
#include "Materia.h"
#include <map>
using std::map;
using std::string;

class Universidad
{
private:
    string Nombre;
    map<int,Estudiante*> Estudiantes;
    map<int,Materia*> Materias;
    int ContrMat=333000;//Variable Controladora de matriculas
    int ControlClaveMat=40000;//Variable para claves de materias
public:
    Universidad(string nombre="WABECE"){Nombre=nombre;};
    ~Universidad();
    string GetNombre ()const {return Nombre;};
    Estudiante *RegistrarEstudainte(string nombre, string carrera);
    Materia *RegistrarMateria(string nombre,int creditos, bool obligatoria=true,Materia::Etapa etapa = Materia::BASICA);
    void RegistrarCalificacion(int matricula, int clave, int valor);
    void ReporteEstudiante()const;
    void ReporteMaterias()const;
    Kardex GetKardex(int main);
};
