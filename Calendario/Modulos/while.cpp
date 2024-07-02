#include <iostream>
#include "menu.cpp"
#include "reservas.cpp"
#include "utilidades.cpp"

using namespace std;

void principal() {
    cargarReservas();

    char continuar;
    do {
        int opcion = menu();

        switch (opcion) {
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