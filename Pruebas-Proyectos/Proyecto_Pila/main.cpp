#include <iostream>
#include "Stack.cpp"
using std::cout;
using std::endl;
int main()
{
    Stack<int> pila;

    pila.Push(9);
    pila.Push(20);
    pila.Push(1);
    pila.Push(3);
    pila.Push(666);
    cout << "ELIEMENTOS DE LA PILA" << endl;
    while (!pila.IsEmpy())
    {
        cout << " " << pila.Pop();
    }
    cout << endl;
    
    try
    {
        pila.Pop();
    }
    catch(const char e)
    {
        cout<<e<<endl;
    }
    



    Stack<double> pila2;

    pila2.Push(1.5);
    pila2.Push(3.1416);
    pila2.Push(8.9);
    pila2.Push(3.3333);
    while (!pila2.IsEmpy())
    {
        cout << " " << pila2.Pop();
    }
    cout<<endl;
}