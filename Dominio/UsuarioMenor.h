#ifndef USUARIO_MENOR_1
#define USUARIO_MENOR_1
#include "Usuario.h"


class UsuarioMenor : public Usuario 
{
    public:
        UsuarioMenor(std::string, std::string, int);
        virtual void visita(IVisitor*);
};


#endif