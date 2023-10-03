#ifndef IVISITOR_SOFTWARE_H
#define IVISITOR_SOFTWARE_H

class Juego;
class Navegador;
class Ofimatica;
class Produccion;
class Seguridad;
class Social;

class IVisitorSoftware
{
    public:
        virtual void acepta(Juego) = 0;
        virtual void acepta(Navegador) = 0;
        virtual void acepta(Ofimatica) = 0;
        virtual void acepta(Produccion) = 0;
        virtual void acepta(Seguridad) = 0;
        virtual void acepta(Social) = 0;
        
};

#endif