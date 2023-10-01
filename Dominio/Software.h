#ifndef SOFTWARE
#define SOFTWARE
#include <string>


class Software
{
    
    private:
        std::string nombre;
        std::string developer;
        std::string clasificacion;
        // ListaUsuario listaUsuarios;
        double precio;

    public:

        Software(std::string, std::string, std::string, double precio);
        std::string getNombre();
        std::string getDeveloper();
        std::string getClasificacion();
        double getPrecio();

   

};




#endif