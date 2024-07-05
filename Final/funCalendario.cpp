#include <iostream>
#include <cstdio>
#include <ctime>
#include <fstream>
#include "Variables.h"

using namespace std;

bool compararFechas(const char *fecha1, const char *hora1, const char *fecha2, const char *hora2);
bool validarFechaHora(const char *fecha, const char *hora);
void copiarCadena(char *destino, const char *origen, int longitud);
int menuCalendario();

bool compararFechas(const char *fecha1, const char *hora1, const char *fecha2, const char *hora2)
{
    int dia1, mes1, anio1, horaInt1, minuto1;
    int dia2, mes2, anio2, horaInt2, minuto2;

    sscanf(fecha1, "%2d/%2d/%4d", &dia1, &mes1, &anio1);
    sscanf(hora1, "%2d:%2d", &horaInt1, &minuto1);
    sscanf(fecha2, "%2d/%2d/%4d", &dia2, &mes2, &anio2);
    sscanf(hora2, "%2d:%2d", &horaInt2, &minuto2);

    if (anio1 < anio2)
        return true;
    if (anio1 > anio2)
        return false;
    if (mes1 < mes2)
        return true;
    if (mes1 > mes2)
        return false;
    if (dia1 < dia2)
        return true;
    if (dia1 > dia2)
        return false;
    if (horaInt1 < horaInt2)
        return true;
    if (horaInt1 > horaInt2)
        return false;
    return minuto1 < minuto2;
}

bool validarFechaHora(const char *fecha, const char *hora)
{
    int dia, mes, anio, horaInt, minuto;
    if (sscanf(fecha, "%2d/%2d/%4d", &dia, &mes, &anio) != 3)
        return false;
    if (sscanf(hora, "%2d:%2d", &horaInt, &minuto) != 2)
        return false;
    if (dia < 1 || dia > 31 || mes < 1 || mes > 12 || anio < 2023)
        return false;
    if (horaInt < 0 || horaInt > 23 || minuto < 0 || minuto > 59)
        return false;
    return true;
}

void obtenerFechaHoraActual(char *fecha, char *hora)
{
    time_t t = time(nullptr);
    tm *now = localtime(&t);

    sprintf(fecha, "%02d/%02d/%04d", now->tm_mday, now->tm_mon + 1, now->tm_year + 1900);
    sprintf(hora, "%02d:%02d", now->tm_hour, now->tm_min);
}

void copiarCadena(char *destino, const char *origen, int longitud)
{
    for (int i = 0; i < longitud - 1 && origen[i] != '\0'; ++i)
    {
        destino[i] = origen[i];
    }
    destino[longitud - 1] = '\0';
}

void guardarReservas()
{
    FILE *archivo = fopen("reservas.dat", "wb");
    if (archivo)
    {
        fwrite(&NUM_APARTAMENTOS, sizeof(NUM_APARTAMENTOS), 1, archivo);
        for (int i = 0; i < NUM_APARTAMENTOS; ++i)
        {
            fwrite(&apartamentos[i].numReservas, sizeof(apartamentos[i].numReservas), 1, archivo);
            fwrite(apartamentos[i].reservas, sizeof(Reserva), apartamentos[i].numReservas, archivo);
        }
        fclose(archivo);
    }
}

void cargarReservas()
{
    FILE *archivo = fopen("reservas.dat", "rb");
    if (archivo)
    {
        fread(&NUM_APARTAMENTOS, sizeof(NUM_APARTAMENTOS), 1, archivo);
        apartamentos = new Apartamento[NUM_APARTAMENTOS];
        for (int i = 0; i < NUM_APARTAMENTOS; ++i)
        {
            fread(&apartamentos[i].numReservas, sizeof(apartamentos[i].numReservas), 1, archivo);
            fread(apartamentos[i].reservas, sizeof(Reserva), apartamentos[i].numReservas, archivo);
        }
        fclose(archivo);
    }
    else
    {
        apartamentos = new Apartamento[NUM_APARTAMENTOS];
    }
}

