#include "UsuarioMayor.h"

UsuarioMayor::UsuarioMayor(std::string nombre , std::string clave, int edad):Usuario(nombre, clave, edad){};

void UsuarioMayor::visita(IVisitor *visitor)
{
    visitor->acepta(*this);
};