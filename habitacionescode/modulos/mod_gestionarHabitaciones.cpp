#include <iostream>
#include <fstream>
using namespace std;

extern const int habitacionesTotales;
extern int habitacionesOcupadas;
extern int habitacionesDisponibles;
extern bool habitaciones[];

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

void LiberarHabitacion(int numHabitacion) {
    if (numHabitacion > 0 && numHabitacion <= habitacionesTotales) {
        if (habitaciones[numHabitacion - 1]) {
            habitaciones[numHabitacion - 1] = false;
            habitacionesOcupadas--;
            habitacionesDisponibles++;
            cout << "Habitación " << numHabitacion << " liberada exitosamente.\n";
        } else {
            cout << "La habitación " << numHabitacion << " ya está libre.\n";
        }
    } else {
        cout << "Número de habitación inválido.\n";
    }
}
