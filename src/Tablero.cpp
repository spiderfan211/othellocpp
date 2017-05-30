#include<iostream>
#include "Tablero.h"
using namespace std;


    Tablero::Tablero(): tablero(){    //ERROR: Expected unqualified-id before ')' token
      turno = 1;    // 1 ó 2 ó 0 ?
      finalizado = false;
      ganador = 0;
      tablero.SetElemento(fils/2,cols/2, 1);
      tablero.SetElemento(fils/2+1,cols/2+1, 1);
      tablero.SetElemento(fils/2+1,cols/2, 2);
      tablero.SetElemento(fils/2,cols/2+1, 2);
    }
    Tablero::Tablero(int f, int c):tablero(f, c){
      turno = 1;
      finalizado = false;
      ganador = 0;
      tablero.SetElemento(fils/2,cols/2, 1);
      tablero.SetElemento(fils/2+1,cols/2+1, 1);
      tablero.SetElemento(fils/2+1,cols/2, 2);
      tablero.SetElemento(fils/2,cols/2+1, 2);
    }

    void Tablero::ImprimeTablero(){
      cout<< "  a b c d e f g h "<<endl<<endl;
      cout<< " -----------------"<<endl;
      for (int i = 0; i < this->GetFils(); i++){
        cout<< i  << "|";
        for (int j = 0; i < this->GetCols(); j++){
          if(this->GetElem(i,j) == 0 )
            cout << "| ";
          else if (this->GetElem(i,j) == 1)
            cout << "|x";
          else if (this->GetElem(i,j) == 2)
            cout << "|o";
          };
          cout << "|" << endl;
      };
      cout<< " -----------------"<<endl;
    };

    int Tablero::GetFils(){
      return tablero.GetFilas();
    };
    int Tablero::GetCols(){
      return tablero.GetColumnas();
    };
    int Tablero::GetElem(int f, int c){
      return tablero.GetElemento(f,c);
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
      if (this->PosValida(f,c) && tablero.GetElemento(f,c) != turno){
        return true;
      }
      else
        return false;
        //NO ESTOY SEGURO
    };
    bool Tablero::Inserta(int f, int c, int d){
      if(this->PuedePoner(f,c)){
        tablero.SetElemento(f,c, d);
        return true;
      }
      else
        return false;
    };

    void Tablero::Vacia(){      //CAMBIAR A BOOLEANO
      for( int i = 0; i < tablero.GetFilas(); i++){
        for( int j = 0; j< tablero.GetColumnas(); j++){
          tablero.SetElemento(i, j, 0);
        }
      }
    };
