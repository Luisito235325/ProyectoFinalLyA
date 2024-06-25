#include <iostream>

using namespace std;

struct REGISTROPAGO
{
    int id;
    char nombre[100];
    int numApartamento;
    int facturaPagada;
    char montoPagar[20];
};
REGISTROPAGO registro[100];

int position = 0;
int opcion;