#include <iostream>
#include "Dominio/Software.cpp"
#include "Dominio/Usuario.cpp"
#include "Dominio/Juego.cpp"
#include "Logica/Sistema.h"

using namespace std;




void login(Sistema*);
void mostrarMenuAdmin(string, string, Sistema*);
void mostrarMenuUsuario(string, string, Sistema*);
void mostrarMenuInfantil(string, string, Sistema*);




int main()
{
    Sistema *sistema = new Sistema();
    Software* soft = new Software("Facebook", "Mark", "Menores a 17", 12.12);
    Software* jueguito = new Juego("Mario", "Un japo", "toda edad", 291.12, "Plataformero");
    Usuario* usuario1 = new Usuario("Cristian", "clave123", 20);

    login(sistema);

    return 0;
}


void login(Sistema*sistema)
{
    cout << "Bienvenido al programa: Manejos Software" << endl;
    
    string nombre, clave;
    do
    {
        cout << "Ingrese Nombre Usuario: ";
        cin >> nombre;
        cout << "Ingrese la clave: ";
        cin >> clave;
    } while (sistema->verificarAcceso(nombre, clave));
    
    int tipoUsuario = sistema->getTipoUsuario(nombre, clave);

    switch(tipoUsuario)
    {
        case Usuario::ADMINISTRADOR:

            mostrarMenuAdmin(nombre, clave, sistema);
            break;

        case Usuario::USUARIO:
            mostrarMenuUsuario(nombre, clave, sistema);
            break;

        case Usuario::INFANTIL:
            mostrarMenuInfantil(nombre, clave, sistema);
            break;

        default:
            cout << "No se ha encontrado al tipo de usuario al que pertenece";
            break;
    }


    


    
};