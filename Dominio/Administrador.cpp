#include "Administrador.h"


Administrador::Administrador(std::string nombre, std::string clave, int edad, std::string correo):
    Usuario(nombre, clave, edad, correo)
{};


void Administrador::visita(IVisitor* visitador)
{
    visitador->acepta(*this);
};