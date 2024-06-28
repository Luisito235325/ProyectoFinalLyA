#include <iostream>
#include "variables.h"

using namespace std;

void limpiarPantalla();
void ActualizarEstadoPago();
void MostrarFactura();
void MostrarFacturasRegistradas();
void EliminarFactura();
void principal();

void LimpiarPantalla()
{
    system("cls");
}

void RegistrarFactura()
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

void ActualizarEstadoPago()
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

void MostrarFactura()
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

void MostrarFacturasRegistradas()
{
    for (int i = 0; i < cantidadFacturas; ++i)
    {
        MostrarFactura();
    }
}

void EliminarFactura()
{
    int facturaAEliminar;
    cout << "Ingrese el número de factura a eliminar: ";
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
            // Repite para los demás arreglos
        }
        cantidadFacturas--;
        cout << "Factura eliminada correctamente." << endl;
    }
    else
    {
        cout << "No se encontró la factura con el número ingresado." << endl;
    }
}

void principal()
{
    do
    {
        LimpiarPantalla();
        cout << "Seleccione una opción:\n";
        cout << "1. Registrar nueva factura\n";
        cout << "2. Ver facturas registradas\n";
        cout << "3. Eliminar factura\n";
        cout << "4. Salir\n";
        cout << "Opción: ";
        cin >> opcion;

        switch (opcion)
        {
        case '1':
            RegistrarFactura();
            ActualizarEstadoPago();
            MostrarFactura();
            cantidadFacturas++;
            break;
        case '2':
            LimpiarPantalla();
            cout << "Facturas Registradas:" << endl;
            MostrarFacturasRegistradas();
            break;
        case '3':
            EliminarFactura();
            break;
        case '4':
            return;
        default:
            cout << "Opción no válida. Intente nuevamente.\n";
        }
        cout << "¿Desea realizar otra operación? (S/N): ";
        cin >> opcion;
    } while (opcion == 'S' || opcion == 's');
}