#include "Social.h"


Social::Social(const Social& otro) : Software(otro.nombre, otro.developer, otro.clasificacion, otro.precio)
{ 
    this->listaAmigos = new std::vector<std::string>(0);
    nombreUsuario = "";
};

Social::Social(std::string nombre, std::string developer, std::string clasificacion, double precio) : Software(nombre, developer, clasificacion, precio)
{
    this->listaAmigos = new std::vector<std::string>(0);

    nombreUsuario = "";
};
// Retorna el usuario que accedio a una aplicación social
std::string Social::getNombreUsuario()
{
    return this->nombreUsuario;
};
std::vector<string> *Social::getListaAmigo()
{
    return this->listaAmigos;
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

bool Social::existeAmigo(std::string nombreAmigo)
{
    for(int i=0;i<listaAmigos->size();i++)
    {
        if(nombreAmigo == listaAmigos->at(i))
        {
            return true;
        }
    }
    return false;
};
bool Social::agregarAmigo(Usuario* amigo)
{
    if(amigo->getNombre() == this->nombreUsuario || existeAmigo(amigo->getNombre()))
    {
        return false;
    }
    Software* softwareAmigo =  amigo->getSoftware(this->nombre);
    if(softwareAmigo == nullptr)
    {
        return false; // Significa que no tiene la aplicación en sus registros
    }
    
    Social* appAmigo = dynamic_cast<Social*>(softwareAmigo);
    listaAmigos->push_back(amigo->getNombre()); // Se asocian a ambas app
    appAmigo->getListaAmigo()->push_back(this->nombreUsuario);
    return true;
};

bool Social::eliminarAmigo(Usuario* examigo)
{
    for(int i=0; i<listaAmigos->size();i++)
    {
        if(examigo->getNombre() == listaAmigos->at(i))
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
}
bool Social::isEmptyListaAmigo()
{
    return listaAmigos->empty();
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

