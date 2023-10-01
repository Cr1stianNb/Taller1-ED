#ifndef NAVEGADOR
#define NAVEGADOR
#include "Software.h"

class Navegador : public Software
{
    private:
        int contador;
        std::string historial[];
    public:
        Navegador(std::string, std::string, std::string, double);
        std::string getHistorial();

};


#endif