#define _CTR_SECURE_NO_WARNINGS
#include <iostream>
#include "Persona.h"
// using namespace std;
using std::cout;
using std::cin;
using std::endl;
int main()
{
    srand(time(0));
    // En C++ existen 2 formas de crear un objeto.
    //Estatica, el objeto se crea en memoria estatica,
    //en el stack del programa
    Persona la_persona("emergencia",19);
    //En este punto del programa, ya existe un objeto de{
    //Clase persona en la memoria stack

    //La sgunda forma es la forma dinamica, el objeto se debe
    // crear en memoria dinamica por medio del operador new
    //new devielve la direccion de memoria del objeto recien creado en el heap.
    //Necesitamos un apuntador para almacenar la direccion y poder aceder al obj
    Persona* otra_persona;
    //Todavia no existe objeto nuevo en este punto
    otra_persona=new Persona("panfilo",25);
    //La proncipal diferencia entre los objetos en memoria estatica y 
    //los objetos en memoria dinamica es que los objetos estaticos
    //se eliminan automaticamente de memoria una vez que finaliza el bloque
    //de codigo en el cual fueron creados(igual que las variables locales).
    //Los objetos en memoria dinamica se tienen que eliminar explicitamente
    //con el operador delete

    //para utilizar el objeto, podemos acceder a sus miembros
    //(Variables o funciones) por medio que los mismos operadores 
    //que utilizamos en las estructuras.
    // . cuando es estatico
    // -> cuando es apuntador

    la_persona.saludar();
    la_persona.hacerReir(rand());

    otra_persona->saludar();
    otra_persona->hacerReir(rand());

    
    delete otra_persona;//se elimina de memoria el obj
}
