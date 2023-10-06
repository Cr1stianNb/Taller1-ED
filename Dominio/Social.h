#ifndef SOCIAL_H
#define SOCIAL_H
#include "Software.h"

class Social : public Software
{
    private:
        std::vector<std::string>* listaAmigos;
        std::string nombreUsuario;

    public:
        Social(const Social&);
        Social(std::string, std::string, std::string, double);
        std::string getNombreUsuario();
        void setNombreUsuario(std::string);
        std::string getNombresAmigos();
        bool agregarAmigo(std::string);
        bool eliminarAmigo(std::string);
        void asociarUsuario(std::string);
        Social* clonar() const override;

        void visita(IVisitorSoftware*);
        void accederSesion(IVisitorSoftware*, Usuario*);

};


#endif