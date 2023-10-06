#ifndef OFIMATICA_H
#define OFIMATICA_H
#include "Software.h"

/**
 * @class Ofimatica extends Software
*/
class Ofimatica : public Software
{
    private:
        int cantArchivos;

    public:
        /**
         * Constructor copia de Ofimatica
         * @param Ofimatica objeto a copiar
         * 
        */
        Ofimatica(const Ofimatica&);
        /**
         * Constructor de la Clase Ofimatica
         * @param string nombre
         * @param string developer
         * @param string clasificacion
         * @param double precio
        */
        Ofimatica(std::string, std::string, std::string, double);
        /**
         * @return cantArchivo
        */
        int getCantArchivo();
        /**
         * Agrega un solo archivo a la cantidad archivo
        */
        bool agregarArchivo();
        /**
         * Elimina un solo archivo a la cantidadArchivo
        */
        bool eliminarArchivo();
        /**
         * Crea una instancia copia de este objeto
         * @return la instancia copia de Ofimatica
        */
        Ofimatica* clonar() const override;
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