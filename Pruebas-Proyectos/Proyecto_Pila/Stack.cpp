#include "Stack.h"

template <class T>
Stack<T>::~Stack()
{
    clear();
}

template <class T>
void Stack<T>::Push(T dato)
{
    struct nodo *nuevo = new struct nodo;
    if (nuevo == nullptr)
        throw("MEMORIA INSUFICIENTE");
    nuevo->dato = dato;
    nuevo->previo = top;
    top = nuevo;
}

template <class T>
T Stack<T>::Pop()
{
    if (top == nullptr)
        throw("Underflow error....");

    auto aux = top;
    top = top->previo;
    T val = aux->dato;
    delete aux;
    return val;
}

template <class T>
void Stack<T>::clear()
{
    struct nodo *aux;
    while (top != nullptr)
    {
        aux = top;
        top = top->previo;
        delete aux;
    }
}

template <class T>
T Stack<T>::peek()
{
    if (top == nullptr)
        throw("Underflow error....");
    return top->dato;
}
