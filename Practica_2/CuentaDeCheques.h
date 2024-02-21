#include <iostream>
#include <string>
#include "Persona.h"
#pragma once

class CuentaDeCheques
{
protected:
    int numeroDeCuenta;
    float saldo;
    Persona Propietario;
    time_t tiempoUltimoMovimiento=time(0);
    char* UltimoMovimiento=ctime(&tiempoUltimoMovimiento);
    
    
public:
    CuentaDeCheques(int ELnumeroDeCuenta,float ELsaldo, Persona ELpropietario);
    ~CuentaDeCheques();
    void depositar(float cantidad);
    void retirar(float cantidad);
    void transferir(float cantidad, CuentaDeCheques* destino);
    void estadoDeCuenta();
};

