#include <iostream>
#include "variables.h"

using namespace std;

int menu()
{
    cout << "Menú" << endl;
    cout << "1. Ingresar factura." << endl;
    cout << "2. Generar recibo." << endl;
    cout << "3. Eliminar recibo." << endl;
    cout << "4. Mostrar todos los recibos." << endl;
    cout << "5. Salir." << endl;
    cout << "Seleccione una opción: ";
    cin >> opcion;
    system("cls || clear");
    return 0;
}
