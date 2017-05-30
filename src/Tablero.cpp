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
    void Tablero::Puntuacion()
  	{
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
  	}

    bool Tablero::Inserta(int f, int c, int d){
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
        tablero.SetElemento(fils/2,cols/2, 1);
        tablero.SetElemento(fils/2+1,cols/2+1, 1);
        tablero.SetElemento(fils/2+1,cols/2, 2);
        tablero.SetElemento(fils/2,cols/2+1, 2);
        finalizado = true;
        turno = 1;
      }
    };


    bool Tablero::PosValida(int fila, int columna)
    {
      int fils;
      bool valido = false;

      for(int i = -1; i <= 1 || valido == false; ++i){
        for(int j = -1; j <= 1 || valido == false ++j){	//BUCLE INFINITO
          if(Contenido(fila + i,columna + j) == 2){  //NO ES 2, ARREGLAR
            if(i == -1){
                    fils = fila + i - 1;

                    if(j == -1){
                      for(int k = columna + j - 1; (k >= 0 && fils >= 0) || (Contenido(fils,k) != turno || Contenido(fils,k) != 0) || valido != true; --k){
                        if(Contenido(fils,k) == turno)
                          valido == true;
                        fils--;
                          cout << "a" << endl;
                      }cout << "b" << endl;
                    }

                    if (j == 0){
                      for(int k = fils; k >= 0 || (Contenido(k, columna) != turno || Contenido(k, columna) != 0) || valido != true; --k){
                        if(Contenido(k,columna) == turno)
                          valido == true;
                          cout << "c" << endl;
                      }cout << "d" << endl;
                    }
                    if (j == 1){
                      for(int k = columna + j + 1; (k < Columnas() && fils >= 0) || (Contenido(fils,k) != turno || Contenido(fils,k) != 0) || valido != true; ++k){
                        if(Contenido(fils,k) == turno);
                          valido == true;
                        fils--;
                          cout << "e" << endl;
                      }cout << "f" << endl;
                    }
            }
            if(i == 0){
                    if(j == -1){
                      for(int k = columna + j - 1; k >= 0 || (Contenido(fila,k) != turno || Contenido(fila, k) != 0) || valido != true; --k){
                        if(Contenido(fila,k) == turno)
                          valido == true;
                        cout << "g" << endl;
                      }cout << "h" << endl;
                    }
                    if(j == 1){
                      for(int k = columna + j + 1; k < Columnas() || (Contenido(fila,k) != turno || 										Contenido(fila,k) != 0) || valido != true; ++k){
                        if(Contenido(fila,k) == 1)
                          valido == true;
                          cout << "i" << endl;
                      }cout << "j" << endl;
                    }
            }
            if(i == 1){
                    fils = fila + i + 1;
                    if(j == -1){
                      for(int k = columna + j - 1; (k >= 0 && fils < Filas()) || Contenido(fils,k) != turno || Contenido(fils,k) != 0 || valido != true; --k){
                        if(Contenido(fils,k) == turno)
                          valido == true;
                        fils++;
                      };
                    }
                    if(j == 0){
                      for(int k = fils; k < Filas() || (Contenido(k,columna) != turno || Contenido(k,columna) != 0) || valido != true; ++k){
                        if(Contenido(k,columna) == turno)
                          valido == true;
                        };
                    }
                    if(j == 1){
                      for(int k = columna + j + 1; (k < Columnas() && fils < Filas()) || (Contenido(fils,k) != turno || Contenido(fils,k) != 0) || valido != true; ++k){
                        if(Contenido(fils,k) == turno)
                          valido == true;
                        fils++;
                      }
                    }
            }
          }
        }
      }

      return valido;
    }

    bool Tablero::PuedePoner(int f, int c){
      if (this->PosValida(f,c) && tablero.GetElemento(f,c) != turno){
        return true;
      }
      else
        return false;
        //NO ESTOY SEGURO
    };
