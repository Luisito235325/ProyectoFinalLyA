#include <iostream>
#include <cstdlib>
#include "funciones.h"

using namespace std;

void mostrarMenu() {
    cout << "Seleccione una opcion:\n";
    cout << "1. Registrar nueva reserva\n";
    cout << "2. Ver reservas registradas\n";
    cout << "3. Eliminar una reserva\n";
    cout << "4. Registrar nueva factura\n";
    cout << "5. Ver estado de las habitaciones\n";
    cout << "6. Salir\n";
    cout << "Opción: ";
}

int main() {
    char opcion;
    
    do {
        mostrarMenu();
        cin >> opcion;
        system("cls");

        switch (opcion) {
            case '1':
                registrarReserva();
                break;
            case '2':
                mostrarReservas();
                break;
            case '3':
                eliminarReserva();
                break;
            case '4':
                registrarFactura();
                break;
            case '5':
                mostrarEstadoHabitaciones();
                break;
            case '6':
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opcion no valida. Intente nuevamente.\n";
        }

        if (opcion != '6') {
            cout << "Presione cualquier tecla para volver al menu principal...";
            cin.ignore();
            cin.get();
            system("cls");
        }
    } while (opcion != '6');

    return 0;
}
