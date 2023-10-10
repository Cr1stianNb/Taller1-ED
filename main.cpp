#include <iostream>
#include <thread> // this_thread::sleep_for
#include <chrono> // chrono::seconds

#include "Dominio/Software.cpp"
#include "Dominio/Usuario.cpp"
#include "Dominio/Juego.cpp"
#include "Logica/Sistema.cpp"
#include "Dominio/Administrador.cpp"
#include "Dominio/UsuarioMenor.cpp"
#include "Dominio/UsuarioMayor.cpp"
#include "Logica/VisitorUsuario.cpp"
#include "Logica/VisitorSoftware.cpp"
#include "Logica/VisitorSesionSoftware.cpp"
#include "Dominio/Navegador.cpp"
#include "Dominio/Ofimatica.cpp"
#include "Dominio/Produccion.cpp"
#include "Dominio/Seguridad.cpp"
#include "Dominio/Social.cpp"

using namespace std;

// Determina el comando a utilizar en system
const char* comandoCMD;

void determinarComando();
double parseDouble(string);
int parseInt(string);
void transicion(int);
void login(Sistema*);
bool logout();
void mostrarMenuAdmin(string, string, Sistema*);
void mostrarMenuUsuario(string, string, Sistema*);
void agregarSoftware(string, string, Sistema&);
void eliminarSoftwareBiblioteca(string, string, Sistema&);
void eliminarSoftwareSesion(string, string, Sistema&);
void accederSoftware(string, string, Sistema&);
void agregarUsuario(string, string, Sistema&);
bool eliminarUsuario(string, string, Sistema&);
void registrarSoftware(string, string, Sistema&, string);
void registrarSoftware(string, string, Sistema&);
bool verificarTodosLosUsuarios(vector<string>* listaUsuarios, string nombreSoft);
void mostrarBiblioteca(Sistema&);
void poblarBaseDatos(Sistema&);
void agregarAmigosPoblarDatos(Sistema&);


/**
 * @brief Función para transicionar entre menus
*/
void transicion(int segundos)
{
    cout << endl << "Espere un momento..." << endl;
    this_thread::sleep_for(chrono::seconds(segundos));
    system(comandoCMD);
};


/**
 * ParseDouble: mientras que el usuario no ponga por teclado un entero, continuara
 * @param string el contexto del número que se pide
 * @return un double
 * 
*/
double parseDouble(string contexto)
{
    bool flag = true;
    double numero;
    string entrada = "";
    do
    {
        cout << contexto << endl;
        getline(cin, entrada);
        try
        {
            numero = stod(entrada);
            flag = false;
        }
        catch(const invalid_argument& e)
        {
            cout << "Opcion no valida" << endl;
        }
        catch(const out_of_range& e1)
        {
            std::cerr << e1.what() << "\n";
        }
    } while (flag);
    return numero;
};

/**
 * ParseInt(): mientras que el usuario no ponga por teclado un entero, continuara
 * @param string el contexto del número que se pide
 * @return un double
 * 
*/
int parseInt(string contexto)
{
    bool flag = true;
    int numero;
    string entrada = "";
    do
    {
        cout << contexto << endl;
        getline(cin, entrada);
        try
        {
            numero = stoi(entrada);
            flag = false;
        }
        catch(const invalid_argument& e)
        {
            cout << "Opcion no valida" << endl;
        }
        catch(const out_of_range& e1)
        {
            std::cerr << e1.what() << "\n";
        }
    } while (flag);
    return numero;
};

void determinarComando()
{
    int opc;
    do{
    cout << "Que Sistema operativo ocupa?"
    << endl << "1) Windows"
    << endl << "2) Linux/Mac" << endl;
    opc = parseInt("Ingrese una opcion: ");
    }while(opc != 2 && opc != 1);

    switch(opc)
    {
        case 1:
            comandoCMD = "cls";
            break;
        
        case 2:
            comandoCMD = "clear";
            break;
        default:
            break;
    }

};

/**
Función main
*/
int main()
{
    determinarComando();
    Sistema* sistema = new Sistema();
    poblarBaseDatos(*sistema);
    agregarAmigosPoblarDatos(*sistema);
    bool flag = true;
    bool isEmptyUsuario = sistema->isEmptyUsuarios(); // No se ingresará al sistema sin haber usuarios previamente, para evitar errores.
    while(flag && !isEmptyUsuario) 
    {
        login(sistema);
        transicion(1.5);
        flag = logout();
        transicion(0.75);
    }
    if(isEmptyUsuario)
    {
        cout << "No tienes a ningun usuario en el sistema." << endl;
    }
    return 0;
}

