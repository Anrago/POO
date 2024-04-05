#include <iostream>
#include "Opcion.h"


Opcion::Opcion(char tecla, string desc, function<void(void)> a)
{
    this->tecla=tecla;
    this->descripcion=desc;
    this->accion=a;
}

void Opcion::Desplegar()const
{
    std::cout <<tecla<<") "<<descripcion<<std::endl;
}
