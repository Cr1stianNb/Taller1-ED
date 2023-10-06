#include "UsuarioMayor.h"

/**
* Constructor de la clase UsuarioMayor
*@param string nombre del usuario
*@param string clave del usuario
*@param int edad
*@param string correo 
*
*
*/
UsuarioMayor::UsuarioMayor(std::string nombre , std::string clave, int edad, std::string correo):Usuario(nombre, clave, edad, correo){};

void UsuarioMayor::visita(IVisitor *visitor)
{
    visitor->acepta(*this);
};