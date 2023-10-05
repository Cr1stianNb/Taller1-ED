#include "Produccion.h"



const std::string  Produccion::VIDEO = "Video", Produccion::MUSICA = "Música", Produccion::STREAMING = "Streaming", Produccion::FOTOS = "Fotos";


Produccion::Produccion(const Produccion& otro): Software(otro.nombre, otro.developer, otro.clasificacion, otro.precio)
{
    this->tipoSolucion = otro.tipoSolucion;
    this->cantidadHoras = otro.cantidadHoras;
};
Produccion::Produccion(std::string nombre, std::string developer, std::string clasificacion, double precio, std::string tipoSolucion):
    Software(nombre, developer, clasificacion, precio)
    {
        this->tipoSolucion = tipoSolucion;
        this->cantidadHoras = 0;
    };

std::string Produccion::getTipoSolucion(){return this->tipoSolucion;}

double Produccion::getCantidadHoras()
{
    return this->cantidadHoras;
}

void Produccion::agregarCantidadHoras(double horas)
{
    this->cantidadHoras += horas;
}

Produccion* Produccion::clonar() const
{
    return new Produccion(*this);
}
void Produccion::visita(IVisitorSoftware *visitorSoftware){visitorSoftware->acepta(*this, nullptr);}

void Produccion::accederSesion(IVisitorSoftware * visitorSoftware, Usuario * usuario)
{
    visitorSoftware->acepta(*this, usuario);
};

bool Produccion::verificarSolucion(std::string solucion)
{
    if (solucion == Produccion::VIDEO) 
    {
        return true;
    } 
    else if (solucion == Produccion::MUSICA) 
    {
        return true;
    } else if (solucion == Produccion::STREAMING) 
    {
        return true;
    }
    else if (solucion == Produccion::FOTOS)
    {
        return true;
    }
    return false;
};