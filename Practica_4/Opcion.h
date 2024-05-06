#include <string>
#include <functional>
using std::string;
using std::function;

class Opcion
{
protected:
    string descripcion;
    char tecla;
    function<void(void)> accion;

public:
    Opcion(char tecla=0,string desc="",
    function<void(void)> a=[](){});

    //Getters sirven para optener info de los atributos(solo su valor)

    char GetTecla() const {return tecla;};
    string GetDescripcion() const {return descripcion;};
    void Desplegar()const;
    void Ejecutar()const{accion(); };

};
