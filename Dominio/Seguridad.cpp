#include "Seguridad.h"


Seguridad::Seguridad(std::string nombre, std::string developer, std::string clasificacion, double precio, std::string tipo):
    Software(nombre, developer, clasificacion, precio)
    {
        this->tipo = tipo;
    };

std::string Seguridad::getTipo(){return this->tipo;};

