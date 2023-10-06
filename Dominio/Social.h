#ifndef SOCIAL_H
#define SOCIAL_H
#include "Software.h"

/**
 * @class Social , clase derivada de Software
*/
class Social : public Software
{
    private:
        std::vector<std::string>* listaAmigos;
        std::string nombreUsuario; // Nombre del usuario que inicio sesión

    public:
        /**
         * Constructor copia de la clase Social
         * @param Social, objeto a copiar
        */
        Social(const Social&);
        /**
         * Constructor de la clase Social
         * @param string nombre
         * @param string developer
         * @param string clasificación
         * @param double precio 
        */
        Social(std::string, std::string, std::string, double);
        /**
         * @brief devuelve el usuario que tiene sesión abierta con la aplicación
         * @return string, nombre del Usuario
        */
        std::string getNombreUsuario();
        /**
         * Cambia el nombre del usuario
        */
        void setNombreUsuario(std::string);
        /**
         * @return el nombre de todos los amigos que tiene el usuario 
        */
        std::string getNombresAmigos();
        /**
         * @brief agrega el nombre del amigo a la listaAmigos
         * @param string nombre del amigo
         * @return true si se agrego, false lo contrario
        */
        bool agregarAmigo(std::string);
        /**
         * @brief elimina un amigo por nombre
         * @param el nombre del amigo a eliminar
         * @return true si se elimino algún usuario, false lo constrario
        */
        bool eliminarAmigo(std::string);
        /**
         * @brief asocia el usuario que se registro en la aplicación
         * @param el nombre del usuario
         * 
        */
        void asociarUsuario(std::string);
        /**
         * @brief Clona el objeto social, instanciando un nuevo objeto
         * @return una instancia copia del objeto social
        */
        Social* clonar() const override;
        /**
         * @brief patrón visitor, método override de la clase padre
         * @param IVisitorSoftware Interfaz IVisitorSoftware
         * 
        */
        void visita(IVisitorSoftware*);
         /**
         * @brief patrón visitor Método que acepta una sesión de un determinado Usuario
         * @param IVisitorSoftware, Interfaz 
         * @param Usuario usuario que accedera la sesión
        */
        void accederSesion(IVisitorSoftware*, Usuario*);

};


#endif