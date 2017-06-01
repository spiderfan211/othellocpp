#include<iostream>
#include "Tablero.h"
using namespace std;


    Tablero::Tablero(): tablero(){
      turno = 1;
      finalizado = false;
      ganador = 0;
      tablero.SetElemento(tablero.GetFilas()/2,tablero.GetColumnas()/2, 1);
      tablero.SetElemento(tablero.GetFilas()/2+1,tablero.GetColumnas()/2+1, 1);
      tablero.SetElemento(tablero.GetFilas()/2+1,tablero.GetColumnas()/2, 2);
      tablero.SetElemento(tablero.GetFilas()/2,tablero.GetColumnas()/2+1, 2);
    }

    Tablero::Tablero(int f, int c):tablero(f, c){
      turno = 1;
      finalizado = false;
      ganador = 0;
      tablero.SetElemento(tablero.GetFilas()/2,tablero.GetColumnas()/2, 1);
      tablero.SetElemento(tablero.GetFilas()/2+1,tablero.GetColumnas()/2+1, 1);
      tablero.SetElemento(tablero.GetFilas()/2+1,tablero.GetColumnas()/2, 2);
      tablero.SetElemento(tablero.GetFilas()/2,tablero.GetColumnas()/2+1, 2);
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

    void Tablero::CambioTurno(){
  			if(turno == 1)
  				turno = 2;
  			else
  				turno = 1;
    };

    int Tablero::GetGanador(){
      return ganador;
    };

    void Tablero::AcabarPartida()
    {
      finalizado = true;
    };

    void Tablero::PuntuacionTotal(){
  		puntuacion1 = 0;
      puntuacion2 = 0;

  		if(this->IsFinalizada() == true){
  			for(int i = 0; i < tablero.GetFilas(); ++i){
  				for(int j = 0; j < tablero.GetColumnas(); ++j){
  					if (tablero.GetElemento(i,j) == 1)
  						puntuacion1++;
            else if( tablero.GetElemento(i,j) == 2)
              puntuacion2++;
  				}
  			}
      }
  	};

    int Tablero::GetPuntuacion( int j ){
      if( j == 1 )
        return puntuacion1;
      else
        return puntuacion2;
    }


    void Tablero::Vacia(){
      if(finalizado == true){
        for( int i = 0; i < tablero.GetFilas(); i++){
          for( int j = 0; j< tablero.GetColumnas(); j++){
            tablero.SetElemento(i, j, 0);
          }
        }
        tablero.SetElemento(tablero.GetFilas()/2,tablero.GetColumnas()/2, 1);
        tablero.SetElemento(tablero.GetFilas()/2+1,tablero.GetColumnas()/2+1, 1);
        tablero.SetElemento(tablero.GetFilas()/2+1,tablero.GetColumnas()/2, 2);
        tablero.SetElemento(tablero.GetFilas()/2,tablero.GetColumnas()/2+1, 2);
        finalizado = true;
        turno = 1;
      }
    };

    int Tablero::TurnoContrario(){
      int t;
      if (turno == 1)
        return t = 2;
      else
        return t = 1;
    }

    void Tablero::Coloca(int f, int c)
    {
       int f_inc = 0;
       int c_inc = 0;
       int x = 0;
       int y = 0;


       tablero.SetElemento(f, c, turno);

       for(f_inc = -1; f_inc <= 1; f_inc++)
         for(c_inc = -1; c_inc <= 1; c_inc++)
         {
           if(f + f_inc < 0 || f + f_inc >= this->GetFils()
             || c + c_inc < 0 || c + c_inc >= this->GetCols()
             || (f_inc ==0 && c_inc == 0))
           {

               if(this->GetElemento(f + f_inc, c + c_inc) == this->TurnoContrario(){
                 x = f + f_inc;
                 y = c + c_inc;


                bool salir;
                 do{
                   salir = false;
                   x += f_inc;
                   y += c_inc;

                   if(x < 0 || x >= SIZE || y < 0 || y >= SIZE)
                     salir = true;
                   if(this->GetElemento(x, y) == ' ')
                     salir = true;
                   if(this->GetElemento(x, y) == turno){
                     salir = true
                     while(this->GetElemento(x-=f_inc, y-=c_inc) == this->TurnoContrario())
                       tablero.SetElemento(x, y, turno);
                   }
                 } while (!salir)
                }
              }
         }
    }

    int Tablero::PosValida(int movs[][10])
    {
      int x, y,
      num_movs = 0;
      bool valido;

      for(int a = 0, a < this->GetFils(); a++)
       for(int b = 0; b < this->GetCols(); b++)
        movs[a][b] = 0;

      for(int i = 0; i < this->GetFils(); i++){
       for(int j = 0; j < this->GetCols(); j++){
        if(this->GetElemento(i,j) == ' '){
         for(int k = -1; (k <= 1)
              || (i + k >= 0)
              || (i + k < this->GetFils());
              k++){
          for(int l = -1; (l >= 1)
              || (j + l >= 0)
              || (j + l < this->GetCols())
              || (k != 0 && l != 0);
              l++){
           if(this->GetElemento(i + k, j + l) == this->TurnoContrario()){
 	            x = i + k;
	            y = j + l;

	            do{
                salir = true;
	              x += k;
	              y += l;

                if( (x < 0) || (x > this->GetFils()) || (y < 0) || (y > this->GetCols()))
  	             salir = false;
  	            if(this->GetElemento(x,y) == ' ')
  	             salir = false;
  	            if(this->GetElemento(x,y) == turno){
  	             movs[i][j] = 1;
                 num_movs++;
  	             salir = false;
                }
  	            }while(!salir)
	   }
	  }
         }
        }
       }
      }
     return num_movs;
    };

    bool Tablero::MovPosible(int movs[][10]){
     return this->PosValida(movs) >= 1;
    }
