#include "Navegador.h"


Navegador::Navegador(std::string nombre, std::string developer, std::string clasificacion, double precio):
    Software(nombre, developer, clasificacion, precio){};

std::string Navegador::getHistorial()
{
    std::string text="Listado de tú historial en este navegador: \n"; 
    for(int i=contador-1; i>=0;i++)
    {
        text += "- Historial N°" + std::to_string(i) + ": \n";
        text += "  " + this->historial[i];
    }
    return text;
};