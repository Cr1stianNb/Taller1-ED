#include "UsuarioMenor.h"



void UsuarioMenor::visita(IVisitor* visitor)
{
    visitor->acepta(*this);
};