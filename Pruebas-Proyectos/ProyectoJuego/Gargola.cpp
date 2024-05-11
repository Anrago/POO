#include "Gargola.h"

Gargola::Gargola() : Enemigo(100, 50, 50, 1, 5, 15)
{
}

void Gargola::Atacar()
{
    if (!vivo)
        return;
    if (rand() % 2)
        Morder();
    else
        Araniar();
}

void Gargola::Curarse()
{
    if (!vivo)
        return;
    vida = vida * 1.10;
    vida = (vida > 100) ? 100 : vida;
}

void Gargola::Defenderse()
{
    cout << "Cubriendose con las alas..." << endl;
}

void Gargola::Morir()
{
    vivo=0;
    cout<<"Cayendo con pescuezo retorcido..."<<endl;
}

void Gargola::Volar()
{
    if (vivo)
    {
        Volador::Volar();
        cout << "Aleteando y papaloteando..." << endl;
    }
}

void Gargola::Aterrizar()
{

    Volador::Aterrizar();
    cout << "Hasta el suelo..." << endl;
}

void Gargola::Morder()
{
    cout << "Morediendo rarw..." << endl;
}

void Gargola::Araniar()
{
    cout << "araniando" << endl;
}

void Gargola::RecibirDanio(float danio_recibido)
{
    if (!vivo)
        return;
    if (!Volando)
    {
        Defenderse();
        return;
    }
    float da = (rand() & 100) / 100.0f * danio_recibido;
    vida -= da;
    if (vida <= 0)
    {
        vida = 0;
        Morir();
    }
}
