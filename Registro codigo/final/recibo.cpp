#include <iostream>
#include "variables.h"

using namespace std;

void generarReciboID();
void showData(const REGISTROPAGO &c);
REGISTROPAGO buscar(int id);
void mostrarDatos();

void generarReciboID()
{
    int id;
    cout << "Ingrese el ID de la factura: ";
    cin >> id;
    REGISTROPAGO c;
    c = buscar(id);
    showData(c);
}

void showData(const REGISTROPAGO &c)
{
    cout << "==============================" << endl;
    cout << "ID: ";
    cout << c.id << endl;
    cout << "NOMBRE: ";
    cout << c.nombre << endl;
    cout << "NUMERO DE APARTAMENTO: " << endl;
    cout << c.numApartamento << endl;
    cout << "PAGO DE LA FACTURA " << endl;
    cout << "1 = Factura pagada " << endl;
    cout << "2 = Factura pendiente " << endl;
    cout << "Estado de la factura: ";
    cout << c.facturaPagada << endl;
    cout << "Monto a pagar: ";
    cout << c.montoPagar << endl;
    cout << "==============================" << endl;
}

REGISTROPAGO buscar(int id, int position = 0)
{
    for (int i = 0; i < position; i++)
    {
        if (id == registro[i].id)
        {
            return registro[i];
        }
    }
    REGISTROPAGO c;
    return c;
}


void mostrarDatos(int position = 0)
{
    for (int i = 0; i < position; i++)
    {
        showData(registro[i]);
    }
}