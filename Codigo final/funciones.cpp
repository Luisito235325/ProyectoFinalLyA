#include <iostream>
#include <cstdio>
#include <ctime>
#include <fstream>
#include "Variables.h"

using namespace std;

bool compararFechas(const char *fecha1, const char *hora1, const char *fecha2, const char *hora2);
bool validarFechaHora(const char *fecha, const char *hora);
void copiarCadena(char *destino, const char *origen, int longitud);
int menuCalendario();

bool compararFechas(const char *fecha1, const char *hora1, const char *fecha2, const char *hora2)
{
    int dia1, mes1, anio1, horaInt1, minuto1;
    int dia2, mes2, anio2, horaInt2, minuto2;

    sscanf(fecha1, "%2d/%2d/%4d", &dia1, &mes1, &anio1);
    sscanf(hora1, "%2d:%2d", &horaInt1, &minuto1);
    sscanf(fecha2, "%2d/%2d/%4d", &dia2, &mes2, &anio2);
    sscanf(hora2, "%2d:%2d", &horaInt2, &minuto2);

    if (anio1 < anio2)
        return true;
    if (anio1 > anio2)
        return false;
    if (mes1 < mes2)
        return true;
    if (mes1 > mes2)
        return false;
    if (dia1 < dia2)
        return true;
    if (dia1 > dia2)
        return false;
    if (horaInt1 < horaInt2)
        return true;
    if (horaInt1 > horaInt2)
        return false;
    return minuto1 < minuto2;
}

bool validarFechaHora(const char *fecha, const char *hora)
{
    int dia, mes, anio, horaInt, minuto;
    if (sscanf(fecha, "%2d/%2d/%4d", &dia, &mes, &anio) != 3)
        return false;
    if (sscanf(hora, "%2d:%2d", &horaInt, &minuto) != 2)
        return false;
    if (dia < 1 || dia > 31 || mes < 1 || mes > 12 || anio < 2023)
        return false;
    if (horaInt < 0 || horaInt > 23 || minuto < 0 || minuto > 59)
        return false;
    return true;
}

void obtenerFechaHoraActual(char *fecha, char *hora)
{
    time_t t = time(nullptr);
    tm *now = localtime(&t);

    sprintf(fecha, "%02d/%02d/%04d", now->tm_mday, now->tm_mon + 1, now->tm_year + 1900);
    sprintf(hora, "%02d:%02d", now->tm_hour, now->tm_min);
}

void copiarCadena(char *destino, const char *origen, int longitud)
{
    for (int i = 0; i < longitud - 1 && origen[i] != '\0'; ++i)
    {
        destino[i] = origen[i];
    }
    destino[longitud - 1] = '\0';
}

void guardarReservas()
{
    FILE *archivo = fopen("reservas.dat", "wb");
    if (archivo)
    {
        fwrite(&NUM_APARTAMENTOS, sizeof(NUM_APARTAMENTOS), 1, archivo);
        for (int i = 0; i < NUM_APARTAMENTOS; ++i)
        {
            fwrite(&apartamentos[i].numReservas, sizeof(apartamentos[i].numReservas), 1, archivo);
            fwrite(apartamentos[i].reservas, sizeof(Reserva), apartamentos[i].numReservas, archivo);
        }
        fclose(archivo);
    }
}

void cargarReservas()
{
    FILE *archivo = fopen("reservas.dat", "rb");
    if (archivo)
    {
        fread(&NUM_APARTAMENTOS, sizeof(NUM_APARTAMENTOS), 1, archivo);
        apartamentos = new Apartamento[NUM_APARTAMENTOS];
        for (int i = 0; i < NUM_APARTAMENTOS; ++i)
        {
            fread(&apartamentos[i].numReservas, sizeof(apartamentos[i].numReservas), 1, archivo);
            fread(apartamentos[i].reservas, sizeof(Reserva), apartamentos[i].numReservas, archivo);
        }
        fclose(archivo);
    }
    else
    {
        apartamentos = new Apartamento[NUM_APARTAMENTOS];
    }
}

