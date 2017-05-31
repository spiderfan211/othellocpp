#include<iostream>
#include"Jugador.h"
using namespace std;

    int Jugador::DialogoEscoger(int n, int* p, Tablero& t){
      int k;
      bool okay;
      cout<<"Hay más de una posición válida, elija una:"<<endl;
      t.ImprimeTablero();
      do{
        cin >> k;
        for(int i = 0; i <n; i++){
          okay = k == p[i];
        }
        if(!okay)
          cout << "Error, introduzca una fila correcta: ";
      }while( !okay || k < 0 || k > t.GetFils() );
      return k;
    }

    Jugador::Jugador(char nom_jugador[], int num_jugador)
    {
      int util = 0;

      for(int i = 0; nom_jugador[i] != '\0' && i < 48; ++i){
        nombre[i] = nom_jugador[i];
        util = i;
      }

      nombre[++util] = '\0';
      punt = 0;
      turno= num_jugador;
    }

    void Jugador::ImprimeNombre()
		{
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
     int n=0;
     int e[t.GetFils()];
     for(int i = 0; i < t.GetFils(); i++){
       if (t.PuedePoner(i, c)){
         e[i] = i;
         n++;
       }
     }

     if(n == 1){
       return e[0];
     }
     else{
       return this->DialogoEscoger(n, e, t);
     }
   };
