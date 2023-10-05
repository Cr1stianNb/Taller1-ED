#ifndef SOCIAL_H
#define SOCIAL_H
#include "Software.h"

class Social : public Software
{
    private:
        std::vector<Usuario*> listaAmigos;

    public:
        Social(const Social&);
        Social(std::string, std::string, std::string, double);
        Usuario* getAmigo(std::string);
        bool agregarAmigo(std::string);
        bool eliminarAmigo(std::string);
        Social* clonar() const override;

        void visita(IVisitorSoftware*);
        void accederSesion(IVisitorSoftware*, Usuario*);

};


#endif