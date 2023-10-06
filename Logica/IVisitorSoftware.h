#ifndef IVISITOR_SOFTWARE_H
#define IVISITOR_SOFTWARE_H
//Forward declaration
class Juego;
class Navegador;
class Ofimatica;
class Produccion;
class Seguridad;
class Social;
class Usuario;
/**
 * @interface Interfaz que implementa los métodos para que clases visiten Softwares y sus derivados
*/
class IVisitorSoftware
{
    
    public:

        virtual void acepta(Juego& , Usuario*) = 0;
        /**
         * Método que visitara el objeto Navegador y aceptara su tipo
         * @param Navegador Navegador que utilizo el método visitar
         * @param Usuario usuario intenta ingresar a la aplicación , nullptr si no es el caso 
        */
        virtual void acepta(Navegador& , Usuario*) = 0;
        /**
         * Método que visitara el objeto Ofimatica y aceptara su tipo
         * @param Ofimatica Ofimatica que utilizo el método visitar
         * @param Usuario usuario intenta ingresar a la aplicación , nullptr si no es el caso 
        */
        virtual void acepta(Ofimatica& , Usuario*) = 0;
        /**
         * Método que visitara el objeto Produccion y aceptara su tipo
         * @param Produccion Produccion que utilizo el método visitar
         * @param Usuario usuario intenta ingresar a la aplicación , nullptr si no es el caso 
        */
        virtual void acepta(Produccion& , Usuario*) = 0;
        /**
         * Método que visitara el objeto Seguridad y aceptara su tipo
         * @param Seguridad Seguridad que utilizo el método visitar
         * @param Usuario usuario intenta ingresar a la aplicación , nullptr si no es el caso 
        */
        virtual void acepta(Seguridad& , Usuario*) = 0;
        /**
         * Método que visitara el objeto Social y aceptara su tipo
         * @param Social Social que utilizo el método visitar
         * @param Usuario usuario intenta ingresar a la aplicación , nullptr si no es el caso 
        */
        virtual void acepta(Social& , Usuario*) = 0;
        /**
         * Indica el tipo de software que visito
         * 
         * @return Tipo de software que visito en forma de string, se tendrá que verificar con las mismas constantes de clase definidas en esta clase
        */
       
};

#endif