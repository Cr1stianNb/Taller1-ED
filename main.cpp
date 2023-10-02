#include <iostream>

#include "Dominio/Software.cpp"
#include "Dominio/Usuario.cpp"
#include "Dominio/Juego.cpp"
#include "Logica/Sistema.cpp"
#include "Dominio/Administrador.cpp"
#include "Dominio/UsuarioMenor.cpp"
#include "Dominio/UsuarioMayor.cpp"
#include "Logica/VisitorUsuario.cpp"
#include "Dominio/Navegador.cpp"
#include "Dominio/Ofimatica.cpp"
#include "Dominio/Produccion.cpp"
#include "Dominio/Seguridad.cpp"
#include "Dominio/Social.cpp"

using namespace std;




void login(Sistema*);
bool logout();
void mostrarMenuAdmin(string, string, Sistema*);
void mostrarMenuUsuario(string, string, Sistema*);

void agregarSoftware(string, string, Sistema*);
void eliminarSoftware(string, string, Sistema*);
void accederSoftware(string, string, Sistema*);
void accederLog(string, string, Sistema*);


int main()
{

    Sistema* sistema = new Sistema();


    Software* soft = new Juego("Mario", "un japo", "toda edad", 9219.2, "Aventuras");
    Software* soft2 = soft->clonar();

    cout << "Id :" << soft << endl;
    cout << "Id :" << soft2 << endl;

    Juego* juego = dynamic_cast<Juego*>(soft2);
    Juego* juego2 = dynamic_cast<Juego*>(soft);
    juego->genero = "Jijijja";
    cout << "Id: " << juego2 << " Genero: " << juego2->getGenero() << endl;
    cout << "Id: " << juego << " Genero: " << juego->getGenero() << endl;


    sistema->agregarUsuarioNormal("Manuel", "123", 10);
    sistema->agregarAdmin("Cristian", "123", 20);
    sistema->agregarUsuarioNormal("Kaka", "123", 20);

    cout << sistema->getTipoUsuario("Manuel", "123") << endl;
    cout << sistema->getTipoUsuario("Kaka", "123") << endl;
    cout << sistema->getTipoUsuario("Cristian", "123") << endl;

    bool a = sistema->verificarAcceso("Cristian", "123");

    sistema->mostrarUsuarios();

    if(a)
    {
        cout << "funciona" << endl;
    }
    else 
    {
        cout << "nO funciona" << endl;
    }

    /*
    bool flag = true;
    while(flag)
    {
        login(sistema);
        flag = logout();
    }
    */

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

        case Usuario::USUARIO_MAYOR:
            mostrarMenuUsuario(nombre, clave, sistema);
            break;

        case Usuario::USUARIO_MENOR:
            mostrarMenuUsuario(nombre, clave, sistema);
            break;
        default:
            cout << "No se ha encontrado al tipo de usuario al que pertenece";
            break;
    }  
    cout << "Ha salido del programa con el usuario: " << nombre << " ...";
};

bool logout()
{
    do
    {
        cout << "-¿Deseas acceder con otro usuario?"
        << endl << "1) Acceder con otro Usuario"
        << endl << "2) Salir del programa"
        << endl << "Escoge una opción: ";
        int opc;
        cin >> opc;
        switch(opc)
        {
            case 1:
                return false;
            case 2:
                return true;
            default:
                cout << "Opción invalida, intente nuevamente" << endl;
                break;
        }
    }while(true);
};


void mostrarMenuAdmin(string nombre, string clave, Sistema* sistema)
{
    while(true)
    {
        cout << "Administrador: " << nombre 
        << endl << "1) Agregar Software" 
        << endl << "2) Eliminar Software"  
        << endl << "3) Acceder Software" 
        << endl << "4) Acceder al log"
        << endl << "5) Salir"
        << endl << "Escoge una opción: " ;
        int opc;
        cin >> opc;

        switch (opc)
        {
        case 1:
            agregarSoftware(nombre, clave, sistema);
            break;

        case 2:
            eliminarSoftware(nombre, clave, sistema);
            break;
        
        case 3:
            accederSoftware(nombre, clave, sistema);
            break;
        
        case 4:
            accederLog(nombre, clave, sistema);
            break;
        
        case 5: 
            return;
        default:
            cout << "Opción no válida" << endl;
            break;
        }
 
    }
};
void mostrarMenuUsuario(string nombre, string clave, Sistema* sistema)
{
    while(true)
    {
        cout << "Usuario: " << nombre 
        << endl << "1) Agregar Software" 
        << endl << "2) Eliminar Software"  
        << endl << "3) Acceder Software" 
        << endl << "4) Salir"
        << endl << "Escoge una opción: " ;
        int opc;
        cin >> opc;

        switch (opc)
        {
        case 1:
            agregarSoftware(nombre, clave, sistema);
            break;

        case 2:
            eliminarSoftware(nombre, clave, sistema);
            break;
        
        case 3:
            accederSoftware(nombre, clave, sistema);
            break;
        case 4: 
            cout << "Ha salido del menú Usuario";
            return;
        default:
            cout << "Opción no válida" << endl;
            break;
        }
 
    }
};


void agregarSoftware(string, string, Sistema*)
{

};
void eliminarSoftware(string, string, Sistema*)
{

};
void accederSoftware(string, string, Sistema*)
{

};
void accederLog(string, string, Sistema*)
{

};
