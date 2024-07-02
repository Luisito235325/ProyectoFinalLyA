#include <iostream>

using namespace std;


const int habitacionesTotales = 8;
bool habitaciones[habitacionesTotales];
int habitacionesOcupadas = 0;
int habitacionesDisponibles = habitacionesTotales;

// Estructuras y variables para la gestión de reservas
const int NUM_APARTAMENTOS = 8;
const int MAX_RESERVAS = 100;

struct Reserva {
    int apartamento;
    char fechaInicio[11];
    char horaInicio[6];   
    char fechaFin[11];    
    char horaFin[6];      
    double montoPagado;
    char nombreInquilino[50];
    char cedulaInquilino[20];
};

struct Apartamento {
    bool disponible;
    Reserva reservas[MAX_RESERVAS]; 
    int numReservas; 
};

Apartamento apartamentos[NUM_APARTAMENTOS];

// Variables y funciones para la gestión de facturación
const int MAX_CHAR = 100;

char numeroFactura[MAX_CHAR];
char nombreCliente[MAX_CHAR];
char fechaEstancia[MAX_CHAR];
char numeroCuarto[MAX_CHAR];
double montoAPagar;
double montoPagado;
int cantidadFacturas = 0;
bool pagado;
