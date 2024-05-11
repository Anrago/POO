#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <thread>
#include <typeinfo>
#include "Enemigo.h"
#include "Mago.h"
#include "Tanque.h"
#include "Gargola.h"
using std::cout;
using std::endl;
using std::vector;

void UsarEnemigo(Enemigo *Enemigo);
void Delay(long ms);

int main()
{
    srand(time(0));
    // Enemigo es una clase abstracta. No se pueden crear instancias
    // de clases abstractas
    // Enemigo Sion;
    vector<Enemigo *> enemigos;
    // Creamos 10 enemigos de forma aleatoria
    for (int i = 0; i < 10; i++)
    {
        switch (rand() % 3)
        {
        case 0:
            enemigos.push_back(new Mago);
            break;
        case 1:
            enemigos.push_back(new Tanque);
            break;
        case 2:
            enemigos.push_back(new Gargola);
            break;
        }
    }
    bool vivos = true;
    while (vivos)
    {
        vivos = false;
        // Iteramos el vector para interactuar con cada enemigo
        for (auto enemigo : enemigos)
        {
            if (enemigo->IsALive())
            {
                vivos = true;
                UsarEnemigo(enemigo);
            }
            Delay(100);
        }
        Delay(800);
    }
}

void UsarEnemigo(Enemigo *enemigo)
{
    if (rand() % 2)
        enemigo->Moverse();
    else
        enemigo->Detenerse();
    if (rand() % 2)
        enemigo->RecibirDanio(rand() % 40);
    if (rand() % 2)
        enemigo->Atacar();
    if (rand() % 2)
        enemigo->Curarse();
    /*En C++, para hacer conversiones existen
    2 macros muy utilies, static_cast y dinamic_cast.
    El primero verifica en tiempo de compilacion
    si la conversion podria ser valida. Si no es valida
    obtenemos un error*/
    // Mago *m=static_cast<Mago*>(enemigo)
    // Esto todavia podria generar errores
    /*Dinamic_cast se utiliza con clases que
    consideran polimorfismo, si la conversio es valida devuelve el apuntador convertio,
    si no es valida devuelve nullptr*/
    Mago *m =dynamic_cast<Mago*>(enemigo);
    if(m!=nullptr)
    {
        if(rand()%2)
            m->RegenerarMana();
    }
    Volador *v=dynamic_cast<Volador*>(enemigo);
    if (v!=nullptr)
    {
        if(rand()%2)
            v->Volar();
        else
            v->Aterrizar();
    }
    

    // CONVERSION EXPLICITA ESTILO C
    // Para conocer el tipo que esta almacenado
    //  en una variable, podemos utilizar el macro
    // type_id. Devuelve un objeto typeinfo, que incluye
    // el nombre
    /*
    std::string tn = typeid(*enemigo).name();
    cout << "Tipo: " << tn << endl;
    if (tn == "4Mago")
    {
        if (rand() % 2)
        {
            Mago *mago = (Mago *)enemigo;
            mago->RegenerarMana();
        }
    }
    if (tn == "7Gargola")
    {
        if (rand() % 2)
            ((Gargola *)enemigo)->Volar();
        else
            ((Gargola *)enemigo)->Aterrizar();
    }
    */
}

void Delay(long ms)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}
