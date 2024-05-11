#pragma once
#include "Enemigo.h"
#include "Volador.h"
class Gargola : public Enemigo,public Volador
{
private:
public:
    Gargola();
    void Atacar() override;
    void Curarse() override;
    void Defenderse() override;
    void Morir() override;
    virtual void Volar() override;
    virtual void Aterrizar() override;
    virtual void Morder();
    virtual void Araniar();
    virtual void RecibirDanio(float danio_recibido) override;
};
