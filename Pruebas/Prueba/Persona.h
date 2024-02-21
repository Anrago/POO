#include <iostream>
#include <string.h>
using std::cout;
using std::cin;
using std::endl;
#pragma once
class Persona {
	//Los miembros de la clase pueden ser privados o publicos, por default son privados, pero se puede cambiar al tipo que nos convenga
	//Existen 3 tipos de proteccion:
	//Public: Los miembros son accesibles desde cualquier parte del programa
	//Private: Los miembros son accesibles solo desde la misma clase
	//Protected: Los miembros son accesibles desde la misma clase y desde las clases hijas
	//Para poner el tipo de proteccion, es utilizada la palabra clave seguida de dos puntos antes de la declaracion de los miembros

protected:
	int edad;
	//char name[30];
	char* name;

	void reir();
	void comer();
	
public:
	//Los objetos pueden tener constructores, que son funciones que se ejecutan automaticamente cuando el objeto es creado
	//El constructor es una funcion que tiene el mismo nombre que la clase, y no tiene tipo de retorno
	//Los constructores pueden tener argumentos, pero no pueden ser llamados directamente
	Persona(const char* elName, int laEdad);
	Persona();
	//En c++ podemos usar el mismo nombre para diferentes funciones, siempre y cuando los parametros sean diferentes
	//Ciamdp implementamos funciones de este tipo, se le llama sobrecarga de funciones

	//Los objetos pueden tener un destructor, El destructor es una funcion que se ejecuta automaticamente cuando el objeto es eliminado
	//El destructor es una funcion que tiene el mismo nombre que la clase, pero precedido por el simbolo ~
	~Persona();

	void saludar();
	void hacerReir(int motivo);
	void liberar();
};
void Persona::reir() {
	cout << "Jajaja..." << endl;
}

void Persona::comer() {
	cout << "nom, nom, nom" << endl;
}

Persona::Persona(){
	//Los constructores se utilizan para inicializar atributos y reservr recursos que pudiera utilizar el objeto
	edad = 20;
	name = (char*) malloc(7); 
	strncpy(name, "Sosimo", 6); // Copia el contenido de la cadena de texto en el segundo argumento al primer argumento
	name[6] = 0;
	
}

Persona::Persona(const char* elName, int laEdad){
	edad= laEdad;
	name=(char* ) malloc(strlen(elName)+1);
	strncpy(name, elName, strlen(elName));
	name[strlen(elName)] = 0;
}

Persona::~Persona(){
	if (name != nullptr) {
		cout << "Adios, " << name << endl;
		free(name);
	}
}

void Persona::saludar(){
	cout << "Hola, soy " << name;
	cout << " y tengo " << edad << endl;
}

void Persona::hacerReir(int motivo){
	if ((motivo % 3) == 0) {
		reir();
	}
	else {
		cout << "mal momo :( " << endl;
	}
}

void Persona::liberar() {
	free(name);
	name = nullptr;
}