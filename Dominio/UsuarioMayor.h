#ifndef USUARIO_MAYOR_1
#define USUARIO_MAYOR_1
#include "Usuario.h"

class UsuarioMayor : public Usuario
{

    public:
        UsuarioMayor(std::string, std::string, int);
        virtual void visita(IVisitor*);
};

#endif