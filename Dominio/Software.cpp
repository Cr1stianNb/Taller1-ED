#pragma once
#include "Software.h"
Software::Software(std::string nombre, std::string developer, std::string clasificacion, double precio )
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