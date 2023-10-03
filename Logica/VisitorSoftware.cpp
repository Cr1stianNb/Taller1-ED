#include "VisitorSoftware.h"



string VisitorSoftware::JUEGO = "Juego";
string VisitorSoftware::NAVEGADOR = "Navegador";
string VisitorSoftware::OFIMATICA = "Ofimatica";
string VisitorSoftware::PRODUCCION = "Produccion";
string VisitorSoftware::SEGURIDAD = "Seguridad";
string VisitorSoftware::SOCIAL = "Social";

VisitorSoftware::VisitorSoftware(){ this->tipoSoftware = "";};
VisitorSoftware::~VisitorSoftware(){};


void VisitorSoftware::acepta(Juego){this->tipoSoftware = VisitorSoftware::JUEGO;};
void VisitorSoftware::acepta(Navegador){this->tipoSoftware = VisitorSoftware::NAVEGADOR;};
void VisitorSoftware::acepta(Ofimatica){this->tipoSoftware = VisitorSoftware::OFIMATICA;};
void VisitorSoftware::acepta(Produccion){this->tipoSoftware = VisitorSoftware::PRODUCCION;};
void VisitorSoftware::acepta(Seguridad){this->tipoSoftware = VisitorSoftware::SEGURIDAD;};
void VisitorSoftware::acepta(Social){this->tipoSoftware = VisitorSoftware::SOCIAL;};

string VisitorSoftware::getTipoSoftware(){return this->tipoSoftware;};

