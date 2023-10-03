#ifndef JUEGO_H
#define JUEGO_H
#include "Software.h"

const std::string GENEROS[10] {"FPS", "MMO", "PUZZLE", "PLATAFORMERO", "RPG", "HORROR", "ESTRATEGIA", "DEPORTES", "ACCIÓN", "ADVENTURAS"};

class Juego : public Software
{
    public:
        std::string genero;
    public:
        Juego(const Juego&);
        Juego(std::string, std::string, std::string, double, std::string);
        std::string getGenero();

        Juego* clonar() const override;
        virtual void visita(IVisitorSoftware*);
        static bool verificarGenero(std::string );
};



#endif