void registrarReserva()
{
    int apartamento;
    char fechaInicio[11], horaInicio[6];
    char fechaFin[11], horaFin[6];
    double montoPagado;
    char nombreInquilino[50];
    char cedulaInquilino[20];

    cout << "Ingrese el numero de apartamento (1-8): ";
    cin >> apartamento;
    if (apartamento < 1 || apartamento > 8)
    {
        cout << "Numero de apartamento invalido." << endl;
        return;
    }

    obtenerFechaHoraActual(fechaInicio, horaInicio);
    cout << "Fecha y hora de inicio de la reserva: " << fechaInicio << " " << horaInicio << endl;

    cout << "Ingrese la fecha de fin de la reserva (DD/MM/AAAA): ";
    cin.ignore();
    cin >> fechaFin;
    cout << "Ingrese la hora de fin de la reserva (HH:MM): ";
    cin >> horaFin;
    if (!validarFechaHora(fechaFin, horaFin) || !compararFechas(fechaInicio, horaInicio, fechaFin, horaFin))
    {
        cout << "Fecha y hora de fin invalidas." << endl;
        return;
    }

    cout << "Ingrese el monto pagado: ";
    cin >> montoPagado;
    cout << "Ingrese el nombre del inquilino: ";
    scanf(" %[^\n]", nombreInquilino);
    cin.ignore();
    cin.getline(nombreInquilino, 50);
    cout << "Ingrese el numero de cedula del inquilino: ";
    cin.getline(cedulaInquilino, 20);

    Reserva nuevaReserva = {apartamento, "", "", "", "", 0.0, ""};
    copiarCadena(nuevaReserva.fechaInicio, fechaInicio, 11);
    copiarCadena(nuevaReserva.horaInicio, horaInicio, 6);
    copiarCadena(nuevaReserva.fechaFin, fechaFin, 11);
    copiarCadena(nuevaReserva.horaFin, horaFin, 6);
    nuevaReserva.montoPagado = montoPagado;
    copiarCadena(nuevaReserva.nombreInquilino, nombreInquilino, 50);
    copiarCadena(nuevaReserva.cedulaInquilino, cedulaInquilino, 20);

    if (apartamentos[apartamento - 1].numReservas < MAX_RESERVAS)
    {
        apartamentos[apartamento - 1].reservas[apartamentos[apartamento - 1].numReservas++] = nuevaReserva;
        cout << "Reserva registrada exitosamente." << endl;
        guardarReservas();
    }
    else
    {
        cout << "No se pueden registrar mas reservas para este apartamento." << endl;
    }
}

void mostrarReservas()
{
    for (int i = 0; i < NUM_APARTAMENTOS; ++i)
    {
        cout << "Apartamento " << i + 1 << ":" << endl;
        for (int j = 0; j < apartamentos[i].numReservas; ++j)
        {
            Reserva &reserva = apartamentos[i].reservas[j];
            cout << "Reserva " << j + 1 << ": "
                 << "Fecha Inicio: " << reserva.fechaInicio << " " << reserva.horaInicio
                 << ", Fecha Fin: " << reserva.fechaFin << " " << reserva.horaFin
                 << ", Monto Pagado: $" << reserva.montoPagado
                 << ", Nombre Inquilino: " << reserva.nombreInquilino
                 << ", Cedula Inquilino: " << reserva.cedulaInquilino << endl;
        }
        cout << endl;
    }
}

void eliminarReserva()
{
    int apartamento, indiceReserva;

    cout << "Ingrese el numero de apartamento (1-8): ";
    cin >> apartamento;
    if (apartamento < 1 || apartamento > 8)
    {
        cout << "Numero de apartamento invalido." << endl;
        return;
    }

    cout << "Reservas del apartamento " << apartamento << ":" << endl;
    for (int i = 0; i < apartamentos[apartamento - 1].numReservas; ++i)
    {
        cout << i + 1 << ". Reserva desde " << apartamentos[apartamento - 1].reservas[i].fechaInicio
             << " " << apartamentos[apartamento - 1].reservas[i].horaInicio
             << " hasta " << apartamentos[apartamento - 1].reservas[i].fechaFin
             << " " << apartamentos[apartamento - 1].reservas[i].horaFin << endl;
    }

    cout << "Ingrese el numero de la reserva a eliminar: ";
    cin >> indiceReserva;
    if (indiceReserva < 1 || indiceReserva > apartamentos[apartamento - 1].numReservas)
    {
        cout << "Numero de reserva invalido." << endl;
        return;
    }

    for (int i = indiceReserva - 1; i < apartamentos[apartamento - 1].numReservas - 1; ++i)
    {
        apartamentos[apartamento - 1].reservas[i] = apartamentos[apartamento - 1].reservas[i + 1];
    }
    --apartamentos[apartamento - 1].numReservas;
    cout << "Reserva eliminada exitosamente." << endl;
    guardarReservas();
}

int menuCalendario()
{
    int opcion;
    cout << "Seleccione una opcion:" << endl;
    cout << "1. Registrar nueva reserva" << endl;
    cout << "2. Ver reservas registradas" << endl;
    cout << "3. Eliminar reserva" << endl;
    cout << "4. Salir" << endl;
    cout << "Opcion: ";
    cin >> opcion;
    return opcion;
}

void principalCalendario()
{
    cargarReservas();
    menuCalendario();
    char continuar;
    do
    {
        int opcion = menuCalendario();

        switch (opcion)
        {
        case 1:
            system("cls");
            registrarReserva();
            break;
        case 2:
            system("cls");
            mostrarReservas();
            break;
        case 3:
            system("cls");
            eliminarReserva();
            break;
        case 4:
            return;
        default:
            cout << "Opcion no valida. Intente nuevamente.\n";
            system("cls");
        }
        cout << "¿Desea realizar otra operacion? (S/N): ";
        cin >> continuar;
        system("cls");
    } while (continuar == 'S' || continuar == 's');

    delete[] apartamentos;
}

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

