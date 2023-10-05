#ifndef PRODUCCION_H
#define PRODUCCION_H
#include "Software.h"

class Produccion : public Software
{
    private:
        std::string tipoSolucion;
        double cantidadHoras;
    public:
        const static std::string VIDEO, MUSICA, STREAMING, FOTOS;
        Produccion(const Produccion&);
        Produccion(std::string , std::string, std::string, double , std::string);
        std::string getTipoSolucion();
        double getCantidadHoras();
        void agregarCantidadHoras(double);
        Produccion* clonar() const override;
        virtual void visita(IVisitorSoftware*);
        virtual void accederSesion(IVisitorSoftware*, Usuario*);
        static bool verificarSolucion(std::string);
};




#endif