#include <iostream>
#include <cmath>
#include <ctime>
#define TAM 8
#define FichasJ1 X
#define FichasJ2 O
#ifndef __tablero__
#define __tablero__

using namespace std;
//ESTE STRUCT SE USARA PARA EL CAMBIO DE JUGADOR Y PARA ASEGURAR QUE EL JUEGO NO SIGA SI ALGUNO GANA
typedef struct s_jugador
{
  string nombre;
  bool gano;
} t_jugador;

#endif //__tablero__
//INT
int eligefila (t_jugador J);
int eligecol ();
int muevefila();
int muevecol();
int LaQEsfila(char tablero[TAM][TAM + 1], char figura, int restric);
int LaQEsCol(char tablero[TAM][TAM + 1], char figura, int restric);
//MUEVE Y ELGIGE FICHA(TIPO VOID)
void mueveficha (char tablero[TAM][TAM + 1], int a, int b, char fig, char f2, int restric, bool corono, char C);
void llena_jugadores (t_jugador J1, t_jugador J2);
void Jugando (char tablero[TAM][TAM + 1]);
void intercambio(char tablero[TAM][TAM + 1], int f1, int c1, int f2, int c2, int restric, char fig, bool corona, char C);
void mientrasTranscurre(char tablero[TAM][TAM + 1], t_jugador J1, t_jugador J2);
void SiHayImp(char tablero[TAM][TAM + 1], int restric);
void LeeTab (char tablero[TAM][TAM + 1], int ARR[2]);
void realizaJ1(char tablero[TAM][TAM + 1], t_jugador J1);
void realizaJ2(char tablero[TAM][TAM + 1], t_jugador J2);
//MOV
void MOV (char tablero[TAM][TAM + 1], int fila, int columna, char fig, char f2,
	  int restric, char C, bool corono);
void MOVC (char tablero[TAM][TAM + 1], int aux1, int aux2, int M1, int M2, 
char fig,  char f2, int restric, char C, bool corona);

//BOOL

bool cumpleTodo(int fila, int columna, char tablero[TAM][TAM + 1], char fig, char f2, int restric, char C);
bool RevisaEnCruz (char tablero[TAM][TAM + 1], int fila, int columna, char f2,
	int restric, char Otro, char fig);
bool cumple2movimiento(int filaORG, int columnaORG, int fila, int col, char tablero[TAM][TAM + 1], char fig, char f2, int restric, char C, bool corono);
bool SiEsQHay(char tablero[TAM][TAM + 1], int restric);
bool coronacion(char tablero[TAM][TAM + 1], int fila, int columna, char figCoro);
bool MovRealeza(char tablero[TAM][TAM + 1], int fila, int columna, char figCoro, int restric, int Forg, int Corg);
bool RevisaReinaAsesina(char tablero[TAM][TAM + 1], int fila, int columna,  char f2, int restric, char Otro, char fig);
bool AsesinaEnPto(char tablero[TAM][TAM + 1], int fila, int columna,  char f2, int restric, char Otro, char fig);
bool cumpleFeo(int fila, int columna, char tablero[TAM][TAM + 1], char fig, char f2, int restric, char C, bool corono);
bool EstaVacio(int fila, int columna, char tablero[TAM][TAM + 1], int Forg, int Corg, int res);