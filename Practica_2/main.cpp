#include <iostream>
#include "CuentaDeCheques.h"
int main()
{
    CuentaDeCheques *Cuenta1, *Cuenta2;
    Persona *Propietario1, *Propietario2;
    Propietario1 =new Persona("Julian",25);
    Propietario2 =new Persona("Sebas",35);


    Cuenta2 = new CuentaDeCheques(275486,2500,*Propietario1);
    Cuenta1 = new CuentaDeCheques(372576,2500,*Propietario1);

    Cuenta2->estadoDeCuenta();
    Cuenta1->estadoDeCuenta();

    Cuenta1->transferir(100,Cuenta2);

    Cuenta1->estadoDeCuenta();
    Cuenta2->estadoDeCuenta();

    free(Cuenta1);
    free(Cuenta2);
    free(Propietario1);
    free(Propietario2);
    
}