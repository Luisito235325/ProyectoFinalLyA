#include <iostream>
#include "variables.h"

using namespace std;

void inicializarHabitaciones();
void OcuparHabitacion();
void Hotel();
void MostrarEstado();
void LiberarHabitacion();

void inicializarHabitaciones()
{
    for (int i = 0; i < habitacionesTotales; ++i)
    {
        habitaciones[i] = false;
    }
}

void OcuparHabitacion(int numHabitacion)
{
    if (numHabitacion > 0 && numHabitacion <= habitacionesTotales)
    {
        if (!habitaciones[numHabitacion - 1])
        {
            habitaciones[numHabitacion - 1] = true;
            habitacionesOcupadas++;
            habitacionesDisponibles--;
            cout << "Habitacion " << numHabitacion << " ocupada exitosamente.\n";
        }
        else
        {
            cout << "La habitacion " << numHabitacion << " ya está ocupada.\n";
        }
    }
    else
    {
        cout << "Numero de habitacion invalido.\n";
    }
}

void LiberarHabitacion(int numHabitacion)
{
    if (numHabitacion > 0 && numHabitacion <= habitacionesTotales)
    {
        if (habitaciones[numHabitacion - 1])
        {
            habitaciones[numHabitacion - 1] = false;
            habitacionesOcupadas--;
            habitacionesDisponibles++;
            cout << "Habitacion " << numHabitacion << " liberada exitosamente.\n";
        }
        else
        {
            cout << "La habitacion " << numHabitacion << " ya esta libre.\n";
        }
    }
    else
    {
        cout << "Numero de habitación invalido.\n";
    }
}

void MostrarEstado()
{
    cout << "Estado de las habitaciones:\n";
    for (int i = 0; i < habitacionesTotales; ++i)
    {
        cout << "Habitacion " << i + 1 << ": " << (habitaciones[i] ? "Ocupada" : "Libre") << "\n";
    }
}

void Hotel()
{
    inicializarHabitaciones();

    int opcion;
    do
    {
        cout << "\nMenu:\n";
        cout << "1. Ocupar una habitacion\n";
        cout << "2. Liberar una habitacion\n";
        cout << "3. Mostrar estado de las habitaciones\n";
        cout << "4. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
        {
            int numHabitacion;
            cout << "Ingrese el numero de la habitacion a ocupar (1-" << habitacionesTotales << "): ";
            cin >> numHabitacion;
            OcuparHabitacion(numHabitacion);
            break;
        }
        case 2:
        {
            int numHabitacion;
            cout << "Ingrese el número de la habitacion a liberar (1-" << habitacionesTotales << "): ";
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
            cout << "Opción invalida. Intente de nuevo.\n";
            break;
        }
    } while (opcion != 4);
}