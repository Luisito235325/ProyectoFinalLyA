#include <iostream>
#include <cstdio>
#include <ctime>
#include <fstream>
#include "habitaciones.cpp"

using namespace std;

void agregarPago(REGISTROPAGO *c);
void generarReciboID();
void pedirDatos();
void showData(REGISTROPAGO &c);
REGISTROPAGO buscar(int id);
void eliminarDato();
void eliminar(int id);
int obtPos(int id);
void writeFile(const REGISTROPAGO &registro);
void saveAll();
int load();

void pedirDatos()
{
    REGISTROPAGO recibo;
    cout << "Datos del recibo\n";
    cout << "ID: ";
    cin >> recibo.id;
    cout << "Nombre: ";
    scanf(" %[^\n]", recibo.nombre);
    cout << "Numero de habitacion: ";
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
    writeFile(recibo);
    saveAll();
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
    cout << "Nombre: ";
    cout << c.nombre << endl;
    cout << "Numero de habitaciones: ";
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

int load()
{
    ifstream archivo("registros.txt");
    if (archivo.fail())
    {
        return 0;
    }
    int i = 0;
    while (archivo >> registro[i].id)
    {
        archivo.ignore();
        archivo.getline(registro[i].nombre, 100);
        archivo >> registro[i].numApartamento;
        archivo >> registro[i].facturaPagada;
        archivo >> registro[i].montoPagar;

        i++;
    }
    archivo.close();
    return i;
}

void writeFile(const REGISTROPAGO &registro)
{
    ofstream archivo;

    archivo.open("registros.txt", ios::app);

    if (archivo.fail())
    {
        cout << "No se puede abrir archivo" << endl;
        exit(1);
    }

    archivo << registro.id << endl;
    archivo << registro.nombre << endl;
    archivo << registro.numApartamento << endl;
    archivo << registro.facturaPagada << endl;
    archivo << registro.montoPagar << endl;
    archivo.close();
}

void saveAll()
{
    ofstream archivo;
    archivo.open("registros.txt", ios::trunc | ios::out);
    for (int i = 0; i < position; i++)
    {
        archivo << registro[i].id << endl;
        archivo << registro[i].nombre << endl;
        archivo << registro[i].numApartamento << endl;
        archivo << registro[i].facturaPagada << endl;
        archivo << registro[i].montoPagar << endl;
    }
    archivo.close();
}

int menuRegistro();
void principal();

int menuRegistro()
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

void Registro()
{
    setlocale(LC_CTYPE, "Spanish");
    do
    {
        system("cls || clear");
        menuRegistro();
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
            system("cls || clear");
            break;
        default:
            break;
        }
    } while (opcion != 5);
}