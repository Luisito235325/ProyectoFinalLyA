#include <iostream>

using namespace std;

int menu();

int menu() {
    int opcion;
    cout << "Seleccione una opcion:\n";
    cout << "1. Registrar nueva reserva\n";
    cout << "2. Ver reservas registradas\n";
    cout << "3. Eliminar reserva\n";
    cout << "4. Salir\n";
    cout << "Opcion: ";
    cin >> opcion;
    return opcion;
}