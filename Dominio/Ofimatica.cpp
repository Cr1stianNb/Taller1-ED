#include "Ofimatica.h"


Ofimatica::Ofimatica(const Ofimatica& otro): Software(otro.nombre, otro.developer, otro.clasificacion, otro.precio){};

Ofimatica::Ofimatica(std::string nombre, std::string developer, std::string clasificacion, double precio):
    Software(nombre, developer, clasificacion, precio){};


int Ofimatica::getCantArchivo(){return this->cantArchivos;};

bool Ofimatica::agregarArchivo()
{
    this->cantArchivos++;
    return true;
};

bool Ofimatica::eliminarArchivo()
{
    this->cantArchivos--;
    return false;
}
Ofimatica *Ofimatica::clonar() const
{
    return new Ofimatica(*this);
};
