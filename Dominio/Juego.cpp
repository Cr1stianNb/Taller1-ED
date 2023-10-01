#include "Juego.h"

Juego::Juego(std::string nombre, std::string developer, std::string clasificacion, double precio, std::string genero):
    Software(nombre, developer, clasificacion, precio)
    {
        this->genero = genero;
    };

std::string Juego::getGenero(){return this->genero;};