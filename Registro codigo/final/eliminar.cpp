#include <iostream>
#include "variables.h"

using namespace std;

void eliminarDato();
void eliminar(int id);
int obtPos(int id);

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