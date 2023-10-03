#ifndef VISITOR_SOFTWARE_H
#define VISITOR_SOFTWARE_H
#include "IVisitorSoftware.h"
#include <string>
using namespace std;

class VisitorSoftware : public IVisitorSoftware
{
    private:
        string tipoSoftware;
    public:
    
        static string JUEGO;
        static string NAVEGADOR;
        static string OFIMATICA;
        static string PRODUCCION;
        static string SEGURIDAD;
        static string SOCIAL;
        VisitorSoftware();
        ~VisitorSoftware();
        virtual void acepta(Juego);
        virtual void acepta(Navegador);
        virtual void acepta(Ofimatica);
        virtual void acepta(Produccion);
        virtual void acepta(Seguridad);
        virtual void acepta(Social);
        string getTipoSoftware();
};





#endif