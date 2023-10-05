#pragma once
#include "Software.h"

/// @brief 
const std::string Software::E = "Everyone", Software::A = "Adult";



Software::Software(const Software& otro)
{
    this->nombre = otro.nombre;
    this->developer = otro.developer;
    this->clasificacion  = otro.clasificacion;
    this->precio = otro.precio;
    this->listaUsuario = new std::vector<Usuario*>(0);
}
Software::Software(std::string nombre, std::string developer, std::string clasificacion, double precio)
{
    this->nombre = nombre;
    this->developer = developer;
    this->clasificacion  = clasificacion;
    this->precio = precio;
    this->listaUsuario = new std::vector<Usuario*>(0);
};


std::string Software::getNombre(){return this->nombre;};
std::string Software::getDeveloper(){return this->developer;};
std::string Software::getClasificacion(){return this->clasificacion;}
std::vector<Usuario*> *Software::getListaUsuario()
{
    return this->listaUsuario;
};
double Software::getPrecio(){return this->precio;}

/*
Software *Software::clonar() const
{
    return new Software(*this);
};
*/

void Software::eliminarAplicacionDeUsuarios()
{

    for(int i=0; i<this->listaUsuario->size();i++)
    {
        listaUsuario->at(i)->eliminarSoftware(this);
    }

};

bool Software::agregarUsuario(Usuario *usuario)
{
    Usuario* us = this->getUsuario(usuario->getNombre());
    if(us != nullptr) return false;
    listaUsuario->push_back(us);
    return true;
};
Usuario *Software::getUsuario(std::string nombre)
{
    for(int i=0; i<listaUsuario->size();i++)
    {
        if(listaUsuario->at(i)->getNombre() == nombre)
        {
            return listaUsuario->at(i);
        }
    }
    return nullptr;
};

