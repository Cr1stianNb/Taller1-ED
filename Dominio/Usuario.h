#ifndef USUARIO
#define USUARIO
#include <string>


class Usuario
{
    private:
        std::string nombre;
        std::string clave;
        int edad;
        // ListaSoftware* ListaSoftware;
    public:
        Usuario(std::string, std::string, int);
        std::string getNombre();
        std::string getClave();
        int getEdad();
};



#endif