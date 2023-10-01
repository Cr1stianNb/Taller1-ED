#include "UsuarioMayor.h"

void UsuarioMayor::visita(IVisitor* visitor)
{
    visitor->acepta(*this);
};