#include "Clasematriz.h"

class Tablero{
private:
    Matriz m;
    int puntuacion;
    int turno;
    bool finalizado;
    int ganador;   //what
    int n;    //Número de fichas a alinear.

  public:
    void Tablero::ImprimeTablero();
//    Tablero(int fichas, int fi, int co );
    int GetFils();
    int GetCols();
    int GetN();
    int GetDato(int fil, int col);
    bool IsFinalizada();
    int GetTurno();
    int GetGanador();
    int CalculaPuntuacion ();
    //bool Tablero::PosValida(int f, int c);
    //ME FALTA LA IMPLEMENTACION DE LAS REGLAS DEL JUEGO EN LA POSICION VALIDA
    bool PuedePoner(int f, int c);//TAMPOCO SÉ SI FUNCIONA
    bool Inserta(int f, int c);
    bool Vacia();
  };
