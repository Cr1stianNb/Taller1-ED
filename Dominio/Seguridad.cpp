#include "Seguridad.h"



const std::string Seguridad::RANSOMWARE = "Ransomware", Seguridad::SPYWARE = "Spyware", Seguridad::BOTNETS = "Botnets", Seguridad::ROOTKITS = "Rootkits", Seguridad::GUSANOS = "Gusanos", Seguridad::TROYANOS = "Troyanos";

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
void Seguridad::visita(IVisitorSoftware *visitorSoftware){visitorSoftware->acepta(*this);}

bool Seguridad::verificarMalware(std::string solucion)
{
    if (solucion == Seguridad::RANSOMWARE) 
    {
        return true;
    } 
    else if (solucion == Seguridad::SPYWARE) 
    {
        return true;
    } else if (solucion == Seguridad::BOTNETS) 
    {
        return true;
    }
    else if (solucion == Seguridad::GUSANOS) 
    {
        return true;
    } 
    else if (solucion == Seguridad::TROYANOS) 
    {
        return true;
    }
    else if (solucion == Seguridad::ROOTKITS)
    {
        return true;
    }
    return false;
};