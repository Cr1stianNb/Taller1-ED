#ifndef SOFTWARE
#define SOFTWARE
#include <string>
#include <vector>
#include "Usuario.h"
class Software 
{
    
    protected:
        std::string nombre;
        std::string developer;
        std::string clasificacion;
        std::vector<Usuario>* listaUsuario;
        double precio;

    public:
        Software(const Software&);
        Software(std::string, std::string, std::string, double);
        std::string getNombre();
        std::string getDeveloper();
        std::string getClasificacion();
        double getPrecio();
        void hacerAlgo();

        virtual Software* clonar() const;

   

};




#endif