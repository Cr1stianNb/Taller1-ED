#include <iostream>
#include "Dominio/Software.cpp"
#include "Dominio/Usuario.cpp"
#include "Dominio/Juego.cpp"

using namespace std;


int main()
{
    Software* soft = new Software("Facebook", "Mark", "Menores a 17", 12.12);
    Software* jueguito = new Juego("Mario", "Un japo", "toda edad", 291.12, "Plataformero");
    Usuario* usuario1 = new Usuario("Cristian", "clave123", 20);

    cout << "Hola juego de " << jueguito->getNombre() << " como estas" << endl;
    cout << "Hola " << soft->getNombre() << " Asi te llamas" << endl;
    cout << "Hola mundo" << endl;
    cout << "Hola " << usuario1->getNombre() << " como estas?" << endl;
    return 0;
}