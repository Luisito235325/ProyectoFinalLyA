#include <iostream>
using namespace std;

extern const int habitacionesTotales;
extern bool habitaciones[];

void MostrarEstado() {
    cout << "Estado de las habitaciones:\n";
    for (int i = 0; i < habitacionesTotales; ++i) {
        cout << "Habitación " << i + 1 << ": " << (habitaciones[i] ? "Ocupada" : "Libre") << "\n";
    }
}
