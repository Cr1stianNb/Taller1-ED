#ifndef SISTEMA
#define SISTEMA
#include <vector>
#include "../Dominio/Usuario.h"
#include "../Dominio/Software.h"

/**
 * @class Clase que implementa todos los métodos para que el programa cumpla con los requerimientos
 * Contiene a todos los usuarios y softwares
*/
class Sistema
{
    private:
        std::vector<Usuario*>* listaUsuarios; // Lista de punteros de usuarios
        std::vector<Software*>* listaSoftwares; // Lista de punteros de softwares
    public:
        // Constructor de la clase Sistema
        Sistema();
        // Destructor de la clase Sistema
        ~Sistema();
        /**
         * muestra por el terminal los nombres de los usuarios en el sistema
        */
        void mostrarUsuarios();
        /**
         * Agrega un administrador en la lista Usuario
         * @param string nombre
         * @param string clave
         * @param int edad
         * @param string correo
         * @return true si se agrego, false lo contrario
        */
        bool agregarAdmin(std::string, std::string, int, std::string);
        /**
         * crea un UsuarioNormal y lo agrega a la lista Usuario
         * @param string nombre
         * @param string clave
         * @param int edad
         * @param correo
         * @return true si se agrego, false lo contrario
        */
        bool agregarUsuarioNormal(std::string, std::string, int, std::string);

        /**
         * Obtener el puntero de un usuario con un nombre y clave
         * @param string nombre del usuario
         * @param string clave del usuario
         * @return puntero a Usuario 
        */
        Usuario* getUsuario(std::string, std::string);
        /**
         * Obtener el ´puntero de un software mediante nombre
         * @param string nombre del software
         * @return Puntero a software 
        */
        Software* getSoftware(std::string);

        /**
         * Elimina un software en la lista Software
         * @param Software software a eliminar
         * @return true si se elimino del sistema, false lo contrario
        */
        bool eliminarSoftwareSistema(Software*);
        /**
         * Verifica si el nombre y clave por parametro existe en el sistema
         * @param string nombre a verificar
         * @param string clave a verificar
         * @return true si el nombre y clave existe en el sistema, false lo contrario
        */
        bool verificarAcceso(std::string, std::string);
        /**
         * Verifica si la lista software esta vacia
         * @return true si esta vacia, false lo contrario
        */
        bool isEmptySoftwares();
        /**
         * Verifica si la lista usuario esta vacia
         * @return true si esta vacia la lista, false lo contrario
         *  
        */
        bool isEmptyUsuarios();
        /**
         * Verifica si un usuario contiene registros de software
         * @param string nombre del usuario
         * @param string clave del usuario
         * @return true si existen registros en el usuario, false si no ha accedido a ningún software
        */
        bool isEmptyRegistrosUsuario(std::string, std::string);
        /**
         * Verifica si el nombre que se envia por parametro existe en la lista Software
         * @param string nombre del software
         * @return true si existe el software en la lista Software, false lo contrario
        */
        bool existeSoftware(std::string);
        /**
         * Verifica si el registro de un software existe en un usuario determinado
         * @param string nombre del usuario
         * @param string clave del usuario
         * @param string nombre del software a verificar si esta en los registros del usuario
         * @return true si el software existe en los registros del usuario, false lo contrario
        */
        bool estaRegistroSoftware(std::string,std::string,std::string);
        /**
         * Retorna un entero que representa el tipo de usuario a verificar
         * @param string nombre del usuario
         * @param string clave del usuario
         * @return retorna Usuario::ADMINISTRADOR o Usuario::USUARIO_MAYOR o Usuario::USUARIO_MENOR, si no es ninguna de los anteriores retorna -1
        */
        int getTipoUsuario(std::string, std::string);
        
        /**
         * Crea una instancia de Juego y lo agrega a la lista Software
         * @param string nombre del juego
         * @param string developer 
         * @param string clasificación
         * @param double precio
         * @param string genero del juego
         * @return true si se agrego el Juego, false lo contrario
        */
        bool agregarJuego(std::string, std::string, std::string, double, std::string);
          
        /**
         * Crea una instancia de Navegador y lo agrega a la lista Software
         * @param string nombre del Navegador
         * @param string developer 
         * @param string clasificación
         * @param double precio
         * @return true si se agrego el Navegador, false lo contrario
        */
        bool agregarNavegador(std::string, std::string, std::string, double);
          
