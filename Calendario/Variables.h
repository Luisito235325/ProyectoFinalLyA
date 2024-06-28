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