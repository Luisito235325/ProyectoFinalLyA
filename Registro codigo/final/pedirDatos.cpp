#include <iostream>
#include "variables.h"

using namespace std;

void agregarPago(REGISTROPAGO *c);

void pedirDatos()
{
    REGISTROPAGO recibo;
    cout << "Datos del recibo\n";
    cout << "ID: ";
    cin >> recibo.id;
    cout << "Nombre del cliente: ";
    scanf(" %[^\n]", recibo.nombre);    
    cout << "Número de apartamento: ";
    cin >> recibo.numApartamento;
    cout << "¿La factura está pagada? " << endl;
    cout << "1. Si " << endl;
    cout << "2. No " << endl;
    cout << "Ingrese su opción: ";
    cin >> recibo.facturaPagada;
    if (recibo.facturaPagada == 2)
    {
        cout << "Monto a pagar: ";
        cin >> recibo.montoPagar;
    }
    else
    {
        cout << "Favor ingrese el número 0: ";
        cin >> recibo.montoPagar;
    }

    agregarPago(&recibo);
    cout << "Registro Agregado....\n";
}

void agregarPago(REGISTROPAGO *c)
{
    registro[position] = *c;
    position++;
}