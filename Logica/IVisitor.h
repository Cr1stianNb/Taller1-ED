// IVisitor.h
#ifndef VISITOR
#define VISITOR

class Administrador;
class UsuarioMenor;
class UsuarioMayor;

class IVisitor
{
    public:
        virtual void acepta(Administrador) = 0;
        virtual void acepta(UsuarioMenor) = 0;
        virtual void acepta(UsuarioMayor) = 0;
};

#endif