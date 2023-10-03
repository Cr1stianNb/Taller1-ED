#include "Produccion.h"


Produccion::Produccion(const Produccion& otro): Software(otro.nombre, otro.developer, otro.clasificacion, otro.precio)
{
    this->tipoSolucion = otro.tipoSolucion;
};
Produccion::Produccion(std::string nombre, std::string developer, std::string clasificacion, double precio, std::string tipoSolucion):
    Software(nombre, developer, clasificacion, precio)
    {
        this->tipoSolucion = tipoSolucion;
    };

std::string Produccion::getTipoSolucion(){return this->tipoSolucion;}


Produccion* Produccion::clonar() const
{
    return new Produccion(*this);
}
void Produccion::visita(IVisitorSoftware *visitorSoftware){visitorSoftware->acepta(*this);};