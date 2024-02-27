#include <iostream>
#include <iomanip>
#include <string>
#include "Vector.h"
using std::cout;
using std::cin;
using std::endl;

int main()
{
    Vector v1(10,20,5),v2={25,11,7};
    Vector v3;
    // v3=v1.Sumar(v2);
    v3=v1+v2;
    cout<<"Resultado de vector: ("<<v3.x<<"),("<<v3.y<<"),("<<v3.z<<")"<<endl;
    // v3=v1.Multiplicar(v2);
    v3=v1*v2;
    cout<<"Resultado de multiplicacion: ("<<v3.x<<"),("<<v3.y<<"),("<<v3.z<<")"<<endl;
    v3=v3.Escalar(2);
    cout<<"Resultado de multiplicacion: ("<<v3.x<<"),("<<v3.y<<"),("<<v3.z<<")"<<endl;

}
