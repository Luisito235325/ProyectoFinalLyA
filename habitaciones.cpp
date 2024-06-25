#include <iostream>

using namespace std;

const int habitacionesTotales = 8;
int habitacionesOcupadas = 0;
int habitacionesDisponibles = habitacionesTotales;
bool habitaciones[habitacionesTotales];

void inicializarHabitaciones() {
    for (int i = 0; i < habitacionesTotales; ++i) {
        habitaciones[i] = false;
    }
}

void OcuparHabitacion(int numHabitacion) {
    if (numHabitacion > 0 && numHabitacion <= habitacionesTotales) {
        if (!habitaciones[numHabitacion - 1]) {
            habitaciones[numHabitacion - 1] = true;
            habitacionesOcupadas++;
            habitacionesDisponibles--;
            cout << "Habitación " << numHabitacion << " ocupada exitosamente.\n";
        } else {
            cout << "La habitación " << numHabitacion << " ya está ocupada.\n";
        }
    } else {
        cout << "Número de habitación inválido.\n";
    }
}

void MostrarEstado() {
    cout << "Estado de las habitaciones:\n";
    for (int i = 0; i < habitacionesTotales; ++i) {
        cout << "Habitación " << i + 1 << ": " << (habitaciones[i] ? "Ocupada" : "Libre") << "\n";
    }
}

void Hotel() {
    inicializarHabitaciones();

    int numHabitaciones;
    cout << "Ingrese el número de habitaciones a ocupar: ";
    cin >> numHabitaciones;

    for (int i = 0; i < numHabitaciones; ++i) {
        int numHabitacion;
        cout << "Ingrese el número de la habitación a ocupar (1-" << habitacionesTotales << "): ";
        cin >> numHabitacion;
        OcuparHabitacion(numHabitacion);
    }

    MostrarEstado();
}

int main() {
    Hotel();
    return 0;
}
