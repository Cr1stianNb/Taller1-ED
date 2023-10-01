#ifndef USUARIO_MENOR_1
#define USUARIO_MENOR_1
#include "Usuario.h"


class UsuarioMenor : public Usuario 
{
    public:
        void visita(IVisitor*);
};


#endif