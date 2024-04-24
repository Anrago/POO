#include <sstream>
#include <iomanip>
#include "Kardex.h"

using std::endl;
using std::left;
using std::right;
using std::setw;

void Kardex::RegistrarCalificacion(Calificacion cal)
{
    calificaciones.push_back(cal);
    // actualizamos los creditos y el promedio
    if (cal.GetValor() >= 60)
        creditos += cal.GetMateria()->GetCreditos();
    double sc = 0;
    for (Calificacion &cal : calificaciones)
        sc += cal.GetValor();
    promedio = sc / calificaciones.size();
    /**/
    sc = promedio * (calificaciones.size() - 1);
    sc += cal.GetValor();
}

string Kardex::ToString() const
{
    std::ostringstream out;
    /*Necesitamos imprimir informacion del estudiante
    La asociacion del estudiante-KArdex debe ser bi deireccional
    NO tenemos la clase estudiante, dejamos esta parte pendiente
    */

    /*
    Imprimimos calificaciones
    Primero un encabezado
    */

    out << "-------------------------------------------------------------------------------";
    out << "Clave";
    out << setw(50) << "Nombre";
    out << " Valor Creditos" << endl;
    out << "-------------------------------------------------------------------------------";
    for (Calificacion cal : calificaciones)
        out << cal.Tostring();
    out << "-------------------------------------------------------------------------------";
    out << "\nPromedio: " << std::setprecision(2) << promedio;
    out << "Creditos: " << creditos << endl;
    return out.str();
}
