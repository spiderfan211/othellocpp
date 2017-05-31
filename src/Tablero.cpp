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
    bool Tablero::PosValida(int fila, int columna, int& v)  //TERMINAR
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
                          v[fils][k]=turno;
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




    bool Tablero::MovPosible(int& v){   //PUNTERO de punteros   Pasaremos la matriz desde el main    inicializar todo a 0 en el puntero   NO MEMORIA DINAMICA (AUN)
  		bool mov_posible;

  		for(int i = 0; i < Filas(); i++){
  			for(int j = 0; j < Columnas(); j++){
  				if(Contenido(i,j) == 0){
  					mov_posible = PosValida(i,j);
            if(mov_posible)
              v[i][j] = 0;
  				}
  			}
  		}

  		return mov_posible;
  	}

    bool Tablero::Coloca(int fila, int columna, int& v)
  	{
      if(this->MovPosible(v)){
        tablero.SetElemento(fila, columna, turno);
        CambioTurno();
        return true;

      }
  		else {
        this->CambioTurno();
        if(!(this->MovPosible(v)))
          this->AcabarPartida();      //EN EL MAIN, COMPROBAR FINALIZADO DESPUES DE ESTO
        return false;
      }
    };
