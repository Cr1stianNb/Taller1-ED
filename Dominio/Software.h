#ifndef SOFTWARE
#define SOFTWARE
#include <string>
#include <vector>
#include "Usuario.h"
#include "../Logica/IVisitorSoftware.h"
#include <iostream>
using namespace std;



/**
*
*@class  Software
*@brief clase abstracta
*
*
*/
class Software 
{
    
    protected:
        std::string nombre;
        std::string developer;
        std::string clasificacion;
        std::vector<Usuario*>* listaUsuario;
        double precio;

    public:

        const static std::string E, A; // Define los tipos de clasificación de edad que puede tener los softwares derivados
        /**
        * Constructor copia 
        *@param Software software a copiar
        *
        */
        Software(const Software&);
        /**
         * Constructor de la clase Software
         * @param string nombre del software
         * @param string developer del software
         * @param string clasificación del software Software::A (Adult)o Software::E (Everyone)
         * 
        */
        Software(std::string, std::string, std::string, double);
        /**
         *@return nombre del software
         *
        */
        std::string getNombre();
        /**
         * @param ,developer del software
        */
        std::string getDeveloper();
        /**
         * @return clasificación del software
        */
        std::string getClasificacion();

        /**
         * @return vector<Usuario*> el puntero a la lista de usuarios que utilizan la aplicación
        */
        std::vector<Usuario*>* getListaUsuario();
        /**
         * @return precio del software
        */
        double getPrecio();
        /**
         * @brief elimina un usuariode la lista de usuarios 
         * @param string el nombre del usuario a eliminar
         * @return true si se elimina el usuario, false si no se elimino
        */
        bool eliminarUsuario(std::string);
        /**
         * @brief eliminar de los usuarios las aplicaciónes (sesiones abiertas) en la lista de usuarios
         * 
         * 
        */
        void eliminarAplicacionDeUsuarios();
        /**
         * @brief Agrega un usuario que haya iniciado sesión con el software
         * @param Usuario agrega un usuario a la lista de usuarios
        */
        bool agregarUsuario(Usuario*);

        /**
         * @brief Verifica si el usuario por parametro existe en la lista de Usuarios del software
         * @param string el nombre del usuario a verificar
         * @return true, si existe, false si no existe en la lista Usuarios
        */
        bool existeUsuario(string);
        /**
         * @return Usuario*
        */
        Usuario* getUsuario(std::string);
        /**
         * @brief Clona el objeto software, virtual para que cada subclase tenga que implementar el método
         * @return retorna el software copiado (nueva instancia)
        */
        virtual Software* clonar() const = 0;
        /**
         * @brief patrón visitor, abstracta para que las clases derivadas tengas que implementar el método
         * @param IVisitorSoftware Interfaz IVisitorSoftware
         * 
        */
        virtual void visita(IVisitorSoftware*) = 0;
        /**
         * @brief patrón visitor Método que acepta una sesión de un determinado Usuario
         * @param IVisitorSoftware, Interfaz 
         * @param Usuario usuario que accedera la sesión
        */
        virtual void accederSesion(IVisitorSoftware*, Usuario*) = 0;
};

#endif