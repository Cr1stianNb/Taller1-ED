#ifndef SOFTWARE
#define SOFTWARE
#include <string>
#include <vector>
#include "Usuario.h"
#include "../Logica/IVisitorSoftware.h"
#include <iostream>
using namespace std;
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

        std::vector<Usuario*>* getListaUsuario();
        double getPrecio();

        void eliminarAplicacionDeUsuarios();
        bool agregarUsuario(Usuario*);
        Usuario* getUsuario(std::string);

        virtual Software* clonar() const = 0;
        virtual void visita(IVisitorSoftware*) = 0;
        virtual void accederSesion(IVisitorSoftware*, Usuario*) = 0;


};




#endif