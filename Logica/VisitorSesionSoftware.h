#ifndef VISITOR_SESION_SOFTWARE_H
#define VISITOR_SESION_SOFTWARE_H
#include "IVisitorSoftware.h"

#include "../Dominio/Juego.h"
#include "../Dominio/Navegador.h"
#include "../Dominio/Ofimatica.h"
#include "../Dominio/Produccion.h"
#include "../Dominio/Social.h"
#include "../Dominio/Seguridad.h"
#include <string>
using namespace std;

class Sistema;

class VisitorSesionSoftware : public IVisitorSoftware
{
    private:
        Sistema* sistema;
    public:
        VisitorSesionSoftware(Sistema*);
        ~VisitorSesionSoftware();
        virtual void acepta(Juego&, Usuario*);
        virtual void acepta(Navegador&, Usuario*);
        virtual void acepta(Ofimatica&, Usuario*);
        virtual void acepta(Produccion&, Usuario*);
        virtual void acepta(Seguridad&, Usuario*);
        virtual void acepta(Social&, Usuario*);
        


};


#endif