#include "CuentaDeCheques.h"

CuentaDeCheques::CuentaDeCheques(int ELnumeroDeCuenta,float ELsaldo, Persona ELpropietario)
{
    numeroDeCuenta= ELnumeroDeCuenta;
    saldo=ELsaldo;
    Propietario=ELpropietario;
}

CuentaDeCheques::~CuentaDeCheques()
{
    if (UltimoMovimiento!=nullptr)
        free(UltimoMovimiento);    
}

void CuentaDeCheques::depositar(float cantidad)
{
    if(cantidad>0)
    {
        saldo+=cantidad;
        tiempoUltimoMovimiento=time(0);
        UltimoMovimiento=ctime(&tiempoUltimoMovimiento);
    }
    else
    {
        cout << "***********************************" <<endl;
        cout << "EL MOVIMIENTO NO PUDO SER REALIZADO" <<endl;
        cout << "***********************************" <<endl;
    }
}

void CuentaDeCheques::retirar(float cantidad)
{
    if(cantidad<=saldo)
    {
        saldo-=cantidad;
        tiempoUltimoMovimiento=time(0);
        UltimoMovimiento=ctime(&tiempoUltimoMovimiento);
    }
    else
    {
        cout << "***********************************" <<endl;
        cout << "SALDO INSUFICIENTE PARA REALIZAR EL MOVIMIENTO" <<endl;
        cout << "***********************************" <<endl;
    }
}

void CuentaDeCheques::transferir(float cantidad, CuentaDeCheques* destino)
{
        
        
            destino->saldo+=cantidad;
            saldo-=cantidad;
        
     
}

void CuentaDeCheques::estadoDeCuenta()
{
    cout <<"********************************" << endl;
    cout << "Numero de la cuenta " << numeroDeCuenta << endl;
    cout << "Saldo Actual: " << saldo << endl;
    cout << "Fecha del ultimo movimiento: " << UltimoMovimiento << endl;
}
