#ifndef JUEGO
#define JUEGO
#include "Software.h"
#include <string>

class Juego : public Software
{
    private:
        std::string genero;
    public:
        Juego(std::string, std::string, std::string, double, std::string);
        std::string getGenero();
};



#endif