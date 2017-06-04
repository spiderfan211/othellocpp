#include<iostream>
#include "Tablero.h"
using namespace std;


    Tablero::Tablero():tablero(){
      turno = 1;
      finalizado = false;
      ganador = 0;
      puntuacion1 = puntuacion2 = 0;
      tablero.SetElemento(tablero.GetFilas()/2 ,tablero.GetColumnas()/2, 1);
      tablero.SetElemento(tablero.GetFilas()/2-1,tablero.GetColumnas()/2-1, 1);
      tablero.SetElemento(tablero.GetFilas()/2-1,tablero.GetColumnas()/2, 2);
      tablero.SetElemento(tablero.GetFilas()/2,tablero.GetColumnas()/2-1, 2);
    }

    Tablero::Tablero(int f, int c): tablero(f,c){
      turno = 1;
      finalizado = false;
      ganador = 0;
      puntuacion1 = puntuacion2 = 0;
      tablero.SetElemento(tablero.GetFilas()/2,tablero.GetColumnas()/2, 1);
      tablero.SetElemento(tablero.GetFilas()/2-1,tablero.GetColumnas()/2-1, 1);
      tablero.SetElemento(tablero.GetFilas()/2-1,tablero.GetColumnas()/2, 2);
      tablero.SetElemento(tablero.GetFilas()/2,tablero.GetColumnas()/2-1, 2);
    }

    void Tablero::ImprimeTablero(){
      char l = 'a';
      cout << " ";
      for(int i = 0; i < this->GetCols() ; i++ ){
        cout << " " << l;
        l ++;

      }
      cout << endl << " ";
      for(int i = 0; i < this->GetCols() * 2 + 1 ; i++ )
        cout<< "-";
      cout << endl;

      for (int i = 0; i < this->GetFils(); i++){
        cout << i  ;
        for (int j = 0; j < this->GetCols(); j++){
          if(this->GetElem(i,j) == 0 )
            cout << "| ";
          else if (this->GetElem(i,j) == 1)
            cout << "|x";
          else if (this->GetElem(i,j) == 2)
            cout << "|o";
          };
          cout << "|" << endl;
      }
      cout << " ";
      for(int i = 0; i < this->GetCols() * 2 + 1 ; i++ )
        cout<< "-";
      cout << endl;
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

    void Tablero::AcabarPartida(){
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
        tablero.SetElemento(tablero.GetFilas()/2-1,tablero.GetColumnas()/2-1, 1);
        tablero.SetElemento(tablero.GetFilas()/2-1,tablero.GetColumnas()/2, 2);
        tablero.SetElemento(tablero.GetFilas()/2,tablero.GetColumnas()/2-1, 2);
        finalizado = false;
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
           if(f + f_inc >= 0 || f + f_inc < this->GetFils()
             || c + c_inc >= 0 || c + c_inc < this->GetCols()
             || (f_inc ==0 && c_inc == 0))
           {

               if(this->GetElem(f + f_inc, c + c_inc) == this->TurnoContrario()){
                 x = f + f_inc;
                 y = c + c_inc;


                bool salir;
                 do{
                   salir = false;
                   x += f_inc;
                   y += c_inc;

                   if(x < 0 || x >= this->GetFils() || y < 0 || y >= this->GetCols())
                     salir = true;
                   if(this->GetElem(x, y) == 0)
                     salir = true;
                   if(this->GetElem(x, y) == turno){
                     salir = true;
                     x-=f_inc;
                     y-=c_inc;
                     while(this->GetElem(x, y) == this->TurnoContrario()){
                       tablero.SetElemento(x, y, turno);
                       x-=f_inc;
                       y-=c_inc;
                     }
                   }
                 } while (!salir);
                }
              }
         }
    }

/* Método que almacena como "1" en una matriz pasada como puntero a punteros las posiciones
válidas de un tablero y devuelve el número de posiciones que haya sumado*/

/*Da error del tipo "segmentation fault: core generado" al llamar en algún momento al módulo de la clase Clasematriz
que devuelve el elemento seleccionado por filas y columnas (intenta devolver un elemento de posicion -1157, 63635)
EL único método llamado aquí que usa dicho método de Clasematriz son this->GetElem()*/

bool Tablero::PosValida(int f, int c)
{
  int x, y = 0;
  bool salir, valido = false;


//Recorremos la matriz tablero entera en busca de todas las posiciones válidas
    if(this->GetElem(f,c) == 0){
     for(int k = -1; (k <= 1)
          && (f + k >= 0)
          && (f + k < this->GetFils());
          k++){
      for(int l = -1; (l <= 1)
          && (c + l >= 0)
          && (c + l < this->GetCols());
          l++){

       if(k != 0 || l != 0){        //la posición misma (i,j) no sirve para seguir buscando en esa dirección
             if(this->GetElem(f + k, c + l) == this->TurnoContrario()){     //Si encontramos una ficha contraria, seguimos esa direccion
                x = f + k;                                                  //De manera que la nueva posición sería (x, y)
                y = c + l;

                do{
                  salir = true;
                  x += k;
                  y += l;

                  if( (x >= 0) && (x < this->GetFils()) && (y >= 0) && (y < this->GetCols())){    //Comprobaciones de límites del tablero
                    salir = false;
                    if(this->GetElem( x, y ) == this->TurnoContrario())   //Si encuentra una ficha contraria, sigue buscando
                      salir = false;
                    if(this->GetElem(x,y) == 0)     //Si el algoritmo encuentra un elemento neutro antes que uno del mismo turno, la posición no es válida, y sigue los bucles superiores
                      valido = false;
                      salir = true;
                    if(this->GetElem(x,y) == this->GetTurno()){    //Si encuentra una de su turno, la posición sería válida
                      valido =true;
                      salir = true;           //Sale del bucle, sigue con los superiores (i, j, k, l)
                    }
                  }
                 }while(!salir);
             }
         }
      }
     }
    }
    else
      valido = false;

    return valido;
};



    bool Tablero::MovPosible(){
      bool pos =false;
      for(int i = 0; (i < this->GetFils()) && (pos == false); i++)
        for (int j = 0; (j < this->GetCols()) && (pos == false); j++)
          pos = this->PosValida(i,j);
      return pos;
    }
