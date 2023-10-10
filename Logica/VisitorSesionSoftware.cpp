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
    
    
    while(true)
    {
        cout << "Sesion: " + usuario->getNombre() << endl;
        cout << "Juego: " << juego.getNombre() << " Genero: " << juego.getGenero() << endl;
        int opc;
        do{
        cout 
        << endl << "1) Cantidad de horas jugadas"
        << endl << "2) Jugar"
        << endl << "3) Salir"
        << endl;
        opc = parseInt("Ingrese una opcion: ");
        }while(opc != 1 && opc != 2 && opc != 3);

        double horas;

        switch (opc)
        {
        case 1:
            cout << "Las horas que has jugado son...." << juego.getHorasJugadas() << " horas nada mal" << endl;
            if(juego.getHorasJugadas() > 1000) cout << "Que vicio :P" << endl;
            break;

        case 2:
            do{
                if(horas < 0)
                {
                    cout << " quieres recuperar tu tiempo :(" << endl;
                }    
                horas = parseDouble("Cuantas horas quieres agregar: ");   
            }while(horas < 0);

            juego.agregarHorasJugadas(horas);
            cout << "Se han agregado tus horas en el registro " << endl;
            break;
        case 3:
            cout << "Has salido de " + juego.getNombre() << endl;
            return;
        default:

            cout << "Error al ingresar la opcion" << endl;
            break;
        }
        transicion(1);
    }
};

void VisitorSesionSoftware::acepta(Navegador& navegador, Usuario* usuario)
{
    if(navegador.getClasificacion() == Software::A && usuario->getEdad() < 18)
    {
        cout << "Lo sentimos pero eres menor de edad para acceder a esta aplicación...\nvuelve cuando seas mas grande ;)" << endl;
        return;
    }

    while(true)
    {
        int opc;
        cout << "Sesion: " << usuario->getNombre() 
        << endl << " Navegador: " << navegador.getNombre();
        do 
        {
            cout
            << endl << "1) Agregar Historial"
            << endl << "2) Ver los ultimos 10 registros"
            << endl << "3) Salir"
            << endl << " Escoge una opcion: \n";
            opc = parseInt("Ingrese una opcion: ");
        }while(opc != 1 && opc != 2 && opc != 3);
    
        string pagina;
        switch (opc)
        {
        case 1:
            cout << "Ingrese que pagina visito: \n";
            cin >> pagina;
            navegador.agregarPagina(pagina);
            cout << "Se agrego a tu historial correctamente" << endl;
            break;

        case 2:
            cout << navegador.getHistorial() << endl;
            break;
        
        case 3:
            cout << "Has salido del programa" << endl;
            return;

        default:
            cout << "Error al ingresar la opcion" << endl;
            break;
        }
        transicion(1);
    }
};

void VisitorSesionSoftware::acepta(Ofimatica& ofimatica, Usuario* usuario)
{
    if(ofimatica.getClasificacion() == Software::A && usuario->getEdad() < 18)
    {
        cout << "Lo sentimos pero eres menor de edad para acceder a esta aplicacion...\nvuelve cuando seas mas grande ;)" << endl;
        return;
    }
    while(true)
    {
        cout << "Sesion: " << usuario->getNombre() 
    << endl << " Ofimatica: " << ofimatica.getNombre() << endl;
    int opc;
    do 
    {
        cout 
        <<         "1) Agregar documento"
        << endl << "2) Eliminar documento"
        << endl << "3) Ver cantidad de documentos"
        << endl << "4) Salir"
        << endl;
    opc = parseInt(" Escoge una opcion: ");
    }while(opc != 1 && opc != 2 && opc != 3 && opc != 4);
    
    string pagina;
    switch (opc)
    {
        case 1:
            cout << "Ingrese que página visito: \n";
            getline(cin, pagina);
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
                cout << "No tienes archivos en la aplicacion" << endl;
            }
            break;
        
        case 3:

            cout << "La cantidad de archivos que tienes son: " << ofimatica.getCantArchivo() << endl;
            break;
        
        case 4:
            cout << "Has salido del programa" << endl;
            return;

        default:
            cout << "Error al ingresar la opcion" << endl;
            break;
        }
        transicion(1);
    }
};

void VisitorSesionSoftware::acepta(Produccion& produccion, Usuario* usuario)
{
    if(produccion.getClasificacion() == Software::A && usuario->getEdad() < 18)
    {
        cout << "Lo sentimos pero eres menor de edad para acceder a esta aplicacion...\nvuelve cuando seas mas grande ;)" << endl;
        return;
    }
   
    while(true)
    {
        cout << "Sesion: " + usuario->getNombre() << endl;
        cout << "produccion: " << produccion.getNombre() << " Tipo de solucion: " << produccion.getTipoSolucion() << endl;
        int opc;
        do
        {
            cout  
            << endl << "1) Cantidad de horas utilizadas en tu produccion"
            << endl << "2) trabajar "
            << endl << "3) Salir" << endl;
            opc = parseInt("Ingrese una opcion: ");

        }while(opc != 1 && opc != 2 && opc != 3);
        double horas;
        switch (opc)
        {
            case 1:
                cout << "Las horas que has jugado son...." << produccion.getCantidadHoras() << endl;
                break;

            case 2:
                do{
                    if(horas < 0) cout << " no puedes ingresar numero negativos" << endl;
                    horas = parseDouble("Cuantas horas quieres agregar? ");
                }while(horas < 0);

                produccion.agregarCantidadHoras(horas);
                cout << "Se han agregado tus horas en el registro " << endl;
                break;
            case 3:
                cout << "has salido del programa" << endl;
                return;
            default:

                cout << "Error al ingresar la opcion" << endl;
                break;
        }
        transicion(1);
    }
};

