#include "Sistema.h"
#include "Visitor.h"
#include <iostream>
using namespace std;
Sistema::Sistema()
{
    listaUsuarios = new vector<Usuario*>();
    listaSoftwares = new vector<Software*>();
};

bool Sistema::verificarAcceso(string nombreUs, string claveUs)
{
    for(int i=0; i<listaUsuarios->size(); i++)
    {
        Usuario *us = listaUsuarios->at(i);
        if(us->getNombre() == nombreUs && us->getClave() == claveUs)
        {
            return true;
        }
    }
    cout <<  "Usuario o contraseña no se han encontrado, vuelva a intentarlo..." ;
    return false;
};

int Sistema::getTipoUsuario(string nombre, string clave)
{
    if(this->verificarAcceso(nombre, clave))
    {
        VisitorUsuario *visitadorUsuario = new VisitorUsuario();
        for(int i=0; i<listaUsuarios->size();i++)
        {
            Usuario *us = listaUsuarios->at(i);
            if(us->getNombre() == nombre && us->getClave() == clave)
            {
                us->visita(visitadorUsuario);
                return visitadorUsuario->getTipo(); 
            }
        }
    }
    return -1;
};
