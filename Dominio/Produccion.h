#ifndef PRODUCCION
#define PRODUCCION
#include "Software.h"

class Produccion : public Software
{
    private:
        std::string tipoSolucion;
        
    public:
        Produccion(std::string , std::string, std::string, double , std::string);
        std::string getTipoSolucion();

};




#endif