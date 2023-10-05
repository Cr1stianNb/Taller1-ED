#ifndef OFIMATICA_H
#define OFIMATICA_H
#include "Software.h"

class Ofimatica : public Software
{
    private:
        int cantArchivos;

    public:
        Ofimatica(const Ofimatica&);
        Ofimatica(std::string, std::string, std::string, double);
        int getCantArchivo();
        bool agregarArchivo();
        bool eliminarArchivo();
        Ofimatica* clonar() const override;
        virtual void visita(IVisitorSoftware*);
        virtual void accederSesion(IVisitorSoftware*, Usuario*);
};




#endif