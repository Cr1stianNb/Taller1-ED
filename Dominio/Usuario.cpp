#pragma once
#include "Usuario.h"
#include <vector>

Usuario::Usuario(std::string nombre, std::string clave, int edad, std::string correo)
{
    this->nombre = nombre;
    this->clave = clave;
    this->edad = edad;
    this->correo = correo;
    this->listaSoftware = new std::vector<Software*>(0);
};

Usuario::Usuario(const Usuario& otro): nombre(otro.nombre), clave(otro.clave), edad(otro.edad)
{   
    this->listaSoftware = new std::vector<Software*>(0);
};

std::vector<Software *>* Usuario::getListaSoftware()
{
    return this->listaSoftware;
}

Software* Usuario::getSoftware(std::string nombreSoftware)
{
    for(int i=0; i<this->listaSoftware->size();i++)
    {
        if(listaSoftware->at(i)->getNombre() == nombreSoftware)
        {
            return listaSoftware->at(i);
        }
    }
    return nullptr;
}

std::string Usuario::getNombre() { return this->nombre; };
std::string Usuario::getClave(){return this->clave;};
int Usuario::getEdad(){return this->edad;}

bool Usuario::agregarSoftware(Software * software)
{
    this->listaSoftware->push_back(software);
    return true;
}
bool Usuario::eliminarSoftware(Software* software)
{
    bool elimina = false;
    for(int i=0; i<listaSoftware->size();i++)
    {
        if(software->getNombre() == listaSoftware->at(i)->getNombre())
        {
            listaSoftware->erase(listaSoftware->begin() + i);
            elimina = true;
        }
    }
    return elimina;
};
