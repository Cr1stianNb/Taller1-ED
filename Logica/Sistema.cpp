#include "Sistema.h"
#include "VisitorUsuario.h"

#include "../Dominio/UsuarioMenor.h"
#include "../Dominio/Administrador.h"
#include "../Dominio/UsuarioMayor.h"
#include "../Dominio/Ofimatica.h"
#include "../Dominio/Produccion.h"
#include "../Dominio/Seguridad.h"
#include "../Dominio/Social.h"
#include "../Dominio/Navegador.h"
#include <iostream>
using namespace std;


Sistema::Sistema()
{
    this->listaUsuarios = new vector<Usuario*>(0);
    this->listaSoftwares = new vector<Software*>(0);
};


void Sistema::mostrarUsuarios()
{
    for(int i=0; i<listaUsuarios->size();i++)
    {
        cout << listaUsuarios->at(i)->getNombre() << endl;
    }
};



// no se permite usuarios con el mismo nombre
bool Sistema::agregarAdmin(string nombre, string clave, int edad)
{
    if(this->getUsuario(nombre, clave) != nullptr) return false;

    Usuario* admin = new Administrador(nombre, clave, edad);
    this->listaUsuarios->push_back(admin);
    return true;
};
bool Sistema::agregarUsuarioNormal(std::string nombre, std::string clave, int edad)
{
    if(this->getUsuario(nombre, clave) != nullptr) return false; 

    Usuario* us;
    if(edad < 18)
    {
        us = new UsuarioMenor(nombre, clave, edad);
    }
    else
    {
        us = new UsuarioMayor(nombre, clave, edad);
    }
  
    this->listaUsuarios->push_back(us);
    return true;
};
Usuario* Sistema::getUsuario(string nombre, string clave)
{
    for(int i=0; i<listaUsuarios->size();i++)
    {
        if(listaUsuarios->at(i)->getNombre() == nombre && listaUsuarios->at(i)->getClave() == clave)
        {
            return listaUsuarios->at(i);
        }
    }
    return nullptr;
    
};
bool Sistema::verificarAcceso(string nombreUs, string claveUs)
{
    if(this->getUsuario(nombreUs, claveUs)) return true;
    cout <<  "Usuario o contraseña no se han encontrado, vuelva a intentarlo..." << endl;
    return false;
};
int Sistema::getTipoUsuario(string nombre, string clave)
{
    VisitorUsuario *visitadorUsuario = new VisitorUsuario();
    Usuario* us = this->getUsuario(nombre, clave);
    int tipo = -1;
    if(us)
    {
        us->visita(visitadorUsuario);
        //bool n = dynamic_cast<UsuarioMenor*>(us) != nullptr;
        tipo = visitadorUsuario->getTipo();
    }  
    delete visitadorUsuario;
    return tipo;
};

Software* Sistema::getSoftware(string nombre)
{
    for(int i=0; i<listaSoftwares->size();i++)
    {
        if(listaSoftwares->at(i)->getNombre() == nombre)
        {
            return listaSoftwares->at(i);
        }
    }
    return nullptr;
}

bool Sistema::agregarJuego(std::string nombre, std::string developer, std::string clasificacion, double precio, std::string genero)
{
    if(this->getSoftware(nombre) != nullptr) return false;
    Software* software = new Juego(nombre, developer, clasificacion, precio, genero);
    listaSoftwares->push_back(software);
    return true;

};
bool Sistema::agregarNavegador(std::string nombre, std::string developer, std::string clasificacion, double precio)
{
    if(this->getSoftware(nombre) != nullptr) return false;
    Software* software = new Navegador(nombre, developer, clasificacion, precio);
    listaSoftwares->push_back(software);
    return true;
};
bool Sistema::agregarOfimatica(std::string nombre, std::string developer, std::string clasificacion, double precio)
{
    if(this->getSoftware(nombre) != nullptr) return false;
    Software* software = new Ofimatica(nombre, developer, clasificacion, precio);
    listaSoftwares->push_back(software);
    return true;
};
bool Sistema::agregarProduccion(std::string nombre, std::string developer, std::string clasificacion, double precio, std::string tipo)
{
    if(this->getSoftware(nombre) != nullptr) return false;
    Software* software = new Produccion(nombre, developer, clasificacion, precio, tipo);
    listaSoftwares->push_back(software);
    return true;
};

bool Sistema::agregarSeguridad(std::string nombre, std::string developer, std::string clasificacion, double precio, std::string tipoMalware)
{
    if(this->getSoftware(nombre) != nullptr) return false;
    Software* software = new Seguridad(nombre, developer, clasificacion, precio, tipoMalware);
    listaSoftwares->push_back(software);
    return true;
};
bool Sistema::agregarSocial(std::string nombre, std::string developer, std::string clasificacion, double precio)

{
    if(this->getSoftware(nombre) != nullptr) return false;
    Software* software = new Social(nombre, developer, clasificacion, precio);
    listaSoftwares->push_back(software);
    return true;
};

bool Sistema::agregarSoftwareUsuario(std::string nombre, std::string clave, std::string nombreSoftware)
{
    Usuario* usuario = getUsuario(nombre, clave);
    Software* software = getSoftware(nombreSoftware);
    if(usuario == nullptr) return false;
    if(software == nullptr) return false;

    software->agregarUsuario(usuario);
    Software* soft = software->clonar();
    usuario->agregarSoftware(soft);
    return true;

};
bool Sistema::eliminarSoftwareUsuario(std::string nombre, std::string clave, std::string nombreSoftware)
{
    if(getUsuario(nombre, clave) == nullptr) return false;
    if(getSoftware(nombreSoftware) == nullptr) return false;

    Usuario* us = this->getUsuario(nombre, clave);
    Software* soft = this->getSoftware(nombreSoftware);
    return us->eliminarSoftware(soft);
}

bool Sistema::eliminarSoftwareSistema(Software* software)
{
    if(software == nullptr) return false;
    for(int i=0; i<listaSoftwares->size();i++)
    {
        if(listaSoftwares->at(i)->getNombre() == software->getNombre())
        {
            listaSoftwares->erase(listaSoftwares->begin() + i);
            return true;
        }
    }
    return false;
};

bool Sistema::eliminarSoftwareBiblioteca(std::string nombreSoftware)
{
    Software* software = getSoftware(nombreSoftware);
    if(software == nullptr) return false;

    return eliminarSoftwareSistema(software);
};


string Sistema::getNombresSoftwares()
{
    if(listaSoftwares->size() == 0) return "No hay aplicaciones en la bibliotecas \n";
    string texto = "Listado de Softwares:\n";
    for(int i=0; i<listaSoftwares->size();i++)
    {
        texto += " -" + listaSoftwares->at(i)->getNombre() + "\n" ;
    }
    return texto;

};