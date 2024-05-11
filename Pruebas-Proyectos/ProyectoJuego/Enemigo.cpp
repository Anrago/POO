#include "Enemigo.h"

Enemigo::Enemigo(float vida, float defensa, float danio, int nivel, float rango, float velocidad)
{
    this->vida = vida;
    this->defensa = defensa;
    this->danio = danio;
    this->nivel = nivel;
    this->rango = rango;
    this->velocidad = velocidad;
}
/*
void Enemigo::Defenderse()
{
}
*/
void Enemigo::RecibirDanio(float danio_recibido)
{
    if (moving)
    {   
        float da=(rand()&100)/100.0f * danio_recibido;
        vida -= da;
        if(vida<=0)
        {
            vida=0;
            Morir();
        }
    }
    else
    {
        Defenderse();
    }
}

void Enemigo::Moverse()
{
    if(vivo)
        moving = true;
}

void Enemigo::Detenerse()
{
    moving = false;
}

/*void Enemigo::Atacar()
{

}
*/
