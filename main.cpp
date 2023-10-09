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


bool parseInt(string);
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
void registrarSoftware(string, string, Sistema&);
void accederLog(string, string, Sistema&);
bool verificarTodosLosUsuarios(vector<string>* listaUsuarios, string nombreSoft);
void mostrarBiblioteca(Sistema&);
void poblarBaseDatos(Sistema&);


/**
 * @brief Función para transicionar entre menus
*/
void transicion(int segundos)
{
    cout << endl << "Espere un momento..." << endl;
    this_thread::sleep_for(chrono::seconds(segundos));
    system("clear");
};


/**
 * ParseInt(): intenta transformar un string en int,
 * @param algo, string a verificar
 * @return true si se puede transformar
 * false caso contrario
*/
bool parseInt(string algo)
{
    try
    {
        int numero = stoi(algo);
        return true;
    }
    catch(const invalid_argument& e)
    {
        std::cerr << e.what() << '\n';
    }
    catch(const out_of_range& e1)
    {
        std::cerr << e1.what() << "\n";
    }
    return false;
    
};



/**
Función main
*/
int main()
{
    Sistema* sistema = new Sistema();
    poblarBaseDatos(*sistema);
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
        cout << "No tienes a ningún usuario en el sistema." << endl;
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
        cin >> nombre;
        cout << "Ingrese la clave: ";
        cin >> clave;
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
        cout << "\n-¿Deseas acceder con otro usuario?"
        << endl << "1) Acceder con otro Usuario"
        << endl << "2) Salir del programa"
        << endl << "Escoge una opción: ";
        int opc;
        cin >> opc;
        switch(opc)
        {
            case 1:
                return true;
            case 2:
                return false;
            default:
                cout << "Opción invalida, intente nuevamente" << endl;
                break;
        }
    }while(true);
};

/**
 * Muestra el menú admin.
 * @param nombre El nombre del usuario que inicio sesión
 * @param clave la clave del usuario que inicio sesión
 * @param sistema contiene la lógica para cumplir los requerimientos
*/
void mostrarMenuAdmin(string nombre, string clave, Sistema* sistema)
{
    while(true)
    {
        transicion(2);
        cout << "Administrador: " << nombre 
        << endl << "1) Agregar Software (Biblioteca General) "
        << endl << "2) Registrar Software (Sesión personal)" 
        << endl << "3) Eliminar Software (Biblioteca General)"
        << endl << "4) Eliminar Software de tus sesiones"   
        << endl << "5) Agregar Usuario "
        << endl << "6) Eliminar Usuario " 
        << endl << "7) Acceder Software" 
        << endl << "8) Acceder al log"
        << endl << "9) Salir"
        << endl << "Escoge una opción: " ;
        int opc;

        cout << endl << endl << endl << "spftwares copias "<<sistema->getUsuario(nombre, clave)->getListaSoftware()->size() ;
        cin >> opc;
        bool seElimino;
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
        
        case 8:
            accederLog(nombre, clave, *sistema);
            break;
        
        case 9: 
            cout << "Ha salido del menú administrador" << endl;
            return;
        default:
            cout << "Opción no válida" << endl;
            break;
        }
 
    }
};

/**
 * Muestra el menú para los usuarios normales, ya sea mayor o menor de edad, ya que, son otras clases que verificarán la edad
 * Contiene menos opciones que el menú administrador
 * @param nombre nombre del usuario que inicio sesión
 * @param clave clave del usuario que inicio sesión
 * @param sistema administra la lógica para cumplir los requerimientos del menú
*/
void mostrarMenuUsuario(string nombre, string clave, Sistema* sistema)
{
    while(true)
    {
        cout << "Usuario: " << nombre 
        << endl << "1) Agregar Software  (Biblioteca General)"
        << endl << "2)  Registrar Software (Uso Personal)" 
        << endl << "3) Eliminar Software (Biblioteca General)"
        << endl << "4) Eliminar Software de tus sesiones"
        << endl << "5) Acceder Software"    
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
            cout << "Ha salido del menú Usuario";
            return;
        default:
            cout << "Opción no válida" << endl;
            break;
        }
 
    }
};

