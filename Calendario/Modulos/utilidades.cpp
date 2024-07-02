#include <iostream>
#include <cstring>
#include <ctime>
#include "variables.h"

using namespace std;

void obtenerFechaHoraActual(char fecha[], char hora[]);
bool validarFechaHora(const char fecha[], const char hora[]);
bool compararFechas(const char fechaInicio[], const char horaInicio[], const char fechaFin[], const char horaFin[]);
void copiarCadena(char destino[], const char fuente[], int tamano);


void obtenerFechaHoraActual(char fecha[], char hora[]) {
    time_t now = time(0);
    tm *ltm = localtime(&now);

    sprintf(fecha, "%02d/%02d/%04d", ltm->tm_mday, 1 + ltm->tm_mon, 1900 + ltm->tm_year);
    sprintf(hora, "%02d:%02d", ltm->tm_hour, ltm->tm_min);
}

bool validarFechaHora(const char fecha[], const char hora[]) {
    int dia, mes, ano, hora, minuto;
    if (sscanf(fecha, "%d/%d/%d", &dia, &mes, &ano) != 3) return false;
    if (sscanf(hora, "%d:%d", &hora, &minuto) != 2) return false;

    if (ano < 1900 || ano > 9999) return false;
    if (mes < 1 || mes > 12) return false;
    if (dia < 1 || dia > 31) return false;

    if (hora < 0 || hora > 23) return false;
    if (minuto < 0 || minuto > 59) return false;

    return true;
}

bool compararFechas(const char fechaInicio[], const char horaInicio[], const char fechaFin[], const char horaFin[]) {
    tm tmInicio = {}, tmFin = {};
    sscanf(fechaInicio, "%d/%d/%d", &tmInicio.tm_mday, &tmInicio.tm_mon, &tmInicio.tm_year);
    sscanf(horaInicio, "%d:%d", &tmInicio.tm_hour, &tmInicio.tm_min);
    sscanf(fechaFin, "%d/%d/%d", &tmFin.tm_mday, &tmFin.tm_mon, &tmFin.tm_year);
    sscanf(horaFin, "%d:%d", &tmFin.tm_hour, &tmFin.tm_min);

    tmInicio.tm_mon -= 1; 
    tmInicio.tm_year -= 1900; 
    tmFin.tm_mon -= 1; 
    tmFin.tm_year -= 1900;

    time_t timeInicio = mktime(&tmInicio);
    time_t timeFin = mktime(&tmFin);

    return difftime(timeInicio, timeFin) < 0;
}

void copiarCadena(char destino[], const char fuente[], int tamano) {
    strncpy(destino, fuente, tamano);
    destino[tamano - 1] = '\0';
}