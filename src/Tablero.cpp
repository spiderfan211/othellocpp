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



    void Tablero::Coloca(int f, int c)
    {
       int f_inc = 0;                   /* Row increment              */
       int c_inc = 0;                   /* Column increment           */
       int x = 0;                          /* Row index for searching    */
       int y = 0;                          /* Column index for searching */


       tablero.SetElemento(f, c, turno); //AQUÍ

       /* Check all the squares around this square */
       /* for the opponents counter                */
       for(f_inc = -1; f_inc <= 1; f_inc++)
         for(c_inc = -1; c_inc <= 1; c_inc++)
         {
           /* Don't check off the board, or the current square */
           if(f + f_inc < 0 || f + f_inc >= this->GetFils()
             || c + c_inc < 0 || c + c_inc >= this->GetCols()
             || (f_inc ==0 && c_inc == 0))
           {

               /* Now check the square */
               if(this->GetElemento(f + f_inc, c + c_inc) == this->TurnoContrario(){
                 /* If we find the opponent, search in the same direction */
                 /* for a player counter                                  */
                 x = f + f_inc;        /* Move to opponent */
                 y = c + c_inc;        /* square           */


                bool salir;
                 do{
                   salir = false;
                   x += f_inc;           /* Move to the      */
                   y += c_inc;           /* next square      */

                   /* If we are off the board give up */
                   if(x < 0 || x >= SIZE || y < 0 || y >= SIZE)
                     salir = true;

                   /* If the square is blank give up */
                   if(this->GetElemento(x, y) == ' ')
                     salir = true;

                   /* If we find the player counter, go backwards from here */
                   /* changing all the opponents counters to player         */
                   if(this->GetElemento(x, y) == turno){
                     salir = true
                     while(this->GetElemento(x-=f_inc, y-=c_inc) == this->TurnoContrario()) /* Opponent? */
                       tablero.SetElemento(x, y, turno);    /* Yes, change it */
                   }
                 } while (!salir)
                }
              }
         }
    }







    //int Tablero::PosValida(int movs[][10])  //TERMINAR
    //{
    //  int x, y,
    //  num_movs = 0;
    //  bool valido;
//
//
//
    //  for(int a = 0, a < this->GetFils(); a++)
    //   for(int b = 0; b < this->GetCols(); b++)
    //    movs[a][b] = 0;
//
    //  for(int i = 0; i < this->GetFils(); i++){
    //   for(int j = 0; j < this->GetCols(); j++){
    //    if(this->GetElemento(i,j) == ' '){
    //     for(int k = -1; i + k < 0 || i + k >= this->GetFils(); i++){
    //      for(int l = -1; j + l < 0
    //          || j + l >= this.GetCols()
    //          || (k == 0 && l == 0); j++){
    //       if(this->GetElemento(i + k, j + l) == this->TurnoContrario()){
 	  //          x = i + k;
	  //          y = j + l;
	  //          valido = true;
//
	  //          do{
	  //            x += k;
	//              y += l;
//
    //            if(x < 0 || x > this->GetFils() || y < 0 || y > this->GetColas())
  	//             valido = false;
  	//            if(this->GetElemento(x,y) == ' ')
  	//             valido = false;
  	//            if(this->GetElemento(x,y) == turno){
  	//             movs[x][y] = 1;
    //             num_movs++;
  	//             valido = false;
  	//            }while(!valido)
	  //           }
	//        }
    //     }
  //      }
    //   }
    //  }
  //   return num_movs;
  //  };




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

    bool Tablero::Coloca(int fila, int columna, int** &v)
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
