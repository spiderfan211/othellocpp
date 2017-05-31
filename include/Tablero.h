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
    bool CambioTurno();
    int GetGanador();
    void AcabarPartida();
    void PuntuacionTotal();
    int GetPuntuacion( int j );
    bool PosValida(int f, int c);
    //ME FALTA LA IMPLEMENTACION DE LAS REGLAS DEL JUEGO EN LA POSICION VALIDA
    bool PuedePoner(int f, int c);//TAMPOCO SÉ SI FUNCIONA
    bool Inserta(int f, int c, int d);    //CAMBIAR A BOOLEANO
    void Vacia();
  };
#endif
