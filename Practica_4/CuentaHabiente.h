#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::string;
using std::vector;

class CuentaDeCheques;

class CuentaHabiente
{
protected:
    int Numero;
    string Nombre;
    string Curp;
    vector<CuentaDeCheques*> misCuentas;
public:
    CuentaHabiente(int Numero, string Nombre, string Curp );
    void ObtenerCuenta(CuentaDeCheques* NuevaCuenta);
    void ImprimirReporte();
};


