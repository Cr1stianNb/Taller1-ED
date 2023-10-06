#include "UsuarioMayor.h"

UsuarioMayor::UsuarioMayor(std::string nombre , std::string clave, int edad, std::string correo):Usuario(nombre, clave, edad, correo){};

void UsuarioMayor::visita(IVisitor *visitor)
{
    visitor->acepta(*this);
};