#ifndef VISITOR_SOFTWARE_H
#define VISITOR_SOFTWARE_H
#include "IVisitorSoftware.h"
#include <string>
using namespace std;

/**
 * @class VisitorSoftware
 * clase que visitara las clases Software y sus derivados
 * implementa la 'Interfaz ' IVisitorSoftware
*/
class VisitorSoftware : public IVisitorSoftware
{
    private:
        string tipoSoftware;
    public:
        const static string JUEGO; //  constante y estatico para verificar el tipo de Software 
        const static string NAVEGADOR; //  cconstante y estatico para verificar el tipo de Software  
        const static string OFIMATICA; //  cconstante y estatico para verificar el tipo de Software 
        const static string PRODUCCION; //  cconstante y estatico para verificar el tipo de Software 
        const static string SEGURIDAD; //  cconstante y estatico para verificar el tipo de Software 
        const static string SOCIAL; //  cconstante y estatico para verificar el tipo de Software 
        VisitorSoftware();  // Constructor
        ~VisitorSoftware();  // Destructor
        /**
         * Método que visitara el objeto Juego y aceptara su tipo
         * @param Juego juego que utilizo el método visitar
         * @param Usuario usuario intenta ingresar a la aplicación , nullptr si no es el caso 
        */
        void acepta(Juego& , Usuario*);
        /**
         * Método que visitara el objeto Navegador y aceptara su tipo
         * @param Navegador Navegador que utilizo el método visitar
         * @param Usuario usuario intenta ingresar a la aplicación , nullptr si no es el caso 
        */
        void acepta(Navegador& , Usuario*);
        /**
         * Método que visitara el objeto Ofimatica y aceptara su tipo
         * @param Ofimatica Ofimatica que utilizo el método visitar
         * @param Usuario usuario intenta ingresar a la aplicación , nullptr si no es el caso 
        */
        void acepta(Ofimatica& , Usuario*);
        /**
         * Método que visitara el objeto Produccion y aceptara su tipo
         * @param Produccion Produccion que utilizo el método visitar
         * @param Usuario usuario intenta ingresar a la aplicación , nullptr si no es el caso 
        */
        void acepta(Produccion& , Usuario*);
        /**
         * Método que visitara el objeto Seguridad y aceptara su tipo
         * @param Seguridad Seguridad que utilizo el método visitar
         * @param Usuario usuario intenta ingresar a la aplicación , nullptr si no es el caso 
        */
        void acepta(Seguridad& , Usuario*);
        /**
         * Método que visitara el objeto Social y aceptara su tipo
         * @param Social Social que utilizo el método visitar
         * @param Usuario usuario intenta ingresar a la aplicación , nullptr si no es el caso 
        */
        void acepta(Social& , Usuario*);
        /**
         * Indica el tipo de software que visito
         * 
         * @return Tipo de software que visito en forma de string, se tendrá que verificar con las mismas constantes de clase definidas en esta clase
        */
        string getTipoSoftware();
};





#endif