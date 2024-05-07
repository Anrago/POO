#include <iomanip>
#include "CuentaDeCheques.h"
using std::cout;
using std::endl;
using std::left;
using std::right;
using std::setw;

CuentaDeCheques::CuentaDeCheques(int ELnumeroDeCuenta, float ELsaldo)
{
    numeroDeCuenta = ELnumeroDeCuenta;
    saldo = ELsaldo;
}

void CuentaDeCheques::depositar(float cantidad)
{
    if (cantidad > 0)
    {
        saldo += cantidad;
        tiempoUltimoMovimiento = time(0);
        UltimoMovimiento = ctime(&tiempoUltimoMovimiento);
    }
    else
    {
        cout << "***********************************" << endl;
        cout << "EL MOVIMIENTO NO PUDO SER REALIZADO" << endl;
        cout << "***********************************" << endl;
    }
}

void CuentaDeCheques::retirar(float cantidad)
{
    if (cantidad <= saldo)
    {
        saldo -= cantidad;
        tiempoUltimoMovimiento = time(0);
        UltimoMovimiento = ctime(&tiempoUltimoMovimiento);
    }
    else
    {
        cout << "***********************************" << endl;
        cout << "SALDO INSUFICIENTE PARA REALIZAR EL MOVIMIENTO" << endl;
        cout << "***********************************" << endl;
    }
}

void CuentaDeCheques::transferir(float cantidad, CuentaDeCheques *destino)
{

    if (cantidad <= saldo)
    {
        destino->saldo += cantidad;
        saldo -= cantidad;
    }
    else
    {
        cout << "***********************************" << endl;
        cout << "SALDO INSUFICIENTE PARA REALIZAR EL MOVIMIENTO" << endl;
        cout << "***********************************" << endl;
    }
}

void CuentaDeCheques::estadoDeCuenta()
{
    cout << numeroDeCuenta << setw(12) << saldo << "    " << UltimoMovimiento;
}
