#pragma once
#include <iostream>
using std::cout;
using std::endl;

class Enemigo
{
protected:
    float vida;
    float defensa;
    float danio;
    int nivel;
    float rango; // Rango de ataque
    float velocidad;
    // atributo para operacion o funcionamiento del enemigo
    bool moving = false;
    bool vivo = true;

public:
    Enemigo(float vida = 100, float defensa = 50, float danio = 80,
            int nivel = 1, float rango = 5, float velocidad = 20);
    float GetVida() const { return vida; };
    float Getdefensa() const { return defensa; };
    float GetDanio() const { return danio; };
    float GetNivel() const { return nivel; };
    float GetRango() const { return rango; };
    float GetVelocidad() const { return velocidad; };
    bool IsALive() const { return vivo; };

    //<METODOS>
    // No sabemos que hara el enemigo para atacar, por lo que no podemos
    // poner codigo en la implementacion, pero el metodo es necesario por
    // disenio. Cuenado tenemos este tipo de metodos lo declramos como
    // virtual puro. Una funcion virtual pura de le conoce como funcion
    // abstracta y no tiene codigo =, por lo que se le asigna 0 como codigo.

    virtual void Atacar() = 0;
    // Toda clase que tenga al menos un metodo virtual se convierte en
    //  clase abstracta
    virtual void Curarse() = 0;
    virtual void Defenderse() = 0;
    virtual void RecibirDanio(float danio_recibido);
    virtual void Moverse();
    virtual void Detenerse();
    virtual void Morir() { vivo = false; };
};
