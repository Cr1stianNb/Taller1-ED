#include "VisitorSoftware.h"



const string VisitorSoftware::JUEGO = "Juego";
const string VisitorSoftware::NAVEGADOR = "Navegador";
const string VisitorSoftware::OFIMATICA = "Ofimatica";
const string VisitorSoftware::PRODUCCION = "Produccion";
const string VisitorSoftware::SEGURIDAD = "Seguridad";
const string VisitorSoftware::SOCIAL = "Social";

VisitorSoftware::VisitorSoftware(){ this->tipoSoftware = "";};
VisitorSoftware::~VisitorSoftware(){};


void VisitorSoftware::acepta(Juego&, Usuario*){this->tipoSoftware = VisitorSoftware::JUEGO;};
void VisitorSoftware::acepta(Navegador&, Usuario*){this->tipoSoftware = VisitorSoftware::NAVEGADOR;};
void VisitorSoftware::acepta(Ofimatica&, Usuario*){this->tipoSoftware = VisitorSoftware::OFIMATICA;};
void VisitorSoftware::acepta(Produccion&, Usuario*){this->tipoSoftware = VisitorSoftware::PRODUCCION;};
void VisitorSoftware::acepta(Seguridad&, Usuario*){this->tipoSoftware = VisitorSoftware::SEGURIDAD;};
void VisitorSoftware::acepta(Social&, Usuario*){this->tipoSoftware = VisitorSoftware::SOCIAL;};

string VisitorSoftware::getTipoSoftware(){return this->tipoSoftware;};

