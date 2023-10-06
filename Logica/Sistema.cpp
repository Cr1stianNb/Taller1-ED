#include "Sistema.h"
#include "VisitorUsuario.h"
#include "VisitorSoftware.h"
#include "../Dominio/UsuarioMenor.h"
#include "../Dominio/Administrador.h"
#include "../Dominio/UsuarioMayor.h"
#include "../Dominio/Ofimatica.h"
#include "../Dominio/Produccion.h"
#include "../Dominio/Seguridad.h"
#include "../Dominio/Social.h"
#include "../Dominio/Navegador.h"
#include "VisitorSesionSoftware.h"
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
    if(this->getUsuario(nombreUs, claveUs) != nullptr) return true;
    cout <<  "Usuario o contraseña no se han encontrado, vuelva a intentarlo..." << endl;
    return false;
}
bool Sistema::existeSoftware(std::string nombreSoftware)
{
    if(this->getSoftware(nombreSoftware) == nullptr) return false;
    return true;
};
bool Sistema::estaRegistroSoftware(std::string nombreUs, std::string clave, std::string nombreSoft)
{
    Usuario* usuario = this->getUsuario(nombreUs, clave);
    Software* software = this->getSoftware(nombreSoft); // conseguir el objeto software del sistema
    if(usuario == nullptr) return false; // Si no existe el usuario retornar falso

    Software* softwareUsuario = usuario->getSoftware(nombreSoft); // conseguir el objeto software de la persona

    if(software != nullptr && softwareUsuario != nullptr) return true; // Si el software existe en la biblioteca , y tambien existe en el usuario entonces si esta registrado

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
    cout << "ENtra";
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
// Agregar un software copia al usuario 
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
            listaSoftwares->at(i)->eliminarAplicacionDeUsuarios();
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

void Sistema::accederSoftware(std::string nombreUs, std::string clave, std::string nombreSoftware)
{
    Usuario* usuario = this->getUsuario(nombreUs, clave);
    Software* copiaSoftware = usuario->getSoftware(nombreSoftware);

    if(usuario == nullptr) return;
    if(copiaSoftware == nullptr) return;

    VisitorSesionSoftware* visitorSesion = new VisitorSesionSoftware(this);
    copiaSoftware->accederSesion(visitorSesion, usuario);

};
/***
 *  Método que devuelve la edad de un usuario a partir del nombre 
 * @param nombre std::string nombre del usuario a buscar la edad
 * @return devuelve la edad del usuario con un determinado nombre, devuelve -1 si no se encontro el usuario en el sistema 
*/
int Sistema::getEdadUsuario(std::string nombre)
{
    for(int i=0; i<listaUsuarios->size();i++)
    {
        if(nombre == listaUsuarios->at(i)->getNombre())
        {
            return listaUsuarios->at(i)->getEdad();
        }
    }
    return -1;
}

std::string Sistema::getNombresUsuarios()
{
    std::string texto= "Lista de usuarios en la biblioteca: \n";
    for(int i=0; i<listaUsuarios->size();i++)
    {
        texto += " -" + listaUsuarios->at(i)->getNombre() + "\n"; 
    }
    return texto;
}

std::string Sistema::getNombresSoftwaresUsuario(std::string nombre, std::string clave)
{
    Usuario* usuario = getUsuario(nombre, clave);
    string texto = "Listados de los Softwares que has iniciado sesión: \n";
    if(usuario == nullptr) return std::string("Usuario " + nombre + " No se ha encontrado en el sistema...");

    vector<Software*>* listaSoftware = usuario->getListaSoftware();
    VisitorSoftware* visitorSoft = new VisitorSoftware();
    for(int i=0; i<listaSoftware->size();i++)
    {

        listaSoftware->at(i)->visita(visitorSoft);
        texto += "- " + listaSoftware->at(i)->getNombre() + " Tipo Software: " + visitorSoft->getTipoSoftware() + "\n";
    }
    delete visitorSoft;
    return texto;
    

}

string Sistema::getNombresSoftwares()
{
    if(listaSoftwares->size() == 0) return "No hay aplicaciones en la bibliotecas \n";
    VisitorSoftware* visitorSoft = new VisitorSoftware();
    string texto = "Listado de Softwares:\n";
    for(int i=0; i<listaSoftwares->size();i++)
    {
        Software* soft = listaSoftwares->at(i);
        soft->visita(visitorSoft);
        texto += " -Nombre: " +  soft->getNombre() +  " Tipo Software: " + visitorSoft->getTipoSoftware() + "\n" ;
    
    }
    delete visitorSoft;
    return texto;

}
std::vector<string>* Sistema::getNombresUsuariosSoftware(std::string nombreSoftware)
{
    Software* software = getSoftware(nombreSoftware);
    if(software == nullptr) return nullptr;

    vector<string>* listaNombres = new vector<string>();
    vector<Usuario*>* listaUsuarios = software->getListaUsuario();

    for(int i=0; i<listaUsuarios->size();i++)
    {
        listaNombres->push_back(listaUsuarios->at(i)->getNombre());
    }
    return listaNombres;
    

};


bool Sistema::isEmptySoftwares()
{
    return listaSoftwares->empty();
};
bool Sistema::isEmptyUsuarios()
{
    return listaUsuarios->empty();
}
bool Sistema::isEmptyRegistrosUsuario(std::string nombre, std::string clave)  
{
    Usuario* usuario = this->getUsuario(nombre, clave);
    if(usuario == nullptr) return true;

    return usuario->getListaSoftware()->empty();
};