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
    cout << "FELICIDADES LA CUENTA DE CHEQUES SE HA CREADO EXITOSAMENTE" << endl;
    cout << "SU NUMERO DE CUENTA ES: " << ELnumeroDeCuenta << endl;
}

void CuentaDeCheques::depositar(float cantidad)
{
    if (cantidad > 0)
    {
        saldo += cantidad;
        tiempoUltimoMovimiento = time(0);
        UltimoMovimiento = ctime(&tiempoUltimoMovimiento);
        cout << "DEPOSITO EXITOSO" << endl;
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
        cout << "RETIRO EXITOSO" << endl;
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
        cout << "TRANSFERENCIA REALIZADA CON EXITO" << endl;
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
