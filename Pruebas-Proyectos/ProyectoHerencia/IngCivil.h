#include "Ingeniero.h"
class IngCivil  : public Ingeniero
{
private:
    /* data */
public:
    IngCivil(string nombre="WILIAM ", string cedula="De Tepito", int edad=25, int aniosExp=3);
    virtual void Construir();
    virtual void ResolverProblemas() override;
};
