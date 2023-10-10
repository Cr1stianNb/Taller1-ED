#ifndef VISITOR_SESION_SOFTWARE_H
#define VISITOR_SESION_SOFTWARE_H
#include "IVisitorSoftware.h"
#include "VisitorSoftware.h"
#include "../Dominio/Juego.h"
#include "../Dominio/Navegador.h"
#include "../Dominio/Ofimatica.h"
#include "../Dominio/Produccion.h"
#include "../Dominio/Social.h"
#include "../Dominio/Seguridad.h"
#include <string>
using namespace std;

double parseDouble(string);
int parseInt(string);
void transicion(int);

class Sistema;
/**
 * @class VisitorSesionSoftware
 * Clase que se encargara de abrir sesión con un software y un usuario determinado
 * implementa la interfaz 'IVisitorSoftware'
*/
class VisitorSesionSoftware : public IVisitorSoftware
{
    private:
        Sistema* sistema; // Tiene un puntero de referencia al sistema
    public:
        /**
         * Constructor de la clase 
         * @param Sistema puntero de referencia al sistema, se necesitaran del sistema para  algunos acciones
        */
        VisitorSesionSoftware(Sistema*);
        /**
         * Destructor de la Clase
        */
        ~VisitorSesionSoftware();
        
        virtual void acepta(Juego&, Usuario*);
        virtual void acepta(Navegador&, Usuario*);
        virtual void acepta(Ofimatica&, Usuario*);
        virtual void acepta(Produccion&, Usuario*);
        virtual void acepta(Seguridad&, Usuario*);
        virtual void acepta(Social&, Usuario*);

        /**
         * Devuelve en formato de string los nombres del vector de string
         * @param vector el vector de string con los nombres
         * @param string el nombre del usuario que esta en actual sesion
         * @return el string con el listado de nombres
        */
        string getNombreUsuarios(vector<string>* listanombres, string usuarioAcceso);
        


};


#endif