#include "Persona.h"
using std::string;
class Estudiante: public Persona
{
protected:
    int matricula;
    int semestre= 1;
    string carrera;
public:
    Estudiante(/* args */);
    Estudiante(int matricula, string nombre,
    string carrera = "Ing. Computacion",int semestre=1, int edad= 18);

    void Estudiar();
    //En una clase derivada se puede redefinir la forma como se hacen
    //Algunos metodos. El metodo se vuelve a declarar e implementa.
    //El nuevo metodo sustituira al metodo heredado. A esta accion se le llama
    //sobrescritura

    void Saludar() const override;
};


