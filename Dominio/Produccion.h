#ifndef PRODUCCION_H
#define PRODUCCION_H
#include "Software.h"

class Produccion : public Software
{
    private:
        std::string tipoSolucion;
        
    public:
        const static std::string VIDEO, MUSICA, STREAMING, FOTOS;
        Produccion(const Produccion&);
        Produccion(std::string , std::string, std::string, double , std::string);
        std::string getTipoSolucion();
        Produccion* clonar() const override;
        virtual void visita(IVisitorSoftware*);
        static bool verificarSolucion(std::string);
};




#endif