/**
 * AgregarUsuario:
 * Agrega un usuario a la biblioteca (sistema)
 * @param nombre nombre del usuario que inicio sesión
 * @param clave clave del usuario que inicio sesión
 * @param sistema clase que implementa la lógica del programa
*/
void agregarUsuario(string nombre, string clave, Sistema& sistema)
{
    string nombreUsuario;
    cout << "Ingrese el nombre del Usuario: " << endl;
    cin >> nombreUsuario;

    int edad;
    string stringEdad;
    cout << "Ingrese la edad del usuario: " << endl;
    cin >> edad;

    while(!parseInt(stringEdad) || stoi(stringEdad) < 6)
    {
        cout << "Opción incorrecta, (6 < edad)";
        cout << "Ingrese la edad del usuario: " << endl;
        cin >> stringEdad;
    }

    string claveNuevo;
    cout << "Ingrese la clave del usuario: " << endl;
    cin >> claveNuevo;

    string correo = "";
    if(edad > 18)
    {  
        cout << "Ingrese el correo del usuario: " << endl;
        cin >> correo;
    }

    string tipoUsuario;
    int opcTipo;
    do
    {
        cout << "Ingrese tipo de Usuario: " 
        << endl << "1) Normal"
        << endl << "2) Admin"
        << endl << "Escoga una opción: " << endl;
        cin >> opcTipo;
    }  while(opcTipo != 1 && opcTipo != 2);

    switch (opcTipo)
    {
    case 1:
        
        sistema.agregarAdmin(nombreUsuario, claveNuevo, edad, correo);
        break;

    case 2:
        sistema.agregarUsuarioNormal(nombreUsuario, claveNuevo, edad, correo);
        break;
    
    default:
        cout << "Opción no encontrada" << endl;
        break;
    }
};

/**
 * Elimina un usuario de la biblioteca general
 * @param nombre Usuario que inicio sesión
 * @param clave clave del usuario
 * @param sistema clase que implementa la lógica
 * @return true si el usuario que se elimino es el mismo quien inicio sesión, es debido a que si se elimino el usuario es necesario que se deslogee automaticamente
 * false si es otro usuario
*/
bool eliminarUsuario(string nombre, string clave, Sistema& sistema)
{
    bool esEl = false;
    cout << "Ingrese el nombre del usuario a eliminar: " << endl;
    string nombreUsuario;
    cin >> nombreUsuario;

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
 * @param nombre nombre del usuario que inicio sesión
 * @param clave clave del usuario
 * @param sistema clase que implementa la lógica
 * 
*/
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
    string tipoSolucion = "";
    string malware = "";
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

            if(sistema.agregarJuego(nombreSoft, developer, clasificacion, precio, genero))
            {
                cout << "Fue ingresado con éxito" << endl;
            }
            else 
            {
                cout << "El nombre de la aplicación ya existe en la biblioteca, por lo tanto no se agrego al repertorio" << endl;
            }
    
            break;

        case 2:

            if(sistema.agregarNavegador(nombreSoft, developer, clasificacion, precio))
            {
                cout << "Fue ingresado con éxito" << endl;
            }
            else 
            {
                cout << "El nombre de la aplicación ya existe en la biblioteca, por lo tanto no se agrego al repertorio" << endl;
            }
            break;
        
        case 3:
            if(sistema.agregarOfimatica(nombreSoft, developer, clasificacion, precio))
            {
                cout << "Fue ingresado con éxito" << endl;
            }
            else 
            {
                cout << "El nombre de la aplicación ya existe en la biblioteca, por lo tanto no se agrego al repertorio" << endl;
            }
            break;

        case 4:
            cout << "Advertencia: Al ser un software de tipo producción, la clasificación será de tipo A  (Adulto)" << endl;
            while(!Produccion::verificarSolucion(tipoSolucion))
            {
                cout << "Ingrese el tipo de Solución del software (1 de las siguientes opciones): " << endl << "("
                << Produccion::VIDEO + " , "
                << Produccion::MUSICA + " , "
                << Produccion::STREAMING + " , "
                << Produccion::FOTOS + " ) "
                << endl; 
                cin >> tipoSolucion;
            }
            if(sistema.agregarProduccion(nombreSoft, developer, Software::A , precio, tipoSolucion))
            {
                cout << "Fue ingresado con éxito" << endl;
            }
            else 
            {
                cout << "El nombre de la aplicación ya existe en la biblioteca, por lo tanto no se agrego al repertorio" << endl;
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
                cin >> malware;
            }
            if(sistema.agregarProduccion(nombreSoft, developer, clasificacion , precio, malware))
            {
                cout << "Fue ingresado con éxito" << endl;
            }
            else 
            {
                cout << "El nombre de la aplicación ya existe en la biblioteca, por lo tanto no se agrego al repertorio" << endl;
            }

            break;
        
        case 6:

            if(sistema.agregarSocial(nombreSoft, developer, clasificacion, precio))
            {
                cout << "Fue ingresado con éxito" << endl;
            }
            else 
            {
                cout << "El nombre de la aplicación ya existe en la biblioteca, por lo tanto no se agrego al repertorio" << endl;
            }
            break;

            break;

        default:
            cout << "Opción incorrecta...\nSe cancela operación" << endl;
            return;

    };
};