void VisitorSesionSoftware::acepta(Seguridad& seguridad, Usuario* usuario)
{
    VisitorUsuario* visitor = new VisitorUsuario();
    usuario->visita(visitor);
    if(seguridad.getClasificacion() == Software::A && usuario->getEdad() < 18)
    {
        cout << "No tienes la edad suficiente para ingresar a esta aplicacion... " << endl;
        return;
    }
    else if(visitor->getTipo() != Usuario::ADMINISTRADOR)
    {
        cout << "Solos los usuarios de tipo admin pueden ingresar a este software..." << endl;
        return;
    }

    while(true)
    {
        int opc;
        cout << "Sesion: " << usuario->getNombre() 
        << endl << "Seguridad: " << seguridad.getNombre() << "Tipo de malware: " << seguridad.getTipo();
        do 
        {
            cout 
            << endl << "1) Informe de seguridad del malware " + seguridad.getTipo() + " (en tus sesiones)"
            << endl << "2) Porcentaje de malwares que son de tipo: " + seguridad.getTipo() + " (en tus sesiones)"
            << endl << "3) Salir" << endl;
            opc = parseInt("Ingrese una opcion: ");
        }while(opc != 1 && opc != 2 && opc != 3);
    
        switch(opc)
        {
            case 1:
                cout << seguridad.getInforme(usuario) << endl;
                break;
            
            case 2:
                cout << seguridad.getPorcentaje(usuario) << endl;
                break;
            case 3:
                cout << "Has salido del programa" << endl;  
                return;  
            default:
                cout << "Opcion incorrecta..." << endl;
                break;
        }
        transicion(1);
    }
};

void VisitorSesionSoftware::acepta(Social& social, Usuario* usuario)

{
    if(social.getClasificacion() == Software::A && usuario->getEdad() < 18)
    {
        cout << "No tienes la edad suficiente para ingresar a la aplicacion" << endl;
        return;
    }
    else if(sistema->getSoftware(social.getNombre())->getListaUsuario()->size() <= 1)
    {
        cout << "Eres el unico que ha iniciado sesion en esta aplicacion social, Invita a tus amigos!!" << endl;
        transicion(1.5);
        return;
    }
    if(social.getNombreUsuario() == "")
    {
        social.setNombreUsuario(usuario->getNombre());
    }
    
    while(true)
    {
        cout << "Sesion: " + usuario->getNombre() 
        << endl << "Aplicacion: " + social.getNombre();
        int opc;
        do 
        {
            cout << endl << "1) Agregar Amigo"
            << endl << "2) Eliminar Amigo"
            << endl << "3) Ver lista de amigos" 
            << endl << "4) Salir" << endl;
            opc = parseInt("Ingrese una opcion: ");
        }while(opc != 1 && opc != 2 && opc != 3 && opc != 4);

        int edadAmigo;
        string nombreAmigo = "";
        bool agregado = false ;
        bool eliminado = false ;
        Usuario* punteroAmigo = nullptr;
        Social* appExAmigo;
        switch (opc)
        {
        case 1:
            cout << this->getNombreUsuarios(sistema->getNombresUsuariosSoftware(social.getNombre()), usuario->getNombre());
            cout << "Ingrese el nombre del amigo a agregar: \n";
            getline(cin, nombreAmigo);
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
                punteroAmigo = this->sistema->getUsuario(nombreAmigo); // 
                agregado = social.agregarAmigo(punteroAmigo); 
                if(agregado) // si los usuarios son diferentes, entonces si se agrego
                {
                    cout << "Se ha agregado correctamente el usuario, ahora son amigos" << endl;
                }
                else 
                {
                    cout << "no se ha podido ingresar el usuario como amigos" << endl;
                }
            }
            break;
        
        case 2:

            if(social.isEmptyListaAmigo())
            {
                cout << "No tienes amigos para eliminar..." << endl;
                break;
            }
            else 
            {
                cout << social.getNombresAmigos();
                cout << "Ingrese el nombre del amigo a eliminar: \n";
                getline(cin, nombreAmigo);

                punteroAmigo = this->sistema->getUsuario(nombreAmigo);
                appExAmigo = dynamic_cast<Social*>(punteroAmigo->getSoftware(social.getNombre()));

                if(appExAmigo != nullptr) // Si es nulo es porque el usuario no tiene la aplicación en sus registros, por lo tanto no puede eliminar
                {
                    eliminado = social.eliminarAmigo(punteroAmigo); // El amigo a eliminar
                    eliminado = appExAmigo->eliminarAmigo(usuario); // El amigo que eliminaste te va eliminar
                }
            
                if(eliminado)
                {
                    cout << "Se ha eliminado correctamente el usuario" << endl;
                }
                else 
                {
                    cout << "El usuario no se ha encontrado en tu lista de amigos. no se han hecho modificaciones" << endl;
                }
                break;
            }
            
        case 3:
            cout << social.getNombresAmigos() << endl;
            break;
        
        case 4:
            cout << "Has salido del programa" << endl;
            return;

        default:
            cout << "Opcion incorrecta" << endl;
            break;
        }

        transicion(1.5);
    }
}

string VisitorSesionSoftware::getNombreUsuarios(vector<string> *listanombres, string usuarioAcceso = "")
{
    string texto = "Listado de nombres: \n";
    for(int i=0; i<listanombres->size();i++)
    {
        if(listanombres->at(i) != usuarioAcceso)
        {
            texto += " " + listanombres->at(i) + " \n";
        } 
    }
    return texto;
};
