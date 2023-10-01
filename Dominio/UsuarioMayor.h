#ifndef USUARIO_MAYOR_1
#define USUARIO_MAYOR_1
#include "Usuario.h"

class UsuarioMayor : public Usuario
{

    public:
        void visita(IVisitor*);
};

#endif