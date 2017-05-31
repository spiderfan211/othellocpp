#include<iostream>
#include "Tablero.h"
using namespace std;


    Tablero::Tablero(): tablero(){
      turno = 1;    // 1 ó 2 ó 0 ?
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

    bool Tablero::CambioTurno(){
      if (finalizado == false){
  			if(turno == 1)
  				turno = 2;
  			else
  				turno = 1;
      }
      return !finalizado;
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

    bool Tablero::Inserta(int f, int c, int d){ //TERMINAR
      if(this->PuedePoner(f,c)){
        tablero.SetElemento(f,c, d);
        return true;
      }
      else
        return false;
    };

    void Tablero::Vacia(){      //CAMBIAR A BOOLEANO
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
    bool Tablero::PosValida(int fila, int columna)  //TERMINAR
    {
      int fils;
      bool valido = false;

      for(int i = -1; i <= 1 || valido == false; i++){
        for(int j = -1; j <= 1 || valido == false; j++){	//BUCLE INFINITO
          if(tablero.GetElemento(fila + i,columna + j) == this->TurnoContrario()){
            if(i == -1){
                fils = fila + i - 1;

                if(j == -1){
                  for(int k = columna + j - 1;
                      (k >= 0)
                      && (fils >= 0)
                      && (tablero.GetElemento(fils,k) == this->TurnoContrario())
                      && (tablero.GetElemento(fils,k) != 0)
                      && (valido != true); //este filtro puede sobrar
                      k--){
                        if(tablero.GetElemento(fils,k) == turno)
                          valido = true;
                        fils--;
                  }
                }

                if (j == 0){
                  for(int k = fils;
                      k >= 0
                      && (tablero.GetElemento(k, columna) == this->TurnoContrario())
                      && (tablero.GetElemento(k, columna) != 0)
                      && valido != true;
                      k--){
                        if(tablero.GetElemento(k,columna) == turno)
                          valido = true;
                  }
                }
                if (j == 1){
                  for(int k = columna + j + 1;
                    (k < tablero.GetColumnas())
                    && (fils >= 0)
                    && (tablero.GetElemento(fils,k) == this->TurnoContrario())
                    && (tablero.GetElemento(fils,k) != 0)
                    && (valido != true);
                    k++){
                    if(tablero.GetElemento(fils,k) == turno);
                      valido = true;
                    fils--;
                  }
                }
            }
            if(i == 0){
                if(j == -1){
                  for(int k = columna + j - 1;
                    (k >= 0)
                    && (tablero.GetElemento(fila,k) == this->TurnoContrario())
                    && (tablero.GetElemento(fila, k) != 0)
                    && (valido != true);
                    k--){
                      if(tablero.GetElemento(fila,k) == turno)
                        valido = true;
                  }
                }
                if(j == 1){
                  for(int k = columna + j + 1;
                    (k < tablero.GetColumnas())
                    && (tablero.GetElemento(fila,k) == this->TurnoContrario())
                    && (tablero.GetElemento(fila, k) != 0)
                    && (valido != true);
                    k++){
                      if(tablero.GetElemento(fila,k) == turno)
                        valido = true;
                  }
                }
            }
            if(i == 1){
                fils = fila + i + 1;
                if(j == -1){
                  for(int k = columna + j - 1;
                    (k >= 0 && fils < tablero.GetFilas())
                    && (tablero.GetElemento(fila,k) == this->TurnoContrario())
                    && (tablero.GetElemento(fila, k) != 0)
                    && (valido != true);
                    k--){
                      if(tablero.GetElemento(fils,k) == turno)
                        valido = true;
                      fils++;
                  };
                }
                if(j == 0){
                  for(int k = fils;
                    (k < tablero.GetFilas())
                    && (tablero.GetElemento(fila,k) == this->TurnoContrario())
                    && (tablero.GetElemento(fila, k) != 0)
                    && (valido != true); ++k){
                      if(tablero.GetElemento(k,columna) == turno)
                        valido = true;
                      };
                }
                if(j == 1){
                  for(int k = columna + j + 1;
                    (k < tablero.GetColumnas())
                    && (fils < tablero.GetFilas())
                    && (tablero.GetElemento(fila,k) == this->TurnoContrario())
                    && (tablero.GetElemento(fila, k) != 0)
                    && (valido != true); ++k){
                      if(tablero.GetElemento(fils,k) == turno)
                        valido = true;
                      fils++;
                  }
                }
            }
          }
        }
      }

      return valido;
    };




    bool Tablero::MovPosible(int& v)   //PUNTERO de punteros    inicializar todo a 0 en el puntero
  	{
  		bool mov_posible = false;

  		for(int i = 0; i < Filas() && mov_posible != true; i++){
  			for(int j = 0; j < Columnas() && mov_posible != true; j++){
  				if(Contenido(i,j) == 0){
  					mov_posible = PosValida(i,j);
            //meter en v[i][j] el elemento
  				}
  			}
  		}

  		return mov_posible;
  	}










    bool Tablero::PuedePoner(int f, int c){
      if (this->PosValida(f,c) && tablero.GetElemento(f,c) != turno){
        return true;
      }
      else
        return false;
        //NO ESTOY SEGURO
    };
