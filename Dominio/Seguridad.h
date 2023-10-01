#ifndef SEGURIDAD
#define SEGURIDAD
#include "Software.h"

class Seguridad : public Software
{
    private:
        static std::string tiposMalware[];
        std::string tipo;

    public:
        Seguridad(std::string, std::string, std::string, double, std::string);
        std::string getTipo();
        

};


#endif