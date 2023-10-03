#include "Social.h"

#define NULL __null

Social::Social(const Social& otro) : Software(otro.nombre, otro.developer, otro.clasificacion, otro.precio){};

Social::Social(std::string nombre, std::string developer, std::string clasificacion, double precio) : Software(nombre, developer, clasificacion, precio){ };


Usuario* Social::getAmigo(std::string nombreAmigo)
{
    for(int i=0; i<this->listaAmigos.size();i++)
    {
        if(nombreAmigo == listaAmigos[i]->getNombre()) return listaAmigos[i];
    }
    return nullptr;
};

bool Social::agregarAmigo(std::string nombreAmigo)
{
    //  Agregar un amigo
    return true;
};

bool Social::eliminarAmigo(std::string nombreAmigo)
{
    // Eliminar un amigo
    return true;
}
Social *Social::clonar() const
{
    return new Social(*this);
}
void Social::visita(IVisitorSoftware *visitorSoftware){visitorSoftware->acepta(*this);};
