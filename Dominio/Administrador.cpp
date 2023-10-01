#include "Administrador.h"


Administrador::Administrador(std::string nombre, std::string clave, int edad):
    Usuario(nombre, clave, edad)
{
    this->accesoLog = true;
};


void Administrador::visita(IVisitor* visitador)
{
    visitador->acepta(*this);
};