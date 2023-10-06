#include "Seguridad.h"
#include "../Logica/VisitorSoftware.h"


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

std::string Seguridad::getTipo(){return this->tipo;}


std::string Seguridad::getInforme(Usuario* usuario)
{
    int contadorMalware = 0;
    std::string texto = "";
    std::vector<Software*>* listaSoftware = usuario->getListaSoftware();
    VisitorSoftware* visitor = new VisitorSoftware();
    for(int i = 0; i<listaSoftware->size(); i++)
    {
        Software* software = listaSoftware->at(i);
        software->visita(visitor);
        if(visitor->getTipoSoftware() == VisitorSoftware::SOCIAL) 
        {
            Seguridad* seg = dynamic_cast<Seguridad*>(software);
            if(seg->getTipo() == this->tipo)
            {
                contadorMalware++;
            }
        }
    }
    texto = "Tienes " + std::to_string(contadorMalware) + " malwares de tipo: " + this->tipo + " que estan en tus registros: ( " + usuario->getNombre() + ")";
    return texto;
}
std::string Seguridad::getPorcentaje(Usuario* usuario)
{
    int contadorTotal = 0;
    int contadorMalware = 0;
    std::string texto = "";
    std::vector<Software*>* listaSoftware = usuario->getListaSoftware();
    VisitorSoftware* visitor = new VisitorSoftware();
    for(int i = 0; i<listaSoftware->size(); i++)
    {
        Software* software = listaSoftware->at(i);
        software->visita(visitor);
        if(visitor->getTipoSoftware() == VisitorSoftware::SOCIAL)
        {
            contadorTotal++;
            Seguridad* seg = dynamic_cast<Seguridad*>(software);
            if(seg->getTipo() == this->tipo)
            {
                contadorMalware++;
            }
        }
    }
    if(contadorTotal == 0) 
    {
        texto = "No tienes has accedido a ninguna aplicación de seguridad, lo cual es raro, por que estas acá en: " + this->nombre;
        return texto;
    }
    double porcentaje = (contadorMalware/contadorTotal)*100;
    texto = "Tienes " + std::to_string(porcentaje) + "'%' de malwares de tipo: " + this->tipo + " que estan en tus registros: ( " + usuario->getNombre() + ")";
    return texto;
};

Seguridad* Seguridad::clonar() const {
    return new Seguridad(*this);
}
void Seguridad::visita(IVisitorSoftware *visitorSoftware){visitorSoftware->acepta(*this, nullptr);}

void Seguridad::accederSesion(IVisitorSoftware * visitorSoftware, Usuario * usuario)
{
    visitorSoftware->acepta(*this, usuario);
};

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