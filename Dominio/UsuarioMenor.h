#ifndef USUARIO_MENOR_1
#define USUARIO_MENOR_1
#include "Usuario.h"

/**
*@class UsuarioMenor
*@brief Clase derivada de Usuario
*
*
*/
class UsuarioMenor : public Usuario 
{

    public:
        /**
        *Constructor de la clase UsuarioMenor
        *@param string nombre
        *@param string clave
        *@param int edad
        *
        */
        UsuarioMenor(std::string, std::string, int);

        /**
        * Método override de la clase Usuario
        *
        */
        void visita(IVisitor*);
};


#endif