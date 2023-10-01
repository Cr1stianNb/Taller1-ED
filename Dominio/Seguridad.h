#ifndef SEGURIDAD
#define SEGURIDAD
#include "Software.h"


const std::string MALWARES[6] {"Ransomware", "Spyware", "botnets", "rootkits", "gusanos", "troyanos"};

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