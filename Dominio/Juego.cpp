#include "Juego.h"

Juego::Juego(const Juego& otro): Software(otro.nombre, otro.developer, otro.clasificacion, otro.precio)
{
    this->genero = otro.genero;
    this->horasJugadas = otro.horasJugadas;
};

Juego::Juego(std::string nombre, std::string developer, std::string clasificacion, double precio, std::string genero) : Software(nombre, developer, clasificacion, precio)
{
    this->genero = genero;
    this->horasJugadas = 0;
    };

std::string Juego::getGenero(){return this->genero;}

double Juego::getHorasJugadas()
{
    return this->horasJugadas;
};

void Juego::agregarHorasJugadas(double cantidadHoras)
{
    this->horasJugadas += cantidadHoras;
};

Juego *Juego::clonar() const
{
    return new Juego(*this);
}
void Juego::visita(IVisitorSoftware *visitorSoftware){visitorSoftware->acepta(*this, nullptr);}

bool Juego::verificarGenero(std::string genero)
{
    for(int i=0; i<10;i++)
    {
        if(GENEROS[i] == genero)
        {
            return true;
        }
    }
    return false;
}
void Juego::accederSesion(IVisitorSoftware * visitorSoftware, Usuario * usuario)
{
    visitorSoftware->acepta(*this, usuario);
};