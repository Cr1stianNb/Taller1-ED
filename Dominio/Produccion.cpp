#include "Produccion.h"



Produccion::Produccion(std::string nombre, std::string developer, std::string clasificacion, double precio, std::string tipoSolucion):
    Software(nombre, developer, clasificacion, precio)
    {
        this->tipoSolucion = tipoSolucion;
    };

std::string Produccion::getTipoSolucion(){return this->tipoSolucion;};