#include "VisitorSesionSoftware.h"
#include "VisitorUsuario.h"
#include "Sistema.h"
VisitorSesionSoftware::VisitorSesionSoftware(Sistema *sistema)
{
    this->sistema = sistema;
};


VisitorSesionSoftware::~VisitorSesionSoftware(){};

void VisitorSesionSoftware::acepta(Juego &juego, Usuario *usuario)
{
    if(juego.getClasificacion() == Software::A && usuario->getEdad() < 18)
    {
        cout << "Lo sentimos pero eres menor de edad para acceder a esta aplicación...\nvuelve cuando seas mas grande ;)" << endl;
        return;
    }
    cout << "Sesión: " + usuario->getNombre() << endl;
    cout << "Juego: " << juego.getNombre() << " Género: " << juego.getGenero() << endl 
    << endl << "1) Cantidad de horas jugadas"
    << endl << "2) Jugar"
    << endl << "Ingrese una opción: " << endl;
    int opc = 0;
    cin >> opc;

    while(opc != 1 && opc != 2 )
    {
        cout 
        << endl << "1) Cantidad de horas jugadas"
        << endl << "2) Jugar"
        << endl << "Ingrese una opción: " << endl;
        cin >> opc;
    }
    double horas;
    switch (opc)
    {
    case 1:
        cout << "Las horas que has jugado son...." << juego.getHorasJugadas() << "nada mal" << endl;
        if(juego.getHorasJugadas() > 1000) cout << "Que vicio :P" << endl;
        break;

    case 2:
        do{
            if(horas < 0) cout << " quieres recuperar tu tiempo :(" << endl;
            cout << "Cuantas horas quieres agregar? " << endl;
            cin >> horas;
        }while(horas < 0);

        juego.agregarHorasJugadas(horas);
        cout << "Se han agregado tus horas en el registro " << endl;
        break;
    default:

        cout << "Error al ingresar la opción" << endl;
        break;
    }
};

void VisitorSesionSoftware::acepta(Navegador& navegador, Usuario* usuario)
{
    if(navegador.getClasificacion() == Software::A && usuario->getEdad() < 18)
    {
        cout << "Lo sentimos pero eres menor de edad para acceder a esta aplicación...\nvuelve cuando seas mas grande ;)" << endl;
        return;
    }
    cout << "Sesión: " << usuario->getNombre() 
    << endl << " Navegador: " << navegador.getNombre() << endl
    << endl << "1) Agregar Historial"
    << endl << "2) Ver los últimos 10 registros"
    << endl << " Escoge una opción: \n";
    int opc = 0;
    cin >> opc;

    while(opc != 1 && opc != 2 )
    {
        cout 
        << endl << "1) Agregar Historial"
        << endl << "2) Ver los últimos 10 registros"
        << endl << "Ingrese una opción: " << endl;
        cin >> opc;
    }
    string pagina;
    switch (opc)
    {
    case 1:
        cout << "Ingrese que página visito: \n";
        cin >> pagina;
        navegador.agregarPagina(pagina);
        cout << "Se agrego a tu historial correctamente" << endl;
        break;

    case 2:
        cout << navegador.getHistorial() << endl;
        break;

    default:
        cout << "Error al ingresar la opción" << endl;
        break;
    }
};

