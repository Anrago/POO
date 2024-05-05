#include "IngSoftware.h"

IngSoftware::IngSoftware(string nombre, string cedula, int edad, int aniosExp)
    : Ingeniero(nombre, cedula, edad, aniosExp)
{
}

void IngSoftware::Programar()
{
    cout << "Pidiendole un programa a ChatGPT" << endl;
}

void IngSoftware::ResolverProblemas()
{
    cout << "checando Tiktok" << endl;
    Programar();
    cout << "Checando mi instragram" << endl;
}
