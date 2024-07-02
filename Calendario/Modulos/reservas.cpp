#include <iostream>
#include <cstdio>
#include <ctime>
#include "variables.h"
#include "utilidades.cpp"

using namespace std;


void cargarReservas();
void guardarReservas();
void registrarReserva();
void mostrarReservas();
void eliminarReserva();


void cargarReservas() {
    FILE* archivo = fopen("reservas.dat", "rb");
    if (archivo) {
        fread(&NUM_APARTAMENTOS, sizeof(NUM_APARTAMENTOS), 1, archivo);
        apartamentos = new Apartamento[NUM_APARTAMENTOS];
        for (int i = 0; i < NUM_APARTAMENTOS; ++i) {
            fread(&apartamentos[i].numReservas, sizeof(apartamentos[i].numReservas), 1, archivo);
            fread(apartamentos[i].reservas, sizeof(Reserva), apartamentos[i].numReservas, archivo);
        }
        fclose(archivo);
    } else {
        apartamentos = new Apartamento[NUM_APARTAMENTOS];
    }
}

void guardarReservas() {
    FILE* archivo = fopen("reservas.dat", "wb");
    if (archivo) {
        fwrite(&NUM_APARTAMENTOS, sizeof(NUM_APARTAMENTOS), 1, archivo);
        for (int i = 0; i < NUM_APARTAMENTOS; ++i) {
            fwrite(&apartamentos[i].numReservas, sizeof(apartamentos[i].numReservas), 1, archivo);
            fwrite(apartamentos[i].reservas, sizeof(Reserva), apartamentos[i].numReservas, archivo);
        }
        fclose(archivo);
    }
}

void registrarReserva() {
    int apartamento;
    char fechaInicio[11], horaInicio[6];
    char fechaFin[11], horaFin[6];
    double montoPagado;
    char nombreInquilino[50];
    char cedulaInquilino[20];

    cout << "Ingrese el numero de apartamento (1-8): ";
    cin >> apartamento;
    if (apartamento < 1 || apartamento > 8) {
        cout << "Numero de apartamento invalido." << endl;
        return;
    }

    obtenerFechaHoraActual(fechaInicio, horaInicio);
    cout << "Fecha y hora de inicio de la reserva: " << fechaInicio << " " << horaInicio << endl;

    cout << "Ingrese la fecha de fin de la reserva (DD/MM/AAAA): ";
    cin >> fechaFin;
    cout << "Ingrese la hora de fin de la reserva (HH:MM): ";
    cin >> horaFin;
    if (!validarFechaHora(fechaFin, horaFin) || !compararFechas(fechaInicio, horaInicio, fechaFin, horaFin)) {
        cout << "Fecha y hora de fin invalidas." << endl;
        return;
    }

    cout << "Ingrese el monto pagado: ";
    cin >> montoPagado;
    cout << "Ingrese el nombre del inquilino: ";
    cin.ignore();
    cin.getline(nombreInquilino, 50);
    cout << "Ingrese el numero de cedula del inquilino: ";
    cin.getline(cedulaInquilino, 20);

    Reserva nuevaReserva = {apartamento};
    copiarCadena(nuevaReserva.fechaInicio, fechaInicio, 11);
    copiarCadena(nuevaReserva.horaInicio, horaInicio, 6);
    copiarCadena(nuevaReserva.fechaFin, fechaFin, 11);
    copiarCadena(nuevaReserva.horaFin, horaFin, 6);
    nuevaReserva.montoPagado = montoPagado;
    copiarCadena(nuevaReserva.nombreInquilino, nombreInquilino, 50);
    copiarCadena(nuevaReserva.cedulaInquilino, cedulaInquilino, 20);

    if (apartamentos[apartamento - 1].numReservas < MAX_RESERVAS) {
        apartamentos[apartamento - 1].reservas[apartamentos[apartamento - 1].numReservas++] = nuevaReserva;
        cout << "Reserva registrada exitosamente." << endl;
        guardarReservas();
    } else {
        cout << "No se pueden registrar mas reservas para este apartamento." << endl;
    }
}

void mostrarReservas() {
    for (int i = 0; i < NUM_APARTAMENTOS; ++i) {
        cout << "Apartamento " << i + 1 << ":" << endl;
        for (int j = 0; j < apartamentos[i].numReservas; ++j) {
            Reserva& reserva = apartamentos[i].reservas[j];
            cout << "Reserva " << j + 1 << ": "
                 << "Fecha Inicio: " << reserva.fechaInicio << " " << reserva.horaInicio
                 << ", Fecha Fin: " << reserva.fechaFin << " " << reserva.horaFin
                 << ", Monto Pagado: $" << reserva.montoPagado
                 << ", Nombre Inquilino: " << reserva.nombreInquilino
                 << ", Cedula Inquilino: " << reserva.cedulaInquilino << endl;
        }
        cout << endl;
    }
}

void eliminarReserva() {
    int apartamento, indiceReserva;

    cout << "Ingrese el numero de apartamento (1-8): ";
    cin >> apartamento;
    if (apartamento < 1 || apartamento > 8) {
        cout << "Numero de apartamento invalido." << endl;
        return;
    }

    cout << "Reservas del apartamento " << apartamento << ":" << endl;
    for (int i = 0; i < apartamentos[apartamento - 1].numReservas; ++i) {
        cout << i + 1 << ". Reserva desde " << apartamentos[apartamento - 1].reservas[i].fechaInicio 
             << " " << apartamentos[apartamento - 1].reservas[i].horaInicio
             << " hasta " << apartamentos[apartamento - 1].reservas[i].fechaFin
             << " " << apartamentos[apartamento - 1].reservas[i].horaFin << endl;
    }

    cout << "Ingrese el numero de la reserva a eliminar: ";
    cin >> indiceReserva;
    if (indiceReserva < 1 || indiceReserva > apartamentos[apartamento - 1].numReservas) {
        cout << "Numero de reserva invalido." << endl;
        return;
    }

    for (int i = indiceReserva - 1; i < apartamentos[apartamento - 1].numReservas - 1; ++i) {
        apartamentos[apartamento - 1].reservas[i] = apartamentos[apartamento - 1].reservas[i + 1];
    }
    --apartamentos[apartamento - 1].numReservas;
    cout << "Reserva eliminada exitosamente." << endl;
    guardarReservas();
}