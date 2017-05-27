#include<iostream>
#include "Tablero.h"
using namespace std;

class Jugador {
private:
  char nombre[50];
  int turno;
  int punt;
  int Jugador::DialogoEscoger(int n, int* p){
    cout<<"Seleccione una de las posiciones válidas:"<<endl;
    for(int i = 0; i < n; i++){
      cout << "Opción "<< i << p[i] << "  " << endl;
    };
    int v;
    cin >> v;
    return v;
  }
public:
  int EscogePosicion(int c, Tablero t)
};
