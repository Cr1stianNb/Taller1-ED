#include <iostream>

#include "Dominio/Software.cpp"
#include "Dominio/Usuario.cpp"
#include "Dominio/Juego.cpp"
#include "Logica/Sistema.cpp"
#include "Dominio/Administrador.cpp"
#include "Dominio/UsuarioMenor.cpp"
#include "Dominio/UsuarioMayor.cpp"
#include "Logica/VisitorUsuario.cpp"
#include "Logica/VisitorSoftware.cpp"
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

void agregarSoftware(string, string, Sistema&);
void eliminarSoftwareBiblioteca(string, string, Sistema*);
void eliminarSoftwareSesion(string, string, Sistema*);
void accederSoftware(string, string, Sistema*);
void accederLog(string, string, Sistema*);


void mostrarBiblioteca(Sistema*);

int main()
{

    Sistema* sistema = new Sistema();
    sistema->agregarAdmin("Cristian", "123", 20); 
    sistema->agregarUsuarioNormal("Manuel", "123", 10);
    sistema->agregarUsuarioNormal("Manuel", "123", 10);
    sistema->agregarUsuarioNormal("Manuel", "123", 10);
    sistema->agregarUsuarioNormal("Kaka", "123", 20); 
    Software* soft = new Navegador("Mario", "un japo", "toda edad", 9219.2);
    Software* soft2 = soft->clonar();
    VisitorSoftware* visitor = new VisitorSoftware();
    soft->visita(visitor);
    cout << visitor->getTipoSoftware() << endl;
    sistema->agregarJuego("Mario", "Japo", "toda edad", 912.1, "Adventuras");
    cout << sistema->agregarSoftwareUsuario("Cristian", "123", "Mario") << endl;
    cout << sistema->agregarSoftwareUsuario("Cristian", "123", "qwe") << endl;
    cout << sistema->eliminarSoftwareUsuario("Cristian", "123", "Mario") << endl;
    cout << sistema->getNombresSoftwares() << endl;
    
    
    
    agregarSoftware("Cristian", "123", *sistema);
    
    cout << sistema->getNombresSoftwares() << endl;

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
        << endl << "1) Agregar Software " 
        << endl << "2) Eliminar Software (Biblioteca General)"
        << endl << "3) Eliminar Software de tus sesiones"   
        << endl << "4) Acceder Software" 
        << endl << "5) Acceder al log"
        << endl << "6) Salir"
        << endl << "Escoge una opción: " ;
        int opc;
        cin >> opc;

        switch (opc)
        {
        case 1:
            agregarSoftware(nombre, clave, *sistema);
            break;

        case 2:
            eliminarSoftwareBiblioteca(nombre, clave, sistema);
            break;
        case 3:
            eliminarSoftwareSesion(nombre, clave, sistema);
            break;
        case 4:
            accederSoftware(nombre, clave, sistema);
            break;
        
        case 5:
            accederLog(nombre, clave, sistema);
            break;
        
        case 6: 
            cout << "Ha salido del menú administrador" << endl;
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
            agregarSoftware(nombre, clave, *sistema);
            break;

        case 2:
            eliminarSoftwareBiblioteca(nombre, clave, sistema);
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


void agregarSoftware(string nombre, string clave, Sistema& sistema)
{
    string nombreSoft;
    cout << "Ingrese el nombre del software: " << endl;
    cin >> nombreSoft;

    string developer;
    cout << "\nIngrese developer de " + nombreSoft + ": "<< endl;
    cin >> developer;

    int opcClasificacion;
    string clasificacion;
    cout << "\nIngrese clasificación de edad: " << endl
    << "1) " + Software::E << endl
    << "2) " + Software::A << endl
    << "-Escoge una opción: ";
    cin >> opcClasificacion;
    switch(opcClasificacion)
    {
        case 1:
            clasificacion = Software::E;
            break;
        case 2:
            clasificacion = Software::A;
            break;
        default:
            cout << "Opción no válida...\n se cancela agregación" << endl;
            return;
    }

    double precio;
    cout << "\nIngrese el precio del producto: " << endl;
    cin >> precio;

    int opcTipo;
    string nuevoSoft;
    cout << "Ingrese el tipo de software a ingresar: " << endl
    << "1) " + VisitorSoftware::JUEGO << endl
    << "2) " + VisitorSoftware::NAVEGADOR << endl
    << "3) " + VisitorSoftware::OFIMATICA << endl
    << "4) " + VisitorSoftware::PRODUCCION << endl
    << "5) " + VisitorSoftware::SEGURIDAD << endl
    << "6) " + VisitorSoftware::SOCIAL << endl
    << "-Escoge una opción: ";
    cin >> opcTipo;
    string genero = " ";
    bool a;
    switch(opcTipo)
    {
        case 1:
            while(!Juego::verificarGenero(genero))
            {
                cout << "Ingrese el género del Juego (1 de las siguientes opciones): " << endl << "("
                << GENEROS[0] + " , " + GENEROS[1] + " , "
                << GENEROS[2] + " , " + GENEROS[3] + " , "
                << GENEROS[4] + " , " + GENEROS[5] + " , "
                << GENEROS[6] + " , " + GENEROS[7] + " , "
                << GENEROS[8] + " , " + GENEROS[9] << ")" << endl; 
                cin >> genero;
            }

            a = sistema.agregarJuego(nombreSoft, developer, clasificacion, precio, genero);
            cout << a; 

            break;

        case 2:
            break;
        
        case 3:

            break;

        case 4:
            break;

        case 5:

            break;
        
        case 6:

            break;

        default:
            cout << "Opción incorrecta...\nSe cancela operación" << endl;
            return;

    };

    
    




};
void eliminarSoftwareBiblioteca(string, string, Sistema*)
{

};
void eliminarSoftwareSesion(string, string, Sistema*)
{

};
void accederSoftware(string, string, Sistema*)
{

};
void accederLog(string, string, Sistema*)
{

};
