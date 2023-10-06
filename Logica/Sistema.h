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
        void mostrarUsuarios();
        bool agregarAdmin(std::string, std::string, int, std::string);
        bool agregarUsuarioNormal(std::string, std::string, int, std::string);

          
        Usuario* getUsuario(std::string, std::string);
        Software* getSoftware(std::string);
        bool eliminarSoftwareSistema(Software*);
        // agregarsoft....
        bool verificarAcceso(std::string, std::string);
        bool isEmptySoftwares();
        bool isEmptyUsuarios();
        bool isEmptyRegistrosUsuario(std::string, std::string);
        bool existeSoftware(std::string);
        bool estaRegistroSoftware(std::string,std::string,std::string);
        int getTipoUsuario(std::string, std::string);
        // Agregar Software a la lista

        bool agregarJuego(std::string, std::string, std::string, double, std::string);
        bool agregarNavegador(std::string, std::string, std::string, double);
        bool agregarOfimatica(std::string, std::string, std::string, double);
        bool agregarProduccion(std::string , std::string, std::string, double , std::string);
        bool agregarSeguridad(std::string, std::string, std::string, double, std::string);
        bool agregarSocial(std::string, std::string, std::string, double);
        bool agregarSoftwareUsuario(std::string, std::string, std::string);
        bool eliminarSoftwareUsuario(std::string, std::string, std::string);
        bool eliminarSoftwareBiblioteca(std::string);
        bool eliminarUsuario(std::string);
        
        void eliminarSesionesDeUsuarios(std::string);
        void accederSoftware(std::string, std::string, std::string);

        int getEdadUsuario(std::string);
        std::string getNombresUsuarios();
        std::string getNombresSoftwaresUsuario(std::string, std::string);
        std::string getNombresSoftwares();
        std::vector<std::string>* getNombresUsuariosSoftware(std::string);
    
        


};

#endif