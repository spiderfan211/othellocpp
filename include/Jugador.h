#ifndef _JUGADORH_
#define _JUGADORH_
#include<iostream>
#include "Tablero.h"

using namespace std;

class Jugador {
private:
  char nombre[50];
  int turno;
  int punt;
  int DialogoEscoger(int n, int* p, Tablero& t);

public:
  Jugador(char nom_jugador[], int num_jugador);
  int EscogePosicion(int c, Tablero& t);
	void ImprimeNombre();
  int GetTurno();
  int GetPuntuacion(Tablero& tablero);


};
#endif
