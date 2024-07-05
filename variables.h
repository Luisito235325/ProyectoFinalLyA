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
    Reserva reservas[10];
    int numReservas = 0;
};

Apartamento* apartamentos;
int NUM_APARTAMENTOS = 8;
int MAX_RESERVAS = 10;

struct Factura
{
    int numeroFactura;
    char nombreCliente[100];
    char fechaEstancia[11];
    int numeroCuarto;
    double montoAPagar;
    double montoPagado;
    bool pagado;
};

Factura *facturas = nullptr;
int cantidadFacturas = 0;
int capacidadFacturas = 10;

const int habitacionesTotales = 8;
int habitacionesOcupadas = 0;
int habitacionesDisponibles = habitacionesTotales;
bool habitaciones[habitacionesTotales];

struct REGISTROPAGO
{
    int id;
    char nombre[100];
    int numApartamento;
    int facturaPagada;
    char montoPagar[20];
};
REGISTROPAGO registro[100];

int position = 0;
int opcion;