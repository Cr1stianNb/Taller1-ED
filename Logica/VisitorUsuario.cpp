//Visitor.cpp
#include "VisitorUsuario.h"
#include "../Dominio/Administrador.h"
#include "../Dominio/UsuarioMenor.h"
#include "../Dominio/UsuarioMayor.h" 
VisitorUsuario::VisitorUsuario(){this->tipoUsuario = -1;};
VisitorUsuario::~VisitorUsuario(){};

void VisitorUsuario::acepta(Administrador us){this->tipoUsuario = Usuario::ADMINISTRADOR;};
void VisitorUsuario::acepta(UsuarioMenor us){this->tipoUsuario = Usuario::USUARIO_MENOR;};
void VisitorUsuario::acepta(UsuarioMayor us){this->tipoUsuario = Usuario::USUARIO_MAYOR;};
int VisitorUsuario::getTipo(){return this->tipoUsuario;};