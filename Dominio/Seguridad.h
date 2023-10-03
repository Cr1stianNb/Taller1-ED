#ifndef SEGURIDAD_H
#define SEGURIDAD_H
#include "Software.h"


const std::string MALWARES[6] {"Ransomware", "Spyware", "botnets", "rootkits", "gusanos", "troyanos"};

class Seguridad : public Software
{
    private:
        static std::string tiposMalware[];
        std::string tipo;

    public:
        Seguridad(const Seguridad&);
        Seguridad(std::string, std::string, std::string, double, std::string);
        std::string getTipo();
        Seguridad* clonar() const override;
        virtual void visita(IVisitorSoftware*);

};


#endif