#include "VisitorSesionSoftware.h"
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



};

void VisitorSesionSoftware::acepta(Social& social, Usuario* usuario)
{

};
