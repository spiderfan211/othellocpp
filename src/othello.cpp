#include<iostream>
#include<string>
#include "Jugador.h"

using namespace std;

int main(){
  string seguir_jugando = "¿Seguir jugando? (S/N)";
  string msg_error = "Debes introducir un valor correcto";
  Tablero t;
  Jugador J1, J2;
  bool seguir = true, error = false;
  char c;
  while(seguir){
    do {










    }while (t.IsFinalizada() == false);
    do{
      cout << seguir_jugando << endl;
      cin >> c;
      if ( c == 's' || c == 'S' )
        seguir = true;
        error = false;
        t.VaciaTablero();
      else if ( c == 'n' || c == 'N' )
        seguir = false;
        error = false;
      else
        error = true;
        cout << msg_error << endl;
    } while (error)
  }
}
