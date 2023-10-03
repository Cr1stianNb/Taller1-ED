#ifndef SISTEMA
#define SISTEMA
#include <vector>
#include "../Dominio/Usuario.h"
#include "../Dominio/Software.h"

class Sistema
{
    private:
        std::vector<Usuario*>* listaUsuarios;
        std::vector<Software*>* listaSoftwares;

        Usuario* getUsuario(std::string, std::string);
        Software* getSoftware(std::string);
        bool eliminarSoftwareSistema(Software*);

    public:
        Sistema();
        void mostrarUsuarios();
        bool agregarAdmin(std::string, std::string, int);
        bool agregarUsuarioNormal(std::string, std::string, int);
        // agregarsoft....
        bool verificarAcceso(std::string, std::string);
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

        std::string getNombresSoftwares();
    
        


};

#endif