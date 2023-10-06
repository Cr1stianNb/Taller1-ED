#ifndef ADMINISTRADOR_1
#define ADMINISTRADOR_1
#include "Usuario.h"

/**
 * @class Administrador extends de Usuario
*/
class Administrador : public Usuario 
{

    public:
        /**
        * Constructor de la clase Administrador
        * @param string nombre
        * @param string clave
        * @param int edad
        * @param string correo
        */
        Administrador(std::string, std::string, int, std::string);
        /**
         * Patrón visitor 
         * @param IVisitor Interfaz visitorUsuario
        */
        void visita(IVisitor*);
};


#endif