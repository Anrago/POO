#include "Tanque.h"

Tanque::Tanque() : Enemigo(500, 250, 30, 1, 5, 15)
{
}

void Tanque::Golpear()
{
    cout << "Tirando un golpe..." << endl;
}

void Tanque::Atacar()
{
    Golpear();
}

void Tanque::Curarse()
{
    vida += 2;
    vida = (vida > 500) ? 500 : vida;
}

void Tanque::Defenderse()
{
    cout << "Poniendo el pecho... " << endl;
}

void Tanque::RecibirDanio(float danio_recibido)
{
    vida -= danio_recibido * .25;
    if (vida <= 0)
    {
        vida = 0;
        Morir();
    }
}

void Tanque::Morir()
{
    vivo = false;
    cout << "Explota..." << endl;
}
