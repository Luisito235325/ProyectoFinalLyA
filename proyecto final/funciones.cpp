#include <iostream>
#include "variables.h"

using namespace std;

void inicializarHabitaciones();
void OcuparHabitacion();
void Hotel();
void MostrarEstado();

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
            cout << "Habitacion " << numHabitacion << " ocupada exitosamente.\n";
        } else {
            cout << "La habitacion " << numHabitacion << " ya esta ocupada.\n";
        }
    } else {
        cout << "Numero de habitación invalido.\n";
    }
}

void MostrarEstado() {
    cout << "Estado de las habitaciones:\n";
    for (int i = 0; i < habitacionesTotales; ++i) {
        cout << "Habitacion " << i + 1 << ": " << (habitaciones[i] ? "Ocupada" : "Libre") << "\n";
    }
}

void Hotel() {
    inicializarHabitaciones();

    int numHabitaciones;
    cout << "Ingrese el número de habitaciones a ocupar: ";
    cin >> numHabitaciones;

    if (numHabitaciones > 8) {
        cout << "No se pueden ocupar mas de 8 habitaciones.\n";
        numHabitaciones = 8;
    }

    for (int i = 0; i < numHabitaciones; ++i) {
        int numHabitacion;
        cout << "Ingrese el número de la habitación a ocupar (1-" << habitacionesTotales << "): ";
        cin >> numHabitacion;
        OcuparHabitacion(numHabitacion);
    }

    MostrarEstado();
}
