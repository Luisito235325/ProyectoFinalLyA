#include <iostream>
using namespace std;
extern const int habitacionesTotales;
extern void inicializarHabitaciones();
extern void OcuparHabitacion(int numHabitacion);
extern void LiberarHabitacion(int numHabitacion);
extern void MostrarEstado();

void Hotel() {
    inicializarHabitaciones();

    int opcion;
    do {
        cout << "\nMenu:\n";
        cout << "1. Ocupar una habitacion\n";
        cout << "2. Liberar una habitacion\n";
        cout << "3. Mostrar estado de las habitaciones\n";
        cout << "4. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                int numHabitacion;
                cout << "Ingrese el numero de la habitacion a ocupar (1-" << habitacionesTotales << "): ";
                cin >> numHabitacion;
                OcuparHabitacion(numHabitacion);
                break;
            }
            case 2: {
                int numHabitacion;
                cout << "Ingrese el numero de la habitacion a liberar (1-" << habitacionesTotales << "): ";
                cin >> numHabitacion;
                LiberarHabitacion(numHabitacion);
                break;
            }
            case 3:
                MostrarEstado();
                break;
            case 4:
                cout << "Saliendo del programa.\n";
                break;
            default:
                cout << "Opcion invalida. Intente de nuevo.\n";
                break;
        }
    } while (opcion != 4);
}
