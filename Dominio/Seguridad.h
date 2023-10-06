#ifndef SEGURIDAD_H
#define SEGURIDAD_H
#include "Software.h"



/**
 * @class Seguridad , extends Software
*/
class Seguridad : public Software
{
    private:
        
        std::string tipo; // Tipo de malware que almacena

    public:
        const static std::string RANSOMWARE, SPYWARE, BOTNETS, ROOTKITS, GUSANOS, TROYANOS; // Constantes estaticas que definen los tipos de malware
        /**
         * Constructor copia de la clase Seguridad
         * @param Seguridad instancia a copiar
        */
        Seguridad(const Seguridad&);
        /**
         * Constructor de la clase Seguridad
         * @param string nombre
         * @param string developer
         * @param string clasificacion
         * @param double precio
         * @param string malware
        */
        Seguridad(std::string, std::string, std::string, double, std::string);
        /**
         * @return tipo malware
        */
        std::string getTipo();
        /**
         * @brief Retorna la cantidad de malwares que almaacena un usuario
         * @param Usuario  el usuario a investigar
         * @return el informe 
        */
        std::string getInforme(Usuario*);
        /**
         * @brief Retorna el porcentaje de la cantidad de malwares del usuario
         * @param Usuario , usuario a acceder 
         * @return string con el informe
        */
        std::string getPorcentaje(Usuario*);
        /**
         * @brief crea una instancia copia de Seguridad
         * @return Seguridad, instancia copia
        */
        Seguridad* clonar() const override;
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
         * @brief verifica si el malware por parametro es correcto
         * @param string malware a verificar
         * @return true, si existe en el sistema, false lo contrario
        */
        static bool verificarMalware(std::string);

};


#endif