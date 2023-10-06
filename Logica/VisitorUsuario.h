#ifndef VISITOR_USUARIOS
#define VISITOR_USUARIOS
#include "IVisitorUsuario.h"


// Forward declaration
class Administrador;
class UsuarioMenor;
class UsuarioMayor;

/**
 * @class VisitorUsuario
 * Clase que se encargara de visitar a los Usuarios y sus clases derivadas
*/
class VisitorUsuario : public IVisitor
{
    private:
        int tipoUsuario;
    public:
        /**
         * Constructor de la Clase VisitorUsuario
        */
        VisitorUsuario();
        /**
         * Destructor
        */
        ~VisitorUsuario();
        /**
         * Métodos override de la 'Interfaz IVisitor'
         * @param Administrador objeto administrador a visitar
        */
        void acepta(Administrador);
         /**
         * Métodos override de la 'Interfaz IVisitor'
         * @param UsuarioMenor objeto UsuarioMenor a visitar
        */
        void acepta(UsuarioMenor);
         /**
         * Métodos override de la 'Interfaz IVisitor'
         * @param UsuarioMayor objeto UsuarioMayor a visitar
        */
        void acepta(UsuarioMayor);
        /**
         * Tipo de usuario que visito
         * @return un entero que define que tipo de usuario visito
        */
        int getTipo();
};


#endif