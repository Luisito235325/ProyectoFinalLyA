// registro de pagos de clientes.
#include <iostream>
#include <fstream>
#include <locale.h>
#include "variables.h"

using namespace std;

void agregarPago(REGISTROPAGO *c);
void generarReciboID();
int menu();
void principal();
void pedirDatos();
void showData(REGISTROPAGO &c);
REGISTROPAGO buscar(int id);
void eliminarDato();
void eliminar(int id);
int obtPos(int id);

int menu()
{
    cout << "Menu" << endl;
    cout << "1. Ingresar factura." << endl;
    cout << "2. Generar recibo." << endl;
    cout << "3. Eliminar factura/recibo." << endl;
    cout << "4. Mostrar todos los recibos." << endl;
    cout << "5. Salir." << endl;
    cout << "Seleccione una opcion: ";
    cin >> opcion;
    system("cls || clear");
}

void pedirDatos()
{
    REGISTROPAGO recibo;
    cout << "Datos del recibo\n";
    cout << "ID: ";
    cin >> recibo.id;
    cout << "NOMBRE: ";
    scanf(" %[^\n]", recibo.nombre);
    cout << "NUMERO DE APARTAMENTO: ";
    cin >> recibo.numApartamento;
    cout << "La factura esta pagada? " << endl;
    cout << "1. Si " << endl;
    cout << "2. No " << endl;
    cout << "Ingrese su opcion: ";
    cin >> recibo.facturaPagada;
    if (recibo.facturaPagada == 2)
    {
        cout << "Monto a pagar: ";
        cin >> recibo.montoPagar;
    }
    else
    {
        cout << "Favor ingrese el numero 0: ";
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

void generarReciboID()
{
    int id;
    cout << "Dime el ID de la factura: ";
    cin >> id;
    REGISTROPAGO c;
    c = buscar(id);
    showData(c);
}

REGISTROPAGO buscar(int id)
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

void showData(REGISTROPAGO &c)
{
    cout << "==============================" << endl;
    cout << "ID: ";
    cout << c.id << endl;
    cout << "NOMBRE: ";
    cout << c.nombre << endl;
    cout << "NUMERO DE APARTAMENTO: " << endl;
    cout << c.numApartamento << endl;
    cout << "Pago de la factura " << endl;
    cout << "1 = Factura pagada " << endl;
    cout << "2 = Factura pendiente " << endl;
    cout << "Estado de la factura: ";
    cout << c.facturaPagada << endl;
    cout << "Monto a pagar: ";
    cout << c.montoPagar << endl;
    cout << "==============================" << endl;
}

void mostrarDatos()
{
    for (int i = 0; i < position; i++)
    {
        showData(registro[i]);
    }
}

void eliminarDato()
{
    int id;
    cout << "Recibo - Eliminar\n";
    cout << "ID: ";
    cin >> id;
    eliminar(id);
    cout << "Eliminando..." << endl;
}

void eliminar(int id)
{
    int posi = obtPos(id);
    for (int i = posi; i < position - 1; i++)
    {
        registro[i] = registro[i + 1];
    }
    position--;
}

int obtPos(int id)
{
    for (int i = 0; i < position; i++)
    {
        if (registro[i].id == id)
        {
            return i;
        }
    }
    return -1;
}

void principal()
{
    setlocale(LC_CTYPE, "Spanish");
    do
    {
        system("cls || clear");
        menu();
        switch (opcion)
        {
        case 1:
            system("cls || clear");
            pedirDatos();
            system("pause");
            break;
        case 2:
            system("cls || clear");
            generarReciboID();
            system("pause");
            break;
        case 3:
            system("cls || clear");
            eliminarDato();
            system("pause");
        case 4:
            system("cls || clear");
            mostrarDatos();
            system("pause");
            break;
        case 5:
            cout << "Gracias por utilizar nuestro servicio" << endl;
            cout << "Saliendo del programa..." << endl;
            break;
        default:
            break;
        }
    } while (opcion != 5);
}
