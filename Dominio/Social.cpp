#include "Social.h"


Social::Social(const Social& otro) : Software(otro.nombre, otro.developer, otro.clasificacion, otro.precio)
{ 
    this->listaAmigos = otro.listaAmigos;
};

Social::Social(std::string nombre, std::string developer, std::string clasificacion, double precio) : Software(nombre, developer, clasificacion, precio)
{
    this->listaAmigos = new std::vector<std::string>();
    nombreUsuario = "";
}
// Retorna el usuario que accedio a una aplicación social
std::string Social::getNombreUsuario()
{
    return this->nombreUsuario;
}
void Social::setNombreUsuario(std::string nombreUsuario)
{
    this->nombreUsuario = nombreUsuario;
};

std::string Social::getNombresAmigos()
{
    std::string texto = "Listado de amigos:\n";
    for(int i=0; i<this->listaAmigos->size();i++)
    {
        texto += " -" + listaAmigos->at(i) + "\n";
    }
    return texto;
};
/**
 * 
 * Método que agrega un amigo a la lista de amigos
 * @param amigo nombre amigo a agregar
 * @return true si se agrega correctamente, false si el nombre del amigo es igual al usuario asociado
 * 
*/
bool Social::agregarAmigo(std::string  amigo)
{
    if(amigo == this->nombreUsuario)
    {
        return false;
    }
    listaAmigos->push_back(amigo);
    return true;
};

bool Social::eliminarAmigo(std::string  examigo)
{
    for(int i=0; i<listaAmigos->size();i++)
    {
        if(examigo == listaAmigos->at(i))
        {
            listaAmigos->erase(listaAmigos->begin() + i);
            return true;
        }
    }
    return false;
}
void Social::asociarUsuario(std::string usuario)
{
    this->nombreUsuario = usuario;
};
Social *Social::clonar() const
{
    return new Social(*this);
}
void Social::visita(IVisitorSoftware *visitorSoftware){visitorSoftware->acepta(*this, nullptr);}

void Social::accederSesion(IVisitorSoftware* visitorSoftware, Usuario* usuario)
{
    visitorSoftware->acepta(*this, usuario);
};

