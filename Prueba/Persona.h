#include <iostream>
#include <string.h>
using std::cout;
using std::cin;
using std::endl;

class Persona
{
    //los mienros de la clase tienen un nivel de 
    //proteccion o acceso. Por default, todos
    //son privado, pero se puede cambiar al
    //tipo que nos convenga
    //existen 3 tipos de proteccion:
    //priavte(default)
    //protected
    //public
    //Para poder el tipo de proteccion, se utiliza la palaabra
    //clave seguida de : antes de la declaracion de los element
    // que tendran ese tipo de proteccion

protected:
    int edad=18;
    char nombre[];

    void Reir();
    void Comer();
public:
    //Los objetos pueden tener un constructor. El constructor
    //es un metodo que se ejecuta automaticamente cuando
    //el objeto fue recien creado en memoria. El constructor 
    //debe ser una funcion que tiene el mismo nombre
    Persona();
    //Los constructores pueden recibir parametros que
    // serviran para la inicializacion
    Persona(const char* el_nombre,int la_edad);
    void HacerReir(int motivo);
    void Saludar();

};

void Persona::Reir()
{
    cout << "jajaja" << endl;
}

void Persona::Comer()
{
    cout << "Nom,nom,nom,nom" << endl;
}

void Persona::Saludar()
{
    cout << "Hola, soy" << nombre;
    cout << "y tengo "<< edad << "anios"  << endl;
}

Persona::Persona(const char *el_nombre, int la_edad)
{
    edad = la_edad;
    nombre=(char*)malloc(strlen(el_nombre)+1);
    strncpy(nombre,el_nombre,strlen(el_nombre));
    nombre[strlen(el_nombre)]=0;
}

void Persona::HacerReir(int motivo)
{
    if ((motivo%3)==0)
    {
        Reir();
    }
    else
    {
        cout << ":|" << endl;
    }
}
