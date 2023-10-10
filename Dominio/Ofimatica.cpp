#include "Ofimatica.h"


Ofimatica::Ofimatica(const Ofimatica& otro): Software(otro.nombre, otro.developer, otro.clasificacion, otro.precio)
{
    cantArchivos = 0;
};

Ofimatica::Ofimatica(std::string nombre, std::string developer, std::string clasificacion, double precio):
    Software(nombre, developer, clasificacion, precio)
    {
        cantArchivos = 0;
    };


int Ofimatica::getCantArchivo(){return this->cantArchivos;};

bool Ofimatica::agregarArchivo()
{
    this->cantArchivos++;
    return true;
};

bool Ofimatica::eliminarArchivo()
{
    if(cantArchivos <= 0) return false;
    this->cantArchivos--;
    return true;
}
Ofimatica *Ofimatica::clonar() const
{
    return new Ofimatica(*this);
}
void Ofimatica::visita(IVisitorSoftware *visitorSoftware){visitorSoftware->acepta(*this, nullptr);}
void Ofimatica::accederSesion(IVisitorSoftware * visitorSoftware, Usuario * usuario)
{
    visitorSoftware->acepta(*this, usuario);
};