#ifndef SOFTWARE
#define SOFTWARE
#include <string>
#include <vector>
#include "Usuario.h"
#include "../Logica/IVisitorSoftware.h"
class Software 
{
    
    protected:
        std::string nombre;
        std::string developer;
        std::string clasificacion;
        std::vector<Usuario*>* listaUsuario;
        double precio;

    public:
        const static std::string E, A;
        Software(const Software&);
        Software(std::string, std::string, std::string, double);
        std::string getNombre();
        std::string getDeveloper();
        std::string getClasificacion();
        double getPrecio();
        bool agregarUsuario(Usuario*);
        Usuario* getUsuario(std::string);

        virtual Software* clonar() const = 0;
        virtual void visita(IVisitorSoftware*) = 0;


};




#endif