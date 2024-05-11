#pragma once
#include "Enemigo.h"
class Mago : public Enemigo
{
private:
    float Mana=1000;
public:
    Mago();
    virtual void LanzarHechizo();
    virtual void HechizoCurativo();
    virtual void RegenerarMana();
    //Es necesario sobreescribir e implementar las funciones virtuales
    //puras e=heredadas para que esta cclase no de abstracta
    void Atacar() override;
    void Curarse() override;
    void Defenderse() override;
    void Morir() override;
    void RecibirDanio(float danio_recibido) override;

};

