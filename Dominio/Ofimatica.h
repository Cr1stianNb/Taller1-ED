#ifndef OFIMATICA
#define OFIMATICA
#include "Software.h"

class Ofimatica : public Software
{
    private:
        int cantArchivos;

    public:
        Ofimatica(std::string, std::string, std::string, double);
        int getCantArchivo();
        bool agregarArchivo();
        bool eliminarArchivo();
};




#endif