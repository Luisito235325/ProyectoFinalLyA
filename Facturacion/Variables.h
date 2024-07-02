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
int capacidadFacturas = 10; // capacidad inicial