/**
 * EliminarSoftwareBiblioteca: Elimina un software de la biblioteca general
 * @param nombre nombre del usuario que inicio sesión
 * @param clave clave del usuario
 * @param sistema clase que implementa la lógica del programa
*/
void eliminarSoftwareBiblioteca(string nombre , string clave, Sistema& sistema)
{
    cout << "Ingrese el nombre del software a ELIMINAR en la Biblioteca: (Se pedira autorización si es que existe otro usuario utilizando la app)" << endl;
    string nombreSoftware;
    cin >> nombreSoftware;
    vector<string>* listaUsuario = sistema.getNombresUsuariosSoftware(nombreSoftware);
    if(listaUsuario == nullptr) cout << "El nombre del software no se encontro..." << endl;
    else
    {
        if(verificarTodosLosUsuarios(listaUsuario, nombreSoftware))
        {
            cout << "Se eliminará el software  de la biblioteca general" + nombreSoftware << endl;
            sistema.eliminarSoftwareBiblioteca(nombreSoftware);
        }
        else 
        {
            cout  << " , no se elimino la Aplicación..." << endl;
        }
    }
    cout << "El tamaño de la lista es: " << listaUsuario->size() << endl;
    this_thread::sleep_for(chrono::seconds(10));

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
        cout << "Nombre de Usuario: " << listaUsuario->at(i) << " ¿Deseas eliminar el software: " + nombreSoft + "?" 
        << endl << "1) Si" << endl << "2) No" << endl << "Escoge una opción: ";
        cin >> opc;

        switch(opc)
        {
            case 1:
                break;
            case 2:
                eliminar = false;
                cout << "El usuario " << listaUsuario->at(i) << "Se negó a eliminar el software";
                return eliminar;
            default:
                cout << "No se eliminará debido a una opción incorrecta..." << endl;
                return false;
        }
    }
    return eliminar;
};

/**
 * eliminarSoftwareSesion: Elimina un software (copia) en los registros de un usuario determinado
 * @param nombre nombre del usuario 
 * @param clave clave del usuario que desea eliminar un registro de un software
 * @param sistema clase que implementa la lógica
*/
void eliminarSoftwareSesion(string nombre, string clave, Sistema& sistema)
{
    string nombreSoft;
    cout << sistema.getNombresSoftwaresUsuario(nombre, clave) << endl;
    cout << "Ingresa el nombre del software a eliminar de la sesión activa: " << endl;
    cin >> nombreSoft;
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
 * @param nombre nombre del usuario
 * @param clave clave del usuario
 * @param sistema clase que implementa la lógica
*/
void registrarSoftware(string nombre, string clave , Sistema& sistema)
{  
    if(!sistema.verificarAcceso(nombre, clave)) return; //Si no se encuentra el usuario, no continuar
    string nombreSoft;
   
    cout << "Registrar un software (Uno no existente en sus registros personales)" 
    << endl << sistema.getNombresSoftwares()
    << endl << "Ingrese el nombre del software a registrar: ";
    cin >> nombreSoft;


    bool ingresado = sistema.agregarSoftwareUsuario(nombre, clave, nombreSoft);

    if(ingresado)
    {
        cout << "Se ha registrado el software correctamente al usuario: " + nombre << endl;
    }
    else 
    {
        cout << "No se pudo ingresal el software al usuario..." << endl;
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
    string nombreSoftware = "";
    
    cout << sistema.getNombresSoftwares() // Muestra todos los nombres de softwares existentes
    << endl << "Ingrese el nombre del software a acceder: ";
    cin >> nombreSoftware;


    if(nombreSoftware == "") // Si no existen softwares en el sistema
    {
        cout << "No existen softwares en la biblioteca..., no puedes acceder porque no existen aplicaciones" << endl;
        return;
    }
    else if(sistema.isEmptyRegistrosUsuario(nombre, clave)) // Si no tiene registros el usuario
    {
        cout << "No te has registrado a ninguna aplicación...no puedes acceder sin haber registrado aplicaciones previamente" << endl;
        return;
    }
    cout << nombreSoftware << nombreSoftware << endl;
    sistema.accederSoftware(nombre, clave, nombreSoftware); // no va a ejecutar el codigo si el nombre del software no se encuentra en el sistema
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
    sistema.agregarSeguridad();
    /*Instancia de Seguridad*/

    /*Instancia de Social*/
    sistema.agregarSocial();
    /*Instancia de Social*/
};

void accederLog(string nombre, string clave, Sistema& sistema)
{

};
