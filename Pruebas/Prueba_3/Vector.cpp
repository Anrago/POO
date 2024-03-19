#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <math.h>
#include "Vector.h"


Vector::Vector(double x, double y, double z)
{
    //todo objeto tiene un apuntador
    //a si mismo, que se llama this. Es una
    //forma de hacer referencia a si mismo

    this->x=x;
    this->y=y;
    this->z=z;

}

Vector Vector::Sumar(Vector v2)
{
    Vector r;
    r.x=this->x+v2.x;
    r.y=y+v2.y;
    r.z=z+v2.z;

    return r;
}

Vector Vector::Multiplicar(Vector v2)
{

    
    Vector r;
    r.x = this->y * v2.z - this->z * v2.y;
    r.y = this->z * v2.x - this->x * v2.z;
    r.z = this->x * v2.y - this->y * v2.x;
    return r;
}

Vector Vector::Escalar(double s)
{

    Vector r;
    r.x=this->x*s;
    r.y=this->y*s;
    r.z=this->z*s;
    return r;
}
Vector Vector::operator*(Vector v2)
{

    Vector r;
    r.x = this->y * v2.z - this->z * v2.y;
    r.y = this->z * v2.x - this->x * v2.z;
    r.z = this->x * v2.y - this->y * v2.x;
    return r;
    
}


Vector Vector::operator+(Vector v2)
{
    Vector r;
    r.x=this->x+v2.x;
    r.y=y+v2.y;
    r.z=z+v2.z;

    return r;

}
double Vector::GetMagnitud()
{

    
    return sqrt(x * x + y * y + z * z);
}
Vector Vector::GetUnitVector()
{
    double m=GetMagnitud();
    Vector r;
    r.x=x/m;
    r.y=y/m;
    r.z=z/m;
    return r;
}
/*char Vector::ToStr()
{
    char cad[128];

    sprintf(cad,"(%.2lf,%.2lf,%.2lf)",x,y,z);
    std::ostringstream out;
    out <<"("<<x<<","<<y<<","<<z<<")";
    return out.str;
}
*/

Vector operator*(double z, Vector v2)
{
    return v2*z;
}

ostream& operator<<(ostream& out, Vector v)
{
    out <<v.x,v.y,v.z;
}