        /**
         * Crea una instancia de Ofimatica y lo agrega a la lista Software
         * @param string nombre del Ofimatica
         * @param string developer 
         * @param string clasificación
         * @param double precio
         * @return true si se agrego el Ofimatica, false lo contrario
        */
        bool agregarOfimatica(std::string, std::string, std::string, double);
          
        /**
         * Crea una instancia de Produccion y lo agrega a la lista Software
         * @param string nombre del Produccion
         * @param string developer 
         * @param string clasificación
         * @param double precio
         * @param string tipo de solución
         * @return true si se agrego el Produccion, false lo contrario
        */
        bool agregarProduccion(std::string , std::string, std::string, double , std::string);
          
        /**
         * Crea una instancia de Seguridad y lo agrega a la lista Software
         * @param string nombre del Seguridad
         * @param string developer 
         * @param string clasificación
         * @param double precio
         * @param string tipo de malware
         * @return true si se agrego el objeto Seguridad, false lo contrario
        */
        bool agregarSeguridad(std::string, std::string, std::string, double, std::string);
          
        /**
         * Crea una instancia de Social y lo agrega a la lista Software
         * @param string nombre del Social
         * @param string developer 
         * @param string clasificación
         * @param double precio
         * @return true si se agrego la app Social, false lo contrario
        */
        bool agregarSocial(std::string, std::string, std::string, double);
          
        /**
         * Agrega una copia del un software a un determinado usuario
         * Además de asociar el usuario con el software original
         * @param string nombre del usuario
         * @param string clave del usuario
         * @param string nombre del software
         * @return true si se agrego la copia al usuario, false si no existe el usuario o el software
        */
        bool agregarSoftwareUsuario(std::string, std::string, std::string);

        /**
         * Elimina la copia creada de un determindo software de un usuario
         * @param string nombre del usuario
         * @param string clave del usuario
         * @param string nombre del software a eliminar
         * @return true si se pudo eliminar, false lo contrario o no se encontro el usuario o el software
        */
        bool eliminarSoftwareUsuario(std::string, std::string, std::string);

        /**
         * Elimina un software de la lista Software, además de eliminar todas las copias de todos los usuarios
         * @param string nombre del software a eliminar
         * @return true si se pudo eliminar el software, false lo contrario
        */
        bool eliminarSoftwareBiblioteca(std::string);
        /**
         * Elimina un usuario de la lista Usuario, además de eliminar todas las referencias en los software
         * @param string nombre del usuario
         * @return true, si se elimino el usuario, false lo contrario
        */
        bool eliminarUsuario(std::string);
        
        /**
         * Elimina las sesiones creadas por los usuarios de un software
         * @param string el nombre del software
         * 
        */
        void eliminarSesionesDeUsuarios(std::string);

        /**
         * Método que comienza el acceso de un software a un usuario.
         * @param string nombre del usuario
         * @param string clave del usuario
         * @param string nombre del software
        */
        void accederSoftware(std::string, std::string, std::string);

        /**
         * Devuelve la edad de un usuario a partir del nombre
         * @param string nombre del usuario
         * @return la edad del usuario, -1 si no se encontro el usuario
        */
        int getEdadUsuario(std::string);
        /**
         * Devuelve el listado de nombres de usuarios que existen en el sistema
         * @return el listado de nombres en string
        */
        std::string getNombresUsuarios();
        /**
         * El listado de los nombres de los softwares  que un usuario ha iniciado  sesión
         * @param string nombre del usuario
         * @param string clave del usuario 
        */
        std::string getNombresSoftwaresUsuario(std::string, std::string);
        /**
         * El listado el listado de nombres de los softwares que existen en el sistema
         * @return string 
        */
        std::string getNombresSoftwares();
        /**
         * Devuelve un vector de string con los nombres de los usuarios que han iniciado sesión en un determinado software
         * @param string nombre del software
         * @return vector de string con los nombres de los usuarios
        */
        std::vector<std::string>* getNombresUsuariosSoftware(std::string);

        /** Verifica si el usuario tiene todos los registros*/
        bool tieneTodo(string, string);
};

#endif