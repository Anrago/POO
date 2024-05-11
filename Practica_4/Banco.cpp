#include "Banco.h"

Banco::Banco()
{
    nombreBanco = "BanCoppel";
    Habientes_cont = 30000;
    Cheques_cont = 10000;
}

Banco::~Banco()
{
    for (auto Ch : C_Habientes)
        delete Ch.second;
    for (auto Ct : C_Cheques)
        delete Ct.second;
}

CuentaHabiente *Banco::CrearCuentaHabiente(string Nombre, string Curp)
{
    CuentaHabiente *NuevaCuenta = new CuentaHabiente(++Habientes_cont, Nombre, Curp);

    C_Habientes[Habientes_cont] = NuevaCuenta;
    return NuevaCuenta;
}

CuentaDeCheques *Banco::CrearCuentaDeCheques(int NumeroCh, float saldo)
{
    CuentaDeCheques *NuevaCuenta = new CuentaDeCheques(++Cheques_cont, saldo);

    if (C_Habientes[NumeroCh])
        C_Habientes[NumeroCh]->ObtenerCuenta(NuevaCuenta);
    else
    {
        cout << "CUENTA INEXISTENTE" << endl;
        return NULL;
    }

    C_Cheques[Cheques_cont] = NuevaCuenta;
    return NuevaCuenta;
}

CuentaHabiente *Banco::GetHabiente(int NumeroCh)
{
    if (C_Habientes[NumeroCh])
        return C_Habientes[NumeroCh];
    else
        return nullptr;
}

CuentaDeCheques *Banco::GetCheques(int NumeroC)
{
    if (C_Cheques[NumeroC])
        return C_Cheques[NumeroC];
    else
        return nullptr;
}

void Banco::ImprimirReporte(int NumeroCh)
{
    if (C_Habientes[NumeroCh])
    {
        C_Habientes[NumeroCh]->ImprimirReporte();
        return;
    }
    else
    {
        cout << "CUENTA INEXISTENTE" << endl;
        return;
    }
}

void Banco::Depositar(int NumeroCuentaC, float Cantidad)
{
    if (C_Cheques[NumeroCuentaC])
    {
        C_Cheques[NumeroCuentaC]->depositar(Cantidad);
    }
    else
    {
        cout << "NO SE HA PODIDO REALIZAR EL DEPOSITO" << endl;
    }
}

void Banco::Retirar(int NumeroCuentaC, float Cantidad)
{
    if (C_Cheques[NumeroCuentaC])
    {
        C_Cheques[NumeroCuentaC]->retirar(Cantidad);
    }
    else
    {
        cout << "NO SE HA PODIDO REALIZAR EL RETIRO" << endl;
    }
}

void Banco::Transferir(CuentaDeCheques *Origen, CuentaDeCheques *Destino, float Cantidad)
{
    Origen->transferir(Cantidad, Destino);
}
