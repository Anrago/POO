#include "Opcion.h"
#include <string>
#include <map>

#ifdef _WIN32
    #define CLEAR_SCREEN "cls"
#else
    #define CLEAR_SCREEN "clear"
#endif

using std::map;
using std::string;

class Menu
{
protected:
    string titulo;
    // Para manejar las multiples instancias
    // de opcion en este menu, usaremos mapa
    map<char, Opcion> opciones;
    char exit_key;

public:
    Menu(string titulo = "MENU");
    void Agregar(Opcion la_opcion);
    void Eliminar(char tecla);
    void SetExitKey(char ek){exit_key=ek;};
    void Desplegar();
    char Seleccionar();
    void Ejecutar();
};
