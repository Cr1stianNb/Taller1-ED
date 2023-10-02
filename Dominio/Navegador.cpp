#include "Navegador.h"

Navegador::Navegador(const Navegador& otro): Software(otro.nombre, otro.developer, otro.clasificacion, otro.precio)
{
    this->contador = otro.precio;
    this->historial = new vector<string>(0);
};
Navegador::Navegador(std::string nombre, std::string developer, std::string clasificacion, double precio):Software(nombre, developer, clasificacion, precio)
{
    this->contador = 0;
    this->historial = new vector<string>(0);
};

std::string Navegador::getHistorial()
{
    std::string text="Listado de tú historial en este navegador: \n"; 
    for(int i=contador-1; i>=0;i++)
    {
        text += "- Historial N°" + std::to_string(i) + ": \n";
        text += "  " + this->historial->at(i);
    }
    return text;
};

Navegador* Navegador::clonar() const
{
    return new Navegador(*this);
};