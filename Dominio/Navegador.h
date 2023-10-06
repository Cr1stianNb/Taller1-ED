#ifndef NAVEGADOR_H
#define NAVEGADOR_H
#include "Software.h"

/**
 * @class Navegador
 * 
*/
class Navegador : public Software
{
    private:
        int contador;
        std::vector<std::string>* historial;
    public:
        /**
         * Constructor copia 
         * @param Navegador, navegador a copiar
        */
        Navegador(const Navegador&);
        /**
         * Constructor de la clase Navegador
         * @param string nombre
         * @param string developer
         * @param string clasificacion
         * @param double precio
        */
        Navegador(std::string, std::string, std::string, double);
        /**
         * @return el historial completo del navegador
        */
        std::string getHistorial();
        /**
         * Agrega una página al vector historial
         * Si el historial es 10, entonces se reemplazar por el primero en la lista
        */
        void agregarPagina(std::string);
        /**
         * Crea una instancia copia de Navegador
         * @return Navegador copia 
        */
        Navegador* clonar() const override;
           /**
         * @brief patrón visitor, método override de la clase padre
         * @param IVisitorSoftware Interfaz IVisitorSoftware
         * 
        */
        virtual void visita(IVisitorSoftware*);
                  /**
         * @brief patrón visitor Método que acepta una sesión de un determinado Usuario
         * @param IVisitorSoftware, Interfaz 
         * @param Usuario usuario que accedera la sesión
        */
        virtual void accederSesion(IVisitorSoftware*, Usuario*);
};


#endif