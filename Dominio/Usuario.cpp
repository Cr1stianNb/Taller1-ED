#pragma once
#include "Usuario.h"

Usuario::Usuario(std::string nombre, std::string clave, int edad)
{
    this->nombre = nombre;
    this->clave = clave;
    this->edad = edad;
};

Usuario::Usuario(const Usuario& otro): nombre(otro.nombre), clave(otro.clave), edad(otro.edad){};

std::string Usuario::getNombre(){return this->nombre;};
std::string Usuario::getClave(){return this->clave;};
int Usuario::getEdad(){return this->edad;};