extern const int habitacionesTotales;
void inicializarHabitaciones();
void OcuparHabitacion();
void Hotel();
void MostrarEstado();
void LiberarHabitacion();
void GuardarEstado();
void CargarEstado();

void inicializarHabitaciones()
{
    for (int i = 0; i < habitacionesTotales; ++i)
    {
        habitaciones[i] = false;
    }
}

void OcuparHabitacion(int numHabitacion)
{
    if (numHabitacion > 0 && numHabitacion <= habitacionesTotales)
    {
        if (!habitaciones[numHabitacion - 1])
        {
            habitaciones[numHabitacion - 1] = true;
            habitacionesOcupadas++;
            habitacionesDisponibles--;
            cout << "Habitacion " << numHabitacion << " ocupada exitosamente.\n";
        }
        else
        {
            cout << "La habitacion " << numHabitacion << " ya esta ocupada.\n";
        }
    }
    else
    {
        cout << "Numero de habitacion invalido.\n";
    }
}

void LiberarHabitacion(int numHabitacion)
{
    if (numHabitacion > 0 && numHabitacion <= habitacionesTotales)
    {
        if (habitaciones[numHabitacion - 1])
        {
            habitaciones[numHabitacion - 1] = false;
            habitacionesOcupadas--;
            habitacionesDisponibles++;
            cout << "Habitacion " << numHabitacion << " liberada exitosamente.\n";
        }
        else
        {
            cout << "La habitacion " << numHabitacion << " ya esta libre.\n";
        }
    }
    else
    {
        cout << "Numero de habitacion invalido.\n";
    }
}

void MostrarEstado()
{
    cout << "Estado de las habitaciones:\n";
    for (int i = 0; i < habitacionesTotales; ++i)
    {
        cout << "Habitacion " << i + 1 << ": " << (habitaciones[i] ? "Ocupada" : "Libre") << "\n";
    }
}

void GuardarEstado()
{
    ofstream archivo("estado_habitaciones.txt");
    if (archivo.is_open())
    {
        archivo << habitacionesOcupadas << endl;
        archivo << habitacionesDisponibles << endl;
        for (int i = 0; i < habitacionesTotales; ++i)
        {
            archivo << habitaciones[i] << endl;
        }
        archivo.close();
        cout << "Estado guardado exitosamente.\n";
    }
    else
    {
        cout << "No se pudo abrir el archivo para guardar.\n";
    }
}

void CargarEstado()
{
    ifstream archivo("estado_habitaciones.txt");
    if (archivo.is_open())
    {
        archivo >> habitacionesOcupadas;
        archivo >> habitacionesDisponibles;
        for (int i = 0; i < habitacionesTotales; ++i)
        {
            archivo >> habitaciones[i];
        }
        archivo.close();
        cout << "Estado cargado exitosamente.\n";
    }
    else
    {
        cout << "No se pudo abrir el archivo para cargar.\n";
    }
}

void Hotel()
{
    inicializarHabitaciones();

    int opcion;
    do
    {
        cout << "\nMenu:\n";
        cout << "1. Ocupar una habitación" << endl;
        cout << "2. Liberar una habitación" << endl;
        cout << "3. Mostrar estado de las habitaciones" << endl;
        cout << "4. Guardar estado" << endl;
        cout << "5. Cargar estado" << endl;
        cout << "6. Salir" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
        {
            int numHabitacion;
            cout << "Ingrese el número de la habitación a ocupar (1-" << habitacionesTotales << "): ";
            cin >> numHabitacion;
            OcuparHabitacion(numHabitacion);
            break;
        }
        case 2:
        {
            int numHabitacion;
            cout << "Ingrese el número de la habitación a liberar (1-" << habitacionesTotales << "): ";
            cin >> numHabitacion;
            LiberarHabitacion(numHabitacion);
            break;
        }
        case 3:
            MostrarEstado();
            break;
        case 4:
            GuardarEstado();
            break;
        case 5:
            CargarEstado();
            break;
        case 6:
            cout << "Saliendo del programa.\n";
            break;
        default:
            cout << "Opción inválida. Intente de nuevo.\n";
            break;
        }
    } while (opcion != 6);
}

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

void home()
{
    int opcion;
    do
    {
        cout << "Menu Principal" << endl;
        cout << "1. Hacer una reservacion" << endl;
        cout << "2. Ver habitaciones disponibles" << endl;
        cout << "3. Facturacion" << endl;
        cout << "4. Registros de pago de clientes" << endl;
        cout << "5. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            principalCalendario();
            break;
        case 2:
            Hotel();
            break;
        case 3:
            facturacion();
            break;
        case 4:
            Registro();
            break;
        case 5:
            cout << "Gracias por utilizar nuestro servicio" << endl;
            cout << "Saliendo del programa..." << endl;
            break;
        default:
            cout << "Opcion invalida. Intente de nuevo.\n";
            break;
        }
    } while (opcion != 5);
}