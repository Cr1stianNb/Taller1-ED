// IVisitor.h
#ifndef VISITOR
#define VISITOR

class Administrador;
class UsuarioMenor;
class UsuarioMayor;

/**
 * @interface Interfaz que tiene los métodos para que las clases visitoras puedan visitar a los Usuario y derivados
*/
class IVisitor
{
    public:
        /**
         * Acepta un Usuario de tipo Administrador
        */
        virtual void acepta(Administrador) = 0;
        /**
         * Acepta un usuario de tipo UsuarioMenor
        */
        virtual void acepta(UsuarioMenor) = 0;
        /**
         * Acepta un usuario de tipo UsuarioMayor
        */
        virtual void acepta(UsuarioMayor) = 0;
};

#endif