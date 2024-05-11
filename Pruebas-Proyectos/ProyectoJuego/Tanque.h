#pragma once
#include "Enemigo.h"
class Tanque : public Enemigo
{
protected:
    float escudo = 100;

public:
    Tanque();
    virtual void Golpear();
    void Atacar() override;
    void Curarse() override;
    void Defenderse() override;
    void RecibirDanio(float danio_recibido) override;
    virtual void Morir() override;
};
