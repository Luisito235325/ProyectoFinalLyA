#include <iostream>
using namespace std;

extern const int habitacionesTotales;
extern bool habitaciones[];

void inicializarHabitaciones() {
    for (int i = 0; i < habitacionesTotales; ++i) {
        habitaciones[i] = false;
    }
}
