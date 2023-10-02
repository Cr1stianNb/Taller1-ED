#pragma once
#include "Usuario.h"
#include <vector>

Usuario::Usuario(std::string nombre, std::string clave, int edad)
{
    this->nombre = nombre;
    this->clave = clave;
    this->edad = edad;
    this->listaSoftware = new std::vector<Software*>(0);
};

Usuario::Usuario(const Usuario& otro): nombre(otro.nombre), clave(otro.clave), edad(otro.edad)
{   
    this->listaSoftware = new std::vector<Software*>(0);
};

std::string Usuario::getNombre(){return this->nombre;};
std::string Usuario::getClave(){return this->clave;};
int Usuario::getEdad(){return this->edad;}

bool Usuario::agregarSoftware(Software * software)
{
    this->listaSoftware->push_back(software);
    return true;
}
bool Usuario::eliminarSoftware(Software * software)
{
    this->listaSoftware->
    return false;
};
