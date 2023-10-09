#ifndef USUARIO_1
#define USUARIO_1
#include <string>
#include <vector>
#include "../Logica/IVisitorUsuario.h"

// Forward declaration (evitar referencias circulares)
class Software;


/**
 * @class Usuario
 * @brief Clase que representa a todos los usuarios del programa
 * 
 * Clase abstracta 
*/
class Usuario
{
    protected:
        std::string nombre; // Nombre del usuario
        std::string clave; //  clave del usuario
        int edad; // edad del usuario
        std::string correo; // correo del usuario
        std::vector<Software*>* listaSoftware; // Lista de software que el usuario se ha registrados
    public:
        const static int ADMINISTRADOR=1, USUARIO_MAYOR=2, USUARIO_MENOR=3; // Constantes de clase: Define los tipos de usuario en forma de enteros

        /** Constructor de la clase Usuario
         * @param string nombre 
         * @param string clave 
         * @param int edad 
         * @param string correo
        */
        Usuario(std::string, std::string, int, std::string); 
        /**
         * @brief constructor copia
         * @param Instancia a copiar
        */
        Usuario(const Usuario&);

        /**
         * @return retorna la lista de software* del usuario
         * 
        */
        std::vector<Software*>* getListaSoftware();
        /**
         * @brief Encuentra entre la lista de software, el software con un determinado nombre , nullptr si no se encontro en la lista
         * 
         * @return devuelve el software*
        */
        Software* getSoftware(std::string);
        

        std::string getNombre();
        std::string getClave();
        int getEdad();

        /**
         * 
         * @brief agrega un software en la lista de software del usuario
         * @param Software, software a agregar
         * @return true si se  pudo agregar, false si ya existe el software en la lista
        */
        bool agregarSoftware(Software*);
        /**
         * @brief Eliminar un software de la lista de software del usuario
         * @param Software a eliminar
         * @return true si se elimino correctamente, false si no se encontro el software en la lista
        */
        bool eliminarSoftware(Software*);
        /**
         * @brief Patron visitor 
         * método abstracto, obliga a implementar el método en cada una de sus clases derivadas, permitiendo polimorfismo sin depender del casteo
        */
        virtual void visita(IVisitor*) = 0;
};

#endif