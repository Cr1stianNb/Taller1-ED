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
        virtual void acepta(Juego& , Usuario*);
        virtual void acepta(Navegador& , Usuario*);
        virtual void acepta(Ofimatica& , Usuario*);
        virtual void acepta(Produccion& , Usuario*);
        virtual void acepta(Seguridad& , Usuario*);
        virtual void acepta(Social& , Usuario*);
        string getTipoSoftware();
};





#endif