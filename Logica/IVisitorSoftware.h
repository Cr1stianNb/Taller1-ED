#ifndef IVISITOR_SOFTWARE_H
#define IVISITOR_SOFTWARE_H

class Juego;
class Navegador;
class Ofimatica;
class Produccion;
class Seguridad;
class Social;
class Usuario;
class IVisitorSoftware
{
    public:
        virtual void acepta(Juego& , Usuario*) = 0;
        virtual void acepta(Navegador& , Usuario*) = 0;
        virtual void acepta(Ofimatica& , Usuario*) = 0;
        virtual void acepta(Produccion& , Usuario*) = 0;
        virtual void acepta(Seguridad& , Usuario*) = 0;
        virtual void acepta(Social& , Usuario*) = 0;
        
};

#endif