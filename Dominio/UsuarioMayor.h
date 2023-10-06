#ifndef USUARIO_MAYOR_1
#define USUARIO_MAYOR_1
#include "Usuario.h"

/**
* @class UsuarioMayor
* @brief Clase derivada de Usuario
*/
class UsuarioMayor : public Usuario
{

    public:
        /**
        *
        *@param string 
        *@param string
        *@param int
        *@param string
        *
        */
        UsuarioMayor(std::string, std::string, int, std::string);
        
        /**
        *@brief método visita (patron visitor)
        *
        */
        virtual void visita(IVisitor*);
};

#endif