#include <iostream>
#include "variables.h" 

using namespace std;


void limpiarPantalla();
void actualizarEstadoPago();
void mostrarFactura();
void mostrarFacturasRegistradas();
void eliminarFactura();
int menu();
void principal();

void registrarFactura()
{
    cout << "Ingrese el numero de factura: ";
    cin >> numeroFactura;
    cout << "Ingrese el nombre del cliente: ";
    cin >> nombreCliente;
    cout << "Ingrese la fecha de estancia (DD/MM/AAAA): ";
    cin >> fechaEstancia;
    cout << "Ingrese el numero de cuarto: ";
    cin >> numeroCuarto;
    cout << "Ingrese el monto a pagar: ";
    cin >> montoAPagar;
    cout << "Ingrese el monto pagado: ";
    cin >> montoPagado;
}

void actualizarEstadoPago()
{
    if (montoPagado >= montoAPagar)
    {
        pagado = true;
    }
    else
    {
        pagado = false;
    }
}

void mostrarFactura()
{
    cout << "Numero de Factura: " << numeroFactura << endl;
    cout << "Nombre del Cliente: " << nombreCliente << endl;
    cout << "Fecha de Estancia: " << fechaEstancia << endl;
    cout << "Numero de Cuarto: " << numeroCuarto << endl;
    cout << "Monto a Pagar: $" << montoAPagar << endl;
    cout << "Monto Pagado: $" << montoPagado << endl;
    cout << "Estado: " << (pagado ? "Pagado" : "Pendiente") << endl;
    cout << "-----------------------------" << endl;
}

void mostrarFacturasRegistradas()
{
    for (int i = 0; i < cantidadFacturas; ++i)
    {
        mostrarFactura();
    }
}

void eliminarFactura()
{
    int facturaAEliminar;
    cout << "Ingrese el numero de factura a eliminar: ";
    cin >> facturaAEliminar;

    int indiceAEliminar = -1;
    for (int i = 0; i < cantidadFacturas; ++i)
    {
        if (numeroFactura[i] == facturaAEliminar)
        {
            indiceAEliminar = i;
            break;
        }
    }

    if (indiceAEliminar != -1)
    {
        for (int i = indiceAEliminar; i < cantidadFacturas - 1; ++i)
        {
            numeroFactura[i] = numeroFactura[i + 1];
            
        }
        cantidadFacturas--;
        cout << "Factura eliminada correctamente." << endl;
    }
    else
    {
        cout << "No se encontro la factura con el numero ingresado." << endl;
    }
}

int menu()
{
    int opcion;
    cout << "Seleccione una opcion:\n";
    cout << "1. Registrar nueva factura\n";
    cout << "2. Ver facturas registradas\n";
    cout << "3. Eliminar factura\n";
    cout << "4. Salir\n";
    cout << "Opcion: ";
    cin >> opcion;
    return opcion;
}

void principal()
{
    char opcion;
    do
    {
        int op = menu();
        switch (op)
        {
        case 1:
            system("cls");
            registrarFactura();
            actualizarEstadoPago();
            mostrarFactura();
            cantidadFacturas++;
            break;
        case 2:
            system("cls");
            cout << "Facturas Registradas:" << endl;
            mostrarFacturasRegistradas();
            break;
        case 3:
            system("cls");
            eliminarFactura();
            break;
        case 4:
            return;
        default:
            cout << "Opcion no valida. Intente nuevamente.\n";
        }

        cout << "¿Desea realizar otra operacion? (S/N): ";
        cin >> opcion;
        system("cls");
    } while (opcion == 'S' || opcion == 's');
}