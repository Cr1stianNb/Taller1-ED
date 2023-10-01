#include "Social.h"

#define NULL __null


Social::Social(std::string nombre, std::string developer, std::string clasificacion, double precio):
    Software(nombre, developer, clasificacion, precio){

    };

Usuario Social::getAmigo(std::string nombreAmigo)
{
    for(int i=0; i<this->listaAmigos.size();i++)
    {
        if(nombreAmigo == listaAmigos[i].getNombre()) return listaAmigos[i];
    }
};

bool Social::agregarAmigo(std::string nombreAmigo)
{
    //  Agregar un amigo
};

bool Social::eliminarAmigo(std::string nombreAmigo)
{
    // Eliminar un amigo
};

