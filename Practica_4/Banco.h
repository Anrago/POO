#include <iostream>
#include <map>
#include "CuentaDeCheques.h"
#include "CuentaHabiente.h"
using std::string;
using std::map;
class Banco
{
protected:
    string nombreBanco;
    int Habientes_cont;
    int Cheques_cont;
    map<int,CuentaHabiente*> C_Habientes;
    map<int,CuentaDeCheques*> C_Cheques;

public:
    Banco();
    ~Banco();
    CuentaHabiente *CrearCuentaHabiente(string Nombre, string Curp);
    CuentaDeCheques *CrearCuentaDeCheques(int NumeroCh,float saldo);
    CuentaHabiente *GetHabiente(int NumeroCh){return C_Habientes[NumeroCh];};
    CuentaDeCheques *GetCheques(int NumeroC){return C_Cheques[NumeroC];};
    void ImprimirReporte(int NumeroCh);
    void Depositar(int NumeroCuentaC,float Cantidad);
    void Retirar(int NumeroCuentaC,float Cantidad);
    void Transferir(CuentaDeCheques *Origen, CuentaDeCheques *Destino, float Cantidad);
};

