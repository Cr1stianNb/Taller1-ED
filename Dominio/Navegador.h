#ifndef NAVEGADOR
#define NAVEGADOR
#include "Software.h"

class Navegador : public Software
{
    private:
        int contador;
        std::vector<std::string>* historial;
    public:
        Navegador(const Navegador&);
        Navegador(std::string, std::string, std::string, double);
        std::string getHistorial();
        Navegador* clonar() const override;

};


#endif