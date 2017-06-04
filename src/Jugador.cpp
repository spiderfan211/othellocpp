#include<iostream>
#include"Jugador.h"
using namespace std;

    int Jugador::DialogoEscoger( int n, int* p, Tablero& t){
      int k;
      bool okay;
      cout<<"Hay más de una posición válida, elija una:"<<endl;
      t.ImprimeTablero();
      do{
        cin >> k;
        k-=1;
        okay = (p[k] == 1);

        if(!okay)
          cout << "Error, introduzca una fila correcta: ";
      }while( !okay || k < 0 || k > n );
      return k;
    }

    Jugador::Jugador(char nom_jugador[], int num_jugador){
      int util = 0;

      for(int i = 0; nom_jugador[i] != '\0' && i < 48; ++i){
        nombre[i] = nom_jugador[i];
        util = i;
      }

      nombre[++util] = '\0';
      punt = 0;
      turno= num_jugador;
    }

    void Jugador::ImprimeNombre(){
			for(int k = 0; nombre[k] != '\0'; ++k)
				cout << nombre[k];
		}

    int Jugador::GetTurno(){
      return turno;
    }

    int Jugador::GetPuntuacion(Tablero& t){
      return t.GetPuntuacion(turno);
    }




    int Jugador::EscogePosicion(int c, Tablero& t){
     int num = 0, ret = 0;
     int e[10];
     int n = t.GetFils();
     for(int i = 0; i < n; i++)
      e[i] = 0;

     for(int i = 0; i < n; i++){
       if (t.PosValida(i,c)){
         num++;
         e[i] = 1;
       }
     }

     if(num == 1){
      for (int i = 0; (i < n); i++)
        if(e[i] == 1)
          ret = i;
     }
     else if(num > 1)
       ret = this->DialogoEscoger(n, e, t);
     else
       ret = 0;


      return ret;
     };
