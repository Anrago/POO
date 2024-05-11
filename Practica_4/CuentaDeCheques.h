#include <iostream>
#include <string>
#include <ctime>
#pragma once
using std::string;
using std::cout;
using std::endl;
class CuentaDeCheques
{
protected:
    int numeroDeCuenta;
    float saldo;
    time_t tiempoUltimoMovimiento=time(NULL);
    string UltimoMovimiento=ctime(&tiempoUltimoMovimiento);
    
    
public:
    CuentaDeCheques(int ELnumeroDeCuenta,float ELsaldo);
    void depositar(float cantidad);
    void retirar(float cantidad);
    void transferir(float cantidad, CuentaDeCheques *destino);
    void estadoDeCuenta();
};

