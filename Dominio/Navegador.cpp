#include "Navegador.h"

Navegador::Navegador(const Navegador& otro): Software(otro.nombre, otro.developer, otro.clasificacion, otro.precio)
{
    contador = 0;
    this->historial = new vector<string>(0);
};
Navegador::Navegador(std::string nombre, std::string developer, std::string clasificacion, double precio):Software(nombre, developer, clasificacion, precio)
{
    contador = 0;
    this->historial = new vector<string>(0);
};

std::string Navegador::getHistorial()
{
    std::string text="Listado de tu historial en este navegador: \n"; 

    for(int i=(contador-1); i>=0;i--)
    {
        text += "  -"+ std::to_string(i+1) + " " + this->historial->at(i) + "\n";
    }
    return text;
}
void Navegador::agregarPagina(std::string pagina)
{
    if(this->historial->size() >= 10)
    {
        historial->erase(historial->begin());
        historial->push_back(pagina);
        contador = 10;
    }
    else 
    {
        historial->push_back(pagina);
        contador++;
        
    }

};

Navegador* Navegador::clonar() const
{
    return new Navegador(*this);
}
void Navegador::visita(IVisitorSoftware *visitorSoftware){visitorSoftware->acepta(*this, nullptr);}

void Navegador::accederSesion(IVisitorSoftware * visitorSoftware, Usuario * usuario)
{
    visitorSoftware->acepta(*this, usuario);
};