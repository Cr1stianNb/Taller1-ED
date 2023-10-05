#include "VisitorSoftware.h"



string VisitorSoftware::JUEGO = "Juego";
string VisitorSoftware::NAVEGADOR = "Navegador";
string VisitorSoftware::OFIMATICA = "Ofimatica";
string VisitorSoftware::PRODUCCION = "Produccion";
string VisitorSoftware::SEGURIDAD = "Seguridad";
string VisitorSoftware::SOCIAL = "Social";

VisitorSoftware::VisitorSoftware(){ this->tipoSoftware = "";};
VisitorSoftware::~VisitorSoftware(){};


void VisitorSoftware::acepta(Juego&, Usuario*){this->tipoSoftware = VisitorSoftware::JUEGO;};
void VisitorSoftware::acepta(Navegador&, Usuario*){this->tipoSoftware = VisitorSoftware::NAVEGADOR;};
void VisitorSoftware::acepta(Ofimatica&, Usuario*){this->tipoSoftware = VisitorSoftware::OFIMATICA;};
void VisitorSoftware::acepta(Produccion&, Usuario*){this->tipoSoftware = VisitorSoftware::PRODUCCION;};
void VisitorSoftware::acepta(Seguridad&, Usuario*){this->tipoSoftware = VisitorSoftware::SEGURIDAD;};
void VisitorSoftware::acepta(Social&, Usuario*){this->tipoSoftware = VisitorSoftware::SOCIAL;};

string VisitorSoftware::getTipoSoftware(){return this->tipoSoftware;};

