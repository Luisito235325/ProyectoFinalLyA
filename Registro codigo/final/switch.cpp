#include <iostream>
#include <fstream>
#include <locale.h>
#include "pedirDatos.cpp" 
#include "recibo.cpp"
#include "menu.cpp"
#include "eliminar.cpp"

using namespace std;

void principal();

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

