#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::ostream;
class Vector
{
public:
    double x,y,z;
    //Utilizamos parametros default
    //si se omiten al invocar el constructor
    //toman el valor default
    Vector(double x=0,double y=0,double z=0);
    Vector Sumar(Vector v2); 
    Vector Multiplicar(Vector v2);
    //En C++ podemos sobrecargar funciones
    //char ToStr();
    Vector Escalar(double s);
    //En C++ podemos sobrecargar los operadores, esto
    //es, podemos definir que sucedera cuando se aplique 
    // un operador a un elemento determinado. Para sobrecargar
    //un operador se crea una funcion con un nombre especial.
    //Cuando la funcion es miembro de una clase, el operador izquierdo es el objetp
    //al cual pertenece la funcion, y el operando derecho
    //debe ser recibido por la funcion como parametro.
    //El nombre de la funcion debe de ser operator seguido
    //del operador a sobrecargar. El tipo de retorno debe ser congruente con la operacon
    Vector operator*(Vector v2);
    Vector operator+(Vector v2);
    double GetMagnitud();
    Vector GetUnitVector();
    
};
//Cuando
Vector operator*(double z,Vector v2);
ostream &operator<<(ostream& out, Vector v);

