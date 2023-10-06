#ifndef SEGURIDAD_H
#define SEGURIDAD_H
#include "Software.h"




class Seguridad : public Software
{
    private:
        
        static std::string tiposMalware[];
        std::string tipo;

    public:
        const static std::string RANSOMWARE, SPYWARE, BOTNETS, ROOTKITS, GUSANOS, TROYANOS;
        Seguridad(const Seguridad&);
        Seguridad(std::string, std::string, std::string, double, std::string);
        std::string getTipo();
        std::string getInforme(Usuario*);
        std::string getPorcentaje(Usuario*);

        Seguridad* clonar() const override;
        virtual void visita(IVisitorSoftware*);
        virtual void accederSesion(IVisitorSoftware*, Usuario*);
        static bool verificarMalware(std::string);

};


#endif