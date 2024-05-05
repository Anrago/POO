#include <string>
#include <iostream>
#include "Persona.h"
using std::cout;
using std::cin;
using std::endl;
using std::string;

class Profesionista:public Persona
{
protected:
    string cedula;
    int aniosExp;

public:
    Profesionista();
    Profesionista(string nombre, string cedula="De Tepito", int edad=25, int aniosExp=3);
    virtual void Trabajar();
    //Sobreescritura de saludar

    //El calidicador ocerrude surve para marcar metodos que
    //sobreescriben a un metodo heredado. Si no hay un metodo
    //heredado con el mismo prototipo el compilador marca error
    void Saludar() const override;

};

