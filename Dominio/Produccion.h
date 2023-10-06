#ifndef PRODUCCION_H
#define PRODUCCION_H
#include "Software.h"

/**
 * @class Produccion clase derivada de Software
*/
class Produccion : public Software
{
    private:
        std::string tipoSolucion;
        double cantidadHoras;
    public:
        const static std::string VIDEO, MUSICA, STREAMING, FOTOS; // constantes estaticas

        /**
         * Constructor copia
         * @param Produccion objeto a copiar
        */
        Produccion(const Produccion&);
        /**
         * Constructor de la clase Produccion
         * @param string nombre
         * @param string developer
         * @param string clasificacion
         * @param double precio
         * @param string tipoSolucion
        */
        Produccion(std::string , std::string, std::string, double , std::string);
        /**
         * @return tipoSolucion
        */
        std::string getTipoSolucion();
        /**
         * @return cantidadHoras
        */
        double getCantidadHoras();
        /**
         * @brief agrega horas a la cantidadHoras
         * @param double cantidad de horas a agregar
        */
        void agregarCantidadHoras(double);

        /**
         * crea una instancia copia
         * @return la instancia copia  Produccion
        */
        Produccion* clonar() const override;
        
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
         /**
         * @brief verifica si la solucion  por parametro es correcto
         * @param string tipoSolucion a verificar
         * @return true, si existe en el sistema, false lo contrario
        */
        static bool verificarSolucion(std::string);
};




#endif