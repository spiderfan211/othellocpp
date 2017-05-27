#include "Tablero.h"
#include "Clasematriz.h"
using namespace std;
  //  Tablero(int fichas, int fi, int co ){
  //
  //  };

    Tablero(){
      puntuacion = 0;
      turno = 0;
      finalizado = false;
      ganador = 0;
      n = 4;
      m();
    }
    void Tablero::ImprimeTablero(){
      cout<< "  a b c d e f g h "<<endl<<endl;
      cout<< " -----------------"<<endl;
      for (int i = 0; i < t.GetFils; i++){
        cout<< i << "|";
        for (int j = 0; i < t.GetCols; j++){
          cout<< this.GetElemento(i, j) << "|"<<endl;   //SUPONGO    (ASÍ NO SALEN X Y O, SINO 1  Y 2)
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
      return Ganador;
    };

    int Tablero::CalculaPuntuacion (){
      return puntuacion;
    };
    bool Tablero::PosValida(int f, int c){
      bool cosa;
      int j = c;
      int k = c + 1;
      int l = c - 1;




      for (int i = f+1; i < this.GetFilas(); i++) {
      //  if((this.GetElem(i,j) != turno) && (this.GetElem(i,j) != 0) ){

      //  }
      while((this.GetElem(i,j) != turno)  &&  (this.GetElem(i,j) != 0))
        this.GetElem(f,c)
      }
      return this.GetElem(f,c) == 0 && f < this.GetFilas() && c < this.GetColumnas;






    }
    bool Tablero::PuedePoner(int f, int c){
      if (this.PosValida(f,c) && m.GetElemento(f,c) != turno){
        return true;
      };
      else
        return false
        //NO ESTOY SEGURO
    }
    bool Tablero::Inserta(int f, int c){
      if(this.PuedePoner(f,c)){
        m.SetElemento(f,c);
        return true;
      };
      else
        return false;
    }

    bool Tablero::Vacia(){
      for( int i = 0; i < m.GetFilas(); i++){
        for( int j = 0; j< m.GetColumnas(); j++){
          m.SetElemento(i, j, 0);
        }
      }
    }
  };
