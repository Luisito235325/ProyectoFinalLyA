#include <iostream>
#include <cstdio>
#include <ctime>
#include <fstream>
#include "funCalendario.cpp"

using namespace std;
 
void limpiarPantalla();
void actualizarEstadoPago(Factura *factura);
void mostrarFactura(Factura *factura);
void mostrarFacturasRegistradas();
void eliminarFactura();
int menuFacturacion();
void principal();
void guardarFacturas();
void cargarFacturas();

void registrarFactura()
{
    if (cantidadFacturas >= capacidadFacturas)
    {
        capacidadFacturas *= 2;
        Factura *nuevasFacturas = new Factura[capacidadFacturas];
        for (int i = 0; i < cantidadFacturas; ++i)
        {
            nuevasFacturas[i] = facturas[i];
        }
        delete[] facturas;
        facturas = nuevasFacturas;
    }

    Factura &factura = facturas[cantidadFacturas];
    cout << "Ingrese el numero de factura: ";
    cin >> factura.numeroFactura;
    cout << "Ingrese el nombre del cliente: ";
    scanf(" %[^\n]", factura.nombreCliente);
    cout << "Ingrese la fecha de estancia (DD/MM/AAAA): ";
    cin >> factura.fechaEstancia;
    cout << "Ingrese el numero de cuarto: ";
    cin >> factura.numeroCuarto;
    cout << "Ingrese el monto a pagar: ";
    cin >> factura.montoAPagar;
    cout << "Ingrese el monto pagado: ";
    cin >> factura.montoPagado;

    actualizarEstadoPago(&factura);
    cantidadFacturas++;
}

void actualizarEstadoPago(Factura *factura)
{
    if (factura->montoPagado >= factura->montoAPagar)
    {
        factura->pagado = true;
    }
    else
    {
        factura->pagado = false;
    }
}

void mostrarFactura(Factura *factura)
{
    cout << "Numero de Factura: " << factura->numeroFactura << endl;
    cout << "Nombre del Cliente: " << factura->nombreCliente << endl;
    cout << "Fecha de Estancia: " << factura->fechaEstancia << endl;
    cout << "Numero de Cuarto: " << factura->numeroCuarto << endl;
    cout << "Monto a Pagar: $" << factura->montoAPagar << endl;
    cout << "Monto Pagado: $" << factura->montoPagado << endl;
    cout << "Estado: " << (factura->pagado ? "Pagado" : "Pendiente") << endl;
    cout << "-----------------------------" << endl;
}

void mostrarFacturasRegistradas()
{
    for (int i = 0; i < cantidadFacturas; ++i)
    {
        mostrarFactura(&facturas[i]);
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
        if (facturas[i].numeroFactura == facturaAEliminar)
        {
            indiceAEliminar = i;
            break;
        }
    }

    if (indiceAEliminar != -1)
    {
        for (int i = indiceAEliminar; i < cantidadFacturas - 1; ++i)
        {
            facturas[i] = facturas[i + 1];
        }
        cantidadFacturas--;
        cout << "Factura eliminada correctamente." << endl;
    }
    else
    {
        cout << "No se encontro la factura con el numero ingresado." << endl;
    }
}

int menuFacturacion()
{
    int opcion;
    cout << "Seleccione una opcion:" << endl;
    cout << "1. Registrar nueva factura" << endl;
    cout << "2. Ver facturas registradas" << endl;
    cout << "3. Eliminar factura" << endl;
    cout << "4. Salir" << endl;
    cout << "Opcion: ";
    cin >> opcion;
    return opcion;
}

void guardarFacturas()
{
    FILE *archivo = fopen("facturas.dat", "wb");
    if (archivo)
    {
        fwrite(&cantidadFacturas, sizeof(cantidadFacturas), 1, archivo);
        fwrite(facturas, sizeof(Factura), cantidadFacturas, archivo);
        fclose(archivo);
    }
}

void cargarFacturas()
{
    FILE *archivo = fopen("facturas.dat", "rb");
    if (archivo)
    {
        fread(&cantidadFacturas, sizeof(cantidadFacturas), 1, archivo);
        facturas = new Factura[cantidadFacturas];
        fread(facturas, sizeof(Factura), cantidadFacturas, archivo);
        fclose(archivo);
    }
    else
    {
        facturas = new Factura[capacidadFacturas];
    }
}

void facturacion()
{
    cargarFacturas();
    menuFacturacion();
    char opcion;
    do
    {
        int op = menuFacturacion();
        switch (op)
        {
        case 1:
            system("cls");
            registrarFactura();
            guardarFacturas();
            break;
        case 2:
            system("cls");
            cout << "Facturas Registradas:" << endl;
            mostrarFacturasRegistradas();
            break;
        case 3:
            system("cls");
            eliminarFactura();
            guardarFacturas();
            break;
        case 4:
            guardarFacturas();
            return;
        default:
            cout << "Opcion no valida. Intente nuevamente.\n";
        }

        cout << "Desea realizar otra operacion? (S/N): ";
        cin >> opcion;
        system("cls");
    } while (opcion == 'S' || opcion == 's');
}