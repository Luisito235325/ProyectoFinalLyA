#include <iostream>
#include <cstdio>
#include <ctime>
#include <fstream>
#include "registros.cpp"

using namespace std;


void home()
{
    int opcion;
    do
    {
        cout << " __ __                            _            _            _ " << endl;
        cout << "|  \\  \\ ___ ._ _  _ _   ___  _ _ <_>._ _  ___ <_> ___  ___ | |" << endl;
        cout << "|     |/ ._>| ' || | | | . \\| '_>| || ' |/ | '| || . \\<_> || |" << endl;
        cout << "|_|_|_|\\___.|_|_|`___| |  _/|_|  |_||_|_|\\_|_.|_||  _/<___||_|" << endl;
        cout << "                       |_|                       |_|          " << endl;
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
        system("cls || clear");
            principalCalendario();
            system("pause");
            break;
        case 2:
        system("cls || clear");
            Hotel();
            system("pause");
            break;
        case 3:
        system("cls || clear");
            facturacion();
            system("pause");
            break;
        case 4:
        system("cls || clear");
            Registro();
            system("pause");
            break;
        case 5:
            cout << "Gracias por utilizar nuestro servicio" << endl;
            cout << "Saliendo del programa..." << endl;
            break;
        default:
            cout << "Opcion invalida. Intente de nuevo.\n";
            system("cls || clear");
            break;
        }
    } while (opcion != 5);
}