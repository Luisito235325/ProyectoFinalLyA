#include <iostream>
using namespace std;

extern const int habitacionesTotales;
extern void inicializarHabitaciones();
extern void OcuparHabitacion(int numHabitacion);
extern void LiberarHabitacion(int numHabitacion);
extern void MostrarEstado();
extern void OcuparHabitacion();
extern void GuardarEstado();
extern void CargarEstado();


void Hotel() {
    inicializarHabitaciones();

    int opcion;
    do {
            cout << "\nMenu:\n";
        cout << "1. Ocupar una habitación\n";
        cout << "2. Liberar una habitación\n";
        cout << "3. Mostrar estado de las habitaciones\n";
        cout << "4. Guardar estado\n";
        cout << "5. Cargar estado\n";
        cout << "6. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
             case 1: {
                int numHabitacion;
                cout << "Ingrese el número de la habitación a ocupar (1-" << habitacionesTotales << "): ";
                cin >> numHabitacion;
                OcuparHabitacion(numHabitacion);
                break;
            }
            case 2: {
                int numHabitacion;
                cout << "Ingrese el número de la habitación a liberar (1-" << habitacionesTotales << "): ";
                cin >> numHabitacion;
                LiberarHabitacion(numHabitacion);
                break;
            }
            case 3:
                MostrarEstado();
                break;
            case 4:
                GuardarEstado();
                break;
            case 5:
                CargarEstado();
                break;
            case 6:
                cout << "Saliendo del programa.\n";
                break;
            default:
                cout << "Opción inválida. Intente de nuevo.\n";
                break;
        }
    } while (opcion != 6);
}