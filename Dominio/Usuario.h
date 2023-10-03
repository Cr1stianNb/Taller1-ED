#ifndef USUARIO_1
#define USUARIO_1
#include <string>
#include <vector>
#include "../Logica/IVisitorUsuario.h"

class Software;

class Usuario
{
    private:
        std::string nombre;
        std::string clave;
        int edad;
        std::vector<Software*>* listaSoftware;
    public:
        const static int ADMINISTRADOR=1, USUARIO_MAYOR=2, USUARIO_MENOR=3;

        Usuario(std::string, std::string, int);
        Usuario(const Usuario&);

        std::vector<Software*>* getListaSoftware();
        std::string getNombre();
        std::string getClave();
        int getEdad();

        bool agregarSoftware(Software*);
        bool eliminarSoftware(Software*);
        // patron visitor 
        virtual void visita(IVisitor*) = 0;
};

#endif