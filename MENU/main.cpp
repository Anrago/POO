#include <iostream>


#include "Menu.h"
using std::cout;
using std::endl;

void Listado()
{
    cout << "archvos en el folder";
    system("dir");
}
void configuracionIP()
{
    cout << "configuracion IP";
    system("ifconfig");
}

void conexionActiva()
{
    cout << "configuracion IP";
    system("netstat");
    
    
}

void configuracion()
{
    Menu submenu("Menu configuracion");

    submenu.Agregar({'1',"subopcion 1",
        [](){cout<< "Ejecutando subOpcion 1.."<<endl;}});

    submenu.Ejecutar();

}

int main()
{
    Menu el_menu("menu de prueba");
    // Agregamos opciones
    el_menu.Agregar({'1', "Ver listado de archivos", Listado});
    el_menu.Agregar({'2', "Ver configuracion IP", configuracionIP});
    el_menu.Agregar({'3', "Ver conexiones acitvas", conexionActiva});
    el_menu.Agregar({'4', "Configuracion", configuracion});
    el_menu.Agregar({'5', "Salir", [](){ cout << "ADIOS" << endl; }});

    el_menu.Ejecutar();
}