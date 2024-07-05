#include <iostream>
#include <cstdio>
#include <ctime>
#include <fstream>
#include "facturacion.cpp"

using namespace std;

extern const int habitacionesTotales;
void inicializarHabitaciones();
void OcuparHabitacion();
void Hotel();
void MostrarEstado();
void LiberarHabitacion();
void GuardarEstado();
void CargarEstado();

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
            cout << "La habitacion " << numHabitacion << " ya esta ocupada.\n";
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
        cout << "Numero de habitacion invalido.\n";
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

void GuardarEstado()
{
    ofstream archivo("estado_habitaciones.txt");
    if (archivo.is_open())
    {
        archivo << habitacionesOcupadas << endl;
        archivo << habitacionesDisponibles << endl;
        for (int i = 0; i < habitacionesTotales; ++i)
        {
            archivo << habitaciones[i] << endl;
        }
        archivo.close();
        cout << "Estado guardado exitosamente.\n";
    }
    else
    {
        cout << "No se pudo abrir el archivo para guardar.\n";
    }
}

void CargarEstado()
{
    ifstream archivo("estado_habitaciones.txt");
    if (archivo.is_open())
    {
        archivo >> habitacionesOcupadas;
        archivo >> habitacionesDisponibles;
        for (int i = 0; i < habitacionesTotales; ++i)
        {
            archivo >> habitaciones[i];
        }
        archivo.close();
        cout << "Estado cargado exitosamente.\n";
    }
    else
    {
        cout << "No se pudo abrir el archivo para cargar.\n";
    }
}

void Hotel()
{
    inicializarHabitaciones();

    int opcion;
    do
    {
        cout << "\nMenu:\n";
        cout << "1. Ocupar una habitación" << endl;
        cout << "2. Liberar una habitación" << endl;
        cout << "3. Mostrar estado de las habitaciones" << endl;
        cout << "4. Guardar estado" << endl;
        cout << "5. Cargar estado" << endl;
        cout << "6. Salir" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
        {
            system("cls || clear");
            int numHabitacion;
            cout << "Ingrese el número de la habitación a ocupar (1-" << habitacionesTotales << "): ";
            cin >> numHabitacion;
            OcuparHabitacion(numHabitacion);
            system("pause");
            break;
        }
        case 2:
        {
            system("cls || clear");
            int numHabitacion;
            cout << "Ingrese el número de la habitación a liberar (1-" << habitacionesTotales << "): ";
            cin >> numHabitacion;
            LiberarHabitacion(numHabitacion);
            system("pause");
            break;
        }
        case 3:
        system("cls || clear");
            MostrarEstado();
            system("pause");
            break;
        case 4:
        system("cls || clear");
            GuardarEstado();
            system("pause");
            break;
        case 5:
        system("cls || clear");
            CargarEstado();
            system("pause");
            break;
        case 6:
            cout << "Saliendo del programa.\n";
            system("cls || clear");
            break;
        default:
            cout << "Opción inválida. Intente de nuevo.\n";
            system("cls || clear");
            break;
        }
    } while (opcion != 6);
}