#ifndef VISITOR_USUARIOS
#define VISITOR_USUARIOS
#include "IVisitor.h"



class Administrador;
class UsuarioMenor;
class UsuarioMayor;


class VisitorUsuario : public IVisitor
{
    private:
        int tipoUsuario;
    public:
        VisitorUsuario();
        void acepta(Administrador);
        void acepta(UsuarioMenor);
        void acepta(UsuarioMayor);
        int getTipo();
};


#endif