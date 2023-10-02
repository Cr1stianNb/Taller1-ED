#pragma once
#include "Software.h"
Software::Software(const Software& otro)
{
     this->nombre = otro.nombre;
    this->developer = otro.developer;
    this->clasificacion  = otro.clasificacion;
    this->precio = otro.precio;
}
Software::Software(std::string nombre, std::string developer, std::string clasificacion, double precio)
{
    this->nombre = nombre;
    this->developer = developer;
    this->clasificacion  = clasificacion;
    this->precio = precio;
};


std::string Software::getNombre(){return this->nombre;};
std::string Software::getDeveloper(){return this->developer;};
std::string Software::getClasificacion(){return this->clasificacion;};
double Software::getPrecio(){return this->precio;};
void Software::hacerAlgo()
{
    std::cout << "Escribo alfo por mensaje";
}

Software *Software::clonar() const
{
    return new Software(*this);
}
