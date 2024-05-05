#include "Ingeniero.h"

class IngSoftware : public Ingeniero
{
private:
    /* data */
public:
    IngSoftware(string nombre="VICTOR", string cedula="De reddit", int edad=25, int aniosExp=3);
    virtual void Programar();
    virtual void ResolverProblemas();
};
