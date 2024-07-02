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