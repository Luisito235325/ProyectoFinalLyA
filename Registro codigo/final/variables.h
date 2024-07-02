#include <iostream>

using namespace std;

typedef struct REGISTROPAGO
{
    int id;
    char nombre[100];
    int numApartamento;
    int facturaPagada;
    char montoPagar[20];
    int position = 0;
    int opcion;
};

REGISTROPAGO registro[100];

