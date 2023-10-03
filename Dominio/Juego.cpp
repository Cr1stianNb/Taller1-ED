#include "Juego.h"

Juego::Juego(const Juego& otro): Software(otro.nombre, otro.developer, otro.clasificacion, otro.precio)
{
    this->genero = otro.genero;
};

Juego::Juego(std::string nombre, std::string developer, std::string clasificacion, double precio, std::string genero) : Software(nombre, developer, clasificacion, precio)
{
    this->genero = genero;
    };

std::string Juego::getGenero(){return this->genero;}

Juego *Juego::clonar() const
{
    return new Juego(*this);
}
void Juego::visita(IVisitorSoftware *visitorSoftware){visitorSoftware->acepta(*this);};