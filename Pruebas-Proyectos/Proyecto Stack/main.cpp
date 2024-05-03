#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
#include <queue>
#include <string.h>
#include "Estudiante.h"
// #include <ncurses.h>
using std::cin;
using std::cout;
using std::deque;
using std::endl;
using std::queue;
using std::stack;
using std::string;
void StackTest();
void StackTest2();
void QueTest();
void PQueTest();
void QueTest2();
void PQueTest2();

int main()
{
    PQueTest2();
}







void StackTest()
{
    stack<int> pila;
    int n;

    while (true)
    {
        cout << "DAME UN NUMERO:(-1 para terminar) ";
        cin >> n;

        if (n == -1)
            break;
        pila.push(n);
    }
    cout << "CANTIDAD DE DATOS EN LA PILA: " << pila.size() << endl;
    cout << "ELEMENTO TOPE: " << pila.top() << endl;
    cout << "TODOS LOS ELEMENTOS DE LA PILA: ";
    while (!pila.empty())
    {
        cout << " " << pila.top();
        pila.pop(); // pop solamente remueve el elemento en el tope, no diece cual era
    }
    cout << endl;
}

void StackTest2()
{
    // verificar si una frase es palindromo
    string frase;
    cout << "DAME UNA FRASE PAPU: ";
    std::getline(cin, frase);
    stack<char> pila;

    for (int i = 0; i < frase.size(); i++)
    {
        if (frase[i] != ' ')
            pila.push(tolower(frase[i]));
    }
    bool palindromo = true;

    for (char c : frase)
    {
        if (c == ' ')
            continue;
        if (c != ' ')
        {
            if (tolower(c) != pila.top())
            {
                palindromo = false;
                break;
            }
            pila.pop();
        }
    }

    if (palindromo)
    {
        cout << "\"" << frase << "\""
             << " SI ES UN PALINDROMO";
    }
    else
    {
        cout << "\"" << frase << "\""
             << " NO ES UN PALINDROMO";
    }
}

void QueTest()
{
    queue<int> cola;
    int n;

    while (true)
    {
        cout << "DAME UN NUMERO:(-1 para terminar) ";
        cin >> n;
        if (n == -1)
            break;

        cola.push(n);
    }
    cout << "CANTIDAD DE DATOS EN LA PILA: " << cola.size() << endl;
    cout << "ELEMENTO TOPE: " << cola.back() << endl;
    cout << "ELEMENTO cabeza: " << cola.front() << endl;
    cout << "TODOS LOS ELEMENTOS DE LA COLA: ";
    while (!cola.empty())
    {
        cout << " " << cola.front();
        cola.pop();
    }
    cout << endl;
}

void QueTest2()
{

    deque<int> cola;
    bool alt = true;
    int n;
    while (true)
    {
        cout << "DAME UN NUMERO:(-1 para terminar) ";
        cin >> n;
        if (n == -1)
            break;
        if (alt == true)
            cola.push_back(n);
        else
            cola.push_front(n);
        alt = !alt;
    }
    cout << "CANTIDAD DE ELEMENTOS EN LA COLA: " << cola.size() << endl;
    cout << "ELEMENTOS AL INICIO: " << cola.front() << endl;
    cout << "ELEMENTO AL FINAL: " << cola.back() << endl;
    cout << "ELEMENTOS EN LA COLA: " << endl;
    while (!cola.empty())
    {
        cout << cola.front() << " " << endl;
        cola.pop_front();
    }
}

void PQueTest2()
{
    std::priority_queue<Estudiante> cola;
    cola.push(Estudiante(354462, "Jose Roberto", 10000));
    cola.push({25425, "Maria Jose", 5000});
    Estudiante e;
    e = {548545, "Totonaco Perez", 9000};
    cola.push(e);
    cola.emplace(66666, "Messi El Mejor", 10101);
    cout << "CANTIDAD DE ELEMENTOS EN LA COLA: " << cola.size() << endl;
    cout << "ELEMENTOS AL INICIO: " << cola.top() << endl;
    cout << "ELEMENTOS EN LA COLA: " << endl;
    while (!cola.empty())
    {
        cout << cola.top();
        cola.pop();
    }
}

void PQueTest()
{
    std::priority_queue<int> cola;
    int n;
    while (true)
    {
        cout << "DAME UN NUMERO:(-1 para terminar) ";
        cin >> n;
        if (n == -1)
            break;
        cola.push(n);
    }
    cout << "CANTIDAD DE ELEMENTOS EN LA COLA: " << cola.size() << endl;
    cout << "ELEMENTOS AL INICIO: " << cola.top() << endl;
    cout << "ELEMENTOS EN LA COLA: " << endl;
    while (!cola.empty())
    {
        cout << cola.top() << endl;
        cola.pop();
    }
}
