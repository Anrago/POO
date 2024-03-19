#include <iostream>
using std::cout;
using std::endl;

// En c++ Existe un mecanismo llamado platillas o templates
// una plantilla permite parametrizar el tipo de dato para
// bloques de codigo. Se declara un tipo de dato generico
// y el codigo se programa usando este dato en donde
// sea pertinente. Cuando se utiliza el bloque de codigo creado
// con template, se puede especificar que tipo de dato se
// aplicara al generico

template <class T> // T es un tipo de dato generico. Si nececito mas datos los separo por ,
void Swap(T &a, T &b);

int main()
{
    int x = 10;
    int y = 666;

    cout << "x: " << x << "  y:" << y << endl;
    Swap<int>(x, y);
    cout << "x: " << x << "  y:" << y << endl;

    float o = 10.0f;
    float p = 3.1416f;

    cout << "o: " << o << "  p:" << p << endl;
    Swap<float>(o, p);
    cout << "o: " << o << "  p:" << p << endl;
}

template <class T> //El template se debe declarar antes de la funcion
void Swap(T &a, T &b)
{
    T temp = a;

    a = b;

    b = temp;
}
