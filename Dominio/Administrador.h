#ifndef ADMINISTRADOR_1
#define ADMINISTRADOR_1
#include "Usuario.h"

class Administrador : public Usuario 
{
    private:
        bool accesoLog;

    public:
        Administrador(std::string, std::string, int);
        virtual void visita(IVisitor*);
};


#endif