#ifndef SISTEMA
#define SISTEMA
#include <vector>
#include "../Dominio/Usuario.h"
#include "../Dominio/Software.h"

class Sistema
{
    private:
        std::vector<Usuario> listaUsuarios;
        std::vector<Software> listaSoftwares;

    public:

        bool verificarAcceso(std::string, std::string);
        int getTipoUsuario(std::string, std::string);
        // Agregar Administrador a la lista
        // Agregar usuario a la lista 
        // Agregar menores  a la lista 
        // Agregar Software a la lista



};

#endif