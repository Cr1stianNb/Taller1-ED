//Visitor.cpp
#include "Visitor.h"
#include "../Dominio/Usuario.h"
#include "../Dominio/UsuarioMenor.h"
#include "../Dominio/UsuarioMayor.h" 
VisitorUsuario::VisitorUsuario(){this->tipoUsuario = -1;};

void VisitorUsuario::acepta(Administrador us){this->tipoUsuario = Usuario::ADMINISTRADOR;};
void VisitorUsuario::acepta(UsuarioMenor us){this->tipoUsuario = Usuario::USUARIO_MAYOR;};
void VisitorUsuario::acepta(UsuarioMayor us){this->tipoUsuario = Usuario::USUARIO_MENOR;};
int VisitorUsuario::getTipo(){return this->tipoUsuario;};