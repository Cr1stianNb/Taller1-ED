#include "Seguridad.h"

Seguridad::Seguridad(const Seguridad& otro): Software(otro.nombre, otro.developer, otro.clasificacion, otro.precio)
{
    this->precio = otro.precio;
};

Seguridad::Seguridad(std::string nombre, std::string developer, std::string clasificacion, double precio, std::string tipo):
    Software(nombre, developer, clasificacion, precio)
    {
        this->tipo = tipo;
    };

std::string Seguridad::getTipo(){return this->tipo;};

Seguridad* Seguridad::clonar() const {
    return new Seguridad(*this);
}
void Seguridad::visita(IVisitorSoftware *visitorSoftware){visitorSoftware->acepta(*this);};