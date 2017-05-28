#include<iostream>
#include "Tablero.h"
using namespace std;
  //  Tablero(int fichas, int fi, int co ){
  //
  //  };

    Tablero(){    //ERROR: Expected unqualified-id before ')' token
      puntuacion = 0;
      turno = 0;
      finalizado = false;
      ganador = 0;
      m();
    }

    void Tablero::ImprimeTablero(){
      cout<< "  a b c d e f g h "<<endl<<endl;
      cout<< " -----------------"<<endl;
      for (int i = 0; i < this->GetFils(); i++){
        cout<< i << "|";
        for (int j = 0; i < this->GetCols(); j++){
          cout<< this->GetElem(i, j) << "|"<<endl;   //SUPONGO    (ASÍ NO SALEN X Y O, SINO 1  Y 2)
        }
        cout<<endl;
      }
      cout<< " -----------------"<<endl;
    };

    int Tablero::GetFils(){
      return m.GetFilas();
    };
    int Tablero::GetCols(){
      return m.GetColumnas();
    };
    int Tablero::GetElem(int f, int c){
      return m.GetElemento(f,c);
    };
    bool Tablero::IsFinalizada(){
      return finalizado;
    };
    int Tablero::GetTurno(){
      return turno;
    };
    int Tablero::GetGanador(){
      return ganador;
    };

    int Tablero::CalculaPuntuacion (){
      return puntuacion;
    };
    bool Tablero::PosValida(int f, int c){        //MAL AÚN
      bool cosa;
      int j = c;
      int k = c + 1;
      int l = c - 1;




      for (int i = f+1; i < this->GetFils(); i++) {
      //  if((this.GetElem(i,j) != turno) && (this.GetElem(i,j) != 0) ){

      //  }
      while((this->GetElem(i,j) != turno)  &&  (this->GetElem(i,j) != 0))
        this->GetElem(f,c);
      }
      return this->GetElem(f,c) == 0 && f < this->GetFils() && c < this->GetCols();
    }


    bool Tablero::PuedePoner(int f, int c){
      if (this->PosValida(f,c) && m.GetElemento(f,c) != turno){
        return true;
      }
      else
        return false;
        //NO ESTOY SEGURO
    };
    bool Tablero::Inserta(int f, int c, int d){
      if(this->PuedePoner(f,c)){
        m.SetElemento(f,c, d);
        return true;
      }
      else
        return false;
    };

    void Tablero::Vacia(){      //CAMBIAR A BOOLEANO
      for( int i = 0; i < m.GetFilas(); i++){
        for( int j = 0; j< m.GetColumnas(); j++){
          m.SetElemento(i, j, 0);
        }
      }
    };
