#ifndef VISITOR_USUARIOS
#define VISITOR_USUARIOS
#include "IVisitorUsuario.h"



class Administrador;
class UsuarioMenor;
class UsuarioMayor;


class VisitorUsuario : public IVisitor
{
    private:
        int tipoUsuario;
    public:
        VisitorUsuario();
        ~VisitorUsuario();
        void acepta(Administrador);
        void acepta(UsuarioMenor);
        void acepta(UsuarioMayor);
        int getTipo();
};


#endif