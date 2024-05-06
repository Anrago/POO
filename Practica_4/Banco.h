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
    CuentaDeCheques *CrearCuentaDeCheques(CuentaHabiente Propietario,float saldo);
    void ObtenerCuenta();
    void ObtenerCuentaCheques();
    void Depositar(int NumeroCuentaC,float Cantidad);
    void Retirar(int NumeroCuentaC,float Cantidad);
    void Transferir(int Origen, int Destino, float Cantidad);
};

