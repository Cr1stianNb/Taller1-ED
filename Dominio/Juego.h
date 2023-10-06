#ifndef JUEGO_H
#define JUEGO_H
#include "Software.h"

// Los generos que acepta la clase Juego
const std::string GENEROS[10] {"FPS", "MMO", "PUZZLE", "PLATAFORMERO", "RPG", "HORROR", "ESTRATEGIA", "DEPORTES", "ACCIÓN", "ADVENTURAS"};

/**
 * @class Juego 
*/
class Juego : public Software
{
    public:
        double horasJugadas;
        std::string genero;
    public:
        /**
         * Constructor copia
         * @param Juego instancia a copiar
        */
        Juego(const Juego&);
        /**
         * Constructor de la clase Juego
         * @param string nombre
         * @param string developer
         * @param string clasificacion
         * @param double precio
         * @param string genero
        */
        Juego(std::string, std::string, std::string, double, std::string);
        /**
         * @return el genero del juego
        */
        std::string getGenero();
        /**
         * @return cantidad de horas jugadas
        */
        double getHorasJugadas();
        /**
         * Agrega horas a la cantidadHoras del objeto
         * @param double horas a agregar
        */
        void agregarHorasJugadas( double cantidadHoras);
        /**
         * Crea una instancia copia de este objeto
         * @return Juego copia
        */
        Juego* clonar() const override;
        /**
         * @brief patrón visitor, método override de la clase padre
         * @param IVisitorSoftware Interfaz IVisitorSoftware
         * 
        */
        virtual void visita(IVisitorSoftware*);
    
        /**
         * vERIFICA el genero del genero que se entrega por parametro
         * @param string el genero a verificar
         * @return true, el genero si existe, false lo contrario
        */
        static bool verificarGenero(std::string );
        /**
         * @brief patrón visitor Método que acepta una sesión de un determinado Usuario
         * @param IVisitorSoftware, Interfaz 
         * @param Usuario usuario que accedera la sesión
        */
        virtual void accederSesion(IVisitorSoftware*, Usuario*);
};



#endif