#include "Banco.h"
#include "Menu.h"

#ifdef _WIN32
    #define CLEAR_SCREEN "cls"
#else
    #define CLEAR_SCREEN "clear"
#endif

void EnElBanco();
void pausa();

int main()
{   
    Menu menu;
    menu.Agregar({'1',"Ingresar al banco",EnElBanco});
    menu.Agregar({'2',"No ingresar e irme ",});
    menu.Ejecutar();
    system(CLEAR_SCREEN);
    return 0;
}

void EnElBanco()
{
    Banco BanCoppel;
    Menu menuBanco;
    system(CLEAR_SCREEN);
    menuBanco.Agregar({'A',"CREAR CUENTA HABIENTE",});
    menuBanco.Agregar({'B',"CREAR CUENTA DE CHEQUES",});
    menuBanco.Agregar({'C',"DEPOSITAR",});
    menuBanco.Agregar({'D',"RETIRAR",});
    menuBanco.Agregar({'E',"TRANSFERIR",});
    menuBanco.SetExitKey('X');
    menuBanco.Ejecutar();
}

void pausa()
{
    cout<<"Presione Enter para continuar...";
    fflush(stdout); // Limpia el búfer de salida para asegurar que el mensaje se muestre antes de esperar la entrada
    while (getchar() != '\n'); // Espera a que el usuario presione Enter
}