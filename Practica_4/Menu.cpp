#include "Menu.h"
#include <iostream>



using std::cin;
using std::cout;
using std::endl;

Menu::Menu(string titulo)
{
    this->titulo = titulo;
}

void Menu::Agregar(Opcion la_opcion)
{
    // agregamos la opcion al mapa con metodo insert
    if (opciones.find(la_opcion.GetTecla()) == opciones.end())
    {
        opciones.insert({la_opcion.GetTecla(), la_opcion});
        exit_key = la_opcion.GetTecla();
    }
    else
        throw "la opcion ya existe en el menu...";
}

void Menu::Eliminar(char tecla)
{
    auto it = opciones.find(tecla);
    if (it != opciones.end())
        opciones.erase(it);
}

void Menu::Desplegar()
{
    cout << titulo << endl;
    // Desplegamos las opciones
    system(CLEAR_SCREEN);
    for (auto &par : opciones)
    {
        par.second.Desplegar();
    }
}

char Menu::Seleccionar()
{
    char sel;
    while (true)
    {
        cout << "Seleccione su opcion: ";
        cin >> sel;
        cin.ignore(1024, '\n');
        // buscamos la opcion selecionada
        auto it = opciones.find(sel);
        if (it != opciones.end())
        {
            (*it).second.Ejecutar();
            return sel;
        }
        else
        {
            cout << "Opcion no valida" << endl;
        }
    }
    return sel;
}

void Menu::Ejecutar()
{
    do
    {
        // system("clear");
        Desplegar();
    } while (Seleccionar() != exit_key);
}
