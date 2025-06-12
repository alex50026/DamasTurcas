#include <iostream>
#include "tablero.h"
#include "fichas.h"
using namespace std;

int main()
{
    char tablero[TAM][TAM + 1];

    Jugando(tablero);
    return 0;
}
