
#include "Persona.h"

Persona::Persona(){
	//Los constructores se utilizan para inicializar atributos y reservr recursos que pudiera utilizar el objeto
	edad = 20;
	name = (char*) malloc(7); 
	strncpy(name,"Sosimo", 6); // Copia el contenido de la cadena de texto en el segundo argumento al primer argumento
	name[6] = 0;
	
}

Persona::Persona(const char* elName, int laEdad){
	edad= laEdad;
	name=(char* ) malloc(strlen(elName)+1);
	strncpy(name, elName, strlen(elName));
	name[strlen(elName)] = 0;
}

Persona::~Persona(){
	if (name != nullptr) 
	{
		cout << "Adios, " << name << endl;
		free(name);
	}
}