#include "Profesionista.h"
class Ingeniero : public Profesionista
{
public:
    Ingeniero(string nombre="WILIAM ", string cedula="De Tepito", int edad=25, int aniosExp=3);
    virtual void ResolverProblemas();
    virtual void Trabajar() override;
};

