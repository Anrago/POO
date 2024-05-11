#include "CuentaHabiente.h"
#include "CuentaDeCheques.h"

CuentaHabiente::CuentaHabiente(int Numero, string Nombre, string Curp)
{
    this->Numero = Numero;
    this->Nombre = Nombre;
    this->Curp = Curp;
    cout << "SU CUENTA HABIENTE SE HA CREADO CON EXITO" << endl;
    cout << "SU NUMERO DE CUENTA HABIENTE ES: " << Numero << endl;
}

void CuentaHabiente::ObtenerCuenta(CuentaDeCheques *NuevaCuenta)
{
    misCuentas.push_back(NuevaCuenta);
}

void CuentaHabiente::ImprimirReporte()
{
    cout << "NUMERO CUENTAHABIENTE: " << Numero << endl;
    cout << "NOMBRE CUENTAHABIENTE: " << Nombre << endl;
    cout << "CURP CUENTAHABIENTE: " << Curp << endl;

    cout << "<<<<<<<<<<<<<CUENTAS DE CHEQUES>>>>>>>>>>>>>>>>>" << endl;
    cout << "No. cuenta | Saldo | Fecha del ultimo movimiento" << endl;
    for (auto Ch : misCuentas)
    {
        Ch->estadoDeCuenta();
    }
}
