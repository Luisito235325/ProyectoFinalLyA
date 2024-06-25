#include <iostream>
#include "Variables.h"

using namespace std;

void Calendario_Disponibilidad() {
    
    bool disponibilidad[NUM_HABITACIONES][NUM_DIAS]; 

   
    for (int i = 0; i < NUM_HABITACIONES; ++i) {
        for (int j = 0; j < NUM_DIAS; ++j) {
            disponibilidad[i][j] = true;
        }
    }

  
    char opcion;
    do {
        int habitacion, diaInicio, diaFin;
        cout << "Ingrese el número de habitación (1-" << NUM_HABITACIONES << "): ";
        cin >> habitacion;
        cout << "Ingrese el día de inicio de la reserva (1-" << NUM_DIAS << "): ";
        cin >> diaInicio;
        cout << "Ingrese el día de fin de la reserva (1-" << NUM_DIAS << "): ";
        cin >> diaFin;

       
        for (int dia = diaInicio; dia <= diaFin; ++dia) {
            disponibilidad[habitacion - 1][dia - 1] = false;
        }

        cout << "¿Desea registrar otra reserva? (S/N): ";
        cin >> opcion;
    } while (opcion == 'S' || opcion == 's');

 
    cout << "Disponibilidad de habitaciones:" << endl;
    for (int i = 0; i < NUM_HABITACIONES; ++i) {
        cout << "Habitación " << i + 1 << ":" << endl;
        for (int j = 0; j < NUM_DIAS; ++j) {
            cout << "Día " << j + 1 << ": " << (disponibilidad[i][j] ? "Disponible" : "No disponible") << endl;
        }
        cout << endl;
    }
}

void principal()
{
    Calendario_Disponibilidad();
}