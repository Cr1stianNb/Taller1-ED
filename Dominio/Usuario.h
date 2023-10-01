#ifndef USUARIO_1
#define USUARIO_1
#include <string>
#include "../Logica/IVisitor.h"

class Usuario
{
    private:
        std::string nombre;
        std::string clave;
        int edad;
        // ListaSoftware* ListaSoftware;
    public:
        const static int ADMINISTRADOR=1, USUARIO_MAYOR=2, USUARIO_MENOR=3;

        Usuario(std::string, std::string, int);
        Usuario(const Usuario&);
        std::string getNombre();
        std::string getClave();
        int getEdad();

        // patron visitor 
        virtual void visita(IVisitor*) = 0;
};

#endif