#include "Banco.h"

Banco::Banco()
{
    nombreBanco = "BanCoppel";
    Habientes_cont = 30000;
    Cheques_cont = 10000;
}

Banco::~Banco()
{
    for(auto Dh:C_Habientes)
        delete Dh.second;
    for (auto Dc:C_Cheques)
        delete Dc.second;
    
    
}

CuentaHabiente *Banco::CrearCuentaHabiente(string Nombre, string Curp)
{
    CuentaHabiente *NuevaCuenta = new CuentaHabiente(++Habientes_cont, Nombre, Curp);

    C_Habientes[Habientes_cont] = NuevaCuenta;
    return NuevaCuenta;
}

CuentaDeCheques *Banco::CrearCuentaDeCheques(CuentaHabiente Propietario, float saldo)
{
    CuentaDeCheques *NuevaCuenta = new CuentaDeCheques(++Cheques_cont, saldo);

    Propietario.ObtenerCuenta(NuevaCuenta);

    C_Cheques[Cheques_cont] = NuevaCuenta;
    return NuevaCuenta;
}

void Banco::Depositar(int NumeroCuentaC, float Cantidad)
{
    for (auto Ct : C_Cheques)
    {
        if (Ct.first == NumeroCuentaC)
        {
            Ct.second->depositar(Cantidad);
            break;
        }
    }
}

void Banco::Retirar(int NumeroCuentaC, float Cantidad)
{
    for (auto Ct : C_Cheques)
    {
        if (Ct.first == NumeroCuentaC)
        {
            Ct.second->retirar(Cantidad);
            break;
        }
    }
}

void Banco::Transferir(int Origen, int Destino, float Cantidad)
{
    for (auto Tr:C_Cheques)
    {
        if(Tr.first==Origen)
            Tr.second->transferir(Cantidad,*C_Cheques[Destino]);
    }   
    
}
