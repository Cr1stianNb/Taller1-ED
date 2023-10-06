#include "UsuarioMenor.h"

UsuarioMenor::UsuarioMenor(std::string nombre, std::string clave, int edad): Usuario(nombre, clave, edad, ""){};

void UsuarioMenor::visita(IVisitor *visitor)
{
    visitor->acepta(*this);
};