void VisitorSesionSoftware::acepta(Ofimatica& ofimatica, Usuario* usuario)
{
    if(ofimatica.getClasificacion() == Software::A && usuario->getEdad() < 18)
    {
        cout << "Lo sentimos pero eres menor de edad para acceder a esta aplicación...\nvuelve cuando seas mas grande ;)" << endl;
        return;
    }
    cout << "Sesión: " << usuario->getNombre() 
    << endl << " Ofimática: " << ofimatica.getNombre() << endl
    << endl << "1) Agregar documento"
    << endl << "2) Eliminar documento"
    << endl << "3) Ver cantidad de documentos"
    << endl << " Escoge una opción: \n";
    int opc = 0;
    cin >> opc;

    while(opc != 1 && opc != 2 && opc != 3)
    {
        cout 
        << endl << "1) Agregar documento"
        << endl << "2) Eliminar documento"
        << endl << "3) Ver cantidad de documentos"
        << endl << "Ingrese una opción: " << endl;
        cin >> opc;
    }
    string pagina;
    switch (opc)
    {
    case 1:
        cout << "Ingrese que página visito: \n";
        cin >> pagina;
        ofimatica.agregarArchivo();
        cout << "Se agrego el documento correctamente" << endl;
        break;

    case 2:

        if(ofimatica.eliminarArchivo())
        {
            cout << "Se elimino un archivo correctamente" << endl;
        }
        else 
        {
            cout << "No tienes archivos en la aplicación" << endl;
        }
        break;
    
    case 3:

        cout << "La cantidad de archivos que tienes son: " << ofimatica.getCantArchivo() << endl;
        break;

    default:
        cout << "Error al ingresar la opción" << endl;
        break;
    }
};

void VisitorSesionSoftware::acepta(Produccion& produccion, Usuario* usuario)
{
    if(produccion.getClasificacion() == Software::A && usuario->getEdad() < 18)
    {
        cout << "Lo sentimos pero eres menor de edad para acceder a esta aplicación...\nvuelve cuando seas mas grande ;)" << endl;
        return;
    }
    cout << "Sesión: " + usuario->getNombre() << endl;
    cout << "produccion: " << produccion.getNombre() << " Tipo de solucion: " << produccion.getTipoSolucion() << endl 
    << endl << "1) Cantidad de horas utilizadas en tu producción"
    << endl << "2) trabajar "
    << endl << "Ingrese una opción: " << endl;
    int opc = 0;
    cin >> opc;

    while(opc != 1 && opc != 2 )
    {
        cout 
        << endl << "1) Cantidad de horas utilizadas en tu producción"
        << endl << "2) trabajar "
        << endl << "Ingrese una opción: " << endl;
        cin >> opc;
    }
    double horas;
    switch (opc)
    {
        case 1:
            cout << "Las horas que has jugado son...." << produccion.getCantidadHoras() << endl;
            break;

        case 2:
            do{
                if(horas < 0) cout << " no puedes ingresar número negativos" << endl;
                cout << "Cuantas horas quieres agregar? " << endl;
                cin >> horas;
            }while(horas < 0);

            produccion.agregarCantidadHoras(horas);
            cout << "Se han agregado tus horas en el registro " << endl;
            break;
        default:

            cout << "Error al ingresar la opción" << endl;
            break;
    }
};

void VisitorSesionSoftware::acepta(Seguridad& seguridad, Usuario* usuario)
{
    VisitorUsuario* visitor = new VisitorUsuario();
    usuario->visita(visitor);
    if(seguridad.getClasificacion() == Software::A && usuario->getEdad() < 18)
    {
        cout << "No tienes la edad suficiente para ingresar a esta aplicación... " << endl;
        return;
    }
    else if(visitor->getTipo() != Usuario::ADMINISTRADOR)
    {
        cout << "Solos los usuarios de tipo admin pueden ingresar a este software..." << endl;
        return;
    }

    int opc;
    cout << "Sesión: " << usuario->getNombre() 
    << endl << "Seguridad: " << seguridad.getNombre() << "Tipo de malware: " << seguridad.getTipo() 
    << endl << "1) Informe de seguridad del malware " + seguridad.getTipo() + " (en tus sesiones)"
    << endl << "2) Porcentaje de malwares que son de tipo: " + seguridad.getTipo() + " (en tus sesiones)"
    << endl << "Ingrese una opción: ";
    cin >> opc;

    while(opc != 1 && opc != 2 )
    {
        cout 
        << endl << "Seguridad: " << seguridad.getNombre() << "Tipo de malware: " << seguridad.getTipo() 
        << endl << "1) Informe de seguridad del malware " + seguridad.getTipo() + " (en la biblioteca)" // Se refiere a la cantidad de malware de tipo que tiene la app en la biblioteca
        << endl << "2) Porcentaje de malwares que son de tipo: " + seguridad.getTipo() + " (en tus sesiones)"
        << endl << "Ingrese una opción: ";
        cin >> opc;
    }

    switch(opc)
    {
        case 1:
            cout << seguridad.getInforme(usuario) << endl;
            break;
        
        case 2:
            cout << seguridad.getPorcentaje(usuario) << endl;
            break;
        
        default:
            cout << "Opción incorrecta..." << endl;
            break;
    }
};