void registrarReserva()
{
    int apartamento;
    char fechaInicio[11], horaInicio[6];
    char fechaFin[11], horaFin[6];
    double montoPagado;
    char nombreInquilino[50];
    char cedulaInquilino[20];

    cout << "Ingrese el numero de apartamento (1-8): ";
    cin >> apartamento;
    if (apartamento < 1 || apartamento > 8)
    {
        cout << "Numero de apartamento invalido." << endl;
        return;
    }

    obtenerFechaHoraActual(fechaInicio, horaInicio);
    cout << "Fecha y hora de inicio de la reserva: " << fechaInicio << " " << horaInicio << endl;

    cout << "Ingrese la fecha de fin de la reserva (DD/MM/AAAA): ";
    cin.ignore();
    cin >> fechaFin;
    cout << "Ingrese la hora de fin de la reserva (HH:MM): ";
    cin >> horaFin;
    if (!validarFechaHora(fechaFin, horaFin) || !compararFechas(fechaInicio, horaInicio, fechaFin, horaFin))
    {
        cout << "Fecha y hora de fin invalidas." << endl;
        return;
    }

    cout << "Ingrese el monto pagado: ";
    cin >> montoPagado;
    cout << "Ingrese el nombre del inquilino: ";
    scanf(" %[^\n]", nombreInquilino);
    cin.ignore();
    cin.getline(nombreInquilino, 50);
    cout << "Ingrese el numero de cedula del inquilino: ";
    cin.getline(cedulaInquilino, 20);

    Reserva nuevaReserva = {apartamento, "", "", "", "", 0.0, ""};
    copiarCadena(nuevaReserva.fechaInicio, fechaInicio, 11);
    copiarCadena(nuevaReserva.horaInicio, horaInicio, 6);
    copiarCadena(nuevaReserva.fechaFin, fechaFin, 11);
    copiarCadena(nuevaReserva.horaFin, horaFin, 6);
    nuevaReserva.montoPagado = montoPagado;
    copiarCadena(nuevaReserva.nombreInquilino, nombreInquilino, 50);
    copiarCadena(nuevaReserva.cedulaInquilino, cedulaInquilino, 20);

    if (apartamentos[apartamento - 1].numReservas < MAX_RESERVAS)
    {
        apartamentos[apartamento - 1].reservas[apartamentos[apartamento - 1].numReservas++] = nuevaReserva;
        cout << "Reserva registrada exitosamente." << endl;
        guardarReservas();
    }
    else
    {
        cout << "No se pueden registrar mas reservas para este apartamento." << endl;
    }
}

void mostrarReservas()
{
    for (int i = 0; i < NUM_APARTAMENTOS; ++i)
    {
        cout << "Apartamento " << i + 1 << ":" << endl;
        for (int j = 0; j < apartamentos[i].numReservas; ++j)
        {
            Reserva &reserva = apartamentos[i].reservas[j];
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

void eliminarReserva()
{
    int apartamento, indiceReserva;

    cout << "Ingrese el numero de apartamento (1-8): ";
    cin >> apartamento;
    if (apartamento < 1 || apartamento > 8)
    {
        cout << "Numero de apartamento invalido." << endl;
        return;
    }

    cout << "Reservas del apartamento " << apartamento << ":" << endl;
    for (int i = 0; i < apartamentos[apartamento - 1].numReservas; ++i)
    {
        cout << i + 1 << ". Reserva desde " << apartamentos[apartamento - 1].reservas[i].fechaInicio
             << " " << apartamentos[apartamento - 1].reservas[i].horaInicio
             << " hasta " << apartamentos[apartamento - 1].reservas[i].fechaFin
             << " " << apartamentos[apartamento - 1].reservas[i].horaFin << endl;
    }

    cout << "Ingrese el numero de la reserva a eliminar: ";
    cin >> indiceReserva;
    if (indiceReserva < 1 || indiceReserva > apartamentos[apartamento - 1].numReservas)
    {
        cout << "Numero de reserva invalido." << endl;
        return;
    }

    for (int i = indiceReserva - 1; i < apartamentos[apartamento - 1].numReservas - 1; ++i)
    {
        apartamentos[apartamento - 1].reservas[i] = apartamentos[apartamento - 1].reservas[i + 1];
    }
    --apartamentos[apartamento - 1].numReservas;
    cout << "Reserva eliminada exitosamente." << endl;
    guardarReservas();
}

int menuCalendario()
{
    int opcion;
    cout << "Seleccione una opcion:" << endl;
    cout << "1. Registrar nueva reserva" << endl;
    cout << "2. Ver reservas registradas" << endl;
    cout << "3. Eliminar reserva" << endl;
    cout << "4. Salir" << endl;
    cout << "Opcion: ";
    cin >> opcion;
    return opcion;
}

void principalCalendario()
{
    cargarReservas();
    menuCalendario();
    char continuar;
    do
    {
        int opcion = menuCalendario();

        switch (opcion)
        {
        case 1:
            system("cls || clear");
            registrarReserva();
            system("pause");
            break;
        case 2:
            system("cls || clear");
            mostrarReservas();
            system("pause");
            break;
        case 3:
            system("cls || clear");
            eliminarReserva();
            system("pause");
            break;
        case 4:
            return;
        default:
            cout << "Opcion no valida. Intente nuevamente.\n";
            system("cls || clear");
        }
        cout << "¿Desea realizar otra operacion? (S/N): ";
        cin >> continuar;
        system("cls || clear");
    } while (continuar == 'S' || continuar == 's');

    delete[] apartamentos;
}