#include <iostream>
#include "CRUD.cpp"

int menu();
void principal();

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
