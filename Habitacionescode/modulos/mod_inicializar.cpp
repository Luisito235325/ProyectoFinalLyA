
#include <iostream>
#include <fstream>
using namespace std;


void inicializarHabitaciones();
void OcuparHabitacion(int numHabitacion);
void LiberarHabitacion(int numHabitacion);
void MostrarEstado();
void GuardarEstado();
void CargarEstado();

const int habitacionesTotales = 8;
int habitacionesOcupadas = 0;
int habitacionesDisponibles = habitacionesTotales;
bool habitaciones[habitacionesTotales];

void GuardarEstado() {
    ofstream archivo("estado_habitaciones.txt");
    if (archivo.is_open()) {
        archivo << habitacionesOcupadas << endl;
        archivo << habitacionesDisponibles << endl;
        for (int i = 0; i < habitacionesTotales; ++i) {
            archivo << habitaciones[i] << endl;
        }
        archivo.close();
        cout << "Estado guardado exitosamente.\n";
    } else {
        cout << "No se pudo abrir el archivo para guardar.\n";
    }
}

void CargarEstado() {
    ifstream archivo("estado_habitaciones.txt");
    if (archivo.is_open()) {
        archivo >> habitacionesOcupadas;
        archivo >> habitacionesDisponibles;
        for (int i = 0; i < habitacionesTotales; ++i) {
            archivo >> habitaciones[i];
        }
        archivo.close();
        cout << "Estado cargado exitosamente.\n";
    } else {
        cout << "No se pudo abrir el archivo para cargar.\n";
    }
}

void MostrarEstado() {
    cout << "Estado de las habitaciones:\n";
    for (int i = 0; i < habitacionesTotales; ++i) {
        cout << "Habitación " << i + 1 << ": " << (habitaciones[i] ? "Ocupada" : "Libre") << "\n";
    }
}