/**
 * 
 * Función Login: Se encarga de verificar el acceso por teclado y mostrar los menús a los usuarios
 * @param sistema -> Se encarga administrar los procesos necesarios para la correcta funcionalidad de los menús
*/
void login(Sistema*sistema)
{
    cout << "Bienvenido al programa: Manejos Software" << endl;
    
    string nombre, clave;
    do
    {
        cout << "Ingrese Nombre Usuario: "; 
        getline(cin,nombre);
        cout << "Ingrese la clave: ";
        getline(cin, clave);
    } while (!sistema->verificarAcceso(nombre, clave));  // hasta que el usuario se encuentra
    
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

/**
 * Logout: Función que se encarga de verificar si el usuario quiere seguir en el programa o cambiar de sesión
 * @return true si quiere cambiar de usuario, false si desea salir del programa
*/
bool logout()
{
    do
    {
        cout << "\nDeseas acceder con otro usuario?"
        << endl << "1) Acceder con otro Usuario"
        << endl << "2) Salir del programa";
        int opc = parseInt("\nEscoge una opcion: ");
        switch(opc)
        {
            case 1:
                return true;
            case 2:
                return false;
            default:
                cout << "Opcion invalida, intente nuevamente" << endl;
                break;
        }
    }while(true);
};

/**
 * Muestra el menú admin.
 * @param string El nombre del usuario que inicio sesión
 * @param string la clave del usuario que inicio sesión
 * @param sistema contiene la lógica para cumplir los requerimientos
*/
void mostrarMenuAdmin(string nombre, string clave, Sistema* sistema)
{
    while(true)
    {
        transicion(2);
        cout << "Administrador: " << nombre 
        << endl << "1) Agregar Software (Biblioteca General) "
        << endl << "2) Registrar Software (Sesion personal)" 
        << endl << "3) Eliminar Software (Biblioteca General)"
        << endl << "4) Eliminar Software de tus sesiones"   
        << endl << "5) Agregar Usuario "
        << endl << "6) Eliminar Usuario " 
        << endl << "7) Acceder Software" 
        << endl << "9) Salir";
        int opc = parseInt("\nEscoge una opcion: ");
        

        bool seElimino;
        transicion(0);
        switch (opc)
        {
        case 1:
            agregarSoftware(nombre, clave, *sistema);
            break;
        case 2:
            registrarSoftware(nombre, clave, *sistema);
            break;

        case 3:
            eliminarSoftwareBiblioteca(nombre, clave, *sistema);
            break;
        case 4:
            eliminarSoftwareSesion(nombre, clave, *sistema);
            break;
        case 5:
            agregarUsuario(nombre, clave, *sistema);
            break;
        case 6:
            seElimino = eliminarUsuario(nombre, clave, *sistema);
            if(seElimino) return;
            break;
        case 7:
            accederSoftware(nombre, clave, *sistema);
            break;
        case 9: 
            cout << "Ha salido del menu administrador" << endl;
            return;
        default:
            cout << "Opcion no valida" << endl;
            break;
        }
 
    }
};

/**
 * Muestra el menú para los usuarios normales, ya sea mayor o menor de edad, ya que, son otras clases que verificarán la edad
 * Contiene menos opciones que el menú administrador
 * @param string nombre del usuario que inicio sesión
 * @param string clave del usuario que inicio sesión
 * @param sistema administra la lógica para cumplir los requerimientos del menú
*/
void mostrarMenuUsuario(string nombre, string clave, Sistema* sistema)
{
    while(true)
    {
        transicion(2);
        cout << "Usuario: " << nombre 
        << endl << "1) Agregar Software  (Biblioteca General)"
        << endl << "2) Registrar Software (Uso Personal)" 
        << endl << "3) Eliminar Software (Biblioteca General)"
        << endl << "4) Eliminar Software de tus sesiones"
        << endl << "5) Acceder Software"    
        << endl << "6) Salir";
        int opc = parseInt("\nEscoge una opcion: ");
        transicion(0);
        switch (opc)
        {
        case 1:
            agregarSoftware(nombre, clave, *sistema);
            break;
        
        case 2:
            registrarSoftware(nombre, clave, *sistema);
            break;

        case 3:
            eliminarSoftwareBiblioteca(nombre, clave, *sistema);
            break;
        
        case 4:
            eliminarSoftwareSesion(nombre, clave, *sistema);
            break;
        case 5:
            accederSoftware(nombre, clave, *sistema);
            break;
        case 6: 
            cout << "Ha salido del menu Usuario";
            return;
        default:
            cout << "Opcion no valida" << endl;
            break;
        }
 
    }
};

/**
 * AgregarUsuario:
 * Agrega un usuario a la biblioteca (sistema)
 * @param string nombre del usuario que inicio sesión
 * @param string clave del usuario que inicio sesión
 * @param sistema clase que implementa la lógica del programa
*/
void agregarUsuario(string nombre, string clave, Sistema& sistema)
{
    bool seAgrego = false;
    string nombreUsuario;
    cout << "Ingrese el nombre del Usuario: " << endl;
    getline(cin,nombreUsuario);

    
    int edad = parseInt("Ingrese la edad del usuario: ");
    while( edad < 6 || edad > 130)
    {
        cout << "Opción incorrecta, (6 < edad)";
        edad = parseInt("Ingrese la edad del usuario: ");
    }

    string claveNuevo;
    cout << "Ingrese la clave del usuario: " << endl;
    getline(cin,claveNuevo);

    string correo = "";
    if(edad > 18)
    {  
        cout << "Ingrese el correo del usuario: " << endl;
        getline(cin,correo);
    }

    string tipoUsuario;
    int opcTipo;
    do
    {
        cout << "Ingrese tipo de Usuario: " 
        << endl << "1) Admin"
        << endl << "2) Normal"
        << endl;
        opcTipo  = parseInt("Escoga una opcion: ");
    }  while(opcTipo != 1 && opcTipo != 2);

    switch (opcTipo)
    {
    case 1:
        
        seAgrego = sistema.agregarAdmin(nombreUsuario, claveNuevo, edad, correo);
        break;

    case 2:
        seAgrego = sistema.agregarUsuarioNormal(nombreUsuario, claveNuevo, edad, correo);
        break;
    
    default:
        cout << "Opcion no encontrada" << endl;
        break;
    }
    if(seAgrego)
    {
        cout << "Se ha agregado correctamente" << endl;
    }
    else 
    {
        cout << "El usuario que agregaste ya se encuentra en el sistema" << endl;
    }
    transicion(3);
};

/**
 * Elimina un usuario de la biblioteca general
 * @param string Usuario que inicio sesión
 * @param string clave del usuario
 * @param sistema clase que implementa la lógica
 * @return true si el usuario que se elimino es el mismo quien inicio sesión, es debido a que si se elimino el usuario es necesario que se deslogee automaticamente
 * false si es otro usuario
*/
bool eliminarUsuario(string nombre, string clave, Sistema& sistema)
{
    bool esEl = false;
    cout << "Ingrese el nombre del usuario a eliminar: " << endl;
    string nombreUsuario;
    getline(cin,nombreUsuario);

    if(nombre == nombreUsuario)
    {
        esEl = true;
    }

    bool eliminar = sistema.eliminarUsuario(nombreUsuario);

    if(eliminar)
    {
        cout << "Se elimino correctamente " << endl;
    }
    else 
    {
        cout << "No se pudo eliminar el usuario, debido a que no se encontro un usuario con nombre: " + nombreUsuario << endl;
    }

    return esEl;
};

/**
 * AgregarSoftware: Agrega un software a la biblioteca general 
 * @param string nombre del usuario que inicio sesión
 * @param string clave del usuario
 * @param sistema clase que implementa la lógica
 * 
*/
void agregarSoftware(string nombre, string clave, Sistema& sistema)

{
    string nombreSoft;
    cout << "Ingrese el nombre del software: " << endl;
    getline(cin, nombreSoft);

    string developer;
    cout << "\nIngrese developer de " + nombreSoft + ": "<< endl;
    getline(cin,developer);

    
    string clasificacion;
    cout << "\nIngrese clasificacion de edad: " << endl
    << "1) " + Software::E << endl
    << "2) " + Software::A << endl;
    int opcClasificacion = parseInt("-Escoge una opcion: ");

    switch(opcClasificacion)
    {
        case 1:
            clasificacion = Software::E;
            break;
        case 2:
            clasificacion = Software::A;
            break;
        default:
            cout << "Opcion no valida...\n se cancela agregacion" << endl;
            return;
    }
    double precio = parseDouble("\nIngrese el precio del producto: ");

    
    string nuevoSoft;
    cout << "Ingrese el tipo de software a ingresar: " << endl
    << "1) " + VisitorSoftware::JUEGO << endl
    << "2) " + VisitorSoftware::NAVEGADOR << endl
    << "3) " + VisitorSoftware::OFIMATICA << endl
    << "4) " + VisitorSoftware::PRODUCCION << endl
    << "5) " + VisitorSoftware::SEGURIDAD << endl
    << "6) " + VisitorSoftware::SOCIAL << endl;
    int opcTipo = parseInt("-Escoge una opcion: ");
    string genero = " ";
    string tipoSolucion = "";
    string malware = "";
    bool a;
    switch(opcTipo)
    {
        case 1:
            while(!Juego::verificarGenero(genero))
            {
                cout << "Ingrese el genero del Juego (1 de las siguientes opciones): " << endl << "("
                << GENEROS[0] + " , " + GENEROS[1] + " , "
                << GENEROS[2] + " , " + GENEROS[3] + " , "
                << GENEROS[4] + " , " + GENEROS[5] + " , "
                << GENEROS[6] + " , " + GENEROS[7] + " , "
                << GENEROS[8] + " , " + GENEROS[9] << ")" << endl; 
                getline(cin,genero);
            }

            if(sistema.agregarJuego(nombreSoft, developer, clasificacion, precio, genero))
            {
                cout << "Fue ingresado con exito" << endl;
            }
            else 
            {
                cout << "El nombre de la aplicacion ya existe en la biblioteca, por lo tanto no se agrego al repertorio" << endl;
            }
    
            break;

        case 2:

            if(sistema.agregarNavegador(nombreSoft, developer, clasificacion, precio))
            {
                cout << "Fue ingresado con exito" << endl;
            }
            else 
            {
                cout << "El nombre de la aplicacion ya existe en la biblioteca, por lo tanto no se agrego al repertorio" << endl;
            }
            break;
        
        case 3:
            if(sistema.agregarOfimatica(nombreSoft, developer, clasificacion, precio))
            {
                cout << "Fue ingresado con exito" << endl;
            }
            else 
            {
                cout << "El nombre de la aplicacion ya existe en la biblioteca, por lo tanto no se agrego al repertorio" << endl;
            }
            break;

        case 4:
            cout << "Advertencia: Al ser un software de tipo producción, la clasificación sera de tipo A  (Adulto)" << endl;
            while(!Produccion::verificarSolucion(tipoSolucion))
            {
                cout << "Ingrese el tipo de Solución del software (1 de las siguientes opciones): " << endl << "("
                << Produccion::VIDEO + " , "
                << Produccion::MUSICA + " , "
                << Produccion::STREAMING + " , "
                << Produccion::FOTOS + " ) "
                << endl; 
                getline(cin,tipoSolucion);
            }
            if(sistema.agregarProduccion(nombreSoft, developer, Software::A , precio, tipoSolucion))
            {
                cout << "Fue ingresado con exito" << endl;
            }
            else 
            {
                cout << "El nombre de la aplicacion ya existe en la biblioteca, por lo tanto no se agrego al repertorio" << endl;
            }

            break;

        case 5:

            while(!Seguridad::verificarMalware(malware))
            {
                cout << "Ingrese el tipo de malware del software (1 de las siguientes opciones): " << endl << "("
                << Seguridad::RANSOMWARE + " , "
                << Seguridad::BOTNETS + " , "
                << Seguridad::TROYANOS + " , "
                << Seguridad::GUSANOS + " , "
                << Seguridad::ROOTKITS + " , "
                << Seguridad::SPYWARE + " )"
                << endl; 
                getline(cin,malware);
            }
            if(sistema.agregarProduccion(nombreSoft, developer, clasificacion , precio, malware))
            {
                cout << "Fue ingresado con exito" << endl;
            }
            else 
            {
                cout << "El nombre de la aplicación ya existe en la biblioteca, por lo tanto no se agrego al repertorio" << endl;
            }

            break;
        
        case 6:

            if(sistema.agregarSocial(nombreSoft, developer, clasificacion, precio))
            {
                cout << "Fue ingresado con exito" << endl;
            }
            else 
            {
                cout << "El nombre de la aplicacion ya existe en la biblioteca, por lo tanto no se agrego al repertorio" << endl;
            }
            break;

            break;

        default:
            cout << "Opcion incorrecta...\nSe cancela operacion" << endl;
            return;

    };
};

/**
 * EliminarSoftwareBiblioteca: Elimina un software de la biblioteca general
 * @param string nombre del usuario que inicio sesión
 * @param string clave del usuario
 * @param sistema clase que implementa la lógica del programa
*/
void eliminarSoftwareBiblioteca(string nombre , string clave, Sistema& sistema)
{
    cout << "Ingrese el nombre del software a ELIMINAR en la Biblioteca: (Se pedira autorizacion si es que existe otro usuario utilizando la app)" << endl;
    cout << sistema.getNombresSoftwares() << endl;
    string nombreSoftware;
    getline(cin,nombreSoftware);
    vector<string>* listaUsuario = sistema.getNombresUsuariosSoftware(nombreSoftware);
    if(listaUsuario == nullptr) cout << "El nombre del software no se encontro..." << endl;
    else
    {
        if(verificarTodosLosUsuarios(listaUsuario, nombreSoftware))
        {
            cout << "Se eliminara el software  de la biblioteca general" + nombreSoftware << endl;
            sistema.eliminarSoftwareBiblioteca(nombreSoftware);
        }
        else 
        {
            cout  << " , no se elimino la Aplicacion..." << endl;
        }
    }
    transicion(5);

};

/**
 * verificarTodosLosUsuarios: Verifica a todos los usuarios que utilizan determinado software , si quieren eliminar al software
 * @param listaUsuario la lista de nombres de los usuarios en el sistema
 * @param nombreSoft nombre del software a eliminar
 * @return true si todos los usuarios quieren eliminar el software, false si al menos uno no desea eliminarlo
*/
bool verificarTodosLosUsuarios(vector<string>* listaUsuario, string nombreSoft)
{
    bool eliminar = true;
    int opc = 0 ;
    for(int i=0; i<listaUsuario->size();i++)
    {
        cout << "Nombre de Usuario: " << listaUsuario->at(i) << " Deseas eliminar el software: " + nombreSoft + "?" 
        << endl << "1) Si"
        << endl << "2) No" 
        << endl;
        opc = parseInt("Escoge una opcion: ");

        switch(opc)
        {
            case 1:
                break;
            case 2:
                eliminar = false;
                cout << "El usuario " << listaUsuario->at(i) << "Se nego a eliminar el software";
                return eliminar;
            default:
                cout << "No se eliminara debido a una opcion incorrecta..." << endl;
                return false;
        }
    }
    return eliminar;
};

/**
 * eliminarSoftwareSesion: Elimina un software (copia) en los registros de un usuario determinado
 * @param string nombre del usuario 
 * @param string clave del usuario que desea eliminar un registro de un software
 * @param sistema clase que implementa la lógica
*/
void eliminarSoftwareSesion(string nombre, string clave, Sistema& sistema)
{
    string nombreSoft;
    cout << sistema.getNombresSoftwaresUsuario(nombre, clave) << endl;
    cout << "Ingresa el nombre del software a eliminar de la sesion activa: " << endl;
    getline(cin,nombreSoft);
    bool estaEliminado = sistema.eliminarSoftwareUsuario(nombre, clave, nombreSoft);
    if(estaEliminado) 
    {
        cout << "Se ha eliminado correctamente" << endl;
    }
    else
    {
        cout << "No se ha podido eliminar, nombre de programa no encontrado en tus sesiones..." << endl;
    }
};

/**
 * registrarSoftware:  usuario registra un software a sus accesos (copias de softwares)
 * @param string nombre del usuario
 * @param string clave del usuario
 * @param Sistema clase que implementa la lógica
*/
void registrarSoftware(string nombre, string clave , Sistema& sistema)
{  
    if(!sistema.verificarAcceso(nombre, clave) || sistema.isEmptySoftwares()) return; //Si no se encuentra el usuario, no continuar
   
    string nombreSoft;
    do 
    {
        cout << "Registrar un software (Uno no existente en sus registros personales)" 
        << endl << sistema.getNombresSoftwares()
        << endl << "Ingrese el nombre del software a registrar: ";
        getline(cin,nombreSoft);
    }
    while(!sistema.existeSoftware(nombreSoft));
  
    bool ingresado = false;
    transicion(1);
    
    if(((sistema.getSoftware(nombreSoft)->getClasificacion() == Software::A) && sistema.getEdadUsuario(nombre) < 18))
    {
        cout << "No eres apto para registrarte a esta aplicacion vuelve cuando hayas crecido :) " << endl;
    }
    else 
    {
        ingresado = sistema.agregarSoftwareUsuario(nombre, clave, nombreSoft);
    }

    if(ingresado)
    {
        cout << "Se ha registrado el software: " << nombreSoft << " correctamente al usuario: " + nombre << endl;
    }
    else 
    {
        cout << "No se pudo ingresal el software " << nombreSoft << " al usuario..." << endl;
    }
};   

/**
 * registrarSoftware:  usuario registra un software a sus accesos (copias de softwares)
 * @param string nombre del usuario
 * @param string clave del usuario
 * @param Sistema clase que implementa la lógica
 * @param string nombre del software
*/
void registrarSoftware(string nombre, string clave , Sistema& sistema, string nombreSoft)
{  
        if(!((sistema.getSoftware(nombreSoft)->getClasificacion() == Software::A) && sistema.getEdadUsuario(nombre) < 18))
        {
            sistema.agregarSoftwareUsuario(nombre, clave, nombreSoft);
        }
};   
/**
 * accederSoftware: Usuario accede a uno de sus registros (copias creadas anteriormente)
 * @param nombre nombre del usuario que desea acceder
 * @param clave clave del usuario
 * @param sistema instancia que implementa la lógica
 * 
 * Si el usuario no tiene registros, no se accede a ningún software
 * Si la biblioteca no tiene software no se accederá al método
*/
void accederSoftware(string nombre , string clave, Sistema& sistema)
{
    if(sistema.isEmptyRegistrosUsuario(nombre, clave))
    {
        cout << "No existen sesiones en tus registros, registrate a un software antes de acceder" << endl;
        return;
    }

    string nombreSoftware = "";
    do{
    cout 
    << sistema.getNombresSoftwaresUsuario(nombre, clave)
    << endl 
    << "Ingrese el nombre del software a acceder: ";
    getline(cin,nombreSoftware);
    }while(!sistema.existeSoftwareUsuario(nombre, clave, nombreSoftware));

    
    bool accedio = sistema.accederSoftware(nombre, clave, nombreSoftware);
    if(!accedio)
    {
        cout << "\n El nombre del software que ingresaste no existe en tu repertorio..." << endl;
    }
    transicion(1.2);
};



void poblarBaseDatos(Sistema& sistema)
{
    sistema.agregarAdmin("Cristian","123", 20, "cristian@admin.cl");  // Admin 

    /*Inicio Instancias Usuarios Mayores*/
    sistema.agregarUsuarioNormal("Jose", "123", 30, "jose@normal.cl");
    sistema.agregarUsuarioNormal("Manuel", "hs123", 40, "manuel@normal.cl");
    sistema.agregarUsuarioNormal("Andres", "km12", 33, "andres@normal.cl");
    sistema.agregarUsuarioNormal("Moia", "grmos", 19, "usuarioNormal@aaa.cl");
    sistema.agregarUsuarioNormal("Shelly","asd123",23, "shelly@normal.cl");
    sistema.agregarUsuarioNormal("Colt", "coltNice", 90, "terceraEdad@normal.cl");
    sistema.agregarUsuarioNormal("bluefox", "jijia", 50, "bluefox@normal.cl");
    sistema.agregarUsuarioNormal("doblangel", "claramente", 34, "aparentemente@normal.cl");
    sistema.agregarUsuarioNormal("oscarrojas", "godines", 60, "oscarsito123@normal.cl");
    sistema.agregarUsuarioNormal("dj_garay", "vegetaDg", 21, "vegeta@dragonBoll.cl");
    /*Final Instancia Usuarios Mayores*/

    /*Inicia Instancias Usuarios Menores*/
    sistema.agregarUsuarioNormal("Augusto", "123", 10);
    sistema.agregarUsuarioNormal("Nina", "gavo", 9);
    sistema.agregarUsuarioNormal("Senda", "senda3000" ,13);
    sistema.agregarUsuarioNormal("Narla", "123", 14);
    /*Final Instancias Usuarios Menores*/


    /*Inicio Intancias Softwares*/
    
    /*Inicio Instancia Juegos*/
    /* {"FPS", "Visual novel", "PUZZLE", "PLATAFORMERO", "RPG", "HORROR", "ESTRATEGIA", "DEPORTES", "ACCIÓN", "ADVENTURAS"};*/
    sistema.agregarJuego("Grand Theft Auto V", "Rockstar North",Software::A, 29.99, GENEROS[9]);
    sistema.agregarJuego("The Witcher 3: Wild Hunt", "CD Projekt",Software::E, 39.99, GENEROS[9]);
    sistema.agregarJuego("Red Dead Redemption 2", "Rockstar Games",Software::E, 59.99, GENEROS[8]);
    sistema.agregarJuego("Brawl Stars", "SUPERCELL", Software::E, 49.99, GENEROS[8]);
    sistema.agregarJuego("FIFA23", "EA", Software::E, 29.99, GENEROS[7]);
    sistema.agregarJuego("PES2012", "Konami", Software::E, 39.99, GENEROS[7]);
    sistema.agregarJuego("Minecraft", "Mojang Studios",Software::E, 19.99, GENEROS[6]);
    sistema.agregarJuego("Fortnite", "Epic Games",Software::E, 0.00, GENEROS[6]);
    sistema.agregarJuego("Saya no Uta", "Nitroplus", Software::A, 59.99, GENEROS[5]);
    sistema.agregarJuego("Higurashi no Naku Koro ni", "Expansion", Software::A, 19.99, GENEROS[5]);
    sistema.agregarJuego("Pokemon Equipo de rescate rojo", "The pokemon company", Software::E, 49.99, GENEROS[4]);
    sistema.agregarJuego("Final Fantasy VII", "Square Enix", Software::E, 29.99, GENEROS[4]);
    sistema.agregarJuego("Mario bros", "Nintendo", Software::E, 39.99, GENEROS[3]);
    sistema.agregarJuego("Sonic", "Sega", Software::E, 59.99, GENEROS[3]);
    sistema.agregarJuego("Candy Crush", "King", Software::E, 19.99, GENEROS[2]);
    sistema.agregarJuego("Tetris", "Alekséi Pázhitnov", Software::E, 19.99, GENEROS[2]);
    sistema.agregarJuego("Fate stay night", "Type Moon", Software::A, 29.99, GENEROS[1]);
    sistema.agregarJuego("Steins gate ", "Nitroplus", Software::E, 39.99, GENEROS[1]);
    sistema.agregarJuego("Fornite", "Epic games", Software::E, 59.99, GENEROS[0]);
    sistema.agregarJuego("CSGO", "Valve", Software::A, 19.99, GENEROS[0]);
    /*\Final Instancia Juegos*/

    /*Intancias de Ofimatica*/
    sistema.agregarOfimatica("Word","Microsoft",Software::E, 43.3);
    sistema.agregarOfimatica("Atom","Github",Software::E, 0);
    sistema.agregarOfimatica("Excel","Microsoft",Software::E, 23.53);
    sistema.agregarOfimatica("PowerPoint","Microsoft",Software::E, 23.53);
    sistema.agregarOfimatica("Google Docs","Google",Software::E, 0);
    /*Intancias de Ofimatica*/

    /*Instancia de Produccion*/
    sistema.agregarProduccion("Photoshop","Adobe",Software::A, 90.1,Produccion::FOTOS);
    sistema.agregarProduccion("Manim","Manim Community",Software::A, 0,Produccion::VIDEO);
    sistema.agregarProduccion("FL studio","Imagine Line",Software::A, 0,Produccion::MUSICA);
    sistema.agregarProduccion("StreamLabs OBS","Jim",Software::A , 0 , Produccion::STREAMING);
    /*\Instancia de Produccion*/

    /*Instancia de Navegador*/
    sistema.agregarNavegador("Chrome","Google",Software::E, 0);
    sistema.agregarNavegador("Microsoft EDge","Microsoft",Software::E, 0);
    /*\Instancia de Navegador*/

    /*Instancia de Seguridad*/
    sistema.agregarSeguridad("Windows Defender", "Microsoft", Software::A, 1, Seguridad::RANSOMWARE);
    sistema.agregarSeguridad("Norton Antivirus", "NortonLifeLock", Software::A, 10.1, Seguridad::TROYANOS);
    sistema.agregarSeguridad("McAfee", "McAfee", Software::E, 40.1, Seguridad::SPYWARE);
    sistema.agregarSeguridad("BitDefender", "Bitdefender", Software::E, 60.3, Seguridad::ROOTKITS);
    sistema.agregarSeguridad("Avast", "Avast Software", Software::A, 101, Seguridad::GUSANOS);
    sistema.agregarSeguridad("Sophos Antivirus", "Sophos group", Software::E, 1.12, Seguridad::BOTNETS);
    /*Instancia de Seguridad*/

    /*Instancia de Social*/
    sistema.agregarSocial("Instagram", "Meta", Software::E, 0);
    sistema.agregarSocial("Omegle", "Omegle", Software::A, 0);
    /*Instancia de Social*/
};


void agregarAmigosPoblarDatos(Sistema& sistema)
{
    vector<Usuario*>* listaUsuario = sistema.getListaUsuario();
    for(int i=0; i<listaUsuario->size();i++)
    {
        registrarSoftware(listaUsuario->at(i)->getNombre(), listaUsuario->at(i)->getClave(), sistema, "Instagram");
        registrarSoftware(listaUsuario->at(i)->getNombre(), listaUsuario->at(i)->getClave(), sistema, "Omegle");
    }    
    vector<string>* sociales = new vector<string>(0);
    sociales->push_back("Instagram");
    sociales->push_back("Omegle");
    Social* app;

    for(int i=0; i<sociales->size();i++)
    {
        app = dynamic_cast<Social*>(sistema.getUsuario("Cristian","123")->getSoftware(sociales->at(i)));
        app->asociarUsuario("Cristian");
        app->agregarAmigo(sistema.getUsuario("Manuel", "hs123"));
        app->agregarAmigo(sistema.getUsuario("Jose", "123"));
        app = dynamic_cast<Social*>(sistema.getUsuario("Manuel", "hs123")->getSoftware(sociales->at(i)));
        app->asociarUsuario("Manuel");
        app->agregarAmigo(sistema.getUsuario("Jose", "123"));


        app = dynamic_cast<Social*>(sistema.getUsuario("Andres", "km12")->getSoftware(sociales->at(i)));
        app->asociarUsuario("Andres");
        app->agregarAmigo(sistema.getUsuario("Moia", "grmos"));
        app->agregarAmigo(sistema.getUsuario("Shelly","asd123"));
        app = dynamic_cast<Social*>(sistema.getUsuario("Moia", "grmos")->getSoftware(sociales->at(i)));
        app->asociarUsuario("Moia");
        app->agregarAmigo(sistema.getUsuario("Shelly","asd123"));

        app = dynamic_cast<Social*>(sistema.getUsuario("Colt", "coltNice")->getSoftware(sociales->at(i)));
        app->asociarUsuario("Colt");
        app->agregarAmigo(sistema.getUsuario("bluefox", "jijia"));
        app->agregarAmigo(sistema.getUsuario("doblangel", "claramente"));
        app = dynamic_cast<Social*>(sistema.getUsuario("doblangel", "claramente")->getSoftware(sociales->at(i)));
        app->asociarUsuario("doblangel");
        app->agregarAmigo(sistema.getUsuario("bluefox", "jijia"));

        app = dynamic_cast<Social*>(sistema.getUsuario("oscarrojas", "godines")->getSoftware(sociales->at(i)));
        app->asociarUsuario("oscarrojas");
        app->agregarAmigo(sistema.getUsuario("dj_garay", "vegetaDg"));
        app->agregarAmigo(sistema.getUsuario("Cristian", "123"));
        
        app = dynamic_cast<Social*>(sistema.getUsuario("Cristian", "123")->getSoftware(sociales->at(i)));
        app->agregarAmigo(sistema.getUsuario("dj_garay", "vegetaDg"));
    }
    
    
    app = dynamic_cast<Social*>(sistema.getUsuario("Nina", "gavo")->getSoftware("Instagram"));
    app->asociarUsuario("Nina");
    app->agregarAmigo(sistema.getUsuario("Senda", "senda3000"));
    app->agregarAmigo(sistema.getUsuario("Narla", "123"));
    app->agregarAmigo(sistema.getUsuario("Augusto", "123"));
    app = dynamic_cast<Social*>(sistema.getUsuario("Augusto", "123")->getSoftware("Instagram"));
    app->asociarUsuario("Augusto");
    app->agregarAmigo(sistema.getUsuario("Senda", "senda3000"));
    app->agregarAmigo(sistema.getUsuario("Narla", "123"));


    
};

