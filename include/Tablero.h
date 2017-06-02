#ifndef _TABLEROH_
#define _TABLEROH_
#include "Clasematriz.h"
#include <iostream>

class Tablero{
private:
    Matriz tablero;
  //  int puntuacion;
    int turno;
    bool finalizado;
    int puntuacion1, puntuacion2;
    int ganador;   //what

  public:
    Tablero();
    Tablero(int f, int c);
    void ImprimeTablero();
//    Tablero(int fichas, int fi, int co );
    int GetFils();
    int GetCols();
    int GetElem(int f, int c);
    bool IsFinalizada();
    int GetTurno();
    void CambioTurno();
    int GetGanador();
    void AcabarPartida();
    void PuntuacionTotal();
    int GetPuntuacion( int j );
    void Vacia();
    int TurnoContrario();
    void Coloca(int f, int c);
    int PosValida(int** movs);
    bool MovPosible(int** movs);

  };
#endif
