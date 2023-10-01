#include "Ofimatica.h"

Ofimatica::Ofimatica(std::string nombre, std::string developer, std::string clasificacion, double precio):
    Software(nombre, developer, clasificacion, precio){};


int Ofimatica::getCantArchivo(){return this->cantArchivos;};