void VisitorSesionSoftware::acepta(Social& social, Usuario* usuario)
{
    if(social.getClasificacion() == Software::A && usuario->getEdad() < 18)
    {
        cout << "No tienes la edad suficiente para ingresar a la aplicación" << endl;
        return;
    }
    if(social.getNombreUsuario() == "")
    {
        social.setNombreUsuario(usuario->getNombre());
    }
    cout << "Sesión: " + usuario->getNombre() 
    << endl << "Aplicación: " + social.getNombre()
    << endl << "1) Agregar Amigo"
    << endl << "2) Eliminar Amigo"
    << endl << "3) Ver lista de amigos"
    << endl << "Ingrese una opción: " << endl;
    int opc;
    cin >> opc;
    while(opc != 1 && opc != 2 && opc != 3)
    {
        cout 
        << endl << "1) Agregar Amigo"
        << endl << "2) Eliminar Amigo"
        << endl << "3) Ver lista de amigos"
        << endl << "Ingrese una opción: " << endl;
        cin >> opc;
    }
    int edadAmigo;
    string nombreAmigo = "";
    bool agregado;
    bool eliminado;
    Usuario* Usamigo = nullptr;
    switch (opc)
    {
    case 1:
        cout << this->sistema->getNombresUsuarios();
        cout << "Ingrese el nombre del amigo a agregar: \n";
        cin >> nombreAmigo;
        
        edadAmigo = sistema->getEdadUsuario(nombreAmigo); // Si retorna -1 es porque no encontro el nombre del usuario
        if(edadAmigo == -1)
        {
            cout << "El usuario con nombre: " << nombreAmigo << " no se ha encontrado en el sistema, vuelva a intentarlo mas tarde..." << endl;
        }
        else if(usuario->getEdad() < 18 && edadAmigo > 18) 
        {
            cout << "El usuario: " << nombreAmigo << " que desea ingresar es mayor de edad, solo puede ingresar amigos menores de edad, debido a la restricciones de edad de la aplicación" << endl;
        }
        else if(usuario->getEdad() > 18 && edadAmigo < 18)
        {
            cout << "No se puede agregar el usuario: " << nombreAmigo << " debido a que es menor de edad" << endl;
        }
        else // Dos posibles opciones: ambos son mayores de edad o ambos son menores de edad, las cuales ambas son validas 
        {
            agregado = social.agregarAmigo(nombreAmigo); 
            if(agregado) // si los usuarios son diferentes, entonces si se agrego
            {
                cout << "Se ha agregado correctamente el usuario, ahora son amigos" << endl;
            }
            else 
            {
                cout << "Parece que ambos tienen el mismo nombre o son la misma persona no se ha podido ingresar el usuario como amigos" << endl;
            }
        }
        break;
    
    case 2:

        cout << social.getNombresAmigos();
        cout << "Ingrese el nombre del amigo a eliminar: \n";
        cin >> nombreAmigo;
        eliminado = social.eliminarAmigo(nombreAmigo);
        if(eliminado)
        {
            cout << "Se ha eliminado correctamente el usuario" << endl;
        }
        else 
        {
            cout << "El usuario no se ha encontrado en tu lista de amigos. no se han hecho modificaciones" << endl;
        }
        break;

    case 3:
        cout << social.getNombresAmigos() << endl;
        break;

    default:
        cout << "Opción incorrecta" << endl;
        break;
    }
};
