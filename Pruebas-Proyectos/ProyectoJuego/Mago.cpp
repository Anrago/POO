#include "Mago.h"

Mago::Mago() : Enemigo(100, 25, 75, 1, 25, 7)
{
}

void Mago::LanzarHechizo()
{
    if (Mana >= 80)
    {
        cout << "Por Demacia" << endl;
        Mana -= 80;
    }
    else
    {
        cout << "No hay mana" << endl;
    }
}

void Mago::HechizoCurativo()
{
    if (Mana >= 90)
    {
        cout << "Hechizo curativo... " << endl;
        Mana -= 90;
        vida *= 1.2 ? 100 : vida;
        vida = (vida > 100);
    }
    else
    {
        cout << "No hay mana... " << endl;
    }
}

void Mago::RegenerarMana()
{
    if(Mana<=990)
        Mana+=10;
    cout << "Regenerando Mana"<<endl;
}

void Mago::Atacar()
{
    if (vivo)
        // Verificar el rango de ataque
        LanzarHechizo();
}

void Mago::Curarse()
{
    if (vivo)
        HechizoCurativo();
}

void Mago::Defenderse()
{
    if (vivo)
        cout << "Escudo negro..." << endl;
}

void Mago::Morir()
{
    vivo = false;
    cout << "Desplomandoze... " << endl;
}

void Mago::RecibirDanio(float danio_recibido)
{
    if (!vivo)
        return;
    if (!moving)
    {
        if (Mana >= 90)
        {
            Defenderse();
            return;
        }
    }
    float da = (rand() & 100) / 100.0f * danio_recibido;
    cout<<"Recibiendo damio..."<<endl;
    vida -= da;
    if (vida <= 0)
    {
        vida = 0;
        Morir();
    }
}
