#ifndef USUARIO_1
#define USUARIO_1
#include <string>


class Usuario
{
    private:
        std::string nombre;
        std::string clave;
        int edad;
        // ListaSoftware* ListaSoftware;
    public:
        const static int ADMINISTRADOR=1, USUARIO=2, INFANTIL=3;

        Usuario(std::string, std::string, int);
        std::string getNombre();
        std::string getClave();
        int getEdad();
};

#endif