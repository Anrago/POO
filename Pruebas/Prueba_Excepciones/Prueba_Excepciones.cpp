#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int Dividir(int num, int den);

int main()
{
    int x, y;
    cout << "Dame el dividendo: ";
    cin >> x;
    cout << "Dame el divisor: ";
    cin >> y;
    // Cuando una funcion puede generar una excepxion, se puede ejecutar
    // codigo relacionado con la invocacion de la funcion en un bloque
    // try-catch
    try
    {

        int d = Dividir(x, y);
        // En caso de que se genere la excepcion, la ejecucion del bloque
        // try se interrumpe, y el control pasa al bloque catch
        cout << "El resultado de la divison de " << x << " / " << y << " es " << d << endl;
    }
    catch (const char *e)
    {
        cout << e << endl;
    }
}

int Dividir(int num, int den)
{
    // Una forma de manejar los errores en c++ y otros lenguajes
    // son las excepciones. Una excepcion es una notificacion de error.
    // Cuando ocurre el error o cuando se detecta el error
    // se lanza la notificacion, y quien invoca el codigo puede recivir
    /// esa notificacion (atraparla) y hacer acciones necesarias para
    // manejar el error. Cuando una excepcion es lanzada, la ejecucion de la funcion se
    // interrumpe y el control regresa al codigo que invoco la funcion
    if (den == 0)
    {
        // para lanzar la notificacion utilizamos throw
        throw "Tonto, no se puede dividir entre 0";
    }
    return num / den;
}
