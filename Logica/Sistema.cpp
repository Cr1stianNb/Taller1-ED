#include "Sistema.h"
#include "Visitor.h"

#include "../Dominio/UsuarioMenor.h"
#include "../Dominio/Administrador.h"
#include "../Dominio/UsuarioMayor.h"
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
    if(this->getUsuario(nombre, clave)) return false;

    Usuario* admin = new Administrador(nombre, clave, edad);
    this->listaUsuarios->push_back(admin);
    return true;
};



bool Sistema::agregarUsuarioNormal(std::string nombre, std::string clave, int edad)
{
    if(this->getUsuario(nombre, clave)) return false;   

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
        bool n = dynamic_cast<UsuarioMenor*>(us) != nullptr;
        tipo = visitadorUsuario->getTipo();
    }  
    delete visitadorUsuario;
    return tipo